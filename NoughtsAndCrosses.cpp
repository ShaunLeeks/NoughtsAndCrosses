// NoughtsAndCrosses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <string>
#include "Grid.h"
#include "GameManager.h"

void tests();

int main()
{
    GameManager game{};
    game.playGame();
    //tests();
}

void tests()
{
    std::cout << "Hello World!\n";
    std::cout << "\n";
    //ClearScreen();
    bool match;
    Grid test1{};
    /*
    test1.insertState(state::Cross, 1, 1);
    test1.insertState(state::Nought, 2, 0);
    test1.insertState(state::Cross, 3, 0);
    test1.insertState(state::Cross, 1, 3);
    test1.draw();
    match = test1.matchRow(state::Cross, 0);

    Grid test2{};
    test2.insertState(state::Cross, 0, 0);
    test2.insertState(state::Cross, 0, 1);
    test2.insertState(state::Cross, 0, 2);
    test2.draw();
    match = test2.matchRow(state::Cross,0);

    Grid test3{};
    test3.insertState(state::Cross, 0, 0);
    test3.insertState(state::Cross, 1, 0);
    test3.insertState(state::Cross, 2, 0);
    test3.draw();
    match = test3.matchColumn(state::Cross, 0);

    Grid test4{};
    test4.insertState(state::Cross, 0, 0);
    test4.insertState(state::Cross, 1, 1);
    test4.insertState(state::Cross, 2, 2);
    test4.draw();
    match = test4.matchRightDiag(state::Cross);

    Grid test5{};
    test5.insertState(state::Cross, 2, 0);
    test5.insertState(state::Cross, 1, 1);
    test5.insertState(state::Cross, 0, 2);
    test5.draw();
    match = test5.matchLeftDiag(state::Cross);
    /**/
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
