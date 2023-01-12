#include "MenuTesty.h"
#include "BF.h"
#include "BB.h"
#include "DP.h"
#include "Timer.h"
#include "AdjacencyMatrix.h"

//Menu do testowania algorytmow
void MenuTesty::menuTestow(){
    bool koniec = false;
	Timer test = *(new Timer());
	while (!koniec) {
		char wybor;
		cout << " TESTOWANIE ALGORYTMOW " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Brute Force" << endl;
        cout << "2.  Branch & Bound" << endl;
        cout << "3.  Dynamic Programming" << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{

		case '1': {
			system("cls");
			testyBF();
			break;
		}

        case '2': {
			system("cls");
			testyBB();
			break;
		}

        case '3': {
			system("cls");
			testyDP();
			break;
		}

		case 'x': {
			system("cls");
			koniec = true;
			break;
		}

		
		default: {
			system("cls");
			cout << endl << "POMYLKA!" << endl << endl;
			break;
		}
		}
	}
}

//menu testow brute force
void MenuTesty::testyBF(){
	bool koniec = false;
	Timer test = *(new Timer());
	while (!koniec) {
		char wybor;
		cout << " TESTOWANIE BRUTE FORCE " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Test" << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{

		case '1': {
			system("cls");
			long count = 0;
			int v;
			double d;

			cout << endl << "Podaj liczbe miast: ";
			cin >> v;
			cout << endl << "Podaj ilosc testow: ";
			cin >> d;

			AdjacencyMatrix mat = *(new AdjacencyMatrix());
            BF bf = *(new BF());

			for (int i = 0; i < d; i++) {
				mat.generateMatrix(v);
				test.start();
				bf.TSP(mat.getMatrix(),mat.getSize());
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania algorytmu Brute Force: " << count / d << endl << endl;
			break;
		}

		case 'x': {
			system("cls");
			koniec = true;
			break;
		}

		
		default: {
			system("cls");
			cout << endl << "POMYLKA!" << endl << endl;
			break;
		}
		}
	}
}

//menu testow branch and bound
void MenuTesty::testyBB() {
	bool koniec = false;
	Timer test = *(new Timer());
	while (!koniec) {
		char wybor;
		cout << " TESTOWANIE BRANCH & BOUND " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Test" << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{

		case '1': {
			system("cls");
			long count = 0;
			int v;
			double d;

			cout << endl << "Podaj liczbe miast: ";
			cin >> v;
			cout << endl << "Podaj ilosc testow: ";
			cin >> d;

			AdjacencyMatrix mat = *(new AdjacencyMatrix());
            BB bb = *(new BB());

			for (int i = 0; i < d; i++) {
				mat.generateMatrix(v);
				test.start();
				bb.TSP(mat.getMatrix(),mat.getSize());
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania algorytmu Branch & Bound: " << count / d << endl << endl;
			break;
		}

		case 'x': {
			system("cls");
			koniec = true;
			break;
		}

		
		default: {
			system("cls");
			cout << endl << "POMYLKA!" << endl << endl;
			break;
		}
		}
	}
}

//menu testow dynamicznego programowania
void MenuTesty::testyDP(){
	bool koniec = false;
	Timer test = *(new Timer());
	while (!koniec) {
		char wybor;
		cout << " TESTOWANIE DYNAMIC PROGRAMMING " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Test" << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{

		case '1': {
			system("cls");
			long count = 0;
			int v;
			double d;

			cout << endl << "Podaj liczbe miast: ";
			cin >> v;
			cout << endl << "Podaj ilosc testow: ";
			cin >> d;

			AdjacencyMatrix mat = *(new AdjacencyMatrix());
            DP dp = *(new DP());

			for (int i = 0; i < d; i++) {
				mat.generateMatrix(v);
				test.start();
				dp.TSP(mat.getMatrix(),mat.getSize());
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania algorytmu Dynamic Programming: " << count / d << endl << endl;
			break;
		}

		case 'x': {
			system("cls");
			koniec = true;
			break;
		}

		
		default: {
			system("cls");
			cout << endl << "POMYLKA!" << endl << endl;
			break;
		}
		}
	}
}