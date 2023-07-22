#include "dungeon.hpp"

void Masmorra::paraFrente()
{
  m_distancia++;
}

int Masmorra::calcularNumeroProgresso()
{
  return (m_distancia*100)/m_tamanho;
}

string Masmorra::calcularProgresso()
{
  auto s=to_string(calcularNumeroProgresso());
  s+="%";
  return s;
}
