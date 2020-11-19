#include<iostream.h>          /////////////////////////
#include<string.h>            /////////////////////////
#include<graphics.h>          ////// VERSION 1.4 //////
#include<conio.h>             //TIME,QUIZ,ADMIN USAGE////
#include<dos.h>               /////////////////////////
#include<process.h>
#include<stdio.h>
#include<time.h>
#include<fstream.h>
#include<stdlib.h>
#include"FUNC.h"

 ///////////////////////////////////////////////
 /////////////GLOBAL VARIABLES/////////////////
 char addque[100];  char addop[100];    int addkey;


 //////////////////////////////////////////////

 struct QSM
 {int genre;
 char ques[250];
 char opt[100];
 int ans;
  };
  struct button
 {int A,B,C,D;};
 union REGS in,out;
  void mousedetect()
  {
  in.x.ax=0;
  int86(0x33,&in,&out);
  }
  void showmouse()
  {
  in.x.ax=1;
  int86(0x33,&in,&out);
  }
  int mouseposition(button X,button Y,button Z,button Q)
  {
  while(1)
  {int x,y;
  in.x.ax=3;
  int86(0x33,&in,&out);
  if(out.x.bx==1)
  {
  x=out.x.cx;
  y=out.x.dx;
  if(x>X.A&&x<X.B&&y>X.C&&y<X.D)
       return 1;
  else if(x>Y.A&&x<Y.B&&y>Y.C&&y<Y.D)
       return 2;
  else if(x>Z.A&&x<Z.B&&y>Z.C&&y<Z.D)
       return 3;
  else if(x>Q.A&&x<Q.B&&y>Q.C&&y<Q.D)
       return 4;
  }
  }
  }
  struct PLYDET
 {char name[20];
  char pass [10];
  int SCORE;
  }P[20];
  class QQQ
 {
// QSM [50];
 public:

 int size;
   QQQ()
   {
   size=10;}
   void fn(int&E,char a[20],int u)
  {
  PLYDET o;
  strcpy(o.name,P[E].name);
  strcpy(o.pass,P[E].pass);
  o.SCORE=0;
  cleardevice();
  setbkcolor(BLACK);
  fstream f;
  f.open(a,ios::binary|ios::in);
  randomize();
  QSM q;

  int t,s,c[30],i=0,p=0;
  for(int k=0;k<5;k++)
  {
  cleardevice();
   settextstyle(3,0,2);
   setbkcolor(BLACK);

  do
  {
  p=0;
  t=random(u);
   c[i]=t;
   for(int j=0;j<i;j++)
   if(t==c[j])
   p++;
   i++;
   }while(p!=0);
   s=t*sizeof(QSM);
   f.seekp(s);
   f.read((char*)&q,sizeof(q));

   backgr();
   settextstyle(3,0,1);
   outtextxy(15,100,q.ques);
   settextstyle(3,0,1);
   setcolor(BLUE);
   outtextxy(15,150,q.opt);
   disp_choice();
   button A={100,150,300,350};
   button B={200,250,300,350};
   button C={300,350,300,350};
   button D={400,450,300,350};
   delay(700);
   mousedetect();
   showmouse();
   int J5=0;
   J5=mouseposition(A,B,C,D);
   if (J5==q.ans)
   {
   sounder(1000);
   sounder(2000);
   //fstream g;
   //g.open("PLAYERS.dat",ios::binary|ios::in|ios::out);

   o.SCORE++;//x++;
   settextstyle(3,0,3);
   outtextxy(350,200,"RIGHT");
   col_chang();
   delay(1000);

   }
   else
   {
   sounder(3000);
   sounder(1000);
   settextstyle(3,0,3);
   outtextxy(350,200,"WRONG");
   delay(1000);
   }
   }
   f.close();
   fstream g;
   g.open("PLAYERS.dat",ios::binary|ios::in|ios::out);
   PLYDET w;
   while(g.read((char*)&w,sizeof(w)))
   {
   if(strcmpi(w.name,o.name)==0&&strcmpi(w.pass,o.pass)==0)
   break;
   }
   g.seekp(-1*sizeof(PLYDET),ios::cur);
   g.write((char*)&o,sizeof(o));
   g.close();

   }

   };
 QQQ QA,PQA,QRA;
 int ff(char a[30])
 {int s=0;
 ifstream l;
 l.open(a,ios::binary);
 QSM A;
 while(l.read((char*)&A,sizeof(A)))
 {
 s++;
 }
 l.close();
 return s;
 }
