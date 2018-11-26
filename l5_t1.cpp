/*
    Дана квадратная матрица n-го порядка, состоящая из целых чисел.
    Определить является ли она магическим квадратом (Магический квадрат — квадратная таблица n × n,
    заполненная n^2 различными числами таким образом, что сумма чисел в каждой строке,
    каждом столбце и на обеих диагоналях одинакова). Для решения задачи использовать функцию поиска суммы элементов
    i-того столбца и строки, массив передается в функцию через указатель.

INPUT
3
2 7 6
9 5 1
4 3 8
OUTPUT
Yes, The square is Magic

============================================

INPUT
1
10
OUTPUT
No, The square is not Magic

INPUT
3
1 2 3
4 5 6
7 8 9
OUTPUT
No, The square is not Magic


*/

#include<iostream>
#include<cstdlib>

using namespace std;

const int MAX_VAL = 1000;

void read(int &n){
    cout <<"Insert N > 0\n";
    cin >> n;
    while(n < 0){
        cout <<"Insert N > 0\n";
        cin >> n;
    }
}

int rowColumnSum(int **a, int n, int idx, bool isRow){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += (isRow)?(a[idx][i]):(a[i][idx]);
    }
    return sum;
}

int main(){
    int n;
    read(n);

    bool isMagic = true;

    int **a = new int*[n];
    for (int i = 0; i < n; ++i){
        a[i] = new int[n];
    }

    int p[n*n];
    int nPower = n*n;

    for(int  i =0; i<=nPower; ++i){
        p[i] = 0;
    }

    for(int i=0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            cin >> a[i][j];
            if(a[i][j]>nPower){
                isMagic = false;
            }
            p[a[i][j]]++;
            if(p[a[i][j]] >= 2){
                isMagic = false;
            }
        }
    }

    int fDiag = 0;
    int sDiag = 0;
    int sum = rowColumnSum(a, n, 0, true);

    for (int i = 0; i < n; ++i){
        fDiag += a[i][i];
        sDiag += a[n - i - 1][n - i - 1];
        if (rowColumnSum(a, n, i, true) != sum && rowColumnSum(a, n, i, false) != sum){
            isMagic = false;
            break;
        }
    }

    if(fDiag != sum || sDiag != sum){
        isMagic = false;
    }

    if(isMagic){
        cout << "\nYes, The square is Magic";
    }else{
        cout << "\nNo, The square is not Magic";
    }

    for (int i = 0; i < n; ++i){
        delete[] a[i];
    }
    delete[] a;

    system("pause");
    return 0;
}
