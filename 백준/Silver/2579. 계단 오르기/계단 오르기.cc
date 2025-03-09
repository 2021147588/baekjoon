# include <iostream>
# include <vector>
using namespace std;

int main(){
    int N;
    vector<int> v;
    int dp[10001];
    cin>>N;
    v.push_back(0);
    for(int i=1;i<=N;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }    
    dp[0] = v[0];
    dp[1] = v[1];
    dp[2] = max(dp[1]+v[2], dp[0]+v[2]);
    for(int i=3;i<=N;i++){
        dp[i] = max(dp[i-2]+v[i], dp[i-3]+v[i-1]+v[i]);
    }
    // for(int i=0;i<=N;i++){
    //     cout<<dp[i].first<<' ';
    //     cout<<dp[i].second<<' ';
    //     cout<<'\n';
    // }
    cout<<dp[N];
}