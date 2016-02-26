/*
   Julian Callin 1012798
   C11 P5 Min priority heap
   File: heap.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Pheap{
        private:
                static const int CAPACITY = 100;
                int _size = 0;
                int data[CAPACITY] = {int()};
        public:
                //Gets left child's array index
                int getLCI(int i){ return ((2 * i) + 1); }
                //Gets right child's array index
                int getRCI(int i){ return ((2 * i) + 2); }
                //Gets parent's array index
                int getPI(int i){ return (i - 1) / 2; }
                //Number of items in heap
                int size(){ return _size; }
                //Index of last item in heap
                int used(){ return _size - 1; }
                //Adds an item to the heap
                void push(int i);
                //Removes the root node (largest)
                void pop();
                //Percolates a node up to preserve max property
                void siftup(int child_index);
                //Percolates a node down to preserve max
                //property
                void siftdown(int parent_index);
                bool haschild(int node_index);
                //Returns the smallest(root node) of the
                //heap
                int top();
                //Erases the heap and prints in
                //order
                void dump();
};