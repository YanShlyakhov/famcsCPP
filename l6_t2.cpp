/*
    Реализовать 3 функции каждая из которых принимает указатель на массив и количество элементов и возвращает
    указатель на новый массив. Первая функция ищет простые числа и заносит их в новый массив,
    вторая – все числа кратные трем, третья – все четные числа.
    Напишите функцию, которая принимает указатель на функцию в качестве параметра.

    input
    10
    1 2 3 4 5 6 7 8 9 10

    out
    (p)
        (указатель на новый массив)
    (3)
        (указатель на новый массив)
    (2)
        (указатель на новый массив)
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool isPrime(int a){
    if(a <= 1){
        return false;
    }
    for(int i = 2; i<(int)(sqrt(a)+1); ++i){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

bool isMod2(int a){
    return !(a%2);
}

bool isMod3(int a){
    return !(a%3);
}

int* engine(int* a, int n, bool (*cmp)(int )){
    int* result = new int[n];
    int length = 0;
    for(int i=0; i<n; ++i){
        if( (*cmp)(a[i]) ){
            result[length] = a[i];
            cout << a[i]<<" ";
            length++;
        }
    }
    cout <<"\n";
    return result;
}

int main(){
    cout <<"Operations: \n\tp Prime\n\t3 %3 == 0\n\t2 %2 == 0\n\te Exit  \n";
    int n;
    cout << "Insert N > 0\n";
    cin >> n;
    while(n <= 0){
        cout << "N should be bigger than 0\n";
        cin >> n;
    }
    cout <<"Insert a:\n";
    int* a = new int[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    cout<<"\nInsert operation (p, 3, 2, e): \n";
    char c;
    cin >> c;
    bool (*cmp)(int ) = NULL;
    if(c=='p'){
        cmp = &isPrime;
    }
    if(c=='3'){
        cmp = &isMod3;
    }
    if(c=='2'){
        cmp = &isMod2;
    }
    if(c!='e'){
        cout << engine(a, n, cmp);
    }
    delete[] a;

    system("pause");
    return 0;
}
