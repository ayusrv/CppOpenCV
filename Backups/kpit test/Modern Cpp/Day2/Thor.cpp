#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();
    int thor1 = initial_tx;
    int thor2 = initial_ty;

    // game loop
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // A single line providing the move to be made: N NE E SE S SW W or NW
        string direction1 = "";
        string direction2 = "";
        if(thor1<light_x){
            direction1 = "E";
            thor1++;
        }
        else if(thor1>light_x){
            direction1 = "W";
            thor1--;
        }
        if(thor2<light_y){
            direction2="S";
            thor2++;
        }
        else if(thor2>light_y){
            direction2="N";
            thor2--;
        }
        cout << direction2<<direction1 << endl;
    }
}