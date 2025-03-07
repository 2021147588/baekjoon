# include <iostream>
using namespace std;

int main(){
    long long N, K;
    cin>>N>>K;
    long long result;
    long long left = 0;
    long long right = N;
    long long mid;
    bool a = false;
    while(left<=right){
        mid = (left+right)/2;
        result = (mid+1)*(N-mid+1);
        // cout<<left<<' '<<mid<<' '<<right<<'\n';
        if (result == K) {
            a = true;
            break;
        }
        if (result > K){
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    if(a) cout<<"YES";
    else cout<<"NO";
}