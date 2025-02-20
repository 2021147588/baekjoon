# include <iostream>
using namespace std;
int R, C, N;
int map[201][201];
int time[201][201];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(){
    cin>>R>>C>>N;
    char temp;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>temp;
            if(temp=='O'){
                map[i][j]=1;
                time[i][j]=3;

            } 
            else{
                map[i][j]=0;
                time[i][j]=0;
            }
        }
    }



    for(int t=1;t<=N;t++){
        if(t%2==0){
            // 폭탄 설치
            for(int i=1;i<=R;i++){
                for(int j=1;j<=C;j++){
                    if(time[i][j]==0){
                        time[i][j]=t+3;
                        map[i][j]=1;
                    }
                }
            }
        }
        else if(t==1) continue;
        else{
            for(int i=1;i<=R;i++){
                for(int j=1;j<=C;j++){
                    if(time[i][j]==t){
                        time[i][j]=0;
                        map[i][j]=0;
                        for(int k=0;k<4;k++){
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if(x>0 && y>0 && x<=R && y<=C && time[x][y]!= t){
                                map[x][y]=0;
                                time[x][y]=0;
                            }
                        }

                    }
                }
            }
        }
        
    } 

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(map[i][j]==1){
                cout<<'O';
            }
            else{
                cout<<'.';
            }
        }
        if(i!=R) cout<<'\n';
    }

    



}