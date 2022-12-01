#include <string>
#include <iostream>
using namespace std;

class Ticket {
	int ticketId = 0;
	int price = 0;
	int* row = nullptr;
	int noRows=0;
	int hour=0;

	Ticket() {

	}

	Ticket(int id, int price, int* row, int NoRows, int hour) {
		this->ticketId = id;
		this->price = price; 
		this->hour = hour;
		this->setRow(row, NoRows);

	}

	void setRow(int* newRow, int newNoRow) {

		if (newNoRow <= 0) {
			throw "Number of rows is not ok";
		}
		if (newRow == nullptr) {
			throw "Rows pointer is not ok";
		}

	

		if (this->row != nullptr)
			delete[] this->row;
		this->row = new int[newNoRow];
		for (int i = 0; i < newNoRow; i++) {
			this->row[i] = newRow[i];
		}
		this->noRows = newNoRow;
	}

	Ticket(const Ticket& ticket) 
	{
		this->ticketId = ticket.ticketId;
		this->price = ticket.price;
		this->row = ticket.row;
		this->noRows = ticket.noRows;
		this->hour = ticket.hour;

	}

	~Ticket() {
		delete[] this->row;
	}

	int getTicketId() {
		return this->ticketId;
	}
	int getPrice() {
		return this->price;
	}
	int* getRow() {
		return this->row;
	}
	int getNoRows() {
		return this->noRows;
	}
	int getHour() {
		return this->hour;
	}

	void setTicketId(int id) {
		if (id < 0) {
			throw "the id has to be at least 0";
		}
		else
		{
			this->ticketId = id;
		}
	}

	void setPrice(int price) {
		if (price < 20) {
			throw "the price has to be at least 20 dollars";
		}
		else
		{
			this->price = price;
		}
	}
	void setHour(int hour) {
		if (hour < 0 || hour > 23) {
			throw "the hour has to be between 0 and 23";
		}
		else
		{
			this->hour = hour;
		}
	}

	static double getTotalPrice(Ticket tickets[], int noTickets) {
		double total = 0;
		for (int i = 0; i < noTickets;i++) {
			total += tickets[i].price;
		}
		return total;
	}


	void changeHour( int difference) {
		this->hour -= difference;
	}

	void operator<<(ostream& out) {

		cout << endl << "ticket Id: " << this->ticketId;

		cout << endl << "Price: " << this->price;
		cout << endl << "row: " << this->row;
		cout << endl << "Number of rows: " << this->noRows;
		cout << endl << "Hour: " << this->hour;
	}

	void operator>>(istream& in) {

		cout << endl << "Ticket id: ";
		in >> ticketId;
		cout << endl << "Price: ";
		in >> price;
		cout << endl << "Row: ";
		for (int i = 0; i < noRows;i++) {
			in >> row[i];
		}

		cout << endl << "number of rows: ";
		in >> noRows;
		cout << endl << "Hour: ";
		in >> hour;
	}

	void operator/(float divide) {
		price /= divide;
	}

	void operator-(float reduce) {
		hour -= reduce;
	}

	friend void operator>>(istream& in, Ticket t);

	friend void operator<<(ostream& out, Ticket t);
};

void operator<<(ostream& out, Ticket t) {

	cout << endl << "ticket Id: " << t.ticketId;

	cout << endl << "Price: " << t.price;
	cout << endl << "row: " << t.row;
	cout << endl << "Number of rows: " << t.noRows;
	cout << endl << "Hour: " << t.hour;
}

void operator>>(istream& in, Ticket t) {

	cout << endl << "Ticket id: ";
	in >> t.ticketId;
	cout << endl << "Price: ";
	in >> t.price;
	cout << endl << "Row: ";
	for (int i = 0; i < t.noRows;i++) {
		in >> t.row[i];
	}

	cout << endl << "number of rows: ";
	in >> t.noRows;
	cout << endl << "Hour: ";
	in >> t.hour;
}

//int ticketId = 0;
//int price = 0;
//int* row = nullptr;
//int noRows;
//int hour;