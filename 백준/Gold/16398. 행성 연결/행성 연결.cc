# include <iostream>
# include <queue>
using namespace std;

int N;
int map[1001][1001];
int visited[1001];
long long cost;
int node;

void prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    for(int i=1;i<=N;i++){
        while(!pq.empty() && visited[pq.top().second]){
            pq.pop();
        }
        
        cost += pq.top().first;
        node = pq.top().second;
        visited[node]=1;

        for(int j=1;j<=N;j++){
            pq.push({map[node][j],j});
                
            
        }
    }
    

}

int main(){
    cin>>N;
    int temp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> temp;
            map[i][j]=temp;
        }
    }

    prim();
    cout<<cost;
}