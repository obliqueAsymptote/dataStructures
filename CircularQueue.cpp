#include <iostream>
#include <variant>
#include <vector>

using
std::variant,
std::cout,
std::string,
std::vector;

class CircularQueue{
    private:
        int headPointer;
        int rearPointer;
        int currentSize;
        int capacity;
        vector<variant<string, int>> queue;

    public:
        CircularQueue(const int& userCapacity) : headPointer(-1), rearPointer(-1), capacity(userCapacity) {
            queue.resize(capacity);
        }
        void enqueue(const variant<string, int>& element){
            if ((rearPointer + 1) % capacity == headPointer){
                cout << "Stack is full";
                return;
            }
            rearPointer = (rearPointer + 1) % capacity;
            queue[rearPointer] = element;
            currentSize ++;

        }

};