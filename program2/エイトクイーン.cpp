#include "DxLib.h"
#include <stdio.h>

int i, j, k;				//���[�v�p�̓Y��
int tate, yoko;				//�擾�����摜�̍��W����ɂ����񎟌��z��̓Y����
char chai[8][8] = { 0 };	//�N���b�N���ꂽ�ꏊ���P�ɂȂ�W�~�W�̔z��
char hei[8] = { 0 };		//�c��@����p�z��
char wid[8] = { 0 };		//����@����p�z��
char skip = 0;


/* �֐����FStart-----------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F�Q�[���J�n�̃X�^�[�g���----------------------------------------------------------------------------------------------*/
void Start() {
	DrawBox(0, 0, 650, 500, GetColor(255, 245, 245), true);

	//�I���{�^���̍쐬
	/*DrawBox(190, 300, 440, 370, GetColor(218, 165, 32), true);*/		//�X�^�[�g�{�^���N���b�N�Ώ۔͈�
	DrawFormatString(75, 90, GetColor(0, 0, 0), "W e l c o m e");
	SetFontSize(45);
	DrawFormatString(120, 170, GetColor(0, 0, 0), "[Eight queens]");
	SetFontSize(25);
	DrawFormatString(240, 320, GetColor(0, 0, 0), "GAME START");
	

}

/* �֐����FSurface---------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F�x�[�X�ƂȂ��ʂ̍쐬------------------------------------------------------------------------------------------------*/
void Surface() {
	DrawBox(0, 0, 650, 500, GetColor(0, 0, 0), true);
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {		//���F
			DrawBox(120 + (100 * i), 40 + 100 * j, 170 + (100 * i), 90 + 100 * j, GetColor(255, 255, 255), true);
		}
		for (i = 0; i < 4; i++) {		//�D�F	
			DrawBox(170 + (100 * i), 40 + 100 * j, 220 + (100 * i), 90 + 100 * j, GetColor(102, 102, 102), true);
		}
	}
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {		//���F
			DrawBox(120 + (100 * i), 90 + 100 * j, 170 + (100 * i), 140 + 100 * j, GetColor(102, 102, 102), true);
		}
		for (i = 0; i < 4; i++) {		//�D�F	
			DrawBox(170 + (100 * i), 90 + 100 * j, 220 + (100 * i), 140 + 100 * j, GetColor(255, 255, 255), true);
		}
	}

	//�I���{�^���̍쐬
	DrawBox(10, 5, 110, 55, GetColor(205, 133, 63), true);
	DrawFormatString(30, 15, GetColor(0, 0, 0), "�I��");

	//���Z�b�g�{�^���̍쐬
	DrawBox(530, 5, 630, 55, GetColor(205, 133, 63), true);
	DrawFormatString(527, 15, GetColor(0, 0, 0), "���Z�b�g");

	//�c��I��
	SetFontSize(22);
	DrawBox(0, 150, 100, 200, GetColor(0, 0, 0), true);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "�c��I��");
	SetFontSize(26);
	DrawFormatString(50, 150, GetColor(255, 255, 255), "8");
}


/* �֐����FClick-----------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F�N���b�N���ꂽ�ꏊ�̓Y��������ɔz��̓Y�������쐬--------------------------------------------------------------------*/
/*         x����y���̊ۂ������ꂽ�i�N���b�N���ꂽ�j�ꏊ�̔z����v���X�P����------------------------------------------------------*/
void Click(int a, int b) {
	tate = (b + 10) / 50 - 1;
	yoko = (a - 70) / 50 - 1;

	chai[tate][yoko] = 1;		//�z��̓��e��ύX
	hei[tate] = 1;
	wid[yoko] = 1;
}


/* �֐����FMaru------------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F�N���b�N���ꂽ�ꏊ�̓Y��������ɉ摜��`��------------------------------------------------------------------------------*/
void Maru() {
	int Queen = LoadGraph("�N�C�[��.png");
	DrawRotaGraph(145 + (yoko * 50), 65 + (tate * 50) , 1.0, 0.0, Queen, true);

	/*DrawCircle(145 + (yoko * 50), 65 + (tate * 50), 20, GetColor(0, 0, 0), 1);*/
}


