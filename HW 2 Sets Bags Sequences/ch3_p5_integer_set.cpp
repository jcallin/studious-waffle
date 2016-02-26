/*
Name:Julian Callin
SUID:W1012798
Chapter 3 project 5: Implementing a set
 */
#include <iostream>

using namespace std;

//Set for storing integers
class set{
        static const int capacity = 50;
        int current;
        int data[capacity];
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
        bool contains(const int& target) const{
                for(int i=0; i<size(); i++){
                        if (data[i]==target)
                                return true;
                }
                return false;
        }

        //Inserts an item into a set
        bool insert(int y){
                if(size() >= capacity || contains(y))
                        return false;
                data[++current] = y;
                return true;
        }

        //Erases a number in a set if it is found
        bool erase_item(const int target){
                if(current < 0)
                        return false;
                int target_index = 0;
                while((target_index < size()) && (data[target_index] != target))
                        target_index++;
                if (target_index == current)
                        return false;
                data[target_index] = data[current];
                current--;
                return true;
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

        //Overloads (-=) for subtraction of sets
        void operator-=(const set& b){
                *this = *this - b;
        }
};

int main(){
        set set1;
        set set2;
        set set3;

        set1.insert(2);
        set1.insert(4);
        set1.insert(8);
        set1.insert(3);
        set1.insert(8);
        set1.insert(69);

        set2.insert(8);
        set2.insert(8);
        set2.insert(8);
        set2.insert(5);

        set1.dump();
        set2.dump();
        cout << endl;

        set1 -= set2;
        cout << "set 1 (-) set 2 result:" << endl;
        set1.dump();

        set3 = set1 - set2;
        cout << "set 3 = set 1 (-) set 2" <<endl;
        set3.dump();

        set3.insert(5);
        set3.insert(5);
        set3.dump();

        return 0;
}
