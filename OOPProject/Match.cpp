#include <iostream>
using namespace std;

class Match {
private:

	string teams; // ex. Germany vs Poland
	int noRows;
	char* row;
	int noSeats;
	int* seat;

public:

	// default constructor
	Match() {
		teams = "";
		noRows = 0;
		row = nullptr;
		noSeats = 0;
		seat = nullptr;
	}

	// constructor with parameters
	Match(string teams, int noRows, char* row, int noSeats, int* seat) {
		this->teams = teams;
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
	~Match() {
		if (row != nullptr) {
			delete[] row;
		}
		if (seat != nullptr) {
			delete[] seat;
		}
	}

	// copy constructor
	Match(const Match& m) {
		this->teams = m.teams;
		if (m.noRows > 0 && m.row != nullptr) {
			this->row = new char[m.noRows];
			for (int i = 0; i < m.noRows; i++) {
				this->row[i] = m.row[i];
			}
			this->noRows = m.noRows;
		}
		else {
			this->row = nullptr;
			this->noRows = 0;
		}
		if (m.noSeats > 0 && m.seat != nullptr) {
			this->seat = new int[m.noSeats];
			for (int i = 0; i < m.noSeats; i++) {
				this->seat[i] = m.seat[i];
			}
			this->noSeats = m.noSeats;
		}
		else {
			this->seat = nullptr;
			this->noSeats = 0;
		}
	}

	// getters
	string getTeams() {
		return teams;
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
	void setTeams(string teams) {
		if (teams.size() > 0) {
			this->teams = teams;
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

	// overloading the index [] operator
	char& operator[](int index) {
		if (index >= 0 && row != nullptr && index < noRows) {
			return row[index];
		}
	}
	friend ostream& operator<<(ostream& out, Match m);
	friend istream& operator>>(istream& in, Match& m);

	// overloading the > operator to compare the number of available seats for 2 matches
	bool operator>(Match m) {
		if ((noSeats * noRows) > (m.noSeats * m.noRows)) {
			return true;
		}
		else return false;
	}
};