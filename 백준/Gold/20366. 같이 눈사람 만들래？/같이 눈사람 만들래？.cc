#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;

    int *snows = new int[N];

    for (int i=0; i<N; i++){
        cin>>snows[i];
    }
    
    sort(snows, snows+N);
    
    int result = 1000000000;
    for(int i=0;i<N;i++){
        for(int j=i+3;j<N;j++){
            int left = i + 1;
            int right = j - 1;
            while(left<right){
                int total = snows[i]+snows[j] -snows[left]-snows[right];
                if (result>abs(total)){
                    result = abs(total);
                }
                if (total<0)right--;
                else left++;
            }
        }
    }
    cout<<result;
    delete[] snows;
    return 0;
}