/*
Name:Julian Callin
SUID:W1012798
Chapter 3 project 8: Keyed bag with dynamic array of pairs
*/

#include <iostream>
#include <utility>

using namespace std;

//Keyed bag for storing integers
template<class key_t, class value_t>
class keyed_bag{
        static const int MAXSIZE = 2;
        int capacity;
        int current;
        pair<key_t, value_t>* data;
        public:

        keyed_bag(){
                capacity = MAXSIZE;
                data = new pair<key_t,value_t>;
                current = -1;
        }

        //Checks if an item is already in a bag
        bool contains(const value_t target) const{
                for(int i=0; size(); i++){
                        if (data[i].second == target)
                                return true;
                }
                return false;
        }

        //Checks if a key is in use
        bool contains_key(key_t& key){
                for(int i=0; i < size(); i++){
                        if(data[i].first == key)
                                return true;
                }
                return false;
        }

        //Inserts an item into a bag
        bool insert(key_t key, value_t value){
                if(contains_key(key))
                        return false;
                if(size() >= capacity){
                        pair<key_t, value_t>* temp_data = new pair<key_t, value_t>[2*capacity];
                        for(int i=0; i < size(); i++){
                                temp_data[i].first = data[i].first;
                                temp_data[i].second = data[i].second;
                        }
                        capacity *= 2;
                        delete[] data;
                        data = temp_data;
                }
                ++current;
                data[current].first = key;
                data[current].second = value;
                return true;
        }

        //Erases a number in a bag if it is found
        bool erase_item(const key_t key){
                if(current < 0)
                        return false;
                if(current == 0){
                        current = -1;
                        return true;
                }
                int target_index = 0;
                while(target_index <= current){
                        if(key == data[target_index].first){
                                data[target_index].second = data[current].second;
                                data[target_index].first = data[current].first;
                                current--;
                                return true;
                        }
                        target_index++;
                }
                if(target_index == current){
                        if(data[target_index].first == key){
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
                        cout << data[i].first << " : " << data[i].second << endl;
                }
                cout << "--------------" <<endl;
                return;
        }


        int size(){
                return current+1;
        }


        //Overloads (-) for subtraction of bags based on key match
        keyed_bag& operator-(const keyed_bag& b){
                int a_index;
                int b_index;
                key_t match;
                for(b_index = 0; b_index < b.current; b_index++)
                {
                        for(a_index = 0; a_index < this->current; a_index++)
                        {
                                if(this->data[a_index].first ==
                                                b.data[b_index].first)
                                {
                                        match = b.data[b_index].first;
                                        this->erase_item(match);
                                        break;
                                }
                        }
                }
                return *this;
        }

        //Overloads (-=) for subtraction of bags
        keyed_bag& operator-=(const keyed_bag& b){
                *this = *this - b;
                return *this;
        }
};

int main(){
        keyed_bag<int, int> bag1;

        bag1.insert(10, 1);
        bag1.insert(11, 2);
        bag1.insert(12, 3);
        bag1.insert(13, 4);
        bag1.insert(14, 5);
        bag1.dump();

        bag1.erase_item(10);
        bag1.dump();
        bag1.erase_item(11);
        bag1.dump();
        bag1.erase_item(12);
        bag1.dump();

        return 0;
}
