/*
ряд фарея
Напечатать в порядке возрастания все простые несократимые дроби,
заключенные между 0 и 1, знаменатели которых меньше заданного числа n.

in     out

100    3003

12     43

0      error
*/

#include <iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

namespace patch{
    //Пернгрузка оператора to_string, MinGW не поддерживает почему-то, лечится только патчем
    template < typename T > std::string to_string( const T& n ){
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std;

int gcd(int x, int y){
    while(x != 0 && y != 0){
        if(x > y){
            x %= y;
        }else{
            y %= x;
        }
    }
    return x + y;
}

int main(){

    int n;

    cout << "Insert n\n";
    cin >> n;

    while( n <= 0 ){
        cout << "N should be bigger than 0\n";
        cin >> n;
    }

    /*
        gcd(x, y) -- алгоритм Евклида для поиска НОД
        __gcd(x, y) -- алгоритм Евклида для поиска НОД в STD
    */

    int countOfResult = 0;
    vector< pair<float, string> > resultArray;
    for (int i = 2; i < n; ++i){
        for (int j = 1; j < i; ++j)
            if (gcd(i, j) == 1){
                pair<float, string> cur;
                cur.first = (float)j / (float)i;
                cur.second = patch::to_string(j) + "/" + patch::to_string(i);
                resultArray.push_back(cur);
                countOfResult++;
            }
    }
    //Компоратор писать не надо, т.к. std::sort сортирует по первому из ключей в pair<>
    sort(resultArray.begin(), resultArray.end());

    cout << countOfResult<<"\n";

    for(int i = 0; i<resultArray.size(); ++i){
        cout << resultArray[i].second <<"\n";
    }

    system("pause");
    return 0;
}

