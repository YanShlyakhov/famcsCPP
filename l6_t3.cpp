/*
    Реализовать 4 функции. Добавьте меню, в котором пользователь может выбрать желаемую операцию:
        a.	Создать функцию, вставляющую строку в двумерный динамический массив в указанную позицию.
        b.	Создать функцию, вставляющую столбец в двумерный динамический массив в указанную позицию.
        c.	Создать функцию, удаляющую заданную строку двумерного динамического массива.
        d.	Создать функцию, удаляющую заданный столбец двумерного динамического массива.

    input

    2 3
    1 2 3
    4 5 6

    output
    (1, 1, 1 2 3)
    1 2 3
    1 2 3
    4 5 6

    (2, 1, 3 4 5)
    3 1 2 3
    4 1 2 3
    5 4 5 6

    (3, 1)
    4 1 2 3
    5 4 5 6

    (4, 1)
    1 2 3
    4 5 6

    (5) Exit.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int**& a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

void insertLine(int**& a, int& n, int m, int k, int*ins){
    int **b = new int*[n+1];
    for (int i = 0; i < n+1; i++)
        b[i] = new int[m];

    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < m; j++){
            if (i < k){
                b[i][j] = a[i][j];
            }else if (i == k){
                b[i][j] = ins[j];
            }
            else{
                b[i][j] = a[i-1][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    a = b;
    n = n+1;
}

void insertColumn(int**& a, int n, int& m, int k, int*ins){
    int **b = new int*[n];
    for (int i = 0; i < n; i++){
        b[i] = new int[m+1];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m+1; j++){
            if (j < k){
                b[i][j] = a[i][j];
            }else if (j == k){
                b[i][j] = ins[i];
            }else{
                b[i][j] = a[i][j-1];
            }
        }
    }

    for (int i = 0; i < n; i++){
        delete[] a[i];
    }
    delete[] a;

    a = b;
    m = m+1;
}

void deleteLine(int**& a, int& n, int m, int k){
    int **b = new int*[n-1];
    for (int i = 0; i < n-1; i++){
        b[i] = new int[m];
    }

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < m; j++){
            if (i < k){
                b[i][j] = a[i][j];
            }else{
                b[i][j] = a[i+1][j];
            }
        }
    }

    for (int i = 0; i < n; i++){
        delete[] a[i];
    }
    delete[] a;

    a = b;
    n = n-1;
}

void deleteColumn(int**& a, int n, int &m, int k){
    int **b = new int*[n];
    for (int i = 0; i < n; i++){
        b[i] = new int[m-1];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m-1; j++){
            if (j < k){
                b[i][j] = a[i][j];
            }else{
                b[i][j] = a[i][j+1];
            }
        }
    }

    for (int i = 0; i < n; i++){
        delete[] a[i];
    }
    delete[] a;

    a = b;
    m = m-1;
}

int main(){
    cout << "Input array dimensions: ";
    int n, m;
    cin >> n >> m;
    int** a = new int*[n];
    for (int i = 0; i < n; i++){
        a[i] = new int[m];
    }

    cout << "Input array elements:\n\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    char c;

    bool isWorking = true;
    while(isWorking){\
        cout << "\nSelect operation:\n" << "\t1. Insert line\n" << "\t2. Insert column\n"
                                        << "\t3. Delete line\n" << "\t4. Delete column\n"
                                        << "\t5. Exit.\n" << "Your's choice(1-5): ";
        cin >> c;
        int k, p;
        int* ins;
        if(c == '5'){
            cout << "End of work. Have a nice day! ";
            isWorking = false;
            break;
        }

        cout << "\nLine/Column: ";
        cin >> k;
        k--;

        if (c == '1' || c == '2'){
            p = (c=='1') ? m:n;
            ins = new int[p];
            cout << "Input line/column (" << p << " numbers): ";
            for (int i = 0; i < p; i++){
                cin >> ins[i];
            }
        }

        switch (c){
            case '1': insertLine(a, n, m, k, ins); break;
            case '2': insertColumn(a, n, m, k, ins); break;
            case '3': deleteLine(a, n, m, k); break;
            case '4': deleteColumn(a, n, m, k); break;
            case '5': isWorking = false; break;
        }

        cout << "\nResulting array:\n\n";
        printArray(a, n, m);
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    system("pause");
    return 0;
}
