#pragma once
#include <iostream>
#include "Pracownicy.h"


class Fabryka_pracownikow
{
    public:
        Fabryka_pracownikow(){}
        ~Fabryka_pracownikow(){}

        enum Pracownicy { inz, mkt, mag, rob};

        unique_ptr<Pracownik> stworz_pracownika(int enum_pracownika)
        {
            unique_ptr<Pracownik> ptr;
            switch (enum_pracownika)
            {
                case inz:
                {
                    unique_ptr<Inz> tmp = make_unique<Inz>();
                    ptr = move(tmp);
                    break;
                }
                case mkt:
                {
                    unique_ptr<Mkt> tmp = make_unique<Mkt>();
                    ptr = move(tmp);
                    break;
                }
                case mag:
                {
                    unique_ptr<Mag> tmp = make_unique<Mag>();
                    ptr = move(tmp);
                    break;
                }
                case rob:
                {
                    unique_ptr<Rob> tmp = make_unique<Rob>();
                    ptr = move(tmp);
                    break;
                }
            }
            return ptr;
        }
    private:
};