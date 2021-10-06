#include "mylib.h"

byte BCD[16][4] ={{0,0,0,0},
{1,0,0,0},
{0,1,0,0},
{1,1,0,0},
{0,0,1,0},
{1,0,1,0},
{0,1,1,0},
{1,1,1,0},
{0,0,0,1},
{1,0,0,1},
{0,1,0,1},
{1,1,0,1},
{0,0,1,1},
{1,0,1,1},
{0,1,1,1},
{1,1,1,1}}; 

int inp1[4] = {4,5,6,7}; 
int inp2[4] = {8,9,10,11};

void Init7Seg()
{
    for(int a = 0; a < 4; a++)
    {
        pinMode(inp1[a], OUTPUT);
        pinMode(inp2[a], OUTPUT);
    }
}

void SetNumber(int number)
{
    for(int c = 0; c < 4; c++)
    {
        digitalWrite(inp1[c], BCD[(number/10)][c]);
        digitalWrite(inp2[c], BCD[(number%10)][c]);
    }
}