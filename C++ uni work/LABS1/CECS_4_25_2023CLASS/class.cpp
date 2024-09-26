#include <iostream>
using namespace std;
int main()
{
	double ex[10];
	int i;
	cout << "\nSe solicita a continuacion la nota del examen "
		<< "para sus 10 estudiantes:\n\n";
	for (i = 0; i < 10; i++)
	{
		cout << "Entre la nota del estudiante " << i + 1 << ": ";
		cin >> ex[i];
		while (ex[i] < 0.0 || ex[i]>100.0)
		{
			cout << "Nota del examen del estudiante "
				<< i + 1 << " inv. Re-entre: ";
			cin >> ex[i];
		}
	}
	cout << "\n\nLas notas entradas para los 10 estudiantes son:\n\n";
	for (i = 0; i < 10; i++)
	{
		cout << "\nLa nota del estudiante " << i + 1 << " es " << ex[i] << '\n';
	}
	cout << "\n\n";
	return 0;
}