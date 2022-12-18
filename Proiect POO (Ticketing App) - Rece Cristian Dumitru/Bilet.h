#include <string>
#include <iostream>
using namespace std;



class Bilet {
private:
	string nume;
	string prenume;
	float pret;
	char* spectacol;
	string sala;  // Sala va fi ulterior luata din clasa eveniment (work in progress)
	int rand;
	int loc;

	const int id;
	static int contorBilete;

public:

	Bilet() : id(++contorBilete) {
		nume = "";
		prenume = "";
		pret = -1;
		spectacol = nullptr;
		sala = "";
		rand = 0;
		loc = 0;
	}

	Bilet(string nume, string prenume, float pret, char* spectacol, string sala, int rand, int loc) : id(++contorBilete) {
		this->nume = nume;
		this->prenume = prenume;
		if(pret < 0) this->pret = pret * (-1);
		else this->pret = pret;
		this->sala = sala;
		this->rand = rand;
		this->loc = loc;
		if (spectacol != nullptr && strlen(spectacol) > 0) {
			delete[] this->spectacol;
			this->spectacol = new char[strlen(spectacol) + 1];
			strcpy_s(this->spectacol, strlen(spectacol) + 1, spectacol);
		}
		else {
			this->spectacol = nullptr;
		}
	}

	Bilet(const Bilet& b) : id(++contorBilete) {
		this->nume = b.nume;
		this->prenume = b.prenume;
		this->pret = b.pret;
		this->sala = b.sala;
		this->rand = b.rand;
		this->loc = b.loc;

		if (b.spectacol != nullptr) {
			this->spectacol = new char[strlen(b.spectacol) + 1];
			strcpy_s(this->spectacol, strlen(b.spectacol) + 1, b.spectacol);
		}
	}

	Bilet& operator=(Bilet& b) {
		if (this != &b) {
			if (this->spectacol != nullptr) {
				delete[] this->spectacol;
			}
			if (b.spectacol != nullptr) {
				this->spectacol = new char[strlen(b.spectacol) + 1];
				strcpy_s(this->spectacol, strlen(b.spectacol) + 1, b.spectacol);
			}
		}
		this->nume = b.nume;
		this->prenume = b.prenume;
		this->pret = b.pret;
		this->sala = b.sala;
		this->rand = b.rand;
		this->loc = b.loc;

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

	char* getSpectacol() {
		if (spectacol != nullptr) {
			char* copy = new char[strlen(spectacol) + 1];
			strcpy_s(copy, strlen(spectacol) + 1, spectacol);
			return copy;
		}
		return nullptr;
	}
	void setSpectacol(const char* spectacol) {
		if (spectacol != nullptr) {
			delete[] this->spectacol;
		}
		this->spectacol = new char[strlen(spectacol) + 1];
		strcpy_s(this->spectacol, strlen(spectacol) + 1, spectacol);
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
		if (spectacol != nullptr) delete[] this->spectacol;
		contorBilete--;
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
	char buffer[50];
	in.get();
	in.getline(buffer, 50);
	b.setSpectacol(buffer);
	cout << "Introduceti denumirea salii in care spectacolul are loc: ";
	//in.get();
	in.getline(buffer, 50);
	b.sala = buffer;


	
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
	out << "------------------Detalii bilet cu ID-ul " << b.id << "-----------------" << endl;
	out << "Nume detinator bilet: " << b.nume << endl;
	out << "Prenume detinator bilet: " << b.prenume << endl;
	out << "Pret bilet: " << b.pret << endl;
	out << "Denumire spectacol aferent biletului: ";
	if (b.spectacol != nullptr) {
		out << b.spectacol << endl;
	}
	else out << "Nu se poate identifica numele spectacolului";
	out << "Sala in care spectacolul are parte: " << b.sala << endl;
	out << "Randul aferent biletului: " << b.rand << endl;
	out << "Locul aferent biletului: " << b.loc << endl;

	out << "-----------------------------------------------------------";

	return out;
}

int Bilet::contorBilete = 0;


