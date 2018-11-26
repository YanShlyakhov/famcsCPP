/*
    Yan Shlyakhau 05.09.2018

    По данному натуральному числу n найдите сумму чисел 1+1/1!+1/2!+1/3!+...+1/n!.
    Количество действий должно быть пропорционально n.
    Напишите программу, которая считывает значение n и выводит результат в виде действительного числа.
    К чему будет стремиться эта сумма при росте числа n? (К числу е)

    n       answer
    2       2.5
    7       2.71825
    -1      Uncorrect N, N should be > 0
*/

#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long fact[20];

const string VALUE_ERROR = "Uncorrect N, N should be > 0 \n";

bool isValid(int x){
    return (x > 0);
}

/*
    Процедура для подсчета факториала от 1 до n



    input output (массив fact)
    1      1 1
    0      1 1
    5      1 1 2 6 24 120
    6      1 1 2 6 24 120 720
*/
void makeFactorial(int n){
    fact[0] = 1;
    fact[1] = 1;
    for( int i = 2; i <= n; ++i )
        fact[i] = fact[i-1] * i;
}

int main(){

    int n;

    /*
        18! -- максимум
        Иначе будут исользоваться вещественные числа и понизится точность
        или длинная арифметика и увеличиться сложность алгоритма -> скорость работы
    */

    cout << "Insert N, 0 < N < 18 \n";
    cin >> n;

    while(!isValid(n)){
        cout << VALUE_ERROR;
        cin >> n;
    }

    makeFactorial( n );

    double sumOfSequence = 0;
    for( int i = 0; i <= n; ++i ){
        // 1 -- целое, 1.0 -- вещественное
        sumOfSequence += (1.0 / fact[i]);
    }

    cout << sumOfSequence << "\n";

    system("pause");
    return 0;
}

