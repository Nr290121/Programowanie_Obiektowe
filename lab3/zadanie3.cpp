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

class listaObecnosci{
    private:
        Osoba *tabOsoba[10]={nullptr};
        bool tabObecnosc[10]={false};
    public:
        void dodajOsobe(Osoba* o){
            for(int i=0;i<10;i++){
                if(tabOsoba[i]==nullptr){
                    tabOsoba[i] = o;
                    break;
                }
            }
        }
        
        void ustawObecnosc(int indeks){
            for(int i=0;i<10;i++){
                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNrIndeks()==indeks){
                    tabObecnosc[i] = !tabObecnosc[i];
                    break;
                }
            }
        }
        
        void wyswietlListe(){
            for(int i=0;i<10;i++){
                if(tabOsoba[i]!=nullptr){
                    cout << tabOsoba[i]->getNrIndeks() << " "
                         << tabOsoba[i]->getImie() << " "
                         << tabOsoba[i]->getNazwisko() << " "
                         << (tabObecnosc[i] ? "Obecny" : "Nieobecny")
                         << endl;
                }
            }
        }
        
        void usunOsobe(int id){
            for(int i=0;i<10;i++){
                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNrIndeks()==id){
                    tabOsoba[i] = nullptr;
                    break;
                }
            }
        }
};

class InterfejsUzytkownika{
    public:
        InterfejsUzytkownika(Osoba *tab1,int licz1,listaObecnosci *tab2,int licz2){
            this->tabOsoba = tab1;
            this->iloscOsob = licz1;
            this->tabList = tab2;
            this->iloscList = licz2;
        }
        void loop(){
            int id,idListy,indeks,wybor=0;
            string tekst;
            Osoba podana;
            while(wybor!=8){
                cout << "Wybierz co chcesz zrobic:" << endl;
                cout << "1 - dodac osobe\n";
                cout << "2 - dodac osobe do listy\n";
                cout << "3 - ustawic obecnosc\n";
                cout << "4 - zmienic dane\n";
                cout << "5 - usunac osobe z listy\n";
                cout << "6 - usunac osobe\n";
                cout << "7 - wyswietlic liste\n";
                cout << "8 - wyjsc\n";
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
                        dodajOsobe(podana);
                        break;
                
                    case 2:
                        cout << "Podaj numer id osoby jaka chcesz dodac:";
                        cin >> id;
                        cout << "Podaj numer id listy do jakiej chcesz dodac dana osobe(0-" << iloscList-1 << "):";
                        cin >> idListy;
                        if(idListy>=0 && idListy<iloscList){
                            for(int i=0;i<iloscOsob;i++){
                                if(tabOsoba[i].getNrIndeks()==id){
                                    Osoba* o = &tabOsoba[i];
                                    tabList[idListy].dodajOsobe(o);
                                    break;
                                }
                            }
                        }
                        break;
                    
                    case 3:
                        cout << "Podaj numer id osoby jaka chcesz znalesc:";
                        cin >> id;
                        cout << "Podaj numer id listy w jakiej chcesz zrobic zmiane(0-" << iloscList-1 << "):";
                        cin >> idListy;
                        tabList[idListy].ustawObecnosc(id);
                        break;
                        
                    case 4:
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
                        zmienElement(id,podana);
                        break;
                        
                    case 5:
                        cout << "Podaj numer id osoby ktora chcesz usunac:";
                        cin >> id;
                        cout << "Podaj numer id listy w jakiej chcesz tego dokonac(0-" << iloscList-1 << "):";
                        cin >> idListy;
                        tabList[idListy].usunOsobe(id);
                        break;
                    
                    case 6:
                        cout << "Podaj numer id osoby ktora chcesz usunac:";
                        cin >> id;
                        for(int i=0;i<iloscList;i++){
                            tabList[i].usunOsobe(id);
                        }
                        usunOsobe(id);
                        break;
                    
                    case 7:
                        cout << "Podaj numer id listy jaka chcesz wyswietlic(0-" << iloscList-1 << "):";
                        cin >> idListy;
                        cout << "\nLista " << idListy << ":\n";
                        tabList[idListy].wyswietlListe();
                        break;
                }
            }
        }
    private:
        Osoba *tabOsoba;
        int iloscOsob;
        listaObecnosci *tabList;
        int iloscList;
        
        void dodajOsobe(Osoba nowa){
            for(int i=0;i<iloscOsob;i++){
                if(tabOsoba[i].getNrIndeks()==0){
                    tabOsoba[i] = nowa;
                    break;
                }
            }
        }
        
        void zmienElement(int id, Osoba zmiana){
            for(int i=0;i<iloscOsob;i++){
                if(tabOsoba[i].getNrIndeks()==id){
                    tabOsoba[i] = zmiana;
                    break;
                }
            }
        }
        
        void usunOsobe(int id){
            for(int i=0;i<iloscOsob;i++){
                if(tabOsoba[i].getNrIndeks()==id){
                    tabOsoba[i] = Osoba();
                    break;
                }
            }
        }
};

int main(){
    Osoba tabOsoba[10];
    listaObecnosci tabList[2];
    int iloscOsob,iloscList;
    InterfejsUzytkownika ui(tabOsoba,10,tabList,2);
    ui.loop();
    return 0;
}
