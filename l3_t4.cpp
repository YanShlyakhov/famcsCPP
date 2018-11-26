/*
Для заданного n найти все меньшие его совершенные числа
(совершенным называется число, равное сумме всех своих делителей, не равных самому числу).

in     out

100    6
       28

12     6
       1

0      error
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
вынести

*/

int amountOfDividers(int x){
    int sum = 0;
    int sqrtOfX = trunc(sqrt(x)) + 1;
    for( int i = 1; i < sqrtOfX; ++i ){
        if( x % i == 0 ){
            sum += i;
            if(i != x/i){ //TODO вынести
                sum += x/i;
            }
        }
    }
    return sum - x;
}

int main(){

    int n;

    cout << "Insert n\n";
    cin >> n;

    while( n <= 0 ){
        cout << "N should be bigger than 0\n";
        cin >> n;
    }

    int result = 0;
    for( int i = 1; i < n; ++i ){
        if( i == amountOfDividers(i) ){
            cout << i <<"\n";
            result++;
        }
    }

    cout << result;
}

