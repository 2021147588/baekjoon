# include <iostream>
# include <queue>
# include <vector>
using namespace std;

int N, M;
int map[101][101];
int visited[101][101];
vector<int> v;

int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

int bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0]=1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        // cout<<x<<' '<<y<<endl;
        if(x == N-1 && y == M-1) {
            return d;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > N || ny < 0 || ny > M) continue;
            if(visited[nx][ny]==0 && map[nx][ny]==1){
                q.push({{nx, ny}, d+1});
                visited[nx][ny]=1;
            }
        }
    }
}
int main(){
    cin >> N >> M;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        for(int j=0;j<M;j++){
            map[i][j]=temp[j] - '0';
        }
    }
    cout<<bfs();
    
    
}