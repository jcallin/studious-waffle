/*
   Julian Callin
   1012798
   Chapter 4 project 1: Extending the mystring class
 */

#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

class mystring{
        //I am using a basic version of the mystring class wihout many
        //overloaded operators
        char* characters;
        int allocated;
        int current_length;
        public:

        //Char array constructor
        mystring(const char str[ ] = "");
        //Copy constructor
        mystring(const mystring& source);
        //Single char constructor
        mystring(const char a);
        //Defaults
        mystring();
        ~mystring();

        //Manages memory allocation
        void reserve(int n);

        //Inserts a string at a given position in another string
        bool insert(mystring &a, int at);

        //Replace a single char in a string at a location
        bool replace(char a, int at);

        void info();

        char operator[](int index) const{
                assert(index < current_length);
                return characters[index];
        }
        //Friends
        friend bool operator==(const mystring& s1, const mystring& s2);
        friend ostream &operator<<(ostream &output, const mystring &s);
};

//Const and dest
mystring::mystring(const char str[]){
        current_length = strlen(str);
        allocated = current_length + 1;
        characters = new char[allocated];
        strcpy(characters, str);
}

mystring::mystring(const mystring& source){
        current_length = strlen(source.characters);
        allocated = source.current_length + 1;
        characters = new char[source.allocated];
        strcpy(characters, source.characters);
}

mystring::mystring(const char a){
        current_length = 1;
        allocated = 2;
        characters = new char[allocated];
        characters[0] = a;
}

mystring::~mystring(){
        delete[] characters;
}

//Reserves n additional characters in a string
void mystring::reserve(int n){
        int newlen =  n + current_length;
        allocated = newlen + 1;
        char* temp = new char[allocated];
        strcpy(temp, characters);
        current_length = newlen;
        delete[] characters;
        characters = temp;
        return;
}

//Mutators
bool mystring::insert(mystring& b, int at){
        reserve(b.current_length);
        int i;
        int newalloc = b.current_length + current_length;
        char* temp = new char[newalloc];
        //Copy the first part of the string into the new string
        for(i = 0; i < at; i++){
                temp[i] = characters[i];
        }
        //Copy the insert string into the new string
        for(int k = 0; k < b.current_length; i++, k++){
                temp[i] = b.characters[k];
        }
        //Copy the second part of the string into the new string
        for(int j = at; j < current_length; i++, j++){
                temp[i] = characters[i];
        }
        delete[]characters;
        characters = temp;
        return true;
}

bool mystring::replace(char b, int loc){
        characters[loc] = b;
        return true;
}

//Accessors
void mystring::info(){
        cout << "Allocated: " << allocated << endl;
        cout << "Length: " << current_length << endl;
        return;
}

//Operators
bool operator==(const mystring& s1, const mystring&s2){
        return (strcmp(s1.characters, s2.characters) == 0);
}

ostream &operator<<(ostream &output, const mystring &s){
        output << s.characters;
        return output;
}

int main(){
        //Test default constructor, string cstor, and ccstor
        mystring s0("");
        mystring s1 = "Beef jerky";
        mystring s2(s1);
        cout << s1 << endl;
        cout << s2 << endl << endl;

        //Test the char constructor
        mystring s3("a");
        cout << s3 << endl << endl;;


        //Test the reserve function
        mystring s4("one");
        s4.reserve(4);
        s4.info();
        cout << s4 << endl << endl;

        //Test insertion
        s1.insert(s4, 0);
        cout << s1 << endl << endl;

        //Test replace
        mystring s5("fifa");
        s5.replace('z',2);
        cout << s5 << endl << endl;

        return 0;
}