/* struct button
 {int A,B,C,D;};*/




  ///////////STRUCTURES DEFINED////////////////////
  ////////////////////////////////////////////////

  ///////////////////////////////////////////////
  //////////FUNCTION DEFINITION STARTS//////////
  void draw()
  {
  setfillstyle(4,GREEN);
  bar(0,0,639,20);
  bar(0,0,20,500);
  bar(0,460,639,500);
  bar(619,0,639,500);

  }

 /* */
  ///////////////////////////////////////////////
  //////////////FUNCTION DEFINITION ENDS/////////
  ///////////////////////////////////////////////
  void main()
  {
  ////////////GRAPHICS INITILISATION///////////////
   int gd=DETECT,gm,E=0;
   initgraph(&gd,&gm,". .//bgi") ;
   char ww[50],passs[50],pa[80]={"rpp"},ww1[80]={"rpp"},ch;
  /* ofstream paa("username.txt");
   paa.write(pa,strlen(pa));
   paa.close();
     ofstream pab("password.txt");
   pab.write(ww1,strlen(ww1));
   pab.close();*/

  ///////////////////////////////////////////////
  ///////////QUESTIONS SOURCE////////////////////
   fstream f3("general.dat",ios::binary|ios::in|ios::out);
QSM Q[10]={{0,"\n\n Question No.1 : What year did Albert Einstein die ?"," Options : 1] 1954  2] 1949  3] 1960  4] 1955 ",4},
   {0,"\n\n Question No.2 : Which is the Largest Planet in the solar system ?","  Options : 1] Jupiter  2] Neptune  3] Earth  4] Mars ",1},
   {0,"\n\n Question No.3 : How many Presidents have there been of the USA ?","  Options : 1] 36  2] 29  3] 46  4] 45 ",4},
   {0,"\n\n Question No.4 : What colour is cerulean ?","  Options : 1] Red  2] Blue  3] Yellow  4] Green ",2},
   {0,"\n\n Ouestion No.5 : What are group of Dolphines called ?","  Options : 1] school  2] Herd  3] Pod  4] Pool",3},
   {0,"\n\n Question No.6 : Who  gave 'The law of Heredity ' ?"," Options :1] Robert Hook  2] G.J.Mendal  3] Charles Darwin  4] William Harvey",2},
   {0,"\n\n Question No.7 : Name the person who was also known as Deshbandu ?"," \n Options : 1] S.Radhakrishnan  2] G.K.Gokhale  3] Chittaranjan Das  4] Madan Mohan Malviya ",3},
   {0,"\n\n Question No.8 : The Capital of Uttarakhand is...."," Options : 1] Masoorie  2] Dehra Dun  3] Nainital  4] None of these ",2},
   {0,"\n\n Question No.9 : World Trade Organization came int existence in....."," Options : 1] 1992   2] 1993   3] 1994   4] 1995 ",4},
   {0,"\n\n Question No.10 :What is the longest river on the earth ?"," Optiions : 1] Amazon River  2] Angara River  3] Nile   4] selenga River ",3}};
   f3.write((char*)&Q,sizeof(Q));
  f3.close();
 fstream f1("scienceandtech.dat",ios::binary|ios::in|ios::out);
QSM PQ[10]={{1,"\n\n Question No.1 :Which one of the following is an air to air missile ? ","Options : 1] Astra  2] Akash 3] Becquerel  4] Prithivi ",1},
   {1,"\n\n Question No.2 :The first indian satellite aryabhatta was launched in....","Options : 1] 1974  2] 1975  3] 1976  4] 1977 ",2},
   {1,"\n\n Question No.3 :Who is popularly known as missile man of India ?","Options : 1] Dr.C.V.Raman  2] Dr.S.Chandrasekhar  3] Dr.Hargobind  4] Dr.A.P.J.Abdul Kalam ",4},
   {1,"\n\n Question No.4 :Geo-stationary satellite revolves at.....","Options : 1] Any height  2] Fixed height  3] Height above pole  4] Depends on its mass ",2},
   {1,"\n\n Question No.5 :What was the name of the space shuttle that landed man on moon","Options : 1] Apollo  2] Chalenger  3] Columbia  4] Eagle ",1},
   {1,"\n\n Question No.6 :Nuclear explosive devices were tested in India at....","Options : 1] Bangalore  2] Shriharikotta  3] Kanchepuram  4] Pokharan ",4},
   {1,"\n\n Question No.7 :Pedology is the science related to the study of....","Options : 1] Atmosphere  2] Soil  3] Pollutants  4] Seeds ",2},
   {1,"\n\n Question No.8 :The first indian satellite aryabhatta was launched from....","Options : 1] Soviet Union  2] America  3] India  4] Israel ",1},
   {1,"\n\n Question No.9 :ISRO was formed in ","Options : 1] 1963  2] 1969  3] 1972  4] 1977 ",2},
   {1,"\n\n Question No.10 :The first high level programming was....","Options : 1] COBAL  2] FORTRAN  3] LISP  4] Pascal ",2}
   };
   f1.write((char*)&PQ,sizeof(PQ));
  f1.close();
    fstream f2("sports.dat",ios::binary|ios::in|ios::out);
   QSM QR[10]={{2,"\n\n Question No.1 :When was the first common Welth Games held ?","Options : 1] 1930  2] 1934  3] 1938  4] 1948 ",1},
   {1,"\n\n Question No.2 :In which sports is the participant called pugilist ?","Options : 1] Sprinter  2] Boxing  3] Wrestling  4] Javelin Throw ",2},
   {1,"\n\n Question No.3 :In which game the term putting is uded ?","Options : 1] Chess  2] Hockey  3] Golf  4] Billards ",3},
   {1,"\n\n Question No.4 :The term beamer is associated with....","Options : 1] Cricket  2] Hockey  3] Chess  4] Football ",1},
   {1,"\n\n Question No.5 :Thomas cup is reffered to....","Options : 1] Tennis  2] Cricket  3] Basketball  4] Batminton ",4},
   {1,"\n\n Question No.6 :Ryder cup is related with which sport ?","Options : 1] Cricket  2] Batminton  3] Golf  4] Football ",3},
   {1,"\n\n Question No.7 :The number of players in each side in Water Polo is","Options : 1] 6  2] 7  3] 8  4] 9 ",2},
   {1,"\n\n Question No.8 :Who is named as Flying Sikh of India ?","Options : 1] Milkha Singh  2] Joginder Singh  3] Ajith Pal  4] Mohinder ",1},
   {1,"\n\n Question No.9 :2023 Cricket world Cup would be held in","Options : 1] England  2] Australia  3] India  4] South Africa ",3},
   {1,"\n\n Question No.10 :Where did the game of chess originate ?","Options : 1] India  2] Persia  3] Arabia  4] Europe ",1}};
   f2.write((char*)&QR,sizeof(QR));
  f2.close();

   /////////QUESTIONS ENDS////////////////////{1,"\n\n Question No.7 :Pedology is the science related to the study of....","Options : 1] Atmosphere  2] Soil  3] Pollutants  4] Seeds ",2}//////////////////////////////////////////////
  highvideo();char f;
  char ch1,ch2,ch3;int op1,op2,op3;
  char p[10],USNAME[20],p1[10]; char prof[50][20];
  int z=0,t=0;
  START:
  clrscr();
   /*for(int i=60;i<=500;i++)
   {
   del  bar(i,220,30+i,240);
   }*/
 ////////////////////////////////////////////////
 ////////TIME FUNCTION///////////////////////////
   cleardevice();
   int j=1;
   while (!kbhit())
   {sound(10000);delay(50);nosound();
   //setbkcolor(I);I++;
   cleardevice();
   setbkcolor(j);j++;
   if (j>15)
   j=0;
   setcolor(WHITE);
   time_t  rawTime;
   struct tm * currentTime;
   char a[100];
   rawTime = time(NULL);
   currentTime =localtime(&rawTime);
   strftime(a, 100, "%I:%M:%S", currentTime);
   setfillstyle(1,4);
   rectangle(170,160,390,230);
  //setfillstyle(1,WHITE);
  // fillpoly(300,200);
   floodfill(300,200,WHITE);
   setcolor(11);
   settextstyle(1,0,5);
   outtextxy(190,170,a);
   strftime(a, 100, "%p", currentTime);
   settextstyle(3,0,4);
   outtextxy(400,190,a);
   strftime(a, 100, "%a, %d %b %Y", currentTime);
   settextstyle(3,0,4);
   outtextxy(130,310,a);
   delay(940);
  }
  nosound();
  cleardevice();
  setbkcolor(BLACK);

//////////////////////////////////
  Start();
////////////////////////////////////


//////////TIME FUNCTION ENDS//////////////////////
///////////////////////////////////////////////////
/* setbkcolor(BLACK);
 for(int k=0;k<320;k+=10)
 {cleardevice();
 setcolor(6+(k/10));
 settextstyle(5,0,7);
 outtextxy(70,360-k,"PIXEL");
 outtextxy(70,430-k,"PRODUCTIONS");
 //outtextxy(70,450,"PRESENTS");
 delay(100);
 }
 */
 delay(1000);

  cleardevice();                 //DRAWING BORDER
 /*draw();
 setbkcolor(WHITE);
 setcolor(RED);
 */
 //for(int rt=0;rt<1000;rt++)
// putpixel(random(640),random(480),random(16));
 backgr();
 settextstyle(7,0,4);
 Text3D(200,40,2,3,11,"QUIZ");
 settextstyle(3,0,3);
 //outtextxy(10,80,"OBJECTIVE OF THE PROJECT:");
 setcolor(BLUE);
 //setcolor(BLACK);
 Text3D(20,100,2,3,11,"OBJECTIVE OF THE PROJECT:");
 settextstyle(2,0,6);
 outtextxy(20,150,"This is a quiz game where the person is given the choice ");
 outtextxy(20,180,"to choose the topics from which he can be questioned.The ");
 outtextxy(20,210,"questions are to be answered within a time limit.The level  ");
 outtextxy(20,240,"of toughness increses as you pass rounds.Game points awarded  ");
 outtextxy(20,270,"for the right answers also depends on the toughness of  ");
 outtextxy(20,300,"the questions.Points are also Deducted for incorrect answers. ");
 outtextxy(20,330,"Finally the program displays the final score based on the   ");
 outtextxy(20,360,"overall performance.This is the best chance to test your ");
 outtextxy(20,390,"knowledge folks .Try it to check your potential.");
 getch();

 cleardevice();
/* draw();
 setbkcolor(WHITE);
 setcolor(GREEN);
 settextstyle(8,0,5);
 outtextxy(200,50,"PROJECT BY");
 setcolor(RED);
 settextstyle(1,0,3);
 outtextxy(100,150,"\3Rahul Raaghav.A");
 setcolor(RED);
 settextstyle(1,0,3);
 outtextxy(100,200,"\3Prashanth.S");
 setcolor(RED);
 settextstyle(1,0,3);
 outtextxy(100,250,"\3Pramodh kumar");
 delay(300);
 getch();
 cleardevice();
 */
 j=10;
 setbkcolor(BLACK);
   for(int rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));
 while (j<600)
 {
 j++;
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy(157,180,"loading please wait.....");
 rectangle(25,205,620,235);
 line(20+j,210,20+j,230);
 }
 backgr();