/* �֐���Check-------------------------------------------------------------------------------------------------------------------*/
/* ���@�e�Fcnt�i�����l8�j����Achai�̒��ɂP�������邽�т�cnt -1�@������--------------------------------------------------------*/
int Check() {
	int cnt = 8;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (chai[i][j] == 1) {
				cnt -= 1;
			}
		}
	}


	return(cnt);
}



/* �֐����FReset-----------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F���ׂĂ̔z����O��������----------------------------------------------------------------------------------------------*/
void Reset() {
	for (i = 0; i < 8; i++) {
		hei[i] = 0;
		wid[i] = 0;
		for (j = 0; j < 8; j++) {
			chai[i][j] = 0;
		}
	}
}



/* �֐����FResidue---------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F�c��I���\����\��--------------------------------------------------------------------------------------------------*/
void Residue(int a) {
	DrawBox(0, 150, 100, 200, GetColor(0, 0, 0), true);
	DrawFormatString(50, 150, GetColor(255, 255, 255), "%d", a);
	
}


/* �֐����FResult----------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F�c��I�𐔂��O�ɂȂ����ꍇ�Ƀ��U���g��ʂ�\��------------------------------------------------------------------------*/
void Result(int a) {
	/*DrawBox(0, 0, 650, 500, GetColor(0, 0, 0), true); */

	DrawBox(0, 100, 120, 200, GetColor(0, 0, 0), true);
	SetFontSize(33);
	SetFontThickness(1);                         //������1�ɕύX
	ChangeFont("HGS�n�p�p�߯�ߑ�");              //HGS�n�p�p�߯�ߑ̂ɕύX


	DrawBox(530, 5, 630, 55, GetColor(0, 0, 0), true);
	DrawBox(10, 5, 110, 55, GetColor(0, 0, 0), true);
	DrawBox(530, 200, 630, 250, GetColor(0, 0, 0), true);

	if (a == 0) {
		DrawFormatString(70, 150, GetColor(255, 0, 42), "���s...������x�`�������W���悤�I");
	}
	else if (a == 1) {
		DrawFormatString(15, 150, GetColor(255, 0, 42), "�听���I�I�Ⴄ�p�^�[�����l���Ă݂悤�I");
	}
	else {
		DrawFormatString(100, 200, GetColor(255, 255, 255), "�G���[");
	}

	SetFontSize(26);

	DrawBox(150, 260, 300, 350, GetColor(218, 165, 32), true);
	DrawFormatString(173, 280, GetColor(0, 0, 0), "������x");
	DrawFormatString(200, 310, GetColor(0, 0, 0), "�V��");
	DrawBox(330, 260, 480, 350, GetColor(218, 165, 32), true);
	DrawFormatString(365, 290, GetColor(0, 0, 0), "�I�@��");
}


/* �֐����Fjudgement-------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F�c�����ƁA�������̂P�̐��������W�Ȃ�u�P�v�A����ȊO�́u�O�v��Ԃ�----------------------------------------------------*/
char Judgement() {
	char heicnt = 0;
	char widcnt = 0;
	char judge = 0;
	//����������
	for (i = 0; i < 8; i++) {
		if (hei[i] == 1) {
			heicnt += 1;
		}
	}
	//�c��������
	for (i = 0; i < 8; i++) {
		if (wid[i] == 1) {
			widcnt += 1;
		}
	}

	if (heicnt == 8 && widcnt == 8) {
		judge = 1;
	}

	return(judge);

}

char Judgement2() {
	char ncnt[8] = { 0 };
	int x, y;
	int han = 0;
	
	for (i = 0; i < 8; i++) {
		for (x = 0, y = i; x <= i; x++, y--) {
			if (chai[x][y] == 1) {
				ncnt[i] = 1;
			}
		}
	}

	for (i = 0; i < 8; i++) {
		if (ncnt[i] == 1) {
			han++;
		}
	}

	return(han);
}

char Judgement3() {
	char ncnt[8] = { 0 };
	int x, y;
	int han = 0;

	for (i = 1; i < 8; i++) {
		for (x = i, y = 7; x < 8; x++, y--) {
			if (chai[x][y] == 1) {
				ncnt[i] = 1;
			}
		}
	}

	for (i = 0; i < 8; i++) {
		if (ncnt[i] == 1) {
			han++;
		}
	}

	return(han);
}

