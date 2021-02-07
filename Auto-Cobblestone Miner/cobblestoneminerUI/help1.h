#pragma once

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
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->OKbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// OKbutton
			// 
			this->OKbutton->BackColor = System::Drawing::SystemColors::Control;
			this->OKbutton->Location = System::Drawing::Point(380, 536);
			this->OKbutton->Name = L"OKbutton";
			this->OKbutton->Size = System::Drawing::Size(75, 23);
			this->OKbutton->TabIndex = 0;
			this->OKbutton->Text = L"OK";
			this->OKbutton->UseVisualStyleBackColor = false;
			this->OKbutton->Click += gcnew System::EventHandler(this, &help::OKbutton_Click);
			// 
			// help
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 571);
			this->Controls->Add(this->OKbutton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"help";
			this->ShowIcon = false;
			this->Text = L"Help";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OKbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		Form::Close();
	}
	};
}
