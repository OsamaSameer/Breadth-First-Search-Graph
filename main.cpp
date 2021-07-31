#include<iostream>
#include<list>
using namespace std;
class Graph {
    int v;
    list<int>* adj;
public:
    Graph(int v);
    void Add_Edge(int v, int w);
    void bfs(int s);
};
Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::Add_Edge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::bfs(int s)
{
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " "<<endl;
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.Add_Edge(0, 1);
    g.Add_Edge(0, 2);
    g.Add_Edge(1, 2);
    g.Add_Edge(2, 0);
    g.Add_Edge(2, 3);
    g.Add_Edge(3, 3);
    g.Add_Edge(3, 1);
    g.Add_Edge(3,4);
    cout << "Breadth First Traversal\n\n";
    g.bfs(3);
    return 0;
}
