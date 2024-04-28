#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>

using namespace std;

const int MAX = 100000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) 
{
	stack<int> s;
	s.push(node);

	while (!s.empty()) 
	{
    	int curr_node = s.top();
    	s.pop();

    	if (!visited[curr_node]) 
    	{
        	visited[curr_node] = true;
        	
        	if (visited[curr_node])
        	{
        	cout << curr_node << " ";
    	    	}

        	#pragma omp parallel for
        	for (int i = 0; i < graph[curr_node].size(); i++)
        	{
            	int adj_node = graph[curr_node][i];
            	if (!visited[adj_node]) 
            	{
                	s.push(adj_node);
            	}
        	}
    	}
	}
}

int main()
{
	int n, m, start_node;
	
	cout << "Enter No of Node,Edges,and start node:" ;
	cin >> n >> m >> start_node;
         
    cout << "Enter Pair of edges:" ;
	for (int i = 0; i < m; i++) 
	{
    	int u, v;
    		
    	cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
	}

	#pragma omp parallel for
	for (int i = 0; i < n; i++) 
	{
    	visited[i] = false;
	}

	dfs(start_node);

	return 0;
}

// -------------------------------------OUTPUT--------------------------------------
/*
gescoe@gescoe-OptiPlex-3010:~/Aniket$ g++ -o gfg -fopenmp HPC1B.cpp
gescoe@gescoe-OptiPlex-3010:~/Aniket$ ./gfg
Enter No of Node,Edges,and start node:
5
4
0
Enter Pair of edges:
0 1
0 2
2 3
2 4
0 1 2 4 3 
escoe@gescoe-OptiPlex-3010:~/Aniket$ 
*/