// for(rt=0;rt<1000;rt++)
//   putpixel(random(640),random(480),random(16));

/* for( int k=0;k<320;k+=10)
 {cleardevice();
 for(rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));
 //setcolor(5+(k/10));
 settextstyle(4,0,5);
 Text3D(200,240,2,3,11,"WELCOME TO");
 Text3D(200,240,2,3,11,"QUIZ COUNTDOWN");
 delay(10);
 }*/
 delay(500);
//////////////////////////////////////////////////////////////////////
 setbkcolor(WHITE);

/////////////////////////////////////////////
////////////INTRODUCTION ENDS////////////////
  M1:
  setcolor(RED);
  settextstyle(1,0,4);
  setbkcolor(BLACK);
  cleardevice();
  //setfillstyle(1,WHITE);
  for(rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));
   /* Text3D(205,140,2,3,11,"QUIZ GAME");
  rectangle(200,135,400,190);//floodfill(205,140,RED);
  button A={200,400,135,190};
  Text3D(205,290,2,3,11,"EXIT");
  rectangle(200,285,290,330);
  button B={200,290,285,330};
  button C={135,35,130,150};
  button D={205,35,130,150};*/
   Text3D(205,140,2,3,11,"QUIZ GAME ");
  settextstyle(1,0,3);
  rectangle(200,130,400,180);
  button A={200,400,130,180};
  Text3D(205,200,2,3,11,"  ADMIN  ");
  rectangle(200,190,430,240);
  button B={200,430,190,240};
  Text3D(205,260,2,3,11," EXIT   ");
  rectangle(200,255,400,300);
  button C={200,400,255,300};
  button D={200,400,310,360};
  mousedetect();
  showmouse();
  int v=0;
  v=mouseposition(A,B,C,D);
 // cout<<"\n\n\n\n"<<v;
  if(v==1)
  {
  sound();
  M2:
  cleardevice();
  for(rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));
    Text3D(205,140,2,3,11,"START GAME");
  settextstyle(1,0,3);
  rectangle(200,130,400,180);
  button A={200,400,130,180};
  Text3D(205,280,2,3,11,"INSTRUCTIONS");
  rectangle(200,275,410,315);
  button B={200,410,275,315};
  Text3D(205,340,2,3,11,"BACK TO MENU");
  rectangle(200,335,380,375);
  button C={200,380,335,375};
  button D={205,35,130,150};
  mousedetect();
  showmouse();
  int z=0;
  z=mouseposition(A,B,C,D);
  if(z==1)  /////////////START GAME/////////////
  {

  sound();
  START1:
  cleardevice();
    for(rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));

   settextstyle(1,0,3);
   setcolor(RED);
   Text3D(205,140,2,3,11,"NEW GAME");
  rectangle(200,135,330,180);
  button A={200,330,135,180};
  Text3D(205,210,2,3,11,"SAVED GAME");
   rectangle(200,205,360,250);
  button B={200,360,205,250};
  button C={135,35,130,150};
  button D={205,35,130,150};
  mousedetect();
  showmouse();
  int J4=0;
  J4=mouseposition(A,B,C,D);
  if (J4==1||J4==2)     ////////NEW/SAVEDGAME LOGIN//////
  {
  sound();
  //LOG1:

   cleardevice();

    for(rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));
   //char p1[20];
   if(J4==1)           ///////NEW GAME LOGIN
   {  Text3D(125,110,2,3,11,"ENTER NEW USER NAME");
    rectangle(125,155,300,180);
   gotoxy(1,1);
   cout<<"\n\n\n\n\n\n\n\n\n\n\t\t";
   gets(P[E].name);
     Text3D(125,190,2,3,11,"ENTER PASSWORD");

   rectangle(125,235,300,260);
   cout<<"\n\n\n\n\t\t";
   cin>>P[E].pass;

   P[E].SCORE=0;
   ofstream fout("PLAYERS.dat",ios::binary|ios::app);
   fout.write((char*)&P[E],sizeof(P[E]));
   fout.close();
   }
  else if(J4==2)
  {Text3D(125,110,2,3,11,"ENTER USER ID");
    rectangle(125,155,300,180);
   gotoxy(1,1);
   cout<<"\n\n\n\n\n\n\n\n\n\n\t\t";
   char XXX[50],YYY[20];
   gets(XXX);
     Text3D(125,190,2,3,11,"ENTER PASSWORD");

   rectangle(125,235,300,260);
   cout<<"\n\n\n\n\t\t";
   gets(YYY);
  // P[E].SCORE=0;
  ////////////
  ifstream fin("PLAYERS.dat",ios::binary);
PLYDET W;
while(fin.read((char*)&W ,sizeof(W)))
{cout<<"*"<<W.name;

if(strcmpi(W.name,XXX)==0)
  {if(strcmpi(W.pass,YYY)==0)
  {cleardevice();clrscr();
  outtextxy(200,200,"welcome player");
  outtextxy(200,250,W.name);
  delay(1000);
  getch();
  break;
  }
  else
  {outtextxy(200,200,"Incorrect password");
    getch();
    break;
    }
    }
    }//while
    //if(!(fin.read((char*)&W,sizeof(W))))
    //outtextxy(200,200,"PLAYER NOT AVAILABLE .START NEW GAME");
  fin.close();



   }
