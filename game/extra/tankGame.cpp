#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

int option;
char box = 219;
char tank1[6] = {box, box, box, '-', '-', '>'};
char tank2[6] = {'0', ' ', '0', ' ', ' ', ' '};

char enemy1[6] = {' ', ' ', ' ', '-', '-', '-'};
char enemy2[6] = {'<', '=', '=', '(', '-', ')'};
char enemy3[6] = {' ', ' ', ' ', '\\', '@', '/'};
char enemy4[6] = {' ', ' ', ' ', '*', '*', '*'};

int bulletX[100];
int bulletY[100];
int enemyBulletX[100];
int enemyBulletY[100];
int bulletCount = 0;
int enemyBulletCount = 0;

int tankX = 5;
int tankY = 5;
int enemyX = 30;
int enemyY = 10;

string enemyDirection = "Up";
int timer = 0;
int score = 0;

void displayTank();
void printLogo();
void printMenu();
void printSubMenu();
void printKeys();

void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void printTank();
void eraseTank();
void printMaze();
void moveBullet();
void moveEnemyBullet();
void generateBullet();
void removeBulletFromArray(int index);
void removeEnemyBulletFromArray(int index);
void moveTankUp();
void moveTankDown();
void moveTankLeft();
void moveTankRight();
void generateEnemyBullet();

void moveEnemy();
void printEnemy();
void eraseEnemy();

void addScore();
void printScore();

void bulletCollisionWithEnemy();
void printBullet(int x, int y);
void eraseBullet(int x, int y);



