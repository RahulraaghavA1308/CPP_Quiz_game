
void disp_choice()
  {setcolor(RED);
   settextstyle(3,0,4);
   rectangle(100,300,150,350);outtextxy(115,305,"1");
   setcolor(BLUE);
   rectangle(200,300,250,350);outtextxy(215,305,"2");
   setcolor(GREEN);
   rectangle(300,300,350,350);outtextxy(315,305,"3");
   setcolor(YELLOW);
   rectangle(400,300,450,350);outtextxy(415,305,"4");
   }
  void col_chang()
  {for(int i=2,k=0;i<9&&k<3;i++)
  {setbkcolor(i);
   delay(100);
   if(i==6)
   {i=1;
   k++;
   }
  }
  }
  void Text3D(int x, int y, int depth, int bgcolor, int fgcolor, char *caption)
{
	int i;
	setcolor(bgcolor);
	for(i=0;i<depth;i++)
		outtextxy(x+i,y+i,caption);
	setcolor(fgcolor);
	outtextxy(x+i,y+i,caption);

}

  void PPlogo()
{
    setcolor(3);
    setfillstyle(SOLID_FILL,3);
    circle(280,180,30);
    floodfill(280,180,3);

    setcolor(15);
    setfillstyle(SOLID_FILL,15);
    circle(280,180,27);
    circle(280,180,24);
    floodfill(254,180,15);

    settextstyle(1,0,4);
    outtextxy(265,160,"PP");


    setcolor(15);
    settextstyle(0,0,4);
    Text3D(100,240,2,3,11,"PIXEL PRODUCTION");
    settextstyle(0,0,2);
    Text3D(220,290,2,3,11,"Presents");
    Text3D(70,390,2,3,11,"www.pixelproductions.blogspot.in");

    settextstyle(0,0,0);

}
  void sound()
  {int i=0;
  while(i<500)
   {sound(5000+i);
    //delay(5);
    i++;
    }
    delay(100);
    nosound();
    }
    void sounder(int freq)
    {
    sound(freq);
    delay(100);
    nosound();
    }
  void Start()
{  delay(1000);
   char CCC[1];getch();
   gotoxy(35,25); gets(CCC); clrscr();cleardevice();
   if (strcmpi(CCC,"X")!=0)
   {settextstyle(0,0,4);
   Text3D(210,200,3,3,11,"Loading...");
   settextstyle(0,0,0);
   for(int i=0;i<1000;i++)
   putpixel(random(640),random(480),random(16));
   delay(4000);
   cleardevice();

   PPlogo();
   for(int l=0;l<1000;l++)
	putpixel(random(640),random(480),random(16));

   delay(5000);
   cleardevice();

   settextstyle(0,0,4);
   Text3D(230,140,3,3,11,"a game by");
    settextstyle(0,0,2);
   Text3D(250,200,2,3,11,"A.RAHUL RAAGHAV");
   Text3D(250,260,2,3,11,"S.PRASHANTH");
   Text3D(250,320,2,3,11,"PROMODH KUMAR");
   settextstyle(0,0,0);
   for(int k=0;k<1000;k++)
	putpixel(random(640),random(480),random(16));

   delay(4000);
   cleardevice();

   settextstyle(0,0,7);
   Text3D(50,150,4,3,11,"QUIZ GAME");
   settextstyle(0,0,2);
   Text3D(100,300,2,3,11,"(c) Copyright 2017 ");
   settextstyle(0,0,0);
   for(int j=0;j<2000;j++)
	putpixel(random(640),random(480),random(16));
   delay(6000); }
   cleardevice();

   }

   void backgr()
   {for(int l=0;l<1000;l++)
    putpixel(random(640),random(480),random(16));
    }