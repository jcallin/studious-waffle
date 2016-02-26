#include "list.h"

typedef int T;

using namespace std;

List::List() {
	cursor = NULL;
	N = 0;
}

List::List(const List &other) {
	*this = other;
}

List::~List() {
	if (cursor == NULL)
		return;
	else {
		while (cursor != NULL)
			remove_current();
	}
	return;
}

List& List::operator=(const List& other) {
	if (this == &other)
		return *this;
	while (size() != 0)
		remove_current();
	if (other.size() == 0)
		return *this;
	Node* temp = other.cursor;
	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL){
		attach(temp->data);
		temp = temp->next;
	}
	return *this;
}

void List::start() {
	while (cursor->prev != NULL) {
		cursor = cursor->prev;
	}
	return;
}

void List::end() {
	while (cursor->next != NULL) {
		advance();
	}
	return;
}

void List::advance() {
	if (cursor->next == NULL)
		return;
	else {
		cursor = cursor->next;
	}
	return;
}

void List::insert(T value) {
	Node* newnode = new Node(value);
	cursor->prev->next = newnode;
	newnode->prev = cursor->prev;
	cursor->prev = newnode;
	newnode->next = cursor;
	N++;
	return;
}

void List::attach(T value) {
	Node* newnode = new Node(value);
	cursor->next->prev = newnode;
	newnode->next = cursor->next;
	cursor->next = newnode;
	newnode->prev = cursor;
	N++;
	return;
}

void List::remove_current() {
	if (cursor->prev == NULL) {
		cursor = cursor->next;
		delete cursor->prev;
		cursor->prev = NULL;
		N--;
		return;
	}
	if (cursor->next == NULL) {
		cursor = cursor->prev;
		delete cursor->next;
		cursor->next = NULL;
		N--;
		return;
	}
	else {
		cursor->prev->next = cursor->next;
		cursor->next->prev = cursor->prev;
		Node* temp = cursor;
		cursor = cursor->next;
		delete temp;
		N--;
		return;
	}
}

int List::size() const {
	return N;
}

T List::current() const {
	return cursor->data;
}

ostream& operator<<(ostream &out, const List &other) {
	List::Node* temp = other.cursor;
	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL)
		cout << temp->data << endl;
	return out;
}