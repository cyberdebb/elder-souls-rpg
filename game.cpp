#include "game.hpp"

bool Game::getFarm(vector<int> todasAsFases) //pergunta ao jogador se ele quer mudar de fase
{
  if(!dungeonProgress(masmorra)){
  cout<<"\nParabéns por tem passado por esta dungeon!"<<endl; //dar premios!
  personagem->aumentarStatus();}

  sleep(1);

  int choice;
  choice:
  system("cls");
  cout<<endl;
  cout<<"o que voce deseja fazer?"<<endl;
  cout<<"1 - Ir para a proxima dungeon"<<endl;
  cout<<"2 - Votar para uma dungeon"<<endl;
  cout<<"3 - Sair do jogo"<<endl;

  while(true)
  {
    cin>>choice;

    if(choice==1)
    {
      cout<<"perfeito.. entao vamos seguir em frente!"<<endl;
      return false;
    }

    else if(choice==2)
    {
      int ch;

      chooseAgain:
      cout<<endl;
      cout<<"para qual dungeon voce quer voltar?"<<endl;
      cout<<"1 - Masmorra dos bebes choroes"<<endl;
      cout<<"2 - Masmorra de gente grande"<<endl;
      cout<<"3 - Masmorra onde o filho chora e a mae nao ve"<<endl;
      cout<<"4 - BOSS FINAL"<<endl;

      while(true)
      {
        cin>>ch;

      if(ch > *max_element(todasAsFases.begin(), todasAsFases.end())){
        //se a fase esolhida for maior que qualquer fase que o jogador ja passou
        cout<<"voce ainda nao passou por essa fase ainda!"<<endl;
        system("cls");
        goto chooseAgain;
      }

      else{
        if(ch==1){
        newFase=1;
        break;}
        else if(ch==2){
        newFase=2;
        break;}
        else if(ch==3){
        newFase=3;
        break;}
        else if(ch==4){
        newFase=4;
        break;}
        else{
        cout<<"Insira um valor valido!"<<endl;
        continue;}
      }
      }

      return true;
    }

    else if(choice==3){
    m_closeGame=true;
    return true;}

    else{
    cout<<"Insira um valor valido!"<<endl;
    continue;}
  }
}

int Game::changeFase()
{
  m_farm=false;
  return newFase;
}

Personagem* Game::chooseCharacter()
{
  setlocale(LC_ALL, "Portuguese");
  int ch, escolhaPersonagem;
  string name, sex;
  int sexNumber;

  cout<<"Escolha a classe do(a) personagem:"<<endl;
  cout<<"1. Assassino"<<endl;
  cout<<"2. Bardo"<<endl;
  cout<<"3. Barbaro"<<endl;
  cout<<"4. Arqueiro"<<endl;
  cout<<"5. Guerreiro"<<endl;
  cout<<"6. Feiticeiro"<<endl;

  while(true){
  cin>>ch;
  if(ch>=1 && ch<=6){
  escolhaPersonagem=ch;
  break;}
  else{
  cout<<"Insira um valor valido!"<<endl;
  continue;}
  }

  cout<<"\nEscolha o nome do(a) personagem:"<<endl;
  while(getline(cin, name)) //recebe a mensagem escrita pelo usuario
   if(name != ""){ //limpar o buffer para usar o getline
          break;
    }

  cout<<"\nEscolha o sexo do(a) personagem:"<<endl;
  cout<<"1. Masculino"<<endl;
  cout<<"2. Feminino"<<endl;

  while(true){
  cin>>sexNumber;
  if(sexNumber==1){
  sex="Masculino";
  break;}
  else if(sexNumber==2){
  sex="Feminino";
  break;}
  else{
  cout<<"Insira um valor valido!"<<endl;
  continue;}
  }

  //nome, sexo, dado, vida, forca, resistencia, agilidade, sorte

  if(escolhaPersonagem==1)
  personagem = new Assassino(name, sex, 12, 25, 5, 6, 8, 9);
  else if(escolhaPersonagem==2)
  personagem = new Bardo(name, sex, 10, 25, 5, 6, 8, 9);
  else if(escolhaPersonagem==3)
  personagem = new Barbaro(name, sex, 30, 25, 5, 6, 8, 9);
  else if(escolhaPersonagem==4)
  personagem = new Arqueiro(name, sex, 16, 25, 5, 6, 8, 9);
  else if(escolhaPersonagem==5)
  personagem = new Guerreiro(name, sex, 20, 25, 5, 6, 8, 9);
  else if(escolhaPersonagem==6)
  personagem = new Feiticeiro(name, sex, 6, 25, 5, 6, 8, 9);

  return personagem;
}

