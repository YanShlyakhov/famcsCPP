/*
    Написать функцию, которая производит двоичный поиск места размещения нового элемента в упорядоченном массиве
    и возвращает указатель на место включения нового элемента. С помощью данной функции реализовать сортировку вставками.

    INPUT
    5
    5 4 3 2 1
    OUTPUT
    1 2 3 4 5

*/
#include <iostream>
#include<cstdlib>

using namespace std;

float* binSearch(float* a, int n, float key){
    int l = 0, r = n;
    while (l < r){
        int m = (l + r) / 2;
        if (a[m] < key)
            l = m+1;
        else
            r = m;
    }
    return a+l;
}

void binInsertionSort(float* a, int n){
    for (int i = 1; i < n; i++){
        float* k = binSearch(a, i, a[i]);
        for (int j = i-1; j >= (k-a); j--)
            swap(a[j], a[j+1]);
    }
}

void qsort(float* a, int l, int r){
    int left = l;
    int rigth = r;
    int mid = rand()%(r-l) + l;

    while(left <= rigth){
        while(a[left] < a[mid])left++;
        while(a[rigth] > a[mid])rigth--;
        if(left <= rigth){
            float buff = a[left];
            a[left] = a[rigth];
            a[rigth] = buff;
            left++;
            rigth--;
        }
    }

    if(l < rigth)qsort(a, l, rigth);
    if(left < r)qsort(a, left, r);
}

int main(){
    int n;
    cin >> n;
    float *a = new float[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    binInsertionSort(a, n);
    //qsort(a, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << a[i] <<  ' ';

    delete[] a;
    system("pause");
    return 0;
}
