#include <iostream>
using namespace std;

class Client {
private: 
	string name;
	string surname;

public:

	Client() {
		this->name = "";
		this->surname = "";
	}

	Client(string name, string surname) {
		this->name = name;
		this->surname = surname;
	}

	~Client() {

	}

	Client(const Client& c) {
		this->name = c.name;
		this->surname = c.surname;
	}

	string getName() {
		return name;
	}

	string getSurname() {
		return surname;
	}

	void getName(string name) {
		if (name.size() > 0) {
			this->name = name;
		}
	}

	void getSurname(string surname) {
		if (surname.size() > 0) {
			this->surname = surname;
		}
	}
};