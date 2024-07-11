#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

int main(){
    string s;
    pair<int, int> score_11(0, 0);
    pair<int, int> score_21(0, 0);
    vector<pair<int, int>> record_11;
    vector<pair<int, int>> record_21;
    while(getline(cin, s, '\n')){
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == 'W'){
                score_11.first ++;
                score_21.first ++;
            }
            else if(s[i] == 'L'){
                score_11.second ++;
                score_21.second ++;
            }
            else if(s[i] == 'E'){
                record_11.push_back(score_11);
                record_21.push_back(score_21);
                break;
            }
            if((score_11.first >= 11 || score_11.second >= 11) && abs(score_11.first - score_11.second) >= 2){
                record_11.push_back(score_11);
                score_11 = {0, 0};
            }
            if((score_21.first >= 21 || score_21.second >= 21) && abs(score_21.first - score_21.second) >= 2){
                record_21.push_back(score_21);
                score_21 = {0, 0};
            }
        }
    }
    for(const auto& i : record_11){
        cout << i.first << ":" << i.second << '\n';
    }
    cout << '\n';
    for(const auto& i : record_21){
        cout << i.first << ":" << i.second << '\n';
    }
    return 0;
}