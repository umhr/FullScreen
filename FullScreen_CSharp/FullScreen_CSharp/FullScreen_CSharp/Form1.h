#include <windows.h>

#pragma once

namespace FullScreen_CSharp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 �̊T�v
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//

			// ���t�H�[���̋��E�i�E�B���h�E�̘g�j������
			// 1. �t�H�[���̋��E���X�^�C�����uNone�v�ɂ���
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

			// �����j�^�T�C�Y���擾�i�����̏ꍇ���Ή��j
			// ���j�^�T�C�Y�ێ��p�̍\���̂𐶐�
			System::Drawing::Rectangle screenRectangle = System::Drawing::Rectangle(0,0,0,0);

			// �f�B�X�v���C�̉𑜓x���擾����
			for each(Screen^ s in Screen::AllScreens){
				screenRectangle.X = Math::Min(screenRectangle.X, s->Bounds.X);
				screenRectangle.Y = Math::Min(screenRectangle.Y, s->Bounds.Y);
				screenRectangle.Width = Math::Max(screenRectangle.Width, s->Bounds.Right);
				screenRectangle.Height = Math::Max(screenRectangle.Height, s->Bounds.Bottom);
			}

			// �E�B���h�E��swf��z�u����G���A�̈ʒu��T�C�Y���w��
			axShockwaveFlash1->Top = 0;
			axShockwaveFlash1->Left = 0;
			axShockwaveFlash1->Width = screenRectangle.Width - screenRectangle.X;
			axShockwaveFlash1->Height = screenRectangle.Height - screenRectangle.Y;
			this->Top = screenRectangle.Top;
			this->Left = screenRectangle.Left;
			this->Width = axShockwaveFlash1->Width;
			this->Height = axShockwaveFlash1->Height;

			// ��SWF��ǂݍ���
			TCHAR currentPath[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, currentPath);
			String^ swfPath = gcnew String(currentPath);
			swfPath += "\\EmbedFlash.swf";

			// ���s�t�@�C����swf���h���b�v�����ꍇ�͂��̃p�X�ɏ㏑��
			// ���s�t�@�C���Ƀh���b�v���ꂽ�t�@�C���̃p�X���擾����
			array<String^>^arguments = Environment::GetCommandLineArgs();

			if(arguments->Length > 1){
				//�h���b�v���ꂽ�t�@�C���̃p�X���擾
				for (int i = 1; i < arguments->Length; i++){
					swfPath = arguments[i];
				}
			}

			// wmode�̎w��
			axShockwaveFlash1->WMode = "Direct";

			// swf�̃��[�h
			axShockwaveFlash1->LoadMovie(0, swfPath);

			// ���}�E�X�E�J�[�\�����\���ɂ���
			// System::Windows::Forms::Cursor::Hide();
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: AxShockwaveFlashObjects::AxShockwaveFlash^  axShockwaveFlash1;
	protected: 

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->axShockwaveFlash1 = (gcnew AxShockwaveFlashObjects::AxShockwaveFlash());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->axShockwaveFlash1))->BeginInit();
			this->SuspendLayout();
			// 
			// axShockwaveFlash1
			// 
			this->axShockwaveFlash1->Enabled = true;
			this->axShockwaveFlash1->Location = System::Drawing::Point(13, 13);
			this->axShockwaveFlash1->Name = L"axShockwaveFlash1";
			this->axShockwaveFlash1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^  >(resources->GetObject(L"axShockwaveFlash1.OcxState")));
			this->axShockwaveFlash1->Size = System::Drawing::Size(192, 192);
			this->axShockwaveFlash1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->axShockwaveFlash1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->axShockwaveFlash1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

