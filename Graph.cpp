#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//directed graph
class Graph{
	int V;
	int **edges;
public:
	Graph(int v);
	int getV();
	void addEdge(int v,int w);
	void BFS(int v);
	void DFS(int s);
	void DFSr(bool *visited,int start);//recursive method
	void gPrint();
};
Graph::Graph(int v){
	this->V = v;
	edges = new int* [v];
	for(int i=0;i<v;i++){
		edges[i] = new int [v];
	}
}
int Graph::getV(){
	return V;
}
void Graph::addEdge(int v,int w){
	this->edges[v][w] = 1;
}

void Graph::gPrint(){
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<edges[i][j]<<" ";
		}
		cout<<endl;
	}
}


void Graph::BFS(int v){
	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		//push new elements first
		int current = q.front();
		q.pop();
		visited[current] = true;
		for(int i=0;i<V;i++){
			if(edges[current][i]==1){
				if(visited[i]==false){
					q.push(i);
				}
			}
		}
		cout<<current<<" ";
	}
	cout<<endl;

}
//non-recursive version
void Graph::DFS(int s){
	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	stack<int> stack;
	stack.push(s);
	while(!stack.empty()){
		int current = stack.top();
		stack.pop();
		if(visited[current]==false){
			visited[current] = true;
			for(int i=0;i<V;i++){
				if(edges[current][i]==1){
					if(visited[i]==false){
						stack.push(i);
					}
				}
			}
			cout<<current<<" ";
		}
	}
	cout<<endl;
}
//recursion version, print order will be reversed
void Graph::DFSr(bool *visited,int start){
	visited[start] = true;
	for(int i=0;i<V;i++){
		if(edges[start][i]==1){
			if(visited[i]==false){
				DFSr(visited,i);
			}
		}
	}
	cout<<start<<" ";
}

int main(){
	// Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.gPrint();
    g.BFS(2);
    g.DFS(0);
    bool *visited = new bool [g.getV()];
    g.DFSr(visited,0);
	return 0;
}