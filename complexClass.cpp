#include <iostream>
#include <ostream>
#include <cmath>

using namespace std;
class  Complex{
    private:
        float re,im;

    public:
        Complex(float x,float y){
            re=x;
            im=y;
        }

        float Re() const{
            return re;
        }

        float Im() const {
            return  im;
        }

        Complex& operator=(const Complex& rhs){
            re = rhs.Re();
            im = rhs.Im();
        }

        float length(){
            return sqrt(re*re + im*im);
        }
        friend const Complex operator+(const Complex& left, const Complex& right);
        friend const Complex operator-(const Complex& left, const Complex& right);
        friend const Complex operator*(const Complex& left, const Complex& right);
        friend const Complex operator/(const Complex& left, const Complex& right);
        friend bool operator==(const Complex& left, const Complex& right);
        friend bool operator >(const Complex& left, const Complex& right);
        friend bool operator <(const Complex& left, const Complex& right);
};


const Complex operator-(const Complex& left, const Complex& right){
    return Complex(left.Re() - right.Re(), left.Im() - right.Im());
}

const Complex operator*(const Complex& left, const Complex& right){
    float a = left.Re();
    float b = left.Im();
    float c = right.Re();
    float d = right.Im();
    return Complex(a*c - b*d, a*d + b*c);
}

const Complex operator/(const Complex& left, const Complex& right){
    float a = left.Re();
    float b = left.Im();
    float c = right.Re();
    float d = right.Im();
    return Complex((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
}

bool operator==(const Complex& left, const Complex& right){
    float a = left.Re();
    float b = left.Im();
    float c = right.Re();
    float d = right.Im();
    return (a==c && b==d);
}

bool operator >(Complex& left, Complex& right){
    return (left.length() > right.length());
}

bool operator <(Complex& left, Complex& right){
    return (left.length() < right.length());
}

ostream& operator<<(ostream& t,const Complex& c){
    t << c.Re() << " " << c.Im();
    return t;
}

template <class T>
class Stack {
    public:
        Stack():top(0) {
            cout << "In Stack constructor\n";
        }
        ~Stack() {
            cout << "In Stack destructor\n";
            while ( !isEmpty() ) {
                pop();
            }
            isEmpty();
        }

        void push (const T& object);
        T pop();
        const T& topElement();
        bool isEmpty();

    private:
        struct StackNode {
            T data;                     // data at this node
            StackNode *next;            // next node in list

            // StackNode constructor initializes both fields
            StackNode(const T& newData, StackNode *nextNode)
                : data(newData), next(nextNode) {}
        };

        Stack(const Stack& lhs) {}
        StackNode *top;                 // top of stack
};

template <class T>
void Stack<T>::push(const T& obj) {
    cout << "In PUSH Operation\n";
    top = new StackNode(obj, top);
}

template <class T>
T Stack<T>::pop() {
    cout << "In POP Operation\n";
    if ( !isEmpty() ) {
        StackNode *topNode = top;
        top = top->next;
        T data = topNode->data;
        delete topNode;
        return data;
    }
    //return 0;
}

template <class T>
const T& Stack<T>::topElement() {
    cout << "Check Top Stack\n";
    if ( !isEmpty() ) {
        return top->data;
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    if (top == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
class Queue {

    public:
        Queue():first(NULL),last(NULL) {
            cout << "In Queue constructor\n";
        }
        ~Queue() {
            cout << "In Queue destructor\n";
            while ( !isEmpty() ) {
                pop();
            }
            isEmpty();
        }

        void push (const T& object);
        T pop();
        const T& topElement();
        bool isEmpty();

    private:
        struct QueueNode {
            T info;
            QueueNode *next;

            QueueNode(const T& newData, QueueNode *nextNode)
                    : info(newData), next(nextNode) {}
        };

    Queue(const Queue& lhs) {}
    QueueNode *first;
    QueueNode *last;

};

template <class T>
void Queue<T>::push(const T& obj) {
    cout << "In PUSH Queue Operation\n";
    QueueNode *temp = new QueueNode(obj, NULL);
    if (first != NULL){
        last->next = temp;
        last = temp;
    } else first = last = temp;
}

template <class T>
T Queue<T>::pop() {
    cout << "In POP Operation\n";
    cout << first->info<<"\n";
    if ( !isEmpty() ) {
        T data = first->info;
        first = first->next;
        return data;
    }
}

template <class T>
const T& Queue<T>::topElement() {
    cout << "Check Top Queue\n";
    if ( !isEmpty() ) {
        return first->info;
    }
}

template <class T>
bool Queue<T>::isEmpty() {
    if (first == NULL) {
        return true;
    }
    else {
        return false;
    }
}

int main(){
    Complex s(5, 6);
    Complex p(2, 3);

    Queue <Complex> qu;
    //Stack <Complex> st;
    //st.push(s);
    //st.push(p);

    qu.push(s);
    qu.push(p);
    //cout << st.pop() <<"\n";
    cout << qu.pop() <<"\n";

    return 0;
}
