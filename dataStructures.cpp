#include <iostream>
#include <vector>
#include <variant>
#include <memory>
#include <optional>
#include <bits/stdc++.h>

using std::string, 
std::cout, 
std::variant,
std::unique_ptr,
std::optional,
std::nullopt;
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
            cout << "\nReleasing linked list..terminating\n";
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
        std::optional<Node> deleteNode(const Node& node){
            if (headNode == nullptr){
                cout << "There are no nodes to delete in the linked list\n";
                return nullopt;
            }
            if (*headNode == node){
                Node deletedNode = Node(headNode->getItem());
                headNode = std::move(headNode->getNextUniPtr());
                return deletedNode;
            }
            Node* currentNode = headNode.get();
            while (currentNode->getNextNode() != nullptr){
                if (*(currentNode->getNextNode()) == node){
                    Node deletedNode = Node(currentNode->getNextNode()->getItem());
                    unique_ptr<Node> nodeToDelete = std::move(currentNode->getNextUniPtr());
                    currentNode->setPointer(std::move(nodeToDelete->getNextUniPtr()));
                    return deletedNode;
                }
                currentNode = currentNode->getNextNode();
            }
            return nullopt;
            /*
            finish the deletion
            */
        }
        void outputList(){
            Node* currentNode = headNode.get();
            while (currentNode != nullptr){
                std::visit([](const auto& value){
                    cout << value << "->";
                }, currentNode->getItem());
                currentNode = currentNode->getNextNode();
            }
        }
};

int main(){
   LinkedList testList;
    int userNodes;
    cout << "How many nodes do you want in your linked list?\n";
    std::cin >> userNodes;
    std::cin.ignore();
    for (int i = 0; i < userNodes; i++){
        string input;
        cout << "Enter word:\n";
        std::getline(std::cin, input);
        testList.insertNode(Node(input));
    }
    testList.outputList();

    string deletedNode;
    cout << "What node would you like to delete?\n";
    std::getline(std::cin, deletedNode);
    testList.deleteNode(Node(deletedNode));
    testList.outputList();

    return 0;
}