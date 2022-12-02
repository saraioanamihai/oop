#include <iostream>
using namespace std;

class MovieTicket {
private:
	string movieName;
	enum categories {VIP, Normal} category;
	char row;
	int seat;

public:

	MovieTicket() {
		movieName = "";
		category = Normal;
		row = NULL;
		seat = 0;
	}

	MovieTicket(string movie, categories category, char row, int seat) {
		this->movieName = movie;
		this->category = category;
		this->row = row;
		this->seat = seat;
	}

	MovieTicket(const MovieTicket& m) {
		this->movieName = m.movieName;
		this->category = m.category;
		this->row = m.row;
		this->seat = m.seat;
	}

	~MovieTicket() {
	}

	string getMovieName() {
		return movieName;
	}

	categories getCategory() {
		return category;
	}

	char getRow() {
		return row;
	}

	int getSeat() {
		return seat;
	}

	void setMovieName(string movie) {
		this->movieName = movie;
	}

	void setCategory(categories category) {
		this->category = category;
	}

	void setRow(char row) {
		this->row = row;
	}

	void setSeat(int seat) {
		this->seat = seat;
	}
};