main()
{
    bool flag = true;
    bool flag02;
    system("cls");
    printLogo();
    displayTank();
    getch();
    while(flag)
    {
        system("cls");
        printLogo();
        printMenu();
        cin >> option;
        if(option == 1)
        {
            system("cls");
            printMaze();
            printTank();
            printEnemy();
            while (true)
            {
                printScore();
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveTankLeft();
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveTankRight();
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveTankUp();
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    moveTankDown();
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    generateBullet();
                }

                if (timer == 3)
                {
                    moveEnemy();
                    // generateEnemyBullet();
                    // Sleep(90);
                    // moveEnemyBullet();
                    timer = 0;
                }
                moveBullet();
                bulletCollisionWithEnemy();
                timer++;
                Sleep(90);
            } 
        }
        else if (option == 2)
        {
            flag02 = true;
            while(flag02)
            {
                system("cls");
                printLogo();
                printSubMenu();
                cin >> option;
                if(option == 1)
                {
                    system("cls");
                    printLogo();
                    printKeys();
                    getch();
                    flag02 = false;
                }
                else if(option == 2)
                {
                    cout << "Here are some instructions." << endl;
                    getch();
                    flag02 = false;
                }
                else if (option == 3)
                {
                    flag02 = false;
                }
            }
        }
        else if (option == 3)
        {
            flag = false;
        }
    }

}
void displayTank()
{

    cout << "             .::.                                                                   " << endl;      
    cout << "       .=++-::-++:                                                                  " << endl;    
    cout << "     .*=:=#%@@#: *%-                                                                " << endl;    
    cout << "    +*.*%::*@@@@. %=*+.                                                             " << endl;    
    cout << "   ++ %@@@#- -#@..#:=.++:                                                           " << endl;    
    cout << "  .@ ##**%@@@**= %: .:: =*:                                                         " << endl;    
    cout << "  :% #-.=***@%:.#-  .  : =*                                                         " << endl;    
    cout << "   %: ++==*+:.+*..:. ::: %%*-                                                       " << endl;    
    cout << "    ++-:.:-+*+.       ::#@:.:*=                                                     " << endl;    
    cout << "      :+%*-::-::   .:..#@=+   .++.                                                  " << endl;    
    cout << "         .=++-:.::  :*@%:-::    .+*:.:--====+==+=====-:                             " << endl;    
    cout << "             :++==+*@%+++=.        -%*:    ..        *+=++-.                        " << endl;    
    cout << "                     :+#+:-::        -****++++***+   @ .-..-++-.                    " << endl;    
    cout << "                        :+*- ::.      .:*+     ::@  -* %===++--=++:                 " << endl;    
    cout << "                           -%*- :::::  .+%:     -*  *:.@ .   .-++ %                 " << endl;     
    cout << "                           #@@@@*:.. :=+*=.     *:  # ==.::::..:*-+-                " << endl;    
    cout << "                          *++%%%%%##*+++. - .-==%+=*@@@=@@@@@@@@@#-%                " << endl;    
    cout << "                   ..::-=*%=.-#:=+:-=====++*+. .      -%+-=+#%@@@@+@-               " << endl;    
    cout << "               =*==-:::..*++%==-:::.     :*:. -   . :*= :=-:.  :-+*@#               " << endl;    
    cout << "             .*- -.  :.:%+*=.     .     *#-+-=:.:=+*- -#=#=:-++*=:. :++=:           " << endl;    
    cout << "            +%--+-*=***@@@:.: .  --   ..%---------*+=%#.+##@%##%::=+*=: -++:        " << endl;    
    cout << "            #*==---===+@%.:=::+-++*==+*=#+===++===#%-:#%+::--:+#==++%:-++-.-+=.     " << endl;    
    cout << "            .@=+:+-..-+*@=-:=..     -  ##++*++*+*%%=*=*--#%*%*+ #*=-:-#*=%+*-.=*.   " << endl;    
    cout << "            +%==*#==*=*-:%.  :  ::.  : .#.: -::-.-* *:# #*# =%%.+@@@@@*###+:-%-%.   " << endl;    
    cout << "             ++ .:.=:  *==%. :   :-:   -.%: .  =  +++@@.=%#+%*# #.:@==*#%**#@*=@.   " << endl;    
    cout << "              =%++=++*==#%.%-+----++==+++=@**=*==#=#=.%#=:===::##++@@%#%+#+**@+.#   " << endl;    
    cout << "               =*- :.::: =* %+##*##=:#@@@@@@-:-...- #.:%-%##*+%=**+#@@%@***+#%*+@:  " << endl;   
    cout << "                -#++#+++*=#%=###+*+@##*@@@@@@+++=#==*@*=@**=@#%+**+%%=#+@@%@##=*.   " << endl;    
    cout << "                 :#  ..:. :-* *###%*%#%#@@@@@@- .:.=:.# +@#%**+%#*@*+%%%*%%::#-     " << endl;    
    cout << "                  :%-*--+---+%%+==+%====%==#@@@==:=-::*%#:::-@-:::%:::%:::%*+       " << endl;    
    cout << "                    ...........................::::::::::::::::::::::::::::.        " << endl;    
                                                                                         
}
void printLogo()
{

    cout << " :::::::::::     :::     ::::    ::: :::    :::  :::       :::     :::     :::::::::  " << endl;
    cout << "     :+:       :+: :+:   :+:+:   :+: :+:   :+:   :+:       :+:   :+: :+:   :+:    :+: " << endl;
    cout << "     +:+      +:+   +:+  :+:+:+  +:+ +:+  +:+    +:+       +:+  +:+   +:+  +:+    +:+ " << endl;
    cout << "     +#+     +#++:++#++: +#+ +:+ +#+ +#++:++     +#+  +:+  +#+ +#++:++#++: +#++:++#:  " << endl;
    cout << "     +#+     +#+     +#+ +#+  +#+#+# +#+  +#+    +#+ +#+#+ +#+ +#+     +#+ +#+    +#+ " << endl;
    cout << "     #+#     #+#     #+# #+#   #+#+# #+#   #+#    #+#+# #+#+#  #+#     #+# #+#    #+# " << endl;
    cout << "     ###     ###     ### ###    #### ###    ###    ###   ###   ###     ### ###    ### " << endl;

}
void printMenu()
{
    cout << "______________________________________________________________________________________" << endl << endl;
    cout << " MENU " << endl;
    cout << "_______________________" << endl;
    cout << "1. Start" << endl;
    cout << "2. Option" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter option : ";
}
void printSubMenu()
{
    cout << "______________________________________________________________________________________" << endl;
    cout << "1. Keys" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Exit " << endl;
    cout << "Enter option: ";
}
void printKeys()
{
    cout << "______________________________________________________________________________________" << endl << endl;
    cout << " KEYS " << endl;
    cout << "_______________________" << endl;
    cout << "1. UP             Go up" << endl;
    cout << "2. DOWN           Go down " << endl;
    cout << "3. LEFT           Go left " << endl;
    cout << "4. RIGHT          Go right" << endl;
    cout << "5. SPACE          Fire user" << endl;
    cout << "6. ESC            Exit Game" << endl;
    cout << "Press any key to continue." << endl;
}
void printScore()
{
    gotoxy(45, 8);
    cout << "Score: " << score;
}

