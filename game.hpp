#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <locale.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <conio.h>
#include <algorithm>
#include <unistd.h>

#include "character.hpp"
#include "monsters.hpp"
#include "dungeon.hpp"
#include "item.hpp"
#include "npc.hpp"
#include "music.hpp"

using namespace std;

class Game
{
private: //declaracao de variaveis de controle
  pair< Item*, int > Info;
  bool m_compra;
  int m_accuracy;
  bool m_farm;
  int newFase;
  bool m_endBattle;
  bool m_gameover;
  bool m_run;
  bool m_closeGame;
  bool m_finalFight;

  //instanciacao de classes dinamicas
  Personagem *personagem;
  Inimigo *inimigo;
  Masmorra *masmorra;
  Item *item;
  Npc *npc;

  //musicas
  Music *Maintheme;
  Music *Luta = new Music("luta","mp3");


public:
  Game() : Info(NULL, 0), m_closeGame(false), newFase(0), m_farm(false), m_compra(true), m_accuracy(0), m_gameover(false),
  m_finalFight(false), m_endBattle(false), m_run(false), personagem(NULL), inimigo(NULL), masmorra(NULL), item(NULL), npc(NULL), Maintheme(NULL) {};

  Game(Music *mainmusic) : Info(NULL, 0), m_closeGame(false), newFase(0), m_farm(false), m_compra(true), m_accuracy(0), m_gameover(false),
  m_finalFight(false), m_endBattle(false), m_run(false), personagem(NULL), inimigo(NULL), masmorra(NULL), item(NULL), npc(NULL), Maintheme(mainmusic) {};

  //setters das classes dinamicas
  vector<Inimigo*> criarVetorInimigos(int intensificador, int quantidade);
  Personagem* chooseCharacter();
  Inimigo* chooseEnemie();
  Masmorra* chooseDungeon(int fase);
  Npc* chooseNpc();

  pair< Item*, int > chooseItem(); //para o bau
  pair< Item*, int > buyItem(); //para o comerciante

  //metodos
  void showMenu();
  int rollDice(int dice);
  bool getFarm(vector<int> todasAsFases);
  bool getCloseGame() {return m_closeGame;};
  int changeFase();
  int agilityCheck();
  bool getfinalFight() {return m_finalFight;};
  bool getBuying() {return m_compra;};
  bool getGameOver() {return m_gameover;};
  bool getEndBattle() {return m_endBattle;};
  bool getRun() {return m_run;};
  void bossFight(Inimigo *boss, vector< pair<Item*, int> > &inventory);
  void fight(int &kills, vector<Inimigo*> &vecEnemies, vector< pair<Item*, int> > &inventory, vector<int> &killedMonsters);
  void fireplace();
  bool dungeonProgress(Masmorra *m);
  bool checkLife();
  bool checkEnemiesLife(int &kills, vector<Inimigo*> &vecEnemies, vector<int> &killedMonsters);
  vector<bool> changeOdds(int fase);
  void SelectFase(int fase, Personagem *p, vector< pair<Item*, int> > &inventory, pair< Item*, int > pairItem);


};

#endif
