#pragma once
#include <iostream>
#include "Kredyt.h"

using namespace std;


class Kredyt
{   
    public:
        Kredyt()
        {
            while(kwota < 0 || kwota > 30000)
            {


            cout << "podaj kwote kredytu" << endl;
            cin >> kwota;
            while(cin.fail())
            {
                cout << "Podaj liczbe typu double" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> kwota;
            }
            if(kwota < 0 || kwota > 30000)
            {
                cout << "kwotaty musi byc mniejsza niz 30 000 i wieksza od 0"<< endl;
            }

            }
            czas_splaty = 11;

            while (czas_splaty > 10 || czas_splaty < 0)
            {
                cout << "podaj czas platy kredyt (dni)" << endl;
                cin >> czas_splaty;
                while(cin.fail())
                {
                    cout << "Podaj liczbe typu int" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> czas_splaty;
                }
                if(czas_splaty > 10 || czas_splaty < 0)
                {
                    cout << "czas splaty musi byc mniejszy niz 10 i wiekszy od 0"<< endl;
                }
                
            }

            rata = kwota * (1 + static_cast<double>(czas_splaty)/10) / czas_splaty;

            cout << "zaciagnieto kredyt wysokosci "  << kwota << endl;
            cout << "do splacenia " << czas_splaty << " rat wysokosci " << rata << endl;
            
        }
        double get_kwota()
        {
            return kwota;
        }
        void set_kwota(double n_kwota)
        {
            kwota = n_kwota;
        }
        int get_czas_splaty()
        {
            return czas_splaty;
        }
        void set_czas_splaty(int n_czas_splaty)
        {
            czas_splaty = n_czas_splaty;
        }
        double get_rata()
        {
            return rata;
        }
    private:
        double rata;
        double kwota;
        int czas_splaty;
};