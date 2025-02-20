#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    int T, K;
    string W;

    // 게임 횟수
    cin >> T;

    vector<int> freq[26];

    for (int t = 0; t < T; t++){
        string W;
        int K;
        int min_num = 100000;
        int max_num = 0;

        cin >> W >> K;
        
        //count frequency
        for(int i = 0; i<26; i++) freq[i].clear();

        for (int i = 0; i < W.length(); i ++){
            int x = W[i] - 97;
            freq[x].push_back(i); //index를 넣음
        }

        for (int i = 0; i < 26; i++){
            int freq_size = freq[i].size();
            if (freq_size >= K){
                for (int j = 0; j <= freq_size-K;j++){
                    min_num = min(min_num, freq[i][j+K-1] - freq[i][j]+1);
                    max_num  = max(max_num, freq[i][j+K-1] - freq[i][j]+1);

                }
                
            }
        }
        if(min_num == 100000 || max_num == 0) cout << -1 << "\n";
        else cout << min_num << " " << max_num << "\n";
    }
}
