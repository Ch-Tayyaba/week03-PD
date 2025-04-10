#include <iostream>
#include <windows.h>
using namespace std;

void printMaze();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);

void printMalrio(int x, int y);
char mar1[3] = {' ', '0', ' '};
char mar2[3] = {'/', '|', char(209)};
char mar3[3] = {'/', ' ', '\\'};

void erase(int x, int y);

void playerMoveDown();
void playerMoveUp();
void playerMoveRight();
void playerMoveLeft();
void moveMalrioDown();

int bulletX[100];
int bulletY[100];
int bulletCount = 0;
void removeBulletFromArray(int index);
void generateBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void moveBullet();


int master_time = 0;

int malrioX = 8;
int malrioY = 6;


main()
{

    
    system("cls");
    printMaze();

    bool gameRunning = true;
    while (gameRunning)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            playerMoveLeft();
            moveMalrioDown();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            playerMoveRight();
            moveMalrioDown();
        }

        if (GetAsyncKeyState(VK_UP))
        {
            playerMoveUp();
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            playerMoveDown();
            moveMalrioDown();
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
            
        }

        if (master_time == 3)
        {
            moveBullet();
            master_time = 0;
        }
        
        Sleep(20);
        master_time++;
    }
}

void printMaze()
{
    cout << "###########################################################################################################################################################################################################  " << endl;
    cout << "###########################################################################################################################################################################################################  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                           #########                                             #########                                                                                             ##  " << endl;
    cout << "##                                           #########                                             #########                                                                                             ##  " << endl;
    cout << "##                                           #########                                             #########                                                                                             ##  " << endl;
    cout << "## ###############################################################################################################################################################################                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                         #######                                                                                                      #########                        ##  " << endl;
    cout << "##                                                         #######                                                                                                      #########                        ##  " << endl;
    cout << "##                                                         #######                                                                                                      #########                        ##  " << endl;
    cout << "##              ################       #############       ######################################################################################################################                        ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                 ###################################           ##########################                                                                                                              ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                                                                                                                                                                                                       ##  " << endl;
    cout << "##                   ################################################################      #########      ######################    ###############   ##############################                     ##  " << endl;                                                               
    cout << "##                   ################################################################      #########      ######################    ###############   ##############################                     ##  " << endl;
    cout << "##                   ################################################################      #########      ######################    ###############   ##############################                     ##  " << endl;
    cout << "##                   #########  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  ##########                     ##  " << endl;
    cout << "###########################################################################################################################################################################################################  " << endl;
    cout << "###########################################################################################################################################################################################################  " << endl;
}


void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

// PRINT OUR MAIN HERO ON SCREEN
void printMalrio(int x, int y)
{

    gotoxy(x, y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << mar1[idx];
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << mar2[idx];
    }
    gotoxy(x, y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << mar3[idx];
    }
}


// EREASE THE MALRIO FROM THE PREVIOUS LOCATION
void erase(int x, int y)
{
    gotoxy(x, y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(x, y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
}


// FUNCTION TO MOVE PLAYER LEFT
void playerMoveLeft()
{
    char nextLocation1 = getCharAtxy(malrioX - 1, malrioY + 1);
    char nextLocation2 = getCharAtxy(malrioX - 1, malrioY + 2);
    char nextLocation = getCharAtxy(malrioX - 1, malrioY);
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') && (nextLocation != '*' && nextLocation1 != '*' && nextLocation2 != '*'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX - 1;
        printMalrio(malrioX, malrioY);
    }
}


// FUNCTION TO MOVE PLYER UP
void playerMoveRight()
{
    char nextLocation = getCharAtxy(malrioX + 3, malrioY);
    char nextLocation1 = getCharAtxy(malrioX + 3, malrioY + 1);
    char nextLocation2 = getCharAtxy(malrioX + 3, malrioY + 2);
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') && (nextLocation != '*' && nextLocation1 != '*' && nextLocation2 != '*'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX + 1;
        printMalrio(malrioX, malrioY);
    }
}


// FUNCTION TO MOVE PLAYER RIGHT
void playerMoveUp()
{
    char nextLocation = getCharAtxy(malrioX, malrioY - 1);
    char nextLocation1 = getCharAtxy(malrioX + 1, malrioY - 1);
    char nextLocation2 = getCharAtxy(malrioX + 2, malrioY - 1);
    if ((nextLocation != '#' && nextLocation1 != '#' && nextLocation2 != '#') && (nextLocation != '*' && nextLocation1 != '*' && nextLocation2 != '*'))
    {
        erase(malrioX, malrioY);
        malrioY = malrioY - 1;
        printMalrio(malrioX, malrioY);
    }
}


// FUNCTION TO MOVE PLAYER DOWN
void playerMoveDown()
{
    char nextLocation = getCharAtxy(malrioX, malrioY + 3);
    char nextLocation1 = getCharAtxy(malrioX + 1, malrioY + 3);
    char nextLocation2 = getCharAtxy(malrioX + 2, malrioY + 3);

    if ((nextLocation != '#' && nextLocation1 != '#' && nextLocation2 != '#') && (nextLocation != '*' && nextLocation1 != '*' && nextLocation2 != '*'))
    {
        erase(malrioX, malrioY);
        malrioY = malrioY + 1;
        printMalrio(malrioX, malrioY);
    }
}



// GENERATE A BULLET FROM THE MALRIO GUN
void generateBullet()
{
    bulletX[bulletCount] = malrioX + 4;
    bulletY[bulletCount] = malrioY + 1;
    char next = getCharAtxy(bulletX[bulletCount],bulletY[bulletCount]);
    if(next != '#' )
    {
    gotoxy(malrioX + 4, malrioY+1);
    cout << ".";
    bulletCount++;
    }
}


// REMOVE BULLET FROM THE ARRAY OF MALRIO GUN
void removeBulletFromArray(int index)
{
    for (int x = index; x < bulletCount - 1; x++)
    {
        bulletX[x] = bulletX[x + 1];
        bulletY[x] = bulletY[x + 1];
    }
    bulletCount--;
}



// MOVEMENT OF MALRIO GUN BULLETES 
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bulletX[x] + 1, bulletY[x] + 1);
        if (next == '#')
        {
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
        else
        {
            eraseBullet(bulletX[x], bulletY[x]);
            bulletX[x] = bulletX[x] + 1;
            printBullet(bulletX[x], bulletY[x]);
        }
    }
}


// PRINT THE BULLETES OF MASTER
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
// ERASE THE BULLTE FROM THE PREVIOUS LOCATION
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}


void moveMalrioDown()
{
    bool flag=true;
    char space1;
    char space2;

    while(flag)
    {
        space1 = getCharAtxy(malrioX,malrioY+3);
        space2 = getCharAtxy(malrioX+3 ,malrioY+3);

        if(space1 == ' ' && space2 == ' ')
        {
            erase(malrioX, malrioY);
            malrioY=malrioY+1;
            printMalrio(malrioX, malrioY);
        }

        else
        {
            flag = false;
        }
    }
}