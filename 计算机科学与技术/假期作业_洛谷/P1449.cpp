//栈
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main(){
    string s;
    getline(cin, s);   
    stack<int> numbers;
    stack<char> op;
    for(int i = 0; i < s.size(); i ++){
        int num = 0;
        int flag = 0;
        while(s[i] >= '0' && s[i] <= '9'){
            num = num*10 + s[i] - '0';
            i ++;
            flag = 1;
        }
        if(flag) {
            numbers.push(num);
            continue;
        }
        int a, b;
        switch(s[i]){
            case '+':
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                numbers.push(b+a);
                break;
            case '-':
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                numbers.push(b-a);
                break;
            case '*':
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                numbers.push(a*b);
                break;
            case '/':
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                numbers.push(b/a);
                break;
            default:
                break;
        }
    }
    cout << numbers.top() << '\n';
    return 0;
}