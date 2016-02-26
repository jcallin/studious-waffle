#include "OrderedList.h"
#pragma once

using namespace std;

OrderedList::OrderedList(){}
OrderedList::OrderedList(OrderedList& other){}
OrderedList::~OrderedList(){}

OrderedList& operator=(const OrderedList& other){}

void OrderedList::insert(T y){
	Node* temp = cursor;
	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp->data < y)
		temp = temp->next;
	Node newnode = new Node(y);
	temp->prev->next = newnode;
	newnode->prev = temp->prev;
	temp->prev = newnode;
	newnode->next = temp;
	N++;
	return;
}

void OrderedList::attach(T y){
	insert(y);
}

ostream& operator<<(ostream& out, OrderedList& other){
	out << static_cast<const list&>(other) << endl;
	return out;
}