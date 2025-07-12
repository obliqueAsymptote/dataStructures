#include <iostream>
#include <memory>
#include <variant>
#include <list>
#include <stdexcept>
#include <optional>

using std::unique_ptr,
std::string,
std::variant,
std::cout,
std::cin,
std::optional;

class Stack{
    private:
        std::list<variant<string, int>> stack;
        const int stackSize;
        int nextSpace;
        
    public:
        Stack(const int& size) : stackSize(size), nextSpace(1) {}

        bool push(variant<string, int> element){
            if (this->stack.size() >= stackSize){
                cout << "Attempting to push onto a full stack\n";
                return false;
            }
            stack.push_back(element);
            nextSpace += 1;
            if (nextSpace > stackSize){
                cout << "Stack is now full\n";
                return true;
            }
            cout << "Next available space at position " << nextSpace << "\n";
            return true;

        }
        optional<variant<string, int>> pop(){
            nextSpace -= 1;
            if (nextSpace <= 0){
                cout << "Stack is already empty\n attempting to pop nonexistant item\n";
                return std::nullopt;
            }
            variant<string, int> poppedItem = stack.back();
            stack.pop_back();
            return poppedItem;
        }
};

int main(){
    int stackSize;
    cout << "Declare stack size:\n";
    cin >> stackSize;
    Stack testStack(stackSize);
    for (int i = 0; i < stackSize; i++){
        int stackItem;
        cout << "Enter item to push: \n";
        cin >> stackItem;
        testStack.push(stackItem);
    }
    return 0;
}