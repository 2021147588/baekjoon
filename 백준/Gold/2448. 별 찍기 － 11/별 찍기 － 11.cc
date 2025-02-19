# include <iostream>
using namespace std;

int tri[3073][6500];

void draw(int n, int y, int x){
    if(n==3){
        tri[y][x] = 1;
        tri[y+1][x-1] = 1;
        tri[y+1][x+1] = 1;
        for(int i=0;i<5;i++){
            tri[y+2][x-2+i] = 1;
        }
        return;     
    }
    draw(n/2, y, x);
    draw(n/2, y+n/2, x-n/2);
    draw(n/2, y+n/2, x+n/2);
}
int main(){
    int N;
    cin>>N;
    draw(N, 0, N);
    for(int i=0;i<=N;i++){
        for(int j=1;j<=2*N;j++){
            cout << (tri[i][j] == 1 ? '*' : ' ');
        }
        cout<<endl;
    }
}