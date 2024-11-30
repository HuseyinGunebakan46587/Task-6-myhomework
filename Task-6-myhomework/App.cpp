#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> q; 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Queue front: " << q.peek() << std::endl; 
    std::cout << "Queue size: " << q.size() << std::endl;  

    q.dequeue(); 
    std::cout << "Queue front after dequeue: " << q.peek() << std::endl; 
    std::cout << "Queue size after dequeue: " << q.size() << std::endl;  

    return 0;
}
