#include <string>
#include <iostream>
using namespace std;

class Ticket {
	int ticketId = 0;
	int price = 0;
	int* row = nullptr;
	int noRows;
	int hour;

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
};