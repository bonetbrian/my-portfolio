#include <iostream>
#include <fstream>
using namespace std;

/*int main() {
	ofstream file;
	double numero;
	int cantidad;

	file.open("boomer.txt");
	if (file.fail())
		cout << "ERROR: no se pudo abrir el archivo "
		<< "numer.txt" << endl;

	else {
		cout << "Cuantos numeros guardara en el archivo: ";
		cin >> cantidad;
		for (int i = 1; i <= cantidad; i++) {
			cout << "Entre cualquier numero: ";
			cin >> numero;
			file << numero << endl;
		}
		file.close();

	}
	return(0);
}
*/

/*int main() {
	ofstream file;
	double numero;
	int cantidad;

	file.open("boomer.txt",ios::binary);
	if (file.fail())
		cout << "ERROR: no se pudo abrir el archivo "
		<< "numer.txt" << endl;

	else {
		cout << "Cuantos numeros guardara en el archivo: ";
		cin >> cantidad;
		for (int i = 1; i <= cantidad; i++) {
			cout << "Entre cualquier numero: ";
			cin >> numero;
			file << numero << endl;
		}
		file.close();

	}
	return 0;
}*/

int main() {
	ifstream file;
	double numero;
	file.open("boomer.txt");
	if (file.fail())
		cout << "ERROR: No se pude abrir el archivo"
		<< "boomer.txt" << endl;
	else {
		file >> numero;
		while (!file.eof()) {
			cout << numero << endl;
			file >> numero;
		}
		file.close();
	}
	return (0);
}