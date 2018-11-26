/*
    Дана строка. «Перевернуть» в строке все слова (например:
    «Жили были дед и баба» - «илиЖ илыб дед и абаб»). Зам. Исходную строку не менять
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>

using namespace std;

const int MAX_STRING_LEN = 256;

bool isdelimiter(char c){
    switch (c){
        case ' ':case '.':case ',':case ';':case ':':case '!':case '-':case '\0': return true;
        default: return false;
    }
}

char* getString(){
    char* s;
    string buf;
    getline(cin, buf);
    s = &buf[0];
    return s;
}

int main(){
    char* s;
    s= getString();
    int st = 0, en = 0;
    while (s[st] != '\0')
        if (!isdelimiter(s[st])){
            en = st + 1;
            while (!isdelimiter(s[en])) en++;
            for (int i = 0; i < (en-st)/2; i++)
                swap(s[st+i], s[en-i-1]);
            st = en;

        } else st++;
    cout << s;
    system("pause");
    return 0;
}
