/*
Найти все натуральные числа, не превосходящие заданного числа n,
у которых все цифры в записи числа различны.

in     out

123    100

10     9

0      error
*/

#include <iostream>
#include <cstdlib>

using namespace std;

bool areDigetsDifferent(int n){
    int a[10];
    bool flagDifferent = true;
    for( int  i = 0; i < 10; ++i ){
        a[i] = 0;
    }

    while( n > 0 ){
        int x = n % 10;
        n /= 10;
        a[x]++;
    }

    for(int i = 0; i < 9; ++i){
        if(a[i] > 1){
            flagDifferent = false;
        }
    }

    return flagDifferent;
}

int main(){

    int n;

    cout << "Insert n\n";
    cin >> n;

    while( n <= 0 ){
        cout << "N should be bigger than 0\n";
        cin >> n;
    }

    int answerCount = 0;

    for(int i = 1; i<n; ++i){
        answerCount += areDigetsDifferent(i); // false == 0, true == 1
    }

    cout << answerCount <<"\n";

    system("pause");
    return 0;
}

