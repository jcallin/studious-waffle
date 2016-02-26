#include <iostream>
#pragma once

typedef int T;

using namespace std;

class List {
public:
	List();
	List(const List &other);
	~List();

	List& operator=(const List &other);

	void start();	//Move cursor to start of list 
	void end();	//Move cursor to end of list
	void advance();	//Move cursor forward one element unless
					//it is already at the end of the list

	void insert(T value);	//Insert before cursor
	void attach(T value);	//Insert after cursor

							//Remove the element at the cursor. The cursor will then move 
							//to the next element unless you removed the last element, in 
							//which case the cursor will point to the new last element
	void remove_current();

	int size() const;	//Return the number of elements in the list
	T current() const;	//Return the element pointed to by the cursor

	friend ostream& operator<<(ostream &out, const List &other);
protected:
	struct Node {
		Node *prev, *next;
		T data;
		Node(T data, Node *prev = NULL, Node *next = NULL) {
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};
	Node *cursor; //Points to the list, is NULL if the list is empty
	int N;	//The number of elements in the list
};
