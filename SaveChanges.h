#pragma once
#include <stdio.h>

namespace Notepad2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ SaveChanges
	/// </summary>
	public ref class SaveChanges : public System::Windows::Forms::Form
	{
	public:
		bool em1;
		String ^ n2;
		RichTextBox ^ richTextBox2 = gcnew RichTextBox;
		SaveChanges(String ^ n)
		{
			n2 = n;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SaveChanges()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SaveChanges::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(44, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Yes";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SaveChanges::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(154, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"No";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SaveChanges::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(256, 85);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Cancel";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &SaveChanges::button3_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->ForeColor = System::Drawing::Color::RoyalBlue;
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(354, 80);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"Save changes in text file\? ";
			// 
			// SaveChanges
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(353, 120);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SaveChanges";
			this->Text = L"SaveChanges";
			this->Load += gcnew System::EventHandler(this, &SaveChanges::SaveChanges_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void SaveChanges_Load(System::Object^  sender, System::EventArgs^  e) {
	richTextBox1->Text = L"Save changes in text file: " + n2;
	richTextBox2->LoadFile("temp.rtf", RichTextBoxStreamType::RichText);

	em1 = false;
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog^ saveFile1 = gcnew SaveFileDialog;

	saveFile1->DefaultExt = "*.doc";
	saveFile1->Filter = "DOC Files|*.doc|TXT Files|*.txt|RTF Files|*.rtf";

	if (saveFile1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
		saveFile1->FileName->Length > 0)
	{
		richTextBox2->SaveFile(saveFile1->FileName, RichTextBoxStreamType::RichText);
	}
	richTextBox2->Text = "";
	richTextBox2->SaveFile("temp.rtf", RichTextBoxStreamType::RichText);
	this->Close();
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	richTextBox2->Text = "";
	richTextBox2->SaveFile("temp.rtf", RichTextBoxStreamType::RichText);
	this->Close();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	em1 = true;
	this->Close();
}
};
}
