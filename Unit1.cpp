//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPingPong *PingPong;

int x = -8;
int y = -8;
int scorePlayerLeft = 0;
int scorePlayerRight = 0;
int bounces = 0;
bool whoPlay = false;

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

  if(ball->Top - 5 <= 0) y = -y;

  if(ball->Top + ball->Height >= background->Height) y = -y;


  if(ball->Left >= paddleRight->Left + paddleRight->Width)
    {
     if(bounces == 0)
      {
        Button1->Caption = "¯aden z zawodników nie odbi³ pi³ki";
        Button1->Visible = true;
        Button2->Caption = IntToStr(scorePlayerLeft) + ":" + IntToStr(scorePlayerRight);
        Button2->Visible = true;
        ball->Visible = false;
        Timer_ball->Enabled = false;
        Button3->Visible = true;
        Button4->Caption = "Graj dalej. Ilosc odbic: " + IntToStr(bounces);
        Button4->Visible = true;
      }else
      {
        whoPlay = true;
        Timer_ball->Enabled = false;
        ball->Visible = false;
        scorePlayerLeft++;
        Button1->Caption = "<-- Punkt dla zawodnika z lewej strony";
        Button1->Visible = true;
        Button2->Caption = IntToStr(scorePlayerLeft) + ":" + IntToStr(scorePlayerRight);
        Button2->Visible = true;
        Button3->Visible = true;
        Button4->Caption = "Graj dalej. Ilosc odbic: " + IntToStr(bounces);
        Button4->Visible = true;
      }
    } else if(ball->Top > paddleRight->Top - ball->Height/2 &&
              ball->Top < paddleRight->Top + paddleRight->Height &&
              ball->Left + ball->Width > paddleRight->Left)
              {
                if(x>0)
                {
                  x = -x;
                  x -= 1;
                  y += 1;
                  bounces++;
                }
              }


    if(ball->Left <= paddleLeft->Left)
    {
     if(bounces == 0)
      {
        Button1->Caption = "¯aden z zawodników nie odbi³ pi³ki";
        Button1->Visible = true;
        Button2->Caption = IntToStr(scorePlayerLeft) + ":" + IntToStr(scorePlayerRight);
        Button2->Visible = true;
        ball->Visible = false;
        Timer_ball->Enabled = false;
        Button3->Visible = true;
        Button4->Caption = "Graj dalej. Ilosc odbic: " + IntToStr(bounces);
        Button4->Visible = true;
      }else
      {
        whoPlay = true;
        Timer_ball->Enabled = false;
        ball->Visible = false;
        scorePlayerLeft++;
        Button1->Caption = "Punkt dla zawodnika z prawej strony -->";
        Button1->Visible = true;
        Button2->Caption = IntToStr(scorePlayerLeft) + ":" + IntToStr(scorePlayerRight);
        Button2->Visible = true;
        Button3->Visible = true;
        Button4->Caption = "Graj dalej. Ilosc odbic: " + IntToStr(bounces);
        Button4->Visible = true;
      }
    } else if(ball->Top > paddleLeft->Top - ball->Height/2 &&
              ball->Top < paddleLeft->Top + paddleLeft->Height &&
              ball->Left < paddleLeft->Left + paddleLeft->Width)
              {
                 if(x<0){
                 x = -x;
                 x += 1;
                 y += 1;
                 bounces++;
                 }
              }
   if(bounces == 5)
   {
     background->Visible = false;
     background2->Visible = true;
     paddleLeft->Visible = true;
     paddleRight->Visible = true;
     ball->Visible = true;
   }
   else if(bounces == 10)
   {
     background2->Visible = false;
     background3->Visible = true;
     paddleLeft->Visible = true;
     paddleRight->Visible = true;
     ball->Visible = true;
   }
  else if(bounces == 15)
   {
     background3->Visible = false;
     background4->Visible = true;
     paddleLeft->Visible = true;
     paddleRight->Visible = true;
     ball->Visible = true;
   }

   if(scorePlayerLeft == 5)
   {
     if(Application->MessageBox("Wygrywa gracz po lewej stronie!!!!","GRATULACJE!!", MB_OK ) == IDOK)
     {
       ball->Visible = false;
       buttonNewGame->Visible = true;
       Button2->Visible = false;
       Button3->Visible = false;
       Button4->Visible = false;
       scorePlayerRight = 0;
       scorePlayerLeft = 0;
       bounces = 0;
     }
   }
   else if(scorePlayerRight == 5)
   {
     if(Application->MessageBox("Wygrywa gracz po prawej stronie!!!!","GRATULACJE!!", MB_OK ) == IDOK)
     {
       ball->Visible = false;
       buttonNewGame->Visible = true;
       Button2->Visible = false;
       Button3->Visible = false;
       Button4->Visible = false;
       scorePlayerRight = 0;
       scorePlayerLeft = 0;
       bounces = 0;
   }
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
  if(paddleLeft->Top + paddleLeft->Height + 10 <= background->Height) paddleLeft->Top += 10;
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
  if(paddleRight->Top + paddleRight->Height + 10 <= background->Height) paddleRight->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::FormCreate(TObject *Sender)
{
  DoubleBuffered = true;
  Application->MessageBox("Witaj w grze PingPong.\n\nSterowanie gracza lewego: Q oraz A.\nSterowanie gracza prawego: strza³ka do góry i w dó³.\n\nZasady gry:\nPo kazdym kolejnym odbiciu pi³ka przyspiesza.\nKolory pola gry zmieniaj¹ siê wraz z iloœci¹ odbiæ.\nWygrywa gracz, który pierwszy zdobêdzie 5 punktów.\n\n\n Mi³ej zabawy!!!",NULL);
  ball->Visible = true;
  Timer_ball->Enabled = false;
  buttonNewGame->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TPingPong::Button3Click(TObject *Sender)
{

   if(Application->MessageBox("Czy na pewno chcesz rozpocz¹æ od nowa?", "PotwierdŸ", MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
   {
     x = -8; y = -8;
     ball->Left = 400;
     ball->Top = 200;
     ball->Visible = true;
     Timer_ball->Enabled = true;
     Button1->Visible = false;
     Button2->Visible = false;
     Button3->Visible = false;
     Button4->Visible = false;
     background->Visible = true;
     scorePlayerLeft = 0;
     scorePlayerRight = 0;
     bounces = 0;
     whoPlay = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::Button4Click(TObject *Sender)
{

   if(whoPlay){ x = -8;  y = -8;}
   else { x = 8;  y = 8;}
   whoPlay = false;
   ball->Left = 400;
   ball->Top = 200;
   ball->Visible = true;
   bounces = 0;
   Timer_ball->Enabled = true;
   Button1->Visible = false;
   Button2->Visible = false;
   Button3->Visible = false;
   Button4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::buttonNewGameClick(TObject *Sender)
{
   ball->Left = 400;
   ball->Top = 200;
   ball->Visible = true;
   x = -8; y = -8;
   Timer_ball->Enabled = true;
   Button1->Visible = false;
   Button2->Visible = false;
   Button3->Visible = false;
   Button4->Visible = false;
   buttonNewGame->Visible = false;
   scorePlayerLeft = 0;
   scorePlayerRight = 0;
   bounces = 0;
   background->Visible = true;
}
//---------------------------------------------------------------------------

