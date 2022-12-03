#include <iostream>
using namespace std;

class Movie {
private:

	string movieTitle;
	int noRows;
	char* row;
	int noSeats;
	int* seat;

public:

	Movie() {
		movieTitle = "";
		noRows = 0;
		row = nullptr;
		noSeats = 0;
		seat = nullptr;
	}

	Movie(string movieTitle, int noRows, char* row, int noSeats, int* seat) {
		this->movieTitle = movieTitle;
		if (noRows > 0 && row != nullptr) {
			this->row = new char [noRows];
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

	~Movie() {
		if (row != nullptr) {
			delete[] row;
		}
		if (seat != nullptr) {
			delete[] seat;
		}
	}

	Movie(const Movie& m) {
		this->movieTitle = m.movieTitle;
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

	string getMovieTitle() {
		return movieTitle;
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

	void setMovieTitle(string movieTitle) {
		this->movieTitle = movieTitle;
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