from collections import defaultdict

class Graph:

    def __init__(self):
        self.adjacency_list = defaultdict(list)
        self.path = []

    def addEdge(self, from_v, to_v):
        self.adjacency_list[from_v].append(to_v)


    def breathFirstSearch(self, init_vertice):
        visited_vertices = len(self.adjacency_list)*[False]
        queue = []

        visited_vertices[init_vertice] = True
        queue.append(init_vertice)

        while(len(queue) != 0):
            vertice = queue.pop(0)
            print("De-queueing "+str(vertice))
            self.path.append(vertice)

            for adj_v in self.adjacency_list[vertice]:
                if(not visited_vertices[adj_v]):
                    visited_vertices[adj_v] = True
                    print("Queueing "+str(adj_v))
                    queue.append(adj_v)

        print(self.path) 



graph = Graph()

graph.addEdge(0, 1)
graph.addEdge(1, 0)
graph.addEdge(1, 4)
graph.addEdge(4, 1)
graph.addEdge(4, 6)
graph.addEdge(6, 4)
graph.addEdge(6, 0)
graph.addEdge(0, 6)
graph.addEdge(1, 5)
graph.addEdge(5, 1)
graph.addEdge(5, 3)
graph.addEdge(3, 5)
graph.addEdge(3, 0)
graph.addEdge(0, 3)
graph.addEdge(5, 2)
graph.addEdge(2, 5)
graph.addEdge(2, 7)
graph.addEdge(7, 2)

graph.breathFirstSearch(0)