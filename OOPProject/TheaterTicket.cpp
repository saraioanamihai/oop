#include <iostream>
using namespace std;

class TheaterTicket {

private: 

	string playName;
	char row;
	int seat;

public:

	TheaterTicket() {
		playName = "";
		row = NULL;
		seat = 0;
	}

	TheaterTicket(string play, char row, int seat) {
		this->playName = play;
		this->row = row;
		this->seat = seat;
	}

};