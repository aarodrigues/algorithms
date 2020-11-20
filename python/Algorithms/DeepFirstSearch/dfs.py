from collections import defaultdict
class Graph:

    def __init__(self):
        self.adjacent_list = defaultdict(list)
        self.path = []

    def addEdge(self, from_v, to_v):
        self.adjacent_list[from_v].append(to_v)

    def deepFirstSearch(self, init_vertice):
        visited_vertices = len(self.adjacent_list)*[False]
        stack = []

        visited_vertices[init_vertice] = True
        stack.append(init_vertice)

        while(len(stack) != 0):
            vertice = stack.pop()
            print("De-stack"+str(vertice))
            self.path.append(vertice)
            for adj_v in self.adjacent_list[vertice]:
                if(not visited_vertices[adj_v]):
                    visited_vertices[adj_v] = True
                    print("Stacking")
                    stack.append(adj_v)

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

graph.deepFirstSearch(0)