#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
main()

{
   int x = 45,y = 15;
    gotoxy(x,y);
    cout << "  ::::::::      :::     ::::    ::::  ::::::::::   ::::::::  :::     ::: :::::::::: :::::::::  "<< endl;
    y = y + 1;
    gotoxy(x,y); 
    cout << " :+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:         :+:    :+: :+:     :+: :+:        :+:    :+: "<< endl;
    y = y + 1;
    gotoxy(x,y);
    cout << " +:+         +:+   +:+  +:+ +:+:+ +:+ +:+         +:+    +:+ +:+     +:+ +:+        +:+    +:+ "<< endl;
    y = y + 1;
    gotoxy(x,y);
    cout << " :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#    +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:  "<< endl;
    y = y + 1;
    gotoxy(x,y);
    cout << " +#+   +#+# +#+     +#+ +#+       +#+ +#+         +#+    +#+  +#+   +#+  +#+        +#+    +#+ "<< endl;
    y = y + 1;
    gotoxy(x,y);
    cout << " #+#    #+# #+#     #+# #+#       #+# #+#         #+#    #+#   #+#+#+#   #+#        #+#    #+# "<< endl;
    y = y + 1;
    gotoxy(x,y);
    cout << "  ########  ###     ### ###       ### ##########   ########      ###     ########## ###    ### "<< endl;
}