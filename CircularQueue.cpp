#include <iostream>
#include <variant>
#include <deque>
#include <optional>

using
std::variant,
std::cout,
std::string,
std::deque,
std::optional,
std::nullopt;

class CircularQueue{
    private:
        int headPointer;
        int rearPointer;
        int currentSize;
        int capacity;
        deque<variant<string, int>> queue;

    public:
        CircularQueue(const int& userCapacity) : headPointer(0), rearPointer(0), capacity(userCapacity) {}
        void enqueue(const variant<string, int>& element){
            if ((rearPointer + 1) % capacity == headPointer){
                cout << "Queue is full\n"; //why the hell did i put stack earlier
                return;
            }
            rearPointer = (rearPointer + 1) % capacity;
            queue[rearPointer] = element;
            currentSize ++;

        }
        optional<variant<string, int>> dequeue(){
            if (rearPointer == headPointer){
                cout << "Queue is empty\n";
                return nullopt;
            }
            headPointer = (headPointer + 1) % capacity;
            auto copiedElement = queue[headPointer];
            currentSize--;

            return copiedElement;

        }

};