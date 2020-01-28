#include "DxLib.h" 
//#include "main.h"

const char TITLE[] = "K019G1062 ��@�D��";//�E�B���h�E�^�C�g���̕�����
const int WIN_HEIGHT = 600;//�E�B���h�E���T�C�Y�p�萔
const int WIN_WITDH = 800; //�E�B���h�E�c�T�C�Y�p�萔



//���\�b�h�֘A
int key[256]; // 0:���͂���Ă��Ȃ� 1:���͂��ꂽ�u�� 2:���͂���Ă���
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
	//�E�B���h�E���[�h�ɐݒ� 
	ChangeWindowMode(TRUE);
	//�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A 
	//���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ��� 
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//�^�C�g����ύX
	SetMainWindowText(TITLE);
	//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�i���j�^�[�̉𑜓x�ɍ��킹��j
	SetGraphMode(WIN_WITDH, WIN_HEIGHT, 32);
	//��ʃT�C�Y��ݒ�i�𑜓x�Ƃ̔䗦�Őݒ�j
	SetWindowSizeExtendRate(1.0);
	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0, 0, 0);


	//Dx���C�u������������ 
	if (DxLib_Init() == -1)
	{
		//�G���[���o����}�C�i�X�l��Ԃ��ďI�� 
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








	//�������[�v�����
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


	//�����������܂őҋ@ 
	//WaitKey();

	//Dx���C�u�����I������ 
	DxLib::DxLib_End();

	return 0;










}