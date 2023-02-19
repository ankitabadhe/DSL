//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//int evalPostfix(string exp)
//{
//    stack<int> stack;
//
//    for (char c: exp)
//    {
//        if (c >= '0' && c <= '9') {
//            stack.push(c - '0');
//        }
//        else {
//            int x = stack.top();
//            stack.pop();
//
//            int y = stack.top();
//            stack.pop();
//
//            if (c == '+') {
//                stack.push(y + x);
//            }
//            else if (c == '-') {
//                stack.push(y - x);
//            }
//            else if (c == '*') {
//                stack.push(y * x);
//            }
//            else if (c == '/') {
//                stack.push(y / x);
//            }
//        }
//    }
//
//    return stack.top();
//}
//
//int main()
//{
//    string exp = "218*+";
//
//    cout << evalPostfix(exp);
//
//    return 0;
//}
//


#include <iostream>
using namespace std;
#include <string.h>
// #define size=50
char s[50];
int top = 0, ele;
void push(char);
char pop();
char in[30], post[30];
int prec(char c)
{
if (c == '(' || c == ')')
return 0;
if (c == '+' || c == '-')
return 1;
if (c == '*' || c == '/')
return 2;
if (c == '^')
return 3;
}
void push(char c)
{
s[top] = c;
top++;
}
char pop()
{
top--;
return (s[top]);
}
int main()
{
int i = 0, j = 0, length;
char temp;
cout << "Enter infix expression=";
cin >> in;
length = strlen(in);
for (i = 0; i < length; i++)
{
if (in[i] != '+' && in[i] != '-' && in[i] != '*' && in[i] != '/' && in[i] != '^' && in[i] != ')' && in[i]
!= '(')
{
post[j++] = in[i];
}
else
{
	if (top == 0)
{
push(in[i]);
}
else
{
if (in[i] != ')' && in[i] != '(')
{
if (prec(in[i]) <= prec(s[top - 1]))
{
temp = pop();
post[j++] = temp;
push(in[i]);
}
else
{
push(in[i]);
}
}
else
{
if (in[i] == '(')
{
push(in[i]);
}
if (in[i] == ')')
{
temp = pop();
while (temp != '(')
{
post[j++] = temp;
temp = pop();
}
}
}
}
}
}
while (top != 0)
{
post[j++] = pop();
}
cout << "Postfix Expression is=" << post;
}

