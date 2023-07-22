#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include "item.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Masmorra
{
protected:
  size_t m_tamanho;
  size_t m_distancia; //tanto que o personagem andou

public:
  Masmorra(int tamanho) : m_tamanho(tamanho), m_distancia(0) {};

  void paraFrente();
  size_t getTamanho() {return m_tamanho;};
  size_t getDistancia() {return m_distancia;};
  string calcularProgresso();
  int calcularNumeroProgresso();

  ~Masmorra() {};

};

#endif
