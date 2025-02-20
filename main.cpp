#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int health = 100;



int main(){
    char First_choice = 'N';
while (health !=0) {
    //INTRODUCTION
   cout<<"Welcome to 'Escape the Dungeon'"<<endl;
   cout<<"You find yourself trapped in a dark dungeon. "<<endl;
   cout<<"Your mission is to find a way out."<<endl;
   // FIRST CHOICE
   cout<<"You come across a fork in the road, do you take the left or right path?"<<endl;
   cout<<"Enter 'L' or 'R'"<<endl;
   cin>>First_choice;
   switch (First_choice) {
    case 'R' :
        cout<<"You chose the correct path, congratulations! Please continue to the next level."<<endl;;
        break;
    case 'L' :
        cout<<"Wrong choice! You lost, please start over"<<endl;
        exit(0);
   }
   //DECISION 2
   string Trap_choice = "NONE";
   cout<<"You made it through the first room, now get ready to die!"<<endl;         //story bit
   cout<<"This level has a choice to malke, do you risk running past the traps or try and disable them?"<<endl;
   cout<<"Make your choice and choose it carefully...."<<endl;
   cout<<"Choose either 'Disable' or 'Risk'"<<endl;
   cin>>Trap_choice;
   if (Trap_choice == "disable") {
    health -= 5;
    cout << "AHH! You got scared by a snake and hit your head on a rock! You disabled the traps but lost 5 health."<<endl;
    cout << "Your current health: " << health << "<<endl;";
} else if (Trap_choice == "risk") {
    health -= 25;
    cout << "OUCH! You got shot by an arrow from the hidden traps. You survived, but lost 5 health."<<endl;
    cout << "Your current health: " << health << ""<<endl;;
} else {
    cout << "Invalid choice. Please restart the game and enter 'Disable' or 'Risk'."<<endl;;
    exit(-1);
    return 0;
}


   return 0;
}
}