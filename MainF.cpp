#include "MainF.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Notepad2::MainF form;
	Application::Run(%form);
}