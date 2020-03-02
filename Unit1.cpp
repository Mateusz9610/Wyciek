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
    x=0;
}
#define PredkoscOtoczenia 10
vector<TImage*> pasy;


void FabrykaPasow(TShape* tlo)
{
        TImage* pas1=new TImage(Form1);
        pas1->Parent=Form1;
        pas1->Picture->LoadFromFile("img/pasy.bmp");
        pas1->Left=((tlo->Width/2)-10); pas1->Top=-50;
        pasy.push_back(pas1);

}
class CFabrykaPasow
{
        private:
        TShape* tlo;
        TImage* pas1;
        public:
        CFabrykaPasow (TShape* tloo) : tlo(tloo) { tlo=tloo; }
        void ProdukujPas () {
        pas1=new TImage(Form1);
        pas1->Parent=Form1;
        pas1->Picture->LoadFromFile("img/pasy.bmp");
        pas1->Left=((tlo->Width/2)-10); pas1->Top=-50;
        pasy.push_back(pas1);}
        void UsunPas () {}

};
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerOtoczenieTimer(TObject *Sender)
{

    if (x<1)
    {
    FabrykaPasow(tlo);
    ++x;
    }
    for(int i=0;i<pasy.size();++i)
    {
      pasy[i]->Top+=PredkoscOtoczenia;
    }
    //pasy.front()->Top+=PredkoscOtoczenia;
    if(pasy.back()->Top>=pasy.front()->Height)
    {
     FabrykaPasow(tlo);
    }
    /*for(int i=0; i<pasy.size(); ++i)
    {
    pasy[i]->Top+=PredkoscOtoczenia;
    }*/
    //pas->Top+=PredkoscOtoczenia;
    if (pasy.front()->Top>=tlo->Height/1.2)
    {
    TImage* wsk=pasy.front();
    pasy.erase(pasy.begin());
    delete wsk;
    }
}
//---------------------------------------------------------------------------
