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

	// default constructor
	Play() {
		playTitle = "";
		noRows = 0;
		row = nullptr;
		noSeats = 0;
		seat = nullptr;
	}

	// constructor with parameters
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

	// destructor
	~Play() {
		if (row != nullptr) {
			delete[] row;
		}
		if (seat != nullptr) {
			delete[] seat;
		}
	}

	// copy constructor
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

	// getters
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

	// setters
	void setPlayTitle(string playTitle) {
		if (playTitle.size() > 0) {
			this->playTitle = playTitle;
		}
	}

	void setNoRows(int noRows) {
		if (noRows > 0) {
			this->noRows = noRows;
		}
	}

	void setRow(char* row) {
		if (row != nullptr) {
			this->row = row;
		}
	}

	void setNoSeats(int noSeats) {
		if (noSeats > 0) {
			this->noSeats = noSeats;
		}
	}

	void setSeat(int* seat) {
		if (seat != nullptr) {
			this->seat = seat;
		}
	}

	friend ostream& operator<<(ostream& out, Play p);
	friend istream& operator>>(istream& in, Play& p);
};

// we overload the << operator to print details about a play
ostream& operator<<(ostream& out, Play p) {
	out << "Title of the play: " << p.playTitle << endl;
	out << "Number of rows: " << p.noRows << endl;
	out << "Number of seats: " << p.noSeats << endl;
	return out;
}

// we overload the >> operator to read details about a movie
istream& operator>>(istream& in, Play& p) {
	cout << "Title of the play: ";
	char buffer[100];
	in >> buffer;
	p.setPlayTitle(buffer);
	cout << "Number of rows: ";
	in >> p.noRows;
	cout << "Number of seats: ";
	in >> p.noSeats;
	return in;
}