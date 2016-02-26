/*
	Julian Callin 1012798
	C11 P1 Max heap with order
	File: main.cpp
	Tests the implementation of heap.cpp
*/
#include "heap.h"

using namespace std;

int main(){
        Pheap heap1;
        heap1.push(20);
        heap1.push(19);
        heap1.push(3);
        heap1.push(2);
        heap1.push(8);
        heap1.push(6);
        heap1.push(10);
        heap1.push(15);
        heap1.push(11);
        heap1.push(2);
        heap1.push(3);
        heap1.dump();
        return 0;
}