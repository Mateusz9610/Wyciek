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
vector<TImage*> pasy;
int x=0;

void FabrykaPasow(TShape* tlo)
{
        TImage* pas1=new TImage(Form1);
        pas1->Parent=Form1;
        pas1->Picture->LoadFromFile("img/pasy.bmp");
        pas1->Left=((tlo->Width/2)-10); pas1->Top=-50;
        pasy.push_back(pas1);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerOtoczenieTimer(TObject *Sender)
{
    do
    {
    FabrykaPasow(tlo);
    ++x;
    }while(pasy.front()

    for(int i=0; i<pasy.size(); ++i)
    {
    pasy[i]->Top+=PredkoscOtoczenia;
    }
    //pas->Top+=PredkoscOtoczenia;
    if (pasy.front()->Top>=tlo->Height/1.2)
    {
    TImage* wsk=pasy.front();
    pasy.pop_back();
    delete wsk;
    x=0;
    }
}
//---------------------------------------------------------------------------
