#include "monsters.hpp"

int Inimigo::getVidaAtual()
{
  if(vidaAtual>=0)
  return vidaAtual;

  else
  return 0; //garante que a vida nunca seja negativa
}

void Inimigo::upgrade(int level)
{
  int n = level-1;
  m_life+=m_life*(0.4*n);
  m_damage+=m_damage*(0.4*n);
}

void Inimigo::tirarVida(int valor)
{
  vidaAtual-=valor;
}
