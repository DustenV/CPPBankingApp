// Name: Dusten Vermette
// Class: CS-210 - Programming Languages
// Professor: Bary Pollack
// Assignment: 5-1: Project 2
// Date: 04/03/2022
// File(s): Airgead_Banking_App.cpp (main)
//          Display.cpp and Display.h

#include <iostream>
#include "Display.h"


int main()
{
    // Initialize the display and user data objects
    auto display = std::make_unique<Display>();
    UserData currUserData;

    // Display the initial screen
    display->displayStartingScreen();

    while (!(display->getProgramDone())) {
        // Gather initial user input for the report
        currUserData.initInvestAmt = display->displayGetDouble("Enter the Initial Investment Amount (min $0.01): $", true, 0.01);
        currUserData.monthlyDepAmt = display->displayGetDouble("Enter the Monthly Deposit Amount (min $0.00): $", true, 0.00);
        currUserData.annualIntRate = display->displayGetDouble("Enter the Annual Interest Rate(%) (min 0.00001%): ", true, 0.00001);
        currUserData.numYearsToDisplay = display->displayGetInt("Enter the number of years to calculate (min 1): ", true, 1);


        // Display the data input screen
        display->displayDataInputMenu(currUserData);
    }

    cout << "\n\nProgram Done\n\n";
    system("pause");
    return 0;
}
