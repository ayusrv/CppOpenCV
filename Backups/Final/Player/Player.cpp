#include "Player.h"
#include<bits/stdc++.h>
using namespace std;

//Default constrctor
player::player():playerId(1), playerName(nullptr), playerAge(0), no_of_match(0), playerRank(0) {
    score[3] = {0};
}

//Getter setter for playerId
unsigned int player::getPlayerId() { return playerId; }
void player::setPlayerId(unsigned int playerId_) { playerId = playerId_; }

//Getter setter for player name
char* player::getPlayerName() { return playerName; }
void player::setPlayerName(char* playerName_) { playerName = playerName_; }

//Getter setter for player age
float player::getPlayerAge() { return playerAge; }
void player::setPlayerAge(float playerAge_) { playerAge = playerAge_; }

//Getter setter for number of match
unsigned int player::noOfMatch() { return no_of_match; }
void player::setNoOfMatch(unsigned int noOfMatch) { no_of_match = noOfMatch; }

//Getter setter for player rank
unsigned int player::getPlayerRank() { return playerRank; }
void player::setPlayerRank(unsigned int playerRank_) { playerRank = playerRank_; }

void player::setPlayerScore(unsigned int s[3]){
    for(int i=0;i<3;i++){
        score[i] = s[i];
    }
}

//Calcute the average score
unsigned int player::calcAveScore(){
    int avg=0;
    for(int i=0;i<3;i++){
        avg+=score[i];
    }
    return avg/3;
}

//boolean operator overloading for less than operator
bool player::operator<(player p){
    return calcAveScore()<p.calcAveScore();
}

//int operator overloading for plus operator
int player::operator+(player &p){
    int val = calcAveScore() + p.calcAveScore();
    return val;
}

//boolean operator overloading for equal equal to operator
bool player::operator==(player &p){
    return no_of_match==p.no_of_match;
}

//friend operator overloading for printing the operator
ostream & operator << (ostream &out,player &p){
    out<<"Player ID: "<<p.playerId<<endl;
    out<<"Player Name: "<<p.playerName<<endl;
    out<<"Player Age: "<<p.playerAge<<endl;
    out<<"Number of Matches: "<<p.no_of_match<<endl;
    out<<"Your score of 3 matches"<<endl;
    for(int i=0;i<3;i++){
        out<<"Score "<<i+1<<" "<<p.score[i]<<endl;
    }
    return out;
}