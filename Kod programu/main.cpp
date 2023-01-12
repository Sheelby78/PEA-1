#include <iostream>
#include <chrono>
#include <thread>
#include "AdjacencyMatrix.h"
#include "BF.h"
#include "BB.h"
#include "DP.h"
#include "MenuTesty.h"
#include "Timer.h"

using namespace std;

void AlgorithmMenu();

AdjacencyMatrix mat = *(new AdjacencyMatrix());

//Głowne menu programu
int main(int, char**) {


    srand(time(NULL));
    bool koniec = false;
    char wybor;
    char temp;

    system("cls");

    while (!koniec) {

        system("cls");
        cout << " ============MENU============ " << endl;
        cout << "-----------------------------" << endl;
        cout << "1.  Wczytaj dane z pliku" << endl;
        cout << "2.  Automatyczne generowanie grafu" << endl;
        cout << "3.  Pomiar czasu" << endl;
        cout << "x.  Zamkniecie programu " << endl;
        cout << "-----------------------------" << endl;
        cout << "Wybor: ";
        cin >> wybor;

        switch (wybor) {
        case '1': {
            cout << "Podaj nazwe pliku do wczytania danych: ";
            string name;
            cin >> name;
            if (!mat.readMatrix(name)) {
                cout << endl << "Blad odczytu pliku" << endl;
                this_thread::sleep_for(std::chrono::milliseconds(1500));
            }
            else {
                cout << endl << "Pomyslnie wczytano plik" << endl;
                this_thread::sleep_for(std::chrono::milliseconds(1500));
                system("cls");
                AlgorithmMenu();
            }

            break;
        }
        case '2': {
            cout << "Podaj liczbe wierzcholkow: ";
            int N;
            cin >> N;
            mat.generateMatrix(N);
            cout << endl << "Pomyslnie wygenerowano graf" << endl;
            this_thread::sleep_for(std::chrono::milliseconds(1500));
            system("cls");
            AlgorithmMenu();
            break;
        }
        case '3': {
            system("cls");
            MenuTesty mt = *(new MenuTesty());
            mt.menuTestow();
            break;
        }
        case 'x':;	koniec = true; break;
        default: {
            cout << endl << "POMYLKA!" << endl;
            this_thread::sleep_for(std::chrono::milliseconds(1500));
            break;
        }
        }
    }
}

//Menu wyboru algorytmu 
void AlgorithmMenu() {

    Timer test = *(new Timer());
    bool koniec = false;
    char wybor;
    char temp;

    while (!koniec) {

        cout << " ============MENU============ " << endl;
        cout << "-----------------------------" << endl;
        cout << "1.  Przeglad zupelny (BF)" << endl;
        cout << "2.  Podzialy i ograniczenia (B & B)" << endl;
        cout << "3.  Programowanie Dynamiczne (DP)" << endl;
        cout << "4.  Wyswietl graf" << endl;
        cout << "x.  Powrot" << endl;
        cout << "-----------------------------" << endl;
        cout << "Wybor: ";
        cin >> wybor;


        switch (wybor) {
        case '1': {
            system("cls");
            BF bf = *(new BF());
            cout << "BRUTE FORCE" << endl;
            test.start();
            cout << bf.TSP(mat.getMatrix(), mat.getSize()) << endl;
            test.stop();
            bf.show();
            cout << endl;
            cout << test.timeCount() << " Microseconds";
            cout << endl << endl;
            break;
        }
        case '2': {
            system("cls");
            BB bb = *(new BB());
            cout << "BRANCH & BOUND" << endl;
            test.start();
            cout << bb.TSP(mat.getMatrix(), mat.getSize()) << endl;
            test.stop();
            bb.show();
            cout << endl;
            cout << test.timeCount() << " Microseconds";
            cout << endl << endl;
            break;
        }
        case '3': {
            system("cls");
            DP dp = *(new DP());
            cout << "DYNAMIC PROGRAMMING" << endl;
            test.start();
            cout << dp.TSP(mat.getMatrix(), mat.getSize()) << endl;
            test.stop();
            dp.show();
            cout << endl;
            cout << test.timeCount() << " Microseconds";
            cout << endl << endl;
            break;
        }
        case '4': {
            system("cls");
            mat.show();
            cout << endl << endl;
            break;
        }
        case 'x':;	koniec = true; break;
        default: {
            cout << endl << "POMYLKA!" << endl;
            this_thread::sleep_for(std::chrono::milliseconds(1500));
            break;
        }
        }
    }
}
