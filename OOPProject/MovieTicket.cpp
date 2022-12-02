#include <iostream>
using namespace std;

class MovieTicket {
private:
	string movieName;
	char row;
	int seat;

public:

	MovieTicket() {
		movieName = "";
		row = NULL;
		seat = 0;
	}

	MovieTicket(string movie, char row, int seat) {
		this->movieName = movie;
		this->row = row;
		this->seat = seat;
	}

};