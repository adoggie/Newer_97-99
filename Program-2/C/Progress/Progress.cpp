//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Progress.res");
USEFORM("Main.cpp", FormMain);
USEFORM("Child.cpp", FormChild);
USEFORM("About.cpp", FormAbout);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------


