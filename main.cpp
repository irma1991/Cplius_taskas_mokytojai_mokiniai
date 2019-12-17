#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream out("rezultatai.txt");

struct mokytojai{
    string vardas;
    string pavarde;
    string dalykas;
    int mokiniuSkaicius;
    float vidurkis;
    };

struct mokiniai{
    string vardas;
    string pavarde;
    string dalykas;
    int pazimys;
    int mokytojoIdeksas;
    };

    void kiekisMokytoju(int &kiekMokytoju, const char byla1[]);
    void kiekisMokiniu(int &kiekMokiniu, const char byla2[]);
    void skaitomMokytojus(mokytojai mokytojaiDuomenys[], int kiekMokytoju, const char byla1[]);
    void skaitomMokinius(mokiniai mokiniaiDuomenys[], int kiekMokiniu, const char byla2[]);
    void rasomMokytojus(mokytojai mokytojaiDuomenys[], int kiekMokytoju, string text);
    void rasomMokinius(mokiniai mokiniaiDuomenys[], int kiekMokiniu, string text);
    void ieskomVienoduDalyku(mokytojai mokytojaiDuomenys[], int kiekMokytoju, mokiniai mokiniaiDuomenys[], int kiekMokiniu);
    int ieskomMaxMokiniu(mokytojai mokytojaiDuomenys[], int kiekis);
    void ieskomDidziausioVidurkio(mokytojai mokytojaiDuomenys[], int kiekMokytoju, mokiniai mokiniaiDuomenys[], int kiekMokiniu);
    int ieskomMaxVidurkio(mokytojai mokytojaiDuomenys[], int kiekis);


int main()
{

    int kiekMokytoju, kiekMokiniu, daugiausiaiMokiniu, geriausiasVidurkis;
    const char duomenysMokytojai[] = "mokytojai.txt";
    const char duomenysMokiniai[] = "mokiniai.txt";

    kiekisMokytoju(kiekMokytoju, duomenysMokytojai);
    cout<<kiekMokytoju<<endl;
    kiekisMokiniu(kiekMokiniu, duomenysMokiniai);
    cout<<kiekMokiniu<<endl;

    mokytojai Mokytojai[kiekMokytoju];
    mokiniai Mokiniai[kiekMokiniu];

    skaitomMokytojus(Mokytojai, kiekMokytoju, duomenysMokytojai);
    skaitomMokinius(Mokiniai, kiekMokiniu, duomenysMokiniai);

    ieskomVienoduDalyku(Mokytojai, kiekMokytoju, Mokiniai, kiekMokiniu);

    daugiausiaiMokiniu = ieskomMaxMokiniu(Mokytojai, kiekMokytoju);

    ieskomDidziausioVidurkio(Mokytojai, kiekMokytoju, Mokiniai, kiekMokiniu);

    geriausiasVidurkis = ieskomMaxVidurkio(Mokytojai, kiekMokytoju);

    rasomMokytojus(Mokytojai, kiekMokytoju, "Mokytojai \n");
    rasomMokinius(Mokiniai, kiekMokiniu, "Mokiniai \n");

    out<<"Daugiausiai mokiniu turi:"<<endl<<Mokytojai[daugiausiaiMokiniu].vardas<<" "<<Mokytojai[daugiausiaiMokiniu].pavarde<<". Sis mokytojas desto: "<<Mokytojai[daugiausiaiMokiniu].dalykas<<" ."<<endl<<"Mokiniu skaicius, kuriems desto si dalyka, yra: "<<Mokytojai[daugiausiaiMokiniu].mokiniuSkaicius<<endl;
    out<<endl;
    out<<"Mokytojas, kurio mokiniai mokosi geriausiai, yra:"<<endl<<Mokytojai[geriausiasVidurkis].vardas<<" "<<Mokytojai[geriausiasVidurkis].pavarde<<"."<<endl<<"Jo destomas dalykas yra: "<<Mokytojai[geriausiasVidurkis].dalykas<<"."<<endl<<"Geriausio jo mokinio vidurkis yra: "<<Mokytojai[geriausiasVidurkis].vidurkis<<"."<<endl;

    out.close();
    return 0;
}

 void kiekisMokytoju(int &kiekMokytoju, const char byla1[]){
    ifstream in(byla1);
    mokytojai LaikinaMokytojuStruktura[1];
    kiekMokytoju=0;
    while(!in.eof()){
        in>>LaikinaMokytojuStruktura[0].vardas>>LaikinaMokytojuStruktura[0].pavarde>>LaikinaMokytojuStruktura[0].dalykas;
        kiekMokytoju++;
    }
    in.seekg(0);
    in.close();
 }

  void kiekisMokiniu(int &kiekMokiniu, const char byla2[]){
    ifstream in(byla2);
    mokiniai LaikinaMokinuStruktura[1];
    kiekMokiniu=0;
    while(!in.eof()){
        in>>LaikinaMokinuStruktura[0].vardas>>LaikinaMokinuStruktura[0].pavarde>>LaikinaMokinuStruktura[0].dalykas>>LaikinaMokinuStruktura[0].pazimys;
        kiekMokiniu++;
    }
    in.seekg(0);
    in.close();
 }

 void skaitomMokytojus(mokytojai mokytojaiDuomenys[], int kiekMokytoju, const char byla1[]){
    ifstream in(byla1);
    for(int i=0; i<kiekMokytoju; i++){
        in>>mokytojaiDuomenys[i].vardas>>mokytojaiDuomenys[i].pavarde>>mokytojaiDuomenys[i].dalykas;
    }
    in.close();
}

 void skaitomMokinius(mokiniai mokiniaiDuomenys[], int kiekMokiniu, const char byla2[]){
    ifstream in(byla2);
    for(int i=0; i<kiekMokiniu; i++){
        in>>mokiniaiDuomenys[i].vardas>>mokiniaiDuomenys[i].pavarde>>mokiniaiDuomenys[i].dalykas>>mokiniaiDuomenys[i].pazimys;
    }
    in.close();
}

