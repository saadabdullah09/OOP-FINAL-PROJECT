
#ifndef HEIST_H
#define HEIST_H

#include<iostream>
#include<string>
using namespace std;

// Stores a single letter tile on the Scrabble board
struct Tile
{
    char tileLetter;
    bool filled;
};

// Stores a clue letter and its board position
enum class WordRow
{
    Word1,
    Word2
};

struct Clue
{
    char clueLetter;
    int cluePosition;
    WordRow clueRow;
};

// Stores information about each cottage location
struct Location
{
    string locName;
    char letterClueLoc;
    int boardPosLoc;
    WordRow locRow;
    bool locSearchFlag;
};

// Represents the current state of the game
enum class GameState
{
    Menu,
    Playing,
    Won,
    Lost,
    Exit
};

// Represents the main menu choices
enum class MenuChoice
{
    NewGame = 1,
    LeaderScoreBoard,
    About,
    Rules,
    Exit
};

void displayMainMenu();

class Cottage
{
private:
    Location* locations;
    int totalLocations;

public:
    Cottage();
    Cottage(const Cottage& other);
    Cottage& operator=(const Cottage& other);
    ~Cottage();

    void displayLocations();
    bool searchLocation(int index);
};

class Character
{
protected:
    string characterName;
    string characterRole;
    string nationality;
    bool isCulprit;

public:
    Character(string name, string role, string nationality, bool culprit);
    virtual void display() = 0;
    string getName();
    bool getCulprit();
    virtual ~Character();
};

class Victim : public Character
{
public:
    Victim(string name, string nationality);
    void display() override;
};

class Suspect : public Character
{
public:
    Suspect(string name, string role, string nationality, bool culprit);
    void display() override;
};

class Detective : public Character
{
public:
    Detective(string name, string nationality);
    void display() override;
};

#endif
