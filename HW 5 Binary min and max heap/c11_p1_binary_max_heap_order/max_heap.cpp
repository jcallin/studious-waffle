#include "heap.h"

/*
   Julian Callin 1012798
   C11 P1 Max heap with order
   File: heap.cpp
   Implementation for a max priority heap with entry ordering
*/

using namespace std;

void Pheap::push(int i){
        if (size() == CAPACITY)
                return;
        data[_size] = i;
        order[_size++] = _order_count++;
        siftup(used());
}

void Pheap::siftup(int child_index){
        if (child_index == 0)
                return;

        int parent_index = getPI(child_index);

        int child_data = data[child_index];
        int parent_data = data[parent_index];
        int temp_data;

        int parent_order = order[parent_index];
        int child_order = order[child_index];
        int temp_order;

        if ((child_data > parent_data) || ((child_data == parent_data) &&
                                (child_order < parent_order))){
                //Swap parent/child data
                temp_data = child_data;
                data[child_index] = parent_data;
                data[parent_index] = temp_data;
                //Swap order array for parent/child
                temp_order = child_order;
                order[child_index] = parent_order;
                order[parent_index] = temp_order;
                //Continue to sift up
                siftup(parent_index);
        }
}

void Pheap::siftdown(int parent_index){
        if (haschild(parent_index) == false)
                return;
        int left_child_index = getLCI(parent_index);
        int right_child_index = getRCI(parent_index);

        int parent_data = data[parent_index];
        int left_child_data = data[left_child_index];
        int right_child_data = data[right_child_index];

        int parent_order = order[parent_index];
        int left_child_order = order[left_child_index];
        int right_child_order = order[right_child_index];

        int temp_data;
        int temp_order;

        if (left_child_data > right_child_data || ((left_child_data == right_child_data) && (left_child_order < right_child_order))){
                //Swap parent data with left child data
                temp_data = parent_data;
                data[parent_index] = left_child_data;
                data[left_child_index] = temp_data;
                //Swap parent order with left child order
                temp_order = parent_order;
                order[parent_index] = left_child_order;
                order[left_child_index] = temp_order;
                siftdown(left_child_index);
        }
        else if (right_child_data > left_child_data ||
                        ((right_child_data == left_child_data) &&
                         (right_child_order < left_child_order))){
                //Swap parent data with right child data
                temp_data = parent_data;
                data[parent_index] = right_child_data;
                data[right_child_index] = temp_data;
                //Swap parent order with right child order
                temp_order = parent_order;
                order[parent_index] = right_child_order;
                order[right_child_index] = temp_order;
                siftdown(right_child_index);
        }
}

bool Pheap::haschild(int node_index){
        if (getLCI(node_index) > used() && getRCI(node_index) > used())
                return false;
        else
                return true;
}

void Pheap::pop(){
        if (size() == 0)
                return;
        //Replace root with bottom most right leaf
        data[0] = data[used()];
        order[0] = order[used()];
        _size--;
        siftdown(0);
}

int Pheap::top(){
        return data[0];
}

void Pheap::dump(){
        int thesize = size();
        for (int i = 0; i < thesize; i++){
                cout << top() << endl;
                pop();
        }
}