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
	/// Form1 の概要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//

			// ◆フォームの境界（ウィンドウの枠）を消す
			// 1. フォームの境界線スタイルを「None」にする
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

			// ◆モニタサイズを取得（複数の場合も対応）
			// モニタサイズ保持用の構造体を生成
			System::Drawing::Rectangle screenRectangle = System::Drawing::Rectangle(0,0,0,0);

			// ディスプレイの解像度を取得する
			for each(Screen^ s in Screen::AllScreens){
				screenRectangle.X = Math::Min(screenRectangle.X, s->Bounds.X);
				screenRectangle.Y = Math::Min(screenRectangle.Y, s->Bounds.Y);
				screenRectangle.Width = Math::Max(screenRectangle.Width, s->Bounds.Right);
				screenRectangle.Height = Math::Max(screenRectangle.Height, s->Bounds.Bottom);
			}

			// ウィンドウとswfを配置するエリアの位置やサイズを指定
			axShockwaveFlash1->Top = 0;
			axShockwaveFlash1->Left = 0;
			axShockwaveFlash1->Width = screenRectangle.Width - screenRectangle.X;
			axShockwaveFlash1->Height = screenRectangle.Height - screenRectangle.Y;
			this->Top = screenRectangle.Top;
			this->Left = screenRectangle.Left;
			this->Width = axShockwaveFlash1->Width;
			this->Height = axShockwaveFlash1->Height;

			// ◆SWFを読み込む
			TCHAR currentPath[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, currentPath);
			String^ swfPath = gcnew String(currentPath);
			swfPath += "\\EmbedFlash.swf";

			// 実行ファイルにswfをドロップした場合はそのパスに上書き
			// 実行ファイルにドロップされたファイルのパスを取得する
			array<String^>^arguments = Environment::GetCommandLineArgs();

			if(arguments->Length > 1){
				//ドロップされたファイルのパスを取得
				for (int i = 1; i < arguments->Length; i++){
					swfPath = arguments[i];
				}
			}

			// wmodeの指定
			axShockwaveFlash1->WMode = "Direct";

			// swfのロード
			axShockwaveFlash1->LoadMovie(0, swfPath);

			// ◆マウス・カーソルを非表示にする
			// System::Windows::Forms::Cursor::Hide();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
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

