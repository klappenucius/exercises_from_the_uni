#include <iostream>
using namespace std;

//BITNO: ako su funkcije inline, nije ispred njih potrebno pisati "template<class T>"

template<class T> //najprije napraviti sve s int, a zatim sve zamijeniti s T
class Polje {
public:
    int BrElem; //broj elemenata
    T *polje; //mora biti pokazivac kako bi se moglo dinamicki alocirati polje
    Polje(int _BrElem) { //konstruktor: prima broj elemenata
        BrElem = _BrElem; //tek UNUTAR viticaste zagrade predaje uneseno clanskoj varijabli
        polje = new T[BrElem]; //u konstruktoru se inicijaliziraju clanske varijable, dakle, polje (osim BrElem)
    }
    int getBrElem() { //metoda koja dohvaca broj elemenata
        return BrElem;
    }

    T& operator[](int n){ //preopterecenje operatora [] -- vraca referencu na template varijablu!!
        return polje[n];
    }
 
    int Sadrzi(T x) {//klasicno provjeravanje nalazi li se nesto u polju
        int i;
        for (i = 0; i < BrElem; i++) {
            if (polje[i] == x) {
                return i;
            }
            else {
                return -1;
            }
        }
    }

};



int main()
{
    Polje<int> A(10);

    // inicijalizacija elemenata slu�ajnim vrijednostima 1-100
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
        A[i] = rand() % 100 + 1; // A.polje[i] ...

    // ispi�i broj elemenata
    cout << "Polje ima " << A.BrElem << " elemenata " << endl;

    //ispis polja
    int i;
    for (i = 0; i < A.BrElem; i++) {
        cout << A.polje[i] << " " << endl;
    };

    // da li se u polju nalazi broj x?
    int x = 58;
    int indeks = A.Sadrzi(x);
    if (indeks != -1)
        cout << "Broj " << x << " se nalazi u elementu s indeksom " << indeks << "!\n";
    else
        cout << "Broj " << x << " se ne nalazi u polju!\n";


    return 0;
}


