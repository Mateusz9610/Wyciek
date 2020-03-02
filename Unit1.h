//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TTimer *TimerOtoczenie;
        TTimer *Lewo;
        TTimer *Prawo;
        TTimer *Gora;
        TTimer *Dol;
        TTimer *TimerPrzeszkoda;
        TMediaPlayer *MediaPlayer1;
        void __fastcall TimerOtoczenieTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall LewoTimer(TObject *Sender);
        void __fastcall PrawoTimer(TObject *Sender);
        void __fastcall GoraTimer(TObject *Sender);
        void __fastcall DolTimer(TObject *Sender);
        void __fastcall TimerPrzeszkodaTimer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations

        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 