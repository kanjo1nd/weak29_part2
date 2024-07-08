#include <iostream>

using namespace std;

class Wheels {
protected:
	int size;
public:
	Wheels() : size(1) {}
	Wheels(int size_t) {
		size = size_t;
	}
	int Get() {
		return size;
	}
	void Set(int size_t) {
		size = size_t;
	}
};

class Engine {
protected:
	char* brand;
public:
	Engine(const char* br) {
		this->brand = new char[strlen(br) + 1];
		strcpy_s(this->brand, strlen(br) + 1, br);
	}
	~Engine() {
		delete[] brand;
	}
	char* Get() const {
		return brand;
	}
	void Set(const char* br) {
		this->brand = new char[strlen(br) + 1];
		strcpy_s(this->brand, strlen(br) + 1, br);
	}
};

class Doors {
protected:
	int size;
public:
	Doors() : size(4) {}
	Doors(int size_t) {
		size = size_t;
	}
	int Get() {
		return size;
	}
	void Set(int size_t) {
		size = size_t;
	}
};

class Car : public Wheels, public Engine, public Doors {
public:
	Car(int size_t, const char* br, int size) : Wheels(size_t), Engine(br), Doors(size) {
	}
	void Output() {
		cout << "Wheels size: " << Wheels::Get() << endl;
		cout << "Engine brand: " << Engine::Get() << endl;
		cout << "Doors size: " << Doors::Get() << endl;
	}
};

int main() {
	Car obj1(12, "ergeg", 34);
	obj1.Output();
	obj1.Wheels::Set(2);
	obj1.Output();
}