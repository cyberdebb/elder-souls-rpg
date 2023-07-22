#include <iostream>

#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Music{

private:
string m_name;
int m_volume;
string getpath;

public:
  Music(string name, string type);
  ~Music(){};

  void Play(string metodo,int volume);
  //from 0
  //wait
  //loop
  void Funcao(string function);
  //pause
  //resume
  //close
  void Volume(int volume);

  void FadeIn(int value);
  void FadeOut(int value);

  void Seek(int milliseconds);
};
