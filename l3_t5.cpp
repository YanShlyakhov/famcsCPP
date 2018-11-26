/*
Найти k-ую цифру в ряду цифр, составленных из подряд идущих натуральных чисел, начиная с 1: 12345678910111213…

in     out

10     0

100    5

0      1
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int countOfDigits(int n){
    int result = 1;
    while(n/=10) result++;
    return result;
}

namespace patch{
    //Пернгрузка оператора to_string, MinGW не поддерживает почему-то, лечится только патчем
    template < typename T > std::string to_string( const T& n ){
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int main(){
    int k;

    cout << "Insert k\n";
    cin >> k;
    while (k < 0){
        cout << "K should be bigger than 0\n";
        cin >> k;
    }

    cout << "Use string [Y/n]?\n";
    char x;
    cin >> x;
    while (x != 'y' && x != 'Y' && x != 'n' && x != 'N'){
        cout <<"[Y/n]?";
        cin >> x;
    }

    if(x == 'y' || x == 'Y'){
        string s = "";
        for( int i = 1; s.size() <= k ; ++i ){
            s += patch::to_string(i);
        }
        cout << s[k];
    }else{
        int sequenceLength = 0;
        int i = 1;
        while(countOfDigits(i) < k){
            k -= countOfDigits(i);
            ++i;
        }

        k = countOfDigits(i) - k;
        while(k){
            i/=10;
            --k;
        }
        cout << i%10 <<"\n";
    }

    system("pause");
    return 0;
}

