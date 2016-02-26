/*
   Julian Callin
   1012798
   Chapter 5 Project 4: Reversing a singly Linked List
*/
using namespace std;

//We assume next() returns a node's next node and next_ptr refers to the node's
//actual pointer
void llist::reverse(node* head){
        node* cursor = head->next();
        node* temp = head;
        node* prev = cursor;

        while(cursor->next() != NULL){
                cursor = cursor->next();
                prev->next_ptr = temp;
                temp = prev;
                prev = cursor;
        }
        cursor->next_ptr = temp;
        head->next_ptr = NULL;
        head = cursor;
        return;
}
