/*
    Дан код программы на С++.  Вывести построчно все операции и частоту их использования в программе.
*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAX_OPERATORS = 36;

const char operators[MAX_OPERATORS][3] = {"+", "-", "*", "/", "!", "=", "%", "~", "&", "|", "^", "*", ".", "?", ":", ">", "<",
                                          "<<", ">>", "<=", "<=", "++", "--", "==", "!=", "&&", "||", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "+=", "^="};
int operators_count[MAX_OPERATORS] = {0};

void count_operator(char* c){
    for (int i = 0; i < MAX_OPERATORS; i++)
        if (strcmp(c, operators[i]) == 0){
            operators_count[i]++;
            break;
        }
}

bool isoperation(char c){
    for (int i = 0; i < 17; i++)
        if (c == operators[i][0]) return true;
    return false;
}

char* getString(){
    char* s;
    string buf;
    getline(cin, buf);
    s = &buf[0];
    return s;
}


int main()
{
    char* code;
    code = getString();
    int len = strlen(code);
    int i = 0;
    while (i < len){
        if (isoperation(code[i])){
            if (isoperation(code[i+1])){
                code[i+2] = '\0';
                count_operator(code+i);
                i+=3;
            } else {
                code[i+1] = '\0';
                count_operator(code+i);
                i+=2;
            }
        }
        else if (code[i] == '\"'){
            while (code[++i] != '\"');
            i++;
        }
        else i++;
    }
    for (int i = 0; i < MAX_OPERATORS; i++)
        if (operators_count[i])
            cout << "Operator " <<  operators[i] << " is used " << operators_count[i] << ((operators_count[i]>1)?" times\n":" time\n");
    system("pause");
    return 0;
}
