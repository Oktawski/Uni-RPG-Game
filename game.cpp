#include "pch.h"
#include <iostream>
#include "Player.h"
#include <stdio.h>
#include "Base.h"
using namespace std;
//Funkcje
void Menu();

int main()
{
	char choice;
	for (;;) {
		Menu();
		choice = getchar();
		switch (choice) {
		case '1': {
			Base b;
			break;
		}
		case'2': {
			cout << "This is my uni project and something i'm enjoying doing.";
			break;
		}
		case'3': {
			cout << "I hope you enjoyed.";
			exit(0);
		}
		}
		getchar(); getchar();
		system("cls");
	}
}

void Menu() {
	cout << "-------------------";
	cout << "\n\tLife\n\n";
	cout << "1. Start Game\n";
	cout << "2. About\n";
	cout << "3. Exit\n\n";
}

