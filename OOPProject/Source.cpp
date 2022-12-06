#include <iostream>
using namespace std;
#include "Ticket.cpp"
#include "Movie.cpp"
#include "Play.cpp"
#include "Match.cpp"

int main() {
	
	char row[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'I', 'J', 'K'};
	int seat[20];
	for (int i = 1; i <= 20; i++) {
		seat[i] = i;
	}
	Movie m1("Halloween", 10, row, 20, seat);
	cout << m1;
	Movie m2("Hustlers", 10, row, 20, seat);
	cout << m2;
	m1 = m2;
	cout << m1;



}

string Ticket::ticketCompany = "Sara's Ticket Company";

// we overload the << operator to print details about a movie
ostream& operator<< (ostream& out, Movie m) {
	out << "Title of the movie: " << m.movieTitle << endl;
	out << "Number of rows: " << m.noRows << endl;
	out << "Number of seats: " << m.noSeats << endl;
	return out;
}

// we overload the >> operator to read details about a movie
istream& operator>> (istream& in, Movie& m) {
	cout << "Title of the movie: ";
	char buffer[100];
	in >> buffer;
	m.setMovieTitle(buffer);
	cout << "Number of rows: ";
	in >> m.noRows;
	cout << "Number of seats: ";
	in >> m.noSeats;
	return in;
}

// we overload the << operator to print details about a play
ostream& operator<<(ostream& out, Play p) {
	out << "Title of the play: " << p.playTitle << endl;
	out << "Number of rows: " << p.noRows << endl;
	out << "Number of seats: " << p.noSeats << endl;
	return out;
}

// we overload the >> operator to read details about a play
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

// we overload the << operator to print details about a match
ostream& operator<<(ostream& out, Match m) {
	out << "The teams that are playing: " << m.teams << endl;
	out << "Number of rows: " << m.noRows << endl;
	out << "Number of seats: " << m.noSeats << endl;
	return out;
}

// we overload the >> operator to read details about a match
istream& operator>>(istream& in, Match& m) {
	cout << "The teams that are playing: ";
	char buffer[100];
	in >> buffer;
	m.setTeams(buffer);
	cout << "Number of rows: ";
	in >> m.noRows;
	cout << "Number of seats: ";
	in >> m.noSeats;
	return in;
}

// we overload the << operator to print details about a ticket
ostream& operator<<(ostream& out, Ticket t) {
	out << "Ticket Company: " << t.ticketCompany << endl;
	out << "Event: " << t.event << endl;
	out << "Row: " << t.row << endl;
	out << "Seat: " << t.seat << endl;
	out << "Price: " << t.price << endl;
	return out;
}

// we overload the >> operator to read details about a ticket
istream& operator>>(istream& in, Ticket& t) {
	cout << "Event: ";
	char buffer[100];
	in >> buffer;
	t.setEvent(buffer);
	cout << "Row: ";
	in >> t.row;
	cout << "Seat: ";
	in >> t.seat;
	cout << "Price: ";
	in >> t.price;
	return in;
}