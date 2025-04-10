#include <iostream>
#include<windows.h>
#include<math.h>
#include<conio.h>
using namespace std;

int playerX = 5 , playerY = 5;
int enemyX = 10 , enemyY = 10;

void printPlayer();
void erasePlayer();
void printEnemy();
void eraseEnemy();

void movePlayerLeft();
void movePlayerRight();
void movePlayerUp();
void movePlayerDown();

void moveEnemyLeft();
void moveEnemyRight();
void moveEnemyUp();
void moveEnemyDown();

int calculateChaseX(int,int,int,int);
int calculateChaseY(int,int,int,int);
void moveEnemy();

void gotoxy(int x, int y);

main()
{
    system("cls");
    bool flag03 = true;
    printPlayer();
    printEnemy();
    // getch();
    while (flag03)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
            // moveEnemy();
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
            // moveEnemy();
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUp();
            // moveEnemy();
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
            // moveEnemy();
        }
         moveEnemy();
        Sleep(90);
    }
}
void printPlayer()
{
    gotoxy(playerX,playerY);
    cout << "P";
}
void erasePlayer()
{
    gotoxy(playerX,playerY);
    cout << " ";
}
void printEnemy()
{
    gotoxy(enemyX , enemyY);
    cout << "E";
}
void eraseEnemy()
{
    gotoxy(enemyX , enemyY);
    cout << " ";
}

void movePlayerLeft()
{
    erasePlayer();
    playerX = playerX - 1;
    printPlayer();
}
void movePlayerRight()
{
    erasePlayer();
    playerX = playerX + 1;
    printPlayer();
}
void movePlayerUp()
{
    erasePlayer();
    playerY = playerY - 1;
    printPlayer();
}
void movePlayerDown()
{
    erasePlayer();
    playerY = playerY + 1;
    printPlayer();
}
void moveEnemyLeft()
{
    eraseEnemy();
    enemyX = enemyX - 1;
    printEnemy();
}
void moveEnemyRight()
{
    eraseEnemy();
    enemyX = enemyX + 1;
    printEnemy();
}
void moveEnemyUp()
{
    eraseEnemy();
    enemyY = enemyY - 1;
    printEnemy();
}
void moveEnemyDown()
{
    eraseEnemy();
    enemyY = enemyY + 1;
    printEnemy();
}
int calculateChaseX(int enemyX , int playerX ,int enemyY , int playerY)
{
    int player = playerX - 1;
    return enemyX - player;
    // float x;
    // float magnitude;
    // float magnitudeX , magnitudeY;
    // magnitudeX = (enemyX - playerX) * (enemyX - playerX);
    // magnitudeY = (enemyY - playerY) * (enemyY - playerY);
    // magnitude = sqrt(magnitudeX + magnitudeY);
    // x = enemyX - playerX;
    // x = x/magnitude;
    // return ceil(x);
}
int calculateChaseY(int enemyX , int playerX ,int enemyY , int playerY)
{
    int player = playerY - 1;
    return enemyY - player;
    // float y;
    // float magnitude;
    // float magnitudeX , magnitudeY;
    // magnitudeX = (enemyX - playerX) * (enemyX - playerX);
    // magnitudeY = (enemyY - playerY) * (enemyY - playerY);
    // magnitude = sqrt(magnitudeX + magnitudeY);
    // y = enemyY - playerY;
    // y = y/magnitude;
    // return ceil(y);  
}
void moveEnemy()
{
    int chaseX , chaseY;
    chaseX = calculateChaseX(enemyX , playerX ,enemyY , playerY);
    chaseY = calculateChaseY(enemyX , playerX ,enemyY , playerY);
    if(chaseX == 0 && chaseY > 0)
    {
        for(int idx = 1; idx <= chaseY; idx++)
        {
            moveEnemyUp();  
            Sleep(50); 
        }
    }
    if(chaseX == 0 && chaseY < 0)
    {
        chaseY = -1 * chaseY;
        for(int idx = 1; idx <= chaseY; idx++)
        {
            moveEnemyDown(); 
            Sleep(50);  
        }
    }
    if(chaseX > 0 && chaseY > 0)
    {
        for(int idx = 1; idx <= chaseX; idx++)
        {
            moveEnemyLeft();
            Sleep(50);
        }
        for(int idx = 1; idx <= chaseY; idx++)
        {
            moveEnemyUp();  
            Sleep(50); 
        }
    }
     if(chaseX > 0 && chaseY < 0)
    {
        chaseY = -1 * chaseY;
        for(int idx = 1; idx <= chaseX; idx++)
        {
            moveEnemyLeft();
            Sleep(50);
        }
        for(int idx = 1; idx <= chaseY; idx++)
        {
            moveEnemyDown(); 
            Sleep(50);  
        }
        
    }
    if(chaseX < 0 && chaseY == 0)
    {
        chaseX = -1 * chaseX;
        for(int idx = 1; idx <= chaseX; idx++)
        {
            moveEnemyRight();
            Sleep(50);
        }
    }
    if(chaseX > 0 && chaseY == 0)
    {
        for(int idx = 1; idx <= chaseX; idx++)
        {
            moveEnemyLeft();
            Sleep(50);
        }
    }
    if(chaseX < 0 && chaseY > 0)
    {
        chaseX = -1 * chaseX;
        for(int idx = 1; idx <= chaseX; idx++)
        {
            moveEnemyRight();
            Sleep(50);
        }
        for(int idx = 1; idx <= chaseY; idx++)
        {
            moveEnemyUp();
            Sleep(50);   
        }
    }
    if(chaseX < 0 && chaseY < 0)
    {
        chaseX = -1 * chaseX;
        chaseY = -1 * chaseY;
        for(int idx = 1; idx <= chaseX; idx++)
        {
            moveEnemyRight();
            Sleep(50);
        }
        for(int idx = 1; idx <= chaseY; idx++)
        {
            moveEnemyDown(); 
            Sleep(50);  
        } 
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}