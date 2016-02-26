#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
/*Julian Callin
  1012708
  Chapter 6 Project 5: multiset of chores
*/

using namespace std;

int main(){
        multiset<string> chores;
        int option;

        //Build initial list of chores from file
        ifstream inFile("chores.txt");
        if(!inFile){
                cout << "File not found" << endl;
                return -1;
        }
        for(string line; getline(inFile, line); )
                chores.insert(line);
        inFile.close();

        while(1){
                cout << "(0) Add a chore\n(1) Print all chores\n(2) Delete a chore\n(3) Exit" << endl;
                cin >> option;
                cin.ignore();
                if(option == 0){
                        string chorename;
                        cout << "Which chore would you like to add?" << endl;
                        getline(cin, chorename);
                        chores.insert(chorename);
                }
                else if (option == 1){
                        cout << "Chores: " << endl;
                        for(multiset<string>::iterator it = chores.begin(); it != chores.end(); it ++)
                                cout << *it << endl;
                        cout << "---------------------" << endl;
                }

                else if (option == 2){
                        cout << "Enter a chore to remove" << endl;
                        if(chores.size() == 0){
                                cout << "No chores in the list to remove" << endl;
                        }
                        else {
                                int i = 0;
                                multiset<string>::iterator it;
                                for(it = chores.begin(); it != chores.end(); it ++, i++){
                                        cout << i << " : ";
                                        cout << *it << endl;
                                }

                                int toremove;
                                cin >> toremove;
                                cin.ignore();
                                //Validate user input
                                if(toremove > chores.size() || toremove < 0)
                                        cout << "This chore does not exist" << endl;
                                else{
                                        it = chores.begin();
                                        for(int k = 0; k < toremove; k++){
                                                it++;
                                        }
                                        chores.erase(it);
                                }
                        }
                }

                else
                        break;
        }
        ofstream toDo("chores.txt");
        for(multiset<string>::iterator it = chores.begin(); it != chores.end(); it++){
                toDo << *it << endl;
        }
        toDo.close();
        return 0;
}
