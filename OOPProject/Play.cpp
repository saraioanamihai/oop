#include <iostream>
using namespace std;

class Play {
private:

	string playTitle;
	int noRows;
	char* row;
	int noSeats;
	int* seat;

public:

	Play() {
		playTitle = "";
		noRows = 0;
		row = nullptr;
		noSeats = 0;
		seat = nullptr;
	}

	Play(string playTitle, int noRows, char* row, int noSeats, int* seat) {
		this->playTitle = playTitle;
		if (noRows > 0 && row != nullptr) {
			this->row = new char[noRows];
			for (int i = 0; i < noRows; i++) {
				this->row[i] = row[i];
			}
			this->noRows = noRows;
		}
		else {
			this->row = nullptr;
			this->noRows = 0;
		}
		if (noSeats > 0 && seat != nullptr) {
			this->seat = new int[noSeats];
			for (int i = 0; i < noSeats; i++) {
				this->seat[i] = seat[i];
			}
			this->noSeats = noSeats;
		}
		else {
			this->seat = nullptr;
			this->noSeats = 0;
		}
	}

	~Play() {
		if (row != nullptr) {
			delete[] row;
		}
		if (seat != nullptr) {
			delete[] seat;
		}
	}

	Play(const Play& p) {
		this->playTitle = p.playTitle;
		if (p.noRows > 0 && p.row != nullptr) {
			this->row = new char[p.noRows];
			for (int i = 0; i < p.noRows; i++) {
				this->row[i] = p.row[i];
			}
			this->noRows = p.noRows;
		}
		else {
			this->row = nullptr;
			this->noRows = 0;
		}
		if (p.noSeats > 0 && p.seat != nullptr) {
			this->seat = new int[p.noSeats];
			for (int i = 0; i < p.noSeats; i++) {
				this->seat[i] = p.seat[i];
			}
			this->noSeats = p.noSeats;
		}
		else {
			this->seat = nullptr;
			this->noSeats = 0;
		}
	}

	string getPlayTitle() {
		return playTitle;
	}

	int getNoRows() {
		return noRows;
	}

	char* getRow() {
		return row;
	}

	int getNoSeats() {
		return noSeats;
	}

	int* getSeat() {
		return seat;
	}

	void setPlayTitle(string playTitle) {
		this->playTitle = playTitle;
	}

	void setNoRows(int noRows) {
		this->noRows = noRows;
	}

	void setRow(char* row) {
		this->row = row;
	}

	void setNoSeats(int noSeats) {
		this->noSeats = noSeats;
	}

	void setSeat(int* seat) {
		this->seat = seat;
	}
};