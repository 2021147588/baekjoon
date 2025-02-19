# include <iostream>
# include <cmath>
using namespace std;

int s, N, K, R1, R2, C1, C2;
bool p[51][51];

void prectal(int length, int sr, int sc){
    if(length==1) return;
    if(sr > R2 || sc > C2 || sr+length-1<R1 || sc+length-1 <C1) return;

    int center_s = length/N * (N-K)/2;
    int center_e = center_s + length/N*K - 1;

    //주어진 행, 열 안에 있는지
    int r1 = max(R1, center_s+sr);
    int r2 = min(R2, center_e+sr);
    int c1 = max(C1, center_s+sc);
    int c2 = min(C2, center_e+sc);
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            p[i-R1][j-C1] = true;
        }
    }

    for(int i=0;i<length;i+=length/N){
        for(int j=0;j<length;j+=length/N){
            if(i>=center_s && i<=center_e && j>= center_s && j<= center_e){
                continue;
            }
            prectal(length/N, sr+i, sc+j);
        }
    }
}

int main(){
    cin>>s>>N>>K>>R1>>R2>>C1>>C2;
    prectal(int(pow(N, s)), 0, 0);
    for(int i=0;i<R2-R1+1;i++){
        for(int j=0;j<C2-C1+1;j++){
            cout<<(p[i][j] ? 1:0);

        }
            cout<<'\n';

    }
    return 0;    
}