Inimigo* Game::chooseEnemie()
{
  srand (time(NULL));
  int random=rand()%6;

  //dado, vida, dano, defesa

  if(random==0)
  inimigo = new Rato(5, 1, 7, 1);
  else if(random==1)
  inimigo = new Aranha(10, 30, 8, 2);
  else if(random==2)
  inimigo = new HomemLagarto(10, 10, 9, 3);
  else if(random==3)
  inimigo = new Orc(15, 15, 9, 4);
  else if(random==4)
  inimigo = new Esqueleto(20, 25, 11, 3);
  else if(random==5)
  inimigo = new Medusa(20, 40, 13, 4);

  return inimigo;
}

Masmorra* Game::chooseDungeon(int fase) //declara o tamanho das masmorras
{
  if(fase==1)
  masmorra = new Masmorra(4);
  if(fase==2)
  masmorra = new Masmorra(8);
  if(fase==3)
  masmorra = new Masmorra(16);
  if(fase==4)
  masmorra = new Masmorra(1);

  return masmorra;
}

pair< Item*, int > Game::chooseItem() //escolhe o item do bau
{
  int quantidadeDeMoedas=0;
  int random1=rollDice(20);
  int luckyDT=(personagem->getLuck()/2)+2.5; //minimo para o item do bau ser util

  if(random1<luckyDT){
    int random2=rand()%6+1;
    if(random2==1)
    {
      Info.first= new Item("Uma pedra");
      Info.second=0;
    }
    else if(random2==2)
    {
      Info.first= new Item("Um graveto");
      Info.second=0;
    }
    else if(random2==3)
    {
      Info.first= new Item("Uma latinha de refrigerante?");
      Info.second=0;
    }
    else if(random2==4)
    {
      Info.first= new Item("Uma vassoura");
      Info.second=0;
    }
    else if(random2==5)
    {
      Info.first= new Item("Um jacare de pelucia");
      Info.second=0;
    }
    else if(random2==6)
    {
      Info.first= new Item("UM CABRITO!");
      Info.second=0;
    }
}

  if(random1>=luckyDT){
    int random3=rand()%6+1;
    if(random3==1)
    {
    quantidadeDeMoedas=rand()%100+1;
    Info.first= new Item("Moedas de ouro");
    Info.second=0;
    personagem->aumentarGold(quantidadeDeMoedas);
    }
    else if(random3==2)
    {
      Info.first= new Item("Amuleto Elfico"); //forca
      Info.second=1;
    }
    else if(random3==3)
    {
      Info.first= new Item("Cinto de Mithril"); //resistencia
      Info.second=2;
    }
    else if(random3==4)
    {
      Info.first= new Item("Fada em um pote"); //vida
      Info.second=3;
    }
    else if(random3==5)
    {
      Info.first= new Item("Bracelete da Aguia"); //agilidade
      Info.second=4;
    }
    else if(random3==6)
    {
      Info.first= new Item("Anel da Sorte"); //sorte
      Info.second=5;
    }
}
  Music bau("bau","mp3");
  Maintheme->Volume(50);
  bau.Play("wait from 0",700);
  cout<<"voce encontrou "<<Info.first->getItemName()<<endl;

  if(quantidadeDeMoedas==0){
  cout<<"item adicionado ao inventario"<<endl;}
  else{
  cout<<quantidadeDeMoedas<<" moedas foram adicionadas ao seu inventario!"<<endl;}
  Maintheme->FadeIn(700);
  return Info; //par item e utilidade
}

