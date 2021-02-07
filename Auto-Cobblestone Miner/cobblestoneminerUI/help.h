#pragma once
#include <stdlib.h>
#include <windows.h>
#include <shellapi.h>


namespace cobblestoneminerUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for help
	/// </summary>
	public ref class help : public System::Windows::Forms::Form
	{
	public:
		help(void)
		{
			InitializeComponent();
			//
			
			timer1->Start();
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~help()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ OKbutton;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Timer^ timer1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(help::typeid));
			this->OKbutton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// OKbutton
			// 
			this->OKbutton->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->OKbutton->Location = System::Drawing::Point(431, 148);
			this->OKbutton->Name = L"OKbutton";
			this->OKbutton->Size = System::Drawing::Size(41, 23);
			this->OKbutton->TabIndex = 0;
			this->OKbutton->Text = L"OK";
			this->OKbutton->UseVisualStyleBackColor = false;
			this->OKbutton->Click += gcnew System::EventHandler(this, &help::OKbutton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(310, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Auto-Cobblestone Miner for Minecraft";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(220, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Tool, made to farm cobblestone while AFKing";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(192, 65);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Features:\r\n- stops mining at low pickaxe durability\r\n- swaps through pickaxes in "
				L"hotbar\r\n- automatic eating\r\n- support for all pickaxe & efficiency level";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 158);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(413, 858);
			this->label4->TabIndex = 5;
			this->label4->Text = resources->GetString(L"label4.Text");
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Location = System::Drawing::Point(345, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(127, 130);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->Location = System::Drawing::Point(17, 202);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(250, 250);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox3->Location = System::Drawing::Point(12, 605);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(302, 301);
			this->pictureBox3->TabIndex = 7;
			this->pictureBox3->TabStop = false;
			// 
			// linkLabel1
			// 
			this->linkLabel1->ActiveLinkColor = System::Drawing::Color::Chartreuse;
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(16, 50);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(290, 13);
			this->linkLabel1->TabIndex = 8;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"https://github.com/realKampfKroete/AutoCobblestoneMiner";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &help::linkLabel1_LinkClicked);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->Location = System::Drawing::Point(17, 202);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(250, 250);
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1600;
			this->timer1->Tick += gcnew System::EventHandler(this, &help::timer1_Tick);
			// 
			// help
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(513, 571);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->OKbutton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"help";
			this->Text = L"Help";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OKbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		Form::Close();
		timer1->Stop();
	}
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		ShellExecute(0, 0, L"https://github.com/realKampfKroete/AutoCobblestoneMiner", 0, 0, SW_SHOW);
	}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	pictureBox2->Visible = !pictureBox2->Visible;
	pictureBox4->Visible = !pictureBox4->Visible;
}
};
}
