#include <bits/stdc++.h>
using namespace std;
#define N 100000
vector<int> parent(N);
vector<int> sz(N);

void make_set(int V){
    parent[V]=V;
    sz[V]=1;
}

int find_set(int V){
    if(V==parent[V]){
        return V;
    }
    return parent[V]=find_set(parent[V]);
}

void union_sets(int s1, int s2){
    s1=find_set(s1);
    s2=find_set(s2);
    if(s1!=s2){
        if(sz[s1]<sz[s2]){
            swap(s1,s2);
        }
        parent[s2]=s1;
        sz[s1]+=sz[s2];
    }
}

int main(){
    int i;
    for(i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    bool cycle=false;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y){
            cycle=true;
        }
        else{
            union_sets(u,v);
        }
    }
    if(cycle){
        cout<<"CYCLE!!!!";
    }
    else{
        cout<<"NO CYCLE";
    }
    return 0;
}


