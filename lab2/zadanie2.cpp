#include <iostream>
#include <string>

using namespace std;

class Osoba{
    private:
        string imie="";
        string nazwisko="";
        int nr_indeks=0;
    public:
        void setImie(string war){
            imie=war;
        }
        void setNazwisko(string war){
            nazwisko=war;
        }
        void setNrIndeks(int war){
            nr_indeks=war;
        }
        string getImie(){
            return imie;
        }
        string getNazwisko(){
            return nazwisko;
        }
        int getNrIndeks(){
            return nr_indeks;
        }
};

void dodajOsobe(Osoba *tab[], Osoba nowa){
    for(int i=0;i<10;i++){
        if(tab[i]==nullptr){
            tab[i] = new Osoba;
            tab[i]->setNrIndeks(nowa.getNrIndeks());
            tab[i]->setImie(nowa.getImie());
            tab[i]->setNazwisko(nowa.getNazwisko());
            break;
        }
    }
}

void ustawObecnosc(Osoba *tab1[], int id, bool *tab2){
    for(int i=0;i<10;i++){
        if(tab1[i]!=nullptr && tab1[i]->getNrIndeks()==id){
            tab2[i] = !tab2[i];
            break;
        }
    }
}

void zmienElement(Osoba *tab[], int id, Osoba zmiana){
    for(int i=0;i<10;i++){
        if(tab[i]!=nullptr && tab[i]->getNrIndeks()==id){
            if(zmiana.getNrIndeks()!=0){
                tab[i]->setNrIndeks(zmiana.getNrIndeks());
            }
            if(zmiana.getImie()!="old"){
                tab[i]->setImie(zmiana.getImie());
            }
            if(zmiana.getNazwisko()!="old"){
                tab[i]->setNazwisko(zmiana.getNazwisko());
            }
            break;
        }
    }
}

void usunOsobe(Osoba *tab1[], int id,bool *tab2){
    for(int i=0;i<10;i++){
        if(tab1[i]!=nullptr && tab1[i]->getNrIndeks()==id){
            delete tab1[i];
            tab1[i]=nullptr;
            tab2[i]=false;
            break;
        }
    }
}

void wyswietlListe(Osoba *tab1[],bool *tab2){
    for(int i=0;i<10;i++){
        if(tab1[i]!=nullptr){
            cout << tab1[i]->getNrIndeks() << " "
                 << tab1[i]->getImie() << " "
                 << tab1[i]->getNazwisko() << " "
                 << tab2[i] << endl;
        }
    }
}

int main(){
    Osoba *tabOsoba[10] = {nullptr};
    Osoba podana;
    bool tabObecnosc[10]={false};
    int id,indeks,wybor=0;
    string tekst;

    while(wybor!=6){
        cout << "Wybierz co chcesz zrobic:" << endl;
        cout << "1 - dodac osobe\n";
        cout << "2 - ustawic obecnosc\n";
        cout << "3 - zmienic dane\n";
        cout << "4 - usunac osobe\n";
        cout << "5 - wyswietlic liste\n";
        cout << "6 - wyjsc\n";
        cout << "Wybierz:";
        cin >> wybor;
        switch(wybor)
        {
            case 1:
                cout << "Podaj numer indeksu:";
                cin >> indeks;
                podana.setNrIndeks(indeks);
                cout << "Podaj imie:";
                cin >> tekst;
                podana.setImie(tekst);
                cout << "Podaj nazwisko:";
                cin >> tekst;
                podana.setNazwisko(tekst);
                dodajOsobe(tabOsoba,podana);
                break;
        
            case 2:
                cout << "Podaj numer id osoby jaka chcesz znalesc:";
                cin >> id;
                ustawObecnosc(tabOsoba,id,tabObecnosc);
                break;
            
            case 3:
                cout << "Podaj numer id osoby ktora chcesz zmienic:";
                cin >> id;
                cout << "Podaj numer indeksu:";
                cin >> indeks;
                podana.setNrIndeks(indeks);
                cout << "Podaj imie:";
                cin >> tekst;
                podana.setImie(tekst);
                cout << "Podaj nazwisko:";
                cin >> tekst;
                podana.setNazwisko(tekst);
                zmienElement(tabOsoba,id,podana);
                break;
                
            case 4:
                cout << "Podaj numer id osoby ktora chcesz usunac:";
                cin >> id;
                usunOsobe(tabOsoba,id,tabObecnosc);
                break;
                
            case 5:
                wyswietlListe(tabOsoba,tabObecnosc);
                break;
        }
    }

    for(int i=0;i<10;i++){
        delete tabOsoba[i];
    }

    return 0;
}
