#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> road[20002];
int school_type[1001];
int visited[1001];
int ans=0;
int node;

void prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    for(int i=0;i<N;i++){
        while(!pq.empty()&&visited[pq.top().second]){
            pq.pop();
        }
        ans += pq.top().first;
        node = pq.top().second;
        visited[node]=true;

        for(auto o: road[node]){
            pq.push({o.second, o.first});
        }
        
        
    }

}

int main(){
    cin>>N>>M;
    char gender;
    char temp;
    for(int i=1;i<=N;i++){
        cin>>temp;
        if(temp=='W') school_type[i] = 1;
        else school_type[i]=0;
    }
    int from, to, cost;
    for(int i=1;i<=M;i++){
        cin>>from>>to>>cost;
        if(school_type[from]!=school_type[to]){
            road[from].push_back({to, cost});
            road[to].push_back({from, cost});
        }
    }
    prim();
    bool fail=false;
    for(int i=1;i<=N;i++){
        if(visited[i]==false){
            fail=true;
            break;
        }
    }

    if(fail==true) cout<<-1;
    else cout<<ans;
}