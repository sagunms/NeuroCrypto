/*[frmMain.h for GUI and main iteration]
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

#include "neurocrypto.h"
#include < stdio.h >
#include < stdlib.h >
#include < vcclr.h >

#pragma once

namespace NeuralCryptography {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Text;
	using namespace System::IO;
	using namespace System::Security::Cryptography;

	NeuroCrypto* nc = NULL;		//Instantiate object of the main NeuroCrypto class
	//Variable Declarations
	int i, ii, ss, itrMax, itrActual = 1, itrActualtemp, j;
	int K, sum, key_size, key_length, dataExchanged;
	int valK, valN, valL, gridElementA, gridElementB, gridElementAB, initialGridCountFlag;
	int timer_itrMax = 1;	//Keeps track of the number times the main publickey generation loop has to iterate
	bool state_StartPause, state_FreshStart, state_beginTick, state_SlowMo;
	int sumMax, lineOriginX, lineOriginY, lineFinalX, lineFinalY;	//For Differnce graph plot


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			desObj = Rijndael::Create();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
    private:
			String^ cipherData;
			// final encrypted data
			//Byte cipherbytes[];
			array<Byte>^ cipherbytes;
			array<Byte>^ plainbytes;
			array<Byte>^ plainbytes2;
			array<Byte>^ plainKey;
			// byte form of plaintext
			//Byte plainbytes[];

			//Byte plainKey[];
			// creating instance of DES class
			SymmetricAlgorithm^ desObj;

	private: System::Windows::Forms::GroupBox^  group_Initial;
	protected: 

	protected: 

	private: System::Windows::Forms::DataGridView^  grid_A;
	private: System::Windows::Forms::GroupBox^  group_Params;

	protected:

	private: System::Windows::Forms::Button^  button_Sync;

	private: System::Windows::Forms::Label^  label_L;
	private: System::Windows::Forms::Label^  label_N;
	private: System::Windows::Forms::Label^  label_K;
	private: System::Windows::Forms::NumericUpDown^  updn_L;
	private: System::Windows::Forms::NumericUpDown^  updn_N;
	private: System::Windows::Forms::NumericUpDown^  updn_K;
	private: System::Windows::Forms::StatusStrip^  status_NeuroCrypto;

	private: System::Windows::Forms::ToolStripStatusLabel^  status_Message;
	private: System::Windows::Forms::GroupBox^  group_Results;


	private: System::Windows::Forms::TextBox^  text_Key;
	private: System::Windows::Forms::Label^  label_Key;
	private: System::Windows::Forms::TextBox^  text_KB;
	private: System::Windows::Forms::Label^  labelKB;



	private: System::Windows::Forms::TextBox^  text_KeyLength;
	private: System::Windows::Forms::Label^  label_KeyLength;


	private: System::Windows::Forms::TextBox^  text_ActualItr;
	private: System::Windows::Forms::Label^  label_ActualItr;


	private: System::Windows::Forms::TextBox^  text_MaxItr;
	private: System::Windows::Forms::Label^  label_MaxItr;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  grid_B;

	private: System::Windows::Forms::Button^  button_Close;
	private: System::Windows::Forms::Button^  button_About;
	private: System::Windows::Forms::Timer^  timer_Itr;
	private: System::Windows::Forms::Button^  button_Stop;
	private: System::Windows::Forms::CheckBox^  check_SlowMo;
	private: System::Windows::Forms::Label^  label_Delay;
	private: System::Windows::Forms::NumericUpDown^  updn_Delay;
	private: System::Windows::Forms::ToolStripStatusLabel^  status_Itr;

	private: System::Windows::Forms::PictureBox^  picture_Graph;

	private: System::Windows::Forms::Button^  button_SyncTurbo;



	private: System::Windows::Forms::GroupBox^  group_Rijndael;
	private: System::Windows::Forms::Button^  button_Encrypt;
	private: System::Windows::Forms::Button^  button_Decrypt;
	private: System::Windows::Forms::TextBox^  text_Decrypt;
	private: System::Windows::Forms::Label^  label_Decrypt;
	private: System::Windows::Forms::TextBox^  text_Encrypt;
	private: System::Windows::Forms::Label^  label_Encrypt;
	private: System::Windows::Forms::TextBox^  text_Plain;
	private: System::Windows::Forms::Label^  label_Plain;








	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->group_Initial = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->grid_B = (gcnew System::Windows::Forms::DataGridView());
			this->grid_A = (gcnew System::Windows::Forms::DataGridView());
			this->group_Params = (gcnew System::Windows::Forms::GroupBox());
			this->button_SyncTurbo = (gcnew System::Windows::Forms::Button());
			this->check_SlowMo = (gcnew System::Windows::Forms::CheckBox());
			this->label_Delay = (gcnew System::Windows::Forms::Label());
			this->updn_Delay = (gcnew System::Windows::Forms::NumericUpDown());
			this->button_Stop = (gcnew System::Windows::Forms::Button());
			this->button_Sync = (gcnew System::Windows::Forms::Button());
			this->label_L = (gcnew System::Windows::Forms::Label());
			this->label_N = (gcnew System::Windows::Forms::Label());
			this->label_K = (gcnew System::Windows::Forms::Label());
			this->updn_L = (gcnew System::Windows::Forms::NumericUpDown());
			this->updn_N = (gcnew System::Windows::Forms::NumericUpDown());
			this->updn_K = (gcnew System::Windows::Forms::NumericUpDown());
			this->status_NeuroCrypto = (gcnew System::Windows::Forms::StatusStrip());
			this->status_Message = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->status_Itr = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->group_Results = (gcnew System::Windows::Forms::GroupBox());
			this->picture_Graph = (gcnew System::Windows::Forms::PictureBox());
			this->button_Close = (gcnew System::Windows::Forms::Button());
			this->button_About = (gcnew System::Windows::Forms::Button());
			this->text_Key = (gcnew System::Windows::Forms::TextBox());
			this->label_Key = (gcnew System::Windows::Forms::Label());
			this->text_KB = (gcnew System::Windows::Forms::TextBox());
			this->labelKB = (gcnew System::Windows::Forms::Label());
			this->text_KeyLength = (gcnew System::Windows::Forms::TextBox());
			this->label_KeyLength = (gcnew System::Windows::Forms::Label());
			this->text_ActualItr = (gcnew System::Windows::Forms::TextBox());
			this->label_ActualItr = (gcnew System::Windows::Forms::Label());
			this->text_MaxItr = (gcnew System::Windows::Forms::TextBox());
			this->label_MaxItr = (gcnew System::Windows::Forms::Label());
			this->timer_Itr = (gcnew System::Windows::Forms::Timer(this->components));
			this->group_Rijndael = (gcnew System::Windows::Forms::GroupBox());
			this->button_Encrypt = (gcnew System::Windows::Forms::Button());
			this->button_Decrypt = (gcnew System::Windows::Forms::Button());
			this->text_Decrypt = (gcnew System::Windows::Forms::TextBox());
			this->label_Decrypt = (gcnew System::Windows::Forms::Label());
			this->text_Encrypt = (gcnew System::Windows::Forms::TextBox());
			this->label_Encrypt = (gcnew System::Windows::Forms::Label());
			this->text_Plain = (gcnew System::Windows::Forms::TextBox());
			this->label_Plain = (gcnew System::Windows::Forms::Label());
			this->group_Initial->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grid_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grid_A))->BeginInit();
			this->group_Params->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updn_Delay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updn_L))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updn_N))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updn_K))->BeginInit();
			this->status_NeuroCrypto->SuspendLayout();
			this->group_Results->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture_Graph))->BeginInit();
			this->group_Rijndael->SuspendLayout();
			this->SuspendLayout();
			// 
			// group_Initial
			// 
			this->group_Initial->Controls->Add(this->label2);
			this->group_Initial->Controls->Add(this->label1);
			this->group_Initial->Controls->Add(this->grid_B);
			this->group_Initial->Controls->Add(this->grid_A);
			this->group_Initial->Location = System::Drawing::Point(12, 12);
			this->group_Initial->Name = L"group_Initial";
			this->group_Initial->Size = System::Drawing::Size(466, 215);
			this->group_Initial->TabIndex = 0;
			this->group_Initial->TabStop = false;
			this->group_Initial->Text = L"Weights of Tree Parity Machines";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(240, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(213, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Terminal B";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(213, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Terminal A";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// grid_B
			// 
			this->grid_B->AllowUserToAddRows = false;
			this->grid_B->AllowUserToDeleteRows = false;
			this->grid_B->AllowUserToResizeColumns = false;
			this->grid_B->AllowUserToResizeRows = false;
			this->grid_B->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->grid_B->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->grid_B->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid_B->ColumnHeadersVisible = false;
			this->grid_B->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->grid_B->Location = System::Drawing::Point(242, 39);
			this->grid_B->Name = L"grid_B";
			this->grid_B->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->grid_B->RowHeadersVisible = false;
			this->grid_B->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->grid_B->Size = System::Drawing::Size(210, 162);
			this->grid_B->TabIndex = 1;
			// 
			// grid_A
			// 
			this->grid_A->AllowUserToAddRows = false;
			this->grid_A->AllowUserToDeleteRows = false;
			this->grid_A->AllowUserToResizeColumns = false;
			this->grid_A->AllowUserToResizeRows = false;
			this->grid_A->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->grid_A->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->grid_A->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid_A->ColumnHeadersVisible = false;
			this->grid_A->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->grid_A->Location = System::Drawing::Point(14, 39);
			this->grid_A->Name = L"grid_A";
			this->grid_A->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->grid_A->RowHeadersVisible = false;
			this->grid_A->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->grid_A->Size = System::Drawing::Size(210, 162);
			this->grid_A->TabIndex = 0;
			// 
			// group_Params
			// 
			this->group_Params->Controls->Add(this->button_SyncTurbo);
			this->group_Params->Controls->Add(this->check_SlowMo);
			this->group_Params->Controls->Add(this->label_Delay);
			this->group_Params->Controls->Add(this->updn_Delay);
			this->group_Params->Controls->Add(this->button_Stop);
			this->group_Params->Controls->Add(this->button_Sync);
			this->group_Params->Controls->Add(this->label_L);
			this->group_Params->Controls->Add(this->label_N);
			this->group_Params->Controls->Add(this->label_K);
			this->group_Params->Controls->Add(this->updn_L);
			this->group_Params->Controls->Add(this->updn_N);
			this->group_Params->Controls->Add(this->updn_K);
			this->group_Params->Location = System::Drawing::Point(12, 241);
			this->group_Params->Name = L"group_Params";
			this->group_Params->Size = System::Drawing::Size(466, 109);
			this->group_Params->TabIndex = 3;
			this->group_Params->TabStop = false;
			this->group_Params->Text = L"Tree Parity Machine Parameters";
			// 
			// button_SyncTurbo
			// 
			this->button_SyncTurbo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_SyncTurbo->Location = System::Drawing::Point(242, -22);
			this->button_SyncTurbo->Name = L"button_SyncTurbo";
			this->button_SyncTurbo->Size = System::Drawing::Size(124, 46);
			this->button_SyncTurbo->TabIndex = 19;
			this->button_SyncTurbo->Text = L"Turbo Sync";
			this->button_SyncTurbo->UseVisualStyleBackColor = true;
			this->button_SyncTurbo->Visible = false;
			this->button_SyncTurbo->Click += gcnew System::EventHandler(this, &frmMain::button_SyncTurbo_Click);
			// 
			// check_SlowMo
			// 
			this->check_SlowMo->AutoSize = true;
			this->check_SlowMo->Checked = true;
			this->check_SlowMo->CheckState = System::Windows::Forms::CheckState::Checked;
			this->check_SlowMo->Location = System::Drawing::Point(376, 80);
			this->check_SlowMo->Name = L"check_SlowMo";
			this->check_SlowMo->Size = System::Drawing::Size(84, 17);
			this->check_SlowMo->TabIndex = 16;
			this->check_SlowMo->Text = L"Slow Motion";
			this->check_SlowMo->UseVisualStyleBackColor = true;
			this->check_SlowMo->CheckedChanged += gcnew System::EventHandler(this, &frmMain::check_SlowMo_CheckedChanged);
			// 
			// label_Delay
			// 
			this->label_Delay->AutoSize = true;
			this->label_Delay->Location = System::Drawing::Point(244, 81);
			this->label_Delay->Name = L"label_Delay";
			this->label_Delay->Size = System::Drawing::Size(56, 13);
			this->label_Delay->TabIndex = 15;
			this->label_Delay->Text = L"Delay (ms)";
			// 
			// updn_Delay
			// 
			this->updn_Delay->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->updn_Delay->Location = System::Drawing::Point(306, 79);
			this->updn_Delay->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->updn_Delay->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->updn_Delay->Name = L"updn_Delay";
			this->updn_Delay->Size = System::Drawing::Size(60, 20);
			this->updn_Delay->TabIndex = 14;
			this->updn_Delay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->updn_Delay->ValueChanged += gcnew System::EventHandler(this, &frmMain::updn_Delay_ValueChanged);
			// 
			// button_Stop
			// 
			this->button_Stop->Location = System::Drawing::Point(372, 24);
			this->button_Stop->Name = L"button_Stop";
			this->button_Stop->Size = System::Drawing::Size(80, 46);
			this->button_Stop->TabIndex = 13;
			this->button_Stop->Text = L"Stop";
			this->button_Stop->UseVisualStyleBackColor = true;
			this->button_Stop->Click += gcnew System::EventHandler(this, &frmMain::button_Stop_Click);
			// 
			// button_Sync
			// 
			this->button_Sync->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_Sync->Location = System::Drawing::Point(242, 24);
			this->button_Sync->Name = L"button_Sync";
			this->button_Sync->Size = System::Drawing::Size(124, 46);
			this->button_Sync->TabIndex = 12;
			this->button_Sync->Text = L"Slow Sync";
			this->button_Sync->UseVisualStyleBackColor = true;
			this->button_Sync->Click += gcnew System::EventHandler(this, &frmMain::button_Sync_Click);
			// 
			// label_L
			// 
			this->label_L->AutoSize = true;
			this->label_L->Location = System::Drawing::Point(20, 78);
			this->label_L->Name = L"label_L";
			this->label_L->Size = System::Drawing::Size(91, 13);
			this->label_L->TabIndex = 11;
			this->label_L->Text = L"Weight Range (L)";
			// 
			// label_N
			// 
			this->label_N->AutoSize = true;
			this->label_N->Location = System::Drawing::Point(20, 52);
			this->label_N->Name = L"label_N";
			this->label_N->Size = System::Drawing::Size(91, 13);
			this->label_N->TabIndex = 10;
			this->label_N->Text = L"Input Neurons (N)";
			// 
			// label_K
			// 
			this->label_K->AutoSize = true;
			this->label_K->Location = System::Drawing::Point(11, 26);
			this->label_K->Name = L"label_K";
			this->label_K->Size = System::Drawing::Size(100, 13);
			this->label_K->TabIndex = 9;
			this->label_K->Text = L"Hidden Neurons (K)";
			// 
			// updn_L
			// 
			this->updn_L->Location = System::Drawing::Point(121, 76);
			this->updn_L->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {7, 0, 0, 0});
			this->updn_L->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->updn_L->Name = L"updn_L";
			this->updn_L->Size = System::Drawing::Size(103, 20);
			this->updn_L->TabIndex = 8;
			this->updn_L->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// updn_N
			// 
			this->updn_N->Location = System::Drawing::Point(121, 50);
			this->updn_N->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->updn_N->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			this->updn_N->Name = L"updn_N";
			this->updn_N->Size = System::Drawing::Size(103, 20);
			this->updn_N->TabIndex = 7;
			this->updn_N->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {8, 0, 0, 0});
			// 
			// updn_K
			// 
			this->updn_K->Location = System::Drawing::Point(121, 24);
			this->updn_K->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->updn_K->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			this->updn_K->Name = L"updn_K";
			this->updn_K->Size = System::Drawing::Size(103, 20);
			this->updn_K->TabIndex = 6;
			this->updn_K->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {6, 0, 0, 0});
			// 
			// status_NeuroCrypto
			// 
			this->status_NeuroCrypto->AutoSize = false;
			this->status_NeuroCrypto->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->status_Message, 
				this->status_Itr});
			this->status_NeuroCrypto->Location = System::Drawing::Point(0, 590);
			this->status_NeuroCrypto->Name = L"status_NeuroCrypto";
			this->status_NeuroCrypto->Size = System::Drawing::Size(711, 22);
			this->status_NeuroCrypto->SizingGrip = false;
			this->status_NeuroCrypto->Stretch = false;
			this->status_NeuroCrypto->TabIndex = 6;
			this->status_NeuroCrypto->Text = L"statusStrip";
			// 
			// status_Message
			// 
			this->status_Message->AutoSize = false;
			this->status_Message->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->status_Message->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->status_Message->Name = L"status_Message";
			this->status_Message->Size = System::Drawing::Size(405, 17);
			this->status_Message->Text = L"Press \'Synchronize\' to synchronize TPM Neural Networks.";
			this->status_Message->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// status_Itr
			// 
			this->status_Itr->AutoSize = false;
			this->status_Itr->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->status_Itr->Name = L"status_Itr";
			this->status_Itr->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->status_Itr->Size = System::Drawing::Size(85, 17);
			this->status_Itr->Text = L"Iteration: 0";
			this->status_Itr->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// group_Results
			// 
			this->group_Results->Controls->Add(this->picture_Graph);
			this->group_Results->Controls->Add(this->button_Close);
			this->group_Results->Controls->Add(this->button_About);
			this->group_Results->Controls->Add(this->text_Key);
			this->group_Results->Controls->Add(this->label_Key);
			this->group_Results->Controls->Add(this->text_KB);
			this->group_Results->Controls->Add(this->labelKB);
			this->group_Results->Controls->Add(this->text_KeyLength);
			this->group_Results->Controls->Add(this->label_KeyLength);
			this->group_Results->Controls->Add(this->text_ActualItr);
			this->group_Results->Controls->Add(this->label_ActualItr);
			this->group_Results->Controls->Add(this->text_MaxItr);
			this->group_Results->Controls->Add(this->label_MaxItr);
			this->group_Results->Location = System::Drawing::Point(12, 356);
			this->group_Results->Name = L"group_Results";
			this->group_Results->Size = System::Drawing::Size(466, 224);
			this->group_Results->TabIndex = 7;
			this->group_Results->TabStop = false;
			this->group_Results->Text = L"Synchronization Results of Terminals A and B ";
			// 
			// picture_Graph
			// 
			this->picture_Graph->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->picture_Graph->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picture_Graph->Location = System::Drawing::Point(241, 19);
			this->picture_Graph->Name = L"picture_Graph";
			this->picture_Graph->Size = System::Drawing::Size(211, 158);
			this->picture_Graph->TabIndex = 28;
			this->picture_Graph->TabStop = false;
			// 
			// button_Close
			// 
			this->button_Close->Location = System::Drawing::Point(128, 131);
			this->button_Close->Name = L"button_Close";
			this->button_Close->Size = System::Drawing::Size(96, 49);
			this->button_Close->TabIndex = 27;
			this->button_Close->Text = L"Close";
			this->button_Close->UseVisualStyleBackColor = true;
			this->button_Close->Click += gcnew System::EventHandler(this, &frmMain::button_Close_Click);
			// 
			// button_About
			// 
			this->button_About->Location = System::Drawing::Point(19, 131);
			this->button_About->Name = L"button_About";
			this->button_About->Size = System::Drawing::Size(96, 49);
			this->button_About->TabIndex = 26;
			this->button_About->Text = L"About";
			this->button_About->UseVisualStyleBackColor = true;
			this->button_About->Click += gcnew System::EventHandler(this, &frmMain::button_About_Click);
			// 
			// text_Key
			// 
			this->text_Key->Location = System::Drawing::Point(67, 192);
			this->text_Key->Name = L"text_Key";
			this->text_Key->ReadOnly = true;
			this->text_Key->Size = System::Drawing::Size(385, 20);
			this->text_Key->TabIndex = 24;
			// 
			// label_Key
			// 
			this->label_Key->AutoSize = true;
			this->label_Key->Location = System::Drawing::Point(6, 195);
			this->label_Key->Name = L"label_Key";
			this->label_Key->Size = System::Drawing::Size(60, 13);
			this->label_Key->TabIndex = 23;
			this->label_Key->Text = L"Public Key:";
			// 
			// text_KB
			// 
			this->text_KB->Location = System::Drawing::Point(121, 98);
			this->text_KB->Name = L"text_KB";
			this->text_KB->ReadOnly = true;
			this->text_KB->Size = System::Drawing::Size(103, 20);
			this->text_KB->TabIndex = 22;
			// 
			// labelKB
			// 
			this->labelKB->AutoSize = true;
			this->labelKB->Location = System::Drawing::Point(11, 101);
			this->labelKB->Name = L"labelKB";
			this->labelKB->Size = System::Drawing::Size(104, 13);
			this->labelKB->TabIndex = 21;
			this->labelKB->Text = L"Data Exchange (KB)";
			// 
			// text_KeyLength
			// 
			this->text_KeyLength->Location = System::Drawing::Point(121, 72);
			this->text_KeyLength->Name = L"text_KeyLength";
			this->text_KeyLength->ReadOnly = true;
			this->text_KeyLength->Size = System::Drawing::Size(103, 20);
			this->text_KeyLength->TabIndex = 20;
			// 
			// label_KeyLength
			// 
			this->label_KeyLength->AutoSize = true;
			this->label_KeyLength->Location = System::Drawing::Point(20, 75);
			this->label_KeyLength->Name = L"label_KeyLength";
			this->label_KeyLength->Size = System::Drawing::Size(97, 13);
			this->label_KeyLength->TabIndex = 19;
			this->label_KeyLength->Text = L"Key Length (Chars)";
			// 
			// text_ActualItr
			// 
			this->text_ActualItr->Location = System::Drawing::Point(121, 19);
			this->text_ActualItr->Name = L"text_ActualItr";
			this->text_ActualItr->ReadOnly = true;
			this->text_ActualItr->Size = System::Drawing::Size(103, 20);
			this->text_ActualItr->TabIndex = 18;
			// 
			// label_ActualItr
			// 
			this->label_ActualItr->AutoSize = true;
			this->label_ActualItr->Location = System::Drawing::Point(34, 22);
			this->label_ActualItr->Name = L"label_ActualItr";
			this->label_ActualItr->Size = System::Drawing::Size(83, 13);
			this->label_ActualItr->TabIndex = 17;
			this->label_ActualItr->Text = L"Actual Iterations";
			// 
			// text_MaxItr
			// 
			this->text_MaxItr->Location = System::Drawing::Point(121, 45);
			this->text_MaxItr->Name = L"text_MaxItr";
			this->text_MaxItr->ReadOnly = true;
			this->text_MaxItr->Size = System::Drawing::Size(102, 20);
			this->text_MaxItr->TabIndex = 16;
			// 
			// label_MaxItr
			// 
			this->label_MaxItr->AutoSize = true;
			this->label_MaxItr->Location = System::Drawing::Point(20, 48);
			this->label_MaxItr->Name = L"label_MaxItr";
			this->label_MaxItr->Size = System::Drawing::Size(97, 13);
			this->label_MaxItr->TabIndex = 15;
			this->label_MaxItr->Text = L"Maximum Iterations";
			// 
			// timer_Itr
			// 
			this->timer_Itr->Interval = 2;
			this->timer_Itr->Tick += gcnew System::EventHandler(this, &frmMain::timer_Itr_Tick);
			// 
			// group_Rijndael
			// 
			this->group_Rijndael->Controls->Add(this->button_Encrypt);
			this->group_Rijndael->Controls->Add(this->button_Decrypt);
			this->group_Rijndael->Controls->Add(this->text_Decrypt);
			this->group_Rijndael->Controls->Add(this->label_Decrypt);
			this->group_Rijndael->Controls->Add(this->text_Encrypt);
			this->group_Rijndael->Controls->Add(this->label_Encrypt);
			this->group_Rijndael->Controls->Add(this->text_Plain);
			this->group_Rijndael->Controls->Add(this->label_Plain);
			this->group_Rijndael->Location = System::Drawing::Point(484, 12);
			this->group_Rijndael->Name = L"group_Rijndael";
			this->group_Rijndael->Size = System::Drawing::Size(217, 568);
			this->group_Rijndael->TabIndex = 11;
			this->group_Rijndael->TabStop = false;
			this->group_Rijndael->Text = L"Rijndael (AES) Private Key Cryptography";
			// 
			// button_Encrypt
			// 
			this->button_Encrypt->Location = System::Drawing::Point(9, 526);
			this->button_Encrypt->Name = L"button_Encrypt";
			this->button_Encrypt->Size = System::Drawing::Size(96, 30);
			this->button_Encrypt->TabIndex = 27;
			this->button_Encrypt->Text = L"Encrypt";
			this->button_Encrypt->UseVisualStyleBackColor = true;
			this->button_Encrypt->Click += gcnew System::EventHandler(this, &frmMain::button_Encrypt_Click);
			// 
			// button_Decrypt
			// 
			this->button_Decrypt->Location = System::Drawing::Point(111, 526);
			this->button_Decrypt->Name = L"button_Decrypt";
			this->button_Decrypt->Size = System::Drawing::Size(97, 30);
			this->button_Decrypt->TabIndex = 26;
			this->button_Decrypt->Text = L"Decrypt";
			this->button_Decrypt->UseVisualStyleBackColor = true;
			this->button_Decrypt->Click += gcnew System::EventHandler(this, &frmMain::button_Decrypt_Click);
			// 
			// text_Decrypt
			// 
			this->text_Decrypt->Location = System::Drawing::Point(10, 379);
			this->text_Decrypt->MaxLength = 65535;
			this->text_Decrypt->Multiline = true;
			this->text_Decrypt->Name = L"text_Decrypt";
			this->text_Decrypt->ReadOnly = true;
			this->text_Decrypt->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->text_Decrypt->Size = System::Drawing::Size(196, 141);
			this->text_Decrypt->TabIndex = 24;
			// 
			// label_Decrypt
			// 
			this->label_Decrypt->AutoSize = true;
			this->label_Decrypt->Location = System::Drawing::Point(7, 363);
			this->label_Decrypt->Name = L"label_Decrypt";
			this->label_Decrypt->Size = System::Drawing::Size(56, 13);
			this->label_Decrypt->TabIndex = 23;
			this->label_Decrypt->Text = L"Decrypted";
			// 
			// text_Encrypt
			// 
			this->text_Encrypt->Location = System::Drawing::Point(9, 214);
			this->text_Encrypt->MaxLength = 65535;
			this->text_Encrypt->Multiline = true;
			this->text_Encrypt->Name = L"text_Encrypt";
			this->text_Encrypt->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->text_Encrypt->Size = System::Drawing::Size(196, 141);
			this->text_Encrypt->TabIndex = 22;
			// 
			// label_Encrypt
			// 
			this->label_Encrypt->AutoSize = true;
			this->label_Encrypt->Location = System::Drawing::Point(7, 198);
			this->label_Encrypt->Name = L"label_Encrypt";
			this->label_Encrypt->Size = System::Drawing::Size(55, 13);
			this->label_Encrypt->TabIndex = 21;
			this->label_Encrypt->Text = L"Encrypted";
			// 
			// text_Plain
			// 
			this->text_Plain->Location = System::Drawing::Point(9, 41);
			this->text_Plain->MaxLength = 65535;
			this->text_Plain->Multiline = true;
			this->text_Plain->Name = L"text_Plain";
			this->text_Plain->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->text_Plain->Size = System::Drawing::Size(196, 144);
			this->text_Plain->TabIndex = 20;
			this->text_Plain->Text = L"C++ Implementation of Neural Cryptography for Public Key Exchange and Secure Mess" 
				L"age Encryption with Rijndael Cipher.";
			// 
			// label_Plain
			// 
			this->label_Plain->AutoSize = true;
			this->label_Plain->Location = System::Drawing::Point(6, 25);
			this->label_Plain->Name = L"label_Plain";
			this->label_Plain->Size = System::Drawing::Size(54, 13);
			this->label_Plain->TabIndex = 19;
			this->label_Plain->Text = L"Plain Text";
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 612);
			this->Controls->Add(this->group_Rijndael);
			this->Controls->Add(this->group_Results);
			this->Controls->Add(this->status_NeuroCrypto);
			this->Controls->Add(this->group_Params);
			this->Controls->Add(this->group_Initial);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"frmMain";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NeuroCrypto v3.0 by Sagun Man Singh © 2010";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMain::frmMain_FormClosing);
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->group_Initial->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grid_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grid_A))->EndInit();
			this->group_Params->ResumeLayout(false);
			this->group_Params->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updn_Delay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updn_L))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updn_N))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updn_K))->EndInit();
			this->status_NeuroCrypto->ResumeLayout(false);
			this->status_NeuroCrypto->PerformLayout();
			this->group_Results->ResumeLayout(false);
			this->group_Results->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture_Graph))->EndInit();
			this->group_Rijndael->ResumeLayout(false);
			this->group_Rijndael->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	// ===========================================================
	// MAIN PROGRAM ----------------------------------------------
	// ===========================================================
	private: System::Void button_Sync_Click(System::Object^  sender, System::EventArgs^  e) {
				if(state_FreshStart) {
					valK = (int)this->updn_K->Value;
					valN = (int)this->updn_N->Value;
					valL = (int)this->updn_L->Value;
					itrMax = (valL * valL * valL * valL) * valN * valK;
					sumMax = valK * valN * valL / 4;
					timer_itrMax = 1;

					//Create new instance of NeuroCrypto class
					nc = new NeuroCrypto(valK, valN, valL);

					//Find sum
					sum = 0;
					for (ss = 0; ss < valK * valN; ss++)
							sum += abs (nc->A.W.Z[ss] - nc->B.W.Z[ss]);

					grid_A->ColumnCount = valN;
					grid_A->RowCount = valK;
					grid_B->ColumnCount = valN;
					grid_B->RowCount = valK;

					this->status_Message->Text = "Synchronizing TPM...";

					state_FreshStart = false;
					state_StartPause = true;	//Start Mode state

					if(state_SlowMo) {			//according to the SlowMo checkbox setting 
						this->button_Sync->Text = "Pause";
						this->timer_Itr->Enabled = true;	//enable Timer
					}
					else {
						this->button_Sync->Text = "Synchronization";
						this->button_Sync->Enabled = false;
						this->timer_Itr->Enabled = false;

					}

				}
				else {
					if(state_StartPause) {
						while(state_beginTick);		//wait for the operations of timer to end
						this->timer_Itr->Enabled = false;	//disable Timer
						this->button_Sync->Text = "Resume";
						this->status_Message->Text = "Press 'Resume' to continue synchronization...";
						state_StartPause = false;			//Pause Mode state
						state_FreshStart = false;
					}
					else {
						this->button_Sync->Text = "Pause";
						this->status_Message->Text = "Synchronizing TPM...";
						state_StartPause = true;			//Start Mode state
						this->timer_Itr->Enabled = true;	//enable Timer
					}
				}
		}
		// ===========================================================


	private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {
				 //Initialize variables
				 state_StartPause = true;
				 state_FreshStart = true;
				 state_beginTick = false;
				 timer_itrMax = 1;
				 this->timer_Itr->Enabled = false;
				 
				 state_SlowMo = 1;
				 this->check_SlowMo->Checked = true;

				 delete nc;		//destroy NeuroCrypto class instance
				 nc = NULL;

				 this->status_Message->Text = "Press 'Synchronize' to synchronize TPM Neural Networks.";
				 this->button_SyncTurbo->Location = Point(242, 24);		//Put button_SyncTurbo in same location as button_Sync

			 }

	private: System::Void button_Close_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Display a message box asking users if they want to exit the application.
				 if (MessageBox::Show("Do you really want to exit?",
					 "NEURO-CRYPTO v3.0", MessageBoxButtons::YesNo,
					 MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
								finito();				//De-instantiate NeuroCrypto class object nc (free memory)
								Application::Exit();
				 }
			 }

	private: System::Void timer_Itr_Tick(System::Object^  sender, System::EventArgs^  e) {
				 tiktok();		//call the function responsible for iteratively synchronizing Terminals A and B and finding public keys
			 }


	private: System::Void button_Stop_Click(System::Object^  sender, System::EventArgs^  e) {
				 while(state_beginTick);				//wait for the operations of timer to end
				 finito();
				 this->picture_Graph->Refresh();		//clear the graph picturebox
			 }


	private: System::Void check_SlowMo_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				if(this->check_SlowMo->Checked) {		//if user selects the Slow Motion mode
					state_SlowMo = true;
					this->button_SyncTurbo->Visible = false;
					this->button_Sync->Visible = true;
					this->label_Delay->Enabled = true;
					this->updn_Delay->Enabled = true;
					this->timer_Itr->Interval = (int)this->updn_Delay->Value;	//Set Timer delay as specified by the user
					//TO DO: updateflag make sure that the main loop in the timer is available in sync button also
				}
				else {									//if user selects the Turbo Motion mode
					state_SlowMo = false;
					this->button_SyncTurbo->Visible = true;
					this->button_Sync->Visible = false;
					this->label_Delay->Enabled = false;
					this->updn_Delay->Enabled = false;
				}
			 
			}


	private: System::Void updn_Delay_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
					this->timer_Itr->Interval = (int)this->updn_Delay->Value;		//Update Timer interval on change in value specified by user
			 }


	private: void finito(void) {
			 	this->timer_Itr->Enabled = false;		//Disable Timer ticks
				this->button_Sync->Text = "Slow Sync";
				this->button_Sync->Enabled = true;
				state_StartPause = true;			//Start Mode state

				timer_itrMax = 1;			//Rewind the main iteration counter for fresh use
				state_FreshStart = true;	//Fresh start mode is turned on. Now  you can't pause/resume.

				delete nc;					//destroy NeuroCrypto class instance
				nc = NULL;
		 }


	private: void tiktok(void) {
				state_beginTick = true;			//Indicate the timer is now busy synchronizing

				//Graphics declaration for drawing Difference Plot in the picture_Graph pictureBox
				Graphics^ gr = this->picture_Graph->CreateGraphics();
				Pen^ pen = gcnew Pen(Color::Red);

				//--------- MAIN ITERATION FOR SYNCHRONIZATION ---------
				if(timer_itrMax < nc->itrMax)		//Maximum effort to synchronize until itrMax times
				{
						itrActualtemp = timer_itrMax;

						this->status_Itr->Text = String::Concat("Iteration: ", itrActualtemp.ToString());
						timer_itrMax++;

						nc->objInput.CreateRandomVector (valK, valN);
						nc->A.ComputeTPMResult (nc->objInput.X);
						nc->B.ComputeTPMResult (nc->objInput.X);
		
						if (nc->A.TPMOutput == nc->B.TPMOutput) {
							lineOriginX = ( itrActualtemp - 1 ) * this->picture_Graph->Size.Width / itrMax;		//(.8 * itrMax);
							lineOriginY = this->picture_Graph->Size.Height - (int)( ( sum / 5 ) * ( this->picture_Graph->Size.Height ) / sumMax );
							if(itrActualtemp > 2)			//when new synchronization starts, prevent drawing unwanted line from the previous Final x,y to the Initial x,y. If this is continuation of old synchronization, we need to draw
								gr->DrawLine(pen, lineFinalX, lineFinalY, lineOriginX, lineOriginY);

							lineFinalX = itrActualtemp * this->picture_Graph->Size.Width / itrMax;		//(.8 * itrMax);		//scaled down itrMax to 80%
							lineFinalY = this->picture_Graph->Size.Height - (int)( ( sum / 5 ) * ( this->picture_Graph->Size.Height ) / sumMax );	//removed -20 gutter from original
							gr->DrawLine(pen, lineOriginX, lineOriginY, lineFinalX, lineFinalY);

							System::Drawing::Drawing2D::GraphicsState^ graph = gr->Save();	//Save the current graph
							gr->Restore(graph);		//Restore the saved graph so that new lines can be appended with the previous lines
						
							nc->A.UpdateWeight (nc->objInput.X);		
							nc->B.UpdateWeight (nc->objInput.X);

							//Find the sum
							sum = 0;
							for (ss = 0; ss < valK * valN; ss++)
								sum += abs (nc->A.W.Z[ss] - nc->B.W.Z[ss]);
						
							for (ii = 0; ii < valK ; ii++) {
								for (j = 0; j < valN; j++) {
										gridElementA = nc->A.W.Z[ii * valN + j];
										gridElementB = nc->B.W.Z[ii * valN + j];
										this->grid_A->Rows[ii]->Cells[j]->Value = gridElementA.ToString();
										this->grid_B->Rows[ii]->Cells[j]->Value = gridElementB.ToString();
									}
							}
							//Automatically Resize the DataGridView controls just for improving looks (warning: slows the synchronization process down)
							this->grid_A->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
							this->grid_B->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
						
						}
						if (sum == 0)
							timer_itrMax = nc->itrMax;		//If two Terminals A and B are already perfectly synchronized, stop computing and prevent Timer from executing anymore

				}			//end if(timer_itrMax < nc->itrMax)
				else		//else if(timer_itrMax < nc->itrMax)
				{
		 				// Computation of result variables after computation of publickey (whether successful or not)
						itrActual = itrActualtemp;
						key_size = 37 / (valL * 2 + 1);
						key_length = valK * valN / key_size;
						dataExchanged = itrActual * (valK * valN + 4) / 1024;

						// Generation of the final public key
						for (i = 1; i < key_length + 1; i++) {
							K = 1;
							for (j = (i - 1) * key_size; j < i * key_size; j++)
								K = K + nc->A.W.Z[j] + valL;
		
							nc->publickey[i - 1] = Dictionary[K];	//Build publickey from selected characters from the Dictionary one at a time
						}
						nc->publickey[key_length] = '\0';		//Null character at the end to form a standard string

						//===================================
						//	GUI
						//===================================
						if (sum == 0) {					//If the weights of both Terminals A and B are perfectly matched
								String ^ sPublicKey = gcnew String((char*)nc->publickey);
								this->text_Key->Text = 	sPublicKey;
								this->text_KB->Text = System::Convert::ToString(dataExchanged);
								this->text_KeyLength->Text = System::Convert::ToString(key_length);		//ttext_KeyLength.ToString();
								this->text_ActualItr->Text = System::Convert::ToString(itrActual);
								this->text_MaxItr->Text = System::Convert::ToString(itrMax);
								this->status_Message->Text = "SUCCESS!";

								this->button_Sync->Text = "Turbo Sync";
						}
						else {
								this->status_Message->Text = "FAILED!";
								this->button_Sync->Text = "Turbo Sync";
						}
						//if(state_SlowMo)
						finito();
				}		//end elseif(timer_itrMax < nc->itrMax)

				state_beginTick = false;		//end semaphore to indicate that Timer is not busy anymore
			}


	private: System::Void button_SyncTurbo_Click(System::Object^  sender, System::EventArgs^  e) {
			//Get K, N, L values from the updown controls entered by user
			valK = (int)this->updn_K->Value;
			valN = (int)this->updn_N->Value;
			valL = (int)this->updn_L->Value;

			itrMax = (valL * valL * valL * valL) * valN * valK;		//Maximum number of iterations to carry on until program gives up
			sumMax = valK * valN * valL / 4;	//Required for difference graph
			timer_itrMax = 1;

			//Create new instance of NeuroCrypto class
			nc = new NeuroCrypto(valK, valN, valL);

			//Find sum
			sum = 0;
			for (ss = 0; ss < valK * valN; ss++)
					sum += abs (nc->A.W.Z[ss] - nc->B.W.Z[ss]);

			grid_A->ColumnCount = valN;
			grid_A->RowCount = valK;
			grid_B->ColumnCount = valN;
			grid_B->RowCount = valK;
					
			this->status_Message->Text = "Synchronizing TPM...";

			state_FreshStart = false;
			state_StartPause = true;			//Start Mode state
			state_beginTick = false;

			Graphics^ gr = this->picture_Graph->CreateGraphics();
			Pen^ pen = gcnew Pen(Color::Blue);

			//--------- MAIN ITERATION FOR SYNCHRONIZATION ---------
			for(timer_itrMax=1; timer_itrMax < nc->itrMax; timer_itrMax++) {	
					itrActualtemp = timer_itrMax;

					this->status_Itr->Text = String::Concat("Iteration: ", itrActualtemp.ToString());

					nc->objInput.CreateRandomVector (valK, valN);
					nc->A.ComputeTPMResult (nc->objInput.X);
					nc->B.ComputeTPMResult (nc->objInput.X);
		
					if (nc->A.TPMOutput == nc->B.TPMOutput) {
						lineOriginX = ( itrActualtemp - 1 ) * this->picture_Graph->Size.Width / itrMax;		//(.8 * itrMax);
						lineOriginY = this->picture_Graph->Size.Height - (int)( ( sum / 5 ) * ( this->picture_Graph->Size.Height ) / sumMax );
						if(itrActualtemp > 2)					//when new synchronization starts, prevent drawing unwanted line from the previous Final x,y to the Initial x,y. If this is continuation of old synchronization, we need to draw
							gr->DrawLine(pen, lineFinalX, lineFinalY, lineOriginX, lineOriginY);

						lineFinalX = itrActualtemp * this->picture_Graph->Size.Width / itrMax;
						lineFinalY = this->picture_Graph->Size.Height - (int)( ( sum / 5 ) * ( this->picture_Graph->Size.Height ) / sumMax );	//removed -20 gutter from original

						gr->DrawLine(pen, lineOriginX, lineOriginY, lineFinalX, lineFinalY);
						
						System::Drawing::Drawing2D::GraphicsState^ graph = gr->Save();
						gr->Restore(graph);
						
						nc->A.UpdateWeight (nc->objInput.X);
						nc->B.UpdateWeight (nc->objInput.X);

						//Find the sum
						sum = 0;
						for (ss = 0; ss < valK * valN; ss++)
							sum += abs (nc->A.W.Z[ss] - nc->B.W.Z[ss]);
					}
					if (sum == 0)
						break;
			}	//end of main iteration

			if (sum == 0)		//Decide whether the validity of the publickey i.e. are neural weight of Terminal A and B exact?
			{
		 			// Computation of result variables
					itrActual = itrActualtemp;
					key_size = 37 / (valL * 2 + 1);
					key_length = valK * valN / key_size;
					dataExchanged = itrActual * (valK * valN + 4) / 1024;

					// Generation of the final public key
					for (i = 1; i < key_length + 1; i++) {
						K = 1;
						for (j = (i - 1) * key_size; j < i * key_size; j++)
							K = K + nc->A.W.Z[j] + valL;
		
						nc->publickey[i - 1] = Dictionary[K];
					}
					nc->publickey[key_length] = '\0';		//Null character at the end

					//===================================
					//	GUI
					//===================================
					for (ii = 0; ii < valK ; ii++) {
						for (j = 0; j < valN; j++) {
								gridElementA = nc->A.W.Z[ii * valN + j];
								gridElementB = nc->B.W.Z[ii * valN + j];
								this->grid_A->Rows[ii]->Cells[j]->Value = gridElementA.ToString();
								this->grid_B->Rows[ii]->Cells[j]->Value = gridElementB.ToString();
							}
					}
					this->grid_A->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
					this->grid_B->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
						
					String ^ sPublicKey = gcnew String((char*)nc->publickey);
					this->text_Key->Text = 	sPublicKey;
					this->text_KB->Text = System::Convert::ToString(dataExchanged);
					this->text_KeyLength->Text = System::Convert::ToString(key_length);		//ttext_KeyLength.ToString();
					this->text_ActualItr->Text = System::Convert::ToString(itrActual);
					this->text_MaxItr->Text = System::Convert::ToString(itrMax);
					this->status_Message->Text = "SUCCESS!";

					this->button_Sync->Text = "Slow Sync";
			}
			else {	//If the weights of Terminals A and B are not exact
					this->status_Message->Text = "FAIL!";
					this->button_Sync->Text = "Slow Sync";
			}

			finito();	//Clean up memory and wind up for fresh synchronization
		 }


	private: System::Void button_About_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show("\n\t             NEURO-CRYPTO v3.0\n=========================================\n A proof-of-concept demonstration of Neural Cryptography \n    - a novel approach to public-key cryptography using \n Tree Parity Machine - a variant of Artificial Neural Networks\n\t-----------------------------------\n\t   Created by: Sagun Man Singh\n\tDate: Fri, Feb 29. 2011 @ 10:30 AM\n\t   Email: sagunms@gmail.com\n             Website: http://sagunms.wordpress.com\n=========================================\n\tStarted = Fri, Oct 8, 2010 @ 3:00 PM\n\tLatest = Fri, Feb 29, 2010 @ 10:30 AM\n\t             (Duration = 30 days)",
							"About", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		 }


	private: System::Void frmMain_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 if (MessageBox::Show("Do you really want to exit?",
				 "NEURO-CRYPTO v3.0", MessageBoxButtons::YesNo,
				 MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
							finito();
							Application::Exit();
			 }
			 else
				 e->Cancel = true;	// cancel the closure of the form.
		 }
	
	/*
	private: System::Void button_test_Click(System::Object^  sender, System::EventArgs^  e) {

			   String ^str = this->text_testin->Text;		//"Hello";

			   // Pin memory so GC can't move it while native function is called
			   pin_ptr<const wchar_t> wch = PtrToStringChars(str);
			   //printf_s("%S\n", wch);

			   // Conversion to char* :
			   // Can just convert wchar_t* to char* using one of the 
			   // conversion functions such as: 
			   // WideCharToMultiByte()
			   // wcstombs_s()
			   // ... etc
			   size_t convertedChars = 0;
			   size_t  sizeInBytes = ((str->Length + 1) * 2);
			   errno_t err = 0;
			   //char    *ch = (char *)malloc(sizeInBytes);
			   char *ch = new char [sizeInBytes];
			   err = wcstombs_s(&convertedChars, 
								ch, sizeInBytes,
								wch, sizeInBytes);
			   if (err != 0)
				  printf_s("wcstombs_s  failed!\n");

				//printf_s("%s\n", ch);



				String ^ stringDisplay = gcnew String((char*)ch);	//myString);
				this->text_testout->Text = 	stringDisplay;
				this->label_K->Text = System::Convert::ToString(ch[0]);
				this->label_N->Text = System::Convert::ToString(ch[1]);
				this->label_L->Text = System::Convert::ToString(ch[1]);
		delete [] ch;
		ch = NULL;

			 }
			 */



