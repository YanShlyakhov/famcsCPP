/*
    Реализовать 4 функции на простейшие арифметические операции
    (+, -, *, /).
    Каждая функция должна принимать два вещественных числа и возвращать результат операции в виде вещественного числа.
    Напишите функцию, которая принимает указатель на функцию в качестве параметра.

    input
    2 3 +
    output
    5

    input
    3 4 -
    output
    -1

    input
    1 3 /
    output
    0.333333

    input
    0 3 *
    output
    0
*/
#include <iostream>
#include <cstdlib>

using namespace std;

double sum(double a, double b){
    return a + b;
}

double mult(double a, double b){
    return a * b;
}

double diff(double a, double b){
    return a - b;
}

double div(double a, double b){
    return a / b;
}

double engine(double a, double b, double (*cmp)(double, double )){
    return (*cmp)(a, b);
}

int main(){
    cout <<"Many command: \n\t+ Sum\n\t- Diff\n\t* Mult\n\t/ Div \n\te Exit  \n";
    double a, b;
    char c;
    bool isWorking = true;
    while(isWorking){
        cout <<"Insert two doubles:\n";
        cin >> a >> b;
        cout <<"Operation:\n";
        cin >> c;
        double (*cmp)(double, double) = NULL;
        if(c == '+'){
            cmp = &sum;
        }
        if(c == '*'){
            cmp = &mult;
        }
        if(c == '-'){
            cmp = &diff;
        }
        if(c == '/'){
            while(b == 0){
                cout << "B should be not zero!\n";
                cin >> b;
            }
            cmp = &div;
        }
        if(c == 'e'){
            cout<<"Exit.\n";
            isWorking = false;
            break;
        }
        cout << engine(a, b, cmp)<<"\n";
    }

    system("pause");
    return 0;
}
