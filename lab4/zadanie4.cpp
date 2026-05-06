#include <iostream>
#include <string>

using namespace std;

class Osoba{
    private:
        string imie="";
        string nazwisko="";
    public:
        virtual ~Osoba() = default;

        void setImie(string war){
            imie=war;
        }
        void setNazwisko(string war){
            nazwisko=war;
        }
        string getImie(){
            return imie;
        }
        string getNazwisko(){
            return nazwisko;
        }
        virtual void drukuj(){
            cout << "Osoba: " << getImie() << " " << getNazwisko();
        }
};

class Student: public Osoba{
    private:
        int nr_indeks=0;
    public:
        void setNrIndeks(int war){
            nr_indeks=war;
        }
        int getNrIndeks(){
            return nr_indeks;
        }
        void drukuj() override{
            cout << "Student: " << getImie() << " " << getNazwisko() <<  " " << getNrIndeks();
        }
};

class Stazysta: public Osoba{
    private:
        int id_pracownika=0;
    public:
        void setIdPracownika(int war){
            id_pracownika=war;
        }
        int getIdPracownika(){
            return id_pracownika;
        }
        void drukuj() override{
            cout << "Stazysta: " << getImie() << " " << getNazwisko() <<  " " << getIdPracownika();
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
        
        void ustawObecnosc(string naz){
            for(int i=0;i<10;i++){
                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNazwisko()==naz){
                    tabObecnosc[i] = !tabObecnosc[i];
                    break;
                }
            }
        }
        
        void wyswietlListe(){
            for(int i=0;i<10;i++){
                if(tabOsoba[i]!=nullptr){
                    tabOsoba[i]->drukuj();
                    cout << " " << (tabObecnosc[i] ? "Obecny" : "Nieobecny") << endl;
                }
            }
        }
        
        void usunOsobe(string naz){
            for(int i=0;i<10;i++){
                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNazwisko()==naz){
                    tabOsoba[i] = nullptr;
                    break;
                }
            }
        }
};

class InterfejsUzytkownika{
    public:
        InterfejsUzytkownika(Osoba **tab1,int licz1,listaObecnosci *tab2,int licz2){
            this->tabOsoba = tab1;
            this->iloscOsob = licz1;
            this->tabList = tab2;
            this->iloscList = licz2;
        }
        void loop(){
            int id,idListy,indeks,kto,wybor=0;
            string tekst,nazwisko;
            
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
                        cout << "Kogo chcesz dodac(1-Student,2-Stazysta):";
                        cin >> kto;
                        if(kto==1){
                            Student* podana1 = new Student();
                            cout << "Podaj numer indeksu:";
                            cin >> indeks;
                            podana1->setNrIndeks(indeks);
                            cout << "Podaj imie:";
                            cin >> tekst;
                            podana1->setImie(tekst);
                            cout << "Podaj nazwisko:";
                            cin >> tekst;
                            podana1->setNazwisko(tekst);
                            dodajOsobe(podana1);
                        }
                        else if(kto==2){
                            Stazysta* podana2 = new Stazysta();
                            cout << "Podaj numer indeksu:";
                            cin >> indeks;
                            podana2->setIdPracownika(indeks);
                            cout << "Podaj imie:";
                            cin >> tekst;
                            podana2->setImie(tekst);
                            cout << "Podaj nazwisko:";
                            cin >> tekst;
                            podana2->setNazwisko(tekst);
                            dodajOsobe(podana2);
                        }
                        break;
                
                    case 2:
                        cout << "Podaj nazwisko osoby jaka chcesz dodac:";
                        cin >> nazwisko;
                        cout << "Podaj numer id listy do jakiej chcesz dodac dana osobe(0-" << iloscList-1 << "):";
                        cin >> idListy;
                        if(idListy>=0 && idListy<iloscList){
                            for(int i=0;i<iloscOsob;i++){
                                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNazwisko()==nazwisko){
                                    tabList[idListy].dodajOsobe(tabOsoba[i]);
                                    break;
                                }
                            }
                        }
                        break;
                    
