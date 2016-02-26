/*Lab 3: Postfix Calculator in C++
  Julian Callin 1012798
  Stephen Chuang 1049541
  1/19/2015
 */

#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class stack{
        int top;
        int capacity;
        static const int MAXSIZE = 5;
        double* stk;

        public:
        stack();
        ~stack();
        void push(double);
        double pop();
        double gettop();
        bool empty();
        bool full();
};

stack::stack(){
        top = -1;
        stk = new double[MAXSIZE];
        capacity = MAXSIZE;
}

stack::~stack(){
        delete[]stk;
}

void stack::push(double y){
        if((top-1) == capacity){
                double* temp = new double[2*capacity];
                for(int i=0; i<=top; i++)
                        temp[i] = stk[i];
                capacity *= 2;
                delete[]stk;
                stk = temp;
        }
        stk[++top] = y;
}

bool stack::empty(){
        return (top== -1);
}

double  stack::pop(){
        if(empty())
                return 0;
        else
                return stk[top--];
}



bool stack::full(){
        return (top==MAXSIZE-1);
}

double stack::gettop(){
        return stk[top];
}

int main(){

        double op1, op2;
        double result;
        stack postfix;

        string expr, token;
        getline(cin,expr);
        istringstream stream(expr);
        while(stream>>token){
                if( (token == "+") || (token  == "-") || (token == "*") ||
                                (token == "/")) {
                        op1 = postfix.pop();
                        op2 = postfix.pop();
                        if(token == "+")
                                postfix.push(op1 + op2);
                        if(token == "-")
                                postfix.push(op2 - op1);
                        if(token == "*")
                                postfix.push(op1 * op2);
                        if(token == "/")
                                postfix.push(op2 / op1);
                }
                else{
                        postfix.push(atof(token.c_str()));
                }
        }
        cout << postfix.gettop() << endl;
        return 0;
}
