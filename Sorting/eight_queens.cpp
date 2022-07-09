#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<pair<int, int>>positions(0);
vector<bool>diag_left(15, false);
vector<bool>diag_right(15, false);
vector<bool>cols(16,false);
bool reserved[8][8];
//during the recursion he made a running variable in the scenario that holds the status of what happened in the past , rather htan checking 
//again and again ! Nte that this is a global not passed through the recursion again and again, only the dependent varaible (in this case the row) is passed into the recursion 

ll num = 0;
void search_pos(ll row){
    if(row == 8){
        num++;
        return;
    }
    else{
        for(int col = 0; col < 8; col++){
            if(cols[col] || diag_left[row - col + 7] || diag_right[row + col] || reserved[row][col]){
                continue;
            }
            else{
                //try him out 
                cols[col] = diag_left[row - col + 7] = diag_right[row + col] = true;
                search_pos(row + 1);
                //climb up the tree after num has been done or you have failed in a particular stage of the recursion
                cols[col] = diag_left[row - col + 7] = diag_right[row + col] = false;
            }
        }
    }
}
int main()
{
    for (int i =0; i< 8; i++){
        for (int j =0; j<8; j++){
            char x;
            cin>>x;
            if(x == '.'){
                reserved[i][j] = false;
            }
            else{
                reserved[i][j] = true;
            }
        }
    }
    search_pos(0); 
    cout<<num<<endl;
    return 0;
}