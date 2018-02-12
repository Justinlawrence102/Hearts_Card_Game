//
//  Hearts.hpp
//  Hearts
//
//  Created by Mateo Delgadillo on 11/28/17.
//  Copyright © 2017 Mateo Delgadillo. All rights reserved.
//

#ifndef Hearts_hpp
#define Hearts_hpp

//CreateHand
bool isEmpty(node *head){ // checks if the node is empty
    if (head==NULL){
        return true;
    }
    else
        return false;
}


/*
 * ValidateCardNum takes in a cardnumber and the hand of the player.
 * This method verifies that the card chosen is indeed in the players hand AND
 * that the card chosen can be played according to the rules of the game.
 * Card played must be of the same suit of the card first played in the round.
 */
bool validateCardNum (int cardNum, node *hand){ //returns false when there is no error, when there is an error, it returns true
    bool error = true;
    while (hand){
        if (hand->cardNum == cardNum){//checks to see if the card is in the player's hand
            error = false;
        }
        hand = hand ->next;
    }
    if (error == true){
        cout<<"That card is not in your hand. Please enter a new card number\n";
    }
    return error;
}

/*
 * creats a linked list of with each node being a card in the deck. There is the suit, card number,
 * and value put into each node. This returns a full deck of cards as a linked list
 */
node* createDeck(node *fullDeck){//creates a full deck of cards, giving it a value, suit, and card number
    node *last = NULL;
    int cardNum = 1;
    for (int j=0; j<4; j++){ //goes through each four suit
        for (int i=1; i<=13; i++){ //goes through each of the 13 types of cards
            if (isEmpty(fullDeck)){
                node *temp = new node;
                if (j==0){
                    temp -> suit = "Hearts";
                }
                else if (j==1){
                    temp -> suit = "Diamonds";
                }
                else if (j==2){
                    temp -> suit = "Spades";
                }
                else if (j==3){
                    temp -> suit = "Clubs";
                }
                if (i ==1){
                    temp -> value = "Ace";
                }
                else if (i==11){
                    temp -> value = "Jack";
                }
                else if (i==12){
                    temp -> value = "Queen";
                }
                else if (i==13){
                    temp -> value = "King";
                }
                else {
                    //cout<<i;
                    temp-> value = to_string(i);
                }
                temp->cardNum = cardNum;
                cardNum++;
                temp -> next = NULL;
                fullDeck = temp;
                last = temp;
            }
            else {
                
                node *fullDeck = new node;
                if (j==0){
                    fullDeck -> suit = "Hearts";
                }
                else if (j==1){
                    fullDeck -> suit = "Diamonds";
                }
                else if (j==2){
                    fullDeck -> suit = "Spades";
                }
                else if (j==3){
                    fullDeck -> suit = "Clubs";
                }
                if (i ==1){
                    fullDeck -> value = "Ace";
                }
                else if (i==11){
                    fullDeck -> value = "Jack";
                }
                else if (i==12){
                    fullDeck -> value = "Queen";
                }
                else if (i==13){
                    fullDeck -> value = "King";
                }
                else {
                    //cout<<i;
                    fullDeck-> value = to_string(i);
                }
                fullDeck->cardNum = cardNum;
                cardNum++;
                fullDeck -> next = NULL;
                last ->next = fullDeck;
                last = fullDeck;
            }
        }
    }
    return fullDeck;
}
/*
 * inputs a set of cards, which then can be printed out with the correct formating with the
 * card num,suit, and value
 */
void showHand(node *fullDeck){//displays the linked list with the proper formating
    while (fullDeck){
        if (fullDeck->cardNum !=0){
            cout<<fullDeck->value<<" of "<<fullDeck->suit<<" card num: "<<fullDeck->cardNum<<"\n";
        }
        fullDeck = fullDeck->next;
    }
    
}
/*
 * takes in a full deck, an array of 52 values, and a range of those number that will be used to create
 * a hand of 13 cards. This returns a hand
 */
