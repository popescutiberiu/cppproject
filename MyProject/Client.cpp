#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

class Client {
private:

	string name = "";
	char* address = nullptr;
	int age=0;
	bool isAdult = false;

	static int NO_CLIENTS;

public:

	Client() {
			
	}

	Client(int id, string name, char* address, int age, bool isAdult) {
		this->name = name;
		this->address = address;
		this->age = age;
		this->isAdult = isAdult;
		NO_CLIENTS++;
	}

	Client(const Client& client) 
	{
		this->name = client.name;
		this->address = client.address;
		this->age = client.age;
		this->isAdult == client.isAdult;
	}


	void print() {
		cout << endl <<"Name: " << this->name;
		cout << endl << "Address: " << this->address;
		cout << endl << "age: " << this->age;
		if (this->isAdult == true) {
			cout << endl << "is over 18";
		}
		else cout << endl << "is under 18";
		
	}

	~Client() {
		delete[] this->address;
		NO_CLIENTS--;
	}

	string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
	char* getAddress() {
		return this->address;
	}
	bool getAdult() {
		return this->isAdult;
	}

	void setAddress(char* newAddress) {
		if (this->address != nullptr) {
			delete[] this->address;
		}
		if (strlen(newAddress) < 3) {
			throw "The Address is too short!";
		}else{
			this->address = new char[strlen(newAddress) + 1];
			strcpy(this->address, newAddress);
		}
		

	}

	void setName(string name) {
		if (name.size() < 3) {
			throw "The name is too short";
		}
		else {
			this->name = name;
		}
	}

	void setAdult(bool adult) {
		this->isAdult = adult;
	}

	void setAge(int age) {
		if (age < 7) {
			throw "you have to be at least 7 to register as a client";
		}
		else {
			this->age = age;
		}
	}

	static int getNoClients() {
		return Client::NO_CLIENTS;
	}

	void makeAdult() {
		this->isAdult = true;
	}

	
	Client operator++() {
		this->age++;
		return *this;
	}
	Client operator--() {
		this->age--;
		return *this;
	}

	bool operator==(Client c) {
		return this->age = c.age;
	}

	friend void operator<<(ostream& out, Client c);

	friend void operator>>(istream& in, Client c);
};

void operator<<(ostream& out, Client c) {

	cout << endl << "Name: " << c.name;
	cout << endl << "Address: " << c.address;
	cout << endl << "age: " << c.age;
	if (c.isAdult == true) {
		cout << endl << "is over 18";
	}
	else cout << endl << "is under 18";
}

void operator>>(istream& in, Client c) {

	cout << endl << "name: ";
	in >> c.name;

	cout << endl << "address: ";
	char buffer[100];
	in >> buffer;
	delete[] c.address;
	c.address = new char[strlen(buffer) + 1];
	strcpy_s(c.address, strlen(buffer) + 1, buffer);
	cout << "address:  " << c.address << endl;
	
	cout << endl << "age: ";
	in >> c.age;
	cout << endl << "is adult? ";
	string adult;
	in >> adult;
	if (adult == "yes") {
		c.isAdult == true;
	}
	else if (adult == "no") {
		c.isAdult == false;
	}
}

