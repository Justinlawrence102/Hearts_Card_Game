//
//  header.cpp
//  Hearts
//
//  Created by Justin Lawrence on 12/2/17.
//  Copyright © 2017 Justin Lawrence. All rights reserved.
//

//include/import libraries
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <tuple>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct node // creates the nodes for the individuals card of the deck
{
    string suit;
    string value;
    node*next;
    int cardNum;
};

class PlayerClass
{
    // Private Variables used in the PlayerClass
private:
    string name;
    int score;
    int playerNum;
    node * playerH = NULL;
    
public:
    PlayerClass(string a, int b, int c){  //The constructor for the PlayerClass
        name = a;
        score = b;
        playerNum = c;
    }
    PlayerClass(){
        name = "";
        score = -1;
        playerNum = -1;
    }
    // All the method used in in the PlayerClass
    void setPlayer(int);
    int getPlayer();
    void setName(string);
    string getName();
    void printName();
    void addScore(int);
    int getScore(int);
    void printScore();
    void setHand(node*);
    node* getHand();
    
};

bool isEmpty(node *head);
bool validateCardNum (int cardNum, node *hand);
node* createDeck(node *fullDeck);
void showHand(node *fullDeck);
node* createHand(node *fullDeck, int num[52], int rangeMin, int rangeMax);
tuple <node*, node*> switchCards (node* hand);
node* addCardsBack (node* hand, node* changedCards);
bool checkHand(int* hand, int card, int player);
int* convert(node* oldHand);
void reOrder(PlayerClass* playOrder, int roundStarter);
PlayerClass* findStarter(node *hand1Node, node *hand2Node, node *hand3Node, node*hand4Node, PlayerClass* og);
int* findBounds(int card);
int findLoser(int* cardsPlayed,int roundStarter, PlayerClass* og);
int findTrueLoser(int roundStarter, int losingPlayer);
bool isPlayable (int cardNum, node *hand, int lastCard);
int firstCardOfRound(PlayerClass firstPlayer);
void playCard(int cardPlayed, PlayerClass player, int* playedCards, int firstCardPlayed , int roundNum);
