/*
    Написать программу, которая содержит функцию, принимающую в качестве аргумента,
    указатели на два массива (А и В) и размеры массивов.
    Функция проверяет, является ли массив В подмножеством/построкой (2 способами, см. зам.)
    массива А и возвращает указатель на начало найденного фрагмента, если элемента нет, возвращает 0.
    Зам. 1) Множество B называется подмножеством множества A, если все элементы, принадлежащие B, также принадлежат A.
         2) Подстрока – это непустая связная часть строки.

    INPUT
    3
    1 2 3
    2
    1 2
    OUTPUT
    Array B is subset of A
    Array B is subset of A
    Array B is subset of A from 0x781600P
    ====================
    INPUT
    3
    1 2 3
    4
    1 2 3 4
    OUTPUT
    Not a subset
    Not a subset
    Array B is subset of A from 0

*/
#include <iostream>
#include <string>
#include<cstdlib>
#include "bestLib.h"

using namespace std;

void read(int &n, string what){
    cout <<"Insert "<<what<<" > 0\n";
    cin >> n;
    while(n < 0){
        cout <<"Insert "<<what<<" > 0\n";
        cin >> n;
    }
}

int* fromToSubset(int* a, int n, int* b, int m){
    for (int i = 0; i < n; i++){
        int j = i, k = 0;
        while(j < n && k < m && a[j] == b[k]){
            j++;
            k++;
        }
        if(k == m){
            return a+i;
        }
    }
    return nullptr;
}

/*
    O( n*m )
    за квадрат проходим и просматриваем все элементы
*/
void firstSolution(int* a, int n, int* b, int m){
    bool isSubSet = true;
    for(int i=0; i<m; ++i){
        bool isBiInAj = false;
        for(int j=0; j<n; ++j){
            if(a[j] == b[i]){
                isBiInAj = true;
            }
        }
        isSubSet = isBiInAj;
    }
    if(isSubSet){
        cout << "Array B is subset of A";
    }else{
        cout << "Not a subset";
    }
}


/*
    O( max(Elem) - min(Elem))
    идея испльзовать принцип сортировки подсчетом
    для отрицательных элементов сдвинуть массив на минимальный элемент
*/
void secondSolution(int *a, int n, int *b, int m){
    int mn = 10000;
    for (int i = 0; i < n; ++i){
        mn = min(mn, a[i]);
    }

    bool c[10000] = {0};//в динамическом массиве нельзя так делать

    if (mn > 0){
        mn = 0;
    }

    for (int i = 0; i < n; ++i){
        c[a[i]-mn] = true;
    }
    bool isWrite = false;

    for (int i = 0; i < m; ++i){
        if (b[i] - mn < 0){
            cout << "Not a subset";
            isWrite = true;
            break;
        }
        if (!c[ b[i] - mn ]){
            cout << "Not a subset";
            isWrite = true;
            break;
        }
    }
    if(!isWrite){
        cout << "Array B is subset of A";
    }
}

int main(){
    int n, m;

    read(n, "N");
    int *a = new int[n];

    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    read(m, "M");
    int *b = new int[m];

    for(int i=0; i<m; ++i){
        cin >> b[i];
    }

    firstSolution(a, n, b, m);
    cout <<"\n";
    secondSolution(a, n, b, m);
    cout << "\nArray B is subset of A from " <<  fromToSubset(a, n, b, m);

    system("pause");
    return 0;
}
