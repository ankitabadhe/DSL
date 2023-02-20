#include <bits/stdc++.h>
using namespace std;

double applyOperator(char op, double b, double a) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        default:
            return 0;
    }
}

double evaluatePostfix(string postfix) {
    stack<double> s;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            double num = c - '0';
            s.push(num);
        }
        else if (c == ' ') {
            continue;
        }
        else {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            double result = applyOperator(c, b, a);
            s.push(result);
        }
    }
    return s.top();
}

int main() {

    
    string postfix;
	cout<<"Enter a string \n"; 
	cin>>postfix;
    double result = evaluatePostfix(postfix);
    cout << result << endl;
    return 0;
}


