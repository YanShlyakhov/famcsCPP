/*
    Удалить из строки заданное слово.

    input
    abcde abcde abc ab ab abcde gde
    ab

    output
    abcde abcde abc abcde gde
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
    char* str1;
    str1 = getString();
    char* word;
    word = strtok (s, delimiter);
    while (word){
        //cout<<word;
        if (strcmp(word, str1)){
            strcat(newS, word);
            strcat(newS, " ");
        }
        word = strtok (NULL, delimiter);
    }
    cout<< newS;
    system("pause");
    return 0;
}
