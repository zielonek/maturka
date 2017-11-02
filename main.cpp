#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    //---------------------------------------------------------------
    cout << "-------------ZADANIE 5.1-------------" << endl;

    string linia;
    int tab[1000];
    int a=0;
    int b=0;
    int c=0;
    int d=0;

    //ZADANIE 5.3//
    int sesja=0;
    int najwiecej=0;
    int najmniej=0;
    int wynik=0;
    //------------//

    fstream plik;
    plik.open("dziennik.txt", ios::in);

    while(!plik.eof()){
        getline(plik, linia);
        int x = atoi(linia.c_str());
        tab[a] = x;
        a++;
    }

    for(int i=0; i<a; i++){
        b = i;
        while(tab[b] < tab[b+1]){
            c++;
            b++;
        }
        //ZADANIE 5.3//
        if(sesja<c){
            sesja = c+1;
            najwiecej = tab[b];
            najmniej = tab[b - c];
            wynik = najwiecej - najmniej;
        }
        //------------//
        if(c>2){
            d++;
            i += c;
            c=0;
        }else{
            c=0;
        }
    }
    cout << "Ilosc pozytywnych sesji dluzszych niz 3 dni: " << d << endl;

    //---------------------------------------------------------------
    cout << "-------------ZADANIE 5.2-------------" << endl;

    int maxi=0;
    int mini=20000;

    for(int i=0; i<a; i++){
        if(maxi < tab[i]){
            maxi = tab[i];
        }
        if(mini > tab[i]){
            mini = tab[i];
        }
    }
    cout << "Dlugosc najdluzszego skoku: " << maxi << endl;
    cout << "Dlugosc najkrotszego skoku: " << mini << endl;

    //---------------------------------------------------------------
    cout << "-------------ZADANIE 5.3-------------" << endl;
    cout << "Najdluzsza pozytywna sesja treningowa: "<< sesja << endl;
    cout << "Poprawa wyniku w tej sesji o: " << wynik << endl;
    return 0;
}
