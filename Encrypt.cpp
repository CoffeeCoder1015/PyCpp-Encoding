#include <encrypt.h>

using namespace std;

string mod_linker(string file_str, string func_str, string arg_str)
{
    Py_Initialize();

    PyObject *mod, *gen_func, *run_func, *ret_val, *arg;
    arg = PyUnicode_FromString(arg_str.c_str());
    mod = PyImport_AddModule("__main__");
    PyRun_SimpleString(func.c_str());
    gen_func = PyObject_GetAttrString(mod, func_str.c_str());
    run_func = PyObject_CallFunctionObjArgs(gen_func, arg, NULL);

    ret_val = PyObject_Repr(run_func);
    //final value
    string return_value = PyUnicode_AsUTF8(ret_val);
    Py_Finalize();

    return return_value;
}

void encrypt(string input_text)
{
    vector<string> ope_lst;
    for (int i = 0; i < input_text.size(); i++)
    {
        ostringstream s_pad;
        s_pad << setfill('0') << setw(4) << to_string(rand() % 1000);
        ope_lst.push_back(input_text.substr(i, 1) + s_pad.str());
    }

    string ope_join = "";
    for (int i = 0; i < ope_lst.size(); i++)
    {
        ope_join += ope_lst[i];
    }

    //removing the quote marks
    string ecs = mod_linker("transcode", "encrypt", ope_join);
    ecs.replace(0, 1, "");
    ecs.replace(ecs.size() - 1, 1, "");

    cout << ecs << endl;
}

void decrypt(string input_text)
{
    string j_str = "";
    string dec = mod_linker("transcode", "decrypt", input_text);
    dec.replace(0, 1, "");
    dec.replace(dec.size() - 1, 1, "");
    for (int i = 0; i < dec.size() / 5; i++)
    {
        j_str += dec[5 * i];
    }

    cout << j_str << endl;
}

int main()
{

    string id;
    string ip_text;

    cout << "Text:";
    getline(cin, ip_text);

    cout << "Encrypt (E) or Decrypt (D):";
    cin >> id;

    //convert id to lowercase
    transform(id.begin(), id.end(), id.begin(), [](unsigned char c) { return std::tolower(c); });

    if (id == "e")
    {
        encrypt(ip_text);
    }
    else if (id == "d")
    {
        decrypt(ip_text);
    }
    else
    {
        cout << "UNKNOWN COMMAND" << endl;
        return 2;
    }
}