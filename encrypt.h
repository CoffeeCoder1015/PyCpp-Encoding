#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <Python.h>
#include <iomanip>
#include <ostream>

std::string func=
"import random\n"
"import cmath\n"
"UNI_CODE_MAX = 1114111\n"
"\n"
"\n"
"def adr (lst):\n"
"    adm = random.randrange(0,UNI_CODE_MAX-max(lst))\n"
"    rtl = [adm+i for i in lst]\n"
"    rtl.append(adm)\n"
"    return rtl\n"
"    \n"
"def encrypt(text: str):\n"
"    text = [ord(i) for i in text]\n"
"    text = adr(text)\n"
"    bin_fmt = \"\".join([format(i,\"023b\") for i in text])\n"
"    int_fmt = int(bin_fmt,2)\n"
"    hex_fmt = hex(int_fmt).replace(\"0x\",\"\")\n"
"    return hex_fmt\n"
"\n"
"def decrypt(enc:str):\n"
"    txt_objs = []\n"
"    enc = list(bin(int(enc,16)).replace(\"0b\",\"\"))\n"
"    \n"
"    for _ in range(0,len(enc)//23):\n"
"        apo = []\n"
"        for _ in range(0,23):\n"
"            sI = len(enc)-1\n"
"            v = enc[sI]\n"
"            del enc[sI]\n"
"            apo.insert(0,v)\n"
"        apo = int(\"\".join(apo),2)\n"
"        txt_objs.insert(0,apo)\n"
"    #append the left out binrary string without 23 indexes\n"
"    txt_objs.insert(0,int(\"\".join(enc),2))\n"
"    \n"
"    sI = len(txt_objs)-1\n"
"    d_num = txt_objs[sI]\n"
"    del txt_objs[sI]\n"
"\n"
"    for i in range(0,len(txt_objs)):\n"
"        txt_objs[i] -= d_num\n"
"        txt_objs[i] = chr(txt_objs[i])\n"
"\n"
"    return \"\".join(txt_objs)\n";