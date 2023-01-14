#include <string>
#include <iostream>
#include "Eveniment.h"
using namespace std;

class Bilet {
private:
	string nume;
	string prenume;
	float pret; //?
	int rand;
	int loc;
	Eveniment evenimentBilet;
	const int id;
	static int contorBilete;

public:

	Bilet() : id(++contorBilete) {
		nume = "";
		prenume = "";
		pret = -1;
		rand = 0;
		loc = 0;
	}

	Bilet(string nume, string prenume, float pret, string sala, int rand, int loc,Eveniment eveniment) : id(++contorBilete) {
		this->nume = nume;
		this->prenume = prenume;
		if(pret < 0) this->pret = pret * (-1);
		else this->pret = pret;
		this->rand = rand;
		this->loc = loc;
		this->evenimentBilet = eveniment;
	}

	Bilet(const Bilet& b) : id(++contorBilete) {
		this->nume = b.nume;
		this->prenume = b.prenume;
		this->pret = b.pret;
		this->rand = b.rand;
		this->loc = b.loc;
		this->evenimentBilet = b.evenimentBilet;
	}

	Bilet& operator=(const Bilet& b) {
		if (this != &b) {
			this->nume = b.nume;
			this->prenume = b.prenume;
			this->pret = b.pret;
			this->rand = b.rand;
			this->loc = b.loc;
			this->evenimentBilet = b.evenimentBilet;
		}
		return *this;
	}

	static int getContorBilete() {
		return contorBilete;
	}

	float getPret() {
		return pret;
	}
	void setPret(float pret) {
		if (pret < 0) this->pret = pret * (-1);
		else this->pret = pret;
	}

	int getRand() {
		return rand;
	}
	void setRand(int rand) {
		this->rand = rand;
	}

	int getLoc() {
		return loc;
	}
	void setLoc(int loc) {
		this->loc = loc;
	}

	Bilet operator+(Bilet b) {
		Bilet copie = *this;
		copie.pret += b.pret;

		return copie;
	}
	Bilet operator+(float pret) {
		Bilet copie = *this;
		copie.pret += pret;
		return copie;
	}

	Bilet operator-=(float valoare) {
		if (pret - valoare > 0) pret-=valoare;
		else pret = 0;

		return *this;
	}

	static float pretMediuBilete(Bilet* bilete, int nrBilete)
	{
		float suma = 0;
		if (bilete != nullptr && nrBilete > 0)
		{
			for (int i = 0; i < nrBilete; i++)
			{
				suma += bilete[i].getPret();
			}
			suma /= nrBilete;
		}
		return suma;
	}

	~Bilet() {
	}

	friend Bilet operator+(float pret, Bilet b);
	friend ostream& operator<<(ostream& out, const Bilet& b);
	friend istream& operator>>(istream& in, Bilet& b);
};

Bilet operator+(float pret, Bilet b) {
	b.pret += pret;
	return b;
};

istream& operator>>(istream& in, Bilet& b) {
	string bufferString;
	int i, bec = 0;

	cout << "Introduceti numele detinatorului biletului: "; in >> b.nume;
	cout << "Introduceti prenumele detinatorului biletului: ";
	char prenume[30];
	in.get();
	in.getline(prenume, 30);
	b.prenume = prenume;
	do {
		cout << "Introduceti pretul biletului: ";
			in >> bufferString;
			for (i = 0; i < bufferString.length(); i++) {
				if (isdigit(bufferString[i]) == false)
					break;
			}
			if (i != bufferString.length()) cout << "!--------Numarul introdus nu este de tip int! ----------! " << endl;
			else {
				b.pret = stoi(bufferString);
				bec = 1;
			}
	} while (b.pret<0 || (!bec) ); bec = 0;

	cout << "Introduceti denumirea spectacolului aferent biletului: ";
	cout << "Introduceti denumirea salii in care spectacolul are loc: ";

	do {
		cout << "Introduceti randul aferent biletului: "; 
		in >> bufferString;
		for (i = 0; i < bufferString.length(); i++) {
			if (isdigit(bufferString[i]) == false)
				break;
		}
		if (i != bufferString.length()) cout << "!--------Numarul introdus nu este de tip int! ----------! " << endl;
		else {
			b.rand = stoi(bufferString);
			bec = 1;
		}
	} while (!bec); bec = 0;
	
	do {
		cout << "Introduceti locul aferent biletului: ";
		in >> bufferString;
		for (i = 0; i < bufferString.length(); i++) {
			if (isdigit(bufferString[i]) == false)
				break;
		}
		if (i != bufferString.length()) cout << "!--------Numarul introdus nu este de tip int! ----------! " << endl;
		else {
			b.loc = stoi(bufferString);
			bec = 1;
		}
	} while (!bec); bec = 0;
	

	return in;
}


ostream& operator<<(ostream& out, const Bilet& b) {
	Bilet aux;
	aux = b;
	out << "------------------Detalii bilet cu ID-ul " << b.id << "-----------------" << endl;
	out << "Nume detinator bilet: " << b.nume << endl;
	out << "Prenume detinator bilet: " << b.prenume << endl;
	out << "Locatia evenimentului: " << aux.evenimentBilet.getLocatieEveniment().getNumeLocatie() << endl;
	out << "Pret bilet: " << b.pret << endl;
	out << "Denumire spectacol aferent biletului: " << aux.evenimentBilet.getDenumireEveniment()<<endl;
	out << "Randul aferent biletului: " << b.rand << endl;
	out << "Locul aferent biletului: " << b.loc << endl;

	out << "-----------------------------------------------------------";

	return out;
}

int Bilet::contorBilete = 0;