void moveEnemy()
{

    if (enemyDirection == "Up")
    {
        char next = getCharAtxy(enemyX, enemyY - 1);
        if (next == ' ')
        {
            eraseEnemy();
            enemyY--;
            printEnemy();
        }
        if (next == '#')
        {
            enemyDirection = "Down";
        }
    }
    if (enemyDirection == "Down")
    {
        char next = getCharAtxy(enemyX, enemyY + 4);
        if (next == ' ')
        {
            eraseEnemy();
            enemyY++;
            printEnemy();
        }
        if (next == '#')
        {
            enemyDirection = "Up";
        }
    }
}

void printEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy1[index];
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy2[index];
    }
    gotoxy(enemyX, enemyY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy3[index];
    }
    gotoxy(enemyX, enemyY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy4[index];
    }
}
void eraseEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}

void moveTankLeft()
{
    char next = getCharAtxy(tankX - 1, tankY);
    if (next == ' ')
    {
        eraseTank();
        tankX = tankX - 1;
        printTank();
    }
}

void moveTankRight()
{
    char next = getCharAtxy(tankX + 6, tankY);
    if (next == ' ')
    {
        eraseTank();
        tankX = tankX + 1;
        printTank();
    }
}

void moveTankUp()
{
    char next = getCharAtxy(tankX, tankY - 1);
    if (next == ' ')
    {
        eraseTank();
        tankY = tankY - 1;
        printTank();
    }
}

void moveTankDown()
{
    char next = getCharAtxy(tankX, tankY + 2);
    if (next == ' ')
    {
        eraseTank();
        tankY = tankY + 1;
        printTank();
    }
}

void generateBullet()
{
    bulletX[bulletCount] = tankX + 7;
    bulletY[bulletCount] = tankY;
    gotoxy(tankX + 7, tankY);
    cout << ".";
    bulletCount++;
}

void generateEnemyBullet()
{
    enemyBulletX[enemyBulletCount] = enemyX - 1;
    enemyBulletY[enemyBulletCount] = tankY + 1;
    gotoxy(enemyX - 1,enemyY + 1);
    cout << ".";
    enemyBulletCount++;
}

void removeBulletFromArray(int index)
{
    for (int x = index; x < bulletCount - 1; x++)
    {
        bulletX[x] = bulletX[x + 1];
        bulletY[x] = bulletY[x + 1];
    }
    bulletCount--;
}

void removeEnemyBulletFromArray(int index)
{
    for (int x = index; x < enemyBulletCount - 1; x++)
    {
        enemyBulletX[x] = enemyBulletX[x + 1];
        enemyBulletY[x] = enemyBulletY[x + 1];
    }
    enemyBulletCount--;
}

void printTank()
{
    gotoxy(tankX, tankY);
    for (int index = 0; index < 6; index++)
    {
        cout << tank1[index];
    }
    gotoxy(tankX, tankY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << tank2[index];
    }
}

void eraseTank()
{
    gotoxy(tankX, tankY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}

void printMaze()
{
    cout << "#########################################" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#                                       #" << endl;
    cout << "#########################################" << endl;
}

void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bulletX[x] + 1, bulletY[x] + 1);
        if (next != ' ')
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

void moveEnemyBullet()
{
    for (int x = 0; x < enemyBulletCount; x++)
    {
        char enemyNext = getCharAtxy(enemyBulletX[x] , enemyBulletY[x] );
        if (enemyNext != ' ')
        {
            eraseBullet(enemyBulletX[x], enemyBulletY[x]);
            removeBulletFromArray(x);
        }
        else
        {
            eraseBullet(enemyBulletX[x], enemyBulletY[x]);
            enemyBulletX[x] = enemyBulletX[x] - 1;
            printBullet(enemyBulletX[x], enemyBulletY[x]);
        }
    }
}

void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void bulletCollisionWithEnemy()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletX[x] + 1 == enemyX && (bulletY[x] == enemyY || bulletY[x] == enemyY + 1 || bulletY[x] == enemyY + 2 || bulletY[x] == enemyY + 3))
        {
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
    }
}

void addScore()
{
    score++;
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

void gotoxy(int x , int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}