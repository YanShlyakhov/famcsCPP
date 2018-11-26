/*
    Дана строка.
    Посчитать в ней частоты всех двухбуквенных
    сочетаний без учета регистра и без учета символов, не являющихся буквами.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>

using namespace std;

char* getString(){
    char* s;
    string buf;
    getline(cin, buf);
    s = &buf[0];
    return s;
}

const int MAX_LEN = 256 * 256 + 1;

int main(){
    char* s;
    char* word;
    s = getString();
    int hash[MAX_LEN] = {0};
    char* pairs[MAX_LEN];
    word = strtok (s, " .,;:!-");
    while (word){
        if (strlen(word) == 2){
            int curHash = (word[0]*31 + word[1])*31 %MAX_LEN;
            hash[curHash]++;
            pairs[curHash] = word;
        }
        word = strtok (NULL, " .,;:!-");
    }
    for(int i=0; i<MAX_LEN; ++i){
        if(hash[i] != 0){
            cout<<pairs[i]<<" "<<hash[i];
        }
    }

    system("pause");
    return 0;
}
