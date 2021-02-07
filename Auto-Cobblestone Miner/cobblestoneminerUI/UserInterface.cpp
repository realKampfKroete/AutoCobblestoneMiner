#include "UserInterface.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	cobblestoneminerUI::UserInterface form;
	Application::Run(% form);
}


