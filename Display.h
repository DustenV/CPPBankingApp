#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using std::fixed;
using std::cout;			using std::cin;				using std::endl;
using std::string;			using std::to_string;		
using std::ostringstream;
using std::setprecision;	
using std::vector;			

#ifndef AIRGEAD_BANKING_APP_DISPLAY_H_
#define AIRGEAD_BANKING_APP_DISPLAY_H_

// UserData Structure to store the user's information
struct UserData {
	double initInvestAmt = 0.0;
	double monthlyDepAmt = 0.0;
	double annualIntRate = 0.0;
	int numYearsToDisplay = 0;
};


/************************************************
*			 - Display Class -					*
*	This class is used to display information	*
*	on the screen. All screens for the program	*
*	are created in this class.					*
************************************************/
class Display
{
public:

	// Startup Screen(s):
	void displayStartingScreen();

	// Value Retrieval Screen(s):
	double displayGetDouble(string t_displayText, bool t_showAcctInfoHeader = true, double t_minAmount = 0.01, string t_errorText = "");
	int displayGetInt(string t_displayText, bool t_showAcctInfoHeader = true, int t_minAmount = 1, string t_errorText = "");

	// Display Screen(s):
	void displayDataInputMenu(UserData t_userData);

	// Getters/Setters for variables
	bool getProgramDone() { return m_programDone; }

private:
	// DO NOT EDIT: The following values are screen widths that should never be altered and are referenced in the program.
	bool m_programDone = false;
	const int m_dataInputScreenWidth = 50;
	const int m_reportScreenWidth = 67;
	const int m_reportYearWidth = 5;
	const int m_reportYearEndBalWidth = 25;
	const int m_reportYearEndEarnedIntWidth = 29;

	// Display Screen(s):
	void m_displayDataInput(UserData t_userData);
	void m_displayDataAlterMenu(UserData t_userData);
	void m_displayAnnualReport(UserData t_userData, bool t_showMonthlyDeposits);

};


#endif // END AIRGEAD_BANKING_APP_DISPLAY_H_

