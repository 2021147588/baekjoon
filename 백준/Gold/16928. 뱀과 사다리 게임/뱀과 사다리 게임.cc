# include <iostream>
# include <queue>
using namespace std;
int map[102] = {0};
bool visit[102] = {0};

void game(int x, int c){
    queue<pair<int, int>> q;
    q.push(make_pair(x, c));
    while(!q.empty()){
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=1;i<=6;i++){
            int next = pos + i;
            if(next==100){
                cout<< cnt+1;
                return;
            }
            else if(next<100){
                while(map[next]!=0){
                    next = map[next];
                }
                if(!visit[next]){
                    q.push(make_pair(next, cnt+1));
                    visit[next]=true;
                }
            }
        }
    }

}

int main(){

    int N, M;
    int from, to;
  
    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>from>>to;
        map[from] = to;
    }
    for(int i=0;i<M;i++){
        cin>>from>>to;
        map[from] = to;
    }
    game(1,0);
    return 0;
    
}
