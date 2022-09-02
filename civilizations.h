/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   civilizations.h contains the prototypes of the functions
   for the three civilization types: agricultural, military, and industrial.
   This file also contains the Civilization class
   which the three civilizations inherit, and the DLL class that the
   three civilizations are stored in.

   Last updated: July 22, 2021
*/
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <math.h>

// ************** BASE CLASS: CIVILIZATION *******************

class Civilization {
public:
  Civilization(int f, int m, int s); //constructor (food, money, soldiers)
  virtual ~Civilization();
  Civilization(const Civilization & source);
  void read(); //fill in fields for the civilization
  void display(char* n, int civ); //display details of the civilization
  virtual void buy(const std::string & to_buy, int amount) = 0; //buy goods from market
  virtual void sell(const std::string & to_sell, int amount) = 0; //sell goods to market in exchange for money
  virtual void trade(int lost, int al, int gained, int ag) = 0; //lost is what you gave, al is how much you lost, gained is what you gained and ag is how much of that item you gained
  virtual int calculate() = 0; //calculate points
  bool check_money(int item, int amount);
  void display_market(); //displays items you can buy
  bool display_inventory(bool m);
  void random_civs(); //prints out random civilization names
  void random_inventory(int & food, int & soldiers); //print out a random inventory amounts (used in trading)
  bool compare_food(int i); //compares food passed in to civ's food 
  bool compare_military(int i); //compares military passed in to civ's military
  char* ret_name(); //return the name
  bool compare_action();
  void required_action(int type);
  void failed_to_do_action(int civ);
protected:
  char* name;
  int food;
  int money; //how much money you have
  int military; // how much protection your civilization has
  int m_food; //market food
  int m_military; //market soldiers
  bool required_action_done;
};

// ************** CIVILIZATION: AGRICULTURE  ******************

class Agriculture : public Civilization {
public:
  Agriculture();
  void buy(const std::string & to_buy, int amount);
  void sell(const std::string & to_sell, int amount);
  void trade(int lost, int al, int gained, int ag);
  int calculate();

  //specifically agriculture functions:
  void harvest(); //harvest crops.
  void water_crops(); //required every turn
  void plant_plots(); //plant more another plot of crops (requires money, but you can have multiple instances of crops growing at the same time).
  void display(char* n);
 private:
  int amount_of_plots;
};

// ************** CIVILIZATION: MILITARY  ******************

class Military : public Civilization {
public:
  Military();
  void buy(const std::string & to_buy, int amount);
  void sell(const std::string & to_sell, int amount);
  void trade(int lost, int al, int gained, int ag);
  int calculate();
  
  //specifically military functions:
  void train_troops(); //gain more soldiers
  void feed_troops(); //you must feed troops every round or you lose soldiers
  void wage_war(); //potentially gain resources but RNG how many soldiers you lose
  void display(char* n);
private:
  int successful_wars;
};

// ************** CIVILIZATION: INDUSTRY  ******************

class Industry : public Civilization {
public:
  Industry();
  void buy(const std::string & to_buy, int amount);
  void sell(const std::string & to_sell, int amount);
  void trade(int lost, int al, int gained, int ag);
  int calculate();
  void display(char* n);
  //specifically industry functions
  void produce_new_product(); //create a new product you can produce
  void work(); //required every turn. Produces existing products
private:
  int amount_of_products;
};


// ************** DATA STRUCTURE: DLL ******************
class Node {
public:
  Node();
  Node(Civilization * c, int t);
  Node(const Civilization & source);

  Node *& go_next(); //go to the next node
  Node *& go_prev(); //go to previous node
  void set_next(Node * n);
  void set_prev(Node * p);
  void call_display();
  char* name();
private:
  Node * next;
  Node * prev;
  Civilization * civ;
  int type; //what type of civ it is: 1 - agr, 2 - mil, 3 - ind
};

class DLL {
public:
  DLL();
  ~DLL();
  DLL(const DLL & source); // copy constructor
  void insert(Civilization * c, int t); //insert to DLL
  void remove(char* name); //remove from DLL
  void display();
  void remove_all(); //clear from DLL
private:
  void cp(Node *& cur, Node * source);
  void insert(Node * current, Node *& to_add); //recursive insert
  void remove(Node * current, char* to_remove); //recursive remove
  void display(Node * current); //recursive display
  void remove_all(Node *& current); //recursive remove all
  void destruct(Node *& cur); // recursive deallocation for whole DLL
  Node * head;
};
