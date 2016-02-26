/*
Name:Julian Callin
SUID:W1012798
Chapter 3 project 8: Keyed bag (with dynamic array source from ch 4 proj 2)
*/
#include <iostream>

using namespace std;

//Keyed bag for storing integers
class keyed_bag{
        static const int MAXSIZE = 2;
        int capacity;
        int current;
        int* data;
        int* keys;
        public:

        keyed_bag(){
                capacity = MAXSIZE;
                data = new int[capacity];
                keys = new int[capacity];
                current = -1;
        }
        //Checks if an item is already in a bag
        bool contains(const int& target) const{
                for(int i=0; i<capacity; i++){
                        if (data[i]==target)
                                return true;
                }
                return false;
        }

        //Checks if a key is in use
        bool contains_key(int& key){
                for(int i=0; i<current+1; i++){
                        if(keys[i]==key)
                                return true;
                }
                return false;
        }

        //Inserts an item into a bag
        bool insert(int y, int key){
                if(size() >= capacity){
                        int* temp_data = new int[2*capacity];
                        int* temp_keys = new int[2*capacity];
                        for(int i=0; i <= current; i++){
                                temp_data[i] = data[i];
                                temp_keys[i] = keys[i];
                        }
                        capacity *= 2;
                        delete[] data;
                        delete [] keys;
                        data = temp_data;
                        keys = temp_keys;
                }
                if(contains_key(key))
                        return false;
                current++;
                data[current] = y;
                keys[current] = key;
                return true;
        }

        //Erases a number in a bag if it is found
        bool erase_item(const int key){
                if(current < 0)
                        return false;
                if(current == 0){
                        current = -1;
                        return true;
                }
                int target_index = 0;
                while(target_index < current){
                        if(key == keys[target_index]){
                                data[target_index] = data[current];
                                keys[target_index] = keys[current];
                                current--;
                                return true;
                        }
                        target_index++;
                }
                if(target_index == current){
                        if(keys[target_index] == key){
                                current--;
                                return true;
                        }
                }
                return false;
        }

        //Accessor Functions
        //Outputs the contents of the bag
        void dump(){
                cout << "bag contents: " << endl;
                for(int i = 0; i <= current; i++){
                        cout << data[i] << " : " << keys[i] << endl;
                }
                cout << "--------------" <<endl;
                return;
        }


        int size(){
                return current+1;
        }


        //Overloads (-) for subtraction of bags
        keyed_bag& operator-(const keyed_bag& b){
                int a_index;
                int b_index;
                int match;
                for(b_index = 0; b_index < b.current; b_index++)
                {
                        for(a_index = 0; a_index < this->current; a_index++)
                        {
                                if(this->data[a_index] == b.data[b_index])
                                {
                                        match = b.data[b_index];
                                        this->erase_item(match);
                                        break;
                                }
                        }
                }
                return *this;
        }

        //Overloads (-=) for subtraction of bags
        keyed_bag& operator-=(const keyed_bag& b){
                int a_index;
                int b_index;
                int match;
                for(b_index = 0; b_index < b.current; b_index++)
                {
                        for(a_index = 0; a_index < this->current; a_index++)
                        {
                                if(this->data[a_index] == b.data[b_index])
                                {
                                        match = b.data[b_index];
                                        this->erase_item(match);
                                        break;
                                }
                        }
                }
                return *this;
        }
};

int main(){
        keyed_bag bag1;

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

        return 0;
}
