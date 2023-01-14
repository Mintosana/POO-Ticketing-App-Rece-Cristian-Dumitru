#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"

#include <iostream>
#include <string>
using namespace std;

int main() {

	/*char s[10] = "Buburuza";
	Bilet b1;
	Bilet b2("Rece", "Cristian", 6.99, s, "Rapsodia", 3, 7);
	Bilet b3(b2);
	Bilet b4("Antonio", "Cerefal", 12, s, "Sala de Cultura", 5, 2);

	b1 = b3;

	b1 + 10;
	10 + b2;
	b1 + b3;
	cin >> b1;
	cout << b1 << endl;

	cout << Bilet::getContorBilete();

	b2 -= 5;
	b2 -= 10;

	Bilet bilete[]{ b2, b4 };
	cout << Bilet::pretMediuBilete(bilete, 2) << endl;*/

	/*Locatie l1;
	Locatie l2(32,"Belvedere","Str Chibz",3);
	Locatie l5(34, "Belvedere", "Str Chibz", 5);
	Locatie l3=l2;
	Locatie l4(l2);

	l4 = l5;*/

	/*cout << (l1 == l2) << endl;
	cout<< (l2 == l3) << endl;
	cin >> l3;
	cout << l3;
	cout << Locatie::getNrLocatii();*/

	//int ** matrice = l4.getMatriceLocuri();
	//for (int i = 0; i < l5.getNrRanduri(); i++) {
	//	cout << endl;
	//	if (i == l5.getNrRanduri() - 1) {
	//		for (int j = 0; j < l5.getMaxLocuri()%l5.getNrScauneRand(); j++) {
	//			cout << matrice[i][j] << " ";
	//		}
	//	}
	//	else {
	//		for (int j = 0; j < l5.getNrScauneRand(); j++) {
	//			cout << matrice[i][j] << " ";
	//		}
	//	}
	//}
	
	

	

	/*Eveniment e1;
	Eveniment e2(10,12,2023, "12:33", "Mandalorian");
	Eveniment e3 = e2;

	e2.setOra("09:60");
	e2.setOra("33:30");
	e2.setOra("04.58");
	e2.setOra("04:59");

	cout << e2;
	cin >> e2;
	
	cout << e2.verificareAnBisect() << endl;

	e2.LowercaseDenumireEveniment();
	cout << e2.getDenumireEveniment();

	e1 = e2++;
	e1 = ++e2;

	e1 = e2--;
	e1 = --e2;*/

	Locatie l2(32, "Belvedere", "Str Chibz", 3);
	Locatie l5(34, "Belvedere", "Str Chibz", 5);
	Locatie l3 = l2;
	Locatie l4(l2);

	Eveniment e2(12, 10, 2024, "12:33", "Mandalorian",l5,cultural);
	Eveniment e3;
	Bilet b2("Rece", "Cristian", 6.99, "Rapsodia", 3, 7, e2);
	cout << e2;
	e2.scriereFisier("fisier.txt");
	e3.citireFisier("fisier.txt");
	e3.scriereFisier("fisier.txt");
}