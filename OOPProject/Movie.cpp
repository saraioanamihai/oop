#include <iostream>
using namespace std;

class Movie {
private:

	string movieTitle;
	int noRows;
	char* rows;
	int noSeats;
	int* seats;

public:

	Movie() {
		movieTitle = "";
		noRows = 0;
		rows = nullptr;
		noSeats = 0;
		seats = nullptr;
	}

	Movie(string movieTitle, int noRows, char* rows, int noSeats, int* seats) {
		this->movieTitle = movieTitle;
		if (noRows > 0 && rows != nullptr) {
			this->rows = new char [noRows];
			for (int i = 0; i < noRows; i++) {
				this->rows[i] = rows[i];
			}
			this->noRows = noRows;
		}
		else {
			this->rows = nullptr;
			this->noRows = 0;
		}
		if (noSeats > 0 && seats != nullptr) {
			this->seats = new int[noSeats];
			for (int i = 0; i < noSeats; i++) {
				this->seats[i] = seats[i];
			}
			this->noSeats = noSeats;
		}
		else {
			this->seats = nullptr;
			this->noSeats = 0;
		}
	}

	~Movie() {
		if (rows != nullptr) {
			delete[] rows;
		}
		if (seats != nullptr) {
			delete[] seats;
		}
	}

};