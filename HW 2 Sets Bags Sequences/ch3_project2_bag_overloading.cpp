/*
        Name:Julian Callin
        SUID:W1012798
        Chapter 3 project 2
*/
#include <iostream>

using namespace std;

//Bag for storing integers
class bag{
        static const int capacity = 50;
        int current = -1;
        int data[capacity];
        public:
                //Inserts an item into a bag
                bool insert(int y){
                        if(size() >= capacity)
                                return false;

                        data[++current] = y;
                        return true;
                }

                //Outputs all contents of a bag
                void dump(){
                        for(int i = 0; i <= current; i++)
                                cout << data[i] << endl;
                }

                //Returns the number of items in a bag
                int size(){
                        return current+1;
                }

                //Erases a number in a bag if it is found
                bool erase_item(const int target){
                       if(current < 0)
                               return false;
                       int target_index;
                       target_index = 0;
                       while((target_index < current) && (data[target_index] != target))
                               target_index++;
                       if (target_index == current)
                               return false;
                       data[target_index] = data[current];
                       current--;
                       return true;
                }

                //Overloads (-) for subtraction of bags
                bag operator-(const bag& b){
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
                void operator-=(const bag& b){
                       *this = *this - b;
                }
};

int main(){
        bag bag1;
        bag bag2;
        bag bag3;

        bag1.insert(2);
        bag1.insert(4);
        bag1.insert(8);
        bag1.insert(3);
        bag1.insert(8);

        bag2.insert(8);
        bag2.insert(8);
        bag2.insert(8);
        bag2.insert(5);

        cout<< "Bag 1 contents:" << endl;
        bag1.dump();
        cout<< "Bag 2 contents:" << endl;
        bag2.dump();
        cout << endl;

        bag1 -= bag2;
        cout << "Bag 1 (-) Bag 2 result:" << endl;
        bag1.dump();

        bag3 = bag1 - bag2;
        cout << "Bag 3 = Bag 1 (-) Bag 2" <<endl;
        bag3.dump();

        return 0;
}
