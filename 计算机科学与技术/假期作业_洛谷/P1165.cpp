#include <iostream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using ull = unsigned long long;

ull base[2000050];
int p;


int main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int n;
    p = 0;
    base[0] = 0;
    std::cin >> n;
    for(int i = 0; i < n; i ++){
        ull op;
        std::cin >> op;
        switch(op){
            case 0:
                std::cin >> op;
                base[p + 1] = MAX(base[p], op);
                p++;
                break;
            case 1:
                if(p) p --;
                break;
            case 2:
                std::cout << base[p] << '\n';
                break;
        }
    }

    return 0;
}