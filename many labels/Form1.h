#pragma once


namespace ManyLabels {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	protected: 


	protected: 

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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(292, 273);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->Text = L"Labels";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 System::Drawing::Font ^font = gcnew System::Drawing::Font( "Microsoft Sans Serif",6 );
				 System::Windows::Forms::Label ^p,^q;
				 unsigned int x,y;
				 unsigned int width = 12 , height = 12;


				 for(x = 0 ; x < 90 ; ++x)
					 for(y = 0 ; y < 70 ; ++y)
					 {
						 p = gcnew System::Windows::Forms::Label;
						 p->Font = font;
						 p->Text = "0";
						 p->Width = width;
						 p->Height = height;
						 p->TextAlign = ContentAlignment::MiddleCenter;
						 p->BackColor = Color::Black;
						 p->ForeColor = Color::Lime;
						 p->Left = x*(width+2) + 2;
						 p->Top = y*(height+2) + 2;
						 p->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
						 Form1::Controls->Add(p);
					 }

			 }
	private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 if(e->KeyChar == '\033')
					 exit(0);
			 }

	private: System::Void label_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 char *p;
				 p = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(static_cast<System::Windows::Forms::Label ^>(sender)->Text).ToPointer();
				 static_cast<System::Windows::Forms::Label ^>(sender)->Text = "";
				 static_cast<System::Windows::Forms::Label ^>(sender)->Text += atoi(p)+1;
				 System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr(p));				 
			 }

};
}

