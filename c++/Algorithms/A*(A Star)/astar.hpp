#include <iostream>
#include <map>
#include <list>
#include <set>

#define INFINIT INT16_MAX

template<typename T>
class Graph {
     public:
        int num_vertices;
        bool bidiretional;
        // map content: from_node -> pair(to_node, weight)  
        std::map<T,std::list<std::pair<T,int>>> adjacency_map;
        
        Graph(const int &num_vertices, bool bidiretional=true) {
            this->num_vertices = num_vertices;
            this->bidiretional = bidiretional;
        }

        void addEdge(const T &from_vertice, const T &&to_vertice, const int &weight) {
            adjacency_map[from_vertice].push_back(make_pair(to_vertice,weight));
            if(this->bidiretional) {
                adjacency_map[to_vertice].push_back(make_pair(from_vertice,weight));
            }
        }

        void printAdjacencies() {
            for(auto v_list : adjacency_map) {
                std::cout << "vertice: " << v_list.first << "->";
                for(auto adj_vertice : v_list.second) {
                    std::cout << "(" << adj_vertice.first << "," << adj_vertice.second << ")";
                }
                std::cout << std::endl;
            }
        }

        void aStart(const T &start_vertice) {
            std::map<T,int> vertice_distances;

            for(auto adj_vertice : adjacency_map) {
                vertice_distances[adj_vertice.first] = INFINIT;
            }

   
        }

        void printDistances(std::map<T,int> vertice_distances) {
            for(auto vertice_distance : vertice_distances) {
                std::cout << vertice_distance.first << " is located at distance of " << vertice_distance.second << std::endl;
            }
        }
};