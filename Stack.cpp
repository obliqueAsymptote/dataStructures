#include <iostream>
#include <memory>
#include <variant>
#include <vector>

using std::unique_ptr,
std::string,
std::variant,
std::cout;

class Stack{
    private:
        std::vector<variant<string, int>> stack;
        const int stackSize;
        int nextSpace;
        
    public:
        Stack(const int& size) : stackSize(size), nextSpace(0) {
            stack.reserve(size);
        }

        void push(variant<string, int> element){

        }
};