#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int verticalShift = -8;
int horizontalShift = -8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
        ball->Left += verticalShift;
        ball->Top += horizontalShift;

        // odbij od gornej sciany
        if(ball->Top - 5 <= background->Top)
                horizontalShift = -horizontalShift;

        // odbij od dolnej sciany
        if(ball->Top + 32 >= background->Top + 501)
                horizontalShift = -horizontalShift;

        // skucha lewa sciana
        if(ball->Left - 5 >= paddleLeft->Top + paddleLeft->Height + 500)
        {
                TimerBall->Enabled = false;
                ball->Visible = false;
        }
        else if(ball->Left > paddleLeft->Left - ball->Width/2 &&
                ball->Left < paddleLeft->Left + paddleLeft->Width &&
                ball->Top + ball->Height > paddleLeft->Top)
        {
               if(horizontalShift > 0) horizontalShift = -horizontalShift;
        }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerUpPaddleRightTimer(TObject *Sender)
{
        if(paddleRight->Top > 10)
                paddleRight->Top -= 10;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerDownPaddleRightTimer(TObject *Sender)
{
        if(paddleRight->Top + paddleRight->Height < background->Height)
                paddleRight->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) timerUpPaddleRight->Enabled = false;
        if(Key == VK_DOWN) timerDownPaddleRight->Enabled = false;
        if(Key == 0x41) timerUpPaddleLeft->Enabled = false;
        if(Key == 0x5A) timerDownPaddleLeft->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) timerUpPaddleRight->Enabled = true;
        if(Key == VK_DOWN) timerDownPaddleRight->Enabled = true;
        if(Key == 0x41) timerUpPaddleLeft->Enabled = true;
        if(Key == 0x5A) timerDownPaddleLeft->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerUpPaddleLeftTimer(TObject *Sender)
{
        if(paddleLeft->Top > 10)
                paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerDownPaddleLeftTimer(TObject *Sender)
{
        if(paddleLeft->Top + paddleLeft->Height < background->Height)
                paddleLeft->Top  += 10;
}
//---------------------------------------------------------------------------