pair< Item*, int > Game::buyItem()
{
  vector< pair<Item*, int> > sellerItens;
  pair<Item*, int> pairItens;
  sellerItens = npc->chooseSellerItens();
  //se for um vendedor, oferece um vector de itens para pegar que custam certo dinheiro

  int escolha;
  int i;
  int preco;
  vector<int> precos;
  cout<<"estes sao os itens que ele tem disponiveis!"<<endl;

  for(i=0; i<sellerItens.size(); i++)
  {
    preco=rand()%30+20;
    precos.push_back(preco);
    cout<<i+1<<" -> "<<sellerItens.at(i).first->getItemName()<<" por "<<precos.at(i)<<" ouros"<<endl;
  }

  cout<<i+1<<" -> "<<"Nao comprar nada"<<endl<<endl;

  chooseagain:
  cout<<"qual voce quer comprar?"<<endl; //limitar dinheiro
  cin>>escolha;
  escolha--;

  if(escolha==3){
    cout<<"tudo bem!"<<endl;
    pairItens.first=NULL;
    pairItens.second=0;
    m_compra=false; //se a compra nao foi feita
  }

  else if(precos.at(escolha) > personagem->getGold()){ //dinheiro nao suficiente
  cout<<"voce nao tem dinheiro o suficiente!"<<endl;
  goto chooseagain;}

  else{
  personagem->gastarOuro(precos.at(escolha)); //compra
  pairItens=sellerItens.at(escolha);}

  return pairItens;
}

vector<Inimigo*> Game::criarVetorInimigos(int intensificador, int quantidade)
{
  vector<Inimigo*> vetor;

  for(int i=0; i<quantidade; i++)
  {
    Inimigo *enemie=chooseEnemie();
    this_thread::sleep_for(chrono::milliseconds(1000));
    enemie->upgrade(intensificador);
    vetor.push_back(enemie);
    cout<<"-> "<<vetor.at(i)->getName()<<endl;
  }
  this_thread::sleep_for(chrono::milliseconds(500));
  return vetor;
}

int Game::rollDice(int dice) //rola o dado
{
  srand(time(NULL));
  int random=rand()%dice+1;
  cout<<"aperte qualquer tecla para jogar o d"<<dice<<endl;
  getch();
  cout<<endl;

cout<<"   _______"<<endl;
cout<<"  /\\ o o o\\ "<<endl;
cout<<" /o \\ o o o\\______"<<endl;
cout<<"<    >------>   o /|"<<endl;
cout<<" \\ o/  o   /_____/o|"<<endl;
cout<<"  \\/______/     |oo|"<<endl;
cout<<"        |   o   |o/"<<endl;
cout<<"        |_______|/"<<endl;

  cout<<endl;
  cout<<"o resultado deu "<<random<<endl;
  return random;
}

int Game::agilityCheck() //checa se o jogador passa no teste de agilidade
{
  int accuracy=rollDice(20);
  int result=(accuracy*personagem->getAgility())/20; //mudando a base
  int test;

  if(result>=personagem->getAgility()*0.8 && result<=personagem->getAgility()*1) //muito bom - 3
  test=3;
  if(result>=personagem->getAgility()*0.50 && result<personagem->getAgility()*0.80) //bom - 2
  test=2;
  if(result>=personagem->getAgility()*0.25 && result<personagem->getAgility()*0.50) //normal - 1
  test=1;
  if(result<personagem->getAgility()*0.25) //falha -0
  test=0;

  return test;
}

bool Game::checkLife()
{
  if(personagem->getVidaAtual()<=0){
  cout<<"voce morreu..."<<endl<<endl;
  m_gameover=true;
  return false;} //false se o personagem estiver morto;

  else
  return true; //true se o personagem estiver vivo
}

bool Game::checkEnemiesLife(int &kills, vector<Inimigo*> &vecEnemies, vector<int> &killedMonsters)
{
  for(int i=0; i<vecEnemies.size(); i++)
  {
    if(vecEnemies.at(i)->getVidaAtual()<=0 && killedMonsters.at(i)==0){
    killedMonsters.at(i)=1;
    kills++;}

      if(vecEnemies.size()==kills){
      m_endBattle=true;
      kills=0;
      return false; //false se todos os inimigos tiverem morrido
    }
  }
  return true; //true se ainda tiver no minimo um montro vivo
}

