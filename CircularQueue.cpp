#include <iostream>
#include <variant>
#include <deque>
#include <optional>
#include <memory>
#include <functional>

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
        deque<string> queue;

    public:
        CircularQueue(const int& userCapacity) : headPointer(0), rearPointer(0), currentSize(0), capacity(userCapacity) {
            queue.resize(capacity);
        }
        void enqueue(const string& element){
            if (isFull()){
                cout << "Queue is full\n";
                return;
            }
            queue[rearPointer] = element;
            rearPointer = (rearPointer + 1) % capacity;
            currentSize ++;

        }
        optional<string> dequeue(){
            if (isEmpty()){
                cout << "Queue is empty\n";
                return nullopt;
            }
            auto copiedElement = queue[headPointer];
            headPointer = (headPointer + 1) % capacity;
            currentSize--;

            return copiedElement;

        }
        string getFront()const {
            if (currentSize == 0){
                return "Queue is empty";
            }
            return queue[headPointer];
        }
        string getRear()const {
            if (currentSize == 0){
                return "Queue is empty";
            }
            return queue[((rearPointer -1 + capacity) % capacity)];
        }
        bool isFull(){
            if (currentSize == capacity){
                return true;
            }
            return false;
        }
        bool isEmpty(){
            if (currentSize == 0){
                return true;
            }
            return false;
        }
        void getQueue()const {
            for (int i = 0; i < currentSize; i++){
                int index = (headPointer + i) % capacity;
                cout << queue[index] << "\n";

            };
        }

};

int main(){
    int capacity;
    cout << "Enter circular queue capacity:\n";
    std::cin >> capacity;
    std::cin.ignore();

    unique_ptr<CircularQueue> testQueue = std::make_unique<CircularQueue>(capacity);
    for (int i = 0; i < capacity; i++){
        string item;
        cout << "Enter item to enqueue: \n";
        std::getline(std::cin, item);
        testQueue->enqueue(item);
        
    }
    testQueue->getQueue();


    return 0;
}