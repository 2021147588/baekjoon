# include <iostream>
# include <queue>
# include <vector>
# include <tuple>
# include <algorithm>
using namespace std;
int V, E;
vector<pair<int, pair<int, int>>> edges;
bool visited[100001];
int parent[10001];

int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]); 
}
void uni(int x, int y) {
	x = find(x); 
	y = find(y); 
	parent[y] = x; 
}
bool sameparent(int x, int y) {
	x = find(x); 
	y = find(y); 
	if (x == y)return true;
	else return false; 
}

int kruskal(){
    //initializing
    for(int i=1;i<=V;i++) parent[i]=i;

    sort(edges.begin(), edges.end());

    int cost=0;
    
    for(int i=0;i<edges.size();i++){
        if(!sameparent(edges[i].second.first, edges[i].second.second)){
            uni(edges[i].second.first, edges[i].second.second);
            cost+=edges[i].first;
        }
    }
    
    return cost;  
    
}

int main(){

    cin>>V>>E;
    for(int i=0;i<E;i++){
        int from, to, cost;
        cin>>from>>to>>cost;
        edges.push_back({cost, {from, to}});
    }
    cout<<kruskal()<<endl;
}
    