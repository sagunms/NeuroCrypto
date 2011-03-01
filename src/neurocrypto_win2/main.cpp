/*  [main.cpp : Main project file]
=========================================
    		NEURO-CRYPTO v3.0
-----------------------------------------	
 A proof-of-concept demonstration of
 Neural Cryptography - a novel approach 
 to public-key cryptography using 
 Tree Parity Machine - a variant of 
       Artificial Neural Networks
-----------------------------------------
 Created by: Sagun Man Singh
 Date: Fri, Oct 29. 2010 @ 1:30 PM
 Email: sagunms@gmail.com
 Website: http://sagunms.wordpress.com
 -----------------------------------------
 Started = Fri, Oct 8, 2010 @ 3:00 PM
 Latest = Fri, Oct 29. 2010 @ 1:30 PM
        (Duration = 21 days)
==========================================
*/
#include "stdafx.h"
#include "frmMain.h"

using namespace NeuralCryptography;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew frmMain());
	return 0;
}
