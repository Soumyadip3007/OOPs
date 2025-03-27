#include<bits/stdc++.h>
using namespace std;

class CircularBuffer
{
    int *buffer;
    int head;
    int tail;
    int capacity;
    int current_size;  // Track current number of elements

public:
    CircularBuffer(int size)
    {
        capacity = size;
        buffer = new int[capacity];
        head = 0;
        tail = 0;
        current_size = 0;
    }

    ~CircularBuffer()
    {
        delete[] buffer;
    }

    void enqueue(int data)
    {
        if(current_size == capacity)
        {
            cout << "Buffer is Full" << endl;
            return;
        }
        buffer[tail] = data;
        tail = (tail + 1) % capacity;
        current_size++;
    }

    void dequeue()
    {
        if(current_size == 0)
        {
            cout << "Buffer is Empty" << endl;
            return;
        }
        head = (head + 1) % capacity;
        current_size--;
    }

    void display()
    {
        if(current_size == 0)
        {
            cout << "Buffer is Empty" << endl;
            return;
        }
        int count = 0;
        int i = head;
        while(count < current_size)
        {
            cout << buffer[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        cout << endl;
    }
};

int main()
{
    CircularBuffer cb(5);
    cb.enqueue(1);
    cb.enqueue(2);
    cb.enqueue(3);
    cb.enqueue(4);
    cb.enqueue(5);
    cb.display();  // Should print: 1 2 3 4 5
    cb.enqueue(6);  // Should print: Buffer is Full
    cb.display();  // Should still print: 1 2 3 4 5
    cb.dequeue();  // Remove first element
    cb.display();  // Should print: 2 3 4 5
    cb.dequeue();  // Remove second element
    cb.display();  // Should print: 3 4 5
}