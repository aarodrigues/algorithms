#include <iostream>
#include <list>
#include <stack>
#include <sstream>


class Graph {
    public:
        int num_vertices;
        std::list<int> *adjacency_list;
        std::list<int> path;

        Graph(const int &num_vertices) {
            this->num_vertices = num_vertices;
            this->adjacency_list = new std::list<int>[num_vertices]();
        }

        void addEdge(const int &from_vertice, const int &to_vertice) {
            adjacency_list[from_vertice].push_back(to_vertice);
        }

        void deepFirtSearch(const int &initial_vertice) {
            bool visited_vertices[num_vertices];
            std::stack <int> stack;

            visited_vertices[initial_vertice] = true;
            std::cout << "Starting at " << initial_vertice << std::endl;
            stack.push(initial_vertice);

            while(stack.size() != 0) {
                int vertice = stack.top();
                stack.pop();
                std::cout << "De-stacking " << vertice << std::endl;
                path.push_back(vertice);

                for (auto const& item : adjacency_list[vertice]) {
                    int adjacent_vertice = item;
                    if(!visited_vertices[adjacent_vertice]) {
                        visited_vertices[adjacent_vertice] = true;
                        std::cout << "Stacking " << adjacent_vertice << std::endl;
                        stack.push(adjacent_vertice);
                    }
                }
            }
            this->printPath();
        }

        void printPath() {
            std::ostringstream oss;
            for(auto const &item : path) {
                oss << item << " ";
            }
            std::cout << "Traveled path: " << oss.str() << std::endl;
        }
};