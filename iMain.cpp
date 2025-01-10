
#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "winmm.lib")
char nameofuser[100], nameofuserarray[100][100];
int coins[100];
int tempindex;
int numberofname;
void file_read()
{
	FILE *fp;
	fp = fopen("username.txt", "r");
	fscanf(fp, "%d", &numberofname);
	for (int i = 0; i < numberofname; i++)
	{
		fscanf(fp, "%s", nameofuserarray[i]);
		fscanf(fp, "%d", &coins[i]);
	}
	fclose(fp);
}
void file_write()
{
	FILE *fp;
	fp = fopen("username.txt", "w");
	strcpy(nameofuserarray[numberofname], nameofuser);
	tempindex = numberofname;
	numberofname++;
	fprintf(fp, "%d\n", numberofname);
	for (int i = 0; i < numberofname; i++)
	{
		fprintf(fp, "%s ", nameofuserarray[i]);
		fprintf(fp, "%d\n", coins[i]);
	}
	fclose(fp);
}
void file_write_coin()
{
	FILE *fp;
	fp = fopen("username.txt", "w");
	fprintf(fp, "%d\n", numberofname);
	for (int i = 0; i < numberofname; i++)
	{
		fprintf(fp, "%s ", nameofuserarray[i]);
		fprintf(fp, "%d\n", coins[i]);
	}
	fclose(fp);
}
struct user
{
	char nam[100];
	int cons;
	int index;
};
void sort()
{
	int i;
	int numx = numberofname;
	struct user ps[numx];
	for (i = 0; i < numberofname; i++)
	{
		strcpy(ps[i].nam, nameofuserarray[i]);
		ps[i].cons = coins[i];
		ps[i].index = i;
	}
	for (int i = 0; i < numx; i++)
	{
		for (int j = i + 1; j < numx; j++)
		{
			if (ps[i].cons < ps[j].cons)
			{
				int t;
				t = ps[j].cons;
				ps[j].cons = ps[i].cons;
				ps[i].cons = t;
				int x;
				x = ps[j].index;
				ps[j].index = ps[i].index;
				ps[i].index = x;
				char str[100];
				strcpy(str, ps[i].nam);
				strcpy(ps[i].nam, ps[j].nam);
				strcpy(ps[j].nam, str);
			}
		}
	}
	for (i = 0; i < numberofname; i++)
	{
		strcpy(nameofuserarray[i], ps[i].nam);
		coins[i] = ps[i].cons;
	}
	for (i = 0; i < numberofname; i++)
	{
		if (ps[i].index == tempindex)
		{
			tempindex = i;
			break;
		}
	}
	file_write_coin();
	file_read();
}
bool musicON = true;
int play = 1, cross = 0, nameIndex = 0, nameofuserindex = 0;
int x = 0, y = 0, dx = 10, dy = 15, flagg = 1, flag = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0, flag7 = 0, flag8 = 0, flag9 = 0, flag10 = 0, flag11 = 0, flag12 = 0, flag13 = 0, flag14 = 0, flag15 = 0, flag16 = 0;
/*
	function iDraw() is called again and again by the system.

	*/
