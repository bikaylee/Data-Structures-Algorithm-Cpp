/*
 This program is a game called Tower of Hanoi. The two requirements
 of the game are only one disk can be moved at a time and larger
 sized disks should be underneath smaller sized disks. The essential
 variables are the number of disks, the source pole, destination pole,
 and the spare pole.
 
 @author: Bixia Deng
 @version: 09/10/18
 @assignment: Lab 1a
 @Editor: Xcode
 @instructor: Samuel Johnson
 */

#include <iostream>
using namespace std;


void solveTowers(int count, char source, char destination, char spare);

int main() {
    solveTowers(5, 'A', 'B', 'C');
}



/*
 Recursive function breaks down the game into four scenarios,
 1) move disks from source pole to spare pole,
 2) one disk is left on source pole,
 3) move it from source pole to destination pole,
 4) move all disks from spare pole to destination pole.
 Function takes in four parameters and recursively moving
 the disk from sour pole to destination pole.
 
 @param count - number of disks
 @param source - starting pole
 @param destination - final pole
 @param spare - spare pole
 */
void solveTowers(int count, char source, char destination, char spare)
{
    if (count == 1)
    {
        cout << "Move disk from pole " << source << " to " << destination << endl;
    }
    else
    {
        solveTowers(count - 1, source, spare, destination);
        solveTowers(1, source, destination, spare);
        solveTowers(count - 1, spare, destination, source);
    }
}
