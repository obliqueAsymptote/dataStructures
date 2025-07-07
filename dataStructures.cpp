#include <iostream>
#include <vector>

using std::string, std::cout;
/*
-linked list
-stack
-queue
-graph
*/

struct Node{
    private:
        string item;
        int pointer;
    public:
        Node(const string& item){
            this->item = item;
        }
        ~Node(){
            cout << "Node revoking from memory";
        }
        void setPointer(int nextIndex){
            pointer = nextIndex;
        }
};

class LinkedList{
    private:
        std::vector<Node> list;
        int headPointer;
    public:
        LinkedList(const Node& firstItem){
            list.reserve(10);
            list.push_back(firstItem);
            headPointer = 0;
        }
        void insertItem(const Node& item){
            list.push_back(item);
        }
};