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
//---------------------------------------------------------------------------
class TPingPong : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *paddleLeft;
        TImage *ball;
        TTimer *Timer_ball;
        TTimer *LeftUp;
        TTimer *LeftDown;
        TImage *paddleRight;
        TTimer *RightUp;
        TTimer *RightDown;
        void __fastcall Timer_ballTimer(TObject *Sender);
        void __fastcall LeftUpTimer(TObject *Sender);
        void __fastcall LeftDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall RightUpTimer(TObject *Sender);
        void __fastcall RightDownTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPingPong(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPingPong *PingPong;
//---------------------------------------------------------------------------
#endif
 