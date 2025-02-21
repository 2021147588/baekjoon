# include <iostream>
# include <vector>
#include <cstring> // memset을 사용하기 위해 필요
using namespace std;

int N, M;
vector<int> v[4001];
int frnd[4001]={0};
bool visited[4001];
bool is_possible = false;

void find_friend(int curr, int depth){
    if(depth==4) {
        is_possible=true;
        return;
    }

    visited[curr]=true;
    for(auto o:v[curr]){
        if (!visited[o]){
            find_friend(o, depth+1);
            visited[o]=false;

        }
    }
    return;
}

int main(){

    cin>>N>>M;
    int x, y;
    for(int i=0;i<M;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<N;i++){
        if(visited[i]==false){    
            find_friend(i, 0);
            visited[i]=false;
        }
        if(is_possible==1) break;

    }

    if(is_possible==1) cout<<1;
    else cout<<0;
    
}