#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <math.h>
#include <cmath>
#include "help.h"
#include <vector>




#define SCROLLUP 120
#define SCROLLDOWN -120




namespace cobblestoneminerUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Summary for UserInterface
	/// </summary>
	public ref class UserInterface : public System::Windows::Forms::Form
	{

		// custom global var //////////////////////////////////////////////////////////
		int TimerOG;
		float pickSpeed;
		float pickDur;
		int pickID;

		float efficiency;
		int efficiencyINT;

		int slotStart = 1;
		int slotEnd = 9;

		int TimerTimes2 = TimerOG * 2;
		String^ MinSec = "";

		int exSeconds;

		String^ optSecondsString;
		String^ optAndString;
		String^ exSecondsString;
		String^ optZusammenString;

		double TimerEquation;
		float TimerMultiplier;

		int old_clock;
		int Slot;

		double damage;

		double StartingTimerValue;
		double StartingTimerValueOG;
		int iteration = 0;


		int clock1 = 0;
		int PerCentFinished;
		double blocksMinedCeil;
		double blocksMinedFloor;

		bool Mining_working;
		String^ NowOnSlotString;
		String^ PerCentFinishedString;
		String^ blocksMinedString;
		String^ HowToExitString;
		String^ ZusammenTextString;
		String^ eating;

		String^ Error1String = "\n";
		String^ Error2String = "\n";


		int _ticks;
		int _ticks2;
		int _tick3;

		bool RBchecked = false;
	private: System::Windows::Forms::Label^ Slot9label;
	private: System::Windows::Forms::Label^ Slot8label;
	private: System::Windows::Forms::Label^ Slot7label;
	private: System::Windows::Forms::Label^ Slot6label;
	private: System::Windows::Forms::Label^ Slot5label;
	private: System::Windows::Forms::Label^ Slot4label;
	private: System::Windows::Forms::Label^ Slot3label;
	private: System::Windows::Forms::Label^ Slot2label;
	private: System::Windows::Forms::Label^ Slot1label;
		   bool RBchecked2 = false;

		// custom global var /////////////////////////////////////////////////////////

		// custom global functions ///////////////////////////////////////////////////


		void ToggleAll() {
			woodpaxeRB->Enabled = !woodpaxeRB->Enabled;
			stonepaxeRB->Enabled = !stonepaxeRB->Enabled;
			goldpaxeRB->Enabled = !goldpaxeRB->Enabled;
			ironpaxeRB->Enabled = !ironpaxeRB->Enabled;
			diamondpaxeRB->Enabled = !diamondpaxeRB->Enabled;
			netheritepaxeRB->Enabled = !netheritepaxeRB->Enabled;

			trackBarSlotStart->Enabled = !trackBarSlotStart->Enabled;
			trackBarSlotEnde->Enabled = !trackBarSlotEnde->Enabled;

			eff0RB->Enabled = !eff0RB->Enabled;
			eff1RB->Enabled = !eff1RB->Enabled;
			eff2RB->Enabled = !eff2RB->Enabled;
			eff3RB->Enabled = !eff3RB->Enabled;
			eff4RB->Enabled = !eff4RB->Enabled;
			eff5RB->Enabled = !eff5RB->Enabled;

		}

		void resetProperties() {
			iteration = 0;
			numericUpDown1->Enabled = true;
			startButton->Enabled = true;

			woodpaxeRB->Checked = false;
			stonepaxeRB->Checked = false;
			goldpaxeRB->Checked = false;
			ironpaxeRB->Checked = false;
			diamondpaxeRB->Checked = false;
			netheritepaxeRB->Checked = false;

			eff0RB->Checked = false;
			eff1RB->Checked = false;
			eff2RB->Checked = false;
			eff3RB->Checked = false;
			eff4RB->Checked = false;
			eff5RB->Checked = false;
			RBchecked = false;
			RBchecked2 = false;

			trackBarSlotStart->Value = 1;
			trackBarSlotEnde->Value = 9;

			StopMiningButton->Enabled = false;

			MiningTimer->Interval = 101;
			CounterTimer->Interval = 101;
			eatingTimer->Interval = 101;

			TimerOG = 0;
			pickSpeed = 0;
			pickDur = 0;
			pickID = 0;
			efficiency = 0;
			efficiencyINT = 0;
			slotStart = 0;
			slotEnd = 0;
			exSeconds = 0;
			TimerEquation = 0;
			TimerMultiplier = 0;
			old_clock = 0;
			slotStart = 1;
			Slot = slotStart;
			slotEnd = 9;
			damage = 0;
			StartingTimerValue = 0;
			StartingTimerValueOG = 0;
			iteration = 0;
			clock1 = 0;
			_ticks = 0;
			_ticks2 = 0;
			_tick3 = 0;

		}

		void fMinSec() { //function to print out seconds or Minutes
			if (TimerTimes2 >= 60000) {
				MinSec = " Minutes";
			}
			else {
				MinSec = " Seconds";
			}
		}

		void optSecondsf() { // makes string based on TimerCalc and fMinSec

			if (exSeconds > 0 && TimerTimes2 > 60000) {
				optSecondsString = " seconds.";
			}
			else {
				optSecondsString = "";
			}
		}

		void optAndF() { // makes string based on TimerCalc and fMinSec
			if (exSeconds > 0 && TimerTimes2 > 60000) {
				optAndString = " and ";
			}
			else {
				optAndString = ".";
			}
		}

		void optExSecondsf() { // makes string based on TimerCalc and fMinSec
			exSeconds = (TimerTimes2 % 60000) / 1000;
			if (exSeconds > 0 && TimerTimes2 > 60000) {
				exSeconds = (TimerTimes2 % 60000) / 1000;
				exSecondsString = exSeconds.ToString();
			}
			else {
				exSecondsString = "";
			}
		}

		void optZusammenf() { // makes string based on TimerCalc and fMinSec

			optExSecondsf();
			optAndF();
			optSecondsf();
			optZusammenString = optAndString + exSecondsString + optSecondsString + "\n";
		}

		void TimerCalc() { //function to decide wheter secconds or minutes



			if (efficiency == 0) {
				damage = (pickSpeed / 60);
				TimerOG = pickDur * ((ceil(1 / damage) / 20) * 1000) + 1000;
			}
			else if (efficiency > 1 && efficiency < 6) {
				damage = (pickSpeed + ((efficiency * efficiency) + 1)) / 60;
				TimerOG = ((pickDur * ((ceil(1 / damage) / 20) * 1000)));
			}


			if (efficiency == 0) {
				TimerMultiplier = 1.85;
			}
			else if (efficiency >= 1) {
				TimerMultiplier = 1.5;
			}

			switch (pickID)
			{
			case 1: //wood
				switch (efficiencyINT)
				{
				case 0:
					TimerMultiplier = TimerMultiplier * 1.2131;//1.1008
					break;
				case 1:
					TimerMultiplier = TimerMultiplier * 0.72;
					break;
				case 2:
					TimerMultiplier = TimerMultiplier * 1.23;
					break;

				case 3:
					TimerMultiplier = TimerMultiplier * 1.74;
					break;

				case 4:
					TimerMultiplier = TimerMultiplier * 1.825;
					break;

				case 5:
					TimerMultiplier = TimerMultiplier * 2.40;
					break;

				}
				break;

			case 2: //stone
				switch (efficiencyINT)
				{
				case 0: TimerMultiplier = 1.895;
					break;

				case 1:
					TimerMultiplier = 0.5062;
					break;

				case 2:
					TimerMultiplier = 1.2352;
					break;

				case 3:
					TimerMultiplier = 1.1775;
					break;

				case 4:
					TimerMultiplier = 0.6847;
					break;

				case 5:
					TimerMultiplier = 1.2115;
					break;
				}

			case 3: //iron
				switch (efficiencyINT)
				{
				case 0:
					TimerMultiplier = TimerMultiplier * 1.055;
					break;

				case 1:
					TimerMultiplier = TimerMultiplier * 0.4862;
					break;

				case 2:
					TimerMultiplier = TimerMultiplier * 1.192;
					break;

				case 3:
					TimerMultiplier = TimerMultiplier * 1.3611;
					break;

				case 4:
					TimerMultiplier = TimerMultiplier * 1.021;
					break;

				case 5:
					TimerMultiplier = TimerMultiplier * 1.4820;
					break;
				}

			case 4: //diamond
				switch (efficiencyINT)
				{
				case 0:
					TimerMultiplier = TimerMultiplier * 0.8549;
					break;

				case 1:
					TimerMultiplier = TimerMultiplier * 0.63449;
					break;

				case 2:
					TimerMultiplier = TimerMultiplier * 1.023;
					break;

				case 3:
					TimerMultiplier = 1.496;
					break;

				case 4:
					TimerMultiplier = TimerMultiplier * 1.005;
					break;

				case 5:
					TimerMultiplier = TimerMultiplier * 0.97019;
					break;
				}

			case 5: //netherite
				switch (efficiencyINT)
				{
				case 0:
					TimerMultiplier = 1.995;
					break;

				case 1:
					TimerMultiplier = 1.518;
					break;

				case 2:
					TimerMultiplier = 1.511;
					break;

				case 3:
					TimerMultiplier = 1.25;
					break;

				case 4:
					TimerMultiplier = 1.65875;//
					break;
				case 5:
					TimerMultiplier = 1.6123;//
					break;
				}

			case 6: //gold
				switch (efficiencyINT)
				{
				case 0:
					TimerMultiplier = TimerMultiplier * 1.188;
					break;

				case 1:
					TimerMultiplier = TimerMultiplier * 1.557;
					break;

				case 2:
					TimerMultiplier = TimerMultiplier * 1.75761;
					break;

				case 3:
					TimerMultiplier = TimerMultiplier * 2.21625;
					break;

				case 4:
					TimerMultiplier = TimerMultiplier * 2.21625;
					break;

				case 5:
					TimerMultiplier = TimerMultiplier * 2.8125;
					break;
				}

			default:
				break;
			}


			TimerTimes2 = TimerOG * TimerMultiplier;


			if (TimerTimes2 >= 60000) {
				(TimerEquation = TimerTimes2 / 60000);
			}
			else {
				TimerEquation = (TimerTimes2 / 1000.00);
			}
		}

		void Counter() { // counts how many blocks have been broken, how much the process is finished and how often it will repeat;
						// Clicker

			old_clock = ((TimerOG / 10));


			//for (clock1 = 0; clock1 < TimerOG; clock1 = clock1 + old_clock) 
			{
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				NowOnSlotString = "Now on Slot: " + Slot + " for " + TimerEquation + MinSec + optZusammenString + "\n";

				PerCentFinished = ceil(((clock1 * 100) / (TimerOG)));
				PerCentFinishedString = "\n" + PerCentFinished.ToString() + "% of durability used.\n\n";

				blocksMinedFloor = floor((clock1 / ((ceil(1 / damage) / 20) * 1000)));
				blocksMinedCeil = floor((clock1 / ((ceil(1 / damage) / 20) * 1000)) * 2);
				blocksMinedString = blocksMinedFloor.ToString() + "-" + blocksMinedCeil.ToString() + " blocks mined.\n";


				HowToExitString = "\n\nNote: while mining, buttons need to be double clicked.\n";

				ZusammenTextString = NowOnSlotString + PerCentFinishedString + blocksMinedString + HowToExitString;
				TimeLabel->Text = ZusammenTextString;


				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				//Sleep((old_clock * TimerMultiplier));

				clock1 = clock1 + old_clock;



			}


		}

		void eatingStart() {


			PerCentFinishedString = "\n100% finished.\n\n";
			NowOnSlotString = "Now on Slot: " + Slot + " for " + TimerEquation + MinSec + optZusammenString + "\n";
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			eating = "eating...\n";
			TimeLabel->Text = NowOnSlotString + PerCentFinishedString + eating + HowToExitString;

		}

		void eatingEnd() {
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			eating = "eating done\n";
			TimeLabel->Text = NowOnSlotString + PerCentFinishedString + eating + HowToExitString;

			mouse_event(MOUSEEVENTF_WHEEL, 0, 0, SCROLLDOWN, 0);
		}


		// custom global functions ///////////////////////////////////////////////////

	public:
		UserInterface(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::Timer^ eatingTimer;
	private: System::Windows::Forms::Timer^ CounterTimer;
	private: System::Windows::Forms::Timer^ MiningTimer;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ helpButton;
	private: System::Windows::Forms::Label^ StartTimerTextLabel;
	private: System::Windows::Forms::Button^ StopMiningButton;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Timer^ tMinus20;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ netheritepaxeRB;
	protected:

	private: System::Windows::Forms::RadioButton^ diamondpaxeRB;

	private: System::Windows::Forms::RadioButton^ goldpaxeRB;

	private: System::Windows::Forms::RadioButton^ ironpaxeRB;

	private: System::Windows::Forms::RadioButton^ stonepaxeRB;

	private: System::Windows::Forms::RadioButton^ woodpaxeRB;
	private: System::Windows::Forms::PictureBox^ stonepaxeFoto;
	private: System::Windows::Forms::PictureBox^ ironpaxeFoto;


	private: System::Windows::Forms::PictureBox^ woodpaxeFoto;
	private: System::Windows::Forms::PictureBox^ goldpaxeFoto;
	private: System::Windows::Forms::PictureBox^ netheriteaxeFoto;


	private: System::Windows::Forms::PictureBox^ diamondpaxeFoto;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ eff2RB;
	private: System::Windows::Forms::RadioButton^ eff5RB;
	private: System::Windows::Forms::RadioButton^ eff4RB;
	private: System::Windows::Forms::RadioButton^ eff3RB;
	private: System::Windows::Forms::RadioButton^ eff1RB;
	private: System::Windows::Forms::RadioButton^ eff0RB;
	private: System::Windows::Forms::TrackBar^ trackBarSlotStart;
	private: System::Windows::Forms::TrackBar^ trackBarSlotEnde;
	private: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::Label^ TimeLabel;
private: System::ComponentModel::IContainer^ components;


	
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserInterface::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->netheritepaxeRB = (gcnew System::Windows::Forms::RadioButton());
			this->stonepaxeFoto = (gcnew System::Windows::Forms::PictureBox());
			this->goldpaxeFoto = (gcnew System::Windows::Forms::PictureBox());
			this->goldpaxeRB = (gcnew System::Windows::Forms::RadioButton());
			this->netheriteaxeFoto = (gcnew System::Windows::Forms::PictureBox());
			this->diamondpaxeFoto = (gcnew System::Windows::Forms::PictureBox());
			this->ironpaxeFoto = (gcnew System::Windows::Forms::PictureBox());
			this->woodpaxeFoto = (gcnew System::Windows::Forms::PictureBox());
			this->diamondpaxeRB = (gcnew System::Windows::Forms::RadioButton());
			this->ironpaxeRB = (gcnew System::Windows::Forms::RadioButton());
			this->stonepaxeRB = (gcnew System::Windows::Forms::RadioButton());
			this->woodpaxeRB = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->eff2RB = (gcnew System::Windows::Forms::RadioButton());
			this->eff5RB = (gcnew System::Windows::Forms::RadioButton());
			this->eff4RB = (gcnew System::Windows::Forms::RadioButton());
			this->eff3RB = (gcnew System::Windows::Forms::RadioButton());
			this->eff1RB = (gcnew System::Windows::Forms::RadioButton());
			this->eff0RB = (gcnew System::Windows::Forms::RadioButton());
			this->trackBarSlotStart = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarSlotEnde = (gcnew System::Windows::Forms::TrackBar());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->TimeLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->Slot9label = (gcnew System::Windows::Forms::Label());
			this->Slot8label = (gcnew System::Windows::Forms::Label());
			this->Slot7label = (gcnew System::Windows::Forms::Label());
			this->Slot6label = (gcnew System::Windows::Forms::Label());
			this->Slot5label = (gcnew System::Windows::Forms::Label());
			this->Slot4label = (gcnew System::Windows::Forms::Label());
			this->Slot3label = (gcnew System::Windows::Forms::Label());
			this->Slot2label = (gcnew System::Windows::Forms::Label());
			this->Slot1label = (gcnew System::Windows::Forms::Label());
			this->tMinus20 = (gcnew System::Windows::Forms::Timer(this->components));
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->helpButton = (gcnew System::Windows::Forms::Button());
			this->StartTimerTextLabel = (gcnew System::Windows::Forms::Label());
			this->StopMiningButton = (gcnew System::Windows::Forms::Button());
			this->MiningTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->CounterTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->eatingTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stonepaxeFoto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->goldpaxeFoto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->netheriteaxeFoto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->diamondpaxeFoto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ironpaxeFoto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->woodpaxeFoto))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSlotStart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSlotEnde))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->netheritepaxeRB);
			this->groupBox1->Controls->Add(this->stonepaxeFoto);
			this->groupBox1->Controls->Add(this->goldpaxeFoto);
			this->groupBox1->Controls->Add(this->goldpaxeRB);
			this->groupBox1->Controls->Add(this->netheriteaxeFoto);
			this->groupBox1->Controls->Add(this->diamondpaxeFoto);
			this->groupBox1->Controls->Add(this->ironpaxeFoto);
			this->groupBox1->Controls->Add(this->woodpaxeFoto);
			this->groupBox1->Controls->Add(this->diamondpaxeRB);
			this->groupBox1->Controls->Add(this->ironpaxeRB);
			this->groupBox1->Controls->Add(this->stonepaxeRB);
			this->groupBox1->Controls->Add(this->woodpaxeRB);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(505, 89);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Pickaxe";
			// 
			// netheritepaxeRB
			// 
			this->netheritepaxeRB->AutoSize = true;
			this->netheritepaxeRB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->netheritepaxeRB->Location = System::Drawing::Point(473, 61);
			this->netheritepaxeRB->Name = L"netheritepaxeRB";
			this->netheritepaxeRB->Size = System::Drawing::Size(14, 13);
			this->netheritepaxeRB->TabIndex = 5;
			this->netheritepaxeRB->UseVisualStyleBackColor = true;
			this->netheritepaxeRB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::netheritepaxeRB_CheckedChanged);
			// 
			// stonepaxeFoto
			// 
			this->stonepaxeFoto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"stonepaxeFoto.Image")));
			this->stonepaxeFoto->Location = System::Drawing::Point(96, 19);
			this->stonepaxeFoto->Name = L"stonepaxeFoto";
			this->stonepaxeFoto->Size = System::Drawing::Size(34, 36);
			this->stonepaxeFoto->TabIndex = 6;
			this->stonepaxeFoto->TabStop = false;
			// 
			// goldpaxeFoto
			// 
			this->goldpaxeFoto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goldpaxeFoto.Image")));
			this->goldpaxeFoto->Location = System::Drawing::Point(184, 19);
			this->goldpaxeFoto->Name = L"goldpaxeFoto";
			this->goldpaxeFoto->Size = System::Drawing::Size(34, 36);
			this->goldpaxeFoto->TabIndex = 6;
			this->goldpaxeFoto->TabStop = false;
			// 
			// goldpaxeRB
			// 
			this->goldpaxeRB->AutoSize = true;
			this->goldpaxeRB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->goldpaxeRB->Location = System::Drawing::Point(194, 61);
			this->goldpaxeRB->Name = L"goldpaxeRB";
			this->goldpaxeRB->Size = System::Drawing::Size(14, 13);
			this->goldpaxeRB->TabIndex = 2;
			this->goldpaxeRB->UseVisualStyleBackColor = true;
			this->goldpaxeRB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::goldpaxeRB_CheckedChanged);
			// 
			// netheriteaxeFoto
			// 
			this->netheriteaxeFoto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"netheriteaxeFoto.Image")));
			this->netheriteaxeFoto->Location = System::Drawing::Point(462, 19);
			this->netheriteaxeFoto->Name = L"netheriteaxeFoto";
			this->netheriteaxeFoto->Size = System::Drawing::Size(34, 36);
			this->netheriteaxeFoto->TabIndex = 6;
			this->netheriteaxeFoto->TabStop = false;
			// 
			// diamondpaxeFoto
			// 
			this->diamondpaxeFoto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"diamondpaxeFoto.Image")));
			this->diamondpaxeFoto->Location = System::Drawing::Point(368, 19);
			this->diamondpaxeFoto->Name = L"diamondpaxeFoto";
			this->diamondpaxeFoto->Size = System::Drawing::Size(34, 36);
			this->diamondpaxeFoto->TabIndex = 6;
			this->diamondpaxeFoto->TabStop = false;
			// 
			// ironpaxeFoto
			// 
			this->ironpaxeFoto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ironpaxeFoto.Image")));
			this->ironpaxeFoto->Location = System::Drawing::Point(274, 19);
			this->ironpaxeFoto->Name = L"ironpaxeFoto";
			this->ironpaxeFoto->Size = System::Drawing::Size(34, 36);
			this->ironpaxeFoto->TabIndex = 6;
			this->ironpaxeFoto->TabStop = false;
			// 
			// woodpaxeFoto
			// 
			this->woodpaxeFoto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"woodpaxeFoto.Image")));
			this->woodpaxeFoto->ImageLocation = L"";
			this->woodpaxeFoto->Location = System::Drawing::Point(11, 19);
			this->woodpaxeFoto->Name = L"woodpaxeFoto";
			this->woodpaxeFoto->Size = System::Drawing::Size(34, 36);
			this->woodpaxeFoto->TabIndex = 1;
			this->woodpaxeFoto->TabStop = false;
			// 
			// diamondpaxeRB
			// 
			this->diamondpaxeRB->AutoSize = true;
			this->diamondpaxeRB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->diamondpaxeRB->Location = System::Drawing::Point(380, 61);
			this->diamondpaxeRB->Name = L"diamondpaxeRB";
			this->diamondpaxeRB->Size = System::Drawing::Size(14, 13);
			this->diamondpaxeRB->TabIndex = 4;
			this->diamondpaxeRB->UseVisualStyleBackColor = true;
			this->diamondpaxeRB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::diamondpaxeRB_CheckedChanged);
			// 
			// ironpaxeRB
			// 
			this->ironpaxeRB->AutoSize = true;
			this->ironpaxeRB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ironpaxeRB->Location = System::Drawing::Point(286, 61);
			this->ironpaxeRB->Name = L"ironpaxeRB";
			this->ironpaxeRB->Size = System::Drawing::Size(14, 13);
			this->ironpaxeRB->TabIndex = 3;
			this->ironpaxeRB->UseVisualStyleBackColor = true;
			this->ironpaxeRB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::ironpaxeRB_CheckedChanged);
			// 
			// stonepaxeRB
			// 
			this->stonepaxeRB->AutoSize = true;
			this->stonepaxeRB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->stonepaxeRB->Location = System::Drawing::Point(107, 61);
			this->stonepaxeRB->Name = L"stonepaxeRB";
			this->stonepaxeRB->Size = System::Drawing::Size(14, 13);
			this->stonepaxeRB->TabIndex = 1;
			this->stonepaxeRB->UseVisualStyleBackColor = true;
			this->stonepaxeRB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::stonepaxeRB_CheckedChanged);
			// 
			// woodpaxeRB
			// 
			this->woodpaxeRB->AutoSize = true;
			this->woodpaxeRB->BackColor = System::Drawing::Color::Transparent;
			this->woodpaxeRB->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->woodpaxeRB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->woodpaxeRB->Location = System::Drawing::Point(21, 61);
			this->woodpaxeRB->Name = L"woodpaxeRB";
			this->woodpaxeRB->Size = System::Drawing::Size(14, 13);
			this->woodpaxeRB->TabIndex = 0;
			this->woodpaxeRB->UseVisualStyleBackColor = false;
			this->woodpaxeRB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::woodpaxeRB_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->eff2RB);
			this->groupBox2->Controls->Add(this->eff5RB);
			this->groupBox2->Controls->Add(this->eff4RB);
			this->groupBox2->Controls->Add(this->eff3RB);
			this->groupBox2->Controls->Add(this->eff1RB);
			this->groupBox2->Controls->Add(this->eff0RB);
			this->groupBox2->Location = System::Drawing::Point(12, 107);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(505, 55);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Enchantment";
			// 
			// eff2RB
			// 
			this->eff2RB->AutoSize = true;
			this->eff2RB->BackColor = System::Drawing::Color::Transparent;
			this->eff2RB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eff2RB->Location = System::Drawing::Point(159, 19);
			this->eff2RB->Name = L"eff2RB";
			this->eff2RB->Size = System::Drawing::Size(80, 17);
			this->eff2RB->TabIndex = 8;
			this->eff2RB->Text = L"Efficiency 2\r\n";
			this->eff2RB->UseVisualStyleBackColor = false;
			this->eff2RB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::eff2RB_CheckedChanged);
			// 
			// eff5RB
			// 
			this->eff5RB->AutoSize = true;
			this->eff5RB->BackColor = System::Drawing::Color::Transparent;
			this->eff5RB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eff5RB->Location = System::Drawing::Point(416, 19);
			this->eff5RB->Name = L"eff5RB";
			this->eff5RB->Size = System::Drawing::Size(80, 17);
			this->eff5RB->TabIndex = 11;
			this->eff5RB->Text = L"Efficiency 5";
			this->eff5RB->UseVisualStyleBackColor = false;
			this->eff5RB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::eff5RB_CheckedChanged);
			// 
			// eff4RB
			// 
			this->eff4RB->AutoSize = true;
			this->eff4RB->BackColor = System::Drawing::Color::Transparent;
			this->eff4RB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eff4RB->Location = System::Drawing::Point(330, 19);
			this->eff4RB->Name = L"eff4RB";
			this->eff4RB->Size = System::Drawing::Size(80, 17);
			this->eff4RB->TabIndex = 10;
			this->eff4RB->Text = L"Efficiency 4";
			this->eff4RB->UseVisualStyleBackColor = false;
			this->eff4RB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::eff4RB_CheckedChanged);
			// 
			// eff3RB
			// 
			this->eff3RB->AutoSize = true;
			this->eff3RB->BackColor = System::Drawing::Color::Transparent;
			this->eff3RB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eff3RB->Location = System::Drawing::Point(245, 19);
			this->eff3RB->Name = L"eff3RB";
			this->eff3RB->Size = System::Drawing::Size(80, 17);
			this->eff3RB->TabIndex = 9;
			this->eff3RB->Text = L"Efficiency 3";
			this->eff3RB->UseVisualStyleBackColor = false;
			this->eff3RB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::eff3RB_CheckedChanged);
			// 
			// eff1RB
			// 
			this->eff1RB->AutoSize = true;
			this->eff1RB->BackColor = System::Drawing::Color::Transparent;
			this->eff1RB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eff1RB->Location = System::Drawing::Point(73, 19);
			this->eff1RB->Name = L"eff1RB";
			this->eff1RB->Size = System::Drawing::Size(80, 17);
			this->eff1RB->TabIndex = 7;
			this->eff1RB->Text = L"Efficiency 1";
			this->eff1RB->UseVisualStyleBackColor = false;
			this->eff1RB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::eff1RB_CheckedChanged);
			// 
			// eff0RB
			// 
			this->eff0RB->AutoSize = true;
			this->eff0RB->BackColor = System::Drawing::Color::Transparent;
			this->eff0RB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eff0RB->Location = System::Drawing::Point(11, 19);
			this->eff0RB->Name = L"eff0RB";
			this->eff0RB->Size = System::Drawing::Size(51, 17);
			this->eff0RB->TabIndex = 6;
			this->eff0RB->Text = L"None";
			this->eff0RB->UseVisualStyleBackColor = false;
			this->eff0RB->CheckedChanged += gcnew System::EventHandler(this, &UserInterface::eff0RB_CheckedChanged);
			// 
			// trackBarSlotStart
			// 
			this->trackBarSlotStart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBarSlotStart->LargeChange = 1;
			this->trackBarSlotStart->Location = System::Drawing::Point(11, 19);
			this->trackBarSlotStart->Maximum = 9;
			this->trackBarSlotStart->Minimum = 1;
			this->trackBarSlotStart->Name = L"trackBarSlotStart";
			this->trackBarSlotStart->Size = System::Drawing::Size(485, 45);
			this->trackBarSlotStart->TabIndex = 12;
			this->trackBarSlotStart->Value = 1;
			this->trackBarSlotStart->Scroll += gcnew System::EventHandler(this, &UserInterface::trackBarSlotStart_ValueChanged);
			// 
			// trackBarSlotEnde
			// 
			this->trackBarSlotEnde->BackColor = System::Drawing::SystemColors::Control;
			this->trackBarSlotEnde->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBarSlotEnde->LargeChange = 1;
			this->trackBarSlotEnde->Location = System::Drawing::Point(11, 70);
			this->trackBarSlotEnde->Maximum = 9;
			this->trackBarSlotEnde->Minimum = 1;
			this->trackBarSlotEnde->Name = L"trackBarSlotEnde";
			this->trackBarSlotEnde->Size = System::Drawing::Size(485, 45);
			this->trackBarSlotEnde->TabIndex = 13;
			this->trackBarSlotEnde->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBarSlotEnde->Value = 9;
			this->trackBarSlotEnde->Scroll += gcnew System::EventHandler(this, &UserInterface::trackBarSlotEnde_ValueChanged);
			// 
			// startButton
			// 
			this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"startButton.Image")));
			this->startButton->Location = System::Drawing::Point(368, 322);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(100, 96);
			this->startButton->TabIndex = 19;
			this->startButton->Text = L"START MINING";
			this->startButton->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->startButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &UserInterface::startButton_Click);
			// 
			// TimeLabel
			// 
			this->TimeLabel->AutoSize = true;
			this->TimeLabel->Location = System::Drawing::Point(12, 295);
			this->TimeLabel->Name = L"TimeLabel";
			this->TimeLabel->Size = System::Drawing::Size(0, 13);
			this->TimeLabel->TabIndex = 14;
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox3->Controls->Add(this->Slot9label);
			this->groupBox3->Controls->Add(this->Slot8label);
			this->groupBox3->Controls->Add(this->Slot7label);
			this->groupBox3->Controls->Add(this->Slot6label);
			this->groupBox3->Controls->Add(this->Slot5label);
			this->groupBox3->Controls->Add(this->Slot4label);
			this->groupBox3->Controls->Add(this->Slot3label);
			this->groupBox3->Controls->Add(this->Slot2label);
			this->groupBox3->Controls->Add(this->Slot1label);
			this->groupBox3->Controls->Add(this->trackBarSlotStart);
			this->groupBox3->Controls->Add(this->trackBarSlotEnde);
			this->groupBox3->Location = System::Drawing::Point(12, 164);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(505, 125);
			this->groupBox3->TabIndex = 5;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Slots";
			// 
			// Slot9label
			// 
			this->Slot9label->AutoSize = true;
			this->Slot9label->Location = System::Drawing::Point(476, 53);
			this->Slot9label->Name = L"Slot9label";
			this->Slot9label->Size = System::Drawing::Size(13, 13);
			this->Slot9label->TabIndex = 14;
			this->Slot9label->Text = L"9";
			// 
			// Slot8label
			// 
			this->Slot8label->AutoSize = true;
			this->Slot8label->Location = System::Drawing::Point(419, 53);
			this->Slot8label->Name = L"Slot8label";
			this->Slot8label->Size = System::Drawing::Size(13, 13);
			this->Slot8label->TabIndex = 14;
			this->Slot8label->Text = L"8";
			// 
			// Slot7label
			// 
			this->Slot7label->AutoSize = true;
			this->Slot7label->Location = System::Drawing::Point(362, 53);
			this->Slot7label->Name = L"Slot7label";
			this->Slot7label->Size = System::Drawing::Size(13, 13);
			this->Slot7label->TabIndex = 14;
			this->Slot7label->Text = L"7";
			// 
			// Slot6label
			// 
			this->Slot6label->AutoSize = true;
			this->Slot6label->Location = System::Drawing::Point(304, 53);
			this->Slot6label->Name = L"Slot6label";
			this->Slot6label->Size = System::Drawing::Size(13, 13);
			this->Slot6label->TabIndex = 14;
			this->Slot6label->Text = L"6";
			// 
			// Slot5label
			// 
			this->Slot5label->AutoSize = true;
			this->Slot5label->Location = System::Drawing::Point(247, 53);
			this->Slot5label->Name = L"Slot5label";
			this->Slot5label->Size = System::Drawing::Size(13, 13);
			this->Slot5label->TabIndex = 14;
			this->Slot5label->Text = L"5";
			// 
			// Slot4label
			// 
			this->Slot4label->AutoSize = true;
			this->Slot4label->Location = System::Drawing::Point(190, 53);
			this->Slot4label->Name = L"Slot4label";
			this->Slot4label->Size = System::Drawing::Size(13, 13);
			this->Slot4label->TabIndex = 14;
			this->Slot4label->Text = L"4";
			// 
			// Slot3label
			// 
			this->Slot3label->AutoSize = true;
			this->Slot3label->Location = System::Drawing::Point(133, 53);
			this->Slot3label->Name = L"Slot3label";
			this->Slot3label->Size = System::Drawing::Size(13, 13);
			this->Slot3label->TabIndex = 14;
			this->Slot3label->Text = L"3";
			// 
			// Slot2label
			// 
			this->Slot2label->AutoSize = true;
			this->Slot2label->Location = System::Drawing::Point(75, 53);
			this->Slot2label->Name = L"Slot2label";
			this->Slot2label->Size = System::Drawing::Size(13, 13);
			this->Slot2label->TabIndex = 14;
			this->Slot2label->Text = L"2";
			// 
			// Slot1label
			// 
			this->Slot1label->AutoSize = true;
			this->Slot1label->BackColor = System::Drawing::Color::Transparent;
			this->Slot1label->Location = System::Drawing::Point(18, 53);
			this->Slot1label->Name = L"Slot1label";
			this->Slot1label->Size = System::Drawing::Size(13, 13);
			this->Slot1label->TabIndex = 14;
			this->Slot1label->Text = L"1";
			// 
			// tMinus20
			// 
			this->tMinus20->Interval = 1000;
			this->tMinus20->Tick += gcnew System::EventHandler(this, &UserInterface::tMinus20_Tick);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(474, 396);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(43, 20);
			this->numericUpDown1->TabIndex = 21;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// helpButton
			// 
			this->helpButton->Location = System::Drawing::Point(474, 295);
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(43, 82);
			this->helpButton->TabIndex = 18;
			this->helpButton->Text = L"Help";
			this->helpButton->UseVisualStyleBackColor = true;
			this->helpButton->Click += gcnew System::EventHandler(this, &UserInterface::helpButton_Click);
			// 
			// StartTimerTextLabel
			// 
			this->StartTimerTextLabel->AutoSize = true;
			this->StartTimerTextLabel->Location = System::Drawing::Point(468, 380);
			this->StartTimerTextLabel->Name = L"StartTimerTextLabel";
			this->StartTimerTextLabel->Size = System::Drawing::Size(58, 13);
			this->StartTimerTextLabel->TabIndex = 20;
			this->StartTimerTextLabel->Text = L"Start Timer";
			// 
			// StopMiningButton
			// 
			this->StopMiningButton->Enabled = false;
			this->StopMiningButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StopMiningButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StopMiningButton.Image")));
			this->StopMiningButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->StopMiningButton->Location = System::Drawing::Point(368, 295);
			this->StopMiningButton->Name = L"StopMiningButton";
			this->StopMiningButton->Size = System::Drawing::Size(100, 23);
			this->StopMiningButton->TabIndex = 17;
			this->StopMiningButton->Text = L"Stop Mining";
			this->StopMiningButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->StopMiningButton->UseVisualStyleBackColor = true;
			this->StopMiningButton->Click += gcnew System::EventHandler(this, &UserInterface::StopMiningButton_Click);
			// 
			// MiningTimer
			// 
			this->MiningTimer->Interval = 101;
			this->MiningTimer->Tick += gcnew System::EventHandler(this, &UserInterface::MiningTimer_Tick);
			// 
			// CounterTimer
			// 
			this->CounterTimer->Interval = 101;
			this->CounterTimer->Tick += gcnew System::EventHandler(this, &UserInterface::CounterTimer_Tick);
			// 
			// eatingTimer
			// 
			this->eatingTimer->Interval = 101;
			this->eatingTimer->Tick += gcnew System::EventHandler(this, &UserInterface::eatingTimer_Tick);
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::Lime;
			this->progressBar1->Location = System::Drawing::Point(15, 349);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(147, 10);
			this->progressBar1->TabIndex = 16;
			this->progressBar1->Visible = false;
			// 
			// progressBar2
			// 
			this->progressBar2->ForeColor = System::Drawing::Color::Lime;
			this->progressBar2->Location = System::Drawing::Point(15, 310);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(147, 10);
			this->progressBar2->TabIndex = 15;
			this->progressBar2->Visible = false;
			// 
			// UserInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(532, 428);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->StopMiningButton);
			this->Controls->Add(this->StartTimerTextLabel);
			this->Controls->Add(this->helpButton);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->TimeLabel);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"UserInterface";
			this->Text = L"Auto-Cobblestone Miner";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stonepaxeFoto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->goldpaxeFoto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->netheriteaxeFoto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->diamondpaxeFoto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ironpaxeFoto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->woodpaxeFoto))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSlotStart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSlotEnde))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	if (RBchecked == true && RBchecked2 == true) {
		ToggleAll();
		progressBar1->Value = 0;
		progressBar2->Value = 0;
		tMinus20->Start();
		numericUpDown1->Enabled = false;
		startButton->Enabled = false;
		helpButton->Enabled = false;
		StopMiningButton->Enabled = true;
	}
	else {
		if (RBchecked == false) {
			Error1String = "No pickaxe selected\n";
		}
		if (RBchecked2 == false) {
			Error2String = "No enchantment level selected\n";
		}
		MessageBox::Show(Error1String+Error2String, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		Error1String = "";
		Error2String = "";
		resetProperties();
	}
		
	

	}
