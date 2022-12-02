#include <iostream>
using namespace std;

class FootballTicket {
private:

	string game; // ex. "Germany vs. Poland
	enum stands { Stand1, Stand2 } stand;
	char row;
	int seat;

public:

	FootballTicket() {
		game = "";
		stand = Stand1;
		row = NULL;
		seat = 0;
	}

	FootballTicket(string game, stands stand, char row, int seat) {
		this->game = game;
		this->stand = stand;
		this->row = row;
		this->seat = seat;
	}

	FootballTicket(const FootballTicket& f) {
		this->game = f.game;
		this->stand = f.stand;
		this->row = f.row;
		this->seat = f.seat;
	}

	~FootballTicket() {

	}

	string getGame() {
		return game;
	}

	stands getStand() {
		return stand;
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

	void setStand(stands stand) {
		this->stand = stand;
	}

	void setRow(char row) {
		this->row = row;
	}

	void setSeat(int seat) {
		this->seat = seat;
	}
};