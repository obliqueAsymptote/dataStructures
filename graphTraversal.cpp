#include <iostream>
#include <vector>
#include <memory>

using
std::string,
std::cout,
std::vector,
std::shared_ptr,
std::getline,
std::cin;

class Graph{
    private:
        vector<vector<int>> adjMatrix;
        bool biDirectional;
    public:
        Graph(int n, bool direction) : adjMatrix(n, vector<int>(n, 0)), biDirectional(direction){}

        void addWeight(int nodeOne, int nodeTwo, int weight){

            adjMatrix[nodeOne][nodeTwo] = weight;
            adjMatrix[nodeTwo][nodeOne] = weight;
        }
        void addEdge(int nodeOne, int nodeTwo){
            adjMatrix[nodeOne][nodeTwo] = 1;
            if (biDirectional){
                adjMatrix[nodeTwo][nodeOne] = 1;
            }
        }
        void printGraph(){
            for (int row = 0; row < adjMatrix.size(); row++){
                for (int element = 0; element < adjMatrix.size(); element++){
                    cout << adjMatrix[row][element] << " ";
                }
            cout << "\n";
            }
        }
};

int main(){
    int vertices;
    bool biDirectional = false;
    cout << "Enter the number of vertices in your graph:\n";
    cin >> vertices;
    cin.ignore();
    cout << "Is your graph direction? (y)/n:\n";
    if (cin.peek() == '\n' || cin.peek() == 'y'){
        biDirectional = true;
    }

    shared_ptr<Graph> graph = std::make_shared<Graph>(vertices, biDirectional);
    

    return 0;
}