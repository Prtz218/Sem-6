#include<bits/stdc++.h>
using namespace std;

class Graph{
    void edge(int x1,int x2){
        lst[x1].push_back(x2);
        lst[x2].push_back(x1);
    }
    public:
    vector<vector<int>> lst;
    Graph(int n,int e){
        lst.resize(n);
        for(int i=0;i<e;i++){
            cout<<"Enter 2 vertices: ";
            int a,b;
            cin>>a>>b;
            edge(a,b);
        }
    }

    void bfs(queue<int>&q,vector<bool>&v){
        if(q.empty()){
            return;
        }
        int vi = q.front();
        q.pop();
        cout<<vi<<" ";

        for(int i=0;i<lst[vi].size();i++){
            if(!v[lst[vi][i]]){
                v[lst[vi][i]] = true;
                q.push(lst[vi][i]);
            }
        }
        bfs(q,v);
    }

    void dfs(stack<int>&s,vector<bool>&v){
        if(s.empty()){
            return;
        }
        int vi = s.top();
        s.pop();
        cout<<vi<<" ";
        for(int i=0;i<lst[vi].size();i++){
            if(!v[lst[vi][i]]){
                v[lst[vi][i]] = true;
                s.push(lst[vi][i]);
            }
        }

        dfs(s,v);
    }
};

int main()
{
  int n,e;
  cout<<"count of vertices & edges: ";
  cin>>n>>e;
  Graph g(n,e);
  vector<bool>vi(n,false);
  queue<int>q;
  stack<int>s;

    // bfs
    cout<<"BFS: \n";
    for(int i=0;i<n;i++){
        if(!vi[i]){
            vi[i] = true;
            q.push(i);
            g.bfs(q,vi);
        }
    }
    for(int i=0;i<n;i++){
        vi[i] = false;
        // cout<<vi[i];
    }
    // dfs
    cout<<"\nDFS:\n";
    for(int i=0;i<n;i++){
        if(!vi[i]){
            vi[i] = true;
            s.push(i);
            g.dfs(s,vi);
        }
    }
  
  
    return 0;
}