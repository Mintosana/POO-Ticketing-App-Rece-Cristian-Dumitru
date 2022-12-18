#pragma once
#include <string>
#include <iostream>
using namespace std;

class Eveniment {
private:
	
	int zi;
	int luna;
	int an;
	string ora;
	string denumireEveniment;

public:

	Eveniment() {
		an = 0;
		luna = 0;
		zi = 0;
		ora = "";
		denumireEveniment = "";
	};

	Eveniment(int zi,int luna,int an, string ora, string denumireEveniment) {
		if(an > 2021) this->an = an;
		if(luna> 0 && luna < 13) this->luna = luna;
		if (zi > 0 && zi < 31) this->zi = zi; // aici e mult mai complicat, voi modifica pe parcurs
		this->ora = ora;
		this->denumireEveniment = denumireEveniment;
	}

	int getZi() {
		return zi;
	}
	void setZi(int zi) {
		if (zi > 0 && zi < 31) {
			this->zi = zi;
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
	int setAn() {
		if (an > 2021) this->an = an;
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

	string getDenumireEveniment() {
		return denumireEveniment;
	}
	void setDenumireEveniment(string denumire) {
		if (denumire != "") {
			denumireEveniment = denumire;
		}
		else cout << "Introduceti o denumire valida pentru Adresa" << endl;
	}

	bool verificareAnBisect() {
		if (an % 4 == 0) return 1;
		else return 0;
	}

	void LowercaseDenumireEveniment() {
		for (int i = 0; i < denumireEveniment.length(); i++) {
			denumireEveniment[i] = tolower(denumireEveniment[i]);
		}

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

	friend ostream& operator<<(ostream& out, const Eveniment& e);
	friend istream& operator>>(istream& in, Eveniment& e);
};

ostream& operator<<(ostream& out, const Eveniment& e) {
	out << endl << "---------------Detaliile evenimentului " << e.denumireEveniment << "--------------" << endl;
	out << "Evenimentul va avea loc pe data de " << e.zi << "-" << e.luna << "-" << e.an << " la ora " << e.ora<< endl;
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

	return in;
}