//
//  Hearts.cpp
//  Hearts
//
// 
//
#include "header.h"
#include "Hearts.hpp"

int main(int argc, const char * argv[]) {
    string respond = "";
    node *fullDeck = NULL;
    node *hand1 = NULL;
    node *hand2 = NULL;
    node *hand3 = NULL;
    node *hand4 = NULL;
    
    //    int playerScore;
    string playerName;
    
    PlayerClass player1 = PlayerClass("player1", 0, 1);
    PlayerClass player2 = PlayerClass("player2", 0, 2);
    PlayerClass player3 = PlayerClass("player3", 0, 3);
    PlayerClass player4 = PlayerClass("player4", 0, 4);
    
    fullDeck = createDeck(fullDeck);
    int num[52];
    for (int k=1; k<53;k++){
        num[k]=k;
    }
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i=1; i<52; i++) {
        int r = rand() % 52+1;  // randomly sorts cards
        int temp = num[i];
        num[i] = num[r];
        num[r] = temp;
    }
    //deck is shuffled and hands will be created
    cout<<"Welcome to Hearts!\n";
    hand1 = createHand(fullDeck, num, 0, 14); //creates each hand
    hand2 = createHand(fullDeck, num, 14, 27);
    hand3 = createHand(fullDeck, num, 27, 40);
    hand4 = createHand(fullDeck, num, 40, 53);
    
    //create player 1
    cout<<"Enter name for player 1: ";
    cin >> playerName;
    player1.setName(playerName);
    
    cout<< "hand 1: \n";
    showHand(hand1);
     node* cardsfromPlay1 = NULL; //this is the temparary spot that the cards that player 1 will get rid of
    tie (cardsfromPlay1, hand1) = switchCards (hand1);
       cout<<"These are the cards you are removing: \n";
     showHand(cardsfromPlay1);
    
    cout<<"\nPress any key and enter to clear hand";
    cin>>respond;
    for (int i=0;i<30; i++){
        cout<<"\n";
    }
    //create player 2
    cout<<"Enter name for player 2: ";
    cin >> playerName;
    player2.setName(playerName);
    
    cout<<"\nhand 2: \n";
    showHand(hand2);
     node* cardsfromPlay2 = NULL; //this is the temparary spot that the cards that player 2 will get rid of
     tie (cardsfromPlay2, hand2) = switchCards (hand2);
      cout<<"These are the cards you are removing: \n";
      showHand(cardsfromPlay2);
    
    cout<<"\nPress any key to clear hand";
    cin>>respond;
    for (int i=0;i<30; i++){
        cout<<"\n";
    }
    //create player 3
    cout<<"Enter name for player 3: ";
    cin >> playerName;
    player3.setName(playerName);
    
    cout<<"\nhand 3: \n";
    showHand(hand3);
     node* cardsfromPlay3 = NULL; //this is the temparary spot that the cards that player 3 will get rid of
     tie (cardsfromPlay3, hand3) = switchCards (hand3);
      cout<<"These are the cards you are removing: \n";
     showHand(cardsfromPlay3);

    cout<<"\nPress any key to clear hand";
    cin>>respond;
    for (int i=0;i<30; i++){
        cout<<"\n";
    }
    //create player 4
    cout<<"Enter name for player 4: ";
    cin >> playerName;
    player4.setName(playerName);
    
    cout<<"\nhand 4: \n";
    showHand(hand4);
     node* cardsfromPlay4 = NULL; //this is the temparary spot that the cards that player 4 will get rid of
      tie (cardsfromPlay4, hand4) = switchCards (hand4);
     cout<<"These are the cards you are removing: \n";
     showHand(cardsfromPlay4);
    
      addCardsBack(hand1, cardsfromPlay2); //adds the cards that player two discarded to player 1's hand
      addCardsBack(hand2, cardsfromPlay3);
      addCardsBack(hand3, cardsfromPlay4);
      addCardsBack(hand4, cardsfromPlay1);
    
    cout<<"The game will now begin with player 1. Pass the compuer to player 1, and presss any key and enter to start";
    cin>>respond;
    for (int i=0;i<30; i++){
        cout<<"\n";
    }
    //the set up of cards that happends at the begining of a game is now done!!!!
    //NOW, all of the hands (hand1, hand2, hand3, and hand4) all have the new set of cards that have been swapped around...Next step is to start a loop that actually runs the game!
    player1.setHand(hand1);
    player2.setHand(hand2);
    player3.setHand(hand3);
    player4.setHand(hand4);
    
    PlayerClass ogPlayers [] = {player1, player2, player3, player4};
    //this is arbitrary list of the players w/ hands that will be changed after every round depending on the loser.
    
    PlayerClass * playOrder = ogPlayers;//findStarter(player1.getHand(), player2.getHand(), player3.getHand(), player4.getHand(), ogPlayers); //player w/ 2 of clubs starts and is assigned.
    string currentSuit = "";
    int cardsPlayed [] = {0,0,0,0};
    //    int lastPlayer = 0;
    int leadingCard = 0;
    int roundStarter =0;
    
    for (int round = 0; round < 13; round++) { //goes through every round
        int pointsInRound =0;
        for (int x = 0; x < 4; x++) { //goes through each player and lets them play
            
            if (x!=0){
                cout<<ogPlayers[x].getName()<<", you are next! Press any key followed by 'enter' to see your cards";
                cin>>respond;
                for (int i=0;i<30; i++){
                    cout<<"\n";
                }
                cout<<"The leading card is "; //promps the user to input the text for not the first round
                translateCardNum(leadingCard);
                cout<<"\nthe cards in the center pile are: \n";
                for (int i=0; i < x; i++){
                    translateCardNum(cardsPlayed[i]);
                }
            }
            else{ cout<<ogPlayers[x].getName()<<", you are going first, please pick your card."; //prompts the user to insert thier cards for the first round
            cout<<"\nPress any key followed by enter to see your cards";
            cin>>respond;
            for (int i=0;i<30; i++){
                cout<<"\n";
            }
            }
            
            cout <<"\n\nHere is your hand: \n";
            showHand(ogPlayers[x].getHand());
            int cardChosen=0;
            bool isError =true;
            
            cout << "Please input card you'd like to play: " << endl;
            
            while (isError==true){
                cin >> cardChosen;
                if (cin.fail()) {//checks to make sure a user inputs an int
                    cout<<"ERROR: Please input a card number\n";
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                    continue;
                }
                if (x == 0){ //for the first round, it just has to check if the card is in the player's hand
                    isError=validateCardNum(cardChosen, ogPlayers[x].getHand());
                }
                else{
                    isError = isPlayable(cardChosen, ogPlayers[x].getHand(), leadingCard); //it has to make sure that it is a legal play, and looks to see if they are suppsed to match suit
                }
            }
            
            if (x == 0) { //makes the first player's card decide the suit
                leadingCard=cardChosen;
            }
            
            
            cardsPlayed[x] = cardChosen;
            
            cout<<"\nYou have played the card ";
            translateCardNum(cardChosen);
            cout<<"Please press any key and move to the next player";
            cin>> respond;
            for (int i=0;i<30; i++){
                cout<<"\n";
            }
            
            ogPlayers[x].setHand(removeCardFromHand((ogPlayers[x].getHand()), cardChosen)); //removes card played from hand
            
        }
        cout<<"ROUND OVER";
        roundStarter = findLoser(cardsPlayed, playOrder[0].getPlayer(), ogPlayers);
        //add points to player who lost
        for (int x = 0; x < 4; x++) {
            if ((cardsPlayed[x] > 0) && (cardsPlayed[x] < 14)) {//looks to see who played the hearts, which the card number is between 1 and 13
                pointsInRound++; //if they did, they get that many points
            }
            if (cardsPlayed[x]==38){
                pointsInRound=13;
            }
        }
        reOrder(ogPlayers, roundStarter); //makes the loser go first the next round

        playOrder[0].addScore(pointsInRound); //gives the user the correct nubmer of points
        cout << "\n";
        ogPlayers[0].printScore(); //displays the score
        ogPlayers[1].printScore();
        ogPlayers[2].printScore();
        ogPlayers[3].printScore();
        cout << "\n";
        //reOrder(ogPlayers, roundStarter);
    }
    
    cout<<"The game is over!The player with the lowest score wins!\n";
    ogPlayers[0].printScore();
    ogPlayers[1].printScore();
    ogPlayers[2].printScore();
    ogPlayers[3].printScore();
   
    
    return 0;
}
