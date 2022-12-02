#include <iostream>
using namespace std;

class TheaterTicket {

private: 

	string playName;
	enum categories { Category1, Category2, Box } category;
	char row;
	int seat;

public:

	TheaterTicket() {
		playName = "";
		category = Category1;
		row = NULL;
		seat = 0;
	}

	TheaterTicket(string play, categories category, char row, int seat) {
		this->playName = play;
		this->category = category;
		this->row = row;
		this->seat = seat;
	}

	TheaterTicket(const TheaterTicket& t) {
		this->playName = t.playName;
		this->category = t.category;
		this->row = t.row;
		this->seat = seat;
	}

	~TheaterTicket() {

	}

	string getPlayName() {
		return playName;
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

	void setPlay(string play) {
		this->playName = play;
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