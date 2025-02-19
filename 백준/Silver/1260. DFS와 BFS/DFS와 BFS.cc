#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int nodeNum, archNum, startNode;
vector<int>adj[1002];
vector<int>BFSpath;
vector<int>DFSpath;
bool DFSvisit[1002]={false};
void getInput();
void BFS(int startNode);
void DFS(int startNode);

int main(){
    getInput();
    DFS(startNode);
    for(int i=0;i<DFSpath.size();i++){
        cout<<DFSpath[i]<<" ";
    } 
    cout<<endl;
    BFS(startNode);

    return 0;
    
}
void getInput(){

    cin >> nodeNum >> archNum >> startNode;
    int node_1, node_2;
    for(int i=0;i<archNum;i++){
        cin>>node_1>>node_2;
        adj[node_1].push_back(node_2);
        adj[node_2].push_back(node_1);
    }
    for(int i=1;i<=nodeNum;i++){
        sort(adj[i].begin(),adj[i].end());
    }
}

void BFS(int startNode){
    queue<int>q;
    bool BFSvisit[1002]={false};
    q.push(startNode);
    BFSvisit[startNode]=true;
    while(!q.empty()){
        int presentNode = q.front();//맨 앞의 숫자
        BFSvisit[presentNode]=true;
        BFSpath.push_back(presentNode);
        q.pop();//queue에서 pop
        for(int i=0;i<adj[presentNode].size();i++){
            if(BFSvisit[adj[presentNode][i]]==false)
                q.push(adj[presentNode][i]);
                BFSvisit[adj[presentNode][i]]=true;
        }
    }
    for(int i=0;i<BFSpath.size();i++){
        cout<<BFSpath[i]<<" ";
    }  
}

void DFS(int startNode){

    DFSvisit[startNode]=true;
    cout<<startNode<<" ";
    for(int i=0;i<adj[startNode].size();i++){
        int x = adj[startNode][i];
        if(DFSvisit[x]==false){
            DFS(x);
        }
    }
}
