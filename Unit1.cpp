//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPingPong *PingPong;

int x = -5;
int y = -5;
int scorePlayerLeft = 0;
int scorePlayerRight = 0;
//---------------------------------------------------------------------------
__fastcall TPingPong::TPingPong(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::Timer_ballTimer(TObject *Sender)
{
  ball->Left += x;
  ball->Top += y;

  //odbicie od top
  if(ball->Top - 5 <= 0) y = -y;
  //odbicie od bottom
  if(ball->Top + ball->Height >= tlo->Height) y = -y;

  //skucha lewego
  if(ball->Left <= 0)
  {
     Timer_ball->Enabled = false;
     ball->Visible = false;
     scorePlayerRight++;
  } else if(ball->Top > paddleLeft->Top - ball->Height/2 &&
            ball->Top < paddleLeft->Top + paddleLeft->Height &&
            ball->Left < paddleLeft->Left + paddleLeft->Width)
           {
             if(x>0) x = -x;
           }
  // odbicie i skucha prawego
  if(ball->Left >= tlo->Width)
  {
     Timer_ball->Enabled = false;
     ball->Visible = false;
     scorePlayerRight++;
  } else if(ball->Top > paddleRight->Top - ball->Height/2 &&
            ball->Top < paddleRight->Top + paddleRight->Height &&
            ball->Left + ball->Width > paddleRight->Left)
            {
              if(x>0) x = -x;
            }
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::LeftUpTimer(TObject *Sender)
{
  if(paddleLeft->Top >= 10) paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::LeftDownTimer(TObject *Sender)
{
  if(paddleLeft->Top + paddleLeft->Height + 10 <= tlo->Height) paddleLeft->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == 0x51) LeftUp->Enabled = true;
   if(Key == 0x41) LeftDown->Enabled = true;
   if(Key == VK_UP) RightUp->Enabled = true;
   if(Key == VK_DOWN) RightDown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == 0x51) LeftUp->Enabled = false;
   if(Key == 0x41) LeftDown->Enabled = false;
   if(Key == VK_UP) RightUp->Enabled = false;
   if(Key == VK_DOWN) RightDown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::RightUpTimer(TObject *Sender)
{
  if(paddleRight->Top >= 10) paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::RightDownTimer(TObject *Sender)
{
  if(paddleRight->Top + paddleRight->Height + 10 <= tlo->Height) paddleRight->Top += 10;
}
//---------------------------------------------------------------------------

