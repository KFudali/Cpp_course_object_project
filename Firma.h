#pragma once
#include <iostream>
#include "Gra.h"
#include "Kredyt.h"
#include "Pracownicy.h"
#include "Fabryka_pracownikow.h"

using namespace std;


class Firma
{
    public:
        enum Pracownicy { inz, mkt, mag, rob};
        Firma()
        {
            cout << "tworze firme" << endl;
            stan_konta = 20000;

            fabryka = new Fabryka_pracownikow;

            n_mag = 0; n_inz = 0; n_mkt = 0; n_rob =0; n_prac = 0;
            zatrudnij_pracownika(inz);
            zatrudnij_pracownika(mkt);
            zatrudnij_pracownika(mag);
            zatrudnij_pracownika(rob);



            poj_magazynu = n_mag * CMag;
            n_kredytow = 0;
            stan_magazynu = 0;

            for (int i = 0; i <3; i++)
            {
                historia_przychodow.push_back(0);
            }
        }
        void zaplac_wynagrodzenie()
        {
            for(auto it = prac.begin(); it != prac.end(); ++it)
            {
                stan_konta = stan_konta - it->get()->get_pensja();
            }
        }
        double oblicz_przychod()
        {
            double przychod;
            double cena = n_inz * CInz;
            int popyt = n_mkt * CMkt;
            poj_magazynu = n_mag * CMag;
            stan_magazynu = min(poj_magazynu, n_rob * CRob + stan_magazynu);
            przychod  = min(popyt, stan_magazynu) * cena;
            stan_magazynu = stan_magazynu - min(popyt, stan_magazynu);

            return przychod;
        }
        void otrzymaj_przychod()
        {
            stan_konta = stan_konta + oblicz_przychod();
            historia_przychodow.insert(historia_przychodow.begin(), oblicz_przychod());
            historia_przychodow.pop_back();
        }
        void splac_raty()
        {

            for(auto it = kredyty.begin(); it != kredyty.end(); it++)
            {
                stan_konta = stan_konta - it->get()->get_rata();
                cout << "splacono rate wysokosci " <<  it->get()->get_rata() << " kredytu nr " << (it - kredyty.begin()) +1 << endl;
                it->get()->set_czas_splaty(it->get()->get_czas_splaty() - 1);
                if (it->get()->get_czas_splaty() == 0)
                {
                    cout << "splacono kredyt nr " << (it - kredyty.begin()) +1 << endl;
                    it = kredyty.erase(it);
                    n_kredytow--;
                }
                else
                {
                    cout << "do splaty zostalo " << it->get()->get_czas_splaty() << " rat" << endl;
                }
                if (n_kredytow == 0)
                {
                    break;
                }
            }
        }

        double get_stan_konta()
        {
            return stan_konta;
        }
        double wartosc_firmy()
        {
            double wartosc = 0;
            for(auto it = historia_przychodow.begin(); it != historia_przychodow.end(); ++it)
            {
                 wartosc = wartosc + *it;
            }
            return wartosc;
        }

        void wez_kredyt()
        {
            ++n_kredytow;
            unique_ptr<Kredyt> kredyt = make_unique<Kredyt>();
            kredyty.push_back(move(kredyt));
        }


        void zatrudnij_pracownika(int enum_pracownika)
        {
            ++n_prac;                
            unique_ptr<Pracownik> ptr;
            switch (enum_pracownika)
            {
                case inz:
                {
                    ptr = this->fabryka->stworz_pracownika(inz);
                    n_inz++;
                    break;
                }
                case mkt:
                {
                    ptr = this->fabryka->stworz_pracownika(mkt);
                    n_mkt++;
                    break;
                }
                case mag:
                {
                    ptr = this->fabryka->stworz_pracownika(mag);
                    n_mag++;
                    break;
                }
                case rob:
                {
                    ptr = this->fabryka->stworz_pracownika(rob);
                    n_rob++;
                    break;
                }

            }
             prac.push_back(move(ptr)); 
        }

        void drukuj_pracownikow()
        {
            for(auto it = prac.begin(); it != prac.end(); ++it)
            {
                it->get()->print();
            }
        }
        
        void drukuj_stan_firmy()
        {
            cout << "stan konta wynosi " << get_stan_konta() << endl;
            if(n_kredytow  == 1)
                {
                cout << "masz " << n_kredytow << " kredyt" << endl;
                }
            else
                {
                cout << "masz " << n_kredytow << " kredytow" << endl;
                }

            for(auto it = kredyty.begin(); it != kredyty.end(); ++it)
            {
                cout << "kredyt " << it - kredyty.begin() + 1 << ". Do splaty pozostalo " << it->get()->get_czas_splaty() << " rat wysokosci " <<  it->get()->get_rata() << endl;
            }
            cout << "magazyn ma pojemnosc " << poj_magazynu << endl;
            cout << "w magazynie jest " << stan_magazynu << " produktow" << endl;
            cout << "obecnie produkujesz " << n_rob * CRob << " produktow na ture" << endl;
            cout << "obecny popyt na wynosi " << n_mkt * CMkt << " produktow na ture" << endl;
            cout << "cena sprzedazy jednego produktu wynosi " << n_inz * CInz <<endl;
            cout << "szacowany przychod wynosi " << oblicz_przychod()<< endl;

            double koszt = 0;
            for(auto it = prac.begin(); it != prac.end(); ++it)
            {
                koszt = koszt + it->get()->get_pensja();
            }
            cout << "koszt utryzmania pracownikow " << koszt << endl;
        }

    private:

        const double CInz = 2000;
        const int CMkt = 10;
        const int CMag = 5;
        const int CRob = 3;

        int n_inz;
        int n_mkt;
        int n_mag;
        int n_rob;

        double stan_konta;
        int poj_magazynu;
        int stan_magazynu;

        int n_prac;
        vector<unique_ptr<Pracownik>> prac;
        Fabryka_pracownikow *fabryka;


        int n_kredytow; vector<unique_ptr<Kredyt>> kredyty;

        const int N = 3;
        vector<double> historia_przychodow;

};