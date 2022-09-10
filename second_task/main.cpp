
#include <iostream>
#include "MultithreadQueue.h"

int MAX_SIZE = 10;

void PrintQueue(MultithreadedQueue<int>);

int main()
{
    MultithreadedQueue<int> MyQueue;

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        MyQueue.push(i);
    }
    PrintQueue(MyQueue);
    MyQueue.pop();
    std::cout << std::endl;
    PrintQueue(MyQueue);
}

void PrintQueue(MultithreadedQueue<int> q) 
{
    int size = MAX_SIZE;
    while (!q.empty())
    {
        std::cout << q.data_queue.front() << " ";
        q.pop();
    }
}
