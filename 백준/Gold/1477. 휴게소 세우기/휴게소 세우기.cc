# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int N, M, L;
vector<int> v;

bool diff(int mid){
    int max = 0;
    int cnt = 0;
    
    for(int j = 1;j<v.size();j++){
        int dist = v[j] - v[j-1];
        cnt+=dist/mid;
        if(dist % mid == 0){
            cnt--;
        }
    }
    return cnt>M;
}

int main(){
    cin>>N>>M>>L;
    v.push_back(0);
    v.push_back(L);

    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int low = 1;
    int high = L;
    int mid, a = 0;
    while(low<=high){
        
        mid = (low+high)/2;
        if(diff(mid)){
            low = mid + 1;
        }
        else {
            a = mid;
            high = mid - 1;
        }
    }
    cout<<a;

}