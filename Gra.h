#pragma once
#include <iostream>

#include "Firma.h"

using namespace std;

class Gra
{
    public:

        enum Pracownicy { inz, mkt, mag, rob};

        Gra()
        {
            stan = 1;
            firma = new Firma;
        }
        ~Gra()
        {
            delete firma;
        }
        void set_stan(bool s)
        {
            stan = s;
        }
        bool get_stan()
        {
            return stan;
        }
        void akcja_gracza()
        {

            cout << "waiting for player action, availble actions:" << endl;
            cout << "1. zatrudnij Inz" << endl;
            cout << "2. zatrudnij Mkt" << endl;
            cout << "3. zatrudnij Mag" << endl;
            cout << "4. zatrudnij Rob" << endl;
            cout << "5. zaciagnij kredyt" << endl;
            cout << "6. wyswietl pracownikow" << endl;
            cout << "7. drukuj stan firmy" << endl;
            cout << "8. zakoncz ture" << endl;
            cout << "9. zakoncz gre" << endl;

            int akcja = 0;

            while (akcja < 1 || akcja > 9)
            {
            cin >> akcja;
            while(cin.fail())
            {
                cout << "Podaj liczbe typu int" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> akcja;
            }

            switch (akcja)
            {
            case 1:
                {
                this->firma->zatrudnij_pracownika(inz);
                cout << "zatrudniono inz" << endl;
                break;
                }
            case 2:
                {
                this->firma->zatrudnij_pracownika(mkt);
                cout << "zatrudniono mkt" << endl;
                break;
                }
            case 3:
                {
                this->firma->zatrudnij_pracownika(mag);
                cout << "zatrudniono mag" << endl;
                break;
                }
            case 4:
                {
                this->firma->zatrudnij_pracownika(rob);
                cout << "zatrudniono rob" << endl;
                break;
                }
            case 5:
                this->firma->wez_kredyt();
                break;
            case 6:
                this->firma->drukuj_pracownikow();
                break;
            case 7:
                this->firma->drukuj_stan_firmy();
                break;
            case 8:
                cout << "wartosc firmy wynosi " << this->firma->wartosc_firmy() << endl;
                koniec_tury();
                break;
            case 9:
                cout << "koniec gry" << endl;       
                set_stan(0);
            }

            if(akcja < 1 || akcja > 9)
            {
                cout << "wybierz akcje z zakresu 1 - 9" << endl;
            }
            }
        }
        void koniec_tury()
        {
            this->firma->otrzymaj_przychod();
            this->firma->zaplac_wynagrodzenie();
            this->firma->splac_raty();

            if (this->firma->wartosc_firmy() > 1000000)
            {
                cout << "wartosc firmy wynosi " << this->firma->wartosc_firmy() << " Gratulacje";
                stan = 0;
            }
            if (this->firma->wartosc_firmy() < -50000)
            {
                cout << "wartosc firmy wynosi " << this->firma->wartosc_firmy() << " Przegrana";
                stan = 0;
            }
        }

    private:
        Firma *firma;
        bool stan;
};