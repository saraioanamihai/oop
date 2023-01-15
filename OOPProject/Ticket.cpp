#include <iostream>
#include "Taxable.cpp"

using namespace std;

class Ticket : public Taxable {
private:

	const int id;
	string event;
	enum categories {Stand1, Stand2, Normal, VIP, Category1, Category2, BOX} category;
	char row;
	int seat;
	float price;
	static string ticketCompany;

public:

	// default constructor
	Ticket() : id(rand()) {
		event = "";
		row = NULL;
		seat = 0;
		price = 0.00;
	}

	// constructor with parameters
	Ticket(string event, categories category, char row, int seat, float price) : id(rand()) {
		this->event = event;
		this->category = category;
		this->row = row;
		this->seat = seat;
		this->price = price;
	}

	// copy constructor
	Ticket(const Ticket& t) : id(t.id) {
		this->event = t.event;
		this->category = t.category;
		this->row = t.row;
		this->seat = t.seat;
		this->price = t.price;
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

	categories getCategory() {
		return category;
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

	float getPrice() {
		return price;
	}

	// setters
	void setEvent(string event) {
		if (event.size() > 0) {
			this->event = event;
		}
	}
	void setCategory(categories category) {
		this->category = category;
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

	void setPrice(float price) {
		if (price != NULL) {
			this->price = price;
		}
	}

	// overloading the == operator
	bool operator==(Ticket t) {
		if (this->event == t.event && this->row == t.row && this->seat == t.seat && this->price == price) {
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
			this->price = t.price;
		}
		return *this;
	}

	static bool checkTicketCompany() {
		if (ticketCompany == "Sara's Ticket Company") return true;
		else return false;
	}

	// overriding pure virtual method
	float computePriceAfterTax() {
		return price * 0.9;
	}

	friend ostream& operator<<(ostream& out, Ticket t);
	friend istream& operator>>(istream& in, Ticket& t);
	friend int main();
};