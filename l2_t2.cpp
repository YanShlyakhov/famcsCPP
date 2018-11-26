/*
    Yan Shlyakhau 05.09.2018

    В первый день спортсмен пробежал x километров,
    а затем он каждый день увеличивал пробег на 10% от предыдущего значения.
    По данному числу y определите номер дня, на который пробег спортсмена составит не менее y километров.
    Например, при вводе 10 20 программа должна вывести 9. x и y – действительные числа, ответ – целое число.

    x   y   answer

    10  20  9
    -1  0   Uncorrect X
*/

#include <iostream>
#include <cstdlib>

using namespace std;

bool isValid(int x){
    return (x > 0);
}

int main(){

    double x, y;

    cout << "Insert X > 0 \n";
    cin >> x;

    while(!isValid(x)){
        cout << "Uncorrect X, X should be > 0 \n";
        cin >> x;
    }

    cout << "Insert Y > 0 \n";
    cin >> y;

    while(!isValid(y)){
        cout << "Uncorrect Y, Y should be > 0 \n";
        cin >> y;
    }

    //Уже прошел один день пробежки
    int days = 1;
    while( x <= y ){
        x += (x / 10);
        ++days;
    }

    cout << days;

    //system("pause");
    //return 0;
}

