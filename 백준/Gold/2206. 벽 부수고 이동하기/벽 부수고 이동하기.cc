# include <iostream>
# include <queue>
using namespace std;

int map[1000][1000][2];
int visit[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;

int bfs(int x, int y){
    queue<pair<pair<int, int>, int>> q;
    q.push({{x,y}, 0});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int broke = q.front().second;

        q.pop();

        if(x == N-1 && y == M-1){
            return map[N-1][M-1][broke] + 1;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M ) continue;
            if (map[nx][ny][0]==1 ) {
                if(broke == 0){
                    map[nx][ny][broke + 1] = map[x][y][broke] + 1;
                    q.push({{nx, ny}, 1});
                }
            }
            else if(map[nx][ny][0]==0){
                if(broke==1 && map[nx][ny][broke]) continue;
                map[nx][ny][broke] = map[x][y][broke] + 1;
                q.push({{nx, ny}, broke});
            }
        }
    }
    return -1;
}

int main(){
    cin>>N>>M;
    char temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>temp;
            map[i][j][0]=temp -'0';
        }
    }
    cout<<bfs(0, 0);
    
    
}