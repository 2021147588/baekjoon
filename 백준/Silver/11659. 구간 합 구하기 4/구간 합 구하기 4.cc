# include <iostream>
# include <vector>
using namespace std;

int N, M;
int nums[100001];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    long sum[100001];
    cin>>N>>M;

    sum[0]=0;
    long nums;

    for(int i=1;i<=N;i++){
        cin>>nums;
        sum[i] = sum[i-1] + nums;    
    }


    int start_i, end_i;
    for(int i=0;i<M;i++){
        cin>>start_i>>end_i;
        cout<<sum[end_i]-sum[start_i-1]<<'\n';
    }

}