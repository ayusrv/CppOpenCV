#ifndef PLAYER_H
#define PLAYER_H

#include<bits/stdc++.h>
using namespace std;

class player{
    private:
        //Taking player ID
        unsigned int playerId;

        //Taking player name
        char* playerName;

        //taking player age
        float playerAge;

        //taking number of match
        unsigned int no_of_match;

        //taking player rank
        unsigned int playerRank;

        //taking scores
        unsigned int score[3];

    public:

        //Default COnstructor
        player();

        //Getter setter for playerId
        unsigned int getPlayerId();
        void setPlayerId(unsigned int playerId_);

        //Getter setter for player name
        char* getPlayerName();
        void setPlayerName(char* playerName_);

        //Getter setter for player age
        float getPlayerAge();
        void setPlayerAge(float playerAge_);

        //Getter setter for number of match
        unsigned int noOfMatch();
        void setNoOfMatch(unsigned int noOfMatch);

        //Getter setter for player rank
        unsigned int getPlayerRank();
        void setPlayerRank(unsigned int playerRank_);
        void setPlayerScore(unsigned int score[3]);

        //Calcute the average score
        unsigned int calcAveScore();

        //boolean operator overloading for less than operator
        bool operator<(player p);

        //boolean operator overloading for equal equal to operator
        bool operator==(player &p);

        //int operator overloading for plus operator
        int operator+(player &p);

        //friend operator overloading for printing the operator
        friend ostream & operator <<(ostream &out, player &p);
};

#endif