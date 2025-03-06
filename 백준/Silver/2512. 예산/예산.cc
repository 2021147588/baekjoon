# include <iostream>
# include <vector>
#include <numeric>  // accumulate 함수 사용
# include <algorithm>
using namespace std;

int N;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>N;
    long long sum;
    long long max = 0;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        sum += temp;
        v.push_back(temp);
        
    }
    sort(v.begin(), v.end());
    int total_budget;
    cin>>total_budget;

    int left = 1;
    int right = v[N-1];
    while(left<=right){
        int mid = (left+right)/2;
        long long sum = 0;
        for(int i=0;i<N;i++){
            if(v[i]>mid) sum += mid;
            else sum+=v[i];
            }
        if(sum<=total_budget) left = mid + 1;
        else right = mid -1;
    }
    cout<<right;

}