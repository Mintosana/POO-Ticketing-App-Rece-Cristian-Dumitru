#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Locatie.h"
using namespace std;
const int valoriLuni[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
enum tipEveniment { undefined = 0, entertainment, cultural, sport };

class Eveniment {
private:
	
	int zi;
	int luna;
	int an;
	string ora;
	string denumireEveniment;
	Locatie locatieEveniment;
	tipEveniment tip;
public:

	Eveniment() {
		an = 0;
		luna = 0;
		zi = 0;
		ora = "";
		denumireEveniment = "";
		tip = undefined;
	};

	Eveniment(int zi,int luna,int an, string ora, string denumireEveniment,Locatie locatie,tipEveniment tip) { //mai ai de facut get set pentru locatie
		if(an > 2021) this->an = an;
		if(luna> 0 && luna < 13) this->luna = luna;
		if (this->an % 4 == 0) {
			if (this->luna == 2) {
				if (zi > 0 && zi <= (valoriLuni[luna - 1]+1)) this->zi = zi;
				else this->zi = 0;
			}
			else {
				if (zi > 0 && zi <= valoriLuni[luna - 1]) this->zi = zi;
				else this->zi = 0;
			}
		}
		else {
			if (zi > 0 && zi <= valoriLuni[luna - 1]) this->zi = zi;
			else this->zi = 0;
		}
		this->ora = ora;
		this->denumireEveniment = denumireEveniment;
		this->locatieEveniment = locatie;
		if (tip > 0 && tip < 4) {
			this->tip = tip;
		}
		else tip = undefined;
	}

	int getZi() {
		return zi;
	}
	void setZi(int zi) {
		if (this->an % 4 == 0) {
			if (this->luna == 2) {
				if (zi > 0 && zi <= (valoriLuni[luna - 1] + 1)) this->zi = zi;
				else cout << "Introduceti o zi valida";
			}
			else {
				if (zi > 0 && zi <= valoriLuni[luna - 1]) this->zi = zi;
				else cout << "Introduceti o zi valida";
			}
		}
		else {
			if (zi > 0 && zi <= valoriLuni[luna - 1]) this->zi = zi;
			else cout << "Introduceti o zi valida";
		}
	}

	int getLuna() {
		return luna;
	}
	void setLuna(int luna) {
		if (luna > 0 && luna < 13) {
			this->luna = luna;
		}
	}

	int getAn() {
		return an;
	}
	void setAn() {
		if (an > 2021) this->an = an;
	}

	tipEveniment getTip() {
		return tip;
	}
	void setTip(tipEveniment tip) {
		if (tip > 0 && tip < 4) {
			this->tip = tip;
		}
		else tip = undefined;
	}

	string getOra() {
		return ora;
	}
	void setOra(string ora) {
		int i = 0;
		if (ora.length() == 5) {
			for (i = 0; i < ora.length(); i++) {
				if (i == 2) {
					if (ora[i] != ':')
						break;
				}
				else {
					if (isdigit(ora[i]) == false)
						break;
				}
			}
			if (i != ora.length()) cout << "!--------Ora nu este introdusa corect! (caracterele introduse nu sunt corespunzatoare formatului) ----------! " << endl;
			else if (ora[0] > 50) cout << "!--------Ora nu este corect introdusa! ---------! " << endl;   // 49-59 echivalent la 1->9 in char
			else if (ora[3] > 53) cout << "!--------Minutele nu sunt corect introduse! ------! " << endl;
			else this->ora = ora;
		}
	}

	Locatie getLocatieEveniment() {
		return this->locatieEveniment;
	}

	string getDenumireEveniment() {
		return denumireEveniment;
	}
	void setDenumireEveniment(string denumire) {
		if (denumire != "") {
			denumireEveniment = denumire;
		}
		else cout << "Introduceti o denumire valida pentru Adresa" << endl;
	}

	void LowercaseDenumireEveniment() {
		for (int i = 0; i < denumireEveniment.length(); i++) {
			denumireEveniment[i] = tolower(denumireEveniment[i]);
		}
	}

	Eveniment& operator=(const Eveniment& e) {
		if (this != &e) {
			this->zi = e.zi;
			this->luna = e.luna;
			this->an = e.an;
			this->ora = e.ora;
			this->denumireEveniment = e.denumireEveniment;
			this->locatieEveniment = e.locatieEveniment;
			this->tip = e.tip;
		}
		return *this;
	}

	Eveniment& operator++()
	{
		an++;
		return *this;
	}
	Eveniment operator++(int i)
	{
		Eveniment copie = *this;
		an++;
		return copie;
	}

	Eveniment& operator--()
	{
		if(an>2022) an--;
		return *this;
	}
	Eveniment operator--(int i)
	{
		Eveniment copie = *this;
		if (an > 2022) an--;
		return copie;
	}

	void scriereFisier(string numeFisier) {
		ofstream f(numeFisier, ios::out | ios::app);
		Eveniment aux;
		f << this->denumireEveniment <<endl;
		f << this->zi << endl;
		f << this->luna << endl;
		f << this->an << endl;
		f << this->ora << endl;
		f << this->locatieEveniment.getNumeLocatie() << endl;
		f << this->locatieEveniment.getDenumireAdresa() << endl;
		f << this->tip << endl;

		cout << "Au fost introduse date in fisierul " << numeFisier << endl;

	}

	void citireFisier(string numeFisier) {
		ifstream f(numeFisier, ios::in);
		string aux;
		int tip;
		if (f.is_open()) {
			f >> this->denumireEveniment;
			f >> this->zi;
			f >> this->luna;
			f >> this->an;
			f >> this->ora;
			f >> aux;
			this->locatieEveniment.setNumeLocatie(aux);
			f >> aux;
			this->locatieEveniment.setDenumireAdresa(aux);
			f >> tip;
			this->tip = (tipEveniment)tip;
		}
	}

	friend ostream& operator<<(ostream& out, const Eveniment& e);
	friend istream& operator>>(istream& in, Eveniment& e);

};

ostream& operator<<(ostream& out, const Eveniment& e) {
	Eveniment aux;
	aux = e;
	out << endl << "---------------Detaliile evenimentului " << e.denumireEveniment << "--------------" << endl;
	out << "Evenimentul va avea loc pe data de " << e.zi << "-" << e.luna << "-" << e.an << " la ora " << e.ora<< endl;
	out << "Locatia este " << aux.locatieEveniment.getNumeLocatie() << " ce se situeaza pe " << aux.locatieEveniment.getDenumireAdresa() << endl;
	out << "Evenimentul este de tip " << aux.tip << endl;
	out << "-----------------------------------------------------------" << endl;

	return out;
}
istream& operator>>(istream& in, Eveniment& e) {
	string buffer;
	int i, bec = 0, aux;

	do {
		bec = 0;
		cout << "Introduceti ziua evenimentului:  ";
		in >> ws >> buffer;
		for (i = 0; i < buffer.length(); i++) {
			if (isdigit(buffer[i]) == false)
				break;
		}

		if (i != buffer.length()) {
			cout << "!--------Numarul introdus nu este valid! ----------! " << endl;
			bec = 1;
		}
		else{
			aux = stoi(buffer);
			if (aux >= 31) {
				cout << "!-------Numarul introdus este prea mare! ----------!" << endl;
				bec = 1;
			}

		}

		if (!bec) e.zi = stoi(buffer);
	} while (bec);

	do {
		bec = 0;
		cout << "Introduceti luna evenimentului:  ";
		in >> ws >> buffer;
		for (i = 0; i < buffer.length(); i++) {
			if (isdigit(buffer[i]) == false)
				break;
		}

		if (i != buffer.length()) {
			cout << "!--------Numarul introdus nu este valid! ----------! " << endl;
			bec = 1;
		}
		else {
			aux = stoi(buffer);
			if (aux > 12) {
				cout << "!-------Numarul introdus este prea mare! ----------!" << endl;
				bec = 1;
			}

		}

		if (!bec) e.luna = stoi(buffer);
	} while (bec);

	do {
		bec = 0;
		cout << "Introduceti anul evenimentului:  ";
		in >> ws >> buffer;
		for (i = 0; i < buffer.length(); i++) {
			if (isdigit(buffer[i]) == false)
				break;
		}

		if (i != buffer.length()) {
			cout << "!--------Numarul introdus nu este valid! ----------! " << endl;
			bec = 1;
		}
		else {
			aux = stoi(buffer);
			if (aux < 2022) {
				cout << "!-------Numarul introdus este prea mic! ----------!" << endl;
				bec = 1;
			}

		}

		if (!bec) e.an = stoi(buffer);
	} while (bec);

	do {
		bec = 0;
		cout << "Introduceti ora evenimentului (hh:mm) :  ";
		in >> ws >> buffer;
		if (buffer.length() == 5) {
			for (i = 0; i < buffer.length(); i++) {
				if (i == 2) {
					if (buffer[i] != ':')
						break;
				}
				else {
					if (isdigit(buffer[i]) == false)
						break;
				}
			}
			if (i != buffer.length()){
				cout << "!--------Ora nu este introdusa corect! (caracterele introduse nu sunt corespunzatoare formatului) ----------! " << endl;
				bec = 1;
			}
			else if ((buffer[0] > 50)) {
				cout << "!--------Ora nu este corect introdusa! ---------! " << endl;
				bec = 1;
			}
			else if (buffer[3] > 53) {
				cout << "!--------Minutele nu sunt corect introduse! ------! " << endl;
				bec = 1;
			}
		}
		else {
			cout << "!-------Ora nu este introdusa corect! ---------! (lungimea string-ului gresita)";
			bec = 1;
		}
		if (!bec) e.ora = buffer;
	} while (bec);

	do {
		cout << "Introduceti denumirea evenimentului (Minim 3 caractere):  ";
		in >> ws;
		getline(in, buffer);
	} while (!(buffer.length() > 2 && buffer.length() < 50));
	e.denumireEveniment = buffer;

	do {
		cout << "Introduceti tipul evenimentului (entertainment/cultural/sport): ";
		in >> ws;
		getline(in, buffer);
	} while (buffer == "entertainment" || buffer == "cultural" || buffer == "sport");
	

	return in;
}
