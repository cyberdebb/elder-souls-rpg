#include "functions.hpp"

void Functions::ShowText(string path, int x, int y, bool hide) //printa o txt na tela
{
  path="txts\\"+path;
  ifstream myfile (path);

    if(myfile.good())
    {
      string tmp;
      while(getline(myfile,tmp))
      {
        gotoxy(x,y);
        if(hide==false)
          cout<<tmp;
        else
        {
          for(size_t i =0;i<tmp.size();i++)
          {
            cout<<" ";
          }
        }
        y++;
      }
    }
}

void Functions::gotoxy(int x, int y)
{
  COORD c;
  c.X=x;
  c.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void Functions::MenuPrincipal()
{
  Music play("play","mp3");
  system("cls");
  ShowText("logo.txt",4,2,false);
  while(true)
  {
    if(_kbhit())
    {
      // play.Seek(10);
      play.Play("wait from 0",1000);
      break;
    }
    gotoxy(45,20);
    cout<<"Press Anything to Continue";
    Esperar(500);
    gotoxy(45,20);
    cout<<"                          ";
    if(_kbhit())
    {
      play.Play("wait from 0",1000);
      break;
    }
    Esperar(1000);
  }
  cout<<endl;
  // system("cls");
}


void Functions::Esperar(int x)
{
  this_thread::sleep_for(chrono::milliseconds(x));
}
