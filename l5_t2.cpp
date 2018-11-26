/*

Заполнить квадратную матрицу (n x n) натуральными четными числами 2,4,6,8,... по сходящейся к центру линии ( по спирали).

INPUT
3
OUTPUT
2 4 6
16 18 8
14 12 10
==============================
INPUT
5
OUTPUT
2 4 6 8 10
32 34 36 38 12
30 48 50 40 14
28 46 44 42 16
26 24 22 20 18
==============================
INPUT
1
OUTPUT
2

*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n, p=1,l=0,r, v = 0, z, c = 0;
    cin >>n;
    r = n;
    z = n;
    int a[101][101];
    while(r-l>0&&z-v>0){
        if(p == 1){
            for(int i=l; i<r; i++){
                c++;
                a[v][i] = c*2;
            }
            v++;
            p = 2;
            continue;
        }
        if(p == 2){
           // cout << v <<" "<<z;
            for(int i = v; i<z; i++){
                c++;
                a[i][r-1] = c*2;
            }
            r--;
            p =3;
            continue;
        }
        if(p == 3){
           // cout <<l <<" "<< r <<"\n";
            for(int i=r-1; i>=l; i--){
                c++;
                a[z-1][i] = c*2;
            }
            z--;
            p = 4;
            continue;
        }
        if(p == 4){
            for(int i=z-1; i>=v; i--){
                c++;
                a[i][l] = c*2;
            }
            l++;
            p =1;
            continue;
        }
    }
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    system("pause");
    return 0;
}
