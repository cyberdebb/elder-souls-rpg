#ifndef MONSTERS_HPP
#define MONSTERS_HPP

#include <iostream>
using namespace std;

class Inimigo
{
protected:
  string m_name;
  int m_dice; //randomicamente aumentar a vida do inimigo
  int m_life;
  int m_damage;
  int m_defense;
  int vidaAtual;

public:
  //construtor e destrutor
  Inimigo() {};
  ~Inimigo() {};

  int getLife() {return m_life;};
  int calcularAtaque() {return m_damage;};
  int calcularDefesa() {return m_defense;};
  void upgrade(int level); //deixa os monstros mais fortes
  void tirarVida(int valor);
  int getVidaAtual();
  string getName() {return m_name;};
};

//em seguida, as subclasses da classe Inimigo

class Rato :public Inimigo
{
protected:

public:
  Rato(int dice, int life, int damage, int defense)
  {
    m_name="Rato";
    m_dice=dice;
    m_life=vidaAtual=life;
    m_damage=damage;
    m_defense=defense;

    int upLife=rand()%m_dice+1;
    m_life+=upLife;
    vidaAtual=m_life;
  }
  ~Rato() {};

};

class Aranha :public Inimigo
{
protected:

public:
  Aranha(int dice, int life, int damage, int defense)
  {
    m_name="Aranha";
    m_dice=dice;
    m_life=vidaAtual=life;
    m_damage=damage;
    m_defense=defense;

    int upLife=rand()%m_dice+1;
    m_life+=upLife;
    vidaAtual=m_life;
  }
  ~Aranha() {};

};

class HomemLagarto :public Inimigo
{
protected:

public:
  HomemLagarto(int dice, int life, int damage, int defense)
  {
    m_name="Homem Lagarto";
    m_dice=dice;
    m_life=vidaAtual=life;
    m_damage=damage;
    m_defense=defense;

    int upLife=rand()%m_dice+1;
    m_life+=upLife;
    vidaAtual=m_life;
  }
  ~HomemLagarto() {};

};

class Orc :public Inimigo
{
protected:

public:
  Orc(int dice, int life, int damage, int defense)
  {
    m_name="Orc";
    m_dice=dice;
    m_life=vidaAtual=life;
    m_damage=damage;
    m_defense=defense;

    int upLife=rand()%m_dice+1;
    m_life+=upLife;
    vidaAtual=m_life;
  }
  ~Orc() {};

};

class Esqueleto :public Inimigo
{
protected:

public:
  Esqueleto(int dice, int life, int damage, int defense)
  {
    m_name="Esqueleto";
    m_dice=dice;
    m_life=vidaAtual=life;
    m_damage=damage;
    m_defense=defense;

    int upLife=rand()%m_dice+1;
    m_life+=upLife;
    vidaAtual=m_life;
  }
  ~Esqueleto() {};

};

class Medusa :public Inimigo
{
protected:

public:
  Medusa(int dice, int life, int damage, int defense)
  {
    m_name="Medusa";
    m_dice=dice;
    m_life=vidaAtual=life;
    m_damage=damage;
    m_defense=defense;

    int upLife=rand()%m_dice+1;
    m_life+=upLife;
    vidaAtual=m_life;
  }
  ~Medusa() {};

};

class Boss :public Inimigo
{
protected:

public:
  Boss(int dice, int life, int damage, int defense)
  {
    m_name="Durnehviir";
    m_dice=dice;
    m_life=vidaAtual=life;
    m_damage=damage;
    m_defense=defense;

    int upLife=rand()%m_dice+1;
    m_life+=upLife;
    vidaAtual=m_life;
  }
  ~Boss() {};

};

#endif
