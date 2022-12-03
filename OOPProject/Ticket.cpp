#include <iostream>
using namespace std;

class Ticket {
private:

	const int id;
	string event;
	static string category;
	char row;
	int seat;

public:

	Ticket() : id(rand()) {
		event = "";
		row = NULL;
		seat = 0;
	}

	Ticket(string event, char row, int seat) : id(rand()) {
		this->event = event;
		this->row = row;
		this->seat = seat;
	}

	Ticket(const Ticket& t) : id(t.id) {
		this->event = t.event;
		this->row = t.row;
		this->seat = t.seat;
	}

	~Ticket() {
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

	void setEvent(string movie) {
		this->event = event;
	}

	void setRow(char row) {
		this->row = row;
	}

	void setSeat(int seat) {
		this->seat = seat;
	}
};