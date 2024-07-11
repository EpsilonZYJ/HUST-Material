#include <iostream>

const int N = 21;

int a[N];

void done(){
    a[0] = 1;
    a[1] = 0;
    for(int i = 2; i < 21; i ++){
        int sum = 0;
        for(int j = 0; j < i; j ++){
            sum += a[j]*a[i-1-j];
        }
        a[i] = sum;
    }
}

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    done();
    for(const auto& i : a)
        std::cout << i << ' ';
    std::cout << a[n];
    return 0;
}