node* createHand(node *fullDeck, int num[52], int rangeMin, int rangeMax){ //creates each hand of 13 cards. The rangeMin and rangerMax is a random array of numbers
    node *last = NULL;
    node *hand=NULL;
    node *begining = fullDeck;
    
    for (int i=rangeMin; i<rangeMax; i++){ //puts the first 16 cards in the random array into the first hand
        while (fullDeck){
            if (num[i]==fullDeck->cardNum){
                if (isEmpty(hand)){
                    node *temp = new node;
                    temp->value=fullDeck->value;
                    temp->suit=fullDeck->suit;
                    temp->cardNum=fullDeck->cardNum;
                    temp -> next = NULL;
                    hand = temp;
                    last = temp;
                }
                else {
                    node *hand = new node;
                    hand->value=fullDeck->value;
                    hand->suit=fullDeck->suit;
                    hand->cardNum=fullDeck->cardNum;
                    hand -> next = NULL;
                    last ->next = hand;
                    last = hand;
                }
            }
            fullDeck=fullDeck->next;
        }
        fullDeck=begining; //resets the fulldeck from the begining
    }
    return hand;
}

/*
 * this method takes in a hand and lets the user select which four cards they want to give to the
 * player next to them. It also checks to make sure that the player does not play an illegal card
 * It returns 2 things,a linked list of the cards the player is going to give to the player next to
 * them and the player's new hand after the cards have been taken off, this is why tuple is used
 */

