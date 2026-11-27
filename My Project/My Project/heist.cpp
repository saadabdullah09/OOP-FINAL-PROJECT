#include "heist.h"

void displayMainMenu()
{
    cout<<endl;
    cout << "====================================" << endl;
    cout << "          THE LOCKER HEIST          " << endl;
    cout << "====================================" << endl;

    cout << "1. New Game" << endl;
    cout << "2. View Leader/Score Board" << endl;
    cout << "3. About" << endl;
    cout << "4. Rules" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your choice = ";
}

// The cottage starts with all seven locations that the detective can explore.
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

// A separate copy of the cottage is made so the two objects don't share the same memory.
Cottage::Cottage(const Cottage& other)
{
    totalLocations = other.totalLocations;
    locations = new Location[totalLocations];

    for(int i = 0; i < totalLocations; i++)
    {
        locations[i] = other.locations[i];
    }
}

// When assigning one cottage to another, we first clear the old memory and then copy the locations.
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

// The dynamically allocated location array is no longer needed when the cottage is destroyed.
Cottage::~Cottage()
{
    delete[] locations;
}

// This shows all locations and lets the player see which ones have already been searched.
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

// We check the index first so the player can't search a location that doesn't exist.
bool Cottage::searchLocation(int index)
{
    if(index < 0 || index >= totalLocations)
    {
        cout << "Invalid location!" << endl;
        return false;
    }

    // A location can only be searched once.
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

// Every character stores their name, role, nationality and whether they are the culprit.
Character::Character(string name, string role, string nationality, bool culprit)
{
    characterName = name;
    characterRole = role;
    this->nationality = nationality;
    isCulprit = culprit;
}

// We can use this to get a character's name without directly accessing the data.
string Character::getName()
{
    return characterName;
}

// This will help us check the culprit later during the investigation.
bool Character::getCulprit()
{
    return isCulprit;
}

// The base class has a virtual destructor so derived objects can be safely destroyed.
Character::~Character()
{
}

// The victim is always given the Victim role and is never marked as the culprit.
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

// A suspect can have any role and can also be marked as the culprit.
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

// The detective is also a character but he is not/never the culprit.
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

// Business partners and other professional connections fall into this group.
BusinessRelations::BusinessRelations(string name, string role, string nationality, bool culprit)
    : Suspect(name, role, nationality, culprit)
{
}

void BusinessRelations::display()
{
    cout << "Name = " << characterName << endl;
    cout << "Role = " << characterRole << endl;
    cout << "Nationality = " << nationality << endl;
}

// The people who work around the cottage are grouped here.
HouseHelp::HouseHelp(string name, string role, string nationality, bool culprit)
    : Suspect(name, role, nationality, culprit)
{
}

void HouseHelp::display()
{
    cout << "Name = " << characterName << endl;
    cout << "Role = " << characterRole << endl;
    cout << "Nationality = " << nationality << endl;
}

// This group covers people who are personally close to the victim.
CloseRelations::CloseRelations(string name, string role, string nationality, bool culprit)
    : Suspect(name, role, nationality, culprit)
{
}

void CloseRelations::display()
{
    cout << "Name = " << characterName << endl;
    cout << "Role = " << characterRole << endl;
    cout << "Nationality = " << nationality << endl;
}

// The PA has connections to both the business and personal sides of the victim.
PA::PA(string name, string nationality, bool culprit)
    : Suspect(name, "PA", nationality, culprit),
      BusinessRelations(name, "PA", nationality, culprit),
      CloseRelations(name, "PA", nationality, culprit)
{
}

void PA::display()
{
    cout << "Name = " << characterName << endl;
    cout << "Role = " << characterRole << endl;
    cout << "Nationality = " << nationality << endl;
}

