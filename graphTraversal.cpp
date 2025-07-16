#include <iostream>
#include <vector>
#include <memory>
#include <optional>

using
std::string,
std::cout,
std::vector,
std::shared_ptr,
std::getline,
std::cin,
std::optional,
std::pair;



class Graph{
    private:
        vector<vector<int>> adjMatrix;
        bool biDirectional;
    public:
        Graph(int n, bool direction) : adjMatrix(n, vector<int>(n, 0)), biDirectional(direction){
            adjMatrix.reserve(n*n);
        }
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
        /*
        pair<string, int> dijkstrasFindPath(int startNode, int endNode) {
        }
        */
        void printGraph(){
            for (int row = 0; row < adjMatrix.size(); row++){
                for (int element = 0; element < adjMatrix.size(); element++){
                    cout << adjMatrix[row][element] << " ";
                }
            cout << "\n";
            }
        }
        bool getDirection(){
            return biDirectional;
        }
};

void addConnection(const shared_ptr<Graph>& graph, bool weight){

    int edgeNumber;
    cout << "Please enter the amount of edges in your graph:\n";
    cin >> edgeNumber;

    for (int i = 0; i < edgeNumber; i++){
        int nodeOne;
        int nodeTwo;
        cout << "Enter node one:\n";
        cin >> nodeOne;
        cout << "Enter node two:\n";
        cin >> nodeTwo;

        if (weight){
            int Weight;
            cout << "Enter weight:\n";
            cin >> Weight;
            graph->addWeight(nodeOne, nodeTwo, Weight);
            graph->printGraph();
            return;
        }
        graph->addEdge(nodeOne, nodeTwo);        
    }
    cout << "Current graph:\n";
        graph->printGraph();
}

int main(){
    int vertices;
    bool biDirectional = false;
    cout << "Enter the number of vertices in your graph:\n";
    cin >> vertices;
    cin.ignore();
    cout << "Is your graph directed? (y)/n:\n";
    if (cin.peek() == '\n' || cin.peek() == 'y'){
        biDirectional = true;
    }
    cin.ignore();
    shared_ptr<Graph> graph = std::make_shared<Graph>(vertices, biDirectional);
    bool hasWeights = false;
    cout << "Does your graph have weights? (y)/n:\n";
    if (cin.peek() == '\n' || cin.peek() == 'y'){
        hasWeights = true;
    }
    cin >> hasWeights;
    if (hasWeights && graph->getDirection() == true){
        addConnection(graph, true);
    }
    else{
        addConnection(graph, false);
    }


    return 0;
}