tuple <node*, node*> switchCards (node* hand){//the users select which cards they want to have removed
    node* start = hand;
    node *last = NULL;
    node *tempCards = NULL;
    bool errorsPresent = true;
    
    int card1 =0;
    int card2 =0;
    int card3 =0;
    int card4 =0;
    cout<<"Pick the cards you will pass to the player to your right. Enter the 4 card numbers followed by 'enter' for each card\n";
    
    while (errorsPresent == true){ //this next bit lets the user input what card they want to swtich. If they select a card that they do not really have, ther is an error and they re-incert a card
        cin>> card1;
        if (cin.fail()) {//checks to make sure a user inputs an int
            cout<<"ERROR: Please input a card number\n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }
        errorsPresent = validateCardNum(card1, hand);
    }
    errorsPresent = true; //resets the errors presents to true again
    cout<<"Sucessful. Please type in the next card\n";
    while (errorsPresent == true){ //user selects second card to swap
        cin>> card2;
        if (cin.fail()) {//checks to make sure a user inputs an int
            cout<<"ERROR: Please input a card number\n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }
        if (card2==card1){
            cout<<"ERROR: you have already played that card. Please enter another card\n";
            continue;
        }
        errorsPresent = validateCardNum(card2, hand);
    }
    errorsPresent = true;
    cout<<"Sucessful. Please type in the next card\n";

    while (errorsPresent == true){ //user selects thrird card to swap
        cin>> card3;
        if (cin.fail()) {//checks to make sure a user inputs an int
            cout<<"ERROR: Please input a card number\n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }
        if (card3==card1 || card3==card2){
            cout<<"ERROR: you have already played that card. Please enter another card\n";
            continue;
        }
        errorsPresent = validateCardNum(card3, hand);
    }
    errorsPresent = true;
    cout<<"Sucessful. Please type in the next card\n";

    while (errorsPresent == true){ //user selects forth card to swap
        cin>> card4;
        if (cin.fail()) {//checks to make sure a user inputs an int
            cout<<"ERROR: Please input a card number\n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }
        if (card4==card1 || card4==card2 || card4==card3){
            cout<<"ERROR: you have already played that card. Please enter another card\n";
            continue;
        }
        errorsPresent = validateCardNum(card4, hand);
    }
    
    for (int i = 0; i<3; i++){ //looks for each 4 card in the player's hand and adds them to a new list
        while (hand){
            if (hand->cardNum==card1 || hand->cardNum==card2 ||hand->cardNum==card3 || hand->cardNum==card4){ //if the card they want to switch is in the hand, it adds the card to a list of temp cards that will be moved to the other player's hand
                if (isEmpty(tempCards)){
                    node *temp = new node;
                    temp->value=hand->value;
                    temp->suit=hand->suit;
                    temp->cardNum=hand->cardNum;
                    temp -> next = NULL;
                    tempCards = temp;
                    last = temp;
                }
                else {
                    node *tempCards = new node;
                    tempCards->value=hand->value;
                    tempCards->suit=hand->suit;
                    tempCards->cardNum=hand->cardNum;
                    tempCards -> next = NULL;
                    last ->next = tempCards;
                    last = tempCards;
                }
                
                hand->cardNum=0; //once the card has been removed, the card number goes to 0. In the showHand method, it doesnt print out the card when the num is 0
                hand->suit="";
                hand->value="";
            }
            hand = hand->next;
        }
        hand = start; //starts hand back at the begining
    }
    return make_tuple (tempCards, hand);
}

/*
 * adds the cards that the user would like to give to the other player into that other player's hand. It returns the player's
 * new hand with the new cards in them.
 */

node* addCardsBack (node* hand, node* changedCards){ //adds cards that players decided to swap to the next player's hand
    node* start = hand;
    while (hand){
        if (hand->cardNum==0){
            hand->suit=changedCards->suit;
            hand->value=changedCards->value;
            hand->cardNum=changedCards->cardNum;
            changedCards = changedCards->next;
        }
        hand = hand->next;
    }
    hand=start;
    return hand;
}

/*
 * PlayerClass is an object modelled after the players in the game.
 * The object contains various methods that access and modify the player object
 * in order to establish the objects name, score, and hand (their cards).
 */

//returns the players hand
node* PlayerClass::getHand() {
    return playerH;
}

//creates a hand for the player
void PlayerClass::setHand(node* hand)
{
    playerH = hand;
}

//creates a name for the player
void PlayerClass::setName(string tempN)
{
    name = tempN;
}

//returns the players name
string PlayerClass::getName()
{
    return name;
}

//prints the name of the player
void PlayerClass::printName()
{
    cout << name << endl;
}

//adds a score to the player
void PlayerClass::addScore(int tempS)
{
    score = tempS + score;
}

//returns the players score
int PlayerClass::getScore(int tempS)
{
    return score;
}

//prints the player's score, fashionably.
void PlayerClass::printScore()
{
    cout << name << "'s score is " << score <<"."<<endl;
}

//returns player's number (used for organizing and reordering players)
int PlayerClass::getPlayer()
{
    return playerNum;
}

//sets players number to an integer
void PlayerClass::setPlayer(int temp)
{
    playerNum = temp;
}

//inline PlayerClass::PlayerClass(string name, int score, int playerNum) {}


/* Find Start Player
 * So far, this method only returns an int that indicates which player should start: 1,2,3 or 4
 * it doesn't actually chaaange anything
 */

bool checkHand(int* hand, int card, int player/*in case having this info helps set this player as first later*/) {
    
    for (int f = 0; f < 13; f++) {
        if (hand[f] == card) {
            return true;
        }
    }
    return false;
}

//converts a hand into an integer
int* convert(node* oldHand){
    int* newHand = new int[13];
    for(int r = 0; r < 13; r++){
        newHand[r] = oldHand->cardNum;
        oldHand = oldHand ->next;
    }
    return newHand;
}

//reorders the players depending on plater lost.
void reOrder(PlayerClass* playOrder, int roundStarter){
    PlayerClass temp1 = playOrder[0];
    PlayerClass temp2 = playOrder[1];
    PlayerClass temp3 = playOrder[2];
    PlayerClass temp4 = playOrder[3];
    PlayerClass order[4];
    
    if (roundStarter == 1) {
        playOrder[0] = temp1;
        playOrder[1] = temp2;
        playOrder[2] = temp3;
        playOrder[3] = temp4;
    }
    else if (roundStarter == 2) {
        playOrder[0] = temp2;
        playOrder[1] = temp3;
        playOrder[2] = temp4;
        playOrder[3] = temp1;
    }
    else if (roundStarter == 3) {
        playOrder[0] = temp3;
        playOrder[1] = temp4;
        playOrder[2] = temp1;
        playOrder[3] = temp2;
    }
    else if (roundStarter == 4) {
        playOrder[0] = temp4;
        playOrder[1] = temp1;
        playOrder[2] = temp2;
        playOrder[3] = temp3;
    }
    
}


int* findBounds(int card){//determines what suit counts for that round
    //std::cout << "first card played: " << card << "\n"; //each suit is a card number. Hearts are 1-13 etc...
    int* bounds = new int[2];
    if (card < 14){
        bounds[0] = 1;
        bounds[1] = 13;
    }
    else if (card < 27){
        bounds[0] = 14;
        bounds[1] = 26;
    }
    else if (card < 40){
        bounds[0] = 27;
        bounds[1] = 39;
    }
    else if (card < 53){ //i don't think the 'if' is necessary here but i kept it for "safety check"?
        bounds[0] = 40;
        bounds[1] = 52;
    }
    return bounds;
}

int findTrueLoser(int roundStarter, int losingPlayer){  //based on who started the round
    int loser = 0;
    loser = losingPlayer - 1 + roundStarter;
    if (loser > 4){
        loser = loser%4;
    }
  //  std::cout << "true loser is " << loser << "\n";
    return loser;
}

int findLoser(int* cardsPlayed,int roundStarter, PlayerClass* og){//if you consider the player who goes first as #1, second as #2, etc.
    int* bounds = findBounds(cardsPlayed[0]);
    //std::cout << "bounds: " << bounds[0] << ", " << bounds[1] << "\n";
    
    int losingPlayer = 0;
    int highest = cardsPlayed[losingPlayer];
    
    for (int i = 1; i < 4; i++) {
        if (cardsPlayed[i] >= bounds[0] && cardsPlayed[i] <= bounds[1]) {//makes sure potential higher card is of the same suit
            if (cardsPlayed[i] > highest) { //if aces r considered higher than kings, add || ==1
                losingPlayer = i;
                highest = cardsPlayed[losingPlayer];
            }
        }
    }
    losingPlayer++;
    //std::cout << "highest card of the appropriate suit: " << highest << "\nso loser is " << losingPlayer << "\n";
    //int trueLoser = findTrueLoser(roundStarter,losingPlayer);
    return losingPlayer;
}

/*
 * isPlayable is a method that takes in the card number, the players hand, and the leading card in the round.
 * This method  determines if the card is within the players hand and if the card matches the same suit as the first card played (leading card)
 * returns boolean value if the cardnum passes all these checkpoints.
 */
bool isPlayable (int cardNum, node *hand, int leadingCard){
    string chosenSuit = "";
    bool hasSameSuit = false;
    bool isError = false;
    node* newHandToLookThrough=hand;
    int lowerBound = 0;
    int upperBound = 0;
    bool error = true;
    while (hand) {
        if (hand->cardNum == cardNum){
            error = false;
        }
        hand = hand ->next;
    }
    
    if (error == true) {
        cout<<"ERROR: That card is not in your hand. Please enter a new card number\n";
        isError = true;
    }
    
    if (error == false) { //no errors, card is within the hand of the player and determining the suit of the card played.
        if (leadingCard > 0 && leadingCard < 14) {
            chosenSuit = "hearts";
            lowerBound = 1;
            upperBound = 13;
        }
        if (leadingCard > 13 && leadingCard < 27) {
            chosenSuit = "diamonds";
            lowerBound = 14;
            upperBound = 26;
        }
        if (leadingCard > 26 && leadingCard < 40) {
            chosenSuit = "spades";
            lowerBound = 27;
            upperBound = 39;
        }
        if (leadingCard > 39 && leadingCard < 53) {
            chosenSuit = "clubs";
            lowerBound = 40;
            upperBound = 52;
        }
        //card chosen is not in the same suit but it is in the hand. Must check if player has any cards in hand that are of the same suit.
        if (cardNum >= lowerBound && cardNum <= upperBound) {
            isError = false;
            return isError;
        } else {
            while (newHandToLookThrough) {
                if (newHandToLookThrough->cardNum >= lowerBound && newHandToLookThrough->cardNum <= upperBound){
                    hasSameSuit = true;// player must choose a card that is within the same suit if available.
                    cout << "ERROR: We know you have a card of the same suit as the leading card, please try again!\n";
                    isError = true;
                    break;
                }
                newHandToLookThrough=newHandToLookThrough->next;
            }
            
        }
        
    }
    return isError;
}

/*
 * firstCardOfRound is a method that takes in the card of the first player and returns the card played.
 * Used by other methods.
 */
int firstCardOfRound(PlayerClass firstPlayer) {
    int c = 0;
    cout << "Please enter the card number you want to play: ";
    cin >> c;
    while (!(validateCardNum(c, firstPlayer.getHand()))) {
        cin >> c;
    }
    return c;
}
/*
 * turns the card number into a print out of what the actual card is
 */
void translateCardNum (int cardNum){
    switch (cardNum){
        case 1:
            cout<<"Ace of Hearts";
            break;
        case 2:
            cout<<"2 of Hearts";
            break;
        case 3:
            cout<<"3 of Hearts";
            break;
        case 4:
            cout<<"4 of Hearts";
            break;
        case 5:
            cout<<"5 of Hearts";
            break;
        case 6:
            cout<<"6 of Hearts";
            break;
        case 7:
            cout<<"7 of Hearts";
            break;
        case 8:
            cout<<"8 of Hearts";
            break;
        case 9:
            cout<<"9 of Hearts";
            break;
        case 10:
            cout<<"10 of Hearts";
            break;
        case 11:
            cout<<"Jack of Hearts";
            break;
        case 12:
            cout<<"Queen of Hearts";
            break;
        case 13:
            cout<<"King of Hearts";
            break;
        case 14:
            cout<<"Ace of Diamonds";
            break;
        case 15:
            cout<<"2 of Diamonds";
            break;
        case 16:
            cout<<"3 of Diamonds";
            break;
        case 17:
            cout<<"4 of Diamonds";
            break;
        case 18:
            cout<<"5 of Diamonds";
            break;
        case 19:
            cout<<"6 of Diamonds";
            break;
        case 20:
            cout<<"7 of Diamonds";
            break;
        case 21:
            cout<<"8 of Diamonds";
            break;
        case 22:
            cout<<"9 of Diamonds";
            break;
        case 23:
            cout<<"10 of Diamonds";
            break;
        case 24:
            cout<<"Jack of Diamonds";
            break;
        case 25:
            cout<<"Queen of Diamonds";
            break;
        case 26:
            cout<<"King of Diamonds";
            break;
        case 27:
            cout<<"Ace of Spades";
            break;
        case 28:
            cout<<"2 of Spades";
            break;
        case 29:
            cout<<"3 of Spades";
            break;
        case 30:
            cout<<"4 of Spades";
            break;
        case 31:
            cout<<"5 of Spades";
            break;
        case 32:
            cout<<"6 of Spades";
            break;
        case 33:
            cout<<"7 of Spades";
            break;
        case 34:
            cout<<"8 of Spades";
            break;
        case 35:
            cout<<"9 of Spades";
            break;
        case 36:
            cout<<"10 of Spades";
            break;
        case 37:
            cout<<"Jack of Spades";
            break;
        case 38:
            cout<<"Queen of Spades";
            break;
        case 39:
            cout<<"King of Spades";
            break;
        case 40:
            cout<<"Ace of Clubs";
            break;
        case 41:
            cout<<"2 of Clubs";
            break;
        case 42:
            cout<<"3 of Clubs";
            break;
        case 43:
            cout<<"4 of Clubs";
            break;
        case 44:
            cout<<"5 of Clubs";
            break;
        case 45:
            cout<<"6 of Clubs";
            break;
        case 46:
            cout<<"7 of Clubs";
            break;
        case 47:
            cout<<"8 of Clubs";
            break;
        case 48:
            cout<<"9 of Clubs";
            break;
        case 49:
            cout<<"10 of Clubs";
            break;
        case 50:
            cout<<"Jack of Clubs";
            break;
        case 51:
            cout<<"Queen of Clubs";
            break;
        case 52:
            cout<<"King of Clubs";
            break;
        default:
            cout<<"not a card";
    }
    cout<<"\n";
}

/*
 * removes the card from the player's hand by making the card number 0, so that it does not print it out.
 */
node* removeCardFromHand (node* hand, int cardNum){
    node*start = hand;
    while (hand){
        if (hand->cardNum==cardNum){
            hand->cardNum = 0;
            break;
        }
        hand = hand->next;
    }
    hand =start;
    return hand;
}

#endif /* Hearts_hpp */