void Game::bossFight(Inimigo *boss, vector< pair<Item*, int> > &inventory)
{
  Maintheme->Volume(10);
  Luta->Play("repeat",400);

  int choice;
  bossMenu:
  system("cls");
  cout<<endl;
  cout<<"o que deseja fazer?"<<endl;
  cout<<"1. Atacar"<<endl;
  cout<<"2. Bloquear"<<endl;
  cout<<"3. Checar inventario"<<endl;

  while(true){
    cin>>choice;

  if(choice==1){
    int result=agilityCheck();

    if(result<=1){
    //se vc falhar no teste, o inimigo te ataca
    cout<<"voce falhou no teste e o inimigo acerta o golpe!"<<endl<<endl;

    cout<<"o(a) "<<boss->getName()<<" te ataca!"<<endl<<endl;
    cout<<"sua vida atual: "<<personagem->getVidaAtual()<<endl;

    int dano_no_personagem=boss->calcularAtaque() - personagem->calcularDefesa();

    if(dano_no_personagem<0)
    dano_no_personagem=0;

    cout<<"dano recebido: "<<dano_no_personagem<<endl;
    personagem->tirarVida(dano_no_personagem);

    cout<<"sua vida depois do ataque: "<<personagem->getVidaAtual()<<endl;

    if(!checkLife()){
    goto boosFinal;}

    cout<<endl<<"agora eh sua vez de atacar: "<<endl;
    goto bossSuaVez;}

    if(result>1){ //se vc passar no teste
  cout<<"voce passou no teste e o inimigo erra o golpe!"<<endl<<endl;

  bossSuaVez:
  int hits=agilityCheck();
  cout<<"voce consegue acertar "<<hits<<" vez(es) o(s) inimigo(s)"<<endl;

  if(hits==0){
  goto boosFinal;}

  //agora o personagem ataca
  for(int i=0;i<hits;i++){
    cout<<endl<< "voce tem "<<hits-i<<" ataque(s) restante(s)"<<endl<<endl;

    cout<<"pressione qualquer botao para atacar!"<<endl;
    getch();

    cout<<"-> "<<boss->getName()<<" / vida: "<<boss->getVidaAtual()<<endl;

    cout<<endl;
    cout<<"vida atual do inimigo: "<<boss->getVidaAtual()<<endl;

    int dano_no_inimigo=personagem->calcularAtaque() - boss->calcularDefesa();

    if(dano_no_inimigo<0)
    dano_no_inimigo=0;

    cout<<"dano causado: "<<dano_no_inimigo<<endl;

    boss->tirarVida(dano_no_inimigo);

    cout<<"vida do inimigo depois do ataque: "<<boss->getVidaAtual()<<endl;

    if(!checkLife()){
    goto boosFinal;}

    if(boss->getVidaAtual()<=0){
    goto boosFinal;}
  }}
  break;}

  else if(choice==2){
    int random = rollDice(20);

    if(random>=10){
    cout<<"voce bloqueia os ataques do inimigo"<<endl;}

    else{

    cout<<"voce nao consegue bloquear"<<endl;
    int dano_no_personagem=personagem->calcularAtaque() - boss->calcularDefesa();

    if(dano_no_personagem<0)
    dano_no_personagem=0;

    cout<<"dano recebido: "<<dano_no_personagem<<endl;

    personagem->tirarVida(dano_no_personagem);

    cout<<"sua vida depois do ataque: "<<personagem->getVidaAtual()<<endl;

    if(!checkLife()){
    goto boosFinal;}
    }
    break;
  }

  else if(choice==3){
    int itemNumber;

    cout<<endl;

    if(inventory.size()==0)
    cout<<"voce nao tem itens"<<endl;

    else{
    for(int i=0; i<inventory.size(); i++)
    {
      cout<<i+1<<" -> "<<inventory.at(i).first->getItemName()<<endl;
    }
    cout<<endl;

    int usarBau;
    cout<<"deseja usar algum item?"<<endl;
    cout<<"(1)Sim/(2)Nao"<<endl;

    while(true){
      cin>>usarBau;
      if(usarBau==1){
        cout<<"qual?"<<endl;
        cin>>itemNumber;
        itemNumber--;
        personagem->realizarUpgrade(inventory.at(itemNumber)); //realiza o upgrade
        inventory.erase(inventory.begin()+itemNumber);
        break;
      }
      if(usarBau==2){
        goto bossMenu;
      }
      else{
        cout<<"Insira um valor valido!"<<endl;
        continue;
      }
    }
  }
  break;
  }

  else{
    cout<<"Insira um valor valido!"<<endl;
    continue;}
  }
    boosFinal:;
}

