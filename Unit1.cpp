//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <time.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
#define PredkoscOtoczenia 10
#define PredkoscPojazdu 10
class CFabrykaPrzeszkod;
class CFabrykaGwiazd;
class CPilka
{
     private:
        int x;
        int IloscTrafionychGwiazd;
        int WskTop;
        int WskLeft;
        TLabel* wsk;
     public:
     TImage* pilka;
     CPilka () : x(0) {}
     void UstanowRelacje (TLabel* Label) {wsk=Label;}
     void Wyswietl() {wsk->Caption=IloscTrafionychGwiazd;}
     //Wszytywanie kolejnych pilek
     void AktualnaPilka () {
        switch(x)
        {
                case 0:
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Picture->LoadFromFile("img/pilka.bmp");
                break;
                case 1:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka1.bmp");
                break;
                case 2:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka2.bmp");
                break;
                case 3:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka3.bmp");
                break;
                case 4:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka4.bmp");
                break;
                case 5:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka5.bmp");
                break;
                case 6:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka6.bmp");
                break;
                case 7:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka7.bmp");
                break;
                case 8:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka8.bmp");
                break;
                case 9:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka9.bmp");
                break;
                case 10:
                        delete pilka;
                        pilka=new TImage(Form1);
                        pilka->Parent=Form1;
                        pilka->Left=WskLeft;
                        pilka->Top=WskTop;
                        pilka->Picture->LoadFromFile("img/pilka10.bmp");
                break;
        }pilka->Transparent=true; pilka->AutoSize=true;
        }
friend void Kolizja(CFabrykaPrzeszkod&,CPilka&);
friend void Kolizja (CFabrykaGwiazd&,CPilka&);
}PILKA;

//KLASA
class CFabrykaGwiazd
{
   private:
        TImage* gwiazda;
        vector<TImage*> gwiazdy;
        TShape* tlo;
   public:
         void UstanowRelacje (TShape* tloo) { tlo= tloo; }
         void ProdukujGwiazde () {
                gwiazda= new TImage(Form1);
                gwiazda->Parent=Form1;
                gwiazda->Picture->LoadFromFile("img/gwiazda.bmp");
                gwiazda->Left=rand()%((tlo->Width)-gwiazda->Width); gwiazda->Top=-100;
                gwiazda->AutoSize=true;
                gwiazda->Transparent=true;
                gwiazdy.push_back(gwiazda);}
         void UsunGwiazde () {
                gwiazda=gwiazdy.front();
                gwiazdy.erase(gwiazdy.begin());
                delete gwiazda;
         }
         void UsunGwiazde1 (int i) {
                delete gwiazdy[i];
                gwiazdy.erase(gwiazdy.begin()+i);
                }
         void SprawdzCzyUsun () {
                if (gwiazdy.front()->Top>=tlo->Height)
                {
                        CFabrykaGwiazd::UsunGwiazde();
                }}
         void RuchGwiazd () {
                for(unsigned i=0;i<gwiazdy.size();++i)
                {
                        gwiazdy[i]->Top+=PredkoscOtoczenia;
                }}
friend void Kolizja (CFabrykaGwiazd&,CPilka&);
}GWIAZDA;

