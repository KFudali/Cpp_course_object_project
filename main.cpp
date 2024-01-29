#include <iostream>

#include "Gra.h"
#include "Pracownicy.h"

using namespace std;


int main()
{
    cout << "start gry" <<endl;
    Gra gra;

    while(gra.get_stan()== 1)
    {
        gra.akcja_gracza();
    }
}