#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Osoba {
public:
	string ime, prezime, oib;
	Osoba () {}
	Osoba(string _oib) : oib(_oib) {

	}
	void RadniStatus() {
		cout << "Osoba nema radni status!" << endl;
	};
};

class Student : public Osoba {
public:
	string NazivStudija, smjer;
	int semestar;
	Student(){}

	void RadniStatus() {
		cout << "Redovni student" << endl;
	}
};

int BrojStudenata(Student* p, int elem, int semestar) {
	int br_studenata = 0;
	for (int i = 0; i < elem; i++) {
		if (p->semestar == semestar) {
			br_studenata++;
		}
	}
	return br_studenata;
}

int main() {

	Student GrupaA[5];
	for (int i = 0; i < 5; i++) {
		string temp;
		cin >> temp;
		GrupaA[i].oib = temp;
	}

	for (int i = 0; i < 5; i++) {
		cout << "Student " << i + 1 << ": " << GrupaA[i].oib << " " << endl;
		GrupaA[i].RadniStatus();
	}

	return 0;
}
