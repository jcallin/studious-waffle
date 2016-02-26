#include "heap.h"

/*
   Julian Callin 1012798
   C11 P1
   Implementation for a min priority heap 
   File: heap.h
 */

using namespace std;

void Pheap::push(int i){
        if (size() == CAPACITY)
                return;
        data[_size++] = i;
        siftup(used());
        return;
}

void Pheap::siftup(int child_index){
        if (child_index == 0)
                return;

        int parent_index = getPI(child_index);

        int child_data = data[child_index];
        int parent_data = data[parent_index];
        int temp_data;

        if (child_data < parent_data){
                //Swap parent/child data
                temp_data = child_data;
                data[child_index] = parent_data;
                data[parent_index] = temp_data;
                //sift up
                siftup(parent_index);
        }
        return;
}

void Pheap::siftdown(int parent_index){
        if (haschild(parent_index) == false)
                return;

        int left_child_index = getLCI(parent_index);
        int right_child_index = getRCI(parent_index);

        int parent_data = data[parent_index];
        int left_child_data = data[left_child_index];
        int right_child_data = data[right_child_index];

        int temp_data;

        if (left_child_data < right_child_data){
                if(parent_data > left_child_data){
                //Swap parent data with left child data
                temp_data = parent_data;
                data[parent_index] = left_child_data;
                data[left_child_index] = temp_data;
                //sift down
                siftdown(left_child_index);
                }
        }
        else if (parent_data > right_child_data){
                //Swap parent data with right child data
                temp_data = parent_data;
                data[parent_index] = right_child_data;
                data[right_child_index] = temp_data;
                //sift down
                siftdown(right_child_index);
        }
        return;
}

bool Pheap::haschild(int parent_index){
        if (getLCI(parent_index) > used() && getRCI(parent_index) > used())
                return false;
        else
                return true;
}

void Pheap::pop(){
        if (size() == 0)
                return;
        //Replace root with bottom most right leaf
        data[0] = data[used()];
        _size--;
        siftdown(0);
        return;
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
        return;
}