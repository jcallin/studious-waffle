/*
   Julian Callin
   1012798
   Chapter 5 Project 2: Deleting repetitions from a linked list
*/

#include<stdlib.h>
using namespace std;

void llist::delete_all_dups(llist& lista){
    //Create a second linked list to examine duplicates
    //assume that llist class is fully functional
    llist* checkList = new llist;
    node* ccursor = checkList.head();
    node* cursor = llist.head();

    while(cursor != NULL){
            while(ccursor != NULL)
                    if(is_empty())
                            return;
                    if(checkList.is_empty()){
                            checkList.insert(cursor->data);
                            continue;
                    }
                    else{
                            if(cursor->data == ccursor->data)
                                    cursor->remove();
                    }
                    ccursor = ccursor->next;
            }
            cursor = cursor->next;
    }
    return;
}

int main(){
        return 0;
}
