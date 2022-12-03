#include <iostream>
using namespace std;

class Ticket {
private:

	const int id;
	string event;
	// static string category;
	char row;
	int seat;
	// price

public:

	// default constructor
	Ticket() : id(rand()) {
		event = "";
		row = NULL;
		seat = 0;
	}

	// constructor with parameters
	Ticket(string event, char row, int seat) : id(rand()) {
		this->event = event;
		this->row = row;
		this->seat = seat;
	}

	// copy constructor
	Ticket(const Ticket& t) : id(t.id) {
		this->event = t.event;
		this->row = t.row;
		this->seat = t.seat;
	}

	// destructor
	~Ticket() {
	}

	// getters
	string getEvent() {
		return event;
	}

	char getRow() {
		return row;
	}

	int getSeat() {
		return seat;
	}

	// setters
	void setEvent(string movie) {
		this->event = event;
	}

	void setRow(char row) {
		this->row = row;
	}

	void setSeat(int seat) {
		this->seat = seat;
	}

	friend ostream& operator<<(ostream& out, Ticket t);
	friend istream& operator>>(istream& in, Ticket& t);
};

// we overload the << operator to print details about a movie
ostream& operator<<(ostream& out, Ticket t) {
	out << "Event: " << t.event << endl;
	out << "Row: " << t.row << endl;
	out << "Seat: " << t.seat << endl;
	return out;
}

// we overload the >> operator to read details about a movie
istream& operator>>(istream& in, Ticket& t) {
	cout << "Event: ";
	char buffer[100];
	in >> buffer;
	t.setEvent(buffer);
	cout << "Row: ";
	in >> t.row;
	cout << "Seat: ";
	in >> t.seat;
	return in;
}