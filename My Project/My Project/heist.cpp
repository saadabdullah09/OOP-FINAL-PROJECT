
#include "heist.h"

void displayMainMenu()
{
    cout<<endl;
    cout << "====================================" << endl;
    cout << "          THE LOCKER HEIST" << endl;
    cout << "====================================" << endl;

    cout << "1. New Game" << endl;
    cout << "2. View Leader/Score Board" << endl;
    cout << "3. About" << endl;
    cout << "4. Rules" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your choice = ";
}

Cottage::Cottage()
{
    totalLocations = 7;
    locations = new Location[totalLocations];

    locations[0] = {"Garden", ' ', 0, WordRow::Word1, false};
    locations[1] = {"Kitchen", ' ', 0, WordRow::Word1, false};
    locations[2] = {"Dining Room", ' ', 0, WordRow::Word1, false};
    locations[3] = {"Living Room", ' ', 0, WordRow::Word1, false};
    locations[4] = {"Bedroom 1", ' ', 0, WordRow::Word1, false};
    locations[5] = {"Bedroom 2", ' ', 0, WordRow::Word1, false};
    locations[6] = {"Study Room", ' ', 0, WordRow::Word1, false};
}

Cottage::Cottage(const Cottage& other)
{
    totalLocations = other.totalLocations;
    locations = new Location[totalLocations];

    for(int i = 0; i < totalLocations; i++)
    {
        locations[i] = other.locations[i];
    }
}

Cottage& Cottage::operator=(const Cottage& other)
{
    if(this != &other)
    {
        delete[] locations;

        totalLocations = other.totalLocations;
        locations = new Location[totalLocations];

        for(int i = 0; i < totalLocations; i++)
        {
            locations[i] = other.locations[i];
        }
    }

    return *this;
}

Cottage::~Cottage()
{
    delete[] locations;
}

void Cottage::displayLocations()
{
    cout<<endl;
    cout << "Available Locations" << endl;

    for(int i = 0; i < totalLocations; i++)
    {
        cout << i + 1 << ". " << locations[i].locName;

        if(locations[i].locSearchFlag)
        {
            cout << " (Searched)";
        }

        cout << endl;
    }
}

bool Cottage::searchLocation(int index)
{
    if(index < 0 || index >= totalLocations)
    {
        cout << "Invalid location!" << endl;
        return false;
    }

    if(locations[index].locSearchFlag)
    {
        cout << "This location has already been searched!" << endl;
        return false;
    }

    locations[index].locSearchFlag = true;
    cout<<endl;
    cout << "You searched " << locations[index].locName << "." << endl;

    return true;
}

Character::Character(string name, string role, string nationality, bool culprit)
{
    characterName = name;
    characterRole = role;
    this->nationality = nationality;
    isCulprit = culprit;
}

string Character::getName()
{
    return characterName;
}

bool Character::getCulprit()
{
    return isCulprit;
}

Character::~Character()
{
}

Victim::Victim(string name, string nationality)
    : Character(name, "Victim", nationality, false)
{
}

void Victim::display()
{
    cout << "Name = " << characterName << endl;
    cout << "Role = " << characterRole << endl;
    cout << "Nationality = " << nationality << endl;
}

Suspect::Suspect(string name, string role, string nationality, bool culprit)
    : Character(name, role, nationality, culprit)
{
}

void Suspect::display()
{
    cout << "Name = " << characterName << endl;
    cout << "Role = " << characterRole << endl;
    cout << "Nationality = " << nationality << endl;
}

Detective::Detective(string name, string nationality)
    : Character(name, "Detective", nationality, false)
{
}

void Detective::display()
{
    cout << "Name = " << characterName << endl;
    cout << "Role = " << characterRole << endl;
    cout << "Nationality = " << nationality << endl;
}