void Game::fight(int &kills, vector<Inimigo*> &vecEnemies, vector< pair<Item*, int> > &inventory, vector<int> &killedMonsters)
{
  Maintheme->Volume(10);

  Luta->Play("repeat",400);
  int random, choice;
  int monsterHIT;
  int aliveMonster;

  for(int i=0; i<vecEnemies.size(); i++)
  {
    if(vecEnemies.at(i)->getVidaAtual()>0)
    aliveMonster=i; //o ultimo monstro vivo
  }

menu:
cout<<endl;
cout<<"o que deseja fazer?"<<endl;
cout<<"1. Atacar"<<endl;
cout<<"2. Bloquear"<<endl;
cout<<"3. Checar inventario"<<endl;
cout<<"4. Fugir"<<endl;

while(true){
  cin>>choice;

if(choice==1){
  int result=agilityCheck();

  if(result<=1){
  //se vc falhar no teste, o inimigo te ataca
  cout<<"voce falhou no teste e o inimigo acerta o golpe!"<<endl<<endl;

  cout<<"o(a) "<<vecEnemies.at(aliveMonster)->getName()<<" te ataca!"<<endl<<endl;
  cout<<"sua vida atual: "<<personagem->getVidaAtual()<<endl;

  int dano_no_personagem=vecEnemies.at(aliveMonster)->calcularAtaque() - personagem->calcularDefesa();

  if(dano_no_personagem<0)
  dano_no_personagem=0;

  cout<<"dano recebido: "<<dano_no_personagem<<endl;
  personagem->tirarVida(dano_no_personagem);

  cout<<"sua vida depois do ataque: "<<personagem->getVidaAtual()<<endl;

  if(!checkLife()){
  goto final;}

  cout<<endl<<"agora eh sua vez de atacar: "<<endl;
  goto suaVez;}

  if(result>1){ //se vc passar no teste
cout<<"voce passou no teste e o inimigo erra o golpe!"<<endl<<endl;

suaVez:
int hits=agilityCheck();
cout<<"voce consegue acertar "<<hits<<" vez(es) o(s) inimigo(s)"<<endl;

if(hits==0){
goto final;}

//agora o personagem ataca
for(int i=0;i<hits;i++){
  cout<<endl<< "voce tem "<<hits-i<<" ataque(s) restante(s)"<<endl<<endl;

  for(int j=0; j<vecEnemies.size();j++){
    cout<<j+1<<" -> "<<vecEnemies.at(j)->getName()<<" / vida: "<<vecEnemies.at(j)->getVidaAtual()<<endl;
  }

  chooseAgain:
  cout<<endl<<"deseja acertar qual?"<<endl;
  cin>>monsterHIT;
  monsterHIT--;

  if(monsterHIT>vecEnemies.size() && monsterHIT<1){
  cout<<"escolha um monstro valido"<<endl;
  goto chooseAgain;}

  if(vecEnemies.at(monsterHIT)->getVidaAtual()<=0){
  cout<<"este monstro ja esta morto"<<endl;
  goto chooseAgain;}

  cout<<endl;
  cout<<"vida atual do inimigo: "<<vecEnemies.at(monsterHIT)->getVidaAtual()<<endl;

  int dano_no_inimigo=personagem->calcularAtaque() - vecEnemies.at(monsterHIT)->calcularDefesa(); //nao ta pegando o dano da classe

  if(dano_no_inimigo<0)
  dano_no_inimigo=0;

  cout<<"dano causado: "<<dano_no_inimigo<<endl;

  vecEnemies.at(monsterHIT)->tirarVida(dano_no_inimigo);

  cout<<"vida do inimigo depois do ataque: "<<vecEnemies.at(monsterHIT)->getVidaAtual()<<endl;

  if(!checkLife()){
  goto final;}

  if(!checkEnemiesLife(kills, vecEnemies, killedMonsters)){
  goto final;}
}}
break;}

else if(choice==2){
  int random = rollDice(20);

  if(random>=10){
  cout<<"voce bloqueia os ataques do inimigo"<<endl;}

  else{

  cout<<"voce nao consegue bloquear"<<endl;
  int dano_no_personagem=personagem->calcularAtaque()-vecEnemies.at(aliveMonster)->calcularDefesa();

  if(dano_no_personagem<0)
  dano_no_personagem=0;

  cout<<"dano recebido: "<<dano_no_personagem<<endl;

  personagem->tirarVida(dano_no_personagem);

  cout<<"sua vida depois do ataque: "<<personagem->getVidaAtual()<<endl;

  if(!checkLife()){
  goto final;}
  }
  break;
}

else if(choice==3){
  int itemNumber;

  cout<<endl;

  if(inventory.size()==0)
  cout<<"voce nao tem itens"<<endl;

  else{
  for(int i=0; i<inventory.size(); i++)
  {
    cout<<i+1<<" -> "<<inventory.at(i).first->getItemName()<<endl;
  }
  cout<<endl;

  int usarBau;
  cout<<"deseja usar algum item?"<<endl;
  cout<<"(1)Sim/(2)Nao"<<endl;

  while(true){
    cin>>usarBau;
    if(usarBau==1){
      cout<<"qual?"<<endl;
      cin>>itemNumber;
      itemNumber--;
      personagem->realizarUpgrade(inventory.at(itemNumber)); //dizer oq mudou
      inventory.erase(inventory.begin()+itemNumber);
      break;
    }
    if(usarBau==2){
      goto menu;
    }
    else{
      cout<<"Insira um valor valido!"<<endl;
      continue;
    }
  }
}
break;
}

else if(choice==4){
  random=rollDice(20);
  if(random>=10){
  cout<<"voce fugiu"<<endl;
  m_endBattle=true;
  m_run=true;}

  else if(random<10)
  cout<<"voce nao conseguiu fugir"<<endl;
  cout<<"sua vida atual: "<<personagem->getVidaAtual()<<endl;

  int dano_no_personagem=personagem->calcularAtaque()-vecEnemies.at(aliveMonster)->calcularDefesa();

  if(dano_no_personagem<0)
  dano_no_personagem=0;

  cout<<"dano recebido: "<<dano_no_personagem<<endl;

  personagem->tirarVida(dano_no_personagem);

  cout<<"sua vida depois do ataque: "<<personagem->getVidaAtual()<<endl;

  if(!checkLife()){
  goto final;}

  break;
}

else{
  cout<<"Insira um valor valido!"<<endl;
  continue;}
}

  final:;
}

