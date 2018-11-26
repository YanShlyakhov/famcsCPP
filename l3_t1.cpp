/*
    Найти количество различных цифр в записи заданного натурального числа n
    (разработать алгоритмы с использованием и без использования массивов).

    in    out
    50    2
    23    2
    123   3
    111   1
    100   2
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

     int n;

     cout << "Insert n\n";
     cin >> n;

     while( n < 0 ){
        cout << "N should be bigger than 0\n";
        cin >> n;
     }

     cout << "Use array [Y/n]?\n";
     char x;
     cin >> x;
     while (x != 'y' && x != 'Y' && x != 'n' && x != 'N'){
        cout <<"[Y/n]?";
        cin >> x;
     }
     if(x == 'y' || x == 'Y'){
        /*
            O( len(n) + 10 )
        */
         int a[10];
         for( int  i = 0; i < 10; ++i ){
            a[i] = 0;
         }

         while( n > 0 ){
            int x = n % 10;
            n /= 10;
            a[x] = 1;
         }

         int result = 0;
         for( int i = 0; i < 10; ++i ){
            result += a[i];
         }
         cout << result;
     }else{
        /*
            O( len(n) * 10 )
        */
         int countDig = 0;
         const int CONST_N = n;

         for (int i = 0; i<=9; ++i){
             int curN = CONST_N;
             while (curN > 0){
                int curLastDig = curN % 10;
                if(curLastDig == i){
                    countDig++;
                    break;
                }
                curN /= 10;
             }
         }
         cout << countDig;
     }
     system("pause");
     return 0;
}
