#include<bits/stdc++.h> 
#include<cstdio>
using namespace std; 
  
// Creating shortcut for an integer pair 
typedef  pair<int, int> iPair; 
int lastweight=-1,sec=0;
int pool[100010];
// Structure to represent a graph 
struct Graph 
{ 
    int V, E; 
    vector< pair<int, iPair> > edges; 
  
    // Constructor 
    Graph(int V, int E) 
    { 
        this->V = V; 
        this->E = E; 
    } 
  
    // Utility function to add an edge 
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
  
    // Function to find MST using Kruskal's 
    // MST algorithm 
    int kruskalMST(); 
}; 
  
// To represent Disjoint Sets 
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    // Constructor. 
    DisjointSets(int n) 
    { 
        // Allocate memory 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        // Initially, all vertices are in 
        // different sets and have rank 0. 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
  
            //every element is parent of itself 
            parent[i] = i; 
        } 
    } 
  
    // Find the parent of a node 'u' 
    // Path Compression 
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    // Union by rank 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  
 /* Functions returns weight of the MST*/ 
  
int Graph::kruskalMST(int *pool) 
{ 
    int mst_wt = 0; // Initialize result 
  
    // Sort edges in increasing order on basis of cost 
    sort(edges.begin(), edges.end()); 
  
    // Create disjoint sets 
    DisjointSets ds(V); 
  
    // Iterate through all sorted edges 
    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
  
        if (set_u != set_v) 
        { 
            // cout << u << " - " << v << endl; 
  
            // Update MST weight 
            mst_wt += it->first;
            // sec++;
            // if(sec*2 >=it->first)
            pool.push_back(lastweight);
            lastweight= it->first;
            // cout << "L " << lastweight  << endl;
            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    /* Let us create above shown weighted 
       and unidrected graph */
    int V = 100010, E = 200010; 
    Graph g(V, E); 
    int n,q,a,b,w;
    cin >> n >> q;
    int dis[n];
    for (int i = 0; i < n; i++)
        cin >> dis[i];

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        a--,b--;
        g.addEdge(a,b,w);
    }
    //  making above shown graph 
  
    int mst_wt = g.kruskalMST(pool); 
    int mx=-1;
    for(int i=0;i<pool.size();i++){
    }
    
    // cout << "\nWeight of MST is " << mst_wt <<endl; 
    if (lastweight%2 !=0) lastweight+=1;
    cout << lastweight/2 <<endl;
    // cout << sec << endl;
    return 0; 
} 

