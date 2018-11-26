/*
    Дано математическое выражение в
    виде строки символов. Напишите программу, которая определит, правильно ли расставлены скобки в выражении,
    если оно состоит из скобок типа: ( ) [ ] { }. (использовать структуру данных стек).

    input
    (())()
    output
    Ok

    input
    )(
    output
    UnCorrect

    input
    ()()()
    output
    Ok.

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
    Stack<char> st;
    bool isCorrect = true;
    for(int i =0; i<s.size(); ++i){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
            continue;
        }
        if(s[i] == ')' || s[i] == '}' || s[i] == ']' && !st.isEmpty()){
            char cur = st.pop();
            if(!((cur == '(' && s[i]==')')||(cur == '{' && s[i]=='}')||(cur == '[' && s[i]==']'))){
                isCorrect = false;
                break;
            }
        }
    }
    if(isCorrect){
        cout <<"Ok."<<"\n";
    }else{
        cout <<"UnCorrect."<<"\n";
    }
    system("pause");
    return 0;
}
