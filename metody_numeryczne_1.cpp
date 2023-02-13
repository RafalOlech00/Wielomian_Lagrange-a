#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	// odczytanie z pliku tekstowego danych 
	fstream read;
	int size = 0;
	read.open("plik_tekstowy.txt"); // otwarcie pliku tekstowego
	read >> size;
	cout << "Rozmiar: " << size << endl;

	// tablice przechowywujące węzły i ich wartości
	int* TabNode = new int[size];
	float* TabValue = new float[size];

	for (int i = 0; i < size; i++)
	{
		read >> TabNode[i];
		read >> TabValue[i];
	}
	read.close(); // zamknięcie pliku tekstowego


	float x;
	cout << "Podaj punkt: ";
	cin >> x;

	float result = 0.0;

	for (int i = 0; i < size; i++)
	{
		float sum = 1.0;

		for (int j = 0; j < size; j++)
		{
			if (j != i)
			{
				sum *= (x - TabNode[j]) / (TabNode[i] - TabNode[j]);
			}
		}
		result += (sum * TabValue[i]);
	}

	cout << "WYNIKI" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Node: " << i << ":" << TabNode[i] << "," << TabValue[i] << endl;
	}
	cout << "Interpolowany punkt:" << result << endl;

}

