#include "DxLib.h"
#include <stdio.h>

int i, j, k;				//ループ用の添字
int tate, yoko;				//取得した画像の座標を基にした二次元配列の添え字
char chai[8][8] = { 0 };	//クリックされた場所が１になる８×８の配列
char hei[8] = { 0 };		//縦列　判定用配列
char wid[8] = { 0 };		//横列　判定用配列
char skip = 0;


/* 関数名：Start-----------------------------------------------------------------------------------------------------------------*/
/* 内　容：ゲーム開始のスタート画面----------------------------------------------------------------------------------------------*/
void Start() {
	DrawBox(0, 0, 650, 500, GetColor(255, 245, 245), true);

	//終了ボタンの作成
	/*DrawBox(190, 300, 440, 370, GetColor(218, 165, 32), true);*/		//スタートボタンクリック対象範囲
	DrawFormatString(75, 90, GetColor(0, 0, 0), "W e l c o m e");
	SetFontSize(45);
	DrawFormatString(120, 170, GetColor(0, 0, 0), "[Eight queens]");
	SetFontSize(25);
	DrawFormatString(240, 320, GetColor(0, 0, 0), "GAME START");
	

}

/* 関数名：Surface---------------------------------------------------------------------------------------------------------------*/
/* 内　容：ベースとなる画面の作成------------------------------------------------------------------------------------------------*/
void Surface() {
	DrawBox(0, 0, 650, 500, GetColor(0, 0, 0), true);
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {		//白色
			DrawBox(120 + (100 * i), 40 + 100 * j, 170 + (100 * i), 90 + 100 * j, GetColor(255, 255, 255), true);
		}
		for (i = 0; i < 4; i++) {		//灰色	
			DrawBox(170 + (100 * i), 40 + 100 * j, 220 + (100 * i), 90 + 100 * j, GetColor(102, 102, 102), true);
		}
	}
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {		//白色
			DrawBox(120 + (100 * i), 90 + 100 * j, 170 + (100 * i), 140 + 100 * j, GetColor(102, 102, 102), true);
		}
		for (i = 0; i < 4; i++) {		//灰色	
			DrawBox(170 + (100 * i), 90 + 100 * j, 220 + (100 * i), 140 + 100 * j, GetColor(255, 255, 255), true);
		}
	}

	//終了ボタンの作成
	DrawBox(10, 5, 110, 55, GetColor(205, 133, 63), true);
	DrawFormatString(30, 15, GetColor(0, 0, 0), "終了");

	//リセットボタンの作成
	DrawBox(530, 5, 630, 55, GetColor(205, 133, 63), true);
	DrawFormatString(527, 15, GetColor(0, 0, 0), "リセット");

	//残り選択数
	SetFontSize(22);
	DrawBox(0, 150, 100, 200, GetColor(0, 0, 0), true);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "残り選択数");
	SetFontSize(26);
	DrawFormatString(50, 150, GetColor(255, 255, 255), "8");
}


/* 関数名：Click-----------------------------------------------------------------------------------------------------------------*/
/* 内　容：クリックされた場所の添え字を基に配列の添え字を作成--------------------------------------------------------------------*/
/*         x軸とy軸の丸が書かれた（クリックされた）場所の配列をプラス１する------------------------------------------------------*/
void Click(int a, int b) {
	tate = (b + 10) / 50 - 1;
	yoko = (a - 70) / 50 - 1;

	chai[tate][yoko] = 1;		//配列の内容を変更
	hei[tate] = 1;
	wid[yoko] = 1;
}


/* 関数名：Maru------------------------------------------------------------------------------------------------------------------*/
/* 内　容：クリックされた場所の添え字を基に画像を描画------------------------------------------------------------------------------*/
void Maru() {
	int Queen = LoadGraph("クイーン.png");
	DrawRotaGraph(145 + (yoko * 50), 65 + (tate * 50) , 1.0, 0.0, Queen, true);

	/*DrawCircle(145 + (yoko * 50), 65 + (tate * 50), 20, GetColor(0, 0, 0), 1);*/
}


/* 関数名Check-------------------------------------------------------------------------------------------------------------------*/
/* 内　容：cnt（初期値8）から、chaiの中に１を見つけるたびにcnt -1　をする--------------------------------------------------------*/
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



/* 関数名：Reset-----------------------------------------------------------------------------------------------------------------*/
/* 内　容：すべての配列を０処理する----------------------------------------------------------------------------------------------*/
void Reset() {
	for (i = 0; i < 8; i++) {
		hei[i] = 0;
		wid[i] = 0;
		for (j = 0; j < 8; j++) {
			chai[i][j] = 0;
		}
	}
}



/* 関数名：Residue---------------------------------------------------------------------------------------------------------------*/
/* 内　容：残り選択可能数を表示--------------------------------------------------------------------------------------------------*/
void Residue(int a) {
	DrawBox(0, 150, 100, 200, GetColor(0, 0, 0), true);
	DrawFormatString(50, 150, GetColor(255, 255, 255), "%d", a);
	
}


