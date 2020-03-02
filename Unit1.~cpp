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
class CPilka
{
     private:
        int x;
        int WskTop;
        int WskLeft;
     public:
     TImage* pilka;
     CPilka () : x(0) {}
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
        }pilka->Transparent=true;
        }
friend void Kolizja(CFabrykaPrzeszkod&,CPilka&);
}PILKA;

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
                        przeszkody.push_back(przeszkoda);
                break;
                case 1:
                        przeszkoda=new TImage(Form1);
                        przeszkoda->Parent=Form1;
                        przeszkoda->Picture->LoadFromFile("img/przeszkoda2.bmp");
                        przeszkoda->Left=rand()%tlo->Width; przeszkoda->Top=-100;
                        przeszkody.push_back(przeszkoda);
                break;
                case 2:
                        przeszkoda=new TImage(Form1);
                        przeszkoda->Parent=Form1;
                        przeszkoda->Picture->LoadFromFile("img/przeszkoda3.bmp");
                        przeszkoda->Left=rand()%tlo->Width; przeszkoda->Top=-100;
                        przeszkody.push_back(przeszkoda);
                break;
                }}
        void UsunPrzeszkode (int i) {
                //przeszkody[i]->Visible=false;
                delete przeszkody[i];
                przeszkody.erase(przeszkody.begin()+i);
                }
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
        CFabrykaPasow () {}
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
    Kolizja(PRZESZKODA,PILKA);
    CHMURA.SprawdzCzyProdukcja();
    CHMURA.SprawdzCzyUsun();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    CHMURA.UstanowRelacje(tlo);
    CHMURA.ProdukujPas();
    PRZESZKODA.UstanowRelacje(tlo);
    PILKA.AktualnaPilka();
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
      if(PILKA.pilka->Top+PILKA.pilka->Height-60<=tlo->Height)
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

