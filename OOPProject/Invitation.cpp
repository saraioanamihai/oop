#include <iostream>
#include "Ticket.cpp"
using namespace std; 
// basically a free ticket
class Invitation : public Ticket {
	float price = 0;
};