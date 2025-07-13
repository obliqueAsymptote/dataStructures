#include <iostream>
#include <variant>
#include <deque>
#include <optional>
#include <memory>

using
std::variant,
std::cout,
std::string,
std::deque,
std::optional,
std::nullopt,
std::unique_ptr;

class CircularQueue{
    private:
        int headPointer;
        int rearPointer;
        int currentSize;
        int capacity;
        deque<variant<string, int>> queue;

    public:
        CircularQueue(const int& userCapacity) : headPointer(0), rearPointer(0), capacity(userCapacity) {
            queue.resize(capacity);
        }
        void enqueue(const variant<string, int>& element){
            if ((rearPointer + 1) % capacity == headPointer){
                cout << "Queue is full\n";
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
        variant<string, int> getFront()const {
            return queue[headPointer];
        }
        variant<string, int> getRear()const {
            return queue[rearPointer];
        }
        bool isFull(){
            return currentSize == currentSize;
        }
        bool isEmpty(){
            return currentSize == 0;
        }
        deque<variant<string, int>> getQueue(){
            return queue;
        }

};

int main(){
    int capacity;
    cout << "Enter circular queue capacity:\n";
    std::cin >> capacity;

    unique_ptr<CircularQueue> testQueue = std::make_unique<CircularQueue>(capacity);
    testQueue->enqueue(15);
    testQueue->enqueue(24);
    testQueue->enqueue(2);
    cout << "Queue is full: " << testQueue->isFull() << "\n";
    cout << "Front: ";
    testQueue->getFront();
    cout << "\n";
    cout << "Rear: ";
    testQueue->getRear();
    cout << "\n";
    cout << "Full current queue: ";
    testQueue->getQueue();


    return 0;
}