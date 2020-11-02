// MonopolyAssignmentV3 - Sehun Babatunde.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

const char POUND = 156;

//Handles Square Data
class CSquares
{
protected:
	int mSqaureID;
	string mSquareName;

public:
	CSquares() {};
	~CSquares() {};

	//Setters
	void SetSquare(int squareID, string sqaureName)
	{
		mSqaureID = squareID;
		mSquareName = sqaureName;
	}


	//Getters
	int getSquareID() { return mSqaureID;}
	string GetName();
};

string CSquares::GetName()
{
	return mSquareName;
}

//Handles Property Data
class CProperties 
{
protected:
	int mPropertyCodeID;
	int mPropertyCost;
	int mPropetryRent;
	int mPropertyGroupID;
    string mPropetryName;

public:
	CProperties() {};
	~CProperties() {};

	//Getters 
	int GetPropertyCost() { return mPropertyCodeID; }
	int GetPropertyRent() { return mPropetryRent; }
	string GetPropertyName() { return mPropetryName; }
	int GetPropertyGroupID() { return mPropertyGroupID; }
	int GetPropertyID() { return mPropertyCodeID; }


	//Setters
	void SetPropertyID(int propertyID) { mPropertyCodeID = propertyID;}
	void SetPropertyCost(int propertyCost) { mPropertyCost = propertyCost; }
	void SetPropetryRent(int propetryRent) { mPropetryRent = propetryRent; }
	void SetPropertyGroupID(int groupID) { mPropertyGroupID = groupID; }
	void SetPropetryName(int propetryName) { mPropetryName = propetryName; }
};

//Handles Players
class CPlayer : public CProperties
{
private:
	int mCurrentFunds;
public:
	CPlayer() { mCurrentFunds = 1500; };
	~CPlayer() {};

	void AddFunds(int amount);
	void ReduceFunds(int cost);
	int GetFunds();
};

void CPlayer::AddFunds(int amount)
{
	mCurrentFunds += amount;
}

int CPlayer::GetFunds()
{
	return mCurrentFunds;
}

void CPlayer::ReduceFunds(int cost)
{
	mCurrentFunds = mCurrentFunds - cost;
}
//Monopoly Game
class CManager : public CProperties
{

public:
	 
	 CManager() {};
	 ~CManager() {};
	 void ReadtxtFile();
	 void Game();
	 int NumGen(string playerName);
};

typedef vector<CSquares*> VectorSquare;
VectorSquare pSquare;
typedef vector<CPlayer*> VectorPlayer;
VectorPlayer pPlayer;
typedef vector <CProperties*>  vectorProperties;
vectorProperties pProperty;

