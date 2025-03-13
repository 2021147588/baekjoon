#include <iostream>
using namespace std;

int N, M;
int sum[1025][1025] ={ 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> M; // N: 배열 크기, M: 쿼리 개수

    int n;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> n;
            sum[i][j] = sum[i][j - 1] + n; // 누적 합 저장
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout<<sum[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    int x1, y1, x2, y2;
    for (int j = 1; j <= M; j++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans=0;
        for(int j=x1;j<=x2;j++){
            ans = ans + sum[j][y2]-sum[j][y1-1];
        }
        cout<<ans<<'\n';
    }

    return 0;
}