private: System::Void button_Encrypt_Click(System::Object^  sender, System::EventArgs^  e) {
			cipherData = text_Plain->Text;
			plainbytes = Encoding::ASCII->GetBytes(cipherData);
			// generating symmetric key
				//desObj->GenerateKey();
				plainKey = Encoding::ASCII->GetBytes(this->text_Key->Text);
				desObj->Key = plainKey;
			// generating vector
			//desObj->GenerateIV();
			// choose other appropriate modes (CBC, CFB, CTS, ECB, OFB)
			desObj->Mode = CipherMode::CBC;
			// setting the padding mode
			desObj->Padding = PaddingMode::PKCS7;
			// --------------- ECRYPTION ---------------
			// memory stream used as a target to write enrypted data
			MemoryStream^ ms = gcnew MemoryStream();
			// transforms and encrypts plaintext data to memorystream object
			CryptoStream^ cs = gcnew CryptoStream(ms, desObj->CreateEncryptor(), CryptoStreamMode::Write);
			cs->Write(plainbytes, 0, plainbytes->Length);
			cs->Close();
			// getting encrypted data from memorystream to bytes
			cipherbytes = ms->ToArray();
			ms->Close();
			text_Encrypt->Text = Encoding::ASCII->GetString(cipherbytes);
		 }
private: System::Void button_Decrypt_Click(System::Object^  sender, System::EventArgs^  e) {
			// --------------- DECRYPTION ---------------
			MemoryStream^ ms1 = gcnew MemoryStream(cipherbytes);
			CryptoStream^ cs1 = gcnew CryptoStream(ms1, desObj->CreateDecryptor(), CryptoStreamMode::Read);
			// allocate array of bytes equal on lenght with ciphertext array
			//plainbytes = new Byte[cipherbytes->Length];
			// decrypt the ciphertext from previous section
			
			cs1->Read(cipherbytes, 0, cipherbytes->Length);
			plainbytes2 = ms1->ToArray();
			cs1->Close();
			ms1->Close();
			text_Decrypt->Text = Encoding::ASCII->GetString(plainbytes2);
		 }
};	//end of frmMain class
	
}	//end of NeuralCryptography namespace
