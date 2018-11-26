/*
    Добавить к некоторой последовательности  A=(ai), i=1..n, n<=100, наименьшее  число элементов,
    чтобы  получить  арифметическую прогрессию (например, 22 1  36  -> 1  8 15 22 29 36).

    in
    5
    1 3 5 7 13
    out
    1 3 5 7 9 11 13

    in
    1
    1
    out
    1

    in
    3
    1 1 1
    out
    1 1 1

    in
    3
    1 1 2
    out
    Bad Sequence

    in
    -1
    out
    error

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
    int a[MAX_VAL];

    cout << " Insert 0 < N <"<<MAX_VAL <<endl;
    cin >> n;

    while (n <= 0 || n > MAX_VAL){
        cout << ERROR_INSERT;
        cin >> n;
    }

    for(int i = 0; i<n; ++i){
        cin >> a[i];
    }

    oddEvenSort(a, n);

    bool flag = true; // if they are all equal
    for(int i =1; i<n; ++i){
        if(a[i-1] != a[i]){
            flag = false;
            break;
        }
    }

    if(flag){
        for(int i=0; i<n; ++i){
            cout << a[i] <<" ";
        }
    }else{

        bool ifEqualElements = false;
        int dst = a[1] - a[0];
        for(int i = 2; i<n; ++i){
            if(a[i] - a[i-1] == 0){
                ifEqualElements = true;
                break;
            }
            dst = gcd(dst, a[i]-a[i-1]);
        }

        if(ifEqualElements){
            cout << "Bad Sequence";
        }else{
            int cur = a[0];
            int finish = a[n-1];

            while(cur <= finish){
                cout << cur <<" ";
                cur += dst;
            }
        }
    }

    system("pause");
    return 0;
}
