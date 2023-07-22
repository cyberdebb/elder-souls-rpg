#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
using namespace std;

class Item
{
  string m_name;
  int m_tipoUpgrade;

public:
  Item() : m_name(""), m_tipoUpgrade(0) {};
  Item(string name) : m_name(name), m_tipoUpgrade(0) {};

  string getItemName() {return m_name;};
  int getTipoUpgrade() {return m_tipoUpgrade;};

  ~Item() {};

  friend class Game; //da certas permissões para a classe Game
};

#endif
