#include<iostream>
#include<queue>
#include<memory.h>

using namespace std; 

char input[100][100];
bool visit[100][100]={false};
int N;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void bfs(int x, int y);
void solution();

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>input[i][j];
        }
    }
    solution();
}

void bfs(int x, int y){
    queue<pair<int, int>>q;

    q.push(make_pair(x,y));
    visit[x][y]=true;
    while(!q.empty()){
        int a,b;
        a = q.front().first;
        b = q.front().second;
        visit[a][b]=true;
        q.pop();
        for(int i=0;i<4;i++){
            int ax = a + dx[i];
            int by = b + dy[i];
            if(ax>=0&&by>=0&&ax<N&&by<N){
                if(visit[ax][by]==false){
                    if(input[a][b]==input[ax][by]){
                        visit[ax][by]=true;
                        q.push(make_pair(ax,by));
                    }
                }
            }
        }
    }
}

void solution(){
    int num=0;
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j]==false){
                bfs(i,j);
                num++;
            }
        }
    }
    cout<<num<<" ";

    int num2=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(input[i][j]=='G'){
                input[i][j]='R';
            }
        }
    }
    memset(visit,false,sizeof(visit));
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j]==false){
                bfs(i,j);
                num2++;
            }
        }
    }
    cout<<num2;
}