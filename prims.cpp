#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class graph
{
public:
vector<vector<int>> grap;
void create(int n,int s,int d,int w)
{
            grap.resize(n,vector<int>(n,0));

    grap[s][d]=w;
    grap[d][s]=w;
}

int minDistancevertex(vector<int>distance, vector<bool>mstSet){
        int min=INT_MAX, min_index;
        for(int v=0; v<distance.size();v++){
            if(!mstSet[v] && distance[v]<min){
                min=distance[v], min_index=v;
            }
        }
        return min_index;
    }
void prims(int start)
{
    int n=grap.size();
    vector<int> dist(n,INT_MAX);
    vector<bool> vis(n,false);
    vector<int> parent(n,-1);
    dist[start]=0;
    for(int i=0;i<n-1;i++)
    {
        int a=minDistancevertex(dist,vis);
        vis[a]=true;
        for(int b=0;b<n;b++)
        {
            if(grap[a][b]!=0 && !vis[b] && grap[a][b]<dist[b])
            {
                parent[b]=a;
                dist[b]=grap[a][b];
            }
        }
    }

    for(int i=1;i<grap.size();i++)// for loop starts wiht 1 , because , parent[0] will be the parent ka first waala and that is the source waala , so parent[source] does not have a predecessor node (since parent vector stores the predecessors)
    {
        cout<<parent[i]<<" - "<<i<<" "<<grap[parent[i]][i]<<endl;
    }
}

};

int main(){
    cout<<"enter no of vertices : "<<endl;
    int v;
    cin>>v;
    cout<<"Enter no of edges : "<<endl;
    int e;
    cin>>e;
    graph g;
    // g.get_size(v);
    for(int i=0;i<e;i++)
    {
        cout<<"enter source, destination, weight"<<endl;
        int s,d,w;
        cin>>s>>d>>w;
        g.create(v,s,d,w);
    }
    cout<<"Enter the start vertex "<<endl;
    int start;
    cin>>start;
    g.prims(start);

    return 0;
}


// INPUT:
// enter no of vertices : 
// 7
// Enter no of edges : 
// 9
// enter source, destination, weight
// 0
// 1
// 10
// enter source, destination, weight
// 1
// 4
// 25
// enter source, destination, weight
// 0
// 3
// 28
// enter source, destination, weight
// 4
// 2
// 24
// enter source, destination, weight
// 2
// 3
// 14
// enter source, destination, weight
// 4
// 5
// 22
// enter source, destination, weight
// 5
// 6
// 12
// enter source, destination, weight
// 3
// 6
// 16
// enter source, destination, weight
// 2
// 5
// 18
// 0
// OUTPUT:
// 0 - 1 10
// 3 - 2 14
// 6 - 3 16
// 1 - 4 25
// 4 - 5 22
// 5 - 6 12
// TOTAL:99