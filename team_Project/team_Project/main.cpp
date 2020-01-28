#include "DxLib.h"

int WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)

{
	const char TITLE[] = "01_step";

	const int WinHeight = 400;
	const int WinWidth = 600;

	//ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	//ウィンドウサイズを手動で変更できず、
	//かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//タイトルを表示
	SetMainWindowText(TITLE);

	//画面サイズの最大サイズ、カラービット数を設定
	SetGraphMode(WinWidth, WinHeight, 32);

	//画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	//画面の背景色を設定
	SetBackgroundColor(0xEF, 0xFF, 0xEF);

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		//エラーが出たらマイナス値を返して終了
		return -1;
	}

	//永久ループを抜ける処理
	while (1)//簡単なループ処理
	{



		WaitTimer(20);//20ミリ秒
		if (ProcessMessage() == -1) break;//WindowsAPIのエラー処理
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;//DxLibの入力処理
	}

	//何か押されるまで待機
	WaitKey();

	//Dxライブラリ終了処理
	DxLib_End();

	return 0;
}