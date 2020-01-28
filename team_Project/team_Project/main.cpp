#include "DxLib.h"

int main()
{

	const char TITLE[] = "01_step";

	const int WinHeight = 400;
	const int WinWidth = 600;

	//�E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y���蓮�ŕύX�ł����A
	//���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//�^�C�g����\��
	SetMainWindowText(TITLE);

	//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�
	SetGraphMode(WinWidth, WinHeight, 32);

	//��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	//��ʂ̔w�i�F��ݒ�
	SetBackgroundColor(0xEF, 0xFF, 0xEF);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�G���[���o����}�C�i�X�l��Ԃ��ďI��
		return -1;
	}

	//�i�v���[�v�𔲂��鏈��
	while (1)//�ȒP�ȃ��[�v����
	{

		int a = 5;

		int b = 10;

		WaitTimer(20);//20�~���b
		if (ProcessMessage() == -1) break;//WindowsAPI�̃G���[����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;//DxLib�̓��͏���
	}

	//�����������܂őҋ@
	WaitKey();

	//Dx���C�u�����I������
	DxLib_End();


}