/*
   Julian Callin 1012798
   Maxen Chung 1072369
   Kelly Wesley 1092292
   Lab 4: Priority Queue using a linked list
   File: queue.h
*/

struct Node{
        Node* next;
        int data;
};

class Queue{
        Node* head;

        public:
        void Enqueue(int n);
        bool isEmpty();
        int Dequeue();
        void dump();
        Queue();
        Queue(Queue& source);
        ~Queue();
        void operator=(const Queue& source);
};