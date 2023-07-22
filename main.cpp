#include "game.hpp"
#include "functions.hpp"

int main()
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

Functions Menu;
//musicas
Music personagem("personagem","mp3");
Music maintheme("maintheme","mp3");
///////////////////////
  personagem.Play("from 0",600);
  this_thread::sleep_for(chrono::milliseconds(1000));
  Menu.MenuPrincipal();

  Game rpg(&maintheme);
  Personagem *p=rpg.chooseCharacter(); //escolhe o personagem
  vector< pair<Item*, int> > inventory; //inventario
  pair< Item*, int > pairItem;
  vector<int> todasAsFases;
  system("cls");
  personagem.FadeOut(0);

  maintheme.Play("repeat",0);
  maintheme.FadeIn(900);

  int fase=1;
  todasAsFases.push_back(fase);
  rpg.SelectFase(fase, p, inventory, pairItem);
  if(rpg.getGameOver())
  goto fail;

  loop:
  //enquanto o jogador nao quiser mudar de dungeon, seguir curso natural
  while(!rpg.getFarm(todasAsFases)){
  fase++;
  todasAsFases.push_back(fase);
  rpg.SelectFase(fase, p, inventory, pairItem);
  if(rpg.getGameOver())
  break;
  if(rpg.getfinalFight()){
    sleep(1);
    system("cls");
    maintheme.Volume(0);
    Music parabens("parabens","mp3");
    parabens.Play("from 0",800);
    Menu.ShowText("parabens.txt", 10, 2, false);
    sleep(10);
  goto endGame;}
}

fail:
  if(rpg.getGameOver()){
  cout<<"deseja tentar novamente?"<<endl;
  cout<<"Sim(1)/Nao(2)"<<endl;
  int ch;

  while(true){
    cin>>ch;
    if(ch==1){
      if(p->getVidaAtual()<0)
      p->vidaFicaPositiva();

      p->curar(p->getVidaBase() - p->getVidaAtual());
      rpg.SelectFase(fase, p, inventory, pairItem);
      goto loop;
    }
    if(ch==2){
      sleep(1);
      system("cls");
      maintheme.Volume(0);
      Music gameover("gameover","mp3");
      gameover.Play("from 0",800);
      Menu.ShowText("gameover.txt", 10, 2, false);
      sleep(10);
      goto endGame;
    }
    else{
      cout<<"Insira um valor v�lido!"<<endl;
      continue;
    }
  }
}

  if(rpg.getCloseGame()){
    cout<<"Ata a proxima!"<<endl;
    sleep(1);
    system("cls");
    Menu.ShowText("bye.txt", 10, 2, false);
    sleep(10);
    goto endGame;
  }

  fase=rpg.changeFase();
  todasAsFases.push_back(fase);
  rpg.SelectFase(fase, p, inventory, pairItem);
  goto loop;

  endGame:
  return 0;
}
