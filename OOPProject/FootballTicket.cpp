#include <iostream>
using namespace std;

class FootballTicket {
private:

	string game; // ex. "Germany vs. Poland
	char row;
	int seat;

public:

	FootballTicket() {
		game = "";
		row = NULL;
		seat = 0;
	}

	FootballTicket(string game, char row, int seat) {
		this->game = game;
		this->row = row;
		this->seat = seat;
	}

	FootballTicket(const FootballTicket& f) {
		this->game = f.game;
		this->row = f.row;
		this->seat = f.seat;
	}

	~FootballTicket() {

	}

	string getGame() {
		return game;
	}

	char getRow() {
		return row;
	}

	int getSeat() {
		return seat;
	}

	void setGame(string game) {
		this->game = game;
	}

	void setRow(char row) {
		this->row = row;
	}

	void setSeat(int seat) {
		this->seat = seat;
	}
};