private: System::Void woodpaxeRB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	TimerOG = 82500;
	pickSpeed = 2.0;
	pickDur = 59 - 5;
	pickID = 1;
	RBchecked = true;
	}
private: System::Void stonepaxeRB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	TimerOG = 94500;
	pickSpeed = 4.0;
	pickDur = 131 - 5;
	pickID = 2;
	RBchecked = true;
	}
private: System::Void ironpaxeRB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	TimerOG = 122500;
	pickSpeed = 6.0;
	pickDur = 250 - 5;
	pickID = 3;
	RBchecked = true;
}
private: System::Void diamondpaxeRB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	TimerOG = 622400;
	pickSpeed = 8.0;
	pickDur = 1564 - 5;
	pickID = 4;
	RBchecked = true;
}
private: System::Void netheritepaxeRB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	TimerOG = 709100;
	pickSpeed = 9.0;
	pickDur = 2031 - 5;
	pickID = 5;
	RBchecked = true;
}
private: System::Void goldpaxeRB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	TimerOG = 7500;
	pickSpeed = 12.0;
	pickDur = 30 - 2;
	pickID = 6;
	RBchecked = true;
}
private: System::Void eff0RB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	efficiency = 0;
	efficiencyINT = 0;
	RBchecked2 = true;
}
private: System::Void eff1RB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	efficiency = 1;
	efficiencyINT = 1;
	RBchecked2 = true;
}
private: System::Void eff2RB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	efficiency = 2;
	efficiencyINT = 2;
	RBchecked2 = true;
}
private: System::Void eff3RB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	efficiency = 3;
	efficiencyINT = 3;
	RBchecked2 = true;
}
private: System::Void eff4RB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	efficiency = 4;
	efficiencyINT = 4;
	RBchecked2 = true;
}
private: System::Void eff5RB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	efficiency = 5;
	efficiencyINT = 5;
	RBchecked2 = true;
}

