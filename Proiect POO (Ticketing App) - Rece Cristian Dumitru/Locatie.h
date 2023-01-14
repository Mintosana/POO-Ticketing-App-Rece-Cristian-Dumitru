#pragma once
#include <string>
#include <iostream>
using namespace std;

class Locatie {
private:
	int maxLocuri;
	string numeLocatie;
	string denumireAdresa;
	int nrRanduri;
	int nrScauneRand;  // numar de scaune per rand
	int** matriceLocuri;
	static int nrLocatii;

public:
	Locatie() {
		maxLocuri = 0;
		numeLocatie = "";
		denumireAdresa = "";
		nrRanduri = 0;
		nrScauneRand = 0;
		
		matriceLocuri = nullptr;

		nrLocatii++;
	}

	Locatie(int maxLocuri,string numeLocatie, string denumireAdresa, int nrScauneRand) {
		this->maxLocuri = maxLocuri;
		this->numeLocatie = numeLocatie;
		this->denumireAdresa = denumireAdresa;
		this->nrScauneRand = nrScauneRand;

		if (maxLocuri % nrScauneRand == 0) this->nrRanduri = maxLocuri / nrScauneRand;
		else this->nrRanduri = maxLocuri / nrScauneRand + 1;

		matriceLocuri = new int* [this->nrRanduri];
		for (int i = 0; i < this->nrRanduri; i++) {
			if (i == this->nrRanduri-1) {
				matriceLocuri[i] = new int[this->maxLocuri%this->nrScauneRand];
			}
			else {
				matriceLocuri[i] = new int[nrScauneRand];
			}
		}
		for (int i = 0; i < this->nrRanduri; i++) {
			if (i == this->nrRanduri-1) {
				for (int j = 0; j < maxLocuri%nrScauneRand; j++) {
					matriceLocuri[i][j] = 1;
				}
			}
			else {
				for (int j = 0; j < nrScauneRand; j++) {
					matriceLocuri[i][j] = 1;
				}
			}
		}

		nrLocatii++;
	}

	Locatie(const Locatie& l) {
		this->maxLocuri = l.maxLocuri;
		this->numeLocatie = l.numeLocatie;
		this->denumireAdresa = l.denumireAdresa;
		this->nrScauneRand = l.nrScauneRand;

		if (this->maxLocuri % this->nrScauneRand == 0) this->nrRanduri = this->maxLocuri / this->nrScauneRand;
		else this->nrRanduri = this->maxLocuri / this->nrScauneRand + 1;

		this->matriceLocuri = new int* [this->nrRanduri];
		for (int i = 0; i < this->nrRanduri; i++) {
			if (i == this->nrRanduri - 1) {
				this->matriceLocuri[i] = new int[this->maxLocuri % this->nrScauneRand];
			}
			else {
				this->matriceLocuri[i] = new int[nrScauneRand];
			}
		}
		for (int i = 0; i < this->nrRanduri; i++) {
			if (i == this->nrRanduri - 1) {
				for (int j = 0; j < this->maxLocuri % this->nrScauneRand; j++) {
					this->matriceLocuri[i][j] = 1;
				}
			}
			else {
				for (int j = 0; j < this->nrScauneRand; j++) {
					this->matriceLocuri[i][j] = 1;
				}
			}
		}

		nrLocatii++;
	}

	Locatie& operator=(const Locatie& l) {
		if (this != &l) {
			if (this->matriceLocuri != NULL) {
				for (int i = 0; i < nrRanduri; i++) {
					delete[] matriceLocuri[i];
				}
				delete[] matriceLocuri;
			}
			this->maxLocuri = l.maxLocuri;
			this->numeLocatie = l.numeLocatie;
			this->denumireAdresa = l.denumireAdresa;
			this->nrScauneRand = l.nrScauneRand;

			if (this->maxLocuri % this->nrScauneRand == 0) this->nrRanduri = this->maxLocuri / this->nrScauneRand;
			else this->nrRanduri = this->maxLocuri / this->nrScauneRand + 1;

			this->matriceLocuri = new int* [this->nrRanduri];
			for (int i = 0; i < this->nrRanduri; i++) {
				if (i == this->nrRanduri - 1) {
						this->matriceLocuri[i] = new int[this->maxLocuri % this->nrScauneRand];
				}
				else {
					this->matriceLocuri[i] = new int[nrScauneRand];
				}
			}
			for (int i = 0; i < this->nrRanduri; i++) {
				if (i == this->nrRanduri - 1) {
					for (int j = 0; j < this->maxLocuri % this->nrScauneRand; j++) {
						this->matriceLocuri[i][j] = 1;
					}
				}
				else {
					for (int j = 0; j < this->nrScauneRand; j++) {
						this->matriceLocuri[i][j] = 1;
					}
				}
			}
		}
		return *this;
	}

	void decrementareMaxLocuri(int val) {
		if (maxLocuri - val < 0) {
			cout << "Sunt prea putine locuri libere";
		}
		else {
			maxLocuri -= val;
		}
	}

	int getMaxLocuri() {
		return maxLocuri;
	}
	void setMaxLocuri(int max) {
		if (max > 0) {
			maxLocuri = max;
		}
		else cout << "Introduceti un nr maxim de locuri mai mare ca 0"<< endl;
	}

	string getNumeLocatie() {
		return numeLocatie;
	}
	void setNumeLocatie(string nume) {
		if ( nume != "") {
			numeLocatie = nume;
		}
		else cout << "Introduceti un nume valid pentru locatie" << endl;
	}

