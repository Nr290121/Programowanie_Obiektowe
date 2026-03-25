#include <iostream>

using namespace std;

void dodajOsobe(string *tab1, string nazwisko, string *tab2, string imie){
    int x=0;
    for(int i=0;i<10;i++){
        if(tab1[i]==""){
            tab1[x]=nazwisko;
            tab2[x]=imie;
            break;
        }
        x++;
    }
}

void ustawObecnosc(int *tab1, int id, bool *tab2){
    for(int i=0;i<10;i++){
        if(tab1[i]==id){
            if(tab2[i]==false){
                tab2[i]=true;
            }
            else{
                tab2[i]=false;
            }
            break;
        }
    }
}

void zmienElement(int *tab1, string *tab2, string *tab3, int id, char opcja, string zmiana){
    for(int i=0;i<10;i++){
        if(tab1[i]==id){
            switch(int(opcja)){
                case 105:
                    tab2[i]=zmiana;
                    break;
                
                case 110:
                    tab3[i]=zmiana;
                    break;
            }
            break;
        }
    }
}

void usunOsobe(int *tab1, string *tab2, string *tab3, bool *tab4, int id){
    for(int i=0;i<10;i++){
        if(tab1[i]==id){
            tab2[i]="";
            tab3[i]="";
            tab4[i]=false;
            break;
        }
    }
}

void wyswietlListe(int *tab1, string *tab2, string *tab3, bool *tab4){
    for(int i=0;i<10;i++){
            cout << tab1[i] << " " << tab2[i] << " " << tab3[i] << " " << tab4[i] << endl;
    }
}

int main(){
    int tabId[10]={1,2,3,4,5,6,7,8,9,10};
    string tabImie[10];
    string tabNazwisko[10];
    bool tabObecnosc[10]={false};
    string imie,nazwisko,zmiana;
    char opcja;
    int id,wybor=0;

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
                cout << "Podaj imie:";
                cin >> imie;
                cout << "Podaj nazwisko:";
                cin >> nazwisko;
                dodajOsobe(tabNazwisko,nazwisko,tabImie,imie);
                break;
        
            case 2:
                cout << "Podaj numer id osoby jaka chcesz znalesc:";
                cin >> id;
                ustawObecnosc(tabId,id,tabObecnosc);
                break;
            
            case 3:
                cout << "Podaj numer id osoby ktora chcesz zmienic:";
                cin >> id;
                cout << "Co chcesz zmienic(i/n):";
                cin >> opcja;
                cout << "Na co chcesz zmienic:";
                cin >> zmiana;
                zmienElement(tabId,tabImie,tabNazwisko,id,opcja,zmiana);
                break;
                
            case 4:
                cout << "Podaj numer id osoby ktora chcesz usunac:";
                cin >> id;
                usunOsobe(tabId,tabImie,tabNazwisko,tabObecnosc,id);
                break;
                
            case 5:
                wyswietlListe(tabId,tabImie,tabNazwisko,tabObecnosc);
                break;
        }
    }

    return 0;
}