int a = 255, b = 0, c = 0, score1 = 2, score2 = 5, score3 = 3, coin = 0, a1, a11, a111, a2, a22, a222, b1, b2, c1, c2, d1, d2, e1, e11, e2, e22, f1, f2, g1, g2, h1, h2, i2, i22, i1, i11, j2, j11, k1, k2, l1, l11, l2, l22, m1, m2, n1, n11, n22, n2, o1, o2, o11, o22, p1, p2, q1, q2, r1, r2, r11, r22, r111, r222, s1, s11, s2, s22, t1, t2, u1, u2, v1, v2, w1, w2, x1, x2, y11, y2, z1, z2;
char score1a[5];
char score2a[5];
char score3a[5];
char coina[100];
char ch[5];
int mainpageIndex = 0, Home_Index = 0, GamesettingsIndex = 0, GamesettingsIndexdummy = 1, HelpDeskIndex = 0, Tickgamelevelindex1 = 0, AboutusIndex = 0, Tickgamelevelindex2 = 0, Tickgamelevelindex3 = 0, Tickgameletterindex1 = 0, Tickgameletterindex2 = 0, Tickgameletterindex3 = 0, Tickgameletterindex4 = 0, Tickgameletterindex5 = 0, Game_level_letters_index = 0, leaderboardIndex = 0, congratulations_Index = 0, Failed_Index = 0, congratulations_Index_amateur = 0, Failed_Index_amateur = 0, congratulations_Index_intermediate = 0, Failed_Index_intermediate = 0, Played_Index = 0, character1_index = 0, character2_index = 0, bullet_index = 0, bullet_x_coordinate = 780, bullet_y_coordinate = 424, character11_index = 0, character11_x_coordinate = 12, character11_y_coordinate = 242;
int a_index = 0, b_index = 0, c_index = 0, d_index = 0, e_index = 0, f_index = 0, g_index = 0, h_index = 0, i_index = 0, j_index = 0, k_index = 0, l_index = 0, m_index = 0, n_index = 0, o_index = 0, p_index = 0, q_index = 0, r_index = 0, s_index = 0, t_index = 0, u_index = 0, v_index = 0, w_index = 0, x_index = 0, y_index = 0, z_index = 0;
int a11_index = 0, a111_index = 0, b11_index = 0, c11_index = 0, d11_index = 0, e11_index = 0, f11_index = 0, g11_index = 0, h11_index = 0, i11_index = 0, j11_index = 0, k11_index = 0, l11_index = 0, m11_index = 0, n11_index = 0, o11_index = 0, p11_index = 0, q11_index = 0, r11_index = 0, r111_index = 0, s11_index = 0, t11_index = 0, u11_index = 0, v11_index = 0, w11_index = 0, x11_index = 0, y11_index = 0, z11_index = 0;
int amateur_7letters_played = 0, amateur_8letters_played = 0, amateur_9letters_played = 0, amateur_10letters_played = 0, amateur_11letters_played = 0;
int intermediate_7letters_played = 0, intermediate_8letters_played = 0, intermediate_9letters_played = 0, intermediate_10letters_played = 0, intermediate_11letters_played = 0;
int extreme_7letters_played = 0, extreme_8letters_played = 0, extreme_9letters_played = 0, extreme_10letters_played = 0, extreme_11letters_played = 0;
char mainpage[20][100] = {"C:\\Project\\bmp\\1.bmp", "C:\\Project\\bmp\\2.bmp", "C:\\Project\\Extreme Level\\Extreme_11letters.bmp", "C:\\Project\\Extreme Level\\Extreme_7letters.bmp", "C:\\Project\\Extreme Level\\Extreme_8letters.bmp", "C:\\Project\\Extreme Level\\Extreme_9letters.bmp", "C:\\Project\\Extreme Level\\Extreme_10letters.bmp", "C:\\Project\\Amateur Level\\Amateur_7_letters.bmp", "C:\\Project\\Amateur Level\\Amateur_8_letters.bmp", "C:\\Project\\Amateur Level\\Amateur_9_letters.bmp", "C:\\Project\\Amateur Level\\Amateur_10_letters.bmp", "C:\\Project\\Amateur Level\\Amateur_11_letters.bmp", "C:\\Project\\Intermediate Level\\Intermediate_7_letters.bmp", "C:\\Project\\Intermediate Level\\Intermediate_8_letters.bmp", "C:\\Project\\Intermediate Level\\Intermediate_9_letters.bmp", "C:\\Project\\Intermediate Level\\Intermediate_10_letters.bmp", "C:\\Project\\Intermediate Level\\Intermediate_11_letters.bmp"};
char name[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Name\\1.bmp"};
char Gamesettings[7][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Game settings\\2.bmp", "C:\\Project\\Game settings\\1.bmp"};
char HelpDesk[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\HelpDesk.bmp", "C:\\Project\\bmp\\Helpdesk1.bmp", "C:\\Project\\bmp\\HelpDesk2.bmp", "C:\\Project\\bmp\\HelpDesk3.bmp"};
char Tickgamelevel1[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\Tick.bmp"};
char congratulations[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Congratulations\\1.bmp", "C:\\Project\\Congrats\\0.bmp"};
char congratulations_amateur[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Congratulations\\2.bmp"};
char congratulations_intermediate[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Congratulations\\3.bmp"};
char Failed[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Failed\\1.bmp"};
char Failed_amateur[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Failed\\2.bmp"};
char Failed_intermediate[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Failed\\3.bmp"};
char played[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Played\\1.bmp"};
char home[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\home\\1.bmp"};
char character1[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Character1\\1.bmp", "C:\\Project\\Character1\\2.bmp", "C:\\Project\\Character1\\3.bmp", "C:\\Project\\Character1\\5.bmp", "C:\\Project\\Character1\\6.bmp", "C:\\Project\\Character1\\7.bmp"};
char character11[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Character1\\4.bmp", "C:\\Project\\bmp\\null.bmp"};
char character2[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Character2\\1.bmp", "C:\\Project\\Character2\\2.bmp"};
char bullet[100][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Bullet\\1.bmp", "C:\\Project\\bmp\\null.bmp"};
char Tickgamelevel2[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\Tick.bmp"};
char Tickgamelevel3[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\Tick.bmp"};
char Tickgameletter1[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\Tick.bmp"};
char Tickgameletter2[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\Tick.bmp"};
char Tickgameletter3[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\Tick.bmp"};
char Tickgameletter4[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\Tick.bmp"};
char Tickgameletter5[6][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\bmp\\Tick.bmp"};
char Aboutus[10][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\About Us bmp\\Aboutus.bmp"};
char Game_level_letters[10][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Game_level_letters\\1.bmp", "C:\\Project\\Game_level_letters\\2.bmp", "C:\\Project\\Game_level_letters\\3.bmp"};
char leaderboard[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\Leaderboard\\1.bmp"};
char a_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\a.bmp"};
char b_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\b.bmp"};
char c_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\c.bmp"};
char d_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\d.bmp"};
char e_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\e.bmp"};
char f_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\f.bmp"};
char g_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\g.bmp"};
char h_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\h.bmp"};
char i_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\i.bmp"};
char j_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\j.bmp"};
char k_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\k.bmp"};
char l_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\l.bmp"};
char m_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\m.bmp"};
char n_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\n.bmp"};
char o_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\o.bmp"};
char p_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\p.bmp"};
char q_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\q.bmp"};
char r_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\r.bmp"};
char s_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\s.bmp"};
char t_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\t.bmp"};
char u_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\u.bmp"};
char v_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\v.bmp"};
char w_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\w.bmp"};
char x_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\x.bmp"};
char y_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\y.bmp"};
char z_letter[2][100] = {"C:\\Project\\bmp\\null.bmp", "C:\\Project\\a-z\\z.bmp"};
void iDraw()
{
	// place your drawing codes here
	iClear();
	iShowBMP(0, 0, mainpage[mainpageIndex]);
	iShowBMP2(350, 25, name[nameIndex], 0);
	iShowBMP2(350, 25, leaderboard[leaderboardIndex], 0);
	iShowBMP2(898, 295, Tickgamelevel1[Tickgamelevelindex1], 0);
	iShowBMP2(898, 196, Tickgamelevel2[Tickgamelevelindex2], 0);
	iShowBMP2(898, 92, Tickgamelevel3[Tickgamelevelindex3], 0);
	iShowBMP2(295, 307, Tickgameletter1[Tickgameletterindex1], 0);
	iShowBMP2(295, 247, Tickgameletter2[Tickgameletterindex2], 0);
	iShowBMP2(295, 184, Tickgameletter3[Tickgameletterindex3], 0);
	iShowBMP2(295, 121, Tickgameletter4[Tickgameletterindex4], 0);
	iShowBMP2(295, 58, Tickgameletter5[Tickgameletterindex5], 0);
	iShowBMP2(350, 25, Aboutus[AboutusIndex], 0);
	iShowBMP2(a1, a2, a_letter[a_index], 0);
	iShowBMP2(a11, a22, a_letter[a11_index], 0);
	iShowBMP2(a111, a222, a_letter[a111_index], 0);
	iShowBMP2(b1, b2, b_letter[b_index], 0);
	iShowBMP2(c1, c2, c_letter[c_index], 0);
	iShowBMP2(d1, d2, d_letter[d_index], 0);
	iShowBMP2(e1, e2, e_letter[e_index], 0);
	iShowBMP2(e11, e22, e_letter[e11_index], 0);
	iShowBMP2(f1, f2, f_letter[f_index], 0);
	iShowBMP2(g1, g2, g_letter[g_index], 0);
	iShowBMP2(h1, h2, h_letter[h_index], 0);
	iShowBMP2(i1, i2, i_letter[i_index], 0);
	iShowBMP2(i11, i22, i_letter[i11_index], 0);
	iShowBMP2(j11, j2, j_letter[j_index], 0);
	iShowBMP2(k1, k2, k_letter[k_index], 0);
	iShowBMP2(l1, l2, l_letter[l_index], 0);
	iShowBMP2(l11, l22, l_letter[l11_index], 0);
	iShowBMP2(m1, m2, m_letter[m_index], 0);
	iShowBMP2(n1, n2, n_letter[n_index], 0);
	iShowBMP2(n11, n22, n_letter[n11_index], 0);
	iShowBMP2(o1, o2, o_letter[o_index], 0);
	iShowBMP2(o11, o22, o_letter[o11_index], 0);
	iShowBMP2(p1, p2, p_letter[p_index], 0);
	iShowBMP2(q1, q2, q_letter[q_index], 0);
	iShowBMP2(r1, r2, r_letter[r_index], 0);
	iShowBMP2(r11, r22, r_letter[r11_index], 0);
	iShowBMP2(r111, r222, r_letter[r111_index], 0);
	iShowBMP2(s1, s2, s_letter[s_index], 0);
	iShowBMP2(s11, s22, s_letter[s11_index], 0);
	iShowBMP2(t1, t2, t_letter[t_index], 0);
	iShowBMP2(u1, u2, u_letter[u_index], 0);
	iShowBMP2(v1, v2, v_letter[v_index], 0);
	iShowBMP2(w1, w2, w_letter[w_index], 0);
	iShowBMP2(x1, x2, x_letter[x_index], 0);
	iShowBMP2(y11, y2, y_letter[y_index], 0);
	iShowBMP2(z1, z2, z_letter[z_index], 0);
	iShowBMP2(350, 25, played[Played_Index], 0);
	iShowBMP2(350, 25, Game_level_letters[0], 0);
	iShowBMP2(225, 266, character1[character1_index], 0);
	iShowBMP2(700, 266, character2[character2_index], 0);
	iShowBMP2(character11_x_coordinate, character11_y_coordinate, character11[character11_index], 0);
	iShowBMP2(bullet_x_coordinate, bullet_y_coordinate, bullet[bullet_index], 0);
	iShowBMP2(350, 25, congratulations[congratulations_Index], 0);
	iShowBMP2(350, 25, Failed[Failed_Index], 0);
	iShowBMP2(350, 25, congratulations_amateur[congratulations_Index_amateur], 0);
	iShowBMP2(350, 25, Failed_amateur[Failed_Index_amateur], 0);
	iShowBMP2(350, 25, congratulations_intermediate[congratulations_Index_intermediate], 0);
	iShowBMP2(350, 25, Failed_intermediate[Failed_Index_intermediate], 0);
	iShowBMP2(350, 25, HelpDesk[HelpDeskIndex], 0);
	iShowBMP2(350, 25, Gamesettings[GamesettingsIndex], 0);
	iShowBMP2(571, 100, home[Home_Index], 0);
	
	if (mainpageIndex == 2 || mainpageIndex == 3 || mainpageIndex == 4 || mainpageIndex == 5 || mainpageIndex == 6)
	{
		iSetColor(0, 0, 0);
		sprintf(score1a, "%d", score1);
		iText(1128, 519, score1a, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1146, 519, "/ 2", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (mainpageIndex == 7 || mainpageIndex == 8 || mainpageIndex == 9 || mainpageIndex == 10 || mainpageIndex == 11)
	{
		iSetColor(0, 0, 0);
		sprintf(score2a, "%d", score2);
		iText(1128, 519, score2a, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1146, 519, "/ 5", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (mainpageIndex == 12 || mainpageIndex == 13 || mainpageIndex == 14 || mainpageIndex == 15 || mainpageIndex == 16)
	{
		iSetColor(0, 0, 0);
		sprintf(score3a, "%d", score3);
		iText(1128, 519, score3a, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1146, 519, "/ 3", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (mainpageIndex == 1)
	{
		iSetColor(255, 255, 255);
		sprintf(coina, "%d", coin);
		iText(1085, 545, coina, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (nameIndex == 1)
	{
		iSetColor(0, 0, 0);
		iText(541, 333, nameofuser, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (leaderboardIndex == 1)
	{
		int i;
		iSetColor(0, 0, 0);
		for (i = 0; i < (numberofname <= 10 ? numberofname : 10); i++)
		{
			char ch[3], ch1[5];
			sprintf(ch, "%d", i + 1);
			sprintf(ch1, "%4d", coins[i]);
			iText(436, 434 - 39 * i, ch, GLUT_BITMAP_HELVETICA_18);
			iText(562, 434 - 39 * i, nameofuserarray[i], GLUT_BITMAP_HELVETICA_18);
			iText(720, 434 - 39 * i, ch1, GLUT_BITMAP_HELVETICA_18);
		}
	}
	if (flagg == 1 && amateur_7letters_played == 1 && amateur_8letters_played == 1 && amateur_9letters_played == 1 && amateur_10letters_played == 1 && amateur_11letters_played == 1  && intermediate_7letters_played == 1 && intermediate_8letters_played == 1 && intermediate_9letters_played == 1 && intermediate_10letters_played == 1 && intermediate_11letters_played == 1  && extreme_7letters_played == 1 && extreme_8letters_played == 1 && extreme_9letters_played == 1 && extreme_10letters_played == 1 && extreme_11letters_played == 1 )
	{
		congratulations_Index = 2;
	}
}
void start()
{
	if (flag == 0)
	{
		mainpageIndex = 1;
		nameIndex = 1;
		flag = 1;
		if (musicON)
		{
			PlaySound("F:\\Project\\music\\Song.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
}
void bulletrun()
{
	if (flag2 == 1 || flag3 == 1 || flag4 == 1 || flag5 == 1 || flag6 == 1 || flag7 == 1 || flag8 == 1 || flag9 == 1 || flag10 == 1 || flag11 == 1 || flag12 == 1 || flag13 == 1 || flag14 == 1 || flag15 == 1 || flag16 == 1)
	{
		bullet_x_coordinate -= 200;
	}
	if (bullet_x_coordinate < 390)
	{
		bullet_index = 2;
		if (flag2 == 1)
			flag2 = 0;
		if (flag3 == 1)
			flag3 = 0;
		if (flag4 == 1)
			flag4 = 0;
		if (flag5 == 1)
			flag5 = 0;
		if (flag6 == 1)
			flag6 = 0;
		if (flag7 == 1)
			flag7 = 0;
		if (flag8 == 1)
			flag8 = 0;
		if (flag9 == 1)
			flag9 = 0;
		if (flag10 == 1)
			flag10 = 0;
		if (flag11 == 1)
			flag11 = 0;
		if (flag12 == 1)
			flag12 = 0;
		if (flag13 == 1)
			flag13 = 0;
		if (flag14 == 1)
			flag14 = 0;
		if (flag15 == 1)
			flag15 = 0;
		if (flag16 == 1)
			flag16 = 0;
		character1_index = 3;
		if (bullet_index == 2)
		{
			character11_index = 1;
			character1_index = 0;
		}
	}
}
void characterdrop()
{
	if (character11_index == 1)
	{
		character11_y_coordinate -= 50;
	}
	if (character11_y_coordinate < 0)
	{
		character11_index = 2;
	}
	if (character11_index == 2)
	{
		if (score1 <= 0 && character11_index == 2)
		{
			Failed_Index = 1;
			character1_index = 0;
			character2_index = 0;
		}
		if (score2 <= 0 && character11_index == 2)
		{
			Failed_Index_amateur = 1;
			character1_index = 0;
			character2_index = 0;
		}
		if (score3 <= 0 && character11_index == 2)
		{
			Failed_Index_intermediate = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
}
void gamelevel()
{
	if (flag1 == 0)
	{
		Game_level_letters_index = 0;
		flag1 = 1;
	}
}
void ball()
{
	x += dx;
	y += dy;
	if (x > 800 || x < 0)
	{
		dx *= -1;
	}
	if (y > 400 || y < 0)
	{
		dy *= -1;
	}
	a = rand() % 255;
	b = rand() % 255;
	c = rand() % 255;
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	// printf("x = %d, y= %d\n", mx, my);
	// x = mx - 250;
	// y = my - 60;
	// place your codes here
}
void game()
{
	printf("game\n");
}
/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		printf("x = %d, y= %d\n", mx, my);
		x = mx;
		y = my;
		if (nameIndex == 1)
		{
			if (x >= 524 && x <= 667 && y >= 181 && y <= 210)
			{
				file_write();
				nameIndex = 0;
			}
		}
		if (congratulations_Index == 2)
		{
			if (x >= 588 && x <= 618 && y >= 39 && y <= 68)
			{
				congratulations_Index = 0;
				flagg = 0;
			}
		}
		if (HelpDeskIndex == 0 && GamesettingsIndex == 0 && leaderboardIndex == 0 && Game_level_letters_index == 0 && mainpageIndex == 1)
		{
			if (AboutusIndex == 0)
			{
				if (x >= 7 && x <= 59 && y >= 509 && y <= 592)
				{
					AboutusIndex = 1;
				}
			}
			else if (AboutusIndex == 1)
			{
				if (x >= 582 && x <= 622 && y >= 38 && y <= 67)
				{
					AboutusIndex = 0;
				}
			}
		}
		if (AboutusIndex == 0 && GamesettingsIndex == 0 && leaderboardIndex == 0, Game_level_letters_index == 0 && mainpageIndex == 1)
		{
			if (HelpDeskIndex == 0)
			{
				if (x >= 94 && x <= 172 && y >= 15 && y <= 87)
				{
					HelpDeskIndex = 1;
				}
			}
			else if (HelpDeskIndex == 1)
			{
				if (x >= 446 && x <= 543 && y >= 194 && y <= 223)
				{
					HelpDeskIndex = 2;
				}
				if (x >= 656 && x <= 750 && y >= 194 && y <= 220)
				{
					HelpDeskIndex = 0;
				}
			}
			else if (HelpDeskIndex == 2)
			{
				if (x >= 542 && x <= 647 && y >= 81 && y <= 110)
				{
					HelpDeskIndex = 3;
				}
				if (x >= 582 && x <= 622 && y >= 38 && y <= 67)
				{
					HelpDeskIndex = 0;
				}
			}
			else if (HelpDeskIndex == 3)
			{
				if (x >= 542 && x <= 647 && y >= 81 && y <= 110)
				{
					HelpDeskIndex = 4;
				}
				if (x >= 582 && x <= 622 && y >= 38 && y <= 67)
				{
					HelpDeskIndex = 0;
				}
			}
			else if (HelpDeskIndex == 4)
			{
				if (x >= 587 && x <= 616 && y >= 38 && y <= 67)
				{
					HelpDeskIndex = 0;
				}
			}
		}
		if (HelpDeskIndex == 0 && AboutusIndex == 0 && GamesettingsIndex == 0 && Game_level_letters_index == 0 && mainpageIndex == 1)
		{
			if (leaderboardIndex == 0)
			{
				if (x >= 1117 && x <= 1190 && y >= 12 && y <= 88)
				{
					leaderboardIndex = 1;
					play = 0;
					cross = 1;
				}
			}
			else if (leaderboardIndex == 1)
			{

				if (cross == 1 && x >= 579 && x <= 609 && y >= 35 && y <= 66)
				{
					leaderboardIndex = 0;
					cross = 0;
				}
			}
		}
		if (HelpDeskIndex == 0 && AboutusIndex == 0 && GamesettingsIndex == 0 && leaderboardIndex == 0 && mainpageIndex == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				if (play == 1 && cross == 0 && Tickgamelevelindex1 == 0 && Tickgamelevelindex2 == 0 && Tickgamelevelindex3 == 0 && Tickgameletterindex1 == 0 && Tickgameletterindex2 == 0 && Tickgameletterindex3 == 0 && Tickgameletterindex4 == 0 && Tickgameletterindex5 == 0 && mainpageIndex == 1)
				{
					flag1 = 0;
					Game_level_letters_index = 1;
				}
				else if ((Tickgamelevelindex1 == 1 || Tickgamelevelindex2 == 1 || Tickgamelevelindex3 == 1) && (Tickgameletterindex1 == 0 && Tickgameletterindex2 == 0 && Tickgameletterindex3 == 0 && Tickgameletterindex4 == 0 && Tickgameletterindex5 == 0))
				{
					flag1 = 0;
					Game_level_letters_index = 2;
				}
				else if ((Tickgamelevelindex1 == 0 && Tickgamelevelindex2 == 0 && Tickgamelevelindex3 == 0) && (Tickgameletterindex1 == 1 || Tickgameletterindex2 == 1 || Tickgameletterindex3 == 1 || Tickgameletterindex4 == 1 || Tickgameletterindex5 == 1))
				{
					flag1 = 0;
					Game_level_letters_index = 3;
				}
			}
		}
		if (Tickgamelevelindex1 == 0 && Tickgamelevelindex2 == 0 && Tickgamelevelindex3 == 0 && mainpageIndex == 1)
		{
			if (x >= 893 && x <= 935 && y >= 295 && y <= 332)
			{
				Tickgamelevelindex1 = 1;
			}
			else if (x >= 893 && x <= 936 && y >= 196 && y <= 231)
			{
				Tickgamelevelindex2 = 1;
			}
			else if (x >= 893 && x <= 935 && y >= 92 && y <= 129)
			{
				Tickgamelevelindex3 = 1;
			}
		}
		else if (Tickgamelevelindex1 == 1)
		{
			if (x >= 893 && x <= 935 && y >= 295 && y <= 332)
			{
				Tickgamelevelindex1 = 0;
			}
		}
		else if (Tickgamelevelindex2 == 1)
		{
			if (x >= 893 && x <= 936 && y >= 196 && y <= 231)
			{
				Tickgamelevelindex2 = 0;
			}
		}
		else if (Tickgamelevelindex3 == 1)
		{
			if (x >= 893 && x <= 935 && y >= 92 && y <= 129)
			{
				Tickgamelevelindex3 = 0;
			}
		}
		if (Tickgameletterindex1 == 0 && Tickgameletterindex2 == 0 && Tickgameletterindex3 == 0 && Tickgameletterindex4 == 0 && Tickgameletterindex5 == 0 && mainpageIndex == 1)
		{
			if (x >= 292 && x <= 332 && y >= 308 && y <= 343)
			{
				Tickgameletterindex1 = 1;
			}
			else if (x >= 292 && x <= 332 && y >= 246 && y <= 282)
			{
				Tickgameletterindex2 = 1;
			}
			else if (x >= 292 && x <= 332 && y >= 185 && y <= 219)
			{
				Tickgameletterindex3 = 1;
			}
			else if (x >= 292 && x <= 332 && y >= 121 && y <= 158)
			{
				Tickgameletterindex4 = 1;
			}
			else if (x >= 292 && x <= 332 && y >= 56 && y <= 95)
			{
				Tickgameletterindex5 = 1;
			}
		}
		else if (Tickgameletterindex1 == 1)
		{
			if (x >= 292 && x <= 332 && y >= 308 && y <= 343)
			{
				Tickgameletterindex1 = 0;
			}
		}
		else if (Tickgameletterindex2 == 1)
		{
			if (x >= 292 && x <= 332 && y >= 246 && y <= 282)
			{
				Tickgameletterindex2 = 0;
			}
		}
		else if (Tickgameletterindex3 == 1)
		{
			if (x >= 292 && x <= 332 && y >= 185 && y <= 219)
			{
				Tickgameletterindex3 = 0;
			}
		}
		else if (Tickgameletterindex4 == 1)
		{
			if (x >= 292 && x <= 332 && y >= 121 && y <= 158)
			{
				Tickgameletterindex4 = 0;
			}
		}
		else if (Tickgameletterindex5 == 1)
		{
			if (x >= 292 && x <= 332 && y >= 56 && y <= 95)
			{
				Tickgameletterindex5 = 0;
			}
		}
		if (HelpDeskIndex == 0 && AboutusIndex == 0 && leaderboardIndex == 0 && Game_level_letters_index == 0 && mainpageIndex == 1)
		{
			if (GamesettingsIndex == 0)
			{
				if (x >= 9 && x <= 83 && y >= 15 && y <= 87)
				{
					GamesettingsIndex = GamesettingsIndexdummy;
				}
			}
			else if (GamesettingsIndex == 1)
			{
				if (x >= 455 && x <= 528 && y >= 220 && y <= 282)
				{
					GamesettingsIndex = 2;
					if (musicON)
					{
						musicON = false;
						PlaySound(0, 0, 0);
					}
				}
				else if (x >= 586 && x <= 601 && y >= 40 && y <= 70)
				{
					GamesettingsIndexdummy = GamesettingsIndex;
					GamesettingsIndex = 0;
					Home_Index = 0;
				}
			}
			else if (GamesettingsIndex == 2)
			{
				if (x >= 455 && x <= 528 && y >= 220 && y <= 282)
				{
					GamesettingsIndex = 1;
					musicON = true;
					if (musicON)
					{
						PlaySound("F:\\Project\\music\\Song.wav", NULL, SND_LOOP | SND_ASYNC);
					}
				}
				else if (x >= 586 && x <= 601 && y >= 40 && y <= 70)
				{
					GamesettingsIndexdummy = GamesettingsIndex;
					GamesettingsIndex = 0;
				}
			}
		}
		if (Tickgameletterindex1 == 1 && Tickgamelevelindex3 == 1 && extreme_7letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 3;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex1 = 0;
				Tickgamelevelindex3 = 0;
			}
		}
		if (Tickgameletterindex2 == 1 && Tickgamelevelindex3 == 1 && extreme_8letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 4;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex2 = 0;
				Tickgamelevelindex3 = 0;
			}
		}
		if (Tickgameletterindex3 == 1 && Tickgamelevelindex3 == 1 && extreme_9letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 5;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex3 = 0;
				Tickgamelevelindex3 = 0;
			}
		}
		if (Tickgameletterindex4 == 1 && Tickgamelevelindex3 == 1 && extreme_10letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 6;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex4 = 0;
				Tickgamelevelindex3 = 0;
			}
		}
		if (Tickgameletterindex5 == 1 && Tickgamelevelindex3 == 1 && extreme_11letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 2;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex5 = 0;
				Tickgamelevelindex3 = 0;
			}
		}
		if (Tickgameletterindex1 == 1 && Tickgamelevelindex1 == 1 && amateur_7letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 7;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex1 = 0;
				Tickgamelevelindex1 = 0;
			}
		}
		if (Tickgameletterindex2 == 1 && Tickgamelevelindex1 == 1 && amateur_8letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 8;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex2 = 0;
				Tickgamelevelindex1 = 0;
			}
		}
		if (Tickgameletterindex3 == 1 && Tickgamelevelindex1 == 1 && amateur_9letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 9;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex3 = 0;
				Tickgamelevelindex1 = 0;
			}
		}
		if (Tickgameletterindex4 == 1 && Tickgamelevelindex1 == 1 && amateur_10letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 10;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex4 = 0;
				Tickgamelevelindex1 = 0;
			}
		}
		if (Tickgameletterindex5 == 1 && Tickgamelevelindex1 == 1 && amateur_11letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 11;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex5 = 0;
				Tickgamelevelindex1 = 0;
			}
		}
		if (Tickgameletterindex1 == 1 && Tickgamelevelindex2 == 1 && intermediate_7letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 12;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex1 = 0;
				Tickgamelevelindex2 = 0;
			}
		}
		if (Tickgameletterindex2 == 1 && Tickgamelevelindex2 == 1 && intermediate_8letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 13;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex2 = 0;
				Tickgamelevelindex2 = 0;
			}
		}
		if (Tickgameletterindex3 == 1 && Tickgamelevelindex2 == 1 && intermediate_9letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 14;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex3 = 0;
				Tickgamelevelindex2 = 0;
			}
		}
		if (Tickgameletterindex4 == 1 && Tickgamelevelindex2 == 1 && intermediate_10letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 15;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex4 = 0;
				Tickgamelevelindex2 = 0;
			}
		}
		if (Tickgameletterindex5 == 1 && Tickgamelevelindex2 == 1 && intermediate_11letters_played == 0)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				mainpageIndex = 16;
				character1_index = 1;
				character2_index = 1;
				Tickgameletterindex5 = 0;
				Tickgamelevelindex2 = 0;
			}
		}
		if (HelpDeskIndex == 0 && AboutusIndex == 0 && leaderboardIndex == 0 && Game_level_letters_index == 0 && (mainpageIndex == 2 || mainpageIndex == 3 || mainpageIndex == 4 || mainpageIndex == 5 || mainpageIndex == 6 || mainpageIndex == 7 || mainpageIndex == 8 || mainpageIndex == 9 || mainpageIndex == 10 || mainpageIndex == 11 || mainpageIndex == 12 || mainpageIndex == 13 || mainpageIndex == 14 || mainpageIndex == 15 || mainpageIndex == 16))
		{
			if (GamesettingsIndex == 0)
			{
				if (x >= 9 && x <= 83 && y >= 518 && y <= 590)
				{
					GamesettingsIndex = GamesettingsIndexdummy;
					Home_Index = 1;
				}
			}
			else if (GamesettingsIndex == 1)
			{
				if (x >= 455 && x <= 528 && y >= 220 && y <= 282)
				{
					GamesettingsIndex = 2;
					Home_Index = 1;
					if (musicON)
					{
						musicON = false;
						PlaySound(0, 0, 0);
					}
				}
				else if (x >= 574 && x <= 617 && y >= 109 && y <= 147)
				{
					GamesettingsIndexdummy = GamesettingsIndex;
					GamesettingsIndex = 0;
					Home_Index = 0;
					character1_index = 0;
					character2_index = 0;
					mainpageIndex = 1;
				}
				else if (x >= 586 && x <= 601 && y >= 40 && y <= 70)
				{
					GamesettingsIndexdummy = GamesettingsIndex;
					GamesettingsIndex = 0;
					Home_Index = 0;
				}
			}
			else if (GamesettingsIndex == 2)
			{
				if (x >= 455 && x <= 528 && y >= 220 && y <= 282)
				{
					GamesettingsIndex = 1;
					musicON = true;
					if (musicON)
					{
						PlaySound("F:\\Project\\music\\Song.wav", NULL, SND_LOOP | SND_ASYNC);
					}
				}
				else if (x >= 574 && x <= 617 && y >= 109 && y <= 147)
				{
					GamesettingsIndexdummy = GamesettingsIndex;
					GamesettingsIndex = 0;
					Home_Index = 0;
					character1_index = 0;
					character2_index = 0;
					mainpageIndex = 1;
				}
				else if (x >= 586 && x <= 601 && y >= 40 && y <= 70)
				{
					GamesettingsIndexdummy = GamesettingsIndex;
					GamesettingsIndex = 0;
					Home_Index = 0;
				}
			}
		}
		if (AboutusIndex == 0 && GamesettingsIndex == 0 && leaderboardIndex == 0, Game_level_letters_index == 0 && (mainpageIndex == 2 || mainpageIndex == 3 || mainpageIndex == 4 || mainpageIndex == 5 || mainpageIndex == 6 || mainpageIndex == 7 || mainpageIndex == 8 || mainpageIndex == 9 || mainpageIndex == 10 || mainpageIndex == 11 || mainpageIndex == 12 || mainpageIndex == 13 || mainpageIndex == 14 || mainpageIndex == 15 || mainpageIndex == 16))
		{
			if (HelpDeskIndex == 0)
			{
				if (x >= 94 && x <= 172 && y >= 520 && y <= 590)
				{
					HelpDeskIndex = 4;
				}
			}
			else if (HelpDeskIndex == 4)
			{
				if (x >= 587 && x <= 616 && y >= 38 && y <= 67)
				{
					HelpDeskIndex = 0;
				}
			}
		}
		if (HelpDeskIndex == 0 && AboutusIndex == 0 && GamesettingsIndex == 0 && Game_level_letters_index == 0 && mainpageIndex == 1)
		{
			if (leaderboardIndex == 0)
			{
				if (x >= 1117 && x <= 1190 && y >= 12 && y <= 88)
				{
					leaderboardIndex = 1;
					play = 0;
					cross = 1;
				}
			}
			else if (leaderboardIndex == 1)
			{

				if (cross == 1 && x >= 579 && x <= 609 && y >= 35 && y <= 66)
				{
					leaderboardIndex = 0;
					cross = 0;
				}
			}
		}
		if (congratulations_Index == 1)
		{
			if (x >= 571 && x <= 617 && y >= 98 && y <= 141)
			{
				a_index = 0, b_index = 0, c_index = 0, d_index = 0, e_index = 0, f_index = 0, g_index = 0, h_index = 0, i_index = 0, j_index = 0, k_index = 0, l_index = 0, m_index = 0, n_index = 0, o_index = 0, p_index = 0, q_index = 0, r_index = 0, s_index = 0, t_index = 0, u_index = 0, v_index = 0, w_index = 0, x_index = 0, y_index = 0, z_index = 0;
				a11_index = 0, b11_index = 0, c11_index = 0, d11_index = 0, e11_index = 0, f11_index = 0, g11_index = 0, h11_index = 0, i11_index = 0, j11_index = 0, k11_index = 0, l11_index = 0, m11_index = 0, n11_index = 0, o11_index = 0, p11_index = 0, q11_index = 0, r11_index = 0, s11_index = 0, t11_index = 0, u11_index = 0, v11_index = 0, w11_index = 0, x11_index = 0, y11_index = 0, z11_index = 0;
				r111_index = 0;
				a111_index = 0;
				congratulations_Index = 0;
				score1 = 2;
				coin += 100;
				coins[tempindex] = coin;
				sort();
				mainpageIndex = 1;
				bullet_index = 0;
				character11_index = 0;
				character1_index = 0;
				character2_index = 0;
				bullet_x_coordinate = 780, bullet_y_coordinate = 424, character11_index = 0, character11_x_coordinate = 12, character11_y_coordinate = 242;
			}
		}
		if (Failed_Index == 1)
		{
			if (x >= 571 && x <= 617 && y >= 98 && y <= 141)
			{
				a11_index = 0, b11_index = 0, c11_index = 0, d11_index = 0, e11_index = 0, f11_index = 0, g11_index = 0, h11_index = 0, i11_index = 0, j11_index = 0, k11_index = 0, l11_index = 0, m11_index = 0, n11_index = 0, o11_index = 0, p11_index = 0, q11_index = 0, r11_index = 0, s11_index = 0, t11_index = 0, u11_index = 0, v11_index = 0, w11_index = 0, x11_index = 0, y11_index = 0, z11_index = 0;
				a_index = 0, b_index = 0, c_index = 0, d_index = 0, e_index = 0, f_index = 0, g_index = 0, h_index = 0, i_index = 0, j_index = 0, k_index = 0, l_index = 0, m_index = 0, n_index = 0, o_index = 0, p_index = 0, q_index = 0, r_index = 0, s_index = 0, t_index = 0, u_index = 0, v_index = 0, w_index = 0, x_index = 0, y_index = 0;
				r111_index = 0;
				a111_index = 0;
				Failed_Index = 0;
				coin -= 10;
				coins[tempindex] = coin;
				sort();
				score1 = 2;
				mainpageIndex = 1;
				bullet_index = 0;
				character11_index = 0;
				character1_index = 0;
				character2_index = 0;
				bullet_x_coordinate = 780, bullet_y_coordinate = 424, character11_index = 0, character11_x_coordinate = 12, character11_y_coordinate = 242;
			}
		}
		if (congratulations_Index_amateur == 1)
		{
			if (x >= 571 && x <= 617 && y >= 98 && y <= 141)
			{
				a_index = 0, b_index = 0, c_index = 0, d_index = 0, e_index = 0, f_index = 0, g_index = 0, h_index = 0, i_index = 0, j_index = 0, k_index = 0, l_index = 0, m_index = 0, n_index = 0, o_index = 0, p_index = 0, q_index = 0, r_index = 0, s_index = 0, t_index = 0, u_index = 0, v_index = 0, w_index = 0, x_index = 0, y_index = 0, z_index = 0;
				a11_index = 0, b11_index = 0, c11_index = 0, d11_index = 0, e11_index = 0, f11_index = 0, g11_index = 0, h11_index = 0, i11_index = 0, j11_index = 0, k11_index = 0, l11_index = 0, m11_index = 0, n11_index = 0, o11_index = 0, p11_index = 0, q11_index = 0, r11_index = 0, s11_index = 0, t11_index = 0, u11_index = 0, v11_index = 0, w11_index = 0, x11_index = 0, y11_index = 0, z11_index = 0;
				r111_index = 0;
				a111_index = 0;
				congratulations_Index_amateur = 0;
				score2 = 5;
				coin += 50;
				coins[tempindex] = coin;
				sort();
				mainpageIndex = 1;
				bullet_index = 0;
				character11_index = 0;
				character1_index = 0;
				character2_index = 0;
				bullet_x_coordinate = 780, bullet_y_coordinate = 424, character11_index = 0, character11_x_coordinate = 12, character11_y_coordinate = 242;
			}
		}
		if (Failed_Index_amateur == 1)
		{
			if (x >= 571 && x <= 617 && y >= 98 && y <= 141)
			{
				a11_index = 0, b11_index = 0, c11_index = 0, d11_index = 0, e11_index = 0, f11_index = 0, g11_index = 0, h11_index = 0, i11_index = 0, j11_index = 0, k11_index = 0, l11_index = 0, m11_index = 0, n11_index = 0, o11_index = 0, p11_index = 0, q11_index = 0, r11_index = 0, s11_index = 0, t11_index = 0, u11_index = 0, v11_index = 0, w11_index = 0, x11_index = 0, y11_index = 0, z11_index = 0;
				a_index = 0, b_index = 0, c_index = 0, d_index = 0, e_index = 0, f_index = 0, g_index = 0, h_index = 0, i_index = 0, j_index = 0, k_index = 0, l_index = 0, m_index = 0, n_index = 0, o_index = 0, p_index = 0, q_index = 0, r_index = 0, s_index = 0, t_index = 0, u_index = 0, v_index = 0, w_index = 0, x_index = 0, y_index = 0;
				r111_index = 0;
				a111_index = 0;
				Failed_Index_amateur = 0;
				coin -= 5;
				coins[tempindex] = coin;
				sort();
				score2 = 5;
				mainpageIndex = 1;
				bullet_index = 0;
				character11_index = 0;
				character1_index = 0;
				character2_index = 0;
				bullet_x_coordinate = 780, bullet_y_coordinate = 424, character11_index = 0, character11_x_coordinate = 12, character11_y_coordinate = 242;
			}
		}
		if (congratulations_Index_intermediate == 1)
		{
			if (x >= 571 && x <= 617 && y >= 98 && y <= 141)
			{
				a_index = 0, b_index = 0, c_index = 0, d_index = 0, e_index = 0, f_index = 0, g_index = 0, h_index = 0, i_index = 0, j_index = 0, k_index = 0, l_index = 0, m_index = 0, n_index = 0, o_index = 0, p_index = 0, q_index = 0, r_index = 0, s_index = 0, t_index = 0, u_index = 0, v_index = 0, w_index = 0, x_index = 0, y_index = 0, z_index = 0;
				a11_index = 0, b11_index = 0, c11_index = 0, d11_index = 0, e11_index = 0, f11_index = 0, g11_index = 0, h11_index = 0, i11_index = 0, j11_index = 0, k11_index = 0, l11_index = 0, m11_index = 0, n11_index = 0, o11_index = 0, p11_index = 0, q11_index = 0, r11_index = 0, s11_index = 0, t11_index = 0, u11_index = 0, v11_index = 0, w11_index = 0, x11_index = 0, y11_index = 0, z11_index = 0;
				r111_index = 0;
				a111_index = 0;
				congratulations_Index_intermediate = 0;
				score3 = 3;
				coin += 80;
				coins[tempindex] = coin;
				sort();
				mainpageIndex = 1;
				bullet_index = 0;
				character11_index = 0;
				character1_index = 0;
				character2_index = 0;
				bullet_x_coordinate = 780, bullet_y_coordinate = 424, character11_index = 0, character11_x_coordinate = 12, character11_y_coordinate = 242;
			}
		}
		if (Failed_Index_intermediate == 1)
		{
			if (x >= 571 && x <= 617 && y >= 98 && y <= 141)
			{
				a11_index = 0, b11_index = 0, c11_index = 0, d11_index = 0, e11_index = 0, f11_index = 0, g11_index = 0, h11_index = 0, i11_index = 0, j11_index = 0, k11_index = 0, l11_index = 0, m11_index = 0, n11_index = 0, o11_index = 0, p11_index = 0, q11_index = 0, r11_index = 0, s11_index = 0, t11_index = 0, u11_index = 0, v11_index = 0, w11_index = 0, x11_index = 0, y11_index = 0, z11_index = 0;
				a_index = 0, b_index = 0, c_index = 0, d_index = 0, e_index = 0, f_index = 0, g_index = 0, h_index = 0, i_index = 0, j_index = 0, k_index = 0, l_index = 0, m_index = 0, n_index = 0, o_index = 0, p_index = 0, q_index = 0, r_index = 0, s_index = 0, t_index = 0, u_index = 0, v_index = 0, w_index = 0, x_index = 0, y_index = 0;
				r111_index = 0;
				a111_index = 0;
				Failed_Index_intermediate = 0;
				coin -= 8;
				coins[tempindex] = coin;
				sort();
				score3 = 3;
				mainpageIndex = 1;
				bullet_index = 0;
				character11_index = 0;
				character1_index = 0;
				character2_index = 0;
				bullet_x_coordinate = 780, bullet_y_coordinate = 424, character11_index = 0, character11_x_coordinate = 12, character11_y_coordinate = 242;
			}
		}
		if (Tickgameletterindex1 == 1 && Tickgamelevelindex3 == 1 && extreme_7letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex2 == 1 && Tickgamelevelindex3 == 1 && extreme_8letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex3 == 1 && Tickgamelevelindex3 == 1 && extreme_9letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex4 == 1 && Tickgamelevelindex3 == 1 && extreme_9letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex5 == 1 && Tickgamelevelindex3 == 1 && extreme_11letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex1 == 1 && Tickgamelevelindex1 == 1 && amateur_7letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex2 == 1 && Tickgamelevelindex1 == 1 && amateur_8letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex3 == 1 && Tickgamelevelindex1 == 1 && amateur_9letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex4 == 1 && Tickgamelevelindex1 == 1 && amateur_10letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex5 == 1 && Tickgamelevelindex1 == 1 && amateur_11letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex1 == 1 && Tickgamelevelindex2 == 1 && intermediate_7letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex2 == 1 && Tickgamelevelindex2 == 1 && intermediate_8letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex3 == 1 && Tickgamelevelindex2 == 1 && intermediate_9letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex4 == 1 && Tickgamelevelindex2 == 1 && intermediate_10letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		else if (Tickgameletterindex5 == 1 && Tickgamelevelindex2 == 1 && intermediate_11letters_played == 1)
		{
			if (x >= 495 && x <= 714 && y >= 46 && y <= 90)
			{
				Played_Index = 1;
			}
		}
		if (Played_Index == 1)
		{
			if (x >= 576 && x <= 610 && y >= 36 && y <= 65)
			{
				Played_Index = 0;
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		a = 255;
		b = 0;
		c = 0;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (mainpageIndex == 2)
	{
		if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score1 > 0)
			{
				e1 = 750, e2 = 117;
				e11 = 475, e22 = 33;
				e_index = 1;
				e11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'i' || key == 'I')
		{
			if (score1 > 0)
			{
				i1 = 422, i2 = 117;
				i11 = 801;
				i22 = 33;
				i_index = 1;
				i11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'l' || key == 'L')
		{
			if (score1 > 0)
			{
				l1 = 310, l2 = 117;
				l11 = 838, l22 = 117;
				l_index = 1;
				l11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'm' || key == 'M')
		{
			if (score1 > 0)
			{
				m1 = 365, m2 = 33;
				m_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score1 > 0)
			{
				n1 = 642, n2 = 117;
				n_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'o' || key == 'O')
		{
			if (score1 > 0)
			{
				o1 = 531, o2 = 117;
				o_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 's' || key == 'S')
		{
			if (score1 > 0)
			{
				s1 = 694, s2 = 33;
				s11 = 584, s22 = 33;
				s_index = 1;
				s11_index = 1;
			}
		}
		else
		{
			if (score1 >= 0 && GamesettingsIndex == 0 && (e_index == 0 || e11_index == 0 || i_index == 0 || i11_index == 0 || l_index == 0 || l11_index == 0 || m_index == 0 || n_index == 0 || o_index == 0 || s_index == 0 || s11_index == 0))
			{
				score1--;
				character1_index = 2;
				character2_index = 2;
				if (score1 <= 0)
				{
					extreme_11letters_played = 1;
					bullet_index = 1;
					flag2 = 1;
				}
			}
		}
		if (score1 > 0 && (e_index == 1 && e11_index == 1 && i_index == 1 && i11_index == 1 && l_index == 1 && l11_index == 1 && m_index == 1 && n_index == 1 && o_index == 1 && s_index == 1 && s11_index == 1))
		{
			congratulations_Index = 1;
			extreme_11letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 3)
	{
		if (GamesettingsIndex == 0 && key == 'p' || key == 'P')
		{
			if (score1 > 0)
			{
				p1 = 308, p2 = 125;
				p_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score1 > 0)
			{
				e1 = 415, e2 = 125;
				e_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score1 > 0)
			{
				n1 = 528, n2 = 125;
				n11 = 360, n22 = 39;
				n_index = 1;
				n11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'g' || key == 'G')
		{
			if (score1 > 0)
			{
				g1 = 635, g2 = 125;
				g_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'u' || key == 'U')
		{
			if (score1 > 0)
			{
				u1 = 743, u2 = 125;
				u_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'i' || key == 'I')
		{
			if (score1 > 0)
			{
				i1 = 837, i2 = 125;
				i_index = 1;
			}
		}

		else
		{
			if (score1 >= 0 && GamesettingsIndex == 0 && (p_index == 0 || e_index == 0 || n_index == 0 || g_index == 0 || u_index == 0 || i_index == 0))
			{
				score1--;
				character1_index = 2;
				character2_index = 2;
				if (score1 <= 0)
				{
					extreme_7letters_played = 1;
					bullet_index = 1;
					flag3 = 1;
				}
			}
		}
		if (score1 > 0 && (p_index == 1 && e_index == 1 && n_index == 1 && g_index == 1 && u_index == 1 && i_index == 1))
		{
			congratulations_Index = 1;
			extreme_7letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 4)
	{
		if (GamesettingsIndex == 0 && key == 'w' || key == 'W')
		{
			if (score1 > 0)
			{
				w1 = 304, w2 = 119;
				w_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score1 > 0)
			{
				a1 = 413, a2 = 125;
				a_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 't' || key == 'T')
		{
			if (score1 > 0)
			{
				t1 = 525, t2 = 125;
				t_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score1 > 0)
			{
				e1 = 633, e2 = 125;
				e_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'r' || key == 'R')
		{
			if (score1 > 0)
			{
				r1 = 741, r2 = 125;
				r_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'l' || key == 'L')
		{
			if (score1 > 0)
			{
				l1 = 835, l2 = 125;
				l_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'o' || key == 'O')
		{
			if (score1 > 0)
			{
				o1 = 357, o2 = 37;
				o11 = 468, o22 = 37;
				o_index = 1;
				o11_index = 1;
			}
		}
		else
		{
			if (score1 >= 0 && GamesettingsIndex == 0 && (w_index == 0 || a_index == 0 || t_index == 0 || e_index == 0 || r_index == 0 || l_index == 0 || o_index == 0 || o11_index == 0))
			{
				score1--;
				character1_index = 2;
				character2_index = 2;
				if (score1 <= 0)
				{
					extreme_8letters_played = 1;
					bullet_index = 1;
					flag4 = 1;
				}
			}
		}
		if (score1 > 0 && (w_index == 1 && a_index == 1 && t_index == 1 && e_index == 1 && r_index == 1 && l_index == 1 && o_index == 1 && o11_index == 1))
		{
			congratulations_Index = 1;
			extreme_8letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 5)
	{
		if (GamesettingsIndex == 0 && key == 'b' || key == 'B')
		{
			if (score1 > 0)
			{
				b1 = 302, b2 = 125;
				b_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'l' || key == 'L')
		{
			if (score1 > 0)
			{
				l1 = 411, l2 = 125;
				l11 = 465, l22 = 38;
				l_index = 1;
				l11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'u' || key == 'U')
		{
			if (score1 > 0)
			{
				u1 = 521, u2 = 125;
				u_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score1 > 0)
			{
				e1 = 632, e2 = 125;
				e11 = 576, e22 = 38;
				e_index = 1;
				e11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'w' || key == 'W')
		{
			if (score1 > 0)
			{
				w1 = 741, w2 = 121;
				w_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'h' || key == 'H')
		{
			if (score1 > 0)
			{
				h1 = 832, h2 = 125;
				h_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score1 > 0)
			{
				a1 = 355, a2 = 38;
				a_index = 1;
			}
		}
		else
		{
			if (score1 >= 0 && GamesettingsIndex == 0 && (b_index == 0 || l_index == 0 || l11_index == 0 || u_index == 0 || e_index == 0 || e11_index == 0 || w_index == 0 || h_index == 0 || a_index == 0))
			{
				score1--;
				character1_index = 2;
				character2_index = 2;
				if (score1 <= 0)
				{
					extreme_9letters_played = 1;
					bullet_index = 1;
					flag5 = 1;
				}
			}
		}
		if (score1 > 0 && (b_index == 1 && l_index == 1 && l11_index == 1 && u_index == 1 && e_index == 1 && e11_index == 1 && w_index == 1 && h_index == 1 && a_index == 1))
		{
			congratulations_Index = 1;
			extreme_9letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 6)
	{
		if (GamesettingsIndex == 0 && key == 'r' || key == 'R')
		{
			if (score1 > 0)
			{
				r1 = 302, r2 = 125;
				r11 = 835, r22 = 125;
				r111 = 575, r222 = 38;
				r_index = 1;
				r11_index = 1;
				r111_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'u' || key == 'U')
		{
			if (score1 > 0)
			{
				u1 = 411, u2 = 125;
				u_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 't' || key == 'T')
		{
			if (score1 > 0)
			{
				t1 = 521, t2 = 125;
				t_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'h' || key == 'H')
		{
			if (score1 > 0)
			{
				h1 = 630, h2 = 125;
				h_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score1 > 0)
			{
				e1 = 741, e2 = 125;
				e_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'f' || key == 'F')
		{
			if (score1 > 0)
			{
				f1 = 363, f2 = 38;
				f_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'o' || key == 'O')
		{
			if (score1 > 0)
			{
				o1 = 465, o2 = 38;
				o_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'd' || key == 'D')
		{
			if (score1 > 0)
			{
				d1 = 684, d2 = 38;
				d_index = 1;
			}
		}
		else
		{
			if (score1 >= 0 && GamesettingsIndex == 0 && (r_index == 0 || r11_index == 0 || r111_index == 0 || u_index == 0 || t_index == 0 || h_index == 0 || e_index == 0 || f_index == 0 || o_index == 0 || d_index == 0))
			{
				score1--;
				character1_index = 2;
				character2_index = 2;
				if (score1 <= 0)
				{
					extreme_10letters_played = 1;
					bullet_index = 1;
					flag6 = 1;
				}
			}
		}
		if (score1 > 0 && (r_index == 1 && r11_index == 1 && r111_index == 1 && u_index == 1 && t_index == 1 && h_index == 1 && e_index == 1 && f_index == 1 && o_index == 1 && d_index == 1))
		{
			congratulations_Index = 1;
			extreme_10letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 7)
	{
		if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score2 > 0)
			{
				e1 = 312, e2 = 115;
				e_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score2 > 0)
			{
				n1 = 422, n2 = 115;
				n11 = 845, n22 = 115;
				n_index = 1;
				n11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'g' || key == 'G')
		{
			if (score2 > 0)
			{
				g1 = 530, g2 = 115;
				g_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'l' || key == 'L')
		{
			if (score2 > 0)
			{
				l1 = 638, l2 = 115;
				l_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score2 > 0)
			{
				a1 = 748, a2 = 115;
				a_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'd' || key == 'D')
		{
			if (score2 > 0)
			{
				d1 = 365, d2 = 28;
				d_index = 1;
			}
		}
		else
		{
			if (score2 >= 0 && GamesettingsIndex == 0 && (e_index == 0 || n11_index == 0 || n_index == 0 || g_index == 0 || l_index == 0 || a_index == 0 || d_index == 0))
			{
				score2--;
				if (score2 == 1)
				{
					character1_index = 2;
				}
				if (score2 == 4)
				{
					character1_index = 4;
				}
				if (score2 == 3)
				{
					character1_index = 5;
				}
				if (score2 == 2)
				{
					character1_index = 6;
				}
				if (score2 == 3)
				{
					character2_index = 2;
				}
				if (score2 <= 0)
				{
					amateur_7letters_played = 1;
					bullet_index = 1;
					flag7 = 1;
				}
			}
		}
		if (score2 > 0 && (e_index == 1 && n11_index == 1 && n_index == 1 && g_index == 1 && l_index == 1 && a_index == 1 && d_index == 1))
		{
			congratulations_Index_amateur = 1;
			amateur_7letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 8)
	{
		if (GamesettingsIndex == 0 && key == 'c' || key == 'C')
		{
			if (score2 > 0)
			{
				c1 = 308, c2 = 115;
				c_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'h' || key == 'H')
		{
			if (score2 > 0)
			{
				h1 = 416, h2 = 115;
				h_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'l' || key == 'L')
		{
			if (score2 > 0)
			{
				l1 = 525, l2 = 115;
				l_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'o' || key == 'O')
		{
			if (score2 > 0)
			{
				o1 = 635, o2 = 115;
				o_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'r' || key == 'R')
		{
			if (score2 > 0)
			{
				r1 = 745, r2 = 115;
				r_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'i' || key == 'I')
		{
			if (score2 > 0)
			{
				i1 = 838, i2 = 115;
				i_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score2 > 0)
			{
				n1 = 362, n2 = 28;
				n_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score2 > 0)
			{
				e1 = 470, e2 = 28;
				e_index = 1;
			}
		}
		else
		{
			if (score2 >= 0 && GamesettingsIndex == 0 && (c_index == 0 || h_index == 0 || l_index == 0 || o_index == 0 || r_index == 0 || i_index == 0 || n_index == 0 || e_index == 0))
			{
				score2--;
				if (score2 == 1)
				{
					character1_index = 2;
				}
				if (score2 == 4)
				{
					character1_index = 4;
				}
				if (score2 == 3)
				{
					character1_index = 5;
				}
				if (score2 == 2)
				{
					character1_index = 6;
				}
				if (score2 == 3)
				{
					character2_index = 2;
				}
				if (score2 <= 0)
				{
					amateur_8letters_played = 1;
					bullet_index = 1;
					flag8 = 1;
				}
			}
		}
		if (score2 > 0 && (c_index == 1 && h_index == 1 && l_index == 1 && o_index == 1 && r_index == 1 && i_index == 1 && n_index == 1 && e_index == 1))
		{
			congratulations_Index_amateur = 1;
			amateur_8letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 9)
	{
		if (GamesettingsIndex == 0 && key == 'b' || key == 'B')
		{
			if (score2 > 0)
			{
				b1 = 308, b2 = 115;
				b_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score2 > 0)
			{
				a1 = 416, a2 = 115;
				a11 = 578, a22 = 28;
				a_index = 1;
				a11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'r' || key == 'R')
		{
			if (score2 > 0)
			{
				r1 = 525, r2 = 115;
				r_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'c' || key == 'C')
		{
			if (score2 > 0)
			{
				c1 = 635, c2 = 115;
				c_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'E' || key == 'e')
		{
			if (score2 > 0)
			{
				e1 = 745, e2 = 115;
				e_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'l' || key == 'L')
		{
			if (score2 > 0)
			{
				l1 = 838, l2 = 115;
				l_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'o' || key == 'O')
		{
			if (score2 > 0)
			{
				o1 = 360, o2 = 28;
				o_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score2 > 0)
			{
				n1 = 471, n2 = 28;
				n_index = 1;
			}
		}
		else
		{
			if (score2 >= 0 && GamesettingsIndex == 0 && (b_index == 0 || a_index == 0 || a11_index == 0 || r_index == 0 || c_index == 0 || e_index == 0 || l_index == 0 || o_index == 0 || n_index == 0))
			{
				score2--;
				if (score2 == 1)
				{
					character1_index = 2;
				}
				if (score2 == 4)
				{
					character1_index = 4;
				}
				if (score2 == 3)
				{
					character1_index = 5;
				}
				if (score2 == 2)
				{
					character1_index = 6;
				}
				if (score2 == 3)
				{
					character2_index = 2;
				}
				if (score2 <= 0)
				{
					amateur_9letters_played = 1;
					bullet_index = 1;
					flag9 = 1;
				}
			}
		}
		if (score2 > 0 && (b_index == 1 && a_index == 1 && a11_index == 1 && r_index == 1 && c_index == 1 && e_index == 1 && l_index == 1 && o_index == 1 && n_index == 1))
		{
			congratulations_Index_amateur = 1;
			amateur_9letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 10)
	{
		if (GamesettingsIndex == 0 && key == 'G' || key == 'g')
		{
			if (score2 > 0)
			{
				g1 = 310, g2 = 115;
				g_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'i' || key == 'I')
		{
			if (score2 > 0)
			{
				i1 = 417, i2 = 115;
				i_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score2 > 0)
			{
				a1 = 528, a2 = 115;
				a11 = 363, a22 = 32;
				a111 = 690, a222 = 32;
				a_index = 1;
				a11_index = 1;
				a111_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score2 > 0)
			{
				n1 = 640, n2 = 115;
				n11 = 475, n22 = 32;
				n_index = 1;
				n11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 't' || key == 'T')
		{
			if (score2 > 0)
			{
				t1 = 747, t2 = 115;
				t_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'p' || key == 'P')
		{
			if (score2 > 0)
			{
				p1 = 840, p2 = 115;
				p_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'd' || key == 'D')
		{
			if (score2 > 0)
			{
				d1 = 580, d2 = 32;
				d_index = 1;
			}
		}
		else
		{
			if (score2 >= 0 && GamesettingsIndex == 0 && (g_index == 0 || i_index == 0 || a_index == 0 || a11_index == 0 || a111_index == 0 || n_index == 0 || n11_index == 0 || t_index == 0 || p_index == 0 || d_index == 0))
			{
				score2--;
				if (score2 == 1)
				{
					character1_index = 2;
				}
				if (score2 == 4)
				{
					character1_index = 4;
				}
				if (score2 == 3)
				{
					character1_index = 5;
				}
				if (score2 == 2)
				{
					character1_index = 6;
				}
				if (score2 == 3)
				{
					character2_index = 2;
				}
				if (score2 <= 0)
				{
					amateur_10letters_played = 1;
					bullet_index = 1;
					flag10 = 1;
				}
			}
		}
		if (score2 > 0 && (g_index == 1 && a_index == 1 && a11_index == 1 && i_index == 1 && a111_index == 1 && n_index == 1 && t_index == 1 && p_index == 1 && n11_index == 1 && d_index == 1))
		{
			congratulations_Index_amateur = 1;
			amateur_10letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 11)
	{
		if (GamesettingsIndex == 0 && key == 's' || key == 'S')
		{
			if (score2 > 0)
			{
				s1 = 312, s2 = 115;
				s_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'c' || key == 'C')
		{
			if (score2 > 0)
			{
				c1 = 421, c2 = 115;
				c_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'h' || key == 'H')
		{
			if (score2 > 0)
			{
				h1 = 530, h2 = 115;
				h_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'r' || key == 'R')
		{
			if (score2 > 0)
			{
				r1 = 640, r2 = 115;
				r11 = 804, r22 = 28;
				r_index = 1;
				r11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'o' || key == 'O')
		{
			if (score2 > 0)
			{
				o1 = 749, o2 = 115;
				o_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'd' || key == 'D')
		{
			if (score2 > 0)
			{
				d1 = 843, d2 = 115;
				d_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'i' || key == 'I')
		{
			if (score2 > 0)
			{
				i1 = 364, i2 = 28;
				i_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score2 > 0)
			{
				n1 = 477, n2 = 28;
				n_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'g' || key == 'G')
		{
			if (score2 > 0)
			{
				g1 = 584, g2 = 28;
				g_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score2 > 0)
			{
				e1 = 693, e2 = 28;
				e_index = 1;
			}
		}
		else
		{
			if (score2 >= 0 && GamesettingsIndex == 0 && (s_index == 0 || c_index == 0 || h_index == 0 || r_index == 0 || o_index == 0 || d_index == 0 || i_index == 0 || n_index == 0 || g_index == 0 || e_index == 0 || r11_index == 0))
			{
				score2--;
				if (score2 == 1)
				{
					character1_index = 2;
				}
				if (score2 == 4)
				{
					character1_index = 4;
				}
				if (score2 == 3)
				{
					character1_index = 5;
				}
				if (score2 == 2)
				{
					character1_index = 6;
				}
				if (score2 == 3)
				{
					character2_index = 2;
				}
				if (score2 <= 0)
				{
					amateur_11letters_played = 1;
					bullet_index = 1;
					flag11 = 1;
				}
			}
		}
		if (score2 > 0 && (s_index == 1 && c_index == 1 && h_index == 1 && r_index == 1 && r11_index == 1 && o_index == 1 && d_index == 1 && i_index == 1 && n_index == 1 && g_index == 1 && e_index == 1))
		{
			congratulations_Index_amateur = 1;
			amateur_11letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 12)
	{
		if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score3 > 0)
			{
				a1 = 310, a2 = 115;
				a_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'm' || key == 'M')
		{
			if (score3 > 0)
			{
				m1 = 420, m2 = 115;
				m_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'p' || key == 'P')
		{
			if (score3 > 0)
			{
				p1 = 530, p2 = 115;
				p_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'l' || key == 'L')
		{
			if (score3 > 0)
			{
				l1 = 638, l2 = 115;
				l_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'i' || key == 'I')
		{
			if (score3 > 0)
			{
				i1 = 749, i2 = 115;
				i_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'f' || key == 'F')
		{
			if (score3 > 0)
			{
				f1 = 843, f2 = 115;
				f_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'y' || key == 'Y')
		{
			if (score3 > 0)
			{
				y11 = 364, y2 = 28;
				y_index = 1;
			}
		}
		else
		{
			if (score3 >= 0 && GamesettingsIndex == 0 && (a_index == 0 || m_index == 0 || p_index == 0 || l_index == 0 || i_index == 0 || f_index == 0 || y_index == 0))
			{
				score3--;
				if (score3 == 1)
				{
					character1_index = 2;
				}
				if (score3 == 2)
				{
					character1_index = 5;
				}
				character2_index = 2;
				if (score3 <= 0)
				{
					intermediate_7letters_played = 1;
					bullet_index = 1;
					flag12 = 1;
				}
			}
		}
		if (score3 > 0 && (a_index == 1 && m_index == 1 && p_index == 1 && l_index == 1 && i_index == 1 && f_index == 1 && y_index == 1))
		{
			congratulations_Index_intermediate = 1;
			intermediate_7letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 13)
	{
		if (GamesettingsIndex == 0 && key == 'r' || key == 'R')
		{
			if (score3 > 0)
			{
				r1 = 307, r2 = 115;
				r_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'o' || key == 'O')
		{
			if (score3 > 0)
			{
				o1 = 417, o2 = 115;
				o_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'h' || key == 'H')
		{
			if (score3 > 0)
			{
				h1 = 526, h2 = 115;
				h_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'i' || key == 'I')
		{
			if (score3 > 0)
			{
				i1 = 635, i2 = 115;
				i_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score3 > 0)
			{
				n1 = 747, n2 = 115;
				n_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'g' || key == 'G')
		{
			if (score3 > 0)
			{
				g1 = 840, g2 = 115;
				g_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'y' || key == 'Y')
		{
			if (score3 > 0)
			{
				y11 = 360, y2 = 28;
				y_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score3 > 0)
			{
				a1 = 470, a2 = 28;
				a_index = 1;
			}
		}
		else
		{
			if (score3 >= 0 && GamesettingsIndex == 0 && (r_index == 0 || o_index == 0 || h_index == 0 || i_index == 0 || n_index == 0 || g_index == 0 || y_index == 0 || a_index == 0))
			{
				score3--;
				if (score3 == 1)
				{
					character1_index = 2;
				}
				if (score3 == 2)
				{
					character1_index = 5;
				}
				character2_index = 2;
				if (score3 <= 0)
				{
					intermediate_8letters_played = 1;
					bullet_index = 1;
					flag13 = 1;
				}
			}
		}
		if (score3 > 0 && (r_index == 1 && o_index == 1 && h_index == 1 && i_index == 1 && n_index == 1 && g_index == 1 && y_index == 1 && a_index == 1))
		{
			congratulations_Index_intermediate = 1;
			intermediate_8letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 14)
	{
		if (GamesettingsIndex == 0 && key == 's' || key == 'S')
		{
			if (score3 > 0)
			{
				s1 = 307, s2 = 115;
				s_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score3 > 0)
			{
				a1 = 415, a2 = 115;
				a_index = 1;
				a11 = 635, a22 = 115;
				a11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'n' || key == 'N')
		{
			if (score3 > 0)
			{
				n1 = 529, n2 = 115;
				n_index = 1;
				n11 = 747, n22 = 115;
				n11_index = 1;
			}
		}

		else if (GamesettingsIndex == 0 && key == 'G' || key == 'g')
		{
			if (score3 > 0)
			{
				g1 = 837, g2 = 115;
				g_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'E' || key == 'e')
		{
			if (score3 > 0)
			{
				e1 = 360, e2 = 28;
				e_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'L' || key == 'l')
		{
			if (score3 > 0)
			{
				l1 = 470, l2 = 28;
				l_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'O' || key == 'o')
		{
			if (score3 > 0)
			{
				o1 = 579, o2 = 28;
				o_index = 1;
			}
		}
		else
		{
			if (score3 >= 0 && GamesettingsIndex == 0 && (s_index == 0 || a_index == 0 || a11_index == 0 || n_index == 0 || n11_index == 0 || g_index == 0 || e_index == 0 || l_index == 0 || o_index == 0))
			{
				score3--;
				if (score3 == 1)
				{
					character1_index = 2;
				}
				if (score3 == 2)
				{
					character1_index = 5;
				}
				character2_index = 2;
				if (score3 <= 0)
				{
					intermediate_9letters_played = 1;
					bullet_index = 1;
					flag14 = 1;
				}
			}
		}
		if (score3 > 0 && (s_index == 1 && a_index == 1 && a11_index == 1 && n_index == 1 && n11_index == 1 && g_index == 1 && e_index == 1 && l_index == 1 && o_index == 1))
		{
			congratulations_Index_intermediate = 1;
			intermediate_9letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 15)
	{
		if (GamesettingsIndex == 0 && key == 's' || key == 'S')
		{
			if (score3 > 0)
			{
				s1 = 307, s2 = 115;
				s_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 't' || key == 'T')
		{
			if (score3 > 0)
			{
				t1 = 417, t2 = 115;
				t_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'r' || key == 'R')
		{
			if (score3 > 0)
			{
				r1 = 528, r2 = 115;
				r_index = 1;
				r11 = 473, r22 = 28;
				r111 = 582, r222 = 28;
				r11_index = 1;
				r111_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score3 > 0)
			{
				a1 = 635, a2 = 115;
				a_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'w' || key == 'W')
		{
			if (score3 > 0)
			{
				w1 = 747, w2 = 115;
				w_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'b' || key == 'B')
		{
			if (score3 > 0)
			{
				b1 = 840, b2 = 115;
				b_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score3 > 0)
			{
				e1 = 360, e2 = 28;
				e_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'y' || key == 'Y')
		{
			if (score3 > 0)
			{
				y11 = 689, y2 = 28;
				y_index = 1;
			}
		}

		else
		{
			if (score3 >= 0 && GamesettingsIndex == 0 && (s_index == 0 || t_index == 0 || r_index == 0 || r11_index == 0 || r111_index == 0 || a_index == 0 || w_index == 0 || b_index == 0 || e_index == 0 || y_index == 0))
			{
				score3--;
				if (score3 == 1)
				{
					character1_index = 2;
				}
				if (score3 == 2)
				{
					character1_index = 5;
				}
				character2_index = 2;
				if (score3 <= 0)
				{
					intermediate_10letters_played = 1;
					bullet_index = 1;
					flag15 = 1;
				}
			}
		}
		if (score3 > 0 && (s_index == 1 && t_index == 1 && r_index == 1 && r11_index == 1 && r111_index == 1 && a_index == 1 && w_index == 1 && b_index == 1 && e_index == 1 && y_index == 1))
		{
			congratulations_Index_intermediate = 1;
			intermediate_10letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (mainpageIndex == 16)
	{
		if (GamesettingsIndex == 0 && key == 'c' || key == 'C')
		{
			if (score3 > 0)
			{
				c1 = 312, c2 = 115;
				c_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'a' || key == 'A')
		{
			if (score3 > 0)
			{
				a1 = 420, a2 = 115;
				a_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'l' || key == 'L')
		{
			if (score3 > 0)
			{
				l1 = 529, l2 = 115;
				l_index = 1;
				l11 = 473, l22 = 30;
				l11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'v' || key == 'V')
		{
			if (score3 > 0)
			{
				v1 = 638, v2 = 115;
				v_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'i' || key == 'I')
		{
			if (score3 > 0)
			{
				i1 = 749, i2 = 115;
				i_index = 1;
				i11 = 694, i22 = 30;
				i11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'N' || key == 'n')
		{
			if (score3 > 0)
			{
				n1 = 845, n2 = 115;
				n_index = 1;
				n11 = 805, n22 = 30;
				n11_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'k' || key == 'K')
		{
			if (score3 > 0)
			{
				k1 = 363, k2 = 30;
				k_index = 1;
			}
		}
		else if (GamesettingsIndex == 0 && key == 'e' || key == 'E')
		{
			if (score3 > 0)
			{
				e1 = 585, e2 = 30;
				e_index = 1;
			}
		}
		else
		{
			if (score3 >= 0 && GamesettingsIndex == 0 && (c_index == 0 || a_index == 0 || l_index == 0 || l11_index == 0 || v_index == 0 || i_index == 0 || i11_index == 0 || n_index == 0 || n11_index == 0 || k_index == 0 || e_index == 0))
			{
				score3--;
				if (score3 == 1)
				{
					character1_index = 2;
				}
				if (score3 == 2)
				{
					character1_index = 5;
				}
				character2_index = 2;
				if (score3 <= 0)
				{
					intermediate_11letters_played = 1;
					bullet_index = 1;
					flag16 = 1;
				}
			}
		}
		if (score3 > 0 && (c_index == 1 && a_index == 1 && l_index == 1 && l11_index == 1 && v_index == 1 && i_index == 1 && i11_index == 1 && n_index == 1 && n11_index == 1 && k_index == 1 && e_index == 1))
		{
			congratulations_Index_intermediate = 1;
			intermediate_11letters_played = 1;
			character1_index = 0;
			character2_index = 0;
		}
	}
	if (nameIndex == 1)
	{
		if (key != '\b')
		{
			nameofuser[nameofuserindex] = key;
			nameofuserindex++;
			nameofuser[nameofuserindex] = '\0';
		}
		else
		{
			if (nameofuserindex > 0)
			{
				nameofuserindex--;
				nameofuser[nameofuserindex] = '\0';
			}
		}
	}
	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_UP)
	{
		y += 10;
	}
	if (key == GLUT_KEY_DOWN)
	{
		y -= 10;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		x += 10;
	}
	if (key == GLUT_KEY_LEFT)
	{
		x -= 10;
	}

}

int main()
{
	file_read();
	sprintf(score1a, "%d", score1);
	sprintf(score2a, "%d", score2);
	sprintf(score3a, "%d", score3);
	iSetTimer(1, bulletrun);
	iSetTimer(1, characterdrop);
	iSetTimer(2000, start);
	iSetTimer(3000, gamelevel);
	iInitialize(1200, 600, "Hangman Game");
	return 0;
}