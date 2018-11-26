/*
    Yan Shlyakhau 05.09.2018

    Дано натуральное число n.
    Определите, является ли оно степенью числа 2,
    и выведите слово YES, если является и слово NO, если не является.

    input    output
    2        YES
             Power of 2 is 1

    -1       Error

    200      NO
*/

#include <iostream>

using namespace std;

bool isValid(int x){
    return (x > 0);
}

int main(){

    int n;

    cout << "Insert N > 0 \n";
    cin >> n;

    while(!isValid(n)){
        cout << "Uncorrect N, N should be bigger than 0 \n";
        cin >> n;
    }

    //Степень двойки
    int powerOfTwo = 0;

    //Два в степени powerOfTwo
    int curValue = 1;

    while( n > curValue ){
        /*
            Можно заменить на pow(2, powerOfTwo)
            Выглядеть будет понятнее, но будет работать медленнее
            while( n > pow( 2, powerOfTwo )){
                powerOfTwo++;
            }
        */
        powerOfTwo++;
        curValue *= 2;
    }


    if ( n == curValue ){
        cout << "YES \nPower of 2 is " << powerOfTwo;
    }else{
        cout << "NO \n";
    }

    //system("pause");
    //return 0;
}
