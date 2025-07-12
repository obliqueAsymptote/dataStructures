#include <iostream>
#include <memory>
#include <variant>
#include <list>
#include <stdexcept>

using std::unique_ptr,
std::string,
std::variant,
std::cout;

class Stack{
    private:
        std::list<variant<string, int>> stack;
        const int stackSize;
        int nextSpace;
        
    public:
        Stack(const int& size) : stackSize(size), nextSpace(1) {}

        bool push(variant<string, int> element){
            if (this->stack.size() >= stackSize){
                cout << "Attempting to push onto a full stack";
                return false;
            }
            stack.push_back(element);
            nextSpace += 1;
            if (nextSpace >= stackSize){
                cout << "Stack is now full";
                return true;
            }
            cout << "Next available space at position " << nextSpace;
            return true;

        }
};