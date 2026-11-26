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
            {
                Cottage cottage;
                int locationChoice;

                cout << endl << "Starting New Game..." << endl;

                while(true)
                {
                    cottage.displayLocations();

                    cout << endl << "Enter location number to search (0 to return) = ";
                    cin >> locationChoice;

                    if(locationChoice == 0)
                    {
                        break;
                    }

                    cottage.searchLocation(locationChoice - 1);
                }

                break;
            }

            case MenuChoice::LeaderScoreBoard:
                cout << endl << "Leaderboard is not available yet." << endl;
                break;

            case MenuChoice::About:
                cout << endl << "THE LOCKER HEIST is a detective mystery game." << endl;
                break;

            case MenuChoice::Rules:
                cout << endl << "Game rules will be added soon." << endl;
                break;

            case MenuChoice::Exit:
                gameState = GameState::Exit;
                cout << endl << "Exiting Game..." << endl;
                break;

            default:
                cout << endl << "Invalid choice!" << endl;
        }
    }

    return 0;
}