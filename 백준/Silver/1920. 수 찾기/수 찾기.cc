#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int search(int* A, int i, int N){
    int start=0;
    int end=N-1;
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(A[mid]==i){
            return 1;
        }
        else if(A[mid]>i){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return 0;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int N, M;
    cin>>N;

    int* A = new int[N];

    for(int i = 0; i < N; i++){
        cin>>A[i];
    }
    sort(A, A+N);
    cin>>M;

    int* B = new int[M];
    for(int j = 0; j<M; j++){
        cin>>B[j];
    }
    for(int j = 0;j<M;j++){
        cout<<search(A, B[j],N)<<"\n";
    }
    return 0;
    
}