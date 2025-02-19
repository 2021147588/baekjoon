# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b){
    if(a.second==b.second) return a.first<b.first;
    else return a.second <b.second;
}

int main(){
    ios::sync_with_stdio(0);

    int N, start, end;
    vector<pair<int, int>> time;

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>start>>end;
        time.push_back(make_pair(start, end));
    }
    // 종료 시간이 빠른 순서대로 정렬
    sort(time.begin(), time.end(), compare);

    int result = 0;
    int last_time = 0;
    for(int i=0;i<N;i++){
        if(last_time <= time[i].first){
            result++;
            last_time = time[i].second;
        }
    }
    cout<<result;
    return 0;
}