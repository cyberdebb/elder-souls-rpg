#include "npc.hpp"

vector< pair<Item*, int> > Npc::chooseSellerItens()
{
  srand(time(NULL));

  int k=0;
  int random, random1, random2, random3;

  pair<Item*, int> Info;
  vector< pair<Item*, int> > todosOsItens; //define todos os itens disponiveis

redo:
  while(true){
  random=rand()%5+1; //escolhe itens aleatorios
  if(random==1)
  {
    Info.first= new Item("Pote de vida"); //cura
    Info.second=6;

    todosOsItens.push_back(Info);
  }
  else if(random==2)
  {
    Info.first= new Item("Chapeu Runico"); //resistencia
    Info.second=7;

    todosOsItens.push_back(Info);
  }
  else if(random==3)
  {
    Info.first= new Item("Vitamina do heroi"); //vida
    Info.second=8;

    todosOsItens.push_back(Info);
  }
  else if(random==4)
  {
    Info.first= new Item("Anel de Espinhos"); //aumenta a defesa em 50%
    Info.second=9;

    todosOsItens.push_back(Info);
  }
  else if(random==5)
  {
    Info.first= new Item("Esfera do Milhao"); //voce pode ganhar moedas
    Info.second=10;

    todosOsItens.push_back(Info);
  }

  if(k==0)
  random1=random;
  if(k==1){
  random2=random;
  if(random2==random1){
  todosOsItens.erase(todosOsItens.begin()+k);
  goto redo;}
  }
  if(k==2){
  random3=random;
  if(random3==random2 || random3==random1){
  todosOsItens.erase(todosOsItens.begin()+k);
  goto redo;}
  }
  //garante que os itens sejam diferentes entre si

  k++;
  if(k==3)
  break;
  }

  return todosOsItens;
}

//personagem vai escolher um dos itens do vendedor (que vai oferecer 3 deles) e comprar com moedas de ouro
