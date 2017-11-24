#include"Map.h"

void mapLoad( Map theMap, string map1 )
{
	int rows, columns;
	string version;
	ifstream infile;
	infile.open( map1.c_str() );

	if( infile.fail())
	{
		cerr<<"File map1.rwm"
			<<" could not be opened."<<endl;

		exit(1);
	}

	getline(infile, version);

	if( version != "CS115RWM 0")
	{
		cout<<"It is not aa valid RWM file."<<endl;

		exit(1);
	}

	infile>>rows>>columns;

	if( rows != MAP_ROWS || columns != MAP_COLUMNS )
	{
		cout<<"Size of the map is not correct."<<endl;

		exit(1);
	}

	for(int i = 0; i < MAP_ROWS; i++)
	{
		for(int j = 0; j < MAP_COLUMNS; j++)
		{
			infile>>theMap[i][j];

			if(theMap[i][j] == '_')
			{
				theMap[i][j] = ' ';
				
			}
		}
	}
}

bool mapIsInside(const Map theMap, int row, int column)
{
	if(row >= 0 && row < 19 && column >= 0 && column < 39)
		return true;
	else
		return false;
}

char mapGetAt(const Map theMap,int row,int column)
{
	char theChar;
	theChar = theMap[row][column];

	return theChar;
}

bool mapIsWall(const Map theMap,int row,int column)
{
	if(theMap[row][column] == WALL)
		return true;
	else
		return false;
}

void mapFind(const Map theMap,char c,int& row,int& column)
{
	for(int i = 0; i < MAP_ROWS; i++)
	{
		for(int j = 0; j < MAP_COLUMNS; j++)
		{
			if(theMap[i][j] == c)
			{
				row = i;
				column = j;
			}				
		}
	}	
}


void print(Map theMap, int robotCurrentRow,int robotCurrentColumn)
{

	cout<<"+----+----+----+----+----+----+----+----+"<<endl;

	for(int i = 0; i < MAP_ROWS; i++)
	{
		if( i == 4 || i == 9 || i == 14)
		{
			cout<<"+";
		}
		else
		{
			cout<<"|";
		}

		for(int j = 0; j<MAP_COLUMNS; j++)
		{

			if (robotCurrentRow == i && robotCurrentColumn == j)
			{	
				theMap[i][j] = 'C';
			}

			cout<<theMap[i][j];
			
		}

		if( i == 4 || i == 9 || i == 14)
		{
			cout<<"+"<<endl;
		}
		else
		{
			cout<<"|"<<endl;
		}
	}

	cout<<"+----+----+----+----+----+----+----+----+"<<endl;
	cout<<" RESOURCES: 0        resources: 0"<<endl;
	cout<<"+++++++++++++++     +++++++++++++++"<<endl;
}

float calculateDistance( int robot_r, int robot_c, int resource_r, int resource_c )
{
	float distance = 0.00;
	float rr = (float) robot_r, rc = (float) robot_c, er = (float)resource_r, ec = (float) resource_c;


	distance = sqrt ((er - rr) * (er - rr) + (ec - rc) * (ec - rc));

	return distance;
}
