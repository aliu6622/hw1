#include "split.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv){
Node *e = new Node(5, nullptr);
Node *d = new Node(4, e);
Node *c = new Node(3, d);
Node *b = new Node(2, c);
Node *a = new Node(1, b);
Node* in = a;

Node* odds = nullptr;
Node* evens = nullptr;
split(in, odds, evens);
cout << "odds: ";
for (Node *p = odds; p != nullptr; p = p->next){ 
cout << p->value << endl;
}
cout << "evens: ";
for (Node *q = evens; q != nullptr; q = q->next){ 
cout << q->value << endl;
}
cout << "in: ";
for (Node *g = in; g != nullptr; g = g->next){ 
cout << g->value << endl;
}
cout << "done.";

delete e;
delete d;
delete c;
delete b;
delete a;
}