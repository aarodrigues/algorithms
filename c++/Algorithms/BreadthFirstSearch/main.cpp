#include <iostream>
#include "bfs.hpp"


int main()
{
    std::cout<<"Hello Breasth First Search!\n";
    Graph graph(8);
    graph.addEdge(0, 1);
    graph.addEdge(1, 0);
    graph.addEdge(1, 4);
    graph.addEdge(4, 1);
    graph.addEdge(4, 6);
    graph.addEdge(6, 4);
    graph.addEdge(6, 0);
    graph.addEdge(0, 6);
    graph.addEdge(1, 5);
    graph.addEdge(5, 1);
    graph.addEdge(5, 3);
    graph.addEdge(3, 5);
    graph.addEdge(3, 0);
    graph.addEdge(0, 3);
    graph.addEdge(5, 2);
    graph.addEdge(2, 5);
    graph.addEdge(2, 7);
    graph.addEdge(7, 2);

    graph.breadthFirtSearch(0);

    return 0;
}