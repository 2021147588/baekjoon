# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    vector<int> v;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    long long left = 0;
    long long right = v[N-1];
    long long mid;
    int a=0;

    while(left<=right){
        mid = (left+right)/2;

        long long sum = 0;
        for(int i=0;i<N;i++){
            if(v[i]>mid) sum += v[i]-mid;
        }
        if(sum>=M) {
            left = mid + 1;
            a = mid;
        } else right = mid - 1;
        
    }
    cout<<a;
}