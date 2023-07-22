#ifndef NPC_HPP
#define NPC_HPP

#include <iostream>
#include <locale.h>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include <utility>

#include "item.hpp"
using namespace std;

class Npc
{
  string m_name;
  string m_function;

public:
  //construtores
  Npc() : m_name(""), m_function("") {};
  Npc(string name, string function) : m_name(name), m_function(function) {};

  vector< pair<Item*, int> > chooseSellerItens(); //escolhe os itens do vendedor

  ~Npc() {};

};

#endif
