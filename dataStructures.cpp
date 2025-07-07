#include <iostream>
#include <vector>
#include <variant>
#include <memory>

using std::string, std::cout, std::variant;
/*
-linked list
-stack
-queue
-graph
*/

struct Node{
    private:
        variant<string, int> item;
        std::unique_ptr<Node> pointer;
    public:
        Node(const variant<string, int>& item){
            this->item = item;
            pointer = nullptr;
        }
        ~Node(){
            cout << "Node revoking from memory";
        }
        void setPointer(std::unique_ptr<Node> nextNode){
            this->pointer = std::move(nextNode);
        }
        const variant<string, int>& getItem() const{
            return item;
        }
        const Node* getNextNode() const{
            return pointer.get();
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
        void insertItem(Node& item){
            list.push_back(item);
        }
};