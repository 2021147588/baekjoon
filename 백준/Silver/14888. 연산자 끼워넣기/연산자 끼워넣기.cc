#include<iostream>
using namespace std;
int N;
int op[4];
int A[11];
int mmin = 1000000001;
int mmax = -1000000001;

void getSolve(int result, int idx){
    
    if(idx==N){
        if(result > mmax){
            mmax = result;
        }
        if(result < mmin){
            mmin = result;
        }
        return;
    }
    
    for(int i=0;i<4;i++){
        if(op[i]>0){    
            op[i]--;
            if(i==0){
                getSolve(result+A[idx], idx+1);
            }
            else if(i==1){
                getSolve(result-A[idx], idx+1);
            }
            else if(i==2){
                getSolve(result * A[idx], idx+1);
            }
            else{
                getSolve(result/A[idx], idx+1);
            }
            op[i]++;
        }
    }
    return;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<4;i++){
        cin>>op[i];
    }
    getSolve(A[0], 1);

    cout<<mmax<<"\n"<<mmin<<"\n";

    return 0;
}