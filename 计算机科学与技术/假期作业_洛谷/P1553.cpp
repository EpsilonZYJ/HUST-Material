#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
using ll = unsigned long long;

int myFind(string s, char c){
    for(int i = 0; i < s.size(); i ++)
        if(s[i] == c)
            return 1;
    return 0;
}

ll reverse(ll s){
    ll x = 0;
    while(s){
        x = x*10 + s%10;
        s /= 10;
    }
    return x;
}

int main(){
    string s;
    cin >> s;
    istringstream iss(s);
    ll a, b;
    char trash;
    int flag = myFind(s, '.') + myFind(s, '/')*2 + (s[s.size()-1] == '%')*3;
    switch(flag){
        case 0:
            iss >> a;
            cout << reverse(a) << '\n';
            break;
        case 1:
            iss >> a;
            iss >> trash;
            iss >> b;
            cout << reverse(a) << '.' << reverse(b) << '\n';
            break;
        case 2:
            iss >> a;
            iss >> trash;
            iss >> b;
            cout << reverse(a) << '/' << reverse(b) << '\n';
            break;
        case 3:
            iss >> a;
            cout << reverse(a) << '%' << '\n';
            break;
        default:
            break;
    }
    return 0;
}