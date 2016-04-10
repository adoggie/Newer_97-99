//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Child.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TFormMain::~TFormMain()
{


}
//------------------------------------------------------------------------------------
void __fastcall TFormMain::ItemNewClick(TObject *Sender)
{
   	AddChildForm(new TFormChild(0));
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCreate(TObject *Sender)
{

	f_ChildList=new TList;
    f_ActiveForm=NULL;
    f_DelFormChild=NULL;

}
//---------------------------------------------------------------------------
void TFormMain::AddChildForm(TFormChild *Form)
{
   //	f_ChildList->Add(Form);
	//f_ActiveForm->SetWindowList(f_ChildList);
    //TMenuItem *Item=new TMenuItem(this);
    //Item->Caption=Form->Caption;

}

//------------------------------------------------------------------------------------
void TFormMain::DelChildForm(TFormChild *Form)
{
	if(MDIChildCount==1)
    {
     	btnSave->Enabled=false;
    }

}
//------------------------------------------------------------------------------------
void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	//if(!f_ChildList) delete f_ChildList;
    for(int i=0;i<f_ChildList->Count;i++)
    {
    	delete (TFormChild *)f_ChildList->Items[i];
    }
    delete f_ChildList;

}
//---------------------------------------------------------------------------
int TFormMain::GetMaxChild(void)
{
 	return (f_ChildList->Count+1);
}
//------------------------------------------------------------------------------------
void TFormMain::CloseAll(void)
{
    for(int i=0;i<MDIChildCount;i++)
    {
     	((TFormChild *)MDIChildren[i])->Close();
    }

}
void __fastcall TFormMain::ItemOpenClick(TObject *Sender)
{

    AnsiString strFileName;
    if(!OpenDlg->Execute()) return;
    strFileName=OpenDlg->FileName;

    TFormChild * f=new TFormChild(0);
	AddChildForm(f);
//    f->LoadInfo(strFileName);

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ItemAboutClick(TObject *Sender)
{
	TFormAbout *About=new TFormAbout(this);
    About->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ItemExitClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::SysTimeTimer(TObject *Sender)
{
//
    int PanelCount=stbar->Panels->Count;
    TDateTime dt=Now();
	stbar->Panels->Items[PanelCount-1]->Text=dt.TimeString();



}
//---------------------------------------------------------------------------
void TFormMain::SetActiveForm(TFormChild * Me)
{
	f_ActiveForm=Me;
//    this->Caption=f_ActiveForm->strFileName;
}
void __fastcall TFormMain::btnSaveClick(TObject *Sender)
{
    Begin:
    TFormChild * Child=(TFormChild *)FormMain->ActiveMDIChild;
    if(Child->GetFileName()!="")
    {
     // do	Something
     //  ---- 将本工程信息保存
     Child->UpdateInfo();
     return;
    }
	if(!SaveDlg->Execute())	return ;

    Child->SetFileName(SaveDlg->FileName);

    goto Begin;


}
//---------------------------------------------------------------------------


void TFormMain::OnWindow(TMessage & msg)
{
//  ShowMessage(AnsiString(LOWORD(msg.WParam)) +" father");
 // TMenuItem *List= this->WindowMenu->Items[WindowMenu->Count-1];
 // ShowMessage(List->Caption);
  TForm::Dispatch(&msg);
}

void TFormMain::SetWindowList(TFormChild * FormChild,bool Flag)
{
   //     ShowMessage("active");
    this->cbFileList->Clear();
    int CurSelIndex=-1;
    for(int i=0;i<MDIChildCount;i++)
    {

            cbFileList->Items->Add(ExtractFileName( MDIChildren[i]->Caption));
            if(MDIChildren[i]==FormChild)
            {

                CurSelIndex=i;
            }
     }
    cbFileList->ItemIndex=CurSelIndex;

    if(GetDelFormChild()!=NULL)
    {
        if(cbFileList->Items->Count>1)
        cbFileList->Items->Delete(1);
        else
        cbFileList->Items->Clear();

    }
    SetDelFormChild((TFormChild *)NULL);

}





void __fastcall TFormMain::cbFileListChange(TObject *Sender)
{
    if(this->cbFileList->Items->Count==0||cbFileList->ItemIndex==-1)   return;
    TForm  * SelForm;
    SelForm= MDIChildren[cbFileList->ItemIndex];
    SelForm->Show();

}
//---------------------------------------------------------------------------

