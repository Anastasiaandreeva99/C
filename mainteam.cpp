#include"Team.cpp"
#include"Team.h"
void testTeam() {
  Player p1("Гандалф Сивия", 45);
  p1.print();
  Player p2;//
  p2 = p1;
  p2.setName("Гандалф Белия");
  p2.setscore(55);
  p1.print();
  p2.print();
  Team team1(p1,),team2;

}

int main() {
  testTeam();
  return 0;
}
