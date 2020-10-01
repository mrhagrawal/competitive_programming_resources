/*=========== Graph Important Questions====================================
1.) Clone a Graph
2.) Check Graph is Bipartite or Not
3.) Disjoint Set Implmentation
4.) Kruskal
5.) Prims
6.) Djiktras
7.) Bellman Ford
8.) Floyd Warshall
*/

//----------------------Clone a Graph --------------------------
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution 
{
    public:
    Node* cloneGraph(Node* node) 
    {
        if(node == NULL)
        return NULL;
        
        unordered_map<Node *,Node *> mp;
        queue<Node *> q;
        q.push(node);
      
        mp[node] = new Node(node->val);
        
        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            
           // cout<<temp->neighbors.size()<< endl;
            
            for(auto n:temp->neighbors)
            {
                if(!mp[n]) 
                {
                    mp[n] = new Node(n->val);
                    q.push(n);
                }
                cout<<mp[n]->val<<" "<<mp[n]->neighbors.size()<<endl;;
                mp[temp]->neighbors.push_back(mp[n]);
            }
        }
        
        return mp[node];
    }
};

//-------------------------- Bipartite Graph ------------------------------------
class Solution 
{
    vector<int> adj[1000];
   
    public:
    bool util(vector<int> &vis,vector<int> &col,int child,int c)
    {
        vis[child] = true;
        col[child] = c;
        
        for(auto e:adj[child])
        {
            if(vis[e] == 0)
            {
                if(util(vis,col,e,!c)==0)
                return false;
            }
            
            else if(col[e] == col[child] )
            return false;
        }
        
        return true;
    }
    
    public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(graph.size()+1,0);
        vector<int> col(graph.size()+1,0);
        
        for(int i=0;i<graph.size();i++)
        {   
            for(int k=0;k<graph[i].size();k++)
            adj[i].push_back(graph[i][k]);  
        } 
      
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(util(vis,col,i,1) == false)
                return false;
            }
        }        
        return true;
    }
};

