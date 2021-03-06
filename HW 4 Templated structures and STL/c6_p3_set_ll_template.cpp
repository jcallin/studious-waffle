/*
        Name:Julian Callin
        SUID:W1012798
        Chapter 5 project 12: Linked List set template
 */
#include <iostream>

using namespace std;

template<class item>
struct node{
        item data;
        node* next;
};

template<class item>
class set{
        node<item> header;
        node<item>* cursor;

        public:
        set(){
                cursor = &header;
                header.next = NULL;

        }
        set(set& source){
               cursor = &header;
               header.next = NULL;
               *this = source;
        }

        ~set(){
                if(header.next == NULL)
                        return;
                else{
                        cursor = header.next;
                        node<item>* temp = cursor;
                        while(cursor != NULL){
                                cursor = cursor->next;
                                delete temp;
                                temp = cursor;
                        }
                }
                return;
        }

        void advance(){
                if(is_empty())
                        return;
                if(cursor->next != NULL)
                        cursor = cursor->next;
                return;
        }

        void start(){
                if(is_empty())
                        return;
                cursor = header.next;
                return;
        }

        void end(){
                if(is_empty())
                        return;
                start();
                while(cursor->next != NULL)
                        cursor = cursor->next;
                return;
        }



        bool insert(const item y){
                if(checkDup(y))
                        return false;
                node<item>* newnode = new node<item>;
                newnode->data = y;
                newnode->next = header.next;
                header.next = newnode;
                cursor = newnode;
                return true;
        }

        bool checkDup(item y){
                if(is_empty())
                        return false;
                node<item>* tcursor = header.next;
                while(tcursor != NULL){
                        if(tcursor->data == y)
                                return true;
                        tcursor = tcursor->next;
                }
                return false;
        }

        //Erases a number in a set if it is found and sets cursor to the next
        //node
        bool remove(const item target){
                node<item>* tcursor = header.next;
                node<item>* prev = &header;
                while(tcursor != NULL){
                        if(tcursor->data == target){
                                prev->next = tcursor->next;
                                delete tcursor;
                                return true;
                        }
                        prev = tcursor;
                        tcursor = tcursor->next;
                }
                return false;
        }

        int current(){
                return cursor->data;
        }

        bool is_empty(){
                if(header.next == NULL)
                        return true;
                else{
                        return false;
                }
        }

        void dump(){
                cout << "Set contents: " << endl;
                node<item>* tcursor = header.next;
                while(tcursor != NULL){
                        cout << tcursor->data << endl;
                        tcursor = tcursor->next;
                }
                cout << "--------------" <<endl;
                return;
        }

        void clear(){
                if(is_empty())
                        return;
                cursor = header.next;
                while(cursor != NULL){
                        remove(current());
                        cursor = cursor->next;
                }
                return;
        }

        void operator-=(set& b){
                *this = *this - b;
        }

        set& operator-(set& b){
                if(b.is_empty() || is_empty())
                        return *this;
                node<item>* a_cursor = header.next;
                node<item>* b_cursor = b.header.next;
                item match;
                while(b_cursor != NULL){
                        while(a_cursor != NULL){
                                if(a_cursor->data == b_cursor->data)
                                {
                                        match = b_cursor->data;
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

        set& operator=(set& b){
                if(this == &b)
                        return *this;
                if(b.is_empty())
                        return *this;

                b.cursor = b.header.next;

                //Clear the LL
                this->clear();

                //Insert all of b into the list
                while(b.cursor != NULL){
                        insert(b.current());
                        b.cursor = b.cursor->next;
                }
                return *this;
        }
};

int main(){
        set<int> set1;
        set<int> set2;
        set<int> set3;
        set<char> set4;
        set<char> set6;

        set1.insert(2);
        set1.insert(4);
        set1.insert(8);
        set1.insert(3);
        set1.insert(8);
        set1.insert(5);
        set1.insert(69);

        set2.insert(8);
        set2.insert(8);
        set2.insert(8);
        set2.insert(5);
        set2.remove(8);

        cout << "set1:" << endl;
        set1.dump();
        cout << "set2:" << endl;
        set2.dump();
        cout << endl;

        set3 = set2;
        cout << "set3:" << endl;
        set3.dump();

        set4.insert('a');
        set4.insert('b');
        set4.insert('c');
        set6.insert('b');
        set6.insert('a');
        cout << "set 4:" << endl;
        set4.dump();
        cout << "set 6:" << endl;
        set6.dump();

        cout << "testing -" <<endl;
        set4 = set4 - set6;
        cout << "set 4 = set 4 (-) set 6" <<endl;
        cout << "set 4" << endl;
        set4.dump();

        cout << "testing copy cstor set5(set4)" << endl;
        set<char> set5(set4);
        cout << "set5" << endl;
        set5.dump();

        return 0;
}
