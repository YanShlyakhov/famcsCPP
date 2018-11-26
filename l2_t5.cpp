/*
    Yan Shlyakhau 05.09.2018

    day month year  answer

    1   13    0     Uncorrect Month, Month should be 1..12

    29  2     4     01.03.4

    1   9     2000  02.09.2000

    31  4     100   Uncorrect Day, Day should be 1..30

    29  2     7     Uncorrect Day, Day should be 1..28

    32  1     2000  Uncorrect Day, Day should be 1..31
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const string BAD_MONTH_ERROR = "Uncorrect Month, Month should be 1..12 \n";
const string BAD_DAY_ERROR = "Uncorrect Day, Day should be 1..";
const string BAD_YEAR_ERROR = "Uncorrect Year, Year should be bigger than zero.";

/*
    На вход:
        year -- год
    На выход:
        true  -- високосный
        false -- невисокосный
    in     out
     2000   True
     2100   False
     4      True
*/
bool isLeapYear(int year){

    bool answer = false;

    if( year % 4 == 0 && year % 100 != 0 ){
        answer = true;
    }

    if( year % 400 == 0 ){
        answer = true;
    }

    return answer;
}

/*
    Входные данные:
       0 <  day   < 32
       0 <  month < 13
       0 <  year (до р.х. не рассматриваются)

       in          out
        1 1 1       01.01.1
*/
void printData(int day, int month, int year){
    if(day < 10){
        cout << "0" << day;
    }else{
        cout << day;
    }
    cout <<".";
    if(month < 10){
        cout << "0" << month;
    }else{
        cout << month;
    }
    cout <<"."<< year <<"\n";
}

int main(){

    //Не const, т.к. возможен високосный год
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int day, month, year;

    cout << "Insert day month year \n";
    cin >> day >> month >> year;

    while ( year < 0 ){
        cout << BAD_YEAR_ERROR;
        cin >> year;
    }

    /*
        Год не имеет значения
        Месяц от 1 до 12
        День зависит от месяца и года
    */

    //Проверка на високосный год
    bool leapYear = isLeapYear( year );

    while( month > 12 || month < 0 ){
        cout << BAD_MONTH_ERROR;
        cin >> month;
    }

    if(leapYear){
        ++daysInMonth[1];
    }

    while( day > daysInMonth[ month - 1 ] || day<0 ){
        cout << BAD_DAY_ERROR << daysInMonth[ month - 1 ] <<" \n";
        cin >> day;
    }

    //Вывод
    if( month == 12 && day == 31 ){
        day = 1;
        month = 1;
        year++;
    }else if( day == daysInMonth[ month - 1 ] ){
        day = 1;
        month++;
    }else {
        day++;
    }

    printData( day, month, year );
    system("pause");
    return 0;
}

