#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAP_ROWS = 19, MAP_COLUMNS = 39;
const char HOME_BASE_PLAYER = 'H', HOME_BASE_OPPONENT = 'h', RESOURCE = '*', WALL = '#';
const int NO_SUCH_ELEMENT = -1000000000;

typedef char Map[MAP_ROWS][MAP_COLUMNS];

void mapLoad( Map theMap, string map1 );  //open map1.rwm and load contents in array, it takes one map type, one string parameters
bool mapIsInside(const Map theMap,int row,int column);  //test position to see if it is inside the map or not, it takes one map type,two ints parameters
char mapGetAt(const Map theMap,int row,int column);  //return the value of specified position in map, it takes one map type, two ints parameters
bool mapIsWall(const Map theMap,int row,int column);  //test position to see if it is wall or not, it takes one map , two ints parameters
void mapFind(const Map theMap,char c,int& row,int& column); //fin specified value's position, it takes one map, one char, two ints parameters

void print(Map, int,int); //print the map's contents to screen, ita takes one map, two ints parameters
float calculateDistance( int, int, int, int ); // calculate the distance between robot and resource, it takes four ints parameters