/*
    Пусть дана без ошибок формула, имеющая следующий синтаксис:
    <формула>::=<цифра> | max(<формула>, < формула >) | min (<формула>,< формула >)
    <цифра>::=0  1  2  3  4  5  6  7  8   9
    Например, 8 или max(4, min(3, 5)) или  min(min(3, 5), max(2, max(3, 4))).
    Вычислить значение формулы, используя структуру данных стек.

    input
        min(max(3,4),max(10,5))
    output
        4

*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

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

int main(){
    string s;
    cin >> s;
    Stack<int> num;
    Stack<char> op;

    int i = 0;

    while(s[i]){
        // mAx mIn (разница между функциями одна буква)
        if (s[i] == 'a' || s[i] == 'i'){
            op.push(s[i]);
            i+=2;
        }
        else if (isdigit(s[i]) || s[i] == '-'){
            num.push(s[i]-'0');
            while (isdigit(s[i]) || s[i] == '-') i++;
        }
        else if (s[i] == ')') {
            int operand1, operand2, operation;
            operation = op.pop();
            operand2 = num.pop();
            operand1 = num.pop();
            switch(operation){
                case 'a':
                    num.push(max(operand1, operand2));
                    break;
                case 'i':
                    num.push(min(operand1, operand2));
                    break;
            }
            i++;
        }
        else
            if (s[i] == '(' || s[i] == ' ' || s[i] == ',' || s[i] == 'm') i++;
    }
    cout<<num.pop()<<"\n";
    system("pause");
    return 0;
}

