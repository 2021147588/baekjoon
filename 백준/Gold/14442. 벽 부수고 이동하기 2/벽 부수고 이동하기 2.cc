# include <iostream>
# include <queue>
using namespace std;

int N, M, K;
int map[1001][1001];
bool visit[1001][1001][11];
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

int bfs(){
    queue<pair<pair<int, int>, pair<int,int>>> q;

    visit[0][0][0] = true;
    q.push({{0, 0}, {0, 1}});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int break_num = q.front().second.first;
        int distance = q.front().second.second;
        q.pop();
        if(x==N-1 && y==M-1) {
            return distance;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            
            if(map[nx][ny]==0&&visit[nx][ny][break_num]==0){
                visit[nx][ny][break_num]=1;
                q.push({{nx, ny}, {break_num, distance+1}});
            }
            else if(map[nx][ny]==1&&break_num<K&&visit[nx][ny][break_num+1]==0){
                visit[nx][ny][break_num+1]=1;
                q.push({{nx, ny}, {break_num+1, distance+1}});
            }

            
            
        }
    }
    return -1;

}
int main(){
    cin>>N>>M>>K;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        for(int j=0;j<M;j++){
            map[i][j]=temp[j]-'0';
        }
    }
    cout<<bfs()<<endl;

}