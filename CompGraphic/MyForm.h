#pragma once
#include <vector>
#include "Matrix.h"

namespace CompGraphic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Data;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}


	protected:
		virtual void OnPaint(PaintEventArgs^ e) override
		{
			
		}
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_draw;
	protected:
	private: System::Windows::Forms::Panel^ panel_settings;

	private: System::Windows::Forms::TrackBar^ trackBar_tX;
	private: System::Windows::Forms::TrackBar^ trackBar_tY;
	private: System::Windows::Forms::TrackBar^ trackBar_tZ;
	private: System::Windows::Forms::TrackBar^ trackBar_rZ;
	private: System::Windows::Forms::TrackBar^ trackBar_rY;
	private: System::Windows::Forms::TrackBar^ trackBar_rX;
	private: System::Windows::Forms::TrackBar^ trackBar_sX;
	private: System::Windows::Forms::TrackBar^ trackBar_sZ;
	private: System::Windows::Forms::TrackBar^ trackBar_sY;
	private: System::Windows::Forms::GroupBox^ groupBox_translate;
	private: System::Windows::Forms::GroupBox^ groupBox_Rotate;
	private: System::Windows::Forms::GroupBox^ groupBox_scale;
	private: System::Windows::Forms::Label^ label_tx;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label_tz;
	private: System::Windows::Forms::Label^ label_ty;


	private: System::Windows::Forms::GroupBox^ groupBox_camera;
	private: System::Windows::Forms::Label^ label_cscale;
	private: System::Windows::Forms::TrackBar^ trackBar_cscale;

	private: System::Windows::Forms::Label^ label_rcz;
	private: System::Windows::Forms::TrackBar^ trackBar_rcz;

	private: System::Windows::Forms::Label^ label_rcy;
	private: System::Windows::Forms::TrackBar^ trackBar_rcy;

	private: System::Windows::Forms::Label^ label_rcx;
	private: System::Windows::Forms::TrackBar^ trackBar_rcx;
	private: System::Windows::Forms::Button^ button_crefresh;
	private: System::Windows::Forms::RadioButton^ radioButton_oxy;

	private: System::Windows::Forms::RadioButton^ radioButton_oxz;

	private: System::Windows::Forms::RadioButton^ radioButton_oyz;

	private: System::Windows::Forms::CheckBox^ checkBox_anim;
	private: System::Windows::Forms::TrackBar^ trackBar_perspZ;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;








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
			this->panel_draw = (gcnew System::Windows::Forms::Panel());
			this->groupBox_camera = (gcnew System::Windows::Forms::GroupBox());
			this->button_crefresh = (gcnew System::Windows::Forms::Button());
			this->label_cscale = (gcnew System::Windows::Forms::Label());
			this->trackBar_cscale = (gcnew System::Windows::Forms::TrackBar());
			this->label_rcz = (gcnew System::Windows::Forms::Label());
			this->trackBar_rcz = (gcnew System::Windows::Forms::TrackBar());
			this->label_rcy = (gcnew System::Windows::Forms::Label());
			this->trackBar_rcy = (gcnew System::Windows::Forms::TrackBar());
			this->label_rcx = (gcnew System::Windows::Forms::Label());
			this->trackBar_rcx = (gcnew System::Windows::Forms::TrackBar());
			this->panel_settings = (gcnew System::Windows::Forms::Panel());
			this->trackBar_perspZ = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox_anim = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton_oxy = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_oxz = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_oyz = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox_scale = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar_sZ = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->trackBar_sY = (gcnew System::Windows::Forms::TrackBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->trackBar_sX = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox_Rotate = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar_rZ = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar_rY = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar_rX = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox_translate = (gcnew System::Windows::Forms::GroupBox());
			this->label_tz = (gcnew System::Windows::Forms::Label());
			this->label_ty = (gcnew System::Windows::Forms::Label());
			this->label_tx = (gcnew System::Windows::Forms::Label());
			this->trackBar_tZ = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar_tY = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar_tX = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox_camera->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_cscale))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rcz))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rcy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rcx))->BeginInit();
			this->panel_settings->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_perspZ))->BeginInit();
			this->groupBox_scale->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_sZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_sY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_sX))->BeginInit();
			this->groupBox_Rotate->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rX))->BeginInit();
			this->groupBox_translate->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_tZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_tY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_tX))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_draw
			// 
			this->panel_draw->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_draw->Location = System::Drawing::Point(0, 0);
			this->panel_draw->Margin = System::Windows::Forms::Padding(4);
			this->panel_draw->Name = L"panel_draw";
			this->panel_draw->Size = System::Drawing::Size(1261, 825);
			this->panel_draw->TabIndex = 0;
			this->panel_draw->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_draw_Paint);
			// 
			// groupBox_camera
			// 
			this->groupBox_camera->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->groupBox_camera->Controls->Add(this->button_crefresh);
			this->groupBox_camera->Controls->Add(this->label_cscale);
			this->groupBox_camera->Controls->Add(this->trackBar_cscale);
			this->groupBox_camera->Controls->Add(this->label_rcz);
			this->groupBox_camera->Controls->Add(this->trackBar_rcz);
			this->groupBox_camera->Controls->Add(this->label_rcy);
			this->groupBox_camera->Controls->Add(this->trackBar_rcy);
			this->groupBox_camera->Controls->Add(this->label_rcx);
			this->groupBox_camera->Controls->Add(this->trackBar_rcx);
			this->groupBox_camera->Location = System::Drawing::Point(0, 623);
			this->groupBox_camera->Name = L"groupBox_camera";
			this->groupBox_camera->Size = System::Drawing::Size(276, 199);
			this->groupBox_camera->TabIndex = 13;
			this->groupBox_camera->TabStop = false;
			this->groupBox_camera->Text = L"Camera";
			// 
			// button_crefresh
			// 
			this->button_crefresh->Location = System::Drawing::Point(100, 168);
			this->button_crefresh->Name = L"button_crefresh";
			this->button_crefresh->Size = System::Drawing::Size(76, 23);
			this->button_crefresh->TabIndex = 14;
			this->button_crefresh->Text = L"Refresh";
			this->button_crefresh->UseVisualStyleBackColor = true;
			this->button_crefresh->Click += gcnew System::EventHandler(this, &MyForm::button_crefresh_Click);
			// 
			// label_cscale
			// 
			this->label_cscale->AutoSize = true;
			this->label_cscale->Location = System::Drawing::Point(0, 137);
			this->label_cscale->Name = L"label_cscale";
			this->label_cscale->Size = System::Drawing::Size(42, 16);
			this->label_cscale->TabIndex = 14;
			this->label_cscale->Text = L"Scale";
			// 
			// trackBar_cscale
			// 
			this->trackBar_cscale->Location = System::Drawing::Point(30, 137);
			this->trackBar_cscale->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_cscale->Maximum = 300;
			this->trackBar_cscale->Minimum = 10;
			this->trackBar_cscale->Name = L"trackBar_cscale";
			this->trackBar_cscale->Size = System::Drawing::Size(229, 45);
			this->trackBar_cscale->TabIndex = 13;
			this->trackBar_cscale->Value = 100;
			this->trackBar_cscale->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_cscale_Scroll);
			// 
			// label_rcz
			// 
			this->label_rcz->AutoSize = true;
			this->label_rcz->Location = System::Drawing::Point(10, 105);
			this->label_rcz->Name = L"label_rcz";
			this->label_rcz->Size = System::Drawing::Size(25, 16);
			this->label_rcz->TabIndex = 12;
			this->label_rcz->Text = L"RZ";
			// 
			// trackBar_rcz
			// 
			this->trackBar_rcz->Location = System::Drawing::Point(30, 100);
			this->trackBar_rcz->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_rcz->Maximum = 360;
			this->trackBar_rcz->Name = L"trackBar_rcz";
			this->trackBar_rcz->Size = System::Drawing::Size(229, 45);
			this->trackBar_rcz->TabIndex = 9;
			this->trackBar_rcz->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_rcz_Scroll);
			// 
			// label_rcy
			// 
			this->label_rcy->AutoSize = true;
			this->label_rcy->Location = System::Drawing::Point(10, 65);
			this->label_rcy->Name = L"label_rcy";
			this->label_rcy->Size = System::Drawing::Size(26, 16);
			this->label_rcy->TabIndex = 11;
			this->label_rcy->Text = L"RY";
			// 
			// trackBar_rcy
			// 
			this->trackBar_rcy->Location = System::Drawing::Point(30, 60);
			this->trackBar_rcy->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_rcy->Maximum = 360;
			this->trackBar_rcy->Name = L"trackBar_rcy";
			this->trackBar_rcy->Size = System::Drawing::Size(229, 45);
			this->trackBar_rcy->TabIndex = 8;
			this->trackBar_rcy->Value = 348;
			this->trackBar_rcy->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_rcy_Scroll);
			// 
			// label_rcx
			// 
			this->label_rcx->AutoSize = true;
			this->label_rcx->Location = System::Drawing::Point(10, 25);
			this->label_rcx->Name = L"label_rcx";
			this->label_rcx->Size = System::Drawing::Size(25, 16);
			this->label_rcx->TabIndex = 10;
			this->label_rcx->Text = L"RX";
			// 
			// trackBar_rcx
			// 
			this->trackBar_rcx->Location = System::Drawing::Point(30, 20);
			this->trackBar_rcx->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_rcx->Maximum = 360;
			this->trackBar_rcx->Name = L"trackBar_rcx";
			this->trackBar_rcx->Size = System::Drawing::Size(229, 45);
			this->trackBar_rcx->TabIndex = 7;
			this->trackBar_rcx->Value = 192;
			this->trackBar_rcx->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_rcx_Scroll);
			// 
			// panel_settings
			// 
			this->panel_settings->Controls->Add(this->label7);
			this->panel_settings->Controls->Add(this->checkBox2);
			this->panel_settings->Controls->Add(this->checkBox1);
			this->panel_settings->Controls->Add(this->trackBar_perspZ);
			this->panel_settings->Controls->Add(this->checkBox_anim);
			this->panel_settings->Controls->Add(this->radioButton_oxy);
			this->panel_settings->Controls->Add(this->radioButton_oxz);
			this->panel_settings->Controls->Add(this->radioButton_oyz);
			this->panel_settings->Controls->Add(this->groupBox_camera);
			this->panel_settings->Controls->Add(this->groupBox_scale);
			this->panel_settings->Controls->Add(this->groupBox_Rotate);
			this->panel_settings->Controls->Add(this->groupBox_translate);
			this->panel_settings->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel_settings->Location = System::Drawing::Point(0, 0);
			this->panel_settings->Margin = System::Windows::Forms::Padding(4);
			this->panel_settings->Name = L"panel_settings";
			this->panel_settings->Size = System::Drawing::Size(276, 825);
			this->panel_settings->TabIndex = 1;
			// 
			// trackBar_perspZ
			// 
			this->trackBar_perspZ->Location = System::Drawing::Point(30, 523);
			this->trackBar_perspZ->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_perspZ->Maximum = 1000;
			this->trackBar_perspZ->Minimum = 25;
			this->trackBar_perspZ->Name = L"trackBar_perspZ";
			this->trackBar_perspZ->Size = System::Drawing::Size(229, 45);
			this->trackBar_perspZ->TabIndex = 15;
			this->trackBar_perspZ->Value = 250;
			this->trackBar_perspZ->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_perspZ_Scroll);
			// 
			// checkBox_anim
			// 
			this->checkBox_anim->AutoSize = true;
			this->checkBox_anim->Location = System::Drawing::Point(12, 470);
			this->checkBox_anim->Name = L"checkBox_anim";
			this->checkBox_anim->Size = System::Drawing::Size(85, 20);
			this->checkBox_anim->TabIndex = 17;
			this->checkBox_anim->Text = L"Animation";
			this->checkBox_anim->UseVisualStyleBackColor = true;
			this->checkBox_anim->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_anim_CheckedChanged);
			// 
			// radioButton_oxy
			// 
			this->radioButton_oxy->AutoSize = true;
			this->radioButton_oxy->Location = System::Drawing::Point(128, 496);
			this->radioButton_oxy->Name = L"radioButton_oxy";
			this->radioButton_oxy->Size = System::Drawing::Size(52, 20);
			this->radioButton_oxy->TabIndex = 16;
			this->radioButton_oxy->Text = L"OXY";
			this->radioButton_oxy->UseVisualStyleBackColor = true;
			this->radioButton_oxy->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_oxy_CheckedChanged);
			// 
			// radioButton_oxz
			// 
			this->radioButton_oxz->AutoSize = true;
			this->radioButton_oxz->Location = System::Drawing::Point(71, 496);
			this->radioButton_oxz->Name = L"radioButton_oxz";
			this->radioButton_oxz->Size = System::Drawing::Size(51, 20);
			this->radioButton_oxz->TabIndex = 15;
			this->radioButton_oxz->Text = L"OXZ";
			this->radioButton_oxz->UseVisualStyleBackColor = true;
			this->radioButton_oxz->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_oxz_CheckedChanged);
			// 
			// radioButton_oyz
			// 
			this->radioButton_oyz->AutoSize = true;
			this->radioButton_oyz->Checked = true;
			this->radioButton_oyz->Location = System::Drawing::Point(13, 496);
			this->radioButton_oyz->Name = L"radioButton_oyz";
			this->radioButton_oyz->Size = System::Drawing::Size(52, 20);
			this->radioButton_oyz->TabIndex = 14;
			this->radioButton_oyz->TabStop = true;
			this->radioButton_oyz->Text = L"OYZ";
			this->radioButton_oyz->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->radioButton_oyz->UseVisualStyleBackColor = true;
			this->radioButton_oyz->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_oyz_CheckedChanged);
			// 
			// groupBox_scale
			// 
			this->groupBox_scale->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_scale->Controls->Add(this->label4);
			this->groupBox_scale->Controls->Add(this->trackBar_sZ);
			this->groupBox_scale->Controls->Add(this->label5);
			this->groupBox_scale->Controls->Add(this->trackBar_sY);
			this->groupBox_scale->Controls->Add(this->label6);
			this->groupBox_scale->Controls->Add(this->trackBar_sX);
			this->groupBox_scale->Location = System::Drawing::Point(0, 300);
			this->groupBox_scale->Name = L"groupBox_scale";
			this->groupBox_scale->Size = System::Drawing::Size(276, 150);
			this->groupBox_scale->TabIndex = 12;
			this->groupBox_scale->TabStop = false;
			this->groupBox_scale->Text = L"Scale";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(20, 105);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Z";
			// 
			// trackBar_sZ
			// 
			this->trackBar_sZ->Location = System::Drawing::Point(30, 100);
			this->trackBar_sZ->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_sZ->Maximum = 100;
			this->trackBar_sZ->Minimum = 1;
			this->trackBar_sZ->Name = L"trackBar_sZ";
			this->trackBar_sZ->Size = System::Drawing::Size(229, 45);
			this->trackBar_sZ->TabIndex = 9;
			this->trackBar_sZ->Value = 10;
			this->trackBar_sZ->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_sZ_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(20, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(16, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Y";
			// 
			// trackBar_sY
			// 
			this->trackBar_sY->Location = System::Drawing::Point(30, 60);
			this->trackBar_sY->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_sY->Maximum = 100;
			this->trackBar_sY->Minimum = 1;
			this->trackBar_sY->Name = L"trackBar_sY";
			this->trackBar_sY->Size = System::Drawing::Size(229, 45);
			this->trackBar_sY->TabIndex = 8;
			this->trackBar_sY->Value = 10;
			this->trackBar_sY->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_sY_Scroll);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 25);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(15, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"X";
			// 
			// trackBar_sX
			// 
			this->trackBar_sX->Location = System::Drawing::Point(30, 20);
			this->trackBar_sX->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_sX->Maximum = 100;
			this->trackBar_sX->Minimum = 1;
			this->trackBar_sX->Name = L"trackBar_sX";
			this->trackBar_sX->Size = System::Drawing::Size(229, 45);
			this->trackBar_sX->TabIndex = 7;
			this->trackBar_sX->Value = 10;
			this->trackBar_sX->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_sX_Scroll);
			// 
			// groupBox_Rotate
			// 
			this->groupBox_Rotate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_Rotate->Controls->Add(this->label1);
			this->groupBox_Rotate->Controls->Add(this->trackBar_rZ);
			this->groupBox_Rotate->Controls->Add(this->label2);
			this->groupBox_Rotate->Controls->Add(this->label3);
			this->groupBox_Rotate->Controls->Add(this->trackBar_rY);
			this->groupBox_Rotate->Controls->Add(this->trackBar_rX);
			this->groupBox_Rotate->Location = System::Drawing::Point(0, 150);
			this->groupBox_Rotate->Name = L"groupBox_Rotate";
			this->groupBox_Rotate->Size = System::Drawing::Size(276, 150);
			this->groupBox_Rotate->TabIndex = 11;
			this->groupBox_Rotate->TabStop = false;
			this->groupBox_Rotate->Text = L"Rotate";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 105);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(15, 16);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Z";
			// 
			// trackBar_rZ
			// 
			this->trackBar_rZ->Location = System::Drawing::Point(30, 100);
			this->trackBar_rZ->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_rZ->Maximum = 360;
			this->trackBar_rZ->Name = L"trackBar_rZ";
			this->trackBar_rZ->Size = System::Drawing::Size(229, 45);
			this->trackBar_rZ->TabIndex = 6;
			this->trackBar_rZ->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_rZ_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 16);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(15, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"X";
			// 
			// trackBar_rY
			// 
			this->trackBar_rY->Location = System::Drawing::Point(30, 60);
			this->trackBar_rY->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_rY->Maximum = 360;
			this->trackBar_rY->Name = L"trackBar_rY";
			this->trackBar_rY->Size = System::Drawing::Size(229, 45);
			this->trackBar_rY->TabIndex = 5;
			this->trackBar_rY->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_rY_Scroll);
			// 
			// trackBar_rX
			// 
			this->trackBar_rX->Location = System::Drawing::Point(30, 20);
			this->trackBar_rX->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_rX->Maximum = 360;
			this->trackBar_rX->Name = L"trackBar_rX";
			this->trackBar_rX->Size = System::Drawing::Size(229, 45);
			this->trackBar_rX->TabIndex = 4;
			this->trackBar_rX->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_rX_Scroll);
			// 
			// groupBox_translate
			// 
			this->groupBox_translate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_translate->Controls->Add(this->label_tz);
			this->groupBox_translate->Controls->Add(this->label_ty);
			this->groupBox_translate->Controls->Add(this->label_tx);
			this->groupBox_translate->Controls->Add(this->trackBar_tZ);
			this->groupBox_translate->Controls->Add(this->trackBar_tY);
			this->groupBox_translate->Controls->Add(this->trackBar_tX);
			this->groupBox_translate->Location = System::Drawing::Point(0, 0);
			this->groupBox_translate->Margin = System::Windows::Forms::Padding(4);
			this->groupBox_translate->Name = L"groupBox_translate";
			this->groupBox_translate->Padding = System::Windows::Forms::Padding(4);
			this->groupBox_translate->Size = System::Drawing::Size(276, 150);
			this->groupBox_translate->TabIndex = 10;
			this->groupBox_translate->TabStop = false;
			this->groupBox_translate->Text = L"Translate";
			// 
			// label_tz
			// 
			this->label_tz->AutoSize = true;
			this->label_tz->Location = System::Drawing::Point(20, 105);
			this->label_tz->Name = L"label_tz";
			this->label_tz->Size = System::Drawing::Size(15, 16);
			this->label_tz->TabIndex = 6;
			this->label_tz->Text = L"Z";
			// 
			// label_ty
			// 
			this->label_ty->AutoSize = true;
			this->label_ty->Location = System::Drawing::Point(20, 65);
			this->label_ty->Name = L"label_ty";
			this->label_ty->Size = System::Drawing::Size(16, 16);
			this->label_ty->TabIndex = 5;
			this->label_ty->Text = L"Y";
			// 
			// label_tx
			// 
			this->label_tx->AutoSize = true;
			this->label_tx->Location = System::Drawing::Point(20, 25);
			this->label_tx->Name = L"label_tx";
			this->label_tx->Size = System::Drawing::Size(15, 16);
			this->label_tx->TabIndex = 4;
			this->label_tx->Text = L"X";
			// 
			// trackBar_tZ
			// 
			this->trackBar_tZ->Location = System::Drawing::Point(30, 100);
			this->trackBar_tZ->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_tZ->Maximum = 100;
			this->trackBar_tZ->Name = L"trackBar_tZ";
			this->trackBar_tZ->Size = System::Drawing::Size(229, 45);
			this->trackBar_tZ->TabIndex = 3;
			this->trackBar_tZ->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_tZ_Scroll);
			// 
			// trackBar_tY
			// 
			this->trackBar_tY->Location = System::Drawing::Point(30, 60);
			this->trackBar_tY->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_tY->Maximum = 100;
			this->trackBar_tY->Name = L"trackBar_tY";
			this->trackBar_tY->Size = System::Drawing::Size(229, 45);
			this->trackBar_tY->TabIndex = 2;
			this->trackBar_tY->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_tY_Scroll);
			// 
			// trackBar_tX
			// 
			this->trackBar_tX->Location = System::Drawing::Point(30, 20);
			this->trackBar_tX->Margin = System::Windows::Forms::Padding(4);
			this->trackBar_tX->Maximum = 100;
			this->trackBar_tX->Name = L"trackBar_tX";
			this->trackBar_tX->Size = System::Drawing::Size(229, 45);
			this->trackBar_tX->TabIndex = 1;
			this->trackBar_tX->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_tX_Scroll);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 557);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(74, 20);
			this->checkBox1->TabIndex = 18;
			this->checkBox1->Text = L"PerspPt";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(103, 557);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(87, 20);
			this->checkBox2->TabIndex = 19;
			this->checkBox2->Text = L"PerspLine";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 519);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 32);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Persp\r\nPoint";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1261, 825);
			this->Controls->Add(this->panel_settings);
			this->Controls->Add(this->panel_draw);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"LR1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox_camera->ResumeLayout(false);
			this->groupBox_camera->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_cscale))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rcz))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rcy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rcx))->EndInit();
			this->panel_settings->ResumeLayout(false);
			this->panel_settings->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_perspZ))->EndInit();
			this->groupBox_scale->ResumeLayout(false);
			this->groupBox_scale->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_sZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_sY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_sX))->EndInit();
			this->groupBox_Rotate->ResumeLayout(false);
			this->groupBox_Rotate->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rX))->EndInit();
			this->groupBox_translate->ResumeLayout(false);
			this->groupBox_translate->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_tZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_tY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_tX))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel_draw_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: void setupCamera(double scale, double rx, double ry, double rz);
	private: void drawObject(std::vector<Point3> vertices, std::vector<std::pair<int, int>> edges);
	private: void drawAxis();
	private: void drawPerspectivePoint();
	private: void drawPerspectiveLines();
	private: System::Void trackBar_tX_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_tY_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_tZ_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_rX_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_rY_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_rZ_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_sX_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_sY_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_sZ_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_cscale_Scroll(System::Object^ sender, System::EventArgs^ e);	
	private: System::Void trackBar_rcx_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_rcy_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_rcz_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_crefresh_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox_anim_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton_oyz_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton_oxz_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton_oxy_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_perspZ_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
};
}
