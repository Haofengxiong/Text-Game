/**************************************************************************
// Student name: Hao Feng Xiong
//
// Student number: 200307144
//
// Assignment number: CS 115 Assignment #1
//
// Program name: Map.h Map.cpp Main.cpp
//
// Date written: 20/01/2013
//
// Promgram: This C++ program loading and displaying the map and make a 
// single robot walk to a point on it.
***************************************************************************/

#include"Map.h"

int main (int argc, char** argv)
{
	cout<<showpoint<<fixed<<setprecision(2);

	std::string fileName = argv[1];
	Map map;
	int robotRow,robotColumn;
	int resourceRow,resourceColumn;
	float theDistance;

	string inputString;
	int len;

	mapLoad( map, fileName );

	mapFind( map, HOME_BASE_PLAYER, robotRow, robotColumn);
	mapFind( map, RESOURCE, resourceRow, resourceColumn);

	print(map,robotRow,robotColumn);	

	theDistance = calculateDistance( robotRow, robotColumn, resourceRow, resourceColumn);

	cout<<"Next? ";
	getline(cin, inputString);
	len = inputString.length();

	while( cin )
	{
		while(len != 0)
		{
			if(inputString[0] == 'q' || inputString[0] == 'Q')
			{
				cout<<"Game over!\n";
				exit(1);
			}
			
			cout<<"Invalid comman\n";
			cout<<"Next? ";
			getline(cin, inputString);
			len = inputString.length();
		}

		while(len == 0)
		{
			int bestRow,bestColumn;
			float bestDistance = 100000;

			for(int i = robotRow - 1; i <= robotRow + 1; i++)
			{
				for(int j = robotColumn - 1; j <= robotColumn + 1; j++)
				{
					theDistance = calculateDistance( i, j, resourceRow, resourceColumn);

					if(theDistance < bestDistance)
					{
						bestDistance = theDistance;
						bestRow = i; bestColumn = j;
					}
					
				}
			}

			if( mapIsInside(map, bestRow, bestColumn) == 1  && mapIsWall(map, bestRow, bestColumn) == 0 )
			{
				mapLoad( map, fileName);
				print(map,bestRow,bestColumn);
				robotRow = bestRow; robotColumn=bestColumn;
			}
			else
			{
				print(map,robotRow,robotColumn);
			}
				
			
			cout<<"Next? ";
			getline(cin, inputString);
			len = inputString.length();
		}
	}
	
	return 0;
}