private: System::Void trackBarSlotStart_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	slotStart = trackBarSlotStart->Value;
	if (trackBarSlotEnde->Value < trackBarSlotStart->Value) {
		trackBarSlotEnde->Value = trackBarSlotStart->Value;
		slotEnd = trackBarSlotEnde->Value;
	}
	
}

private: System::Void trackBarSlotEnde_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	slotEnd = trackBarSlotEnde->Value;
	if (trackBarSlotEnde->Value < trackBarSlotStart->Value) {
		trackBarSlotEnde->Value = trackBarSlotStart->Value;
		slotEnd = trackBarSlotEnde->Value;
	}
}
private: System::Void tMinus20_Tick(System::Object^ sender, System::EventArgs^ e) {
	
	if (numericUpDown1->Value < 5) {
		numericUpDown1->Value = 5;
	}
	else if (numericUpDown1->Value > 20) {
		numericUpDown1->Value = 20;
	}
	
	StartingTimerValue = numericUpDown1->Value.ToDouble(numericUpDown1->Value) - iteration;
	StartingTimerValueOG = numericUpDown1->Value.ToDouble(numericUpDown1->Value);

	_ticks++;
	TimeLabel->Text = "Starting in " + StartingTimerValue + " seconds\n\n\n\n\n\n" +
		 "- select the first pickaxe in your hotbar\n"
		 "- the cobblestone miner will automatically eat, to prevent you from starving.\n"
		 "  put food in your offhand";
	iteration++;
	


	if (_ticks == StartingTimerValueOG+1) {
		iteration = 0;
		_ticks = 0;
		TimeLabel->Text = "Starting now...";
		tMinus20->Stop();
		numericUpDown1->Enabled = true;
		MiningTimer->Start();
	}

}
private: System::Void StopMiningButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ToggleAll();
	tMinus20->Stop();
	MiningTimer->Stop();
	CounterTimer->Stop();
	progressBar1->Visible = false;
	progressBar1->Value = 0;
	progressBar2->Visible = 0;
	progressBar2->Value = 0;
	TimeLabel->Text = "Stopped";
	iteration = 0;
	numericUpDown1->Enabled = true;
	startButton->Enabled = true;
	helpButton->Enabled = true;

	woodpaxeRB->Checked = false;
	stonepaxeRB->Checked = false;
	goldpaxeRB->Checked = false;
	ironpaxeRB->Checked = false;
	diamondpaxeRB->Checked = false;
	netheritepaxeRB->Checked = false;

	MiningTimer->Interval = 101;
	CounterTimer->Interval = 101;

	eff0RB->Checked = false;
	eff1RB->Checked = false;
	eff2RB->Checked = false;
	eff3RB->Checked = false;
	eff4RB->Checked = false;
	eff5RB->Checked = false;
	RBchecked = false;
	RBchecked2 = false;

	clock1 = 0;

	slotStart = 1;
	Slot = slotStart;
	slotEnd = 9;
	trackBarSlotStart->Value = 1;
	trackBarSlotEnde->Value = 9;

	_ticks = 0;
	_ticks2 = 0;

	StopMiningButton->Enabled = false;

	progressBar1->Value = 0;
	progressBar2->Value = 0;


}
private: System::Void MiningTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (_ticks == 0) {
		_ticks2 = 0;
		_tick3 = 0;
		Slot = slotStart;
		TimerCalc();
		fMinSec();
		optZusammenf();
		MiningTimer->Stop();//

		MiningTimer->Interval = 200;
		CounterTimer->Start();
					
		_ticks++;
		
	}
	else if (_ticks > 0 && _ticks <= ((slotStart-slotEnd)*-1)) {
		_ticks++;

		if (((slotStart - slotEnd) * -1) == 1) {
			progressBar2->Step = 50;
			progressBar2->PerformStep();
		}
		else if (((slotStart - slotEnd) * -1) == 2) {
			progressBar2->Step = 33;
			progressBar2->PerformStep();
		}
		else if (((slotStart - slotEnd) * -1) == 3) {
			progressBar2->Step = 25;
			progressBar2->PerformStep();
		}
		else if (((slotStart - slotEnd) * -1) == 4) {
			progressBar2->Step = 20;
			progressBar2->PerformStep();
		}
		else if (((slotStart - slotEnd) * -1) == 5) {
			progressBar2->Step = 16;
			progressBar2->PerformStep();
		}
		else if (((slotStart - slotEnd) * -1) == 6) {
			progressBar2->Step = 14;
			progressBar2->PerformStep();
		}
		else if (((slotStart - slotEnd) * -1) == 7) {
			progressBar2->Step = 12;
			progressBar2->PerformStep();
		}
		else if (((slotStart - slotEnd) * -1) == 8) {
			progressBar2->Step = 11;
			progressBar2->PerformStep();
		}
		else {
			progressBar2->Step = 100;
		}

		CounterTimer->Start();
	}
	else if (_ticks > ((slotStart - slotEnd) * -1)) {
		TimerCalc();
		fMinSec();
		optZusammenf();

		int BlockMinedInsgesamt = floor(((TimerOG / ((ceil(1 / damage) / 20) * 1000)) * ((slotEnd - slotStart) + 1)));
		String^ BlocksMinedInsgesamtString = BlockMinedInsgesamt.ToString();

		MiningTimer->Stop();
		MiningTimer->Interval = 101;

		TimeLabel->Text = "MINING FINISHED\n\n\n\n\n\n\n\n" +
			"*under perfect conditions you mined " + BlocksMinedInsgesamtString
			 + " blocks*";

		progressBar2->Value = 100;
		progressBar1->Visible = false;
		resetProperties();
		StopMiningButton->Enabled = false;
		startButton->Enabled = true;
		ToggleAll();
		MiningTimer->Stop();
		CounterTimer->Stop();
		MiningTimer->Interval = 101;
		_ticks = 0;
		_ticks2 = 0;
		_tick3 = 0;

	}

	
	}
