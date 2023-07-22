#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <utility>
#include <conio.h>

#include "monsters.hpp"
#include "item.hpp"

using namespace std;

class Personagem //classe base
{
protected:
  string m_name;
  string m_sex;
  string m_nameClass;
  int m_level;
  int m_dice;
  int m_life; //vida base
  int vidaAtual; //vida atual
  int m_strength;
  int m_endurance;
  int m_agility;
  int m_luck;
  int m_aim;
  int m_intelligence;
  int m_XP;
  int m_gold;
  int m_estilo;

public:
  Personagem()
  {
    m_name="";
    m_sex="";
    m_nameClass="";
    m_level=1;
    m_dice=0;
    m_life=vidaAtual=0;
    m_strength=0;
    m_endurance=0;
    m_agility=0;
    m_luck=0;
    m_aim=0;
    m_intelligence=0;
    m_XP=0;
    m_gold=100;
    m_estilo=0;
  }
  ~Personagem() {};

  //metodos
  virtual int calcularAtaque() {return 0;}; //polimorfismo da funcao
  int calcularDefesa() {return m_endurance;};
  void showStatus();
  void aumentarXP(int &counter, vector<Inimigo*> &vecEnemies);
  void aumentarGold(int valor);
  void aumentarStatus();
  void realizarUpgrade(pair<Item*, int> &pairItem);
  void tirarVida(int valor);
  int getVidaAtual();
  int getVidaBase() {return m_life;};
  int getLuck() {return m_luck;};
  int getGold() {return m_gold;};
  int getAgility() {return m_agility;};
  void curar(int valor);
  void gastarOuro(int valor);
  void vidaFicaPositiva();

};

class Assassino :public Personagem
{
protected:

public:
  Assassino(string name, string sex, int dice, int life, int strenght, int endurance, int agility, int luck)
  {
    m_nameClass="Assassino";
    m_name=name;
    m_sex=sex;
    m_dice=dice;
    m_life=vidaAtual=life;
    m_strength=strenght;
    m_endurance=endurance;
    m_agility=agility;
    m_luck=luck;
  }
  ~Assassino() {};
  int calcularAtaque();

};
class Bardo :public Personagem
{
protected:

public:
  Bardo(string name, string sex, int dice, int life, int strenght, int endurance, int agility, int luck)
  {
    m_nameClass="Bardo";
    m_name=name;
    m_sex=sex;
    m_dice=dice;
    m_life=vidaAtual=life;
    m_strength=strenght;
    m_endurance=endurance;
    m_agility=agility;
    m_luck=luck;
    m_intelligence=4;
  }
  ~Bardo() {};
  int calcularAtaque();

};

class Barbaro :public Personagem
{
protected:

public:
  Barbaro(string name, string sex, int dice, int life, int strenght, int endurance, int agility, int luck)
  {
    m_nameClass="Barbaro";
    m_name=name;
    m_sex=sex;
    m_dice=dice;
    m_life=vidaAtual=life;
    m_strength=strenght;
    m_endurance=endurance;
    m_agility=agility;
    m_luck=luck;
  }
  ~Barbaro() {};
  int calcularAtaque();

};

class Arqueiro :public Personagem
{
protected:

public:
  Arqueiro(string name, string sex, int dice, int life, int strenght, int endurance, int agility, int luck)
  {
    m_nameClass="Arqueiro";
    m_name=name;
    m_sex=sex;
    m_dice=dice;
    m_life=vidaAtual=life;
    m_strength=strenght;
    m_endurance=endurance;
    m_agility=agility;
    m_luck=luck;
    m_aim=6;
  }
  ~Arqueiro() {};
  int calcularAtaque();

};

class Guerreiro :public Personagem
{
protected:

public:
  Guerreiro(string name, string sex, int dice, int life, int strenght, int endurance, int agility, int luck)
  {
    m_nameClass="Guerreiro";
    m_name=name;
    m_sex=sex;
    m_dice=dice;
    m_life=vidaAtual=life;
    m_strength=strenght;
    m_endurance=endurance;
    m_agility=agility;
    m_luck=luck;
  }
  ~Guerreiro() {};
  int calcularAtaque();

};

class Feiticeiro :public Personagem
{
protected:

public:
  Feiticeiro(string name, string sex, int dice, int life, int strenght, int endurance, int agility, int luck)
  {
    m_nameClass="Feiti�eiro";
    m_name=name;
    m_sex=sex;
    m_dice=dice;
    m_life=vidaAtual=life;
    m_strength=strenght;
    m_endurance=endurance;
    m_agility=agility;
    m_luck=luck;
    m_intelligence=6;
  }
  ~Feiticeiro() {};
  int calcularAtaque();

};

#endif