                    case 3:
                        cout << "Podaj nazwisko osoby jaka chcesz znalesc:";
                        cin >> nazwisko;
                        cout << "Podaj numer id listy w jakiej chcesz zrobic zmiane(0-" << iloscList-1 << "):";
                        cin >> idListy;
                        tabList[idListy].ustawObecnosc(nazwisko);
                        break;
                        
                    case 4:
                        cout << "Kogo chcesz zaktualizowac(1-Student,2-Stazysta):";
                        cin >> kto;
                        if(kto==1){
                            cout << "Podaj nazwisko osoby ktora chcesz zmienic:";
                            cin >> nazwisko;
                            for(int i=0;i<iloscOsob;i++){
                                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNazwisko()==nazwisko){
                                        Student* podana1 = new Student();
                                        cout << "Podaj numer indeksu:";
                                        cin >> indeks;
                                        podana1->setNrIndeks(indeks);
                                        cout << "Podaj imie:";
                                        cin >> tekst;
                                        podana1->setImie(tekst);
                                        cout << "Podaj nazwisko:";
                                        cin >> tekst;
                                        podana1->setNazwisko(tekst);
                                        for(int i=0;i<iloscList;i++){
                                            tabList[i].usunOsobe(nazwisko);
                                        }
                                        zmienElement(nazwisko, podana1);
                                    break;
                                }
                            }
                        }
                        else if(kto==2){
                            cout << "Podaj nazwisko osoby ktora chcesz zmienic:";
                            cin >> nazwisko;
                            for(int i=0;i<iloscOsob;i++){
                                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNazwisko()==nazwisko){
                                        Stazysta* podana2 = new Stazysta();
                                        cout << "Podaj numer indeksu:";
                                        cin >> indeks;
                                        podana2->setIdPracownika(indeks);
                                        cout << "Podaj imie:";
                                        cin >> tekst;
                                        podana2->setImie(tekst);
                                        cout << "Podaj nazwisko:";
                                        cin >> tekst;
                                        podana2->setNazwisko(tekst);
                                        for(int i=0;i<iloscList;i++){
                                            tabList[i].usunOsobe(nazwisko);
                                        }
                                        zmienElement(nazwisko, podana2);
                                    break;
                                }
                            }
                        }
                        break;
                        
                    case 5:
                        cout << "Podaj nazwisko osoby ktora chcesz usunac z listy obecnosci:";
                        cin >> nazwisko;
                        cout << "Podaj numer id listy w jakiej chcesz tego dokonac(0-" << iloscList-1 << "):";
                        cin >> idListy;
                        tabList[idListy].usunOsobe(nazwisko);
                        break;
                    
                    case 6:
                        cout << "Podaj nazwisko osoby ktora chcesz calkowicie usunac:";
                        cin >> nazwisko;
                        for(int i=0;i<iloscList;i++){
                            tabList[i].usunOsobe(nazwisko);
                        }
                        usunOsobe(nazwisko);
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
        Osoba **tabOsoba;
        int iloscOsob;
        listaObecnosci *tabList;
        int iloscList;
        
        void dodajOsobe(Osoba* nowa){
            for(int i=0;i<iloscOsob;i++){
                if(tabOsoba[i] == nullptr){
                    tabOsoba[i] = nowa;
                    break;
                }
            }
        }
        
        void zmienElement(string naz, Osoba* zmiana){
            for(int i=0;i<iloscOsob;i++){
                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNazwisko()==naz){
                    delete tabOsoba[i];
                    tabOsoba[i] = zmiana;
                    break;
                }
            }
        }
        
        void usunOsobe(string naz){
            for(int i=0;i<iloscOsob;i++){
                if(tabOsoba[i] != nullptr && tabOsoba[i]->getNazwisko()==naz){
                    delete tabOsoba[i];
                    tabOsoba[i] = nullptr;
                    break;
                }
            }
        }
};

int main(){
    Osoba* tabOsoba[10] = {nullptr};
    listaObecnosci tabList[2];
    
    InterfejsUzytkownika ui(tabOsoba,10,tabList,2);
    ui.loop();
    
    for(int i = 0; i < 10; i++){
        if(tabOsoba[i] != nullptr){
            delete tabOsoba[i];
        }
    }
    
    return 0;
}
