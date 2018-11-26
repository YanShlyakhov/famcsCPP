/*
    Дан массив целых чисел, из этой последовательности целых чисел выбрать три числа, произведение которых максимально.

    in            out
    2              error
    ...

    4
    -1 -2 -3 3     18

    4
    -1 -2 -3 -4    -6

    4

    1 2 3 -10      6
*/
#include <iostream>
#include <cstdlib>
#include "bestLib.h"

using namespace std;

const int MAX_N = 10000;

int main(){

    int n;
    cout << "Insert N" << endl;
    cin >> n;
    while(n < 3){
        cout << "Insert N >= 3" << endl;
        cin >> n;
    }

    int a[MAX_N];
    for( int i = 0; i < n; ++i ){
        cin >> a[i];
    }

    oddEvenSort(a, n);
    cout << max(a[0]*a[1]*a[n-1], a[n-1]*a[n-2]*a[n-3])  <<endl;

    system("pause");
    return 0;
}

