#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int health = 100;
int score = 0;

int Skelebruh_Health =200;
string Attack ="NONE";
int Skele_Damage;
int Skele_Damage_on_Player = rand() % 6;

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
        cout<<"You chose the correct path, congratulations! Please continue to the next level."<<endl;
        score +=5;
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
   if (Trap_choice == "Disable") {
    health -= 5;
    score +=25;
    cout << "AHH! You got scared by a snake and hit your head on a rock! You disabled the traps but lost 5 health."<<endl;
    cout << "Your current health: " << health<<endl;
} else if (Trap_choice == "Risk") {
    health -= 25;
    cout << "OUCH! You got shot by an arrow from the hidden traps. You survived, but lost 25 health."<<endl;
    cout << "Your current health: " << health <<endl;
    score -=3;
} else {
    cout << "Invalid choice. Please restart the game and enter 'Disable' or 'Risk'."<<endl;
    exit(-1);
    return 0;
}
//Decision 3
    cout<<"Congratulations you have made it halfway through! For this next level you will need to fight the infamous skelebruh, AND make it out alive"<<endl;
    while (Skelebruh_Health >0 and health>=0 ){
        cout<<"Choose from one of four approaches: Slash, Range, or Stealth"<<endl;
        cin>>Attack;
        if (Attack == "Slash"){
            cout<<"You attack 'Skelebruh' and he sees you coming and attacks back!"<<endl;
            cout<<"You do "<<(Skele_Damage = rand() % 11)<<" healthpoints of damage on 'SkeleBruh' while he did "<<(Skele_Damage_on_Player = rand() % 6)<<" healthpoints on you!"<<endl;
            Skelebruh_Health -=Skele_Damage;
            if (Skelebruh_Health<0){
                Skelebruh_Health =0;
            }
            health -=Skele_Damage_on_Player;
            cout<<"Your current health is: "<<health<<endl;
            cout<<"Skelebruh's health is : "<<Skelebruh_Health<<endl;

        }else if (Attack == "Range"){
            cout<<"You search around the floor and find a rock to throw at 'Skelebruh'. You throw it at him. He throws it right back."<<endl;
            cout<<"You do "<<(Skele_Damage = rand() % 15)<<" healthpoints of damage on 'SkeleBruh' while he did "<<(Skele_Damage_on_Player = rand() % 3)<<" healthpoints on you!"<<endl;//Skelebruh has no muscles so he cant throw very hard
            Skelebruh_Health -=Skele_Damage;
            if (Skelebruh_Health<0){
                Skelebruh_Health =0;
            }
            health -=Skele_Damage_on_Player;
            cout<<"Your current health is: "<<health<<endl;
            cout<<"Skelebruh's health is : "<<Skelebruh_Health<<endl;
        }else if (Attack =="Stealth"){
            cout<<"You sneak around the room and attack 'Skelebruh' while he has his back turned and RIP his head off of his shoulders, killing him instantly."<<endl;
            cout<<"You do "<<(Skele_Damage +=100 )<<" healthpoints of damage on 'SkeleBruh' while he did 0 healthpoints of damage on you!"<<endl;
            Skelebruh_Health -=Skele_Damage;
            health -=Skele_Damage_on_Player;
            if (Skelebruh_Health<0){
                Skelebruh_Health =0;
            }
            cout<<"Your current health is: "<<health<<endl;
            cout<<"Skelebruh's health is : "<<Skelebruh_Health<<endl;

        }else {
            cout<<"Please choose an attack and try again."<<endl;
        }
         
    }
    //after killing skelebruh
    cout<<"Good job defeating skelebruh, onto the next level!"<<endl;



   return 0;
}
}