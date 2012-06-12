using System;
using System.Drawing;
using System.Windows.Forms;
using System.IO;

namespace FullScreen
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // SWFを読み込む
            // http://memo.sappari.org/flash-in-csharp
            // 読み込むswfパスの初期値。実行ファイル(exe)と同階層のEmbedFlash.swfを指定。
            String swfPath = Directory.GetCurrentDirectory() + Path.DirectorySeparatorChar + "EmbedFlash.swf";

            // 実行ファイルにswfをドロップした場合はそのパスに上書き
            // 実行ファイルにドロップされたファイルのパスを取得する
            // http://dobon.net/vb/dotnet/programing/dropfiletoexe.html
            string[] cmds = System.Environment.GetCommandLineArgs();

            if (cmds.Length > 1)
            {
                //ドロップされたファイルのパスをすべて表示
                for (int i = 1; i < cmds.Length; i++)
                {
                    // Console.WriteLine(cmds[i]);
                    swfPath = cmds[i];
                }
            }

            // モニタサイズの取得。マルチモニタの場合にも対応できるように値を比較
            // モニタサイズ保持用の構造体を生成
            Rectangle screenRectangle = new Rectangle(0, 0, 0, 0);

            // ディスプレイの解像度を取得するには？
            // http://www.atmarkit.co.jp/fdotnet/dotnettips/003screen/screen.html
            foreach (Screen s in Screen.AllScreens)
            {
                //Console.WriteLine(s.Bounds);
                screenRectangle.X = Math.Min(screenRectangle.X, s.Bounds.X);
                screenRectangle.Y = Math.Min(screenRectangle.Y, s.Bounds.Y);

                screenRectangle.Width = Math.Max(screenRectangle.Width, s.Bounds.Right);
                screenRectangle.Height = Math.Max(screenRectangle.Height, s.Bounds.Bottom);
            }
            //Console.WriteLine(screenRectangle);

            // Windowsアプリケーションをフルスクリーンで表示するには？
            // http://www.atmarkit.co.jp/fdotnet/dotnettips/199fullscreen/fullscreen.html
            // 1. フォームの境界線スタイルを「None」にする
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;

            // ウィンドウとswfを配置するエリアの位置やサイズを指定
            axShockwaveFlash1.Top = 0;
            axShockwaveFlash1.Left = 0;
            this.Top = screenRectangle.Top;
            this.Left = screenRectangle.Left;
            this.Width = axShockwaveFlash1.Width = screenRectangle.Width - screenRectangle.X;
            this.Height = axShockwaveFlash1.Height = screenRectangle.Height - screenRectangle.Y;

            // wmodeの指定
            axShockwaveFlash1.WMode = "Direct";

            // swfのロード
            axShockwaveFlash1.LoadMovie(0, swfPath);

            // マウス・カーソルを非表示にするには？
            // http://www.atmarkit.co.jp/fdotnet/dotnettips/390cursorhide/cursorhide.html
            //Cursor.Hide();
        }
    }
}
