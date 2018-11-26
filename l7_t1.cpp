/*
    Дана строка символов.
    Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.
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
    s = getString();
    int* a = new int[256];
    for(int i=0; i<256; ++i)
        a[i] = 0;
    calcDiff(s, a);
    for(int i=0; i<256; ++i){
        cout<<(char)i<<" "<<a[i]<<"\n";
    }
    system("pause");
    return 0;
}