char Judgement4() {
	char ncnt[8] = { 0 };
	int x, y;
	int han = 0;

	for (i = 7; i >= 0; i--) {
		for (x = 7 - i, y = 0; x < 8; x++, y++) {
			if (chai[x][y] == 1) {
				ncnt[i] = 1;
			}
		}
	}

	for (i = 0; i < 8; i++) {
		if (ncnt[i] == 1) {
			han++;
		}
	}

	return(han);
}

char Judgement5() {
	char ncnt[8] = { 0 };
	int x, y;
	int han = 0;

	for (i = 7; i > 0; i--) {
		for (x = 0, y = 8 - i; x < i; x++, y++) {
			if (chai[x][y] == 1) {
				ncnt[i] = 1;
			}
		}
	}

	for (i = 0; i < 8; i++) {
		if (ncnt[i] == 1) {
			han++;
		}
	}

	return(han);
}


/* �֐����Ffin-------------------------------------------------------------------------------------------------------------------*/
/* ���@�e�F���ʕ\���̃{�^�����쐬------------------------------------------------------------------------------------------------*/
void fin() {
	DrawBox(530, 200, 630, 250, GetColor(173, 255, 47), true);
	SetFontSize(24);
	DrawFormatString(530, 210, GetColor(0, 0, 0), "���ʕ\��");
	SetFontSize(26);
}






// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	int Mouse;		//	�}�E�X�̓��͏��
	int x, y;		//�@�}�E�X�̍��W
	int cnt = 8;
	int judge, judge2, judge3, judge4, judge5;
	int lastjudge = 0;

	int finish = 0;

	ChangeWindowMode(true);
	
	if( DxLib_Init() == -1 )		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}

	SetFontSize(60);
	ChangeFont("Courier New");


	Start();

	while (1) {
		Mouse = GetMouseInput();		//�}�E�X�̓��͏��
		if (Mouse & MOUSE_INPUT_LEFT) {
			GetMousePoint(&x, &y);		//�}�E�X�̈ʒu���擾


			if (skip == 0 && x >= 190 && x <= 440 && y >= 300 && y <= 370) {		//�����ʂ̏I���{�^���������ꂽ��I��
				skip = 1;
				WaitTimer(1000);
				SetFontSize(26);
				ChangeFont("HGS�n�p�p�߯�ߑ�");
				Surface();
			}

			//�D�F�Ɣ��̔Ֆʂ̒����N���b�N���ꂽ��
			if (cnt > 0 && skip >= 1 && x >= 120 && x <= 520 && y >= 40 && y <= 440) {
				if (skip == 1) {
					skip = 2;
				}
				else {
					Click(x, y);		//���W����Y������
					Maru();				//�ۂ�`��
					cnt = Check();		//�����J�E���g����Ă��邩���ׂ�cnt�ɑ��
					Residue(cnt);		//�c��I�𐔂�\��
				}

				if (cnt == 0){
					fin();
				}

			
			}


			//���ʕ\����ʂ������ꂽ��
			if (cnt == 0 && x >= 530 && x <= 630 && y >= 200 && y <= 250) {
				finish = 1;
				judge = Judgement();		//�c���̔���
				judge2 = Judgement2();
				judge3 = Judgement3();
				judge4 = Judgement4();
				judge5 = Judgement5();

				if (judge == 1 && (judge2 + judge3) == 8 && (judge4 + judge5) == 8) {
					lastjudge = 1;
				}
				WaitTimer(1000);

				Result(lastjudge);				//�c������̌��ʂ���Ƀ��U���g���

			}



			if (finish == 1 && x >= 150 && x <= 300 && y >= 260 && y <= 350) {		//�����ʂ̏I������x�{�^���������ꂽ��I��
				Surface();
				Reset();
				lastjudge = 0;
				finish = 0;
				cnt = 8;
				WaitTimer(1000);
			}

			if (finish == 1 && x >= 330 && x <= 480 && y >= 260 && y <= 350) {		//�����ʂ̏I���{�^���������ꂽ��I��
				break;
			}

			//���Z�b�g�{�^���������ꂽ��
			if (x >= 530 && x <= 630 && y >= 5 && y <= 55) {
				Surface();		//�V���ȔՖʂ��쐬
				Reset();		//�z��̃��Z�b�g
				
				lastjudge = 0;
				finish = 0;
				cnt = 8;
			}


			//�I���{�^���������ꂽ��
			if (x >= 10 && x <= 110 && y >= 0 && y <= 50) {
					break;			//���[�v�𔲂��ďI��
			}
		}
	}

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;				// �\�t�g�̏I�� 
}