void Game::fireplace()
{
  int choice1, choice2;
  int cura;
  int counter;
  bool curando=true;
  cout<<"\napos a batalha, voce encontra uma fogueira, deseja descansar?"<<endl;
  cout<<"(1)Sim/(2)Nao"<<endl;

  while(true){
  cin>>choice1;

  if(choice1==1 && personagem->getVidaAtual() == personagem->getVidaBase()){
  cout<<"sua vida ja esta no maximo!"<<endl;
  break;}

  else if(choice1==1 && personagem->getVidaAtual() != personagem->getVidaBase()){
    counter++;

  do{
    cura=0.3*personagem->getVidaBase();
    personagem->curar(cura);
    cout<<"voce curou "<<cura<<" de vida"<<endl;

    cout<<"deseja descansar mais?"<<endl;
    cout<<"(1)Sim/(2)Nao"<<endl;

    while(true){
    cin>>choice2;
    if(choice2==1){
      counter++;

      if(counter==3 || personagem->getVidaAtual() >= personagem->getVidaBase()){
      cout<<endl<<"voce ja esta ha tempo demais aqui"<<endl;
      personagem->tirarVida(personagem->getVidaAtual() - personagem->getVidaBase());
      curando=false;}

    break;}
    else if(choice2==2){
    cout<<"voce sai da fogueira"<<endl;
    curando=false;
    break;}
    else{
    cout<<"Insira um valor valido!"<<endl;
    continue;}
    }

  }while(curando);

  break;}

  else if(choice1==2){
  cout<<"voce ignora a fogueira"<<endl;
  break;}

  else{
  cout<<"Insira um valor valido!"<<endl;
  continue;}
}
}

