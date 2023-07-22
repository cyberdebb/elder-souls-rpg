#include "music.hpp"

Music::Music(string name, string type)
{
  m_name = name+"."+type;

  if(type == "mp3")
    type = " type mpegvideo ";
  else if(type == "wav")
    type =" type waveaudio ";
  else type = "";

  char UserPath[MAX_PATH];
  GetCurrentDirectoryA(MAX_PATH, UserPath);///Get User Path
  getpath = UserPath;//Aqui tem o diretorio do usuario

  string abrir = "open "+getpath+"\\musics\\"+m_name+ type + " alias "+ m_name;//Pra abrir arquivo
  mciSendString(abrir.c_str(),NULL,0,NULL);//Load a musica
}

void Music::Play(string metodo,int volume)
{
  m_volume = volume;

  string strvolume = "setaudio "+m_name+" volume to "+to_string(m_volume);
  mciSendString(strvolume.c_str(),NULL,0,NULL);

  string play = "play "+m_name+ " "+metodo;
  mciSendString(play.c_str(),NULL,0,NULL);
}

void Music::Funcao(string function)
{
  function = function+" "+m_name;
  mciSendString(function.c_str(),NULL,0,NULL);
}

void Music::Volume(int volume)
{
  m_volume = volume;
  string strvolume = "setaudio "+m_name+" volume to "+to_string(m_volume);
  mciSendString(strvolume.c_str(),NULL,0,NULL);
}

void Music::FadeIn(int value)
{
  while(m_volume<=value)
  {
    m_volume+=10;
    string strvolume = "setaudio "+m_name+" volume to "+to_string(m_volume);
    mciSendString(strvolume.c_str(),NULL,0,NULL);
    this_thread::sleep_for(chrono::milliseconds(30));
  }
}

void Music::FadeOut(int value)
{
  while(m_volume>=value)
  {
  m_volume-=10;
  string strvolume = "setaudio "+m_name+" volume to "+to_string(m_volume);
  mciSendString(strvolume.c_str(),NULL,0,NULL);
  this_thread::sleep_for(chrono::milliseconds(30));
  }
  if(m_volume==0)
    Funcao("close");
}

void Music::Seek(int milliseconds)
{
  string seek = "seek "+ m_name +" to "+to_string(milliseconds);
}
