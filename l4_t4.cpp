/*
    Найти сумму и произведение двух многочленов, заданных массивами своих коэффициентов.

    in
    5
    1 2 3 4 5
    6
    1 2 3 4 5 6

    out
    Sum:
    2 4 6 8 10 6
    Multiplication:
    1 4 10 20 35 50 58 58 49 30

    in
    5
    0 0 0 0 0
    7
    0 0 0 0 0 0 0
    out
    Sum:
    0 0 0 0 0 0 0
    Multiplication:
    0 0 0 0 0 0 0 0 0 0 0

    in
    -1
    124 124 1 24
    -2
    123123
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

int main(){

    int n;
    int m;
    int a[MAX_VAL];
    int b[MAX_VAL];
    int sum[MAX_VAL];
    int mult[MAX_VAL];

    cout << " Insert 0 < N <"<<MAX_VAL <<endl;
    cin >> n;

    while (n <= 0 || n > MAX_VAL){
        cout << ERROR_INSERT;
        cin >> n;
    }

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << " Insert 0 < M <"<<MAX_VAL <<endl;
    cin >> m;
    while (m <= 0 || m > MAX_VAL){
        cout << ERROR_INSERT;
        cin >> m;
    }

    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    for (int i = 0; i < max(n, m); i++){
        sum[i] = a[i] + b[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mult[i + j] += a[i] * b[j];
        }
    }

    cout << "Sum: " << endl;
    for ( int i = 0; i < max(n, m); i++ ){
        cout << sum[i] << " ";
    }
    cout << endl << "Multiplication: "  << endl;
    for ( int i = 0; i < n + m - 1; i++ ){
        cout << mult[i] << " ";
    }

    system("pause");
    return 0;
}
