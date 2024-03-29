//---------------------------------------------------------------------------

#ifndef ChildH
#define ChildH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormChild : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *N1;
	TMenuItem *ItemNew;
	TMenuItem *ItemOpen;
	TMenuItem *N10;
	TMenuItem *ItemSetupPrinter;
	TMenuItem *N5;
	TMenuItem *ItemExit;
	TMenuItem *N2;
	TMenuItem *ItemTopic;
	TMenuItem *N8;
	TMenuItem *ItemAbout;
	TMenuItem *N3;
	TMenuItem *ItemUndo;
	TMenuItem *ItemRender;
	TMenuItem *N11;
	TMenuItem *ItemClose;
	TMenuItem *ItemCloseAll;
	TMenuItem *ItemSave;
	TMenuItem *ItemSaveAs;
	TMenuItem *N6;
	TMenuItem *ItemPrint;
	TPanel *Panel1;
	TEdit *Edit1;
	TEdit *Edit3;
	TEdit *Edit2;
	TSplitter *Splitter2;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TSplitter *Splitter1;
	TStringGrid *StringGrid1;
	TBevel *Bevel1;
    TMenuItem *ItemMain;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ItemNewClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ItemCloseClick(TObject *Sender);
	void __fastcall ItemCloseAllClick(TObject *Sender);
	void __fastcall ItemOpenClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
  //  void __fastcall ItemAddClick(TObject *Sender)

private:	// User declarations
	AnsiString strProjectName;  //项目名称
    AnsiString strFileName;
	void OnWindow(TMessage & msg); //项目文件名称
    bool bCloseAll;
public:
	AnsiString GetFileName(){	return strFileName.Trim(); }
	void SetFileName(AnsiString FileName) { strFileName=FileName;}
	void LoadInfo(void);
    void UpdateInfo();
public:		// User declarations

	__fastcall TFormChild(TComponent* Owner);
    void 	SetWindowList( void );
protected:
	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_COMMAND, TMessage, OnWindow)
	END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TFormChild *FormChild;
//---------------------------------------------------------------------------
#endif