void Game::showMenu()
{
  cout<<"1. Seguir em frente"<<endl;
  cout<<"2. Checar inventario"<<endl;
  cout<<"3. Sair"<<endl;
}

bool Game::dungeonProgress(Masmorra *m)
{
  if(m->calcularNumeroProgresso() == 100){
  return false;} //false se a masmorra tiver acabado

  else
  return true;
}

vector<bool> Game::changeOdds(int fase)
{
  //bau / inimigos / npc / nada
  //level 1 - 4:2:4:0
  //level 2 - 3:3:3:1
  //level 3 - 2:5:2:1
  //level 4 - boss apenas

  vector<bool> odds(4, false);
  int evento=rand()%10+1; //d10 para escolher o evento aleatoriamente

  if(fase==1)
  {
    if(evento>=1 && evento<=4) //bau
    odds.at(0)=true;

    if(evento>=5 && evento<=6) //inimigos
    odds.at(1)=true;

    if(evento>=7 && evento<=10) //npc
    odds.at(2)=true;

    if(evento==11) //nada
    odds.at(3)=true; //probabilidade 0
  }

  if(fase==2)
  {
    if(evento>=1 && evento<=3) //bau
    odds.at(0)=true;

    if(evento>=4 && evento<=6) //inimigos
    odds.at(1)=true;

    if(evento>=7 && evento<=9) //npc
    odds.at(2)=true;

    if(evento==10) //nada
    odds.at(3)=true;
  }

  if(fase==3)
  {
    if(evento>=1 && evento<=2) //bau
    odds.at(0)=true;

    if(evento>=3 && evento<=7) //inimigos
    odds.at(1)=true;

    if(evento>=8 && evento<=9) //npc
    odds.at(2)=true;

    if(evento==10) //nada
    odds.at(3)=true;
  }
  return odds;
}

