# include <iostream>
# include <queue>
using namespace std;

int N, M;
int map[1001][1001];
int visited[1001][1001];
int ans[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<pair<int, int>, int>> q;

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            // cout<<nx<<' '<<ny<<endl;

            // cout<<visited[nx][ny]<<' '<< map[nx][ny]<<endl;
            if(visited[nx][ny]==0 && map[nx][ny]==1){

                q.push({{nx, ny}, d+1});
                ans[nx][ny]=d+1;
                visited[nx][ny]=1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    int temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>temp;
            map[i][j]=temp;
            if(temp==2){
                q.push({{i,j}, 0});
                visited[i][j]=1;
                ans[i][j]=0;
            }
        }
    }
    bfs();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==1 && ans[i][j]==0) cout<<-1<<' ';
            else cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}