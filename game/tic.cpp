#include<iostream>
#include<windows.h>
using namespace std;


void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void color1(int color1)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
}
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char turn = 'X';
int row, column;
bool draw = false;
void display_board() {
    system("cls");
    cout << endl;
    color1(2);
  



gotoxy(1,3);
cout<<" /$$$$$$$$ /$$                 /$$$$$$$$                        /$$$$$$$$                 "<<endl;
gotoxy(1,4);
cout<<"   | $$     /|/                |_  $$_/                       |_  $$__/                 "<<endl;
gotoxy(1,5);
cout<<"   | $$    /$$  /$$$$$$$         | $$  /$$$$$$   /$$$$$$$        |$$  /$$$$$$   /$$$$$$ "<<endl;
gotoxy(1,6);
cout<<"   | $$   | $$ /$$__/            | $$        |_  $$ /$$__/       |$$ /$$_  $$ /$$__  $$"<<endl;
gotoxy(1,7);
cout<<"   | $$   | $$| $$               | $$  /$$$$$$$| $$              |$$| $$   $$| $$$$$$$$"<<endl;
gotoxy(1,8);
cout<<"   | $$   | $$| $$               | $$   /$$_  $$| $$             |$$| $$  |$$|  $$__/"<<endl;
gotoxy(1,9);
cout<<"   | $$   | $$|  $$$$$$$         | $$|  $$$$$$$|  $$$$$$$        |$$|  $$$$$$/|  $$$$$$$"<<endl;
gotoxy(1,10);
cout<<"   |_/   |/ \\__/         |_/ \\__/ \\___/         |_/ \\__/  \\__/"<<endl;
    
    cout << endl;
    cout << endl;                                                                                      
    cout << endl;
    cout << "\tPLAYER1[X]\n \tPLAYER2[O]" << endl;
     color1(7);
    cout << endl;
    color1(1);
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "\t\t__|_|__" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "\t\t__|_|__" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "\t\t     |     |     " << endl;
    cout << endl;
    color1(7);
   
}
void player_turn() {
    int choise;

    if (turn == 'X') {
        color1(6);
        cout << "\tPLAYER 1[X] TURN :";
        color1(7);
        cin >> choise;
    }
    if (turn == 'O') {
        color1(4);
        cout << "\tPLAYER 2[O] TURN :";
        color1(7);
        cin >> choise;
    }
    switch (choise)
    {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "invalid choise..!!" << endl;
        break;
    }
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        cout << "BOX ALREADYY FILLED...!!\n PLEASE TRYY AGAIN" << endl;
        player_turn();
    }
    display_board();
}

bool gameover() {
    // check win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        return false;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }

    //game playing
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        if (board[i][j] != 'X' && board[i][j] != 'O') {
            return true;
        }
    //game draw
    draw = true;
    return false;
}

int main() {
    while (gameover()) {
        display_board();
        player_turn();
        gameover();
        
    }
    if (turn == 'X' && draw == false) {
        cout << "player 2[O] WINS!!!" << endl;
    }
    else if (turn == 'O'  && draw == false) {
        cout << "player 1[X] WINS!!!" << endl;
    }
    else {
        cout << "GAME DRAW!!" << endl;
    }


}