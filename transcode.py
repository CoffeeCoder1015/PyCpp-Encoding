import random
import cmath
UNI_CODE_MAX = 1114111


def adr (lst):
    adm = random.randrange(0,UNI_CODE_MAX-max(lst))
    rtl = [adm+i for i in lst]
    rtl.append(adm)
    return rtl
    
def encrypt(text: str):
    text = [ord(i) for i in text]
    text = adr(text)
    bin_fmt = "".join([format(i,"023b") for i in text])
    int_fmt = int(bin_fmt,2)
    hex_fmt = hex(int_fmt).replace("0x","")
    return hex_fmt

def decrypt(enc:str):
    txt_objs = []
    enc = list(bin(int(enc,16)).replace("0b",""))
    
    for _ in range(0,len(enc)//23):
        apo = []
        for _ in range(0,23):
            sI = len(enc)-1
            v = enc[sI]
            del enc[sI]
            apo.insert(0,v)
        apo = int("".join(apo),2)
        txt_objs.insert(0,apo)
    #append the left out binrary string without 23 indexes
    txt_objs.insert(0,int("".join(enc),2))
    
    sI = len(txt_objs)-1
    d_num = txt_objs[sI]
    del txt_objs[sI]

    for i in range(0,len(txt_objs)):
        txt_objs[i] -= d_num
        txt_objs[i] = chr(txt_objs[i])

    return "".join(txt_objs)