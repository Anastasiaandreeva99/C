#include <iostream>
#include "player.h"

void anonymousPrint(Player p) {
  p.setName("<��������>");
  p.print();
}

void testPlayer() {
  Player p1("������� �����", 45);
  p1.print();
  Player p2;//
  p2 = p1;
  p2.setName("������� �����");
  p2.setscore(55);
  p1.print();
  p2.print();
  anonymousPrint(p2);
  p1.print();
  p2.print();
}

int main() {
  testPlayer();
  return 0;
}
