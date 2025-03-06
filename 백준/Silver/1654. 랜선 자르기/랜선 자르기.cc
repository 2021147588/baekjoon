# include <iostream> 
# include <vector>
# include <algorithm>
using namespace std;

int main(){
    int K, N;

    cin>>K>>N;

    vector<int> v;
    for(int i=0; i<K;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    long long left=1;
    long long right=v[K-1];
    long long mid;
    long long a=0;
    while(left<=right){
        mid = (left+right)/2;
        // cout<<left<<' '<<mid<<' '<<right<<endl;

        long long num=0;
        for(int i=0;i<K;i++){
            num += v[i]/mid;
        }
        if(num<N) right = mid - 1;
        else {
            left = mid + 1;
            a = mid;
        }
    }
    cout<<a;
    
}