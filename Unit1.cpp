#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int horizontalShift = -8;
int verticalShift = -8;
int countBounces = 0;
int leftPlayerPoints = 0;
int rightPlayerPoints = 0;
bool startGame = false;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
        if(startGame == true)
        {
        ball->Left += verticalShift;
        ball->Top += horizontalShift;

        // odbij od gornej sciany
        if(ball->Top - 5 <= background->Top)
                horizontalShift = -1.1 * horizontalShift;

        // odbij od dolnej sciany
        if(ball->Top + 32 >= background->Top + 475)
                horizontalShift = -1.1 * horizontalShift;

        if (ball->Left < paddleLeft->Left  &&
                (ball->Top + ball->Height / 2 < paddleLeft->Top ||
                 ball->Top + ball->Height / 2 > paddleLeft->Top + paddleLeft->Height))
        {
                rightPlayerPoints++;
                TimerBall->Enabled = false;
                ball->Visible = false;
                startGame = false;
                Form1->newGameButton->Visible = true;
                Form1->scoreButton->Caption = IntToStr(leftPlayerPoints) + " : " + IntToStr(rightPlayerPoints);
                Form1->scoreButton->Visible = true;
                Form1->bouncesButton->Caption = "Amount of bounces: " + IntToStr(countBounces);
                Form1->bouncesButton->Visible = true;
                Form1->nextRoundButton->Visible = true;
                Form1->rightPlayerPointButton->Visible = true;
                verticalShift = -8;
                horizontalShift = -8;
        }
        else if(ball->Left + ball->Width > paddleRight->Left + paddleRight->Width &&
                (ball->Top + ball->Height / 2 < paddleRight->Top ||
                 ball->Top + ball->Height / 2 > paddleRight->Top + paddleRight->Height))
        {
                leftPlayerPoints++;
                TimerBall->Enabled = false;
                ball->Visible = false;
                startGame = false;
                Form1->newGameButton->Visible = true;
                Form1->scoreButton->Caption = IntToStr(leftPlayerPoints) + " : " + IntToStr(rightPlayerPoints);
                Form1->scoreButton->Visible = true;
                Form1->bouncesButton->Caption = "Amount of bounces: " + IntToStr(countBounces);
                Form1->bouncesButton->Visible = true;
                Form1->nextRoundButton->Visible = true;
                Form1->leftPlayerPointButton->Visible = true;
                verticalShift = -8;
                horizontalShift = -8;
        }

        // odbicie pilki od paletki lewej
        else if ((ball->Left < paddleLeft->Left + paddleLeft->Width &&
                ball->Top + ball->Height/2 <= paddleLeft->Top + paddleLeft->Height &&
                ball->Top + ball->Height/2 >= paddleLeft->Top))
        {
                verticalShift = 1.2 * verticalShift;
                countBounces++;
                if(verticalShift < 0)
                {
                        //Strefa górna
                        if ((ball->Left <= paddleLeft->Left + paddleLeft->Width &&
                             ball->Top + ball->Height/2 < paddleLeft->Top + paddleLeft->Height/3 &&
                             ball->Top + ball->Height/2 >= paddleLeft->Top))
                        {
                                verticalShift = -  0.9 * verticalShift;
                                horizontalShift = 0.9 * horizontalShift;
                        }

                        //strefa srodkowa
                        else if ((ball->Left <= paddleLeft->Left + paddleLeft->Width &&
                                  ball->Top + ball->Height/2 <= paddleLeft->Top + 2 * paddleLeft->Height/3 &&
                                  ball->Top + ball->Height/2 >= paddleLeft->Top + paddleLeft->Height/3))
                        {
                                verticalShift = -1.2 * verticalShift;
                        }
                        //strefa dolne
                        else if ((ball->Left <= paddleLeft->Left + paddleLeft->Width &&
                                  ball->Top + ball->Height/2 <= paddleLeft->Top +  paddleLeft->Height &&
                                  ball->Top + ball->Height/2 > paddleLeft->Top + 2/3 * paddleLeft->Height))
                        {
                                verticalShift = -0.9 * verticalShift;
                                horizontalShift = 0.9 * horizontalShift;
                        }
                }
        }
        //odbicie pilki od paletki prawej
        else if ((ball->Left + ball->Width >= paddleRight->Left  &&
                  ball->Top + ball->Height/2 <= paddleRight->Top + paddleRight->Height &&
                  ball->Top + ball->Height/2 >= paddleRight->Top))
            {
                verticalShift =  1.2 * verticalShift;
                countBounces++;
                if(verticalShift > 0)
                {
                        //Strefa górna
                        if ((ball->Left + ball->Width >= paddleRight->Left &&
                             ball->Top + ball->Height/2 < paddleRight->Top + paddleRight->Height/3 &&
                             ball->Top + ball->Height/2 >= paddleRight->Top))
                        {
                                verticalShift = -  0.9 * verticalShift;
                                horizontalShift = 0.9 * horizontalShift;
                        }

                        //strefa srodkowa
                        else if ((ball->Left <= paddleRight->Left + paddleRight->Width &&
                                  ball->Top + ball->Height/2 <= paddleRight->Top + 2 * paddleRight->Height/3 &&
                                  ball->Top + ball->Height/2 >= paddleRight->Top + paddleRight->Height/3))
                        {
                                verticalShift = - 1.2*verticalShift;
                        }
                        //strefa dolna
                        else if ((ball->Left <= paddleRight->Left + paddleRight->Width &&
                                  ball->Top + ball->Height/2 <= paddleRight->Top +  paddleRight->Height &&
                                  ball->Top + ball->Height/2 > paddleRight->Top + 2/3 * paddleRight->Height))
                        {
                                verticalShift = -0.9 * verticalShift;
                                horizontalShift = 0.9 * horizontalShift;
                        }
                }
           }

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

void __fastcall TForm1::newGameButtonClick(TObject *Sender)
{
        if(Application->MessageBoxA(
                "Are you sure to start new Game ?",
                "New Game",
                MB_OKCANCEL) == IDOK)
        {
                if(startGame == false){

                        ball->Left = 450;
                        ball->Top = 250;
                        startGame = true;
                        ball->Visible = true;
                        int horizontalShift = 8;
                        int verticalShift = 8;
                        TimerBall->Enabled = true;
                        Form1->newGameButton->Visible = false;
                        Form1->startStatement->Visible = false;
                        Form1->scoreButton->Visible = false;
                        Form1->bouncesButton->Visible = false;
                        Form1->nextRoundButton->Visible = false;
                        Form1->rightPlayerPointButton->Visible = false;
                        Form1->leftPlayerPointButton->Visible = false;
                        countBounces = 0;
                        leftPlayerPoints = 0;
                        rightPlayerPoints = 0;
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::nextRoundButtonClick(TObject *Sender)
{
        if(startGame == false){

                ball->Left = 450;
                ball->Top = 250;
                startGame = true;
                ball->Visible = true;
                int horizontalShift = 8;
                int verticalShift = 8;
                TimerBall->Enabled = true;
                Form1->newGameButton->Visible = false;
                Form1->startStatement->Visible = false;
                Form1->scoreButton->Visible = false;
                Form1->bouncesButton->Visible = false;
                Form1->nextRoundButton->Visible = false;
                Form1->rightPlayerPointButton->Visible = false;
                Form1->leftPlayerPointButton->Visible = false;
                countBounces = 0;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormActivate(TObject *Sender)
{
        Application->MessageBoxA(
                        "Hello in Ping pong game.\n"
                        "The left player uses A to move up and Z to move down.\n"
                        "The right player uses PgUp to move up and PgDn to move down.\n\n"
                        "To add variety to the fun:\n"
                        "When you bounce the ball in the middle of the paddle, then you change its angle and the ball will accelerate.\n"
                        "The longer you bounce, the faster the ball moves.\n"
                        "You can freely change the playing field.\n\n"
                        "Have fun !\n",
                        "Pingpong", MB_OK);
}
//---------------------------------------------------------------------------















