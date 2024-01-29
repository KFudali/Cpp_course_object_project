#pragma once
#include <iostream>
#include "RandomNameGenerator.hpp"
#include <random>

using namespace std;


class Pracownik
{
    public:
        Pracownik()
        {
            imie = get_random_name();
        }
        virtual ~Pracownik(){}

        virtual void print() = 0
        {
            cout << imie;
        }
        string get_imie()
        {
            return imie;
        }
        double get_pensja()
        {
            return pensja;
        }
        void set_pensja(double p)
        {
            pensja = p;
        }
    private:
        string imie;
        double pensja;
};


class Inz : public Pracownik
{
    public:
        Inz()
        {        
            wydzial = get_random_faculty();
            set_pensja(5000);
        }
        void print() override
        {
            cout << "Inz " << get_imie() << ", wydzial " << wydzial << endl;
        }
    private:
        string wydzial;
        const double CInz = 2000;
};

class Mkt : public Pracownik
{
    public:
        Mkt()
        {
            set_pensja(3500);
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int>follows_rand(0,1000);
            follows = follows_rand(gen);
        }
        void print() override
        {
            cout << "Mkt " << get_imie() << ", follows " << follows << endl;
        }

    private:
        int follows;
        const double CMkt = 10;      

};

class Mag : public Pracownik
{
    public:
        Mag()
        {
            set_pensja(3000);
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int>obsl_widl_rand(0,1); 
            obsl_widl = obsl_widl_rand(gen);
        }
        void print() override
        {
            cout << "Mag " << get_imie() << ", obsl_widl " << obsl_widl << endl;
        }

    private:
        bool obsl_widl;
        const double CMag = 5;  
};

class Rob : public Pracownik
{
    public:
        Rob()
        {
            set_pensja(4000);
            random_device rd;
            mt19937 gen(rd());            
            uniform_real_distribution<double>but_rand(38, 45);
            but = but_rand(gen);
        }
        void print() override
        {
            cout << "Rob " << get_imie() << ", rozmiar buta " << but << endl;
        }

    private:
        double but;
        const double CRob = 3;  
};