	string getDenumireAdresa() {
		return denumireAdresa;
	}
	void setDenumireAdresa(string denumire) {
		if (denumire != "") {
			denumireAdresa = denumire;
		}
		else cout << "Introduceti o denumire valida pentru Adresa" << endl;
	}

	int getNrRanduri() {
		return nrRanduri;
	}
	void setNrRanduri(int randuri) {
		if (randuri > 0) {
			if (randuri < maxLocuri) {
				nrRanduri = randuri;
			}
			else cout << "Numarul de randuri este mai mare decat nr de locuri!! "<< endl;
		}
		else cout << "Numarul de randuri trebuie sa fie mai mare ca 0!! " << endl;
	}

	int getNrScauneRand() {
		return nrScauneRand;
	}
	void setNrScauneRand(int scauneRand) {
		if (scauneRand > 0) {
			nrScauneRand = scauneRand;
		}
		else cout << "Numarul scaunelor pe rand trebuie sa fie mai mare ca 0!! " << endl;
	}
	
	
	int** getMatriceLocuri() {
		int** aux;

		aux = new int* [this->nrRanduri];

		for (int i = 0; i < this->nrRanduri; i++) {
			if (i == this->nrRanduri - 1) {
				aux[i] = new int[1];
			}
			else
				aux[i] = new int[nrScauneRand];
		}
		for (int i = 0; i < this->nrRanduri; i++) {
			for (int j = 0; j < nrScauneRand; j++) {
				aux[i][j] = this->matriceLocuri[i][j];
			}
		}

		return aux;
	}
	void setMatriceLocuri(int** matriceLocuri) {
		if (this->matriceLocuri != NULL)
			delete[] this->matriceLocuri;

		this->matriceLocuri = new int* [this->nrRanduri * this->nrScauneRand];

		for (int i = 0; i < this->nrRanduri; i++) {
			matriceLocuri[i] = new int[nrScauneRand];
		}
		for (int i = 0; i < this->nrRanduri; i++) {
			for (int j = 0; j < nrScauneRand; j++) {
				matriceLocuri[i][j] = this->matriceLocuri[i][j];
			}
		}
	}

	static int getNrLocatii() {
		return nrLocatii;
	}

	Locatie operator! () {  // inchid vanzarea de bilete

		this->maxLocuri = 0;
		return *this;
	}

	int operator==(Locatie l) { // compara numarul de locuri intre doua obiecte de tip Locatie
		if (this->maxLocuri == l.maxLocuri) return 0;
		else if (this->maxLocuri > l.maxLocuri) return 1;
		else return -1;
	}

	~Locatie() {
		if (this->matriceLocuri != nullptr) {
			for (int i = 0; i < nrRanduri; i++) {
				delete[] matriceLocuri[i];
			}
			delete[] matriceLocuri;
		}

		nrLocatii--;
	}

	friend istream& operator>>(istream& in, Locatie& l);
	friend ostream& operator<<(ostream& out, Locatie& l);
};

istream& operator>>(istream& in, Locatie& l) {
	string buffer;
	int i, bec=0;
	do {
		cout << "Introduceti numarul maxim de locuri al acestei locatii:  ";
		in >> buffer;
		for (i = 0; i < buffer.length(); i++) {
			if (isdigit(buffer[i]) == false)
				break;
		}
		if (i != buffer.length()) cout << "!--------Numarul introdus nu este de tip int! ----------! " << endl;
		else {
			l.maxLocuri = stoi(buffer);
			bec = 1;
		}
	} while (!bec); bec = 0;
	
	do {
		cout << "Introduceti denumirea locatiei (Minim 3 caractere):  ";
		in >> ws;
		getline(in, buffer);
	} while (!(buffer.length() > 2 && buffer.length() < 50));
	l.numeLocatie = buffer;


	do {
		cout << "Introduceti denumirea adresei locatiei (Minim 3 caractere):  ";
		in >> ws;
		getline(in, buffer);
	} while (!(buffer.length() > 2 && buffer.length() < 50));
	l.denumireAdresa = buffer;

	do {
		bec = 0;
		cout << "Introduceti nr de locuri pe rand al locatiei:  ";
		in >> ws >> buffer;
		for (i = 0; i < buffer.length(); i++) {
			if (isdigit(buffer[i]) == false)
				break;
		}

		if (i != buffer.length()){
			cout << "!--------Numarul introdus nu este de tip int! ----------! " << endl;
			bec = 1;
		}
		else if ((stoi(buffer) > l.maxLocuri) && !bec) { // am fost nevoit sa pun else if deoarece crapa stoi 
			cout << "!--------Ati introdus un numar mai mare decat cel alocat salii----------!" << endl;
			bec = 1;
		}
		

		if(!bec) l.nrScauneRand = stoi(buffer);
	} while (bec);

	if (l.maxLocuri % l.nrScauneRand == 0) l.nrRanduri = l.maxLocuri / l.nrScauneRand;
	else {
		l.nrRanduri = l.maxLocuri / l.nrScauneRand + 1;
		cout << "!!  Ultimul rand va contine mai putine locuri  !!" << endl;
	}

	return in;
}

ostream& operator<<(ostream& out, Locatie& l) {
	out << "------------------Detaliile locatiei "<< l.numeLocatie << "-----------------" << endl;
	out << "Numar maxim de locuri al salii: " << l.maxLocuri << endl;
	out << "Numele locatiei: " << l.numeLocatie << endl;
	out << "Adresa locatiei: " << l.denumireAdresa << endl;
	out << "Nr de randuri al salii: " << l.nrRanduri << endl;
	out << "Nr de scauni per rand: " << l.nrScauneRand << endl;
	out << "-----------------------------------------------------------"<< endl;
	
	return out;
}

int Locatie::nrLocatii = 0;