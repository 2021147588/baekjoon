#include <iostream>
#include <vector>
using namespace std;

long long int cache[31][31];


int main(){
    int T, N, M;
    for(int i = 0; i<31;i++){
        for(int j=1;j<31;j++){
            if(i==j){
                cache[i][j]=1;
            }
            else if(i==0) {
                cache[i][j]=1;
            }
            else{
            cache[i][j] = cache[i-1][j-1]+cache[i][j-1];
            }
        }
    }
    cin>>T;
    
    for(int i = 0; i<T;i++){
        cin>>N>>M;
        cout<<cache[N][M]<<endl;
    }

}