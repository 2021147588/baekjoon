#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<pair<int, int>> G[100001];
int visited[100001];

int prim() {
    //<cost, 현재 node의 인접 노드>
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq;
    int total_cost = 0;
    pq.push({0, 1});
    for(int i=0;i<N;i++){
        while(!pq.empty()&&visited[pq.top().second]){
            pq.pop();
        }

        int next = pq.top().second;
        total_cost += pq.top().first;
        visited[next]=true;

        //find adjecent nodes
        for(auto o:G[next]){
            pq.push({o.second, o.first});
        }
    }
    return total_cost;
}

int main(){
    cin>>N;
    cin>>M;
    
    for(int i=0; i<M; i++){
        int from, to, cost;
        cin>>from>>to>>cost;
        G[from].push_back({to, cost});
        G[to].push_back({from, cost});
    }
    cout<<prim();
}