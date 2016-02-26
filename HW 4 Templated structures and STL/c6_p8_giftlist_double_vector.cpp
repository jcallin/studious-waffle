/*Julian Callin
  1012798
  Chapter 6 Project 8: giftlist with vector of string vectors
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Giftlist{
        private:
                vector< vector<string> > names;
                int _size;
        public:
                int size(){
                        return names.size();
                }

                void AddGift(int index){
                        cout << "Enter a gift to add" << endl;
                        string gift = "";
                        getline(cin, gift);
                        names[index].push_back(gift);
                }

                void AddPerson(string name){
                        vector<string> newname;
                        newname.push_back(name);
                        names.push_back(newname);
                }

                void DeleteGift(int index){
                       cout << "Select a gift to delete" << endl;
                       PrintGifts(index);
                       int option;
                       cin >> option;
                       cin.ignore();
                       if(option > names[index].size())
                               return;
                       vector<string>::iterator it = names[index].begin();
                       for(int i = 0; i < option; i++, it++){}
                       names[index].erase(it);
                }

                void DeletePerson(){
                        if(names.size() == 0){
                                cout << "There's no one in your gift list to remove" << endl;
                                return;
                        }
                        cout << "Select a person to remove them and all their gifts... muahahaha" << endl;
                        PrintPeople();
                        int index;
                        cin >> index;
                        cin.ignore();
                        if(index > names.size())
                                return;
                        names[index].clear();
                        vector< vector<string> >::iterator it = names.begin();
                        for(int i = 0; i < index; i++, it++){}
                        names.erase(it);
                }

                void PrintPeople(){
                        for(int i = 0; i < names.size(); i ++)
                                cout << i << " : " << names[i][0] << endl;
                }

                void PrintGifts(int index){
                        for(int i = 1; i < names[index].size(); i++)
                                cout << i << " : " << names[index][i] << endl;
                }

                void PrintAll(){
                        if(names.size() == 0){
                                cout << "There's nothing to print!" << endl;
                                return;
                        }
                        for(int i = 0; i < names.size(); i ++){
                                for(int j = 0; j < names[i].size(); j++)
                                        cout << names[i][j] << endl;
                                cout << endl;
                        }
                        return;
                }
};

int main(){
        Giftlist ourlist;
        while(1){
                cout << "(1) Add Gift\n(2) Add Person\n(3) Check off a Gift\n(4)Remove a person\n(5) Print All\n(6) Exit" << endl;
                int option;
                cin >> option;
                cin.ignore();
                string name = "";
                if(option == 1){
                        if(ourlist.size() == 0){
                                cout << "No one in list yet, enter a name to add" << endl;
                                getline(cin, name);
                                ourlist.AddPerson(name);
                        }
                        cout << "Select a person to add the gift for" << endl;
                        ourlist.PrintPeople();
                        cin >> option;
                        cin.ignore();
                        ourlist.AddGift(option);
                }
                else if(option == 2){
                        cout << "Enter a person to add to the list" << endl;
                        getline(cin, name);
                        ourlist.AddPerson(name);
                }
                else if(option == 3){
                        cout << "Select a person to view their list of gifts" << endl;
                        ourlist.PrintPeople();
                        cin >> option;
                        cin.ignore();
                        ourlist.DeleteGift(option);
                }
                else if(option == 4){
                        ourlist.DeletePerson();
                }
                else if(option == 5){
                        ourlist.PrintAll();
                }
                else
                        break;
        }
        return 0;
}
