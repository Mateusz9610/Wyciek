//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
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

class CFabrykaPasow
{
    private:
    //Tworzenie wektora na kt�ry rzucamy nowe pasy
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
                pas1->Left=((tlo->Width/2)-10); pas1->Top=-50;
                pasy.push_back(pas1);}
        void UsunPas () {
                wsk=pasy.front();
                pasy.erase(pasy.begin());
                delete wsk;}
        void RuchPasow() {
        //Poruszanie si� ka�dego pasa
                for(int i=0;i<pasy.size();++i)
                {
                        pasy[i]->Top+=PredkoscOtoczenia;
                }}
        void SprawdzCzyProdukcja () {
        //Sprawdzenie, czy g�rna cz�sc pasa przekorczyla jego wysokosc (przyj�ty warunek)
                if(pasy.back()->Top>=pasy.front()->Height)
                {
                //Jesli tak to wywo�ujemy metod� stworzonej klasy
                CFabrykaPasow::ProdukujPas();
                }}
        void SprawdzCzyUsun () {
        // po przekroczeniu odpowieniej wysokosci tla usuwamy stworzony pas
                if (pasy.front()->Top>=tlo->Height/1.2)
                {
                CFabrykaPasow::UsunPas ();
                }}
};
CFabrykaPasow PAS;

//---------------------------------------------------------------------------
void __fastcall TForm1::TimerOtoczenieTimer(TObject *Sender)
{
    PAS.RuchPasow();
    PAS.SprawdzCzyProdukcja();
    PAS.SprawdzCzyUsun();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    PAS.UstanowRelacje(tlo);
    PAS.ProdukujPas();
}
//---------------------------------------------------------------------------


