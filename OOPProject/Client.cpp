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

	void setName(string name) {
		if (name.size() > 0) {
			this->name = name;
		}
	}

	void setSurname(string surname) {
		if (surname.size() > 0) {
			this->surname = surname;
		}
	}

	friend ostream& operator<<(ostream& out, Client c);
};

// we overload the << operator to print details about a client
ostream& operator<<(ostream& out, Client c) {
	out << "Name: " << c.name << endl;
	out << "Surname: " << c.surname << endl;
	return out;
}

// we overload the >> operator to read details about a client
istream& operator>>(istream& in, Client& c) {
	cout << "Name: ";
	char buffer[100];
	in >> buffer;
	c.setName(buffer);
	cout << "Surname: ";
	char buffer1[100];
	in >> buffer1;
	c.setSurname(buffer1);
	return in;
}