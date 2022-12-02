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

	MovieTicket(const MovieTicket& m) {
		this->movieName = m.movieName;
		this->row = m.row;
		this->seat = m.seat;
	}

	~MovieTicket() {
	}

	string getMovieName() {
		return movieName;
	}

	char getRow() {
		return row;
	}

	int getSeat() {
		return seat;
	}


};