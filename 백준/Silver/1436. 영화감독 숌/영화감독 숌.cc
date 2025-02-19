#include <iostream>
#include <string>
using namespace std;
int number[10001];
int cnt=0;

void find666(int num){
    string str_num = to_string(num);
    for(int i = str_num.size()-1; i>=0;i--){
        if(i-2>=0){
            if((str_num[i]=='6') && (str_num[i-1]=='6') && (str_num[i-2]=='6')){
                cnt++;
                number[cnt]=num;
                break;
            }
        }
    }
}
int main(){
    int N;
    cin>>N;
    int k = 665;
    while(1){
        k++;
        find666(k);
        if(number[N]!=0) break;
    }
    cout<<number[N];
}