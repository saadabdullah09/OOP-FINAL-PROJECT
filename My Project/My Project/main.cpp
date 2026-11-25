
#include "heist.h"

int main()
{
    GameState gameState = GameState::Menu;
    int input;

    cout << "Welcome to THE LOCKER HEIST!" << endl;
    cout << "A mysterious theft has taken place at a wealthy owner's cottage." << endl;
    cout << "Your job is to investigate and identify the culprit." << endl;

    while(gameState != GameState::Exit)
    {
        displayMainMenu();
        cin >> input;

        MenuChoice choice = static_cast<MenuChoice>(input);

        switch(choice)
        {
            case MenuChoice::NewGame:
                cout << "\nStarting New Game..." << endl;
                break;

            case MenuChoice::LeaderScoreBoard:
                cout << "\nLeaderboard is not available yet." << endl;
                break;

            case MenuChoice::About:
                cout << "\nTHE LOCKER HEIST is a detective mystery game." << endl;
                break;

            case MenuChoice::Rules:
                cout << "\nGame rules will be added soon." << endl;
                break;

            case MenuChoice::Exit:
                gameState = GameState::Exit;
                cout << "\nExiting Game..." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }
    }

    return 0;
}
