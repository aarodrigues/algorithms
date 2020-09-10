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

        void dijkstra(const T &start_vertice) {
            std::map<T,int> vertice_distances;

            for(auto adj_vertice : adjacency_map) {
                vertice_distances[adj_vertice.first] = INFINIT;
            }

            std::set<std::pair<int,T>> min_distance;
            vertice_distances[start_vertice] = 0;
            min_distance.insert(make_pair(0,start_vertice));

            while(!min_distance.empty()) {
                auto pair = *(min_distance.begin());
                T vertice = pair.second;
                int v_distance = pair.first; 
                min_distance.erase(min_distance.begin());

                for(auto child_pair : adjacency_map[vertice]) {
                    if(v_distance + child_pair.second < vertice_distances[child_pair.first]) {
                        // I set is not possible to update an unique value from pair is not possible 
                        // So it is necessary to remove the old pair and insert a new one
                        T destination_vertice = child_pair.first;
                        auto v_item = min_distance.find(make_pair(vertice_distances[destination_vertice], destination_vertice));
                        if(v_item != min_distance.end()) {
                            min_distance.erase(v_item);
                        }
                        // Insert new pair to update distance
                        vertice_distances[destination_vertice] = v_distance + child_pair.second;
                        min_distance.insert(make_pair(vertice_distances[destination_vertice], destination_vertice));
                    }
                }
            }
            this->printDistances(vertice_distances);
        }

        void printDistances(std::map<T,int> vertice_distances) {
            for(auto vertice_distance : vertice_distances) {
                std::cout << vertice_distance.first << " is located at distance of " << vertice_distance.second << std::endl;
            }
        }
};