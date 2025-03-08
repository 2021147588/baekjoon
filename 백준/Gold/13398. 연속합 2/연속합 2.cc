# include <iostream>
# include <vector>
# include <map>
using namespace std;
#define MAX 100010


int solve(){int N;
    vector<int> v;
    cin>>N;

    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    if(N==1) {
        cout<<v[0];
        return 1;
    }
    int sum[100000];
    sum[0] = v[0];
    for(int i=0;i<N-1;i++){   
        if(sum[i]+v[i+1]<v[i+1]){
            sum[i+1] = v[i+1];
        }
        else{
            sum[i+1] = sum[i]+v[i+1];
        }
    }
    int rightsum[100000];
    rightsum[N-1]=v[N-1];
    for(int i=N-1;i>=1;i--){
        if(rightsum[i]+v[i-1] < v[i-1]){
            rightsum[i-1]=v[i-1];
        }
        else{
            rightsum[i-1]=rightsum[i]+v[i-1];
        }

    }
    // for(int i=0;i<N;i++){

    //     cout<<sum[i]<<' ';
    // }
    // for(int i=0;i<N;i++){

    //     cout<<rightsum[i]<<' ';
    // }
    int ans=-1000;
    for(int i=0;i<N;i++){
        if(ans<sum[i]){
            ans = sum[i];
        }
    }
    for(int i=1;i<N-1;i++){
        if(sum[i-1]+rightsum[i+1]>ans){
            ans = sum[i-1]+rightsum[i+1];
        }
    }
    cout<<ans;
    return 0;

}
int main(){
    solve();
    
}