/* 関数名：Result----------------------------------------------------------------------------------------------------------------*/
/* 内　容：残り選択数が０になった場合にリザルト画面を表示------------------------------------------------------------------------*/
void Result(int a) {
	/*DrawBox(0, 0, 650, 500, GetColor(0, 0, 0), true); */

	DrawBox(0, 100, 120, 200, GetColor(0, 0, 0), true);
	SetFontSize(33);
	SetFontThickness(1);                         //太さを1に変更
	ChangeFont("HGS創英角ﾎﾟｯﾌﾟ体");              //HGS創英角ﾎﾟｯﾌﾟ体に変更


	DrawBox(530, 5, 630, 55, GetColor(0, 0, 0), true);
	DrawBox(10, 5, 110, 55, GetColor(0, 0, 0), true);
	DrawBox(530, 200, 630, 250, GetColor(0, 0, 0), true);

	if (a == 0) {
		DrawFormatString(70, 150, GetColor(255, 0, 42), "失敗...もう一度チャレンジしよう！");
	}
	else if (a == 1) {
		DrawFormatString(15, 150, GetColor(255, 0, 42), "大成功！！違うパターンも考えてみよう！");
	}
	else {
		DrawFormatString(100, 200, GetColor(255, 255, 255), "エラー");
	}

	SetFontSize(26);

	DrawBox(150, 260, 300, 350, GetColor(218, 165, 32), true);
	DrawFormatString(173, 280, GetColor(0, 0, 0), "もう一度");
	DrawFormatString(200, 310, GetColor(0, 0, 0), "遊ぶ");
	DrawBox(330, 260, 480, 350, GetColor(218, 165, 32), true);
	DrawFormatString(365, 290, GetColor(0, 0, 0), "終　了");
}


/* 関数名：judgement-------------------------------------------------------------------------------------------------------------*/
/* 内　容：縦方向と、横方向の１の数が両方８なら「１」、それ以外は「０」を返す----------------------------------------------------*/
char Judgement() {
	char heicnt = 0;
	char widcnt = 0;
	char judge = 0;
	//横方向判定
	for (i = 0; i < 8; i++) {
		if (hei[i] == 1) {
			heicnt += 1;
		}
	}
	//縦方向判定
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


/* 関数名：fin-------------------------------------------------------------------------------------------------------------------*/
/* 内　容：結果表示のボタンを作成------------------------------------------------------------------------------------------------*/
void fin() {
	DrawBox(530, 200, 630, 250, GetColor(173, 255, 47), true);
	SetFontSize(24);
	DrawFormatString(530, 210, GetColor(0, 0, 0), "結果表示");
	SetFontSize(26);
}






// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	int Mouse;		//	マウスの入力状態
	int x, y;		//　マウスの座標
	int cnt = 8;
	int judge, judge2, judge3, judge4, judge5;
	int lastjudge = 0;

	int finish = 0;

	ChangeWindowMode(true);
	
	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}

	SetFontSize(60);
	ChangeFont("Courier New");


	Start();

	while (1) {
		Mouse = GetMouseInput();		//マウスの入力状態
		if (Mouse & MOUSE_INPUT_LEFT) {
			GetMousePoint(&x, &y);		//マウスの位置を取得


			if (skip == 0 && x >= 190 && x <= 440 && y >= 300 && y <= 370) {		//判定画面の終了ボタンが押されたら終了
				skip = 1;
				WaitTimer(1000);
				SetFontSize(26);
				ChangeFont("HGS創英角ﾎﾟｯﾌﾟ体");
				Surface();
			}

			//灰色と白の盤面の中がクリックされたら
			if (cnt > 0 && skip >= 1 && x >= 120 && x <= 520 && y >= 40 && y <= 440) {
				if (skip == 1) {
					skip = 2;
				}
				else {
					Click(x, y);		//座標から添え字へ
					Maru();				//丸を描画
					cnt = Check();		//今何個カウントされているか調べてcntに代入
					Residue(cnt);		//残り選択数を表示
				}

				if (cnt == 0){
					fin();
				}

			
			}


			//結果表示画面が押されたら
			if (cnt == 0 && x >= 530 && x <= 630 && y >= 200 && y <= 250) {
				finish = 1;
				judge = Judgement();		//縦横の判定
				judge2 = Judgement2();
				judge3 = Judgement3();
				judge4 = Judgement4();
				judge5 = Judgement5();

				if (judge == 1 && (judge2 + judge3) == 8 && (judge4 + judge5) == 8) {
					lastjudge = 1;
				}
				WaitTimer(1000);

				Result(lastjudge);				//縦横判定の結果を基にリザルト画面

			}



			if (finish == 1 && x >= 150 && x <= 300 && y >= 260 && y <= 350) {		//判定画面の終もう一度ボタンが押されたら終了
				Surface();
				Reset();
				lastjudge = 0;
				finish = 0;
				cnt = 8;
				WaitTimer(1000);
			}

			if (finish == 1 && x >= 330 && x <= 480 && y >= 260 && y <= 350) {		//判定画面の終了ボタンが押されたら終了
				break;
			}

			//リセットボタンが押されたら
			if (x >= 530 && x <= 630 && y >= 5 && y <= 55) {
				Surface();		//新たな盤面を作成
				Reset();		//配列のリセット
				
				lastjudge = 0;
				finish = 0;
				cnt = 8;
			}


			//終了ボタンを押されたら
			if (x >= 10 && x <= 110 && y >= 0 && y <= 50) {
					break;			//ループを抜けて終了
			}
		}
	}

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;				// ソフトの終了 
}