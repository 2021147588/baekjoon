# include <iostream>
# define MOD 1000000
using namespace std;

int num[100001], pos[100001];
int ans;
int num_disc, rod1, rod2, rod3, x;

void power(int n)
{
	num[0] = 1;
	for (int i = 1; i <= n; i++)
		num[i] = (num[i - 1] * 2) % MOD;
}

void hanoi(int disc, int to) // to는 옮겨야 할 곳
{
    if (disc == 0) return;
    int now = pos[disc];
    int temp; // 중간 막대기 번호
    // 중간 막대기 번호 찾기기
    for(int i=1;i<=3;i++){
        if(now != i && to != i){
            temp = i;
        }
    }
    if(now == to) hanoi(disc-1, to);
    else{
		ans = (ans + num[disc - 1]) % MOD;
        hanoi(disc-1, temp);
    }
}

int main(){
    ios::sync_with_stdio(0); 
	cin.tie(0); 
    cin>>num_disc;
    cin>>rod1>>rod2>>rod3;
    power(num_disc);
    //첫번째 rod
    for(int i=0;i<rod1;i++){
        cin>> x;
        pos[x]=1;
    }

    for(int i=0;i<rod2;i++){
        cin>> x;
        pos[x]=2;
    }

    for(int i=0;i<rod3;i++){
        cin>> x;
        pos[x]=3;
    }
    
    hanoi(num_disc, pos[num_disc]);
    cout<<pos[num_disc]<<endl;
    cout<<ans;
}