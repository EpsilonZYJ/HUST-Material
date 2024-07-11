//广度优先（队列）
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int N = 35;

int m[N][N];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    vector<pair<int, int>> move = {{0, 1}, {0, -1}, {1,0}, {-1, 0}};
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> m[i][j];
    int xflag = 0;
    int yflag = 0;    
    for(int i = 0; i < n; i ++){
        xflag = 0;
        yflag = 0;
        for(int j = 0; j < n; j ++){
            if(m[i][j]){
                i ++;
                yflag = i;
                while(m[i][j] == 1) j++;
                xflag = j;
                break;
            }
        }
        if(xflag && yflag)
            break;
    }
    m[yflag][xflag] = 2;
    q.push(make_pair(yflag, xflag));
    while (!q.empty()) {
        pair<int, int> a = q.front();
        q.pop();
        for(auto i : move){
            if(!m[a.first + i.first][a.second + i.second]){
                m[a.first + i.first][a.second + i.second] = 2;
                q.push(make_pair(a.first+i.first, a.second+i.second));
            }
        }
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++){
                cout << m[i][j];
                if(j == n-1) cout << '\n';
                else cout << ' ';
            }
    return 0;
}