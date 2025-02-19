# include <iostream>
# include <vector>
# include <cassert>
# include <algorithm>
# include <stack>

using namespace std;

int main(){
    stack<int> stack;
    vector<pair<int, int>> idx;
    string input;
    cin>>input;
    int num_p = 0;
    for(int i=0;i<input.size();i++){
        if(input[i]=='('){
            stack.push(i);
            num_p++;
        }
        else if(input[i]==')'){
            int open_p = stack.top();
            idx.push_back(make_pair(i, open_p));
            stack.pop();
        }
    }
    vector<vector<int>> comb(1 << num_p); // 크기를 2^num_p로 설정

    // 비트마스크를 사용해 부분 집합 생성
    for (int mask = 0; mask < (1 << num_p); mask++) {
        for (int i = 0; i < num_p; i++) {
            if (mask & (1 << i)) { // i번째 비트가 켜져 있는지 확인
                comb[mask].push_back(i); // comb[mask]에 현재 값(i+1)을 추가
            }
        }
    }

    vector<string> result;
    for (int i=1;i<comb.size();i++){
        string temp = input;
        for(int j=0;j<comb[i].size();j++){
            int p_index = comb[i][j];
            int open_p_idx = idx[p_index].first;
            int close_p_idx = idx[p_index].second;
            temp[open_p_idx] = '$';
            temp[close_p_idx] = '$';

        }
        result.push_back(temp);
    }

    for(int i=0;i<result.size();i++){
        string output;
        for(char c : result[i]) {
            if(c!='$') output +=c;
        }
        result[i] = output;
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

}