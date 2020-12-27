// ConsoleApplication2.cpp : main project file.

#include "stdafx.h"

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>

#include <conio.h>
#include <iomanip>
using namespace System;
using namespace std;


int ingresapositivo()
{
	int num;
	do
	{

		cout << "ingresae positivo"; cin >> num;
	} while (num <= 0 || num > 200);
	return num;
}
void asignavalores(int *n, int*vector)
{

	for (int i = 0; i < *n - 1; i++)
		vector[i] = i + 2;

}

void imprimirarreglo(int *n, int*vector)
{
	cout << endl << "datod drl vector" << endl;
	for (int i = 0; i < *n - 1; i++)
		cout << vector[i] << "  ";
}

void eliminanoprimos(int *n, int*vector)
{
	int n1 = *n;
	for (int i = 0; i < *n - 1; i++)
		if (vector[i] != -1 && pow(vector[i], 2) < *n)
			for (int j = 1; j < *n - 1; j++)
				if (vector[j] >= pow(vector[i], 2) && vector[j] % vector[i] == 0)
				{
					vector[j] = -1;

					imprimirarreglo(&n1, vector);
				}
}

int main()
{
	int n = ingresapositivo();
	int *vector;
	vector = new int[n - 1];
	asignavalores(&n, vector);
	imprimirarreglo(&n, vector);
	eliminanoprimos(&n, vector);
	imprimirarreglo(&n, vector);
	delete[]vector;
	_getch();

}