#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<pair<int, int>>positions(0);
ll num = 0;
bool isvalid(ll i, ll j, vector<pair<int, int>>positions){
    for (auto &p : positions){
        if( i == p.first || j == p.second || i - p.first == j - p.second){
            return false;
        }
    }
    return true;
}
void num_of_ways(vector<vector<char>> & chessboard, ll row_index, ll pos_onwards){
    for (ll i = row_index ; i < chessboard[0].size(); i++){
        bool flag = false;
        for (int j = pos_onwards; j< chessboard[0].size(); j++){
            if(isvalid(i , j , positions) && chessboard[i][j] != '*'){
                positions.push_back(make_pair(i, j));
                flag = true;
                num_of_ways(chessboard, row_index + 1, 0);
            }
        }
        if(flag == false){
            pair<int, int> pos_last = positions.back();
            int j_last = pos_last.second;
            positions.pop_back();
            num_of_ways(chessboard, row_index- 1, j_last + 1);
        }
    }
    if(row_index == chessboard[0].size()){
        num ++ ;
    }
}
int main()
{
    vector<vector<char>>chessboard(8, vector<char>(8, '.'));
    num_of_ways(chessboard, 0, 0);
    cout<<num<<endl;
    return 0;
}