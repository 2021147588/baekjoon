# include <iostream>
# include <queue>
# include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> road[500001];
int visited[100001];
long long ans;
void prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    for(int i=1;i<=N;i++){
        while(!pq.empty()&&visited[pq.top().second]){
            pq.pop();
        }
        ans += pq.top().first;
        int node = pq.top().second;
        visited[node]=1;

        for(auto o: road[node]){
            pq.push({o.second, o.first});
        }
    }

}
int main(){

    cin>>N>>M;
    int from, to, cost;
    long long total_cost=0;

    for(int i=0;i<M;i++){
        cin>>from>>to>>cost;
        road[from].push_back({to, cost});
        road[to].push_back({from, cost});
        total_cost += cost;
    }
    prim();
    int fail = 0;
    for(int i=1;i<=N;i++){
        if(visited[i]==0){
            fail = 1;
            break;
        }
    }
    if(fail == 1) cout<<-1;
    
    else{

        cout<<total_cost-ans;
    }

}