//Reads in Monopoly txt file  and puts them into seprate respective vectors  with error check
void CManager::ReadtxtFile()
{
	string arrayr[10];
	string   line;
	ifstream infile;
	string sqaureName;
	int    squareID;
	int squareCost;
	int squareRent;
	int squareGroup;
	int    count = 0;
	int count2 = 0;

	infile.open("Monopoly.txt");

	
	if (!infile)
	{
		cout << "Error reading file!" << endl;
	}

	if (infile.is_open())
	{
		while (getline (infile, line))
		{
			stringstream w(line);
			int i = 0;
			
			while (w.good() && i < 10)
			{
				w >> arrayr[i];
				i++;
			}

			squareID = stoi(arrayr[0]);

			switch (squareID)
			{
			case 1:
				sqaureName = arrayr[1] + " " + arrayr[2];
				squareCost = stoi(arrayr[3]);
				squareRent = stoi(arrayr[4]);
				squareGroup = stoi(arrayr[5]);

				pSquare.push_back(new CSquares);
				pSquare[count]->SetSquare(squareID, sqaureName);

				pProperty.push_back(new CProperties);
				pProperty[count2]->SetPropertyCost(squareCost);
				pProperty[count2]->SetPropetryRent(squareRent);
				pProperty[count2]->SetPropertyGroupID(squareGroup);
				count++;
				count2++;
				break;
			case 2:
				sqaureName = arrayr[1];
				pSquare.push_back(new CSquares);
				pSquare[count]->SetSquare(squareID, sqaureName);
				count++;
				break;
			case 3:
				sqaureName = arrayr[1] + " " + arrayr[2];
				squareCost = 200;
				squareRent = 10;
				squareGroup = -1;

				pSquare.push_back(new CSquares);
				pSquare[count]->SetSquare(squareID, sqaureName);

				pProperty.push_back(new CProperties);
				pProperty[count2]->SetPropertyCost(squareCost);
				pProperty[count2]->SetPropetryRent(squareRent);
				pProperty[count2]->SetPropertyGroupID(squareGroup);
				count++;
				count2++;
				break;
			case 4:
				sqaureName = arrayr[1];

				pSquare.push_back(new CSquares);
				pSquare[count]->SetSquare(squareID, sqaureName);
				count++;
				break;
			case 5:
				sqaureName = arrayr[1];
				pSquare.push_back(new CSquares);
				pSquare[count]->SetSquare(squareID, sqaureName);
				count++;
				break;
			case 6:
				sqaureName = arrayr[1];
				pSquare.push_back(new CSquares);
				pSquare[count]->SetSquare(squareID, sqaureName);
					count++;
					break;
			case 7:
				sqaureName = arrayr[1] + " " + arrayr[2] + " " + arrayr[3];
				pSquare.push_back(new CSquares);
				pSquare[count]->SetSquare(squareID, sqaureName);
				count++;
				break;
			case 8:
				sqaureName = arrayr[1];
				pSquare.push_back(new CSquares);
				pSquare[count]->SetSquare(squareID, sqaureName);
				count++;
				break;
			}

		}

	}



}
//Play out the game 
void CManager::Game()
{
	int rollCount = 0;
	int moveSpaces = 0;
	int playerLocation = 0;
	int player2Location = 0;
	int playerNum = 0;

	pPlayer.push_back(new CPlayer);
	pPlayer.push_back(new CPlayer);

	srand(5);
	cout << " " << endl;
	cout << "Monopoly Assignment - Sehun Babatunde" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Welcome to Monopoly" << endl;
	cout << " " << endl; 
	cout << " " << endl;
	while (rollCount < 40)
	{
		
		if (playerNum == 0)
		{
			moveSpaces = NumGen("dog");
			playerLocation += moveSpaces;
			if (playerLocation > 25)
			{
				playerLocation %= 26;
				pPlayer[playerNum]->AddFunds(200);
				cout << "Passed GO." << endl;

			}
			cout << "dog lands on " << pSquare[playerLocation]->GetName() << endl;
			cout << "dog has " << POUND << pPlayer[playerNum]->GetFunds() << endl;

			for (int i = 0; i < pProperty.size(); i++)
			{
				if (pSquare[playerLocation]->getSquareID() == 1 || pSquare[playerLocation]->getSquareID() == 3)
				{
					int cost = pPlayer[playerNum]->GetPropertyCost();
					
					pPlayer[playerNum]->ReduceFunds(GetProperty;
					//if (pSquare[playerNum]->getSquareID() == 1 || pSquare[playerNum]->getSquareID() == 2)
					//{
					//	pPlayer[playerNum]->ReduceFunds(GetPropertyCost());
					////	pPlayer[playerNum]->SetPropertyID(playerNum);
					//	//pPlayer[playerNum]->SetPropertyID(player);
					//
					//}
				}
			}

			playerNum = 1;
		}
		else if (playerNum == 1)
		{
			moveSpaces = NumGen("car");
			player2Location += moveSpaces;
			if (player2Location > 25)
			{
				player2Location %= 26;
				pPlayer[playerNum]->AddFunds(200);
				cout << "Passed GO." << endl;
			}
			cout << "car lands on " << pSquare[player2Location]->GetName() << endl;
			cout << "car has " << POUND << pPlayer[playerNum]->GetFunds() << endl;

			playerNum = 0;
		}
		

		rollCount++;
	}
}
// Generates a list of random numbers based on seed
int CManager::NumGen(string playerName)
{
	int diceRoll; 
	diceRoll  =  static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);

	cout << playerName << " rolls " << diceRoll << endl;

	return diceRoll;
}




int main()
{
	CManager* Manager = new CManager;
	Manager->ReadtxtFile();
	Manager->Game();

	system("pause");
}