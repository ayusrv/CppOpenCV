#include "Player.cpp"
#include <bits/stdc++.h>
using namespace std;

class excep : public exception
{
public:
    const char *what()
    {
        return "You have entered wrong value";
    }
};

int main()
{
    player p[2];
    for (int i = 0; i < 2; i++)
    {
        //Goto statement
        wrongimp:

        //entering the details
        cout << "Enter Player ID: ";
        int playerId;
        cin >> playerId;
        char *playerName = new char[20];
        cout << "Enter Player Name: ";
        cin >> playerName;
        int playerAge;
        cout << "Enter Player Age: ";
        cin >> playerAge;
        cout << "Enter Number of Match: ";
        int no_of_match;
        cin >> no_of_match;
        cout << "Enter PLayer Rank: ";
        int rank;
        cin >> rank;
        unsigned int score[3];
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter score " << i + 1 << ": ";
            cin >> score[i];
        }

        //try catch for checking the edge cases
        try
        {
            //If any value is negative throw the error
            if (playerId < 0 || playerAge < 0 || no_of_match < 0 || rank < 0 || score[0] < 0 || score[1] < 0 || score[2] < 0)
            {
                excep e;
                throw e;
            }

            //if all the values is correct put the values
            p[i].setPlayerId(playerId);
            p[i].setPlayerName(playerName);
            p[i].setPlayerAge(playerAge);
            p[i].setNoOfMatch(no_of_match);
            p[i].setPlayerRank(rank);
            p[i].setPlayerScore(score);
        }

        //catch the exception then send to goto
        catch (excep e)
        {
            cout << e.what() << endl;
            goto wrongimp;
        }
    }

    //Printing the values
    for (int i = 0; i < 2; i++)
    {
        cout << p[i];
    }

    //comapring two average
    cout << "To Companre average of two player: " << endl;
    if (p[0].operator<(p[1]))
    {
        cout << "Average of 2nd player is more" << endl;
    }
    else
    {
        cout << "Average of first player is more" << endl;
    }

    //cheking if two player have same matches or not
    cout<<"Checkin number of matches"<<endl;
    if (p[0].operator==(p[1]))
    {
        cout << "Both player have same number of matches" << endl;
    }
    else
    {
        cout << "Both player have different number of matches" << endl;
    }

    //priting the avearge of two playes
    cout << "The average of both the players " << p[0].operator+(p[1]) << endl;
}