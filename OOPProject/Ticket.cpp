#include <iostream>
using namespace std;

class Ticket {
private:

	const int id;
	string event;
	//category;
	char row;
	int seat;
	// price
	static string ticketCompany;

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
	int getId() {
		return id;
	}

	string getEvent() {
		return event;
	}

	char getRow() {
		return row;
	}

	int getSeat() {
		return seat;
	}

	static string getTicketCompany() {
		return ticketCompany;
	}

	// setters
	void setEvent(string event) {
		if (event.size() > 0) {
			this->event = event;
		}
	}

	void setRow(char row) {
		if (row != NULL) {
			this->row = row;
		}
	}

	void setSeat(int seat) {
		if (seat != NULL) {
			this->seat = seat;
		}
	}

	static void setTicketCompany(string ticketCompany) {
		if (ticketCompany.size() > 0) {
			Ticket::ticketCompany = ticketCompany;
		}
	}

	// overloading the == operator
	bool operator==(Ticket t) {
		if (this->event == t.event && this->row == t.row && this->seat == t.seat) {
			return true;
		}
		else return false;
	}

	// overloading the = operator to copy an existing object into another existing, as opposed to the copy constructor
	Ticket operator = (const Ticket& t) {
		if (this != &t) {	
			this->event = t.event;
			this->row = t.row;
			this->seat = t.seat;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Ticket t);
	friend istream& operator>>(istream& in, Ticket& t);
};

string Ticket::ticketCompany = "Sara's Ticket Company";

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