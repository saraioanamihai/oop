#include <iostream>
using namespace std;
#include "Ticket.cpp"
#include "Movie.cpp"
#include "Play.cpp"
#include "Match.cpp"

int main() {
	
	char row[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'I', 'J', 'K'};
	int seat[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	
	Movie m1("Halloween", 10, row, 20, seat);
	cout << m1 << endl;
	Movie m2("Hustlers", 10, row, 20, seat);
	cout << m2 << endl;
	m1 = m2;
	cout << m1 << endl;
	Movie m3("Hush", 10, row, 20, seat);
	Movie m4 = m1 + m3;
	cout << m4 << endl;
	Movie m5 = m1 - m3;
	cout << m5 << endl;

	Play p1;
	p1.setPlayTitle("Hamlet");
	p1.setNoRows(10);
	p1.setRow(row);
	p1.setNoSeats(20);
	p1.setSeat(seat);
	cout << p1 << endl;
	p1++;
	cout << p1 << endl;
	++p1;
	cout << p1 << endl;

	Match ma1("France vs Brazil", 10, row, 20, seat);
	cout << ma1.getTeams() << " ";
	cout << ma1.getNoRows() << " ";
	cout << ma1.getRow() << " ";
	cout << ma1.getNoSeats() << " ";
	cout << ma1.getSeat() << endl;
	cout << ma1[3] << endl;
	char row2[] = {'A','B'};
	int seat2[] = {1, 2};
	Match ma2("Steaua vs Dinamo", 2, row2, 2, seat2);
	if (ma1 > ma2) {
		cout << "Match 1 has more available seats than Match 2" << endl;
	}
	else {
		cout << "Match 2 has more available seats than Match 1" << endl;
	}
	cout << endl;

	Ticket t1("Movie: Halloween", Ticket::categories::VIP, 'C', 7, (float) 19.99);
	cout << t1 << endl;
	Ticket t2 = t1;
	cout << t2 << endl;
	if (t1 == t2) {
		cout << "Ticket 1 and Ticket 2 are identical" << endl;
	}
	else {
		cout << "Ticket 1 and Ticket 2 are different" << endl;
	}
	cout << endl;
	Ticket t3;
	cin >> t3;
	cout << endl;
	cout << t3 << endl;
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