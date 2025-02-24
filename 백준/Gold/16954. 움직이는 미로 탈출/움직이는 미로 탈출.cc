# include <iostream>
# include <queue>
using namespace std;
# define INF 987654321

int dx[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0 };
int dy[9] = {-1, 1, 0, 0, 1, -1, -1, 1, 0 };
int wall[8][8][8];
int visit[9][8][8];
queue<pair<pair<int, int>, int>> wall_q;

int first_wall_x=10;

void wall_spread(){
    for(int t=1;t<9;t++){
        for(int i=1;i<8;i++){
            for(int j=0;j<8;j++){
                if(wall[t-1][i-1][j]==1){
                    wall[t][i][j]=1;
                }
            }
        }
    }

}

int bfs(){
    queue<pair<pair<int,int>, int>> pos;
    pos.push({{7,0}, 0});
    while(!pos.empty()){
        int x = pos.front().first.first;
        int y = pos.front().first.second;
        int time = pos.front().second;
        pos.pop();
        
        // cout<<"pos: "<<x<<' '<<y<<endl;

        for(int i=0;i<9;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt;
            if(time >= first_wall_x) nt = first_wall_x;
            else nt = time+1;
            

            if(nx==0 && ny == 7) return 1;
            
            // 범위에 벗어남
            if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;

            // 가려는 칸에 벽이 내려오거나 지금 시간에 벽이 있으면 
            if(wall[nt][nx][ny]==1 || wall[time][nx][ny]==1) continue;
            if(visit[nt][nx][ny]==0){
                visit[nt][nx][ny]=1;
                pos.push({{nx, ny}, time+1});
   
            }
        }

    }
    return 0;


}

int main(){

    string temp;

    for(int i=0;i<8;i++){
        cin>>temp;
        for(int j=0;j<8;j++){
            if(temp[j]=='.'){
                wall[0][i][j]=0;

            }
            else{
                wall[0][i][j]=1;
                wall_q.push({{i, j}, 0});
                if(first_wall_x==10) first_wall_x = 8 - i; 
            }
        }
    }
    wall_spread();
    cout<<bfs();

    // for(int t=0;t<8;t++){
    //     cout<<"==="<<t<<endl;
    //     for(int i=0;i<8;i++){
    //         for(int j=0;j<8;j++){
    //             cout<<wall[t][i][j]<<' ';
    //         }
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }



}