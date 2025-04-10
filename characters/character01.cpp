#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

char box = 223;
int nickX;
int nickY;
int elitesX, elitesY;
int lethoX, lethoY;
int deathClawsX, deathClawsY;
int darkGannonX, darkGannonY;

char nick01[11] = {' ' , ' ' , ' ' , ' ' ,'/' , '`' , '\\' ,' ' , ' ' , ' ', ' '};
char nick02[11] = {' ' , ' ' , '_' , '(' , '^' , ' ' , '^' , ')' , '_' , ' ' , ' '};
char nick03[11] = {'.' , '/' , '|' , ' ' , ' ' , box , ' ' , ' ' , '|' , '\\' , '.'};
char nick04[11] = {' ' , ' ' , ' ' , '\\' , '_' , box , '_' , '/' ,' ' , ' ' , ' ' };
char nick05[11] = {' ' , ' ' , ' ' , '|' , '|' , ' ' , '|' , '|' , ' ' , ' ' , ' ' };
char nick06[11] = {' ' , ' ' , ' ' , '`' , '`' , ' ' , '`' , '`' , ' ' , ' ' , ' ' };

void printnick();
void printElites();
void printLetho();
void printDeathClaws();
void printDarkGannon();

main()
{
    printnick();
    cout << endl;
    printElites();
    cout << endl;
    printLetho();
    cout << endl;
    printDeathClaws();
    cout << endl;
    printDarkGannon();


}
void printnick()
{
    char box = 223;
    cout << "    /`\\" << endl;
    cout << "  _(^ ^)_" << endl;
    cout << "./|  " << box << "  |\\." << endl;
    cout << "   \\_" << box << "_/"<< endl;
    cout << "   || ||" << endl;
    cout << "   `` ``" << endl;
}
char elites01[26] = {' ' , '(' , ',' , '"' ,'"' , ',' , ')' , ' ' , ' ' , ' ', ' ' , ' ' , ' ', ' ' , ' ' , ' ', ' ' , ' ' , ' ', ' ' , ' ' , ',' , ',' , '"' , ')' , ' '};
char elites02[26] = {'(' , ',' , '"' , '.' ,'"' , '-' , ',' , ';' , ',' , '-', '"' , ',' , '-', ',' , ',' , '-', ',' , ' ' , ' ', ' ' , '"' , '"' , '-' , '-' , '"' , ' '};
char elites03[26] = {'"' , ',' , ' ' , '(' ,'o' , ')' , ')' , ',' , '"' , ',', '"' , ',' , '-', '"' , '-' , ',', '"' , '-' , ',', ' ' , ' ' , '"' , '-' , ',' , '"' , ','};
char elites04[26] = {' ' , '"' , ',' , '/' ,'|' , ',' , '"' , ' ' , ',' , '"', ',' , ' ' , ',', ',' , '-' , '"', ' ' , '"' , '-', '-' , '"' , '"' , ',' , ',' , '"' , ' '};
char elites05[26] = {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ',' , '"' ,'"' , ',' , ' ' , ',' , '"' , '"', ',', ',' , ')' , '"' , ')' , '"' , ' ' , ' ' , ' ', ' ' , ' ' , ' '};
char elites06[26] = {' ' , ' ' , ' ' , ' ' , ' ' , '(' , '"' ,'(' , '"' , ' ' , ' ' , ',' , ' ' , ',', '-' , '"', ',' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '};
char elites07[26] = {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,  '(' , '"' ,'(' , '"' , ' ' , '(' , '"' ,'(' , '"' , ' ' , ' ' , ' ' , ' ' , ' '};

void printElites()
{
    cout << " (,'',)              ,,')" << endl;
    cout << "(,'.'-,;,-',_,,_,   ''-'" << endl;
    cout << "', (o)),',',-'-,'-,  '-,'," << endl;
    cout << " ',/|,' ,', ,,-' '--'',,'"<< endl;
    cout << "      ,'', ,'',, )')'" << endl;
    cout << "     ('('  ,  ,-'," << endl;
    cout << "            ('(' ('(' " << endl;

}
char letho01[5] = {' ' , '_' , '_' , '_' , ' '};
char letho02[5] = {'/' , '/' , '_' , '+' , '\\'};
char letho03[5] = {'/' , '[' , '\\' , ']' , '\\'};
char letho04[5] = {'_' , '/' , ' ' , '|' , '_'};
void printLetho()
{
    cout << " ___" << endl;
    cout << "//_+\\" << endl;
    cout << "/[\\]\\" << endl;
    cout << "_/ |_" << endl;
}
char deathClaws01[10] = {' ' , ' ' , ' ' , '_' ,'_' , '_' , ' ' , ' ' , ' ' , ' '};
char deathClaws02[10] = {' ' , ' ' , '(' , '0' , ' ' , 'o' , ')' , ' ' , ' ' , ' '};
char deathClaws03[10] = {' ' , ' ' , '/' , ' ' , '0' , ' ' , '\\' , ' ' , ' ' , ' '};
char deathClaws04[10] = {' ' , '/' , '/' , '|' , ' ' , '|' , '\\' , '\\' , ' ' , ' '};
char deathClaws05[10] = {'(' , '`' , ')' , ' ' , '|' , '|' , ' ' , '(' , '`' , ')'};
char deathClaws06[10] = {' ' , ' ' , ' ' , ' ' , '/' , '\\' , ' ' , ' ' , ' ' , ' ' };
char deathClaws07[10] = {' ' , ' ' , ' ' , '_' , '|' , '|'  , '_' , ' ' , ' ' , ' '};
void printDeathClaws()
{
    cout << "   ___" << endl;
    cout << "  (O o)" << endl;
    cout << "  / 0 \\" << endl;
    cout << " //| |\\\\" << endl;
    cout << "(`) || (`)" << endl;
    cout << "    /\\" << endl;
    cout << "   _||_" << endl;
}
char darkGannon01[6] = {' ' , '[' , '@' , '@' , ']' , ' '};
char darkGannon02[6] = {'/' , '|' , '_' , '_' , '|' , '\\'};
char darkGannon03[6] = {' ' , 'd' , ' ' , ' ' , 'b' , ' '};
void printDarkGannon()
{
    cout << " [@@]" << endl;
    cout << "/|__|\\" << endl;
    cout << " d  b"<< endl;
}

void printnick()
{
    gotoxy(nickX, nickY);
    for (int index = 0; index < 11; index++)
    {
        cout << nick01[index];
    }
    gotoxy(nickX, nickY + 1);
    for (int index = 0; index < 11; index++)
    {
        cout << nick02[index];
    }
    gotoxy(nickX, nickY + 2);
    for (int index = 0; index < 11; index++)
    {
        cout << nick03[index];
    }
    gotoxy(nickX, nickY + 3);
    for (int index = 0; index < 11; index++)
    {
        cout << nick04[index];
    }
    gotoxy(nickX, nickY + 4);
    for (int index = 0; index < 11; index++)
    {
        cout << nick05[index];
    }
    gotoxy(nickX, nickY + 5);
    for (int index = 0; index < 11; index++)
    {
        cout << nick06[index];
    }
}

void printElites()
{
    gotoxy(elitesX, elitesY);
    for (int index = 0; index < 26; index++)
    {
        cout << elites01[index];
    }
    gotoxy(elitesX, elitesY + 1);
    for (int index = 0; index < 26; index++)
    {
        cout << elites02[index];
    }
    gotoxy(elitesX, elitesY + 2);
    for (int index = 0; index < 26; index++)
    {
        cout << elites03[index];
    }
    gotoxy(elitesX, elitesY + 3);
    for (int index = 0; index < 26; index++)
    {
        cout << elites04[index];
    }
    gotoxy(elitesX, elitesY + 4);
    for (int index = 0; index < 26; index++)
    {
        cout << elites05[index];
    }
    gotoxy(elitesX, elitesY + 5);
    for (int index = 0; index < 26; index++)
    {
        cout << elites06[index];
    }
    gotoxy(elitesX, elitesY + 6);
    for (int index = 0; index < 26; index++)
    {
        cout << elites06[index];
    }
}

void printLetho()
{
    gotoxy(lethoX, lethoY);
    for (int index = 0; index < 5; index++)
    {
        cout << letho01[index];
    }
    gotoxy(lethoX, lethoY + 1);
    for (int index = 0; index < 5; index++)
    {
        cout << letho02[index];
    }
    gotoxy(lethoX, lethoY + 2);
    for (int index = 0; index < 5; index++)
    {
        cout << letho03[index];
    }
    gotoxy(lethoX, lethoY + 3);
    for (int index = 0; index < 5; index++)
    {
        cout << letho04[index];
    }
    gotoxy(lethoX, lethoY + 4);
    for (int index = 0; index < 5; index++)
    {
        cout << letho05[index];
    }
}

void printDeathClaws()
{
    gotoxy(deathClawsX, deathClawsY);
    for (int index = 0; index < 10; index++)
    {
        cout << deathClaws01[index];
    }
    gotoxy(deathClawsX, deathClawsY + 1);
    for (int index = 0; index < 10; index++)
    {
        cout << deathClaws02[index];
    }
    gotoxy(deathClawsX, deathClawsY + 2);
    for (int index = 0; index < 10; index++)
    {
        cout << deathClaws03[index];
    }
    gotoxy(deathClawsX, deathClawsY + 3);
    for (int index = 0; index < 10; index++)
    {
        cout << deathClaws04[index];
    }
    gotoxy(deathClawsX, deathClawsY + 4);
    for (int index = 0; index < 10; index++)
    {
        cout << deathClaws05[index];
    }
    gotoxy(deathClawsX, deathClawsY + 5);
    for (int index = 0; index < 10; index++)
    {
        cout << deathClaws06[index];
    }
    gotoxy(deathClawsX, deathClawsY + 6);
    for (int index = 0; index < 10; index++)
    {
        cout << deathClaws06[index];
    }
}

void printDarkGannon()
{
    gotoxy(darkGannonX, darkGannonY);
    for (int index = 0; index < 6; index++)
    {
        cout << darkGannon01[index];
    }
    gotoxy(darkGannonX, darkGannonY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << darkGannon02[index];
    }
    gotoxy(darkGannonX, darkGannonY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << darkGannon03[index];
    }
}
