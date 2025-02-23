#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int health = 100;
int score = 0;
int Skelebruh_Health = 100;
string Attack = "NONE";
int Skele_Damage;
int Skele_Damage_on_Player;
int Weapon_Choice = 0;
string Weapon = "NONE";
int Health_Potion = 0;
string Shield = "NONE";
int Giant_Snake_Health = 300;
int Weapon_Damage = 0;
string Attack_Snake = "NONE";
int Giant_Snake_Damage_On_Player;
int Door;
int rando;

int main() {
    char First_choice = 'N';
    while (health > 0) {
        // INTRODUCTION
        cout << "Welcome to 'Escape the Dungeon'" << endl;
        cout << "You find yourself trapped in a dark dungeon. " << endl;
        cout << "Your mission is to find a way out." << endl;

        // FIRST CHOICE
        cout << "You come across a fork in the road, do you take the left or right path?" << endl;
        cout << "Enter 'L' or 'R'" << endl;
        cin >> First_choice;

        switch (First_choice) {
            case 'R':
                cout << "You chose the correct path, congratulations! Please continue to the next level." << endl;
                score += 5;
                break;
            case 'L':
                cout << "Wrong choice! You lost, please start over" << endl;
                score = 0;
                cout << "Score: " << score << endl;
                exit(0);
        }

        // DECISION 2
        string Trap_choice = "NONE";
        cout << "You made it through the first room, now get ready to die!" << endl; // story bit
        cout << "This level has a choice to make, do you risk running past the traps or try and disable them?" << endl;
        cout << "Make your choice and choose it carefully...." << endl;
        cout << "Choose either 'Disable' or 'Risk'" << endl;
        cin >> Trap_choice;

        if (Trap_choice == "Disable") {
            health -= 5;
            score += 15;
            cout << "AHH! You got scared by a snake and hit your head on a rock! You disabled the traps but lost 5 health." << endl;
            cout << "Your current health: " << health << endl;
        } else if (Trap_choice == "Risk") {
            health -= 25;
            cout << "OUCH! You got shot by an arrow from the hidden traps. You survived, but lost 25 health." << endl;
            cout << "Your current health: " << health << endl;
            score -= 3;
        } else {
            cout << "Invalid choice. Please restart the game and enter 'Disable' or 'Risk'." << endl;
            exit(-1);
        }

        // DECISION 3
        cout << "Congratulations you have made it halfway through! For this next level you will need to fight the infamous Skelebruh, AND make it out alive" << endl;
        while (Skelebruh_Health > 0 && health > 0) {
            cout << "Choose from one of three approaches: Slash, Range, or Stealth" << endl;
            cin >> Attack;

            if (Attack == "Slash") {
                score += 5;
                cout << "You attack 'Skelebruh' and he sees you coming and attacks back!" << endl;
                cout << "You do " << (Skele_Damage = rand() % 11) << " healthpoints of damage on 'Skelebruh' while he did " << (Skele_Damage_on_Player = rand() % 6) << " healthpoints on you!" << endl;
                Skelebruh_Health -= Skele_Damage;
                if (Skelebruh_Health < 0) {
                    Skelebruh_Health = 0;
                }
                health -= Skele_Damage_on_Player;
                if (health < 0) {
                    health = 0;
                    cout << "YOU DIED" << endl;
                    cout << "Score: " << score << endl;
                    exit(0);
                }
                cout << "Your current health is: " << health << endl;
                cout << "Skelebruh's health is: " << Skelebruh_Health << endl;

            } else if (Attack == "Range") {
                score += 10;
                cout << "You search around the floor and find a rock to throw at 'Skelebruh'. You throw it at him. He throws it right back." << endl;
                cout << "You do " << (Skele_Damage = rand() % 15) << " healthpoints of damage on 'Skelebruh' while he did " << (Skele_Damage_on_Player = rand() % 3) << " healthpoints on you!" << endl; // Skelebruh has no muscles so he can't throw very hard
                Skelebruh_Health -= Skele_Damage;
                if (Skelebruh_Health < 0) {
                    Skelebruh_Health = 0;
                }
                health -= Skele_Damage_on_Player;
                if (health < 0) {
                    health = 0;
                    cout << "YOU DIED" << endl;
                    cout << "Score: " << score << endl;
                    exit(0);
                }
                cout << "Your current health is: " << health << endl;
                cout << "Skelebruh's health is: " << Skelebruh_Health << endl;

            } else if (Attack == "Stealth") {
                score += 15;
                cout << "You sneak around the room and attack 'Skelebruh' while he has his back turned and RIP his head off of his shoulders, killing him instantly." << endl;
                cout << "You do " << (Skele_Damage += 100) << " healthpoints of damage on 'Skelebruh' while he did 0 healthpoints of damage on you!" << endl;
                Skelebruh_Health -= Skele_Damage;
                if (Skelebruh_Health < 0) {
                    Skelebruh_Health = 0;
                }
                cout << "Your current health is: " << health << endl;
                cout << "Skelebruh's health is: " << Skelebruh_Health << endl;

            } else {
                cout << "Please choose an attack and try again." << endl;
            }
        }

        // After killing Skelebruh
        cout << "Good job defeating Skelebruh, onto the next level!" << endl;

        // DECISION 4
        cout << "You made it to level 3, this level will prepare you for the next battle. You have a choice between three different chests of weapons, and you are only allowed to pick one." << endl;
        cout << "Choose a number 1-3" << endl;
        cin >> Weapon_Choice;

        switch (Weapon_Choice) {
            case 1:
                cout << "You get a sword, health potion, and a shield" << endl;
                Weapon = "Sword";
                Health_Potion = 1;
                Shield = "Yes";
                score += 10;
                break;
            case 2:
                cout << "You get a battle axe, one health potion, and no shield." << endl;
                Weapon = "Battle Axe";
                Health_Potion = 1;
                Shield = "No";
                score += 20;
                break;
            case 3:
                cout << "You get a Spear, 2 health potions, and a shield" << endl;
                Weapon = "Spear";
                Health_Potion = 2;
                Shield = "Yes";
                score += 15;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                break;
        }

        // Room 5 Boss fight
        cout << "You come across a giant snake and you must kill it to progress." << endl;

        while (Giant_Snake_Health > 0 && health > 0) {
            if (Weapon == "Sword") {
                Weapon_Damage = 25 + rand() % 6;
            } else if (Weapon == "Battle Axe") {
                Weapon_Damage = 35 + rand() % 11;
            } else if (Weapon == "Spear") {
                Weapon_Damage = 20 + rand() % 15;
            }
        
            cout << "What attack do you want to do? Choose 'Melee', 'Heal', or 'Block'" << endl;
            cin >> Attack_Snake;
        
            if (Attack_Snake == "Melee") {
                score += 15;
                Giant_Snake_Damage_On_Player = rand() % 26;
                Giant_Snake_Health -= Weapon_Damage;
                if (Giant_Snake_Health < 0) {
                    Giant_Snake_Health = 0;
                }
                health -= Giant_Snake_Damage_On_Player;
                if (health < 0) {
                    health = 0;
                    cout << "YOU DIED" << endl;
                    cout << "Score: " << score << endl;
                    exit(0);
                }
                cout << "You do " << Weapon_Damage << " damage on the Giant Snake while it does " << Giant_Snake_Damage_On_Player << " damage on you!" << endl;
                cout << "Your current health: " << health << " | Giant Snake's health: " << Giant_Snake_Health << endl;
            } else if (Attack_Snake == "Heal") {
                score += 20;
                if (Health_Potion > 0) {
                    health = health + 50;
                    Health_Potion--;
                    cout << "You used a health potion. Your health is now: "<<health<<endl;
                    cout<<"You have: "<<Health_Potion<<" left."<<endl;
                } else {
                    cout << "You have no health potions left!" << endl;
                }
            } else if (Attack_Snake == "Block") {
                if (Shield == "Yes") {
                    score += 15;
                    rando = rand() % 2;
                    if (rando == 1) {
                        cout << "You successfully block the attack with your shield!" << endl;
                    } else {
                        cout << "You did not land the block, and the snake hit you!" << endl;
                        Giant_Snake_Damage_On_Player = rand() % 26;
                        if (Giant_Snake_Health < 0) {
                            Giant_Snake_Health = 0;
                        }
                        health -= Giant_Snake_Damage_On_Player;
                        if (health < 0) {
                            health = 0;
                            cout << "YOU DIED" << endl;
                            cout << "Score: " << score << endl;
                            exit(0);
                        }
                        cout << "The giant snake did " << Giant_Snake_Damage_On_Player << ". Your health is " << health << "." << endl;
                    }
                }else if (Shield =="N0")
                {
                    cout << "No Shield!!!!!" << endl;
                }
                cout << "Your current health: " << health << " | Giant Snake's health: " << Giant_Snake_Health << endl;
            }
        }

// Room 6: Final Room
cout << "You come into the final room to see 3 doors ahead of you. These doors will close behind you, so it is imperative you choose the right one, or else you lose." << endl;
cout << "Pick one of these three doors." << endl;
cin >> Door;
switch (Door) 
{
    case 1:
        cout << "YOU CHOSE THE WRONG DOOR! YOU LOSE!" << endl;
        health = 0;
        break;
    case 2:
        cout << "YOU CHOSE THE RIGHT DOOR! YOU WIN!" << endl;
        score += 100;
        cout << "Score: " << score << endl;
        break;
    case 3:
        cout << "YOU CHOSE THE WRONG DOOR! YOU LOSE!" << endl;
        cout << "Score: " << score << endl;
        health = 0;
        break;
}
return 0;
 }
}