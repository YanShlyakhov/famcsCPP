/*
    Рациональная (несократимая) дробь представляется парой целых чисел (a,b),
    где a – числитель, b – знаменатель. Создать класс Rational для работы с рациональными дробями.
    Реализовать конструкторы: копирования и инициализации, а также методы:
        a.	сложение add, (a,b) + (c,d) = (ad+bc,bd);
        b.	умножение mul, (a,b) * (c,d) = (ac, bd);
        c.	деление div, (a,b)/(c,d) = (ad,bc);
        d.	сравнение equal, greater, less;
        e.	вывод print.
*/
#include <iostream>
#include <ostream>

using namespace std;

class Rational{

    private:
        int n, m;
    public:

    Rational(){
        n = 0;
        m = 1;
    }

    Rational(int x){
        n = x;
        m = 1;
    }

    Rational(int x, int y){
        n = x;
        m = y;
    }

    int numerator() const{
        return n;
    }

    int denominator() const{
        return m;
    }

    Rational& operator=(const Rational& rhs){
        n = rhs.numerator();
        m = rhs.denominator();
    }
};

ostream& operator<<(ostream& t,const Rational& c){
    t << c.numerator() << "/" << c.denominator();
    return t;
}

class RationalEngine{
    private:
        Rational reduction(Rational x){
            int n = x.numerator();
            int m = x.denominator();
            while(n!=0 && m!=0){
                (n>m)?n%=m:m%=n;
                swap(n,m);
            }
            int d = n + m;
            return Rational(x.numerator() / d, x.denominator() / d);
        }

        const int cmp(const Rational& left, const Rational& right){
            Rational a = reduction(left);
            Rational b = reduction(right);

            if(a.numerator() == b.numerator() && a.denominator() == b.denominator()){
                return 0;
            }

            if(a.numerator() > b.numerator() && a.denominator() <= b.denominator()){
                return 1;
            }
            if(a.numerator() < b.numerator() && a.denominator() >= b.denominator()){
                return -1;
            }
        }

    public:
        RationalEngine(){}
        //RationalEngine(int x, int y):Rational(x, y){}

        const Rational add(const Rational& left, const Rational& right){
            int n = left.numerator() * right.denominator() + left.denominator() * right.numerator();
            int m = left.denominator() * right.denominator();
            return reduction(Rational(n,m));
        }

        const Rational mul(const Rational& left, const Rational& right){
            int n = left.numerator() * right.numerator();
            int m = left.denominator() * right.denominator();
            return reduction(Rational(n,m));
        }

        const Rational div(const Rational& left, const Rational& right){
            int n = left.numerator() * right.denominator();
            int m = left.denominator() * right.numerator();
            return reduction(Rational(n,m));
        }

        const bool equal(const Rational& left, const Rational& right){
            if(cmp(left, right) == 0){
                return true;
            }else{
                return false;
            }
        }

        const bool greater(const Rational& left, const Rational& right){
            if(cmp(left, right) == 1){
                return true;
            }else{
                return false;
            }
        }

        const bool less(const Rational& left, const Rational& right){
            if(cmp(left, right) == -1){
                return true;
            }else{
                return false;
            }
        }

        const void print(const Rational& c){
            cout << c.numerator() <<"/"<<c.denominator();
        }
};

int main(){
    Rational a(1, 2);
    Rational b(3, 4);
    RationalEngine Engine;
    cout << Engine.mul(a,b);
}
