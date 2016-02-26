/*
        Name:Julian Callin
        SUID:W1012798
        Chapter 5 project 17: Keyed bag with circularly linked list
*/
#include <iostream>

using namespace std;
struct node{
        int key;
        int data;
        node* next;
};

//Keyed bag for storing integers
class keyed_bag{
        node head;
        node* cursor;

        public:

        keyed_bag(){
                cursor = &head;
                head.next = &head;
        }

        keyed_bag(keyed_bag& source){
                cursor = &head;
                head.next = &head;
                *this = source;
        }


        ~keyed_bag(){
                start();
                if(!is_empty()){
                        while(cursor != &head){
                                remove();
                        }
                }
        }

        void start(){
                cursor = head.next;
                return;
        }

        int current_data(){
                return cursor->data;
        }

        int current_key(){
                return cursor->key;
        }

        bool contains_data(const int& target){
                node* tcursor = head.next;
                while(tcursor != &head){
                        if(tcursor->data == target)
                                return true;
                        else
                                tcursor = tcursor->next;
                }
                return false;
        }

        bool contains_key(const int& target){
                node* tcursor = head.next;
                while(tcursor != &head){
                        if(tcursor->key == target)
                                return true;
                        tcursor = tcursor->next;
                }
                return false;
        }

        bool insert(int y, int key){
                if(contains_key(key))
                        return false;
                node* tcursor = head.next;
                node* newnode = new node;
                newnode->key = key;
                newnode->data = y;
                newnode->next = tcursor->next;
                tcursor->next = newnode;
                cursor = newnode;
                return true;
       }
        bool is_empty(){
                if(head.next == &head)
                        return true;
                else
                        return false;
        }

        //Erases a number in a bag if it is found
        bool erase_item(const int key){
                if(is_empty())
                        return false;
                node* tcursor = head.next;
                node* temp = &head;
                while(tcursor!= &head){
                        if(tcursor->key == key){
                                temp->next = tcursor->next;
                                temp = tcursor;
                                cursor = tcursor->next;
                                delete temp;
                                return true;
                        }
                        temp = tcursor;
                        tcursor = tcursor->next;
                }
                return false;
        }

        //Remove the item that the cursor is on and moves the cursor to the next
        //item
        void remove(){
                node* prev;
                node* flag = cursor;
                while(cursor->next != flag){
                        cursor = cursor->next;
                }
                prev = cursor;
                cursor = cursor->next;
                prev->next = cursor->next;
                cursor = cursor->next;
                delete flag;
                return;
        }

        void dump(){
                cursor = head.next;
                cout << "bag contents: " << endl;
                while(cursor != &head){
                        cout << cursor->data << " : " << cursor->key << endl;
                        cursor = cursor->next;
                }
                cout << "--------------" << endl;
                return;
        }

        void clear(){
                if(is_empty())
                        return;
                start();
                while(cursor != &head)
                        remove();
                return;
        }


        keyed_bag& operator=(const keyed_bag& b){
                if(this == &b)
                        return *this;
                clear();
                start();

                node* tcursor = b.head.next;
                while(tcursor != &b.head){
                        insert(tcursor->data, tcursor->key);
                        tcursor = tcursor->next;
                }
                return *this;
        }

        keyed_bag& operator-(const keyed_bag& b){
                node* a_cursor = head.next;
                node* b_cursor = b.head.next;
                int match;
                while(b_cursor != &b.head)
                {
                        while(a_cursor != &head)
                        {
                                if(a_cursor->key == b_cursor->key)
                                {
                                        match = b_cursor->key;
                                        erase_item(match);
                                        break;
                                }
                                a_cursor = a_cursor->next;
                        }
                        a_cursor = head.next;
                        b_cursor = b_cursor->next;
                }
                return *this;
        }

        keyed_bag& operator-=(const keyed_bag& b){
                *this = *this - b;
                return *this;
       }
};

int main(){
        keyed_bag bag1;
        keyed_bag bag2;
        bag1.insert(1, 10);
        bag1.insert(2, 11);
        bag1.insert(3, 12);
        bag1.insert(4, 13);
        bag1.insert(5, 14);
        bag1.dump();

        bag1.erase_item(10);
        bag1.dump();
        bag1.erase_item(11);
        bag1.dump();
        bag1.erase_item(12);
        bag1.dump();

        cout << "testing copy cstor" << endl;
        keyed_bag bag3(bag1);
        bag3.dump();

        bag2.insert(20,30);
        bag2.insert(21,31);
        bag2.insert(22,32);
        bag2.insert(500,13);
        bag2.dump();

        cout << "testing -= operator" << endl;
        bag2 -= bag1;
        bag2.dump();

        cout << "testing bag2 - bag1" << endl;
        keyed_bag bag4 = bag2 - bag1;
        bag4.dump();

        return 0;
}
