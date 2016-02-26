/*
Name:Julian Callin
SUID:W1012798
Chapter 6 project 3: Implementing a set template class
 */
#include <iostream>

using namespace std;

//Set for storing primitive c++ objects
template<class object>
class set{
        static const int capacity = 50;
        int current;
        object data[capacity];
        public:

        set(){
                current = -1;
        }

        set(set& source){
                current = source.current;
                for(int i = 0; i < size(); i++)
                        data[i] = source.data[i];
        }

        //Checks if an item is already in a set
        bool contains(const object& target) const{
                for(int i=0; i<size(); i++){
                        if (data[i]==target)
                                return true;
                }
                return false;
        }

        //Inserts an item into a set
        bool insert(const object& y){
                if(size() >= capacity || contains(y))
                        return false;
                data[++current] = y;
                return true;
        }

        //Erases a number in a set if it is found
        bool erase_item(const object target){
                if(current < 0)
                        return false;
                int target_index = 0;
                while(target_index <= current){
                        if(data[target_index] == target){
                                data[target_index] = data[current--];
                                return true;
                        }
                        else
                                target_index++;
                }
                return false;
        }

        //Accessor Functions
        //Outputs the contents of the set
        void dump(){
                cout << "Set contents: " << endl;
                for(int i = 0; i < size(); i++)
                        cout << data[i] << endl;
                cout << "--------------" <<endl;
                return;
        }


        int size() const{
                return current+1;
        }


        //Overloads (-) for subtraction of sets
        set& operator-(const set& b){
                int a_index;
                int b_index;
                int match;
                for(b_index = 0; b_index < b.size(); b_index++)
                {
                        for(a_index = 0; a_index < this->size(); a_index++)
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

        void operator=(const set& b){
                current = b.current;
                for(int i = 0; i < b.size(); i++){
                        data[i] = b.data[i];
                }
        }

        void operator-=(const set& b){
                *this = *this - b;
        }
};

int main(){
        set<int> set1;
        set<int> set2;
        set<char> set3;
        set<char> set4;
        set<char> set5;

        set1.insert(1);
        set1.insert(2);
        set1.insert(3);

        set2.insert(3);

        set1 -= set2;
        cout << "set 1 (-) set 2 result:" << endl;
        set1.dump();

        set3.insert('a');
        set3.insert('b');
        set3.insert('c');
        set4.insert('a');
        set5 = set3 - set4;
        cout << "set 5 = set 3 (-) set 4" <<endl;
        set5.dump();

        return 0;
}
