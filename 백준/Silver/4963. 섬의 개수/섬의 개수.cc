#include <iostream>
using namespace std;
int G[51][51]={0};
int W, H, num;
bool check[51][51];


void dfs(int i, int j, int dep){
    if(check[i][j]==1) return ;
    check[i][j]=true;
    if(G[i][j]==1){
        if(dep==0) {
            num++;
        }
        if(i<H-1) dfs(i+1,j, dep+1);
        
        if(i>0) dfs(i-1,j,dep+1);
        
        if(j<W-1) dfs(i,j+1, dep+1);
        if(j>0) dfs(i,j-1, dep+1);
        if(i<H-1&&j<W-1) dfs(i+1,j+1, dep+1);
        if(i<H-1&&j>0) dfs(i+1,j-1,dep+1);
        if(i>0&&j<W-1) dfs(i-1, j+1, dep+1);
        if(i>0&&j>0) dfs(i-1,j-1,dep+1);


    }
}
int main(){
    int x;
    while(1){
        num = 0;
        cin>>W>>H;
        if(W==0 && H==0) break;
        for(int i = 0; i<H;i++){
            for(int j=0;j<W;j++){   
                check[i][j]=false;
                }
            }
        for(int i = 0; i<H;i++){
            for(int j=0;j<W;j++){   
                cin>>x;
                G[i][j]=x;
                }
            }
        for(int i = 0; i<H;i++){
            for(int j=0;j<W;j++){   
                dfs(i,j,0);
                }
            }
        cout<<num<<endl;
    }
}
    
    

