#include <iostream>
#include <vector>
#include <variant>
#include <memory>
#include <bits/stdc++.h>

using std::string, 
std::cout, 
std::variant,
std::unique_ptr;
/*
-linked list
-stack
-queue
-graph
*/

struct Node{
    private:
        variant<string, int> item;
        unique_ptr<Node> pointer;
    public:
        Node(const variant<string, int>& nodeItem) : item(nodeItem), pointer(nullptr) {}
        
        void setPointer(unique_ptr<Node> nextNode){
            this->pointer = std::move(nextNode);
        }
        const variant<string, int>& getItem() const{
            return item;
        }
        const Node* getNextNode() const{
            return pointer.get();
        }
        unique_ptr<Node>& getNextUniPtr(){
            return pointer;
        }

        bool operator==(const Node& otherNode) const{
            return item == otherNode.item;
        }
        bool operator!=(const Node& otherNode) const {
            return !(*this == otherNode);
        }
};

class LinkedList{
    private:
        unique_ptr<Node> headNode;
    public:
        LinkedList() : headNode(nullptr) {}
        LinkedList(unique_ptr<Node> firstNode) : headNode(std::move(firstNode)) {}

        ~LinkedList() {
            cout << "Releasing linked list\n";
        }
};