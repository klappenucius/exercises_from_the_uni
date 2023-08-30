#include <iostream>
using namespace std;

class Objekt {
public:
	static int broj_instanci;
	static int broj_ID;
	int ID;
	Objekt () {
		broj_instanci++;
		if (broj_instanci < broj_ID) {
			broj_ID = broj_ID + 1;
		}
		else {
			broj_ID = broj_instanci;
		}
		ID = broj_ID;
	}

	~Objekt() {

		broj_instanci--;
	}

	static int BrojInstanci() {
		return broj_instanci;
	};
};

int Objekt::broj_instanci = 0;
int Objekt::broj_ID = 0;


int main() {
	Objekt obj1; // ID = 1, brojInstanci = 1
	Objekt niz[10]; // ID = 2..11, brojInstanci = 11
	Objekt* p = new Objekt[10]; // ID = 12..21, brojInstanci = 21
	delete[] p; // brojInstanci = 11!
	Objekt zadnji; cout << zadnji.ID << " " << Objekt::BrojInstanci() << endl; // 22 12
	
	return 0; 
}

