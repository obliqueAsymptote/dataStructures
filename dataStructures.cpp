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
        Node* getNextNode() {
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

        void insertNode(const Node& node){
            unique_ptr<Node> newNode = std::make_unique<Node>(node.getItem());
            if (headNode == nullptr){
                headNode = std::move(newNode);
            }
            else{
                Node* currentNode = headNode.get();
                while (currentNode->getNextNode() != nullptr){
                    currentNode = currentNode->getNextNode();
                }
                currentNode->setPointer(std::move(newNode));
            }
        }
        void outputList(){
            Node* currentNode = headNode.get();
            while (currentNode != nullptr){
                std::visit([](const auto& value){
                    cout << value << " ";
                }, currentNode->getItem());
                currentNode = currentNode->getNextNode();
            }
        }
};

int main(){
    Node nodeOne = Node("meow");
    Node nodeTwo = Node("wroof");
    LinkedList testList;
    testList.insertNode(nodeOne);
    testList.insertNode(nodeTwo);
    
    testList.outputList();

    return 0;
}