void Game::SelectFase(int fase, Personagem *p, vector< pair<Item*, int> > &inventory, pair< Item*, int > pairItem)
{
  m_gameover=false;
  int intensificador=fase;
  int menu;
  int counter=0;
  int kills=0;

  Inimigo *in;
  Item *it;

  personagem=p;
  Masmorra *m=chooseDungeon(fase);

  //1 - Masmorra dos beb�s chor�es
  //2 - Masmorra de gente grande
  //3 - Masmorra onde o filho chora e a m�e n�o v�
  //4 - BOSS FINAL

  cout<<endl;

  if(fase==1){
  cout<<"Bem vindo a Masmorra dos bebes choroes"<<endl;}

  else if(fase==2){
  cout<<"Bem vindo a Masmorra de gente grande"<<endl;}

  else if(fase==3){
  cout<<"Bem vindo a Masmorra onde o filho chora e a mae nao ve"<<endl;}

  else if(fase==4){
  cout<<"Bem vindo a Masmorra do Boss Final"<<endl;
  m_finalFight=true;}

  sleep(2);

  if(getfinalFight()){
  Boss *bossfinal = new Boss(20, 50, 25, 9);
  cout<<"voce encontra um grande Dragao Petrificado!"<<endl;

  while(!getEndBattle() && !getGameOver()) //enquanto o boss e o personagem estiverem vivos
  {
    bossFight(bossfinal, inventory);
  }
  m_endBattle=false;
  Luta->FadeOut(0);
  Maintheme->FadeIn(600);
  goto grandFinale;}

  else{

  while(dungeonProgress(m) && !getGameOver()){
menu:
system("cls");
  p->showStatus();
  cout << "Progresso da dungeon: " << m->calcularProgresso() <<endl<<endl;
  showMenu();
  cin>>menu;

if(menu==1){
  m->paraFrente();
  vector<bool> odds=changeOdds(fase); //dependendo da fase, as chances dos eventos muda

  if(odds.at(0)){ //bau
    cout<<"voce encontrou um ba�!"<<endl<<endl;

    if(inventory.size()>=10)
    cout<<"seu inventario esta muito cheio!"<<endl;

    else{
  pairItem=chooseItem();
  inventory.push_back(pairItem);
  }
  }

  if(odds.at(1)){ //inimigos
  int quantidadeInimigos=rand()%3+1;
  cout<<"voce encontrou: "<<endl;
  vector<Inimigo*> vecEnemies;
  vecEnemies.clear();
  vecEnemies=criarVetorInimigos(intensificador, quantidadeInimigos);
  vector<int> killedMonsters(vecEnemies.size());

  while(!getEndBattle() && !getGameOver())
  {
    fight(kills, vecEnemies, inventory, killedMonsters);
  }

  Luta->FadeOut(0);
  Maintheme->FadeIn(600);
  //enquanto todos os inimigos nao tiverem morrido

  if(!getGameOver()){ //se o personagem na tiver morrido
  counter+=vecEnemies.size();
  if(getEndBattle() && !getRun()){
  p->aumentarXP(counter, vecEnemies);
  fireplace();
}}

  m_endBattle=false;
  m_run=false;
  }

  if(odds.at(2)){ //npc
    Music shop("shop","mp3");
    Maintheme->Volume(10);
    shop.Play("from 0",600);
    cout<<"voce encontra um comerciante!"<<endl<<endl; //npc

    if(inventory.size()>=10)
    cout<<"seu inventario esta muito cheio!"<<endl;

    else{
  pairItem=buyItem();

  if(getBuying())
  inventory.push_back(pairItem);
  }
  shop.FadeOut(0);
  Maintheme->FadeIn(600);
  }

  if(odds.at(3)){ //nada
    cout<<"voce nao encontrou nada aqui"<<endl;
  }

continue;}

if(menu==2){
  int itemNumber;

  cout<<endl;

  if(inventory.size()==0)
  cout<<"voce nao tem itens"<<endl;

  else{
  for(int i=0; i<inventory.size(); i++)
  {
    cout<<i+1<<" -> "<<inventory.at(i).first->getItemName()<<endl;
  }
  cout<<endl;

  int usarBau;
  cout<<"deseja usar algum item?"<<endl;
  cout<<"Sim(1)/Nao(2)"<<endl;

  cin>>usarBau;

  while(true){
    if(usarBau==1){
      cout<<"qual?"<<endl;
      cin>>itemNumber;
      itemNumber--;
      p->realizarUpgrade(inventory.at(itemNumber)); //realiza o upgrade dependendo do item
      inventory.erase(inventory.begin()+itemNumber);
      break;
    }
    if(usarBau==2){
      goto menu;
      break;
    }
    else{
      cout<<"Insira um valor valido!"<<endl;
      continue;
    }
  }
}
continue;}

if(menu==3){ //saindo da dungeon
int sair;
cout<<"voce tem certeza que quer sair da dungeon? seu avan�o n�o ser� salvo!"<<endl;
cout<<"Sim(1)/Nao(2)"<<endl;

while(true){
  cin>>sair;
  if(sair==1){
    cout<<"Saindo da dungeon"<<endl;
    break;
  }
  if(sair==2){
    goto menu;
  }
  else{
    cout<<"Insira um valor valido!"<<endl;
    continue;
  }
}

break;}

else{
cout<<"Insira um valor valido!"<<endl;
continue;}

grandFinale:;
}}}
