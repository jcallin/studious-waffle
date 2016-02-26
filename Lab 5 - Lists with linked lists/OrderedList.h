#include "list.h"
#pragma once
typedef int T;
using namespace std;

class OrderedList : public List{
	OrderedList();
	OrderedList(OrderedList& other);
	~OrderedList();

	OrderedList& operator=(const OrderedList& other);

	friend ostream& operator<<(ostream& out, OrderedList& other);

	void insert(T data);
	void attach(T data);
};
