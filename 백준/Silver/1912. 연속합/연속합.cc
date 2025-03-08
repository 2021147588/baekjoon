# include <iostream>
# include <vector>
using namespace std;

int main(){
    vector<int> v;
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    int sum[100000];
    sum[0]=v[0];

    for(int i=0;i<N-1;i++){
        if(sum[i]+v[i+1]<v[i+1]){
            sum[i+1] = v[i+1];
            // cout<<"1s: "<<sum[i+1]<<endl;
        }
        else{
            sum[i+1] = sum[i] + v[i+1];
            // cout<<"2s: "<<sum[i+1]<<endl;
        }
    }
    int max = -1000;
    for(int i=0;i<N;i++){
        if(max<sum[i]){
            max = sum[i];
        }

    }
    cout<<max;
}