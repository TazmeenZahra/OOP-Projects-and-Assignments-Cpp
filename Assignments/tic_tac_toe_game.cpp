#include <iostream>
using namespace std;
class TicTacToe
{
    char gamegrid [9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; 
    char currentplayer = 'X';

    public:
    void displayGrid ()
    {
        for (int i = 0; i < 9; i++)
        {
            cout << gamegrid [i] << ((i % 3 == 2)? "\n" : " | ");
            if (i % 3 == 2 && i < 8)
            {
                cout << "---------" << endl;
            }
        }
    }

    bool iswinner ()
    {
        const int winpaths [8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
        for (auto &p : winpaths)
        {
            if (gamegrid [p[0]] == currentplayer && gamegrid[p[0]] == gamegrid[p[1]] && gamegrid[p[1]] == gamegrid[p[2]])
            {
                return true;
            }
        }
        return false;
    }
    bool isdraw ()
    {
        for (int i = 0; i < 9; i ++)
        {
            if (gamegrid [i] == ' ')
            {
                return false;
            }
        }
        return true;
    }

    void play ()
    {
        int move;
        cout << "Welcome to Tic-Tac-Toe!" << endl;
        while (true)
        {
            displayGrid ();
            cout << "Player " << currentplayer << "! Enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || gamegrid [move - 1] != ' ')
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            gamegrid [move - 1] = currentplayer;

            if (iswinner ())
            {
                displayGrid ();
                cout << "Player " << currentplayer << " wins!" << endl;
                break;
            }
            if (isdraw ())
            {
                displayGrid ();
                cout << "It's a draw!" << endl;
                break;
            }
            currentplayer = (currentplayer == 'X')? 'O' : 'X';
        }
    }
};

int main()
{
    TicTacToe().play();
    return 0;
}
