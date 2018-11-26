/*
    В данной строке все вхождения подстроки str1 заменить подстрокой str2.
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>

using namespace std;

/*
    т.к. не знаем длину строки
*/
char* getString(){
    char* s;
    string buf;
    getline(cin, buf);
    s = &buf[0];
    return s;
}

/*
    применяется идея сортировки подсчетом
*/
void calcDiff(char* s, int* a){
    for(int i=0; s[i]!='\0'; ++i){
        int x = (int)s[i];
        cout<<x;
        a[x]++;
    }
}

int main(){
    char* s;
    char newS[255]={'\0'};
    const char* delimiter = " ";
    s = getString();
    char* word;
    word = strtok(s, delimiter);

    char* str1;
    str1 = getString();

    char* str2;
    str2 = getString();

    while (word){
        cout<<word<<'\n';
        if (strcmp(word, str1) == 0){
            strcat(newS, str2);
            strcat(newS, " ");
        }else{
            strcat(newS, word);
            strcat(newS, " ");
        }

        word = strtok(NULL, delimiter);
    }
    cout<< newS;
    system("pause");
    return 0;
}

