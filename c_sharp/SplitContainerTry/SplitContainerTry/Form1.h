#pragma once

namespace SplitContainerTry {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
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
	private: System::Windows::Forms::SplitContainer^  outerSplitContainer;

	protected: 

	protected: 
		//bool hide;

	private: System::Windows::Forms::SplitContainer^  innerSplitContainer;
	private: System::Windows::Forms::ComboBox^  comboBoxForPanelChange;
	private: System::Windows::Forms::SplitContainer^  singleSplitContainer;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;


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
			this->outerSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->innerSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->comboBoxForPanelChange = (gcnew System::Windows::Forms::ComboBox());
			this->singleSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->outerSplitContainer))->BeginInit();
			this->outerSplitContainer->Panel1->SuspendLayout();
			this->outerSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->innerSplitContainer))->BeginInit();
			this->innerSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->singleSplitContainer))->BeginInit();
			this->singleSplitContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// outerSplitContainer
			// 
			this->outerSplitContainer->AccessibleName = L"OuterContainer";
			this->outerSplitContainer->Location = System::Drawing::Point(28, 12);
			this->outerSplitContainer->Name = L"outerSplitContainer";
			this->outerSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// outerSplitContainer.Panel1
			// 
			this->outerSplitContainer->Panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->outerSplitContainer->Panel1->Controls->Add(this->innerSplitContainer);
			this->outerSplitContainer->Panel1MinSize = 22;
			// 
			// outerSplitContainer.Panel2
			// 
			this->outerSplitContainer->Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->outerSplitContainer->Panel2MinSize = 22;
			this->outerSplitContainer->Size = System::Drawing::Size(600, 69);
			this->outerSplitContainer->SplitterDistance = 45;
			this->outerSplitContainer->SplitterWidth = 1;
			this->outerSplitContainer->TabIndex = 0;
			// 
			// innerSplitContainer
			// 
			this->innerSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->innerSplitContainer->Location = System::Drawing::Point(0, 0);
			this->innerSplitContainer->Name = L"innerSplitContainer";
			this->innerSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// innerSplitContainer.Panel1
			// 
			this->innerSplitContainer->Panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->innerSplitContainer->Panel1MinSize = 0;
			// 
			// innerSplitContainer.Panel2
			// 
			this->innerSplitContainer->Panel2->BackColor = System::Drawing::Color::Cyan;
			this->innerSplitContainer->Panel2MinSize = 0;
			this->innerSplitContainer->Size = System::Drawing::Size(600, 45);
			this->innerSplitContainer->SplitterDistance = 20;
			this->innerSplitContainer->SplitterWidth = 1;
			this->innerSplitContainer->TabIndex = 0;
			// 
			// comboBoxForPanelChange
			// 
			this->comboBoxForPanelChange->FormattingEnabled = true;
			this->comboBoxForPanelChange->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Inner Panel 1", L"Inner Panel 2", 
				L"Inner Panel 1 & 2"});
			this->comboBoxForPanelChange->Location = System::Drawing::Point(229, 227);
			this->comboBoxForPanelChange->Name = L"comboBoxForPanelChange";
			this->comboBoxForPanelChange->Size = System::Drawing::Size(121, 21);
			this->comboBoxForPanelChange->TabIndex = 1;
			this->comboBoxForPanelChange->Tag = L"";
			this->comboBoxForPanelChange->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxForPanelChange_SelectedIndexChanged);
			// 
			// singleSplitContainer
			// 
			this->singleSplitContainer->Location = System::Drawing::Point(64, 121);
			this->singleSplitContainer->Name = L"singleSplitContainer";
			this->singleSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// singleSplitContainer.Panel1
			// 
			this->singleSplitContainer->Panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->singleSplitContainer->Panel1MinSize = 22;
			// 
			// singleSplitContainer.Panel2
			// 
			this->singleSplitContainer->Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->singleSplitContainer->Panel2MinSize = 22;
			this->singleSplitContainer->Size = System::Drawing::Size(500, 46);
			this->singleSplitContainer->SplitterDistance = 22;
			this->singleSplitContainer->SplitterWidth = 1;
			this->singleSplitContainer->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->panel1->Location = System::Drawing::Point(64, 174);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(500, 23);
			this->panel1->TabIndex = 3;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(449, 227);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(200, 100);
			this->flowLayoutPanel1->TabIndex = 4;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(356, 263);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(200, 100);
			this->tableLayoutPanel1->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(675, 322);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->singleSplitContainer);
			this->Controls->Add(this->comboBoxForPanelChange);
			this->Controls->Add(this->outerSplitContainer);
			this->Name = L"Form1";
			this->Text = L"EmbededSplitContainerForm";
			this->outerSplitContainer->Panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->outerSplitContainer))->EndInit();
			this->outerSplitContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->innerSplitContainer))->EndInit();
			this->innerSplitContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->singleSplitContainer))->EndInit();
			this->singleSplitContainer->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 /*if (hide)
				 {
					 hide = false;
					 this->button1->Text = L"Show";
				 }
				 else
				 {
					 hide = true;
					 this->button1->Text = L"Hide";
				 }*/
			 }
	private: System::Void comboBoxForPanelChange_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(this->comboBoxForPanelChange->SelectedIndex == 0) {
					 this->innerSplitContainer->Panel1Collapsed = false;
					 this->innerSplitContainer->Panel2Collapsed = true;
					 this->singleSplitContainer->Panel1Collapsed = false;
					 this->singleSplitContainer->Panel2Collapsed = true;
				 }
				 if(this->comboBoxForPanelChange->SelectedIndex == 1) {
					 this->innerSplitContainer->Panel1Collapsed = true;
					 this->innerSplitContainer->Panel2Collapsed = false;
					 this->singleSplitContainer->Panel1Collapsed = true;
					 this->singleSplitContainer->Panel2Collapsed = false;
				 }
				 if(this->comboBoxForPanelChange->SelectedIndex == 2) {
					 this->innerSplitContainer->Panel1Collapsed = false;
					 this->innerSplitContainer->Panel2Collapsed = false;
					 this->singleSplitContainer->Panel1Collapsed = false;
					 this->singleSplitContainer->Panel2Collapsed = false;
				 }
			 }
};
}