////////////////////////////////////
      /*outtextxy(125,270,"CONFIRM PASSWORD");
   rectangle(125,315,300,340);
   cout<<"\n\n\n\n\t\t";
   cin>>p1;
   rectangle(125,315,300,340);
   cout<<"\n\n\n\n\t\t";
   cin>>p1;
   if (strcmp(p,p1)!=0)
   {cout<<"\n\t\tPass word mismatch";
    goto LOG1;
   }/*/
   //////////////////////////////////////////////
   ////////////////////QUESTIONS////////////////
   //////////////////////////////////////////////
  // char x=A;
   getch();
   MMMM:
   cleardevice();
   backgr();
   Text3D(170,30,2,3,11,"Select your Desired category");
   Text3D(205,140,2,3,11,"  GENERAL  ");
  settextstyle(1,0,3);
  rectangle(200,130,400,180);
  button A={200,400,130,180};
  Text3D(205,200,2,3,11,"SCIENCE AND TECH");
  rectangle(200,190,430,240);
  button B={200,430,190,240};
  Text3D(205,260,2,3,11,"   SPORTS   ");
  rectangle(200,255,400,300);
  button C={200,400,255,300};
  Text3D(205,320,2,3,11,"BACK TO MENU");
  rectangle(200,310,400,360);
  button D={200,400,310,360};
  mousedetect();
  showmouse();
  int z=0;
  z=mouseposition(A,B,C,D);


   QQQ QA,PQA,QRA;
   if(z==1)
   {
   int h=ff("general.dat");
   sound();QA.fn(E,"general.dat",h);}
   else if(z==2)
   {
   sound();
   int H=ff("scienceandtech.dat");
   PQA.fn(E,"scienceandtech.dat",H);
   }
   else if(z==3)
   {int Y=ff("sports.dat");
   sound();QRA.fn(E,"sports.dat",Y);}
   else if(z==4)
   {sound();goto M1;}
  ///////////////////////////////////////////////
  ////////////ENDING SCREEN//////////////////////
  cleardevice();
  setbkcolor(BLACK);
  /*for( i=1;i<70;i+=5)
  {setcolor(i);
  line(10+i,10+i,630+i,10+i);line(10+i,10+i,10+i,440+i);line(10+i,440+i,630+i,440+i);line(630+i,10+i,630+i,440+i);
  line(5-i,5-i,635-i,5-i);line(5-i,5-i,5-i,445-i);line(5-i,445-i,635-i,445-i);line(635-i,5-i,635-i,445-i);delay(100);}
  setcolor(BLUE);
  settextstyle(3,0,5);
  */
  fstream k;
  k.open("PLAYERS.dat",ios::binary|ios::in|ios::out);
  PLYDET c;
  while(k.read((char*)&c,sizeof(c)));
  k.close();
  for(rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));
   Text3D(100,150,4,3,11,"CONGRADULATIONS");
   Text3D(100,220,4,3,11,"YOU SCORED");
  // x=x-65;
  char x[20],O[20];
  itoa(c.SCORE,x,10);
  outtextxy(400,220,x);

  delay(2000);
  PPPP:
  cleardevice();
   for(rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));

  setcolor(RED);
  settextstyle(3,0,2);
   Text3D(205,140,2,3,11,"TRY AGAIN");

  rectangle(200,130,400,180);
  button ABB={200,400,130,180};
   Text3D(205,280,2,3,11,"  EXIT  ");
  rectangle(200,275,410,315);
  button BBB={200,410,275,315};
   Text3D(205,340,2,3,11,"VIEW HIGHSCORES");
  rectangle(200,335,450,375);
  button CBB={200,450,335,375};
  button DBB={205,35,130,150};
  mousedetect();
  showmouse();
  int Y=mouseposition(ABB,BBB,CBB,DBB);
  if(Y==1)
 {sound(); E++;goto START1;}
  else if(Y==3)
  {
   sound();
   ifstream h;
   h.open("PLAYERS.dat",ios::binary);
   PLYDET s,t[30];
   int y=0;
   while(h.read((char*)&s,sizeof(s)))
   {
   t[y]=s;
   y++;
   }
   h.close();
  int F=E+1;
  setcolor(BLUE);
  outtextxy(200,100,"NAME");
  outtextxy(270,100,"SCORE");
  setcolor(RED);
  for(int U=0;U<y-1;U++)
  for(int L=0;L<y-1-U;L++)
  if(t[L].SCORE<t[L+1].SCORE)
  {int r=t[L].SCORE;
  strcpy(O,t[L].name);
  t[L].SCORE=t[L+1].SCORE;
  strcpy(t[L].name,t[L+1].name);
  t[L+1].SCORE=r;
  strcpy(t[L+1].name,O);
  }
  char S[20];
  int D=0;
  cleardevice();
  for(rt=0;rt<1000;rt++)
   putpixel(random(640),random(480),random(16));
  setcolor(BLUE);
  Text3D(200,100,2,3,11,"NAME");
  Text3D(270,100,2,3,11,"SCORE");
  for(U=0;U<F;U++,D+=50)
 {outtextxy(200,150+D,(t[U].name));
 itoa(t[U].SCORE,S,10);
  outtextxy(270,150+D,S);
  }
  outtextxy(200,380,"BACK TO MENU");
  rectangle(190,380,360,410);
  button AB={195,360,380,410};
  button BC={200,25,220,260};
  button CD={135,35,130,150};
  button DA={205,35,130,150};
  mousedetect();
  showmouse();
  int J1=0;
  J1=mouseposition(AB,BC,CD,DA);
  if(J1==1)
  {sound();goto PPPP;}

  }
  else if(Y==2)
  {
  sound();
  cleardevice();
  setcolor(BLUE);
 /* for( i=1;i<70;i+=5)
  {setcolor(i);
  line(10+i,10+i,630+i,10+i);line(10+i,10+i,10+i,440+i);line(10+i,440+i,630+i,440+i);line(630+i,10+i,630+i,440+i);
  line(5-i,5-i,635-i,5-i);line(5-i,5-i,5-i,445-i);line(5-i,445-i,635-i,445-i);line(635-i,5-i,635-i,445-i);delay(100);}*/
  backgr();
  setcolor(RED);
  settextstyle( 3,0,7);
  settextstyle(0,0,7);
   if (kbhit()) exit;
   Text3D(50,150,4,3,11,"T");
  delay(600);
  Text3D(105,150,4,3,11,"H");
  delay(600);
  Text3D(165,150,4,3,11,"A");
  delay(600);
  Text3D(210,150,4,3,11,"N");
  delay(600);
  Text3D(265,150,4,3,11,"K");
  delay(600);
  Text3D(310,150,4,3,11," ");
  delay(600);
  Text3D(365,150,4,3,11,"Y");
  delay(600);
  Text3D(415,150,4,3,11,"O");
  delay(600);
  Text3D(470,150,4,3,11,"U");
  delay(600);
  }
  getch();

   ////////////ENDING SCREEN ENDS////////////////
   //////////////////////////////////////////////

   }
   ////


  }
  else if(z==2)//////////////////INSTRUCTIONS/////
  {
  sound();
  cleardevice();
  backgr();
  outtextxy(15,50,"INSTRUCTIONS:");
  settextstyle(1,0,2);
  outtextxy(20,90,"This is a quiz game where the person is given the choice ");
  outtextxy(20,120,"to choose the topics from which he can be questioned.The ");

  outtextxy(20,150,"questions are to be answered within a time limit.The level  ");
  outtextxy(20,180,"of toughness increses as you pass rounds.Game points awarded  ");
  outtextxy(20,210,"for the right answers also depends on the toughness of  ");
  outtextxy(20,240,"the questions.Points are also Deducted for incorrect answers. ");
  outtextxy(20,270,"Finally the program displays the final score based on the   ");
  outtextxy(20,300,"overall performance.This is the best chance to test your ");
  outtextxy(20,330,"knowledge folks .Try it to check your potential.");
  outtextxy(200,380,"BACK TO MENU");
  rectangle(190,380,360,410);
  button A={195,360,380,410};
  button B={200,25,220,260};
  button C={135,35,130,150};
  button D={205,35,130,150};
  mousedetect();
  showmouse();
  int J1=0;
  J1=mouseposition(A,B,C,D);
  if(J1==1)
  {sound();goto M2;}
  }
  else if (z==3)
  {sound();goto M1;
  }
  }
  //////////////////admin prog///////////////////////////
  else if(v==2)
  {
  SSS:
  cleardevice();

  backgr();
   Text3D(125,110,2,3,11,"ENTER ADMIN USER NAME");

   rectangle(125,155,300,180);
   gotoxy(1,1);
   cout<<"\n\n\n\n\n\n\n\n\n\n\t\t";
   gets(ww);
   /*ifstream s,r;
   char t[80],g[80];
   s.open("username.txt");
   r.open("password.txt");
   while(s>>t);
   while(r>>g);
   s.close();
   r.close();*/
     Text3D(125,190,2,3,11,"ENTER ADMIN PASSWORD");

   rectangle(125,235,300,260);
   cout<<"\n\n\n\n\t\t";
   /*for(int ggg=0;;)
   {
   ch=getch();
   passs[ggg]=ch;
   ggg++;
   cout<<'*';
   if(ch=='\r')
   {passs[ggg]='\0';
   break;
   }


   } */
   gets(passs);
   if(strcmp(passs,pa)==0&&strcmpi(ww,ww1)==0)
   {
  SGS:
  cleardevice();
  backgr();
  Text3D(205,30,2,3,11,"ADMINISTRATOR'S PAGE");
  Text3D(205,140,2,3,11,"QUESTION SETTINGS");
  settextstyle(1,0,3);
  rectangle(200,130,400,180);
  button A={200,400,130,180};
  Text3D(205,200,2,3,11,"PLAY QUIZ");
  rectangle(200,190,430,240);
  button B={200,430,190,240};
  Text3D(205,260,2,3,11,"CHANGE PASSWORD");
  rectangle(200,255,400,300);
  button C={200,400,255,300};
  Text3D(205,320,2,3,11,"LOG OUT");
  rectangle(200,310,400,360);
  button D={200,400,310,360};
  mousedetect();
  showmouse();
  int z=0;
  z=mouseposition(A,B,C,D);
 if(z==1)
  {
  ////////////////////zz is for adding/editing/delete
  ////////////////////z  is for CATEGORIES
  cleardevice();
  backgr();
  Text3D(205,200,2,3,11,"ADD QUESTIONS");
  rectangle(200,190,430,240);
  button A={200,430,190,240};
  Text3D(205,260,2,3,11,"EDIT QUESTIONS");
  rectangle(200,255,400,300);
  button B={200,400,255,300};
  Text3D(205,320,2,3,11,"DELETE QUESTIONS");
  rectangle(200,310,400,360);
  button C={200,400,310,360};

  mousedetect();
  showmouse();
  int zz=0;
  zz=mouseposition(A,B,C,D);
  cleardevice();
   backgr();
   Text3D(170,30,2,3,11,"select the category you want to change");
   Text3D(205,140,2,3,11,"  GENERAL  ");
  settextstyle(1,0,3);
  rectangle(200,130,400,180);
  button a={200,400,130,180};
  Text3D(205,200,2,3,11,"SCIENCE AND TECH");
  rectangle(200,190,430,240);
  button b={200,430,190,240};
  Text3D(205,260,2,3,11,"   SPORTS   ");
  rectangle(200,255,400,300);
  button c={200,400,255,300};
  Text3D(205,320,2,3,11,"BACK TO MENU");
  rectangle(200,310,400,360);
  button d={200,400,310,360};
  mousedetect();
  showmouse();
  int z=0;
  z=mouseposition(a,b,c,d);
  if(zz==1)
  { //add ques

    if(z==1)
  {cleardevice();
  //addques general category

   backgr();
  outtextxy(150,150,"Enter Que to be added");
  gotoxy(5,5);
  cout<<"\n\n\n\n\n\n";
  gets(addque);
  outtextxy(150,200,"Enter the Options");
  cout<<"\n\n";

  gets(addop);
  outtextxy(150,250,"Enter the ANS KEY");
  cout<<"\n\n\n";
 do
 {
 cin>>addkey;
 }while(addkey<1&&addkey>5);
  QSM E;
  strcpy(E.ques,addque);
  strcpy(E.opt,addop);
  E.ans=addkey;
  E.genre=0;
 ofstream j;
 j.open("general.dat",ios::binary|ios::app);
 //j.seekp(-1*sizeof(QSM),ios::cur);
 j.write((char*)&E,sizeof(E));
 j.close();

 /* strcpy(Q[QA.size].ques,addque);
  strcpy(Q[QA.size].opt,addop);
  Q[QA.size].ans=addkey;
  QA.size++;*/
  goto RAH;
  }
  else if(z==2)
  {//addque science and tech
 cleardevice();
   backgr();
 outtextxy(150,150,"Enter Que to be added");
  gotoxy(5,5);
  cout<<"\n\n\n\n\n\n";
  gets(addque);
  outtextxy(150,200,"Enter the Options");
  cout<<"\n\n";

  gets(addop);
  outtextxy(150,250,"Enter the ANS KEY");
  cout<<"\n\n\n";
 do
 {
 cin>>addkey;
 }while(addkey<1&&addkey>5);
  QSM E;
  strcpy(E.ques,addque);
  strcpy(E.opt,addop);
  E.ans=addkey;
  E.genre=0;
 ofstream j;
 j.open("scienceandtech.dat",ios::binary|ios::app);
 //j.seekp(-1*sizeof(QSM),ios::cur);
 j.write((char*)&E,sizeof(E));
 j.close();
 /* strcpy(PQ[PQA.size].ques,addque);
  strcpy(PQ[PQA.size].opt,addop);
 PQ[PQA.size].ans=addkey;
  ++PQA.size;*/
  goto RAH;
  }
  else if(z==3)
  {//addque sport
   cleardevice();
   backgr();
 outtextxy(150,150,"Enter Que to be added");
  gotoxy(5,5);
  cout<<"\n\n\n\n\n\n";
  gets(addque);
  outtextxy(150,200,"Enter the Options");
  cout<<"\n\n";

  gets(addop);
  outtextxy(150,250,"Enter the ANS KEY");
  cout<<"\n\n\n";
 do
 {
 cin>>addkey;
 }while(addkey<1&&addkey>5);
   QSM E;
  strcpy(E.ques,addque);
  strcpy(E.opt,addop);
  E.ans=addkey;
  E.genre=0;
 ofstream j;
 j.open("sports.dat",ios::binary|ios::app);
// j.seekp(-1*sizeof(QSM),ios::cur);
 j.write((char*)&E,sizeof(E));
 j.close();
  /*strcpy(QR[QRA.size].ques,addque);
  strcpy(QR[QRA.size].opt,addop);
 QR[QRA.size].ans=addkey;
  ++QRA.size;*/
  goto RAH;
  }
  }//zz==1//ADD QUE
  else if(zz==2)//EDIT QUE ALL CATEGORY
  { if(z==1)
  {//GENERAL
  int FFFF;
   cleardevice(); int kkkk=0;
   backgr();
   settextstyle(1,0,1);char kk[1]="1";
   ifstream m;
   m.open("general.dat",ios::binary);
   QSM r;
   while(m.read((char*)&r,sizeof(r)))
   {
   outtextxy(100,100+kkkk,r.ques);

   outtextxy(80,100,kk);
   kkkk+=30;
   kk[0]++;
   }
   m.close();
  /* for (int i=1;i<11;i++,kkkk+=30,kk[0]++)
   {outtextxy(100,100+kkkk,Q[i-1].ques);

   outtextxy(80,100,kk);
   }*/

   gotoxy(20,20);
   cin>>FFFF;
   cleardevice();
  //addques general category

  outtextxy(150,150,"Enter MODIFIED Que ");
  gotoxy(5,5);
  cout<<"\n\n\n\n\n\n";
  gets(addque);
  outtextxy(150,200,"Enter the Options");
  cout<<"\n\n";

  gets(addop);
  outtextxy(150,250,"Enter the ANS KEY");
  cout<<"\n\n\n";
 do
 {
 cin>>addkey;
 }while(addkey<1&&addkey>5);
  QSM E;
  strcpy(E.ques,addque);
  strcpy(E.opt,addop);
  E.ans=addkey;
  E.genre=0;
 /* strcpy(Q[FFFF-1].ques,addque);
  strcpy(Q[FFFF-1].opt,addop);
  Q[FFFF-1].ans=addkey;   */
  ofstream d;
  d.open("general.dat",ios::binary|ios::ate);
  d.seekp((FFFF-1)*sizeof(QSM));
  d.write((char*)&E,sizeof(E));
  goto RAH;

   }
   else if(z==2)
  {//addque science and tech
  int FFFF;
   cleardevice(); int kkkk=0;
   settextstyle(1,0,1);char kk[1]="1";
   ifstream m;
   m.open("scienceandtech.dat",ios::binary);
   QSM r;
   while(m.read((char*)&r,sizeof(r)))
   {
   outtextxy(100,100+kkkk,r.ques);

   outtextxy(80,100,kk);
   kkkk+=30;
   kk[0]++;
   }
   m.close();
  /* for (int i=1;i<11;i++,kkkk+=30,kk[0]++)
   {outtextxy(100,100+kkkk,PQ[i-1].ques);

   outtextxy(80,100,kk);
   }*/

   gotoxy(20,20);
   cin>>FFFF;
   cleardevice();
   backgr();
  //addques general category

  outtextxy(150,150,"Enter MODIFIED Que ");
  gotoxy(5,5);
  cout<<"\n\n\n\n\n\n";
  gets(addque);
  outtextxy(150,200,"Enter the Options");
  cout<<"\n\n";

  gets(addop);
  outtextxy(150,250,"Enter the ANS KEY");
  cout<<"\n\n\n";
 do
 {
 cin>>addkey;
 }while(addkey<1&&addkey>5);
  QSM E;
  strcpy(E.ques,addque);
  strcpy(E.opt,addop);
  E.ans=addkey;
  E.genre=0;

  fstream d;
  d.open("scienceandtech.dat",ios::binary|ios::ate);
  d.seekp((FFFF-1)*sizeof(QSM));
  d.write((char*)&E,sizeof(E));
  /*strcpy(PQ[FFFF-1].ques,addque);
  strcpy(PQ[FFFF-1].opt,addop);
  PQ[FFFF-1].ans=addkey;*/
  goto RAH;

  }
  else if(z==3)
  {//addque sport
  int FFFF;
   cleardevice(); int kkkk=0;
   backgr();
   settextstyle(1,0,1);char kk[1]="1";
   ifstream m;
   m.open("sports.dat",ios::binary);
   QSM r;
   while(m.read((char*)&r,sizeof(r)))
   {
   outtextxy(100,100+kkkk,r.ques);

   outtextxy(80,100,kk);
   kkkk+=30;
   kk[0]++;
   }
   m.close();
  /* for (int i=1;i<11;i++,kkkk+=30,kk[0]++)
   {outtextxy(100,100+kkkk,QR[i-1].ques);

   outtextxy(80,100,kk);
   }*/

   gotoxy(20,20);
   cin>>FFFF;
   cleardevice();
   backgr();
  //addques general category

  outtextxy(150,150,"Enter MODIFIED Que ");
  gotoxy(5,5);
  cout<<"\n\n\n\n\n\n";
  gets(addque);
  outtextxy(150,200,"Enter the Options");
  cout<<"\n\n";

  gets(addop);
  outtextxy(150,250,"Enter the ANS KEY");
  cout<<"\n\n\n";
 do
 {
 cin>>addkey;
 }while(addkey<1&&addkey>5);
  QSM E;
  strcpy(E.ques,addque);
  strcpy(E.opt,addop);
  E.ans=addkey;
  E.genre=0;

  ofstream d;
  d.open("sports.dat",ios::binary|ios::ate);
  d.seekp((FFFF-1)*sizeof(QSM));
  d.write((char*)&E,sizeof(E));



 /*strcpy(QR[FFFF-1].ques,addque);
  strcpy(QR[FFFF-1].opt,addop);
  QR[FFFF-1].ans=addkey;*/
  goto RAH;

  }
  }
 /////////////////////
  else if(zz==3)/////delete que all category
  { if(z==1)
  {
  int FFFF;
   cleardevice(); int kkkk=0;
   backgr();
   settextstyle(1,0,1);char kk[1]="1";
   ifstream m;
   m.open("general.dat",ios::binary);
   QSM r;
   while(m.read((char*)&r,sizeof(r)))
   {
   outtextxy(100,100+kkkk,r.ques);

   outtextxy(80,100,kk);
   kkkk+=30;
   kk[0]++;
   }
   m.close();
   gotoxy(20,20);
   cin>>FFFF;
   cleardevice();
   ifstream y;
   ofstream z("temp.dat",ios::binary);
   y.open("general.dat",ios::binary);
   QSM AA;
   while(y.read((char*)&AA,sizeof(AA)))
   {
   if(y.tellg()!=(sizeof(QSM)*(FFFF)))
   {
   z.write((char*)&AA,sizeof(AA));
   }
   }
   y.close();
   z.close();
   remove("general.dat");
   rename("temp.dat","general.dat");

   goto RAH;



  //GENERAL
  }
   else if(z==2)
  {//addque science and tech
  int FFFF;
   cleardevice(); int kkkk=0;
   backgr();
   settextstyle(1,0,1);char kk[1]="1";
   ifstream m;
   m.open("scienceandtech.dat",ios::binary);
   QSM r;
   while(m.read((char*)&r,sizeof(r)))
   {
   outtextxy(100,100+kkkk,r.ques);

   outtextxy(80,100,kk);
   kkkk+=30;
   kk[0]++;
   }
   m.close();
   gotoxy(20,20);
   cin>>FFFF;
   cleardevice();
   ifstream y;
   ofstream z("temp.dat",ios::binary);
   y.open("scienceandtech.dat",ios::binary|ios::in|ios::out);
   QSM AA;
   while(y.read((char*)&AA,sizeof(AA)))
   {
   if(y.tellg()!=(sizeof(QSM)*(FFFF)))
   {
   z.write((char*)&AA,sizeof(AA));
   }
   }
   y.close();
   z.close();
   remove("scienceandtech.dat");
   rename("temp.dat","scienceandtech.dat");
   goto RAH;
  }
  else if(z==3)
  {//addque sport
  int FFFF;
   cleardevice(); int kkkk=0;
   settextstyle(1,0,1);char kk[1]="1";
   ifstream m;
   m.open("sports.dat",ios::binary);
   QSM r;
   while(m.read((char*)&r,sizeof(r)))
   {
   outtextxy(100,100+kkkk,r.ques);

   outtextxy(80,100,kk);
   kkkk+=30;
   kk[0]++;
   }
   m.close();
   gotoxy(20,20);
   cin>>FFFF;
   cleardevice();
   ifstream y;
   ofstream z("temp.dat",ios::binary);
   y.open("sports.dat",ios::binary|ios::in|ios::out);
   QSM AA;
   while(y.read((char*)&AA,sizeof(AA)))
   {
   if(y.tellg()!=(sizeof(QSM)*(FFFF)))
   {
   z.write((char*)&AA,sizeof(AA));
   }
   }
   y.close();
   z.close();
   remove("sports.dat");
   rename("temp.dat","sports.dat");
   goto RAH;
  }
   }

  }//z==1
  else if(z==2)
  {RAH:
  goto M1;
  }//z==2
  else if(z==3)
  {
  cleardevice();
  backgr();
  char na[40],paa[50],npaa[50];
  Text3D(125,110,2,3,11,"ENTER ADMIN USER NAME");

   rectangle(125,155,300,180);
   gotoxy(1,1);
   cout<<"\n\n\n\n\n\n\n\n\n\n\t\t";
   gets(na);

     Text3D(125,190,2,3,11,"ENTER EXISTING PASSWORD");

   rectangle(125,235,300,260);
   cout<<"\n\n\n\n\t\t";
   gets(paa);

   Text3D(125,270,2,3,11,"ENTER NEW PASSWORD");
   rectangle(125,315,300,340);
   cout<<"\n\n\n\n\t\t";
   gets(npaa);
   if(strcmpi(na,ww1)==0&&strcmp(pa,paa)==0)
   {strcpy(pa,npaa);
    cleardevice();
    backgr();
    outtextxy(200,190,"your password has successfully changed to");
    outtextxy(230,220,pa);
    delay(1000);
    goto SGS;

    }
    else
    {
    cleardevice();
    backgr();
    outtextxy(200,190,"SORRY! SOMETHING WENT WRONG");
    delay(500);
    goto SGS;


    }


  }//z==3
  else if(z==4)
  {
  goto M1;
  }
  }//passs
  else
  {cleardevice();backgr();outtextxy(150,190,"INCORRECT USER NAME OR PASSWORD");delay(700);goto SSS; }

		   }
  else
  if (v==3)
  {cleardevice();
  outtextxy(200,190,"SEE YOU LATER");

  }
  }
