#include <string>
#include <iostream>
using namespace std;

class Event {
private:
	const int id;
	int stageNo = 0;
	string eventName = "";
	int capacity = 0;
	int duration = 0;


public:
	Event(): id(0) {

	}

	Event(int id, int stageNo, string name, int capacity, int duration) :id(id) {
		this->stageNo = stageNo;
		this->eventName = name;
		this->capacity = capacity;
		this->duration = duration;
		
	}

	Event(const Event& event): id(event.id)
	{
		this->eventName = event.eventName;
		this->stageNo = event.stageNo;
		this->capacity = event.capacity;
		this->duration = event.duration;
	
	}

	void print() {
		cout << endl << "eventName: " << this->eventName;
		cout << endl << "Stage Number: " << this->stageNo;
		cout << endl << "capacity: " << this->capacity;
		cout << endl << "duration in minutes: " << this->duration;

	}

	~Event() {

	}

	int getStageNo() {
		return this->stageNo;
	}
	string getEventName() {
		return this->eventName;
	}
	int getCapacity() {
		return this->capacity;
	}

	int getDuration() {
		return this->duration;
	}


	void setStageNo(int stageNo) {

		this->stageNo = stageNo;
	
	}

	void setEventName(string name) {
		if (name.size() < 3) {
			throw "The name is too short";
		}
		else {
			this->eventName = name;
		}
	}

	void setCapacity(int capacity) {
		if (capacity < 500) {
			throw "the capacity should be at least 500 people";
		}
		else {
			this->capacity = capacity;
		}
	}

	void setDuration(int duration) {
		if (duration < 30) {
			throw "the event should last at least 30 minutes";
		}
		else {
			this->duration = duration;
		}
	}

	void increaseCapacity(int capcity) {
		this->capacity += capcity;
	}

	static int getTotalDuration(Event events[], int noEvents) {
		int total = 0;
		for (int i = 0; i < noEvents;i++) {
			total += events[i].duration;
		}
		return total;
	}


	void operator*(float multiplier) {
		capacity *= multiplier;
	}

	void operator+(int plus) {
		duration += plus;
	}

	friend void operator>>(istream& in, Event e);

	friend void operator<<(ostream& out, Event e);
};

void operator<<(ostream& out ,Event e) {

	cout << endl << "eventName: " << e.eventName;

	cout << endl << "Stage Number: " << e.stageNo;
	cout << endl << "capacity: " << e.capacity;
	cout << endl << "duration in minutes: " << e.duration;
}

void operator>>(istream& in, Event e) {

	cout << endl << "Event name: ";
	in >> e.eventName;
	cout << endl << "Stage No: ";
	in >> e.stageNo;
	cout << endl << "capacity: ";
	in >> e.capacity;
	cout << endl << "duration: ";
	in >> e.duration;



}
// have to add generic methods