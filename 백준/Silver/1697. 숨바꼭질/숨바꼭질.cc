#include<iostream>
#include<queue>
using namespace std;

queue<pair<int,int>> que;
int K, N, level;
int visit[100001];

bool valid(int i){
    if(i<0 || i>100000 || visit[i]){
        return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin>>N>>K;
    visit[N]=1;
    que.push({N, 0});
    
    while(!que.empty()){
        int a = que.front().first;
        int l = que.front().second;
        que.pop();
        if(a==K){
            level = l;
            break;
        }
        if(valid(2*a)){
            visit[2*a]=1;
            que.push({a*2, l+1});
        }
        if(valid(a-1)){
            visit[a-1]=1;
            que.push({a-1, l+1});
        }
        if(valid(a+1)){
            visit[a+1]=1;
            que.push({a+1, l+1});
        }
    }
    cout<<level;

}