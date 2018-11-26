/*
    Дан массив целых чисел.
    Реализовать функцию для обработки массива целых чисел.
    Функция находит минимальный элемент массива и сортирует все элементы левее его по убыванию,
    а правее его – по возрастанию.
    Функция возвращает индекс минимального элемента.

    in
    7
    1 2 3 0 3 2 1
    out
    3 2 1 0 1 2 3

    in
    5
    0 1 2 3 4
    out
    0 1 2 3 4

    in
    5
    5 4 3 2 1
    out
    5 4 3 2 1

    in
    -1
    out
    ERROR
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "bestLib.h"

using namespace std;

const int MAX_VAL = 10000;
const string ERROR_INSERT = "ERROR in insert, please insert correct number\n";


int getMinPos(int *a, int n){
    int minPos = 0;

    for(int i = 1; i<n; ++i){
        if(a[i] < a[minPos]){
            minPos = i;
        }
    }
    //TODO one array
    int curArray[MAX_VAL];
    for(int i=0; i<minPos; ++i){
        curArray[i] = a[i];
    }

    bubleSort(curArray, minPos);
    reverse(curArray, minPos);

    for(int i = 0; i<minPos; ++i){
        a[i] = curArray[i];
    }

    for(int i = minPos+1, j = 0; i<n; ++i, ++j){
        curArray[j] = a[i];
    }

    bubleSort(curArray, n - minPos - 1);

    for(int i = minPos+1, j = 0; i<n; ++i, ++j){
        a[i] = curArray[j];
    }

    return minPos;
}

int main(){

    int n;
    int m;
    int a[MAX_VAL];

    cout << " Insert 0 < N <"<<MAX_VAL <<endl;
    cin >> n;

    while (n <= 0 || n > MAX_VAL){
        cout << ERROR_INSERT;
        cin >> n;
    }

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int minPos = getMinPos(a, n);

    for(int i=0; i<n; ++i){
        cout <<a[i]<<" ";
    }

    system("pause");
    return 0;
}

