#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>

#include "game.hpp"

using namespace std;

class Functions
{

public:
  //construtores e destrutores
  Functions() {};
  ~Functions(){};

  //metodos  
  void ShowText(string path, int x, int y, bool hide);
  void gotoxy(int x, int y);
  void Esperar(int x);

  void MenuPrincipal();
};

#endif
