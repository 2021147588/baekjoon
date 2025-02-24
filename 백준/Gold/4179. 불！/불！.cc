# include <iostream>
# include <vector>
# include <queue>
# include <string>
using namespace std;

int R, C;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[1001][1001];
int fire[1001][1001];
pair<int, int> curr;
bool spreads = true;
bool visited[1001][1001];
queue<pair<pair<int, int>, int>> q;

void fire_spreads(){
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int curr_time = q.front().second;
        q.pop();
        curr_time++;
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0||nx>=R||ny<0||ny>=C) continue;
            if(fire[nx][ny]>curr_time&&map[nx][ny]!=1){
                fire[nx][ny]=curr_time;
                q.push({{nx, ny}, curr_time});
            }
        }
    }
}

int bfs(int a, int b){
    queue<pair<pair<int,int>, int>> Q;
    Q.push({{a, b}, 1});
    visited[a][b]=true;

    while(!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int t = Q.front().second;
        // cout<<"place: "<<x<<' '<<y<<' '<<t<<endl;;
        Q.pop();
        if(x==0||y==0||x==R-1|| y==C-1) return t;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx <R && ny>=0 && ny<C){
                if(map[nx][ny]!=1 && visited[nx][ny]==0){
                    if(fire[nx][ny]>t+1){
                        visited[nx][ny]=1;
                        Q.push({{nx, ny}, t+1});
                    }
                }
            }
        }
    }
    return -1;

}

int main(){
    cin.tie(0); ios::sync_with_stdio(NULL);

    cin>>R>>C;
    string temp;
        for(int i=0;i<R;i++){
            cin>>temp;
            for(int j=0;j<C;j++){
                if(temp[j]=='#'){
                    map[i][j]=1;
                    fire[i][j]=987654321;
                }
                else if(temp[j]=='J'){
                    curr = {i, j};
                    fire[i][j]=987654321;

                }   
                else if(temp[j]=='F'){
                    q.push({{i,j},1});
                    fire[i][j]=1;
                    map[i][j]=1;
                }
                else{
                    map[i][j]=0;
                    fire[i][j]=987654321;

                }
            }
        }

    fire_spreads();
    // for(int i=0;i<R;i++){
    //     for(int j=0;j<C;j++){
    //         cout<<fire[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    int success = bfs(curr.first, curr.second);
    if(success!=-1) cout<<success;
    else cout<<"IMPOSSIBLE";
}