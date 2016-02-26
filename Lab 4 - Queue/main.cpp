/*
      Julian Callin 1012798
         Maxen Chung 1072369
            Kelly Wesley 1092292
               Lab 4: Priority Queue using a linked list
                  File: main.cpp
*/
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
        Queue a;
        a.Enqueue(6);
        a.Enqueue(10);
        a.Enqueue(1);
        a.Enqueue(68);
        a.Enqueue(3);
        a.Enqueue(6);
        a.Enqueue(2);
        a.Enqueue(300);
        a.Enqueue(2);
        Queue b;
        b = a;

        cout << "Queue B: " <<endl;
        b.dump();

        cout << "Queue A: " <<endl;
        a.dump();
        return 0;

}