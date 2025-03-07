# include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    string num;
    int sum=0;
    cin>>num;
    for(int j=0;j<N;j++){
        sum += num[j] - '0';
    }
    
    cout<<sum;
}