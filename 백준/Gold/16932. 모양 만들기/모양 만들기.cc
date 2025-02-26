# include <iostream>
# include <vector>
# include <queue>
# include <map>
using namespace std;

int N, M;
pair<int, int> visit[1001][1001];
int graph[1001][1001];
queue<pair<int, int>> q;
queue<pair<int, int>> qq;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
int answer;
int group_num;

void bfs(int a, int b){
    q.push({a, b});
    qq.push({a, b});
    visit[a][b]={group_num, 1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(graph[nx][ny]==1&&visit[nx][ny].first==0){
                q.push({nx,ny});
                visit[nx][ny].first = group_num;
                visit[nx][ny].second = 1;
                qq.push({nx, ny});
                
            }

        }
    }
    int x, y;
    int group_size = qq.size();
    while(!qq.empty()){
        x = qq.front().first;
        y = qq.front().second;
        qq.pop();
        visit[x][y] = {group_num, group_size};
    }

}


int main(){
    cin>>N>>M;
    int temp;
    vector<pair<int, int>> zeros;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>temp;
            graph[i][j] = temp;
            if(temp==0){
                zeros.push_back({i, j});
            }
        }
    }

    // 1인 칸들을 그룹화
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]==1 && !visit[i][j].first){
                group_num++;
                bfs(i, j);
            }
        }
    }

    // 그룹끼리 묶기
    for(int i=0;i<zeros.size();i++){
        map<int, int> plus;
        int x = zeros[i].first;
        int y = zeros[i].second;
        int cnt=1;
        if(!visit[x][y].first){
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx<0||nx>=N||ny<0||ny>=M) continue;
                if(visit[nx][ny].first!=0){
                    plus[visit[nx][ny].first]=visit[nx][ny].second;
                                            
        
                }
            }
        }
        for(auto o:plus){
            cnt+=o.second;
        }
        answer= max(answer, cnt);
    }

    cout<<answer<<endl;

}