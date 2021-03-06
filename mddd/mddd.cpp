// mddd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
using namespace std;

void setTextColor(int Color)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, Color);
}
int getMin(int A[], int N) {
	int Min = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		if (Min > A[i]) Min = A[i];
	}
	return Min;
}

int getMax(int A[], int N) {
	int Max = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		if (Max < A[i]) Max = A[i];
	}
	return Max;
}

void fillArray(int A[], int N, int Min, int Max) {
	for (int i = 0; i < N; i++)
	{
		int rad = rand() % (Max - Min + 1) + Min;
		A[i] = rad;
	}
}

void showArrayExtremums(int A[], int N)
{
	int Max = getMax(A, N);
	int Min = getMin(A, N);
	
	setTextColor(7);

	for (int i = 0; i < N; i++)
	{
		if (i % 10 == 0) cout << endl;
			else cout << setw(5);

		if (A[i] == Max) {
			setTextColor(4);
			cout << A[i];
			setTextColor(7);
			continue;
		}
		if (A[i] == Min) {
			setTextColor(3);
			cout << A[i];
			setTextColor(7);
			continue;
		}
		cout << A[i] ;
	}

}

int main()
{
	srand(time(NULL));
	int N;
	cout << "Enter N = "; cin >> N;
	int *b = new int[N];
	fillArray(b, N, 0, 99);	
	showArrayExtremums(b, N);

}