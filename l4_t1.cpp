/*
    Дан массив целых чисел, в котором все числа кроме одного встречаются четное количество раз,
    одно число встречается нечетное количество раз. Найти это число.

    in          out
    1            1
    1

    3
    1 2 2        1

    5
    1 2 1 2 2    2
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int n;
    cout << "Insert N";
    cin >> n;

    while (n < 0){
        cout << "Insert N, that bigger than 0";
        cin >> n;
    }

    int *a = new int[n];

    for(int i =0; i<n; ++i){
        cin >> a[i];
    }

    int result = a[0];
    for(int i=1; i<n; ++i){
        result ^= a[i];
    }

    cout << result;

    system("pause");
    return 0;
}
