ifstream fin("PLAYERS.dat)
PLYDET W;
while(fin.read((char*)&W,sizeof(W)))
{ if(strcmp(W.name,P[E].name)==0)
  {if(strcmp(W.pass,p[E].pass)==0)
  {outtextxy(200,200,"welcome player");
  outtextxy(200,250,W.name);
  break();
  }
  else
  {outtextxy(200,200,"Incorrect password");
    break();
    }
    }
    }//while
    if(!(fin.read((char*)&W,sizeof(W))))
    outtextxy(200,200,"PLAYER NOT AVAILABLE .START NEW GAME");
  fin.close();

////////////////////////////////////
 ifstream fin("PLAYERS.dat",ios::binary)
 PLYDET A[100];int i=0;
 while(fin.read((char)*W,sizeof(W)))
 {A[i]=W;
 i++;
 }
 fin.close();
 ofstream fout("TEMP.dat",ios::binary)
 while(SIZE>=0)
 {
 fout.write((char)*A[i],sizeof(A[i]))
 i++;
 Size--;
 }
 fout.close();
 remove("PLAYERS.dat")
 rename("TEMP.dat","PLAYERS.dat");

 }



