#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <Windows.h>

#define MAXSIZE 340
#define SIZE 20

const COLORREF cowcolor[] = {
	RGB(213,116,48),RGB(224,130,68),RGB(232,232,232),RGB(244,158,107),
	RGB(255,255,255),RGB(230,128,2),RGB(252,248,213),RGB(170,179,160),
	RGB(255,87,87),RGB(249,155,94),RGB(163,63,13),RGB(243,149,98),
	RGB(17,182,103)
};

#define SKIN1 cowcolor[0]
#define SKIN2 cowcolor[1]
#define HAND cowcolor[2]
#define HORN cowcolor[3]
#define EYE cowcolor[4]
#define BEER cowcolor[5]
#define FOAM cowcolor[6]
#define CUP cowcolor[7]
#define MOUTH cowcolor[8]
#define NOSE1 cowcolor[9]
#define NOSE2 cowcolor[10]
#define EAR cowcolor[11]
#define COOLAPK cowcolor[12]

int msperframe = 250;

void p(void)
{
	if (msperframe > 0)
		Sleep(msperframe);
}

void SetColor(COLORREF fill, COLORREF back)
{
	setfillcolor(fill);
	setbkcolor(back);
}

void Pol(POINT pointset[], int count, COLORREF fill)
{
	SetColor(fill, fill);
	fillpolygon(pointset, count);
	p();
}

void DrawNiupi(void)
{
	int i = 0;
	HWND hwnd = initgraph(MAXSIZE, MAXSIZE + 20, 0);		//绘图窗口
	POINT tri1[] = { {140,180},{80,180},{110,200} };
	POINT tri2[] = { {95,190},{110,200},{125,190} };
	POINT tri3[] = { {100,20},{100,60},{80,60} };
	POINT tri4[] = { {160,20},{160,60},{180,60} };
	POINT pol1[] = { {80,180},{110,200},{140,180},{160,180},{160,140},
	{180,120},{220,200},{210,220},{200,200},{200,300},{120,300} };
	POINT pol2[] = { {180,120},{180,70},{320,140},{320,320},{260,320},{260,300} };
	POINT pol3[] = { {160,140},{180,120},{180,70},{200,70},{200,50},{180,50},{130,40},
	{80,50},{60,50},{60,70},{80,70},{80,120},{60,140} };
	POINT pol4[] = { {200,200},{210,220},{220,200},{230,220},{240,200},{250,220},
	{260,200},{260,240},{200,240} };
	setbkcolor(WHITE);
	settextcolor(BLACK);
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 12;                      // 设置字体高度为
	f.lfQuality = 4;					// 设置输出效果为抗锯齿  
	settextstyle(&f);
	cleardevice();
	setlinecolor(BLACK);
	for (i = 0; i <= 12; i++)
	{
		SetColor(cowcolor[i], cowcolor[i]);
		fillrectangle(i * SIZE, 340, 20 + i * SIZE, 360);
	}

	p();
	Pol(pol1, 11, SKIN2);
	setlinecolor(BLACK);
	Pol(tri1, 3, BLACK);
	Pol(tri2, 3, MOUTH);
	setlinecolor(SKIN1);
	Pol(pol2, 6, SKIN1);
	setlinecolor(BLACK);

	
	SetColor(HAND, HAND);
	fillrectangle(50, 240, 70, 320);
	p();
	fillrectangle(20, 260, 60, 320);
	p();
	line(40, 280, 60, 280);
	p();
	line(40, 300, 60, 300);
	p();

	SetColor(SKIN1, SKIN1);
	fillrectangle(70, 300, 200, 320);
	p();
	setlinecolor(SKIN1);
	line(120, 300, 200, 300);
	setlinecolor(BLACK);
	p();

	setlinecolor(NOSE2);
	SetColor(NOSE1, NOSE1);
	fillrectangle(60, 140, 160, 180);
	p();

	SetColor(NOSE2, NOSE2);
	fillrectangle(80, 150, 100, 160);
	p();
	fillrectangle(120, 150, 140, 160);
	p();

	setlinecolor(BLACK);
	Pol(tri3, 3, EAR);
	Pol(tri4, 3, EAR);
	Pol(pol3, 13, SKIN1);

	setlinecolor(CUP);
	Pol(pol4, 9, FOAM);
	setfillcolor(BEER);
	fillrectangle(200, 225, 260, 310);
	p();

	SetColor(HAND, HAND);
	setlinecolor(BLACK);
	fillrectangle(260, 220, 280, 260);
	p();
	fillrectangle(260, 240, 300, 300);
	p();
	line(260, 260, 280, 260);
	p();
	line(260, 280, 280, 280);
	p();

	setlinecolor(CUP);
	setfillcolor(CUP);
	fillrectangle(200, 310, 260, 320);
	p();

	setlinecolor(BLACK);
	setfillcolor(EYE);
	fillrectangle(100, 80, 120, 100);
	p();
	fillrectangle(140, 80, 160, 100);
	p();
	setfillcolor(BLACK);
	fillrectangle(107, 87, 113, 93);
	p();
	fillrectangle(147, 87, 153, 93);
	p();

	setlinecolor(SKIN1);
	line(180, 70, 180, 120);
	p();
	line(180, 120, 160, 140);
	p();
	outtextxy(5, 5, _T("CoolApk Niupi"));
	setfillcolor(COOLAPK);
	setlinecolor(COOLAPK);
	fillcircle(290, 50, 30);

	setlinecolor(WHITE);
	circle(280, 50, 10);
	setlinecolor(COOLAPK);
	fillrectangle(289, 40, 300, 60);
	setlinecolor(WHITE);
	
	line(288, 54, 300, 40);
	line(300, 40, 306, 60);
	line(306, 60, 296, 50);

	system("pause");
	
}

int main(void)
{
	printf("请输入每帧毫秒数(<=0:直接播放):");
	scanf("%d", &msperframe);
	DrawNiupi();
	return 0;
}