/*
    Yan Shlyakhau 05.09.2018

    Дано натуральное число n. Выведите сумму цифр числа n.

    N    answer
    100  1
    123  6
    999  27
    -1   Uncorrect N, N should be > 0
    0    Uncorrect N, N should be > 0
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const string VALUE_ERROR = "Uncorrect N, N should be > 0 \n";

bool isValid(int x){
    return (x > 0);
}

int main(){

    int n;

    cout << "Insert N > 0 \n";
    cin >> n;

    while(!isValid(n)){
        cout << VALUE_ERROR;
        cin >> n;
    }

    //Суммирование цифр
    int sumOfDigets = 0;
    while( n > 0 ){
        sumOfDigets += n % 10;
        n /= 10;
    }
    cout << sumOfDigets;

    system("pause");
    return 0;
}
