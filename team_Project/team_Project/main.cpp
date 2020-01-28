#include "DxLib.h" 
//#include "main.h"

const char TITLE[] = "K019G1062 矢嶋　優多";//ウィンドウタイトルの文字列
const int WIN_HEIGHT = 600;//ウィンドウ横サイズ用定数
const int WIN_WITDH = 800; //ウィンドウ縦サイズ用定数



//メソッド関連
int key[256]; // 0:入力されていない 1:入力された瞬間 2:入力されている
void inputKey() {
	static char buf[256];
	GetHitKeyStateAll(buf);
	for (int i = 0; i < 256; i++)
	{
		if (buf[i])
		{
			if (key[i] == 0) key[i] = 1;
			else if (key[i] == 1) key[i] = 2;
		}
		else key[i] = 0;
	}
}

int WINAPI WinMain
(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	//ウィンドウモードに設定 
	ChangeWindowMode(TRUE);
	//ウィンドウサイズを手動では変更できず、 
	//かつウィンドウサイズに合わせて拡大できないようにする 
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//タイトルを変更
	SetMainWindowText(TITLE);
	//画面サイズの最大サイズ、カラービット数を設定（モニターの解像度に合わせる）
	SetGraphMode(WIN_WITDH, WIN_HEIGHT, 32);
	//画面サイズを設定（解像度との比率で設定）
	SetWindowSizeExtendRate(1.0);
	// 画面の背景色を設定する
	SetBackgroundColor(0, 0, 0);


	//Dxライブラリを初期化 
	if (DxLib_Init() == -1)
	{
		//エラーが出たらマイナス値を返して終了 
		return -1;
	}


	int texture;

	texture = LoadGraph("ascii_font.png");

	int positionX;
	int positionY;

	positionX = 0;
	positionY = 0;

	int CheckSpace;
	CheckSpace = 0;

	int keys[256];








	//無限ループを作る
	while (true)
	{
		ClearDrawScreen();






		if (CheckHitKey(KEY_INPUT_UP) == 1)
		{
			positionY--;
		}

		if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		{
			positionY++;
		}

		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			positionX++;
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			positionX--;
		}



		//if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			inputKey();
			if (key[KEY_INPUT_SPACE] == 1 && CheckSpace == 0)
			{

				CheckSpace = 1;
			}
			else if (key[KEY_INPUT_SPACE] == 1 && CheckSpace == 1)
			{
				SetDrawScreen(DX_SCREEN_FRONT);

				CheckSpace = 0;
			}

		}

		if (CheckSpace == 0)
		{
			//SetDrawScreen(DX_SCREEN_FRONT);
			DrawGraph(positionX, positionY, texture, true);
			DrawFormatString(100, 100, GetColor(255, 255, 255), "checkSpace %d", CheckSpace);

		}

		if (CheckSpace == 1)
		{
			SetDrawScreen(DX_SCREEN_BACK);

			DrawGraph(positionX, positionY, texture, true);
			DrawFormatString(100, 100, GetColor(255, 255, 255), "checkSpace %d", CheckSpace);


			ScreenFlip();

		}



		DrawFormatString(100, 100, GetColor(255, 255, 255), "checkSpace %d", CheckSpace);








		WaitTimer(20);



		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

	}
	int DeleteGraph(texture);


	//何か押されるまで待機 
	//WaitKey();

	//Dxライブラリ終了処理 
	DxLib::DxLib_End();

	return 0;










}