//KLASA
class CFabrykaPrzeszkod
{
    private:
        vector<TImage*> przeszkody;
        TShape* tlo;
    public:
        TImage* przeszkoda;
        void UstanowRelacje (TShape* tloo) { tlo= tloo; }
        //Losowanie przeszkody co czas w TimerPrzeszkoda
        void LosujPrzeszkode() {
                srand(time(NULL));
                int m= rand()%3;
                switch(m)
                {
                case 0:
                        przeszkoda=new TImage(Form1);
                        przeszkoda->Parent=Form1;
                        przeszkoda->Picture->LoadFromFile("img/przeszkoda1.bmp");
                        przeszkoda->Left=rand()%((tlo->Width)-przeszkoda->Width); przeszkoda->Top=-100;
                        przeszkoda->AutoSize=true;
                        przeszkody.push_back(przeszkoda);
                break;
                case 1:
                        przeszkoda=new TImage(Form1);
                        przeszkoda->Parent=Form1;
                        przeszkoda->Picture->LoadFromFile("img/przeszkoda2.bmp");
                        przeszkoda->Left=rand()%tlo->Width; przeszkoda->Top=-100; przeszkoda->AutoSize=true;
                        przeszkody.push_back(przeszkoda);
                break;
                case 2:
                        przeszkoda=new TImage(Form1);
                        przeszkoda->Parent=Form1;
                        przeszkoda->Picture->LoadFromFile("img/przeszkoda3.bmp");
                        przeszkoda->Left=rand()%tlo->Width; przeszkoda->Top=-100; przeszkoda->AutoSize=true;
                        przeszkody.push_back(przeszkoda);
                break;
                }}
        //Usuwa przeszkode jesli nastapi³a kolizja
        void UsunPrzeszkode (int i) {
                //przeszkody[i]->Visible=false;
                delete przeszkody[i];
                przeszkody.erase(przeszkody.begin()+i);
                }
        //Sprawdza i usuwa przeszkody jesli wyszlo poza plansze
        void UsunPrzeszkode1 () {
                przeszkoda=przeszkody.front();
                przeszkody.erase(przeszkody.begin());
                delete przeszkoda;
        }
        void SprawdzCzyUsun () {
        // po przekroczeniu odpowieniej wysokosci tla usuwamy stworzony pas
                if (przeszkody.front()->Top>=tlo->Height)
                {
                CFabrykaPrzeszkod::UsunPrzeszkode1 ();
                }}
        void RuchPrzeszkod () {
                for(unsigned i=0;i<przeszkody.size();++i)
                {
                        przeszkody[i]->Top+=PredkoscOtoczenia;
                }}
friend void Kolizja(CFabrykaPrzeszkod&,CPilka&);
};
CFabrykaPrzeszkod PRZESZKODA;

class CFabrykaChmur
{
    private:
    //Tworzenie wektora na który rzucamy nowe chmury
        vector<TImage*> pasy;
    //Tlo potrzebne do umieszczenia pasa w odpowiednim miejscu
        TShape* tlo;
        TImage* pas1;
        TImage* wsk;
    public:
        //Ustanowienie relacji z obiektem tlo
        void UstanowRelacje (TShape* tloo) { tlo= tloo; }
        void ProdukujPas () {
                pas1=new TImage(Form1);
                pas1->Parent=Form1;
                pas1->Picture->LoadFromFile("img/pasy.bmp");
                pas1->Transparent=true;
                srand(time(NULL));
                pas1->Left=rand()%(tlo->Width-pas1->Width); pas1->Top=-100;
                pasy.push_back(pas1);}
        void UsunPas () {
                wsk=pasy.front();
                pasy.erase(pasy.begin());
                delete wsk;}
        void RuchPasow() {
        //Poruszanie siê ka¿dego pasa
                for(unsigned i=0;i<pasy.size();++i)
                {
                        pasy[i]->Top+=PredkoscOtoczenia;
                }}
        void SprawdzCzyProdukcja () {
        //Sprawdzenie, czy górna czêsc pasa przekorczyla jego wysokosc (przyjêty warunek)
                if(pasy.back()->Top>=pasy.front()->Height-50)
                {
                //Jesli tak to wywo³ujemy metodê stworzonej klasy
                CFabrykaChmur::ProdukujPas();
                }}
        void SprawdzCzyUsun () {
        // po przekroczeniu odpowieniej wysokosci tla usuwamy stworzony pas
                if (pasy.front()->Top>=tlo->Height)
                {
                CFabrykaChmur::UsunPas ();
                }}
};
CFabrykaChmur CHMURA;

void Kolizja (CFabrykaGwiazd& przeszkoda,CPilka& pilka)
{
     for(unsigned i=0; i<przeszkoda.gwiazdy.size();++i)
     {
     if (       pilka.pilka->Left >= przeszkoda.gwiazdy[i]->Left-pilka.pilka->Width &&
                pilka.pilka->Left <= przeszkoda.gwiazdy[i]->Left+przeszkoda.gwiazdy[i]->Width &&
                pilka.pilka->Top >= przeszkoda.gwiazdy[i]->Top-pilka.pilka->Height &&
                pilka.pilka->Top <= przeszkoda.gwiazdy[i]->Top+przeszkoda.gwiazdy[i]->Height)
                {
                // Usuwanie przeszkody z ktora sie zderzyla pilka;
                przeszkoda.UsunGwiazde1(i);
                pilka.IloscTrafionychGwiazd++;
                pilka.Wyswietl();
                }
     }
}

