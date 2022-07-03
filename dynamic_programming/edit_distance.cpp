#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MOD 1000000007
bool isgreaterthanzero(ll input){
    if(input >= 0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    string s,t;
    cin>>s>>t;
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
    for (int i = 0; i <= s.size(); i++){
        for (int j =0; j <= t.size(); j++){
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                    = 1
                      + min(dp[i][j - 1], // Insert
                            min(dp[i - 1][j], // Remove
                            dp[i - 1][j - 1])); // Replace
        }
    }
    cout<<dp[s.size()][t.size()]<<endl;
    
    return 0;
}