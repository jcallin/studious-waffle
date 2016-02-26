/*
   Julian Callin
   1012798
   Chapter 3 project 3: Implementing a sequence
*/

#include <iostream>
#include <assert.h>

using namespace std;

static const int MAXSIZE = 50;

class sequence{
        int used = 0;
        int current_index = used;
        int data[MAXSIZE];

        public:

        //Cursor functions
        void start(){
                if(used == 0)
                        return;
                current_index = 0;
                return;
        }

        void advance(){
                if(used == 0)
                        return;
                if(current_index == used-1)
                        return;
                current_index++;
                return;
        }

        void last(){
                current_index = --used;
        }

        //Mutator functions
        void shift_right(){
                int dest = used;
                int src = dest-1;
                while(dest != current_index)
                        data[dest--] = data[src--];
                return;
        }

        void shift_left(){
                int dest = current_index;
                int src = dest+1;
                while(src != used)
                        data[dest++] = data[src++];
                return;
        }
        void insert(const int& entry){
                assert(size() < MAXSIZE);
                if(is_item() == false){
                        data[used++] = entry;
                        return;
                }

                shift_right();
                data[current_index] = entry;
                used++;
                return;
        }

        void attach(const int& entry){
                assert (size() < MAXSIZE);
                if(is_item() == false){
                        data[used++] = entry;
                        return;
                }
                current_index++;
                shift_right();
                data[current_index] = entry;
                used++;
                return;
        }

        void remove_current(){
                assert (is_item());
                shift_left();
                used--;
                return;
        }

        int remove_rear(){
                int temp = used-1;
                used--;
                return(data[temp]);
        }

        bool add_front(int y){
                if(size() < MAXSIZE)
                        return false;
                current_index = 0;
                shift_right();
                data[current_index] = y;
                used++;
                return true;
        }

        bool add_rear(int y){
                if(size() > MAXSIZE)
                        return false;
                data[used] = y;
                current_index = used;
                used++;
                return true;
        }

        //Accessors
        int current(){
                return data[current_index];
        }

        void dump(){
                cout << "Sequence is now: " << endl;
                if(used == 0){
                        cout << "empty" << endl;
                        return;
                }
                for(int i = 0; i < used; i++)
                        cout << data[i] << endl <<endl;
                cout << "-----------------" << endl;
                return;
        }

        //Constant member functions
        int size() const{
                return used;
        }

        bool is_item(){
                if(current_index==used)
                        return false;
                return true;
        }

        //Overloaded operators
        sequence operator+(sequence& source){
                assert ((this->size() + source.size()) <= 50);
                sequence result;
                int shibby;
                int sizeb = source.size();
                int sizea = this->size();
                for(int i = 0; i < sizeb; i++){
                        shibby = source.remove_rear();
                        result.insert(shibby);
                }
                for(int i = 0; i < sizea; i++){
                        shibby = this->remove_rear();
                        result.insert(shibby);
                }
                return result;
        }

        //Couldn't get this one to work, sequence always appears empty once it
        //is += to another sequence
        void operator+=(sequence& source){
                assert ((this->size() + source.size()) <= 50);
                std::copy(source.data, source.data + used, data + used);
                used += source.used;
        }
};

int main(){
        sequence a;
        for(int i = 0; i < 50; i++)
                a.insert(i);
        a.dump();
        for(int k = 0; k < 50; k++)
                a.remove_current();
        a.dump();

        a.insert(1);
        a.insert(2);
        a.insert(3);
        a.attach(4);
        a.insert(5);
        a.dump();

        sequence b;
        b.insert(6);
        b.insert(7);
        b.insert(8);
        b.dump();

        sequence c;
        c = a + b;
        c.dump();

        a += b;
        a.dump();

        return 1;
}
