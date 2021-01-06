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
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *paddleLeft;
        TImage *paddleRight;
        TImage *ball;
        TTimer *TimerBall;
        TTimer *timerUpPaddleLeft;
        TTimer *timerDownPaddleLeft;
        TTimer *timerUpPaddleRight;
        TTimer *timerDownPaddleRight;
        TButton *newGameButton;
        TButton *nextRoundButton;
        TButton *bouncesButton;
        TButton *scoreButton;
        TButton *rightPlayerPointButton;
        TButton *leftPlayerPointButton;
        TButton *startStatement;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall timerUpPaddleRightTimer(TObject *Sender);
        void __fastcall timerDownPaddleRightTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall timerUpPaddleLeftTimer(TObject *Sender);
        void __fastcall timerDownPaddleLeftTimer(TObject *Sender);
        void __fastcall newGameButtonClick(TObject *Sender);
        void __fastcall nextRoundButtonClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