void rasomMokytojus(mokytojai mokytojaiDuomenys[], int kiekMokytoju, string text){
    out<<text;
    for(int i=0; i<kiekMokytoju; i++){
        out<<setw(4)<<left<<" "<<mokytojaiDuomenys[i].vardas<<" "<<setw(4)<<right<<mokytojaiDuomenys[i].pavarde<<" "<<setw(4)<<right<<mokytojaiDuomenys[i].dalykas<<" "<<mokytojaiDuomenys[i].mokiniuSkaicius;
        out<<endl;
        out<<endl;
    }

}

void rasomMokinius(mokiniai mokiniaiDuomenys[], int kiekMokiniu, string text){
    out<<text;
    for(int i=0; i<kiekMokiniu; i++){
        out<<setw(4)<<left<<" "<<mokiniaiDuomenys[i].vardas<<" "<<setw(4)<<right<<mokiniaiDuomenys[i].pavarde<<" "<<setw(4)<<right<<mokiniaiDuomenys[i].dalykas<<" "<<mokiniaiDuomenys[i].pazimys;
        out<<endl;
        out<<endl;
    }

}

void ieskomVienoduDalyku(mokytojai mokytojaiDuomenys[], int kiekMokytoju, mokiniai mokiniaiDuomenys[], int kiekMokiniu){
    int laikinas;
    for(int i=0; i<kiekMokytoju; i++){
            laikinas=0;
            for(int j=0; j<kiekMokiniu; j++){
        if(mokytojaiDuomenys[i].dalykas == mokiniaiDuomenys[j].dalykas){
            laikinas++;
            }
        }
    mokytojaiDuomenys[i].mokiniuSkaicius=laikinas;
    cout<<mokytojaiDuomenys[i].mokiniuSkaicius<<" "<<mokytojaiDuomenys[i].dalykas<<endl;
    }
}

int ieskomMaxMokiniu(mokytojai mokytojaiDuomenys[], int kiekis){
    int vieta = 0;

     for(int i = 0; i < kiekis; i++){
         if(mokytojaiDuomenys[i].mokiniuSkaicius > mokytojaiDuomenys[vieta].mokiniuSkaicius){
            vieta = i;
         }
     } return vieta;
}

void ieskomDidziausioVidurkio(mokytojai mokytojaiDuomenys[], int kiekMokytoju, mokiniai mokiniaiDuomenys[], int kiekMokiniu){
    int laikinas, suma;

    for(int i = 0; i < kiekMokytoju; i++){
        laikinas = 0;
        suma = 0;
        for(int j = 0; j < kiekMokiniu; j++){
            if(mokytojaiDuomenys[i].dalykas == mokiniaiDuomenys[j].dalykas){
                laikinas++;
                suma += mokiniaiDuomenys[j].pazimys;
            }
        }

        mokytojaiDuomenys[i].vidurkis = float(suma)/float(laikinas);
        cout<<mokytojaiDuomenys[i].vardas<<" "<<mokytojaiDuomenys[i].pavarde<<" "<<mokytojaiDuomenys[i].dalykas<<" "<<mokytojaiDuomenys[i].vidurkis<<endl;
    }
}

int ieskomMaxVidurkio(mokytojai mokytojaiDuomenys[], int kiekis){
    int vieta = 0;

    for(int i = 0; i < kiekis; i++){
        if(mokytojaiDuomenys[i].vidurkis > mokytojaiDuomenys[vieta].vidurkis){
            vieta = i;
        }
        return vieta;
    }
}
