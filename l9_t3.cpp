/*
    Дана строка, которая представляет собой исходное математическое выражение,
    содержащее целые числа, операции +,  *, -, /  и скобки любой степени вложенности.
    Перевести его в обратную польскую запись и вычислить значение записанного выражения.

    input
        (2+2)*3/4
    output
        3
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
        T back();
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
T Stack<T>::back() {
    cout << "In POP Operation\n";
    if ( !isEmpty() ) {
        return top->data;
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

bool delim (char c) {
	return c == ' ';
}

bool isOp (char c) {
	return c=='+' || c=='-' || c=='*' || c=='/' || c=='%';
}

int priority (char op) {
	return
		op == '+' || op == '-' ? 1 :
		op == '*' || op == '/' || op == '%' ? 2 :
		-1;
}

void processOp (Stack<int> & st, char op) {
	int r = st.pop();
	int l = st.pop();
	switch (op) {
		case '+':  st.push(l + r);  break;
		case '-':  st.push(l - r);  break;
		case '*':  st.push(l * r);  break;
		case '/':  st.push(l / r);  break;
		case '%':  st.push(l % r);  break;
	}
}

int calc (string & s) {
    Stack<int> st;
    Stack<char> op;
	for (size_t i=0; i<s.length(); ++i)
		if (!delim (s[i]))
			if (s[i] == '(')
				op.push('(');
			else if (s[i] == ')') {
				while (op.back() != '(')
					processOp (st, op.pop());
				op.pop();
			}
			else if (isOp (s[i])) {
				char curop = s[i];
				while (!op.isEmpty() && priority(op.back()) >= priority(s[i]))
					processOp (st, op.pop());
				op.push(curop);
			}
			else {
				string operand;
				while (i < s.length() && isalnum (s[i]))
					operand += s[i++];
				--i;
				if (isdigit (operand[0]))
					st.push(atoi (operand.c_str()));
			}
	while (!op.isEmpty())
		processOp (st, op.pop());
	return st.pop();
}

int main(){
    string s;
    cin >> s;
    cout<<calc(s)<<"\n";
    system("pause");
    return 0;
}
