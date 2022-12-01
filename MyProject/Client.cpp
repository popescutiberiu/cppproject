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




	void operator<<(ostream& out) {
		
		cout << endl << "Name: " << this->name;
		cout << endl << "Address: " << this->address;
		cout << endl << "age: " << this->age;
		if (this->isAdult == true) {
			cout << endl << "is over 18";
		}
		else cout << endl << "is under 18";
	}

	void operator>>(istream& in) {

		cout << endl << "name: ";
		in >> name;
		cout << endl << "address: ";
		in >> address;
		cout << endl << "age: ";
		in >> age;
		cout << endl << "is adult? ";
		string adult;
		in >> adult;
		if (adult == "yes") {
			isAdult == true;
		}
		else if (adult == "no") {
			isAdult == false;
		}
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
		return this->age == c.age;
	}
};

