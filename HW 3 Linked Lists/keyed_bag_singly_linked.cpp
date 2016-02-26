/*
        Name:Julian Callin
        SUID:W1012798
        Chapter 5 project 12: Keyed bag with linked list
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
        node header;
        node* cursor;

        public:

        keyed_bag(){
                cursor = &header;
                header.next = NULL;
        }

        keyed_bag(keyed_bag& source){
                cursor = &header;
                header.next = NULL;
                *this = source;
        }

        ~keyed_bag(){
                clear();
        }

        void start(){
                cursor = header.next;
                return;
        }

        void end(){
                start();
                while(cursor->next != NULL)
                        cursor = cursor->next;
                return;
        }

        void advance(){
                if(cursor->next == NULL)
                        return;
                else
                        cursor = cursor->next;
                return;
        }

        bool contains_data(const int& target){
                while(cursor!= NULL){
                        if(cursor->data == target)
                                return true;
                        cursor = cursor->next;
                }
                return false;
        }

        bool contains_key(const int& target){
                start();
                while(cursor != NULL){
                        if(cursor->key == target)
                                return true;
                        cursor = cursor->next;
                }
                return false;
        }

        bool insert(int y, int key){
                if(contains_key(key))
                        return false;
                node* newnode = new node;
                newnode->key = key;
                newnode->data = y;
                newnode->next = header.next;
                header.next = newnode;
                return true;
       }

        bool remove(const int key){
                if(header.next == NULL)
                        return false;
                start();
                node* temp = &header;
                while(cursor!= NULL){
                        if(cursor->key == key){
                                temp->next = cursor->next;
                                delete cursor;
                                start();
                                return true;
                        }
                        temp = cursor;
                        cursor = cursor->next;
                }
                return false;
        }

        void clear(){
                start();
                while(header.next != NULL){
                        header.next = cursor->next;
                        delete cursor;
                        cursor = header.next;
                }
                return;
        }

        //Accessor Functions
        //Outputs the contents of the bag
        void dump(){
                cursor = header.next;
                cout << "bag contents: " << endl;
                while(cursor != NULL){
                        cout << cursor->data << " : " << cursor->key << endl;
                        cursor = cursor->next;
                }
                cout << "--------------" <<endl;
                return;
        }

        int current_key(){
                return cursor->key;
        }

        int current_data(){
                return cursor->data;
        }

        keyed_bag& operator-(const keyed_bag& b){
                node* a_cursor = header.next;
                node* b_cursor = b.header.next;
                int match;
                while(b_cursor != NULL){
                        while(a_cursor != NULL){
                                if(a_cursor->key == b_cursor->key)
                                {
                                        match = b_cursor->key;
                                        remove(match);
                                        break;
                                }
                                a_cursor = a_cursor->next;
                        }
                        a_cursor = header.next;
                        b_cursor = b_cursor->next;
                }
                return *this;
        }

        keyed_bag& operator-=(const keyed_bag& b){
                *this = *this - b;
                return *this;
        }

        void operator=(keyed_bag& b){
                if(this == &b)
                        return;

                clear();
                start();
                b.start();

                while(b.cursor != NULL){
                        insert(b.current_data(), b.current_key());
                        b.cursor = b.cursor->next;
                }
                return;
        }
};

int main(){
        keyed_bag bag1;
        keyed_bag bag2;
        keyed_bag bag3;
        keyed_bag bag4;

        bag1.insert(1, 10);
        bag1.insert(2, 11);
        bag1.insert(3, 12);
        bag1.insert(4, 13);
        bag1.insert(5, 14);
        bag1.dump();

        bag1.remove(10);
        bag1.dump();
        bag1.remove(11);
        bag1.dump();
        bag1.remove(12);
        bag1.dump();

        cout << "testing assignment operator" << endl;
        bag3 = bag1;
        bag3.dump();

        bag2.insert(4, 13);
        bag2.insert(99,100);
        bag2.insert(100, 90);

        cout << "testing bag -= bag" << endl;
        bag2 -= bag1;
        bag2.dump();

        bag4.insert(99, 100);
        bag4.insert(100, 90);


        cout << "testing bag - bag" << endl;
        bag2 = bag2 - bag4;
        bag2.dump();

        cout << "testing copy cstor" << endl;
        keyed_bag bag5(bag4);
        bag5.dump();

        return 0;
}