//-----------------------Disjoint Set Implmentation -------------------------------
/* 
Cycle Detection Unidirected Graph using DSU - Union and Find Algorithm By Path Compression
==========================================================================================
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
	int parent;
	int rank;
};

vector<node> pr;

//FIND operation
int find(int v)
{
	if(pr[v].parent==-1)
	return v;
	
	return pr[v].parent=find(pr[v].parent);	//Path Compression
}

void union_op(int fromP,int toP)
{
	//UNION by RANK
	if(pr[fromP].rank > pr[toP].rank)	//fromP has higher rank
		pr[toP].parent = fromP;
	else if(pr[fromP].rank < pr[toP].rank)	//toP has higher rank
		pr[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent
		pr[fromP].parent = toP;
		pr[toP].rank +=1;		//Increase rank of parent
	}
}

bool isCyclic(vector<pair<int,int>>& edge_List)
{
	for(auto p: edge_List)
	{
		int fromP = find(p.first);	//FIND absolute parent of subset
		int toP = find(p.second);

		if(fromP == toP)
			return true;

		//UNION operation
		union_op(fromP,toP);	//UNION of 2 sets
	}
	return false;
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

	pr.resize(V);	//Mark all vertices as separate subsets with only 1 element
	for(int i=0;i<V;++i)	//Mark all nodes as independent set
	{
		pr[i].parent=-1;
		pr[i].rank=0;
	}

	vector<pair<int,int>> edge_List;	//Adjacency list
	for(int i=0;i<E;++i)
	{
		int from,to;
		cin>>from>>to;
		edge_List.push_back({from,to});
	}

	if(isCyclic(edge_List))
		cout<<"TRUE\n";
	else
		cout<<"FALSE\n";
	
	return 0;
}

//TIME COMPLEXITY: O(E.V)

//-------------------------------- Kruskal ----------------------------------------
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;

	class graph
	{
		vector<pair<int,par>> edges;
		int v;

		public:
		graph(int n)
		{ v=n; }

		void addEdge(int u,int v,int w)
		{ edges.push_back({w,{u,v}}); }

		int kruskal_mst();
	};

	struct node 
	{ 
		int parent; 
		int rank; 
	};

	vector<node> pr;
	
	//===================================================================
	int find(int v)
	{
		if(pr[v].parent==-1)
		return v;
		return pr[v].parent=find(pr[v].parent);	
	}

	void union_op(int fromP,int toP)
	{
		if(pr[fromP].rank > pr[toP].rank)	
		pr[toP].parent = fromP;
		
		else if(pr[fromP].rank < pr[toP].rank)	
		pr[fromP].parent = toP;
		
		else
		{
			pr[fromP].parent = toP;
			pr[toP].rank +=1;		
		}
	}
	// har baar minimum weight wale edge sae select krte
	
	int graph::kruskal_mst()	  // isme ham sirf ye dkhte hai ki naya edge cycle na bnaye
	{
		int mst_wt = 0;
		sort(edges.begin(),edges.end()); // {wt, {u,v}}
		
		vector<pair<int,par>>:: iterator it;
		
		for(it = edges.begin();it!=edges.end();it++)
		{
			int u = it->second.first;
			int v = it->second.second;

			int wt = it->first;

			int u_par = find(u);
			int v_par = find(v);

			if(u_par != v_par)   // Keep Choosing Min Edge as long as there is no Cycle
			{
				cout<<u<<" "<<v<<endl;
				mst_wt = mst_wt + wt;
				union_op(u_par,v_par);
			} 
		}
		//print_mst();
		return mst_wt;
	}

//==================================================================================
int main()
{
	int e = 14;
	int v = 9; 
	
	pr.resize(v);	
	
	for(int i=0;i<v;++i)
	{ pr[i].parent=-1; pr[i].rank=0; }
	
	graph g(v); 
  	
  	//  making above shown graph 
   	g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    cout << "Edges of MST are \n"; 
    int mst_wt = g.kruskal_mst(); 
  	cout << "\nWeight of MST is " << mst_wt; 

  	return 0;
}

//-------------------------------- Prims ---------------------------------------
#include<bits/stdc++.h>
using namespace std;

class graph
{
	vector< pair<int,int> > adj[100];
	int v;
	
	public:
	graph(int n)
	{v=n;}

	void addEdge(int u,int v,int w)
	{
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	void printMst()
	{
		int dist[v] , parent[v], inMst[v];

		for(int i=0;i<v;i++)
		{ dist[i] = INT_MAX;   parent[i] = -1;   inMst[i] = 0; }
			
		priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int> >> pq;
		
		int src = 0;             // We delibrately select source node in prims algorithm
		dist[src] = 0;

		pq.push({0,src})  ; // {wt,node}

		while(pq.empty() == false)
		{
			int node = pq.top().second;
			pq.pop();
			
			inMst[node] = 1;

			for(auto x = adj[node])
			{
				int child = x.first;
				int wt = x.second;

				if(inMst[child] == false  && dist[child] > wt)
				{
					dist[child] = wt;
					pq.push({dist[child],child});
					parent[child] = node;
				}
			}
		}

		for(int i=0;i<v;i++)
		{ 
			if (i==0)
			continue;
			cout<<parent[i]<<"->"<<i<<"\n"; 
		}
	
	}
};

	int main()
	{

		int v = 9;
		graph g(v);

		g.addEdge(0, 1, 4); 
	    g.addEdge(0, 7, 8); 
	    g.addEdge(1, 2, 8); 
	    g.addEdge(1, 7, 11); 
	    g.addEdge(2, 3, 7); 
	    g.addEdge(2, 8, 2); 
	    g.addEdge(2, 5, 4); 
	    g.addEdge(3, 4, 9); 
	    g.addEdge(3, 5, 14); 
	    g.addEdge(4, 5, 10); 
	    g.addEdge(5, 6, 2); 
	    g.addEdge(6, 7, 1); 
	    g.addEdge(6, 8, 6); 
	    g.addEdge(7, 8, 7); 
		
		g.printMst();
		return 0;
	}

//-------------------------- Djiktras ----------------------------------
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

class graph
{
	vector<pr> adj[10000];
	int v;
	public:
	graph(int n)
	{v=n;}

	void addEdge(int u,int v,int w)
	{
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	void dijkstra(int src) // In Djiktras we are given with the source node 
	{
		priority_queue<pr,vector<pr>,greater<pr>> pq;
		vector<int> dist(v,INT_MAX);
		
		dist[src] = 0;
		pq.push({0,src});   // {wt,node}

		while(pq.empty()==false)
		{
			int node = pq.top().second;
			pq.pop();

			for(auto x:adj[node])
			{
				int child = x.first;
				int wt = x.second;

				if(dist[child] > dist[node] + wt)
				{
					dist[child] = dist[node] + wt;
					pq.push({dist[child],child});
				}
			}
		}
		
		cout<<"Distance of Each Node From Source Vertex:"<<src<<endl;
		for(int i=0;i<v;i++)
		cout<<src<<"->"<<i<<" = "<<dist[i]<<endl;
	}
};


int main() 
{ 
    // create the graph given in above fugure 
    int v = 9; 
    graph g(v); 
    g.addEdge( 0, 1, 4); 
    g.addEdge( 0, 7, 8); 
    g.addEdge( 1, 2, 8); 
    g.addEdge( 1, 7, 11); 
    g.addEdge( 2, 3, 7); 
    g.addEdge( 2, 8, 2); 
    g.addEdge( 2, 5, 4); 
    g.addEdge( 3, 4, 9); 
    g.addEdge( 3, 5, 14); 
    g.addEdge( 4, 5, 10); 
    g.addEdge( 5, 6, 2); 
    g.addEdge( 6, 7, 1); 
    g.addEdge( 6, 8, 6); 
    g.addEdge( 7, 8, 7); 
  
    g.dijkstra(0); 
  
    return 0; 
} 

//------------------------------- Bellman Ford ---------------------------------------
#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int src,dst,wt;
};

int V,E;

void bellmanFord(vector<edge>& Edges,int src)
{
	vector<int> dist(V,INT_MAX);	//Keeps shortest path dists to each vertex from source
	dist[src] = 0;	//start node has dist=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	bool updated;
	for(int i=0;i<V-1;++i)
	{
		updated = false;
		for(int j=0;j<E;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(dist[U]!=INT_MAX && dist[V] > dist[U] + wt)      //similar to => {dist[child] > dist[node] + wt}
			{
				dist[V] = dist[U]+wt;
				updated = true;
			}
		}
		if(updated==false)
		break;
	}
	//Now check by relaxing once more if we have a negative edge cycle
	for(int j=0;j<E && updated == true;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(dist[U]!=INT_MAX and dist[V] > dist[U] + wt)
			{
				cout<<"Graph has -VE edge cycle\n";
				return;
			}
		}
	//Print Shortest Path Graph
	for(int i=0;i<V;++i)
	cout<<src<<"->"<<i<<"="<<dist[i]<<"\n";
}

int main()
{
	cin>>V>>E;	//Enter no of Vertices and Edges
	vector<edge> edgelist(E);

	//Now input all E edges
	int src,dst,wt;
	for(int i=0;i<E;++i)
	{
		cin>>src>>dst>>wt;
		
		edgelist[i].src = src;
		edgelist[i].dst = dst;
		edgelist[i].wt = wt;
	}

	bellmanFord(edgelist,0);	
	return 0;
}

//TIME COMPLEXITY: O(V.E)

//----------------------------------- Floydd Warshall ------------------------------------------------
// Floyd Warshall
----------------------------------------
#include<bits/stdc++.h>
using namespace std;

#define INT_MAX inf
int V;

void floyd_warshall(int graph[V][V])
{
	int dist[V][V];

	//Assign all values of graph to allPairs_SP
	for(int i=0;i<V;++i)
	{	
		for(int j=0;j<V;++j)
		dist[i][j] = graph[i][j];
	}

	//Find all pairs shortest path by trying all possible paths
	for(int k=0;k<V;++k)
	{	
		//Try all intermediate nodes
		for(int i=0;i<V;++i)	//Try for all possible starting position
		{	
			for(int j=0;j<V;++j)	//Try for all possible ending position
			{
				if(dist[i][k] == inf || dist[k][j] == inf)	//SKIP if K is unreachable from i or j is unreachable from k
				continue;
				
				else if(dist[i][k]+dist[k][j] < dist[i][j])		//Check if new distance is shorter via vertex K
				dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	//Check for negative edge weight cycle
	for(int i=0;i<V;++i)
	{	
		if(dist[i][i] < 0)
		{
			cout<<"Negative edge weight cycle is present\n";
			return;
		}
	}

	//Print Shortest Path Graph
	//(Values printed as inf defines there is no path)
	for(int i=1;i<V;++i)
	{
		for(int j=0;j<V;++j)
		cout<<i<<" to "<<j<<" distance is "<<dist[i][j]<<"\n";
		
		cout<<"=================================\n";
	}
}

int main()
{
	V = 6;
	int graph[V][V] = { {0, 1, 4, inf, inf, inf},
						{inf, 0, 4, 2, 7, inf},
						{inf, inf, 0, 3, 4, inf},
						{inf, inf, inf, 0, inf, 4},
						{inf, inf, inf, 3, 0, inf},
						{inf, inf, inf, inf, 5, 0} 
					  };

	floyd_warshall(graph);
	return 0;
}
//TIME COMPLEXITY: O(V^3)
