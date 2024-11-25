#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int SIZE = 13;

struct Edge 
    {
        int src, dest, weight;
    };

typedef pair<int, int> Pair; // Creates alias 'Pair' for the pair<int,int> data type

class Graph 
    {
    public:
        // a vector of vectors of Pairs to represent an adjacency list
        vector<vector<Pair>> adjList;
        
        // Graph Constructor
        Graph(vector<Edge> const &edges) 
            {
            
            // resize the vector to hold SIZE elements of type vector<Edge>
            adjList.resize(SIZE);
        
            // add edges to the directed graph
            for (auto &edge: edges) 
                {
                int src = edge.src;
                int dest = edge.dest;
                int weight = edge.weight;
                // insert at the end
                adjList[src].push_back(make_pair(dest, weight));
                // for an undirected graph, add an edge from dest to src also
                adjList[dest].push_back(make_pair(src, weight));
                }
            }
       
        // Print the graph's adjacency list
        void printGraph() 
            {
            cout << "Graph's adjacency list:" << endl;
                for (int i = 0; i < adjList.size(); i++) 
                    {
                    cout << i << " --> ";
                    for (Pair v : adjList[i])
                    cout << "(" << v.first << ", " << v.second << ") ";
                    cout << endl;
                    }
            }
   /* void bfs(int start)
        {
            vector<bool> visited(SIZE, false); 

            queue<int> q; 

            visited[start] = true; 
            q.push(start); 

            cout<<"BFS starting from vertex "<<start<<":"<<endl;

            while(!q.empty()) 
            {
                int current = q.front();
                q.pop(); 
                cout<<current<<" ";

                for(int x: adjList[current]) //wawsnt sure how to access the adjacency list
                {
                    if(!visited[x]) 
                    {
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }

        }
     void dfsRecursive (int s)
    {   
        vector<bool> visited (SIZE, false);
        visited[s] = true;
        
        cout<<"DFS starting from vertex"<<s<<": "<<endl;  

        for (int x : adjList[s])
            if(visited[x] == false)
                dfsRecursive(x);     
    }*/

    };



   

int main() {

    

    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
    // (x, y, w) —> edge from x to y having weight w
    {0,2,8}, {0,3,21},{0,7,7}, {0,11,11},{0,12,12},{2,3,6},{2,6,2},{2,4,4},{2,9,5},
    {3,8,18},{4,9,9},{6,9,6},{6,10,2},{7,10,10},{11,12,13}
    }; //manually add the deleted the nodes. deleted nodes 1 and 5
        // added nodes 7, 8, 9, 10, 11, 12

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();

   // graph.bfs(0); 

    return 0;
}