void Kolizja (CFabrykaPrzeszkod& przeszkoda,CPilka& pilka)
{
     for(unsigned i=0; i<przeszkoda.przeszkody.size();++i)
     {
     if (       pilka.pilka->Left >= przeszkoda.przeszkody[i]->Left-pilka.pilka->Width &&
                pilka.pilka->Left <= przeszkoda.przeszkody[i]->Left+przeszkoda.przeszkody[i]->Width &&
                pilka.pilka->Top >= przeszkoda.przeszkody[i]->Top-pilka.pilka->Height &&
                pilka.pilka->Top <= przeszkoda.przeszkody[i]->Top+przeszkoda.przeszkody[i]->Height)
                {
                //Inkrementacja x w celu pozniejszej zmiany pilki w funkcji Aktualna pilka
                pilka.x++;
                //Zapewnieni, by nowa pilka wchodzila w pozycji starej
                pilka.WskTop=pilka.pilka->Top;
                pilka.WskLeft=pilka.pilka->Left;
                pilka.AktualnaPilka();
                // Usuwanie przeszkody z ktora sie zderzyla pilka;
                przeszkoda.UsunPrzeszkode(i);
                }
     }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::TimerOtoczenieTimer(TObject *Sender)
{
    CHMURA.RuchPasow();
    PRZESZKODA.RuchPrzeszkod();
    GWIAZDA.RuchGwiazd();
    Kolizja(PRZESZKODA,PILKA);
    Kolizja(GWIAZDA,PILKA);
    GWIAZDA.SprawdzCzyUsun();
    CHMURA.SprawdzCzyProdukcja();
    CHMURA.SprawdzCzyUsun();
    PRZESZKODA.SprawdzCzyUsun();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    GWIAZDA.UstanowRelacje(tlo);
    GWIAZDA.ProdukujGwiazde();
    CHMURA.UstanowRelacje(tlo);
    CHMURA.ProdukujPas();
    PRZESZKODA.UstanowRelacje(tlo);
    PRZESZKODA.LosujPrzeszkode();
    PILKA.AktualnaPilka();
    PILKA.UstanowRelacje(IloscGwiazd);
    MediaPlayer1->FileName="sound/Clock Machine - Spadaæ i lataæ.mp3";
    MediaPlayer1->Open();
    MediaPlayer1->Play();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_LEFT)  Lewo->Enabled=true;
        if(Key==VK_RIGHT) Prawo->Enabled=true;
        if(Key==VK_UP) Gora->Enabled=true;
        if(Key==VK_DOWN) Dol->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_LEFT)  Lewo->Enabled=false;
        if(Key==VK_RIGHT) Prawo->Enabled=false;
        if(Key==VK_UP) Gora->Enabled=false;
        if(Key==VK_DOWN) Dol->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LewoTimer(TObject *Sender)
{
     if(PILKA.pilka->Left-10>=tlo->Left)
     PILKA.pilka->Left-= PredkoscPojazdu;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PrawoTimer(TObject *Sender)
{
        if(PILKA.pilka->Left+PILKA.pilka->Width<=tlo->Width)
        PILKA.pilka->Left+= PredkoscPojazdu;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GoraTimer(TObject *Sender)
{
    if(PILKA.pilka->Top-10>=tlo->Top)
        PILKA.pilka->Top-= PredkoscPojazdu;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DolTimer(TObject *Sender)
{
      if(PILKA.pilka->Top+PILKA.pilka->Height+10<=tlo->Height)
      PILKA.pilka->Top+= PredkoscPojazdu;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPrzeszkodaTimer(TObject *Sender)
{
        PRZESZKODA.LosujPrzeszkode();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        MediaPlayer1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerGwiazdaTimer(TObject *Sender)
{
     GWIAZDA.ProdukujGwiazde();
}
//---------------------------------------------------------------------------