private: System::Void CounterTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (_ticks2 == 0) {
		MiningTimer->Stop();
		progressBar1->Visible = true;
		progressBar2->Visible = true;
		TimerCalc();
		fMinSec();
		optZusammenf();
		Counter();
		
		int CounterTimerSleep;
		CounterTimerSleep = ((old_clock * TimerMultiplier)/*+1000*/);
		CounterTimer->Interval = CounterTimerSleep;
		
		_ticks2++;
	}
	else if(_ticks2 >= 1 && _ticks2 <= 8) {
		progressBar1->PerformStep();
		_ticks2++;
		Counter();
		}
	else if (_ticks2 == 9) {
		progressBar1->PerformStep();
		Counter();
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		eatingTimer->Start();
		progressBar1->PerformStep();
		CounterTimer->Stop();
		CounterTimer->Interval = 101;
		_ticks2++;
		_ticks2 = 0;
	}
	else if (_ticks2 >= 10) {
		CounterTimer->Stop();
		_ticks2 = 0;
		CounterTimer->Interval = 101;
		
	}
	}
private: System::Void eatingTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (_tick3 == 0) {
		eatingTimer->Interval = 2000;
		_tick3++;
		eatingStart();
	}
	else if (_tick3 == 1) {
		eatingEnd();
		Slot++;
		_tick3++;
		eatingTimer->Interval = 120;
		}
	else if (_tick3 > 1) {
		//progressBar1->PerformStep();
		eatingTimer->Stop();
		eatingTimer->Interval = 101;
		clock1 = 0;
		_tick3 = 0;
		MiningTimer->Start();
		progressBar1->Value = 0;
	}
}
private: System::Void helpButton_Click(System::Object^ sender, System::EventArgs^ e) {
	 help ^ helpForm = gcnew help;
	 helpForm->ShowDialog();
}
};
}
