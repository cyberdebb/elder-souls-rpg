#include "character.hpp"

void Personagem::showStatus()
{
  cout<<endl;
  cout<<"Nome: "<<m_name<<endl;
  cout<<"Sexo: "<<m_sex<<endl;
  cout<<"Classe: "<<m_nameClass<<endl;
  cout<<"Nivel: "<<m_level<<endl;
  cout<<"d"<<m_dice<<endl;
  cout<<"Vida: "<<vidaAtual<<endl;
  cout<<"Forca: "<<m_strength<<endl;
  cout<<"Resistencia: "<<m_endurance<<endl;
  cout<<"Agilidade: "<<m_agility<<endl;
  cout<<"Sorte: "<<m_luck<<endl;
  cout<<"Experiencia: "<<m_XP<<endl;
  cout<<"Ouro: "<<m_gold<<endl;

  if(m_aim!=0)
  cout<<"Mira: "<<m_aim<<endl;

  if(m_intelligence!=0)
  cout<<"Inteligencia: "<<m_intelligence<<endl;

  if(m_estilo!=0)
  cout<<"Estilo: "<<m_estilo<<endl;
}

int Personagem::getVidaAtual()
{
  if(vidaAtual>=0)
  return vidaAtual;

  else
  return 0;
}

void Personagem::aumentarXP(int &counter, vector<Inimigo*> &vecEnemies)
{
  if(counter>=5){
  aumentarStatus(); //a cada 5 inimigos mortos
  counter-=5;}
}

void Personagem::aumentarGold(int valor)
{
  m_gold+=valor;
}

void Personagem::aumentarStatus()//sobre os status do personagem
{
  cout<<"voce subiu de nivel!"<<endl;

  m_level++;
  m_life+=m_life*0.5;
  m_strength+=m_strength*0.5;
  m_endurance+=m_endurance*0.5;
  m_agility+=m_agility*0.5;
  m_luck+=m_luck*0.5;

  if(m_aim!=0)
  m_aim+=m_aim*0.5;

  if(m_intelligence!=0)
  m_intelligence+=m_intelligence*0.5;
}

void Personagem::realizarUpgrade(pair<Item*, int> &pairItem)
{
// normal-0
// forca-1
// resistencia-2
// vida-3
// agilidade-4
// sorte-5
// pocao de vida-6

  int type=pairItem.second; //realiza o upgrade do item de acordo com sua funcao

  if(type==0){
  cout<<"isso nao parece ser muito util agora"<<endl;}
  if(type==1){
  m_strength+=15;
  m_aim+=15;}
  if(type==2){
  m_endurance+=15;
  m_intelligence+=15;}
  if(type==3){
  m_life+=15;
  curar(m_life-vidaAtual);}
  if(type==4){
  m_agility+=15;}
  if(type==5){
  m_luck+=15;}
  if(type==6){
  curar(m_life-vidaAtual);}
  if(type==7){
    cout<<"agora voce esta ainda mais estiloso"<<endl;
    m_estilo++;
  }
  if(type==8){
  m_endurance+=5;
  m_strength+=5;
  m_agility+=5;
  m_intelligence+=5;
  m_aim+=5;}
  if(type==9){
  m_endurance+=m_endurance*0.5;}
  if(type==10){
    cout<<"com esta esfera, voce pode ganhar muito ouro...."<<endl;
    getch();
    cout<<"se tiver sorte"<<endl;
    cout<<"aperte qualquer botao para usa-la"<<endl;
    getch();
    int quantidadeDeMoedas=rand()%101;
    cout<<"voce ganhou "<<quantidadeDeMoedas<<" moeda(s) de ouro"<<endl;
    m_gold+=quantidadeDeMoedas;
  }
}

//cada subclasse tem uma conta diferente para o seu ataque

int Assassino::calcularAtaque()
{
  int diceDamage=(rand()%m_dice+1)/2;
  int ataque=(m_strength+m_agility)/2;
  ataque+=diceDamage;
  return ataque;
}

int Bardo::calcularAtaque()
{
  int diceDamage=(rand()%m_dice+1)/2;
  int ataque=(m_strength+m_agility+m_intelligence)/3;
  ataque+=diceDamage;
  return ataque;
}

int Barbaro::calcularAtaque()
{
  int diceDamage=(rand()%m_dice+1)/2;
  int ataque=m_strength;
  ataque+=diceDamage;
  return ataque;
}

int Arqueiro::calcularAtaque()
{
  int diceDamage=(rand()%m_dice+1)/2;
  int ataque=(m_strength+m_aim)/2;
  ataque+=diceDamage;
  return ataque;
}

int Guerreiro::calcularAtaque()
{
  int diceDamage=(rand()%m_dice+1)/2;
  int ataque=m_strength;
  ataque+=diceDamage;
  return ataque;
}

int Feiticeiro::calcularAtaque()
{
  int diceDamage=(rand()%m_dice+1)/2;
  int ataque=(m_intelligence+m_agility)/2;
  ataque+=diceDamage;
  return ataque;
}

void Personagem::tirarVida(int valor)
{
  vidaAtual-=valor;
}

void Personagem::curar(int valor)
{
  vidaAtual+=valor;
}

void Personagem::vidaFicaPositiva()
{
  vidaAtual=0;
}

void Personagem::gastarOuro(int valor)
{
  m_gold-=valor;
}
