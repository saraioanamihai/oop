#include <iostream>
using namespace std;

class Movie {
private:

	string movieTitle;
	int noRows;
	char* row; // dynamically allocated vector of charachters
	int noSeats; 
	int* seat = {0}; // dynamically allocated numeric vector

public:

	// default constructor
	Movie() {
		movieTitle = "";
		noRows = 0;
		row = nullptr;
		noSeats = 0;
		seat = nullptr;
	}

	// constructor with parameters
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

	// destructor
	~Movie() {
		if (row != nullptr) {
			delete[] row;
		}
		if (seat != nullptr) {
			delete[] seat;
		}
	}

	
	// copy constructor
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

	// getters
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

	// setters
	void setMovieTitle(string movieTitle) {
		if (movieTitle.size() > 0) {
			this->movieTitle = movieTitle;
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


	// overloading the + operator
	Movie operator+(Movie m) {
		Movie copy = *this;
		copy.movieTitle = this->movieTitle + m.movieTitle;
		return copy;
	}

	// oveloading the - operator
	Movie operator-(Movie m) {
		Movie copy = *this;
		if (this->noSeats > m.noSeats) {
			copy.noSeats = copy.noSeats - m.noSeats;
		}
	}

/*	bool checkAvailability(char row, int seat) {
		int ok = 0;
		for (int i = 0; i < this->noRows; i++) {
			if (this->row[i] == row) ok++;
		}
		for()
	}

*/

	friend ostream& operator<<(ostream& out, Movie m);
	friend istream& operator>>(istream& in, Movie& m);
};
