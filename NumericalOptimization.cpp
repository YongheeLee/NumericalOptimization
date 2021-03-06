// NumericalOptimization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ch1_0_bruteOptimize.h"
#include "ch3_0_intro.h"
#include "ch3_1_steplength.h"

int main()
{
    double optx1, optx2;
    BruteOptimize::optimize(optx1, optx2);

    double sol1 = LineSearchIntro::getSolve(10);
    double sol2 = LineSearchStep::getSolve(10);

    std::cout << optx1 << "    " << optx2 << "\n";
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
