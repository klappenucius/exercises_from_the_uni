#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Automobil {
public:
	string ime_vozaca = 0;
	Automobil () {}
	Automobil (string _ime_vozaca) : ime_vozaca(_ime_vozaca) {}
	virtual ~Automobil() {
		cout << "Poziv destruktora klase Automobil" << endl;
	}

	virtual int GetProsjecnaTezina() {
		return 0;
	}
	string GetOsiguranjeInfo() {
		return "Nepoznato";
	}
};

class AutoPrednjiPogon : public Automobil {
public:
	AutoPrednjiPogon(string _ime_vozaca) : Automobil(_ime_vozaca) {}
	~AutoPrednjiPogon() {
		cout << "Poziv destruktora klase AutoPrednjiPogon" << endl;
	}
	int GetProsjecnaTezina() {
		return 1500;
	}
	string GetOsiguranjeInfo() {
		return "Generali osiguranje";
	}

};

class AutoStraznjiPogon : public Automobil {
public:
	AutoStraznjiPogon(string _ime_vozaca) : Automobil(_ime_vozaca) {}
	int GetProsjecnaTezina() {
		return 1650;
	}
	string GetOsiguranjeInfo() {
		return "Euroherc";
	}
};

double ProsjecnaTezina(vector<Automobil*> utrka) {
	int i;
	double ukupno;
	double suma = 0;
	for (i = 0; i < utrka.size(); i++) {
		suma += (double)utrka[i]->GetProsjecnaTezina();
	}
	ukupno = suma / (double)utrka.size();
	return ukupno;
}

int main() {

	AutoStraznjiPogon DaciaLogan("Pero Peric");
	cout << "Dacia Logan: " << DaciaLogan.ime_vozaca << " " << DaciaLogan.GetProsjecnaTezina() << " " << DaciaLogan.GetOsiguranjeInfo() << endl;
	AutoPrednjiPogon FiatPunto("Ante Antic");
	AutoStraznjiPogon RenaultClio("Ivo Ivic");
	vector<Automobil*> utrka;
	utrka.push_back(&DaciaLogan);
	utrka.push_back(&FiatPunto);
	utrka.push_back(&RenaultClio);
	double ukupni_prosjek = ProsjecnaTezina(utrka);
	cout << "Ukupna prosjecna tezina: " << ukupni_prosjek << " kg" << endl;
	Automobil* a = new AutoPrednjiPogon("Ante");
	delete a;

	return 0;
}