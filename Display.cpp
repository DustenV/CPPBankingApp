#include "Display.h"

// Startup Screen(s):
void Display::displayStartingScreen() {

	// Custom messages to display at the beginning of the program (up to 50 characters)
	vector<string> m_messageRows = { "Welcome to the Airgead Banking App!",
										"-----------------------------------",
										"Developed by ChadaTech" };

	// Display the starting section
	cout << "******************************************************\n"
		<< "*                                                    *\n";

	// This loop prints the outer sections of the rows
	for (int i = 0; i < m_messageRows.size(); i++) {
		cout << "* ";

		// Calculate the front padding
		int messageFrontPadding = (50 - m_messageRows[i].length()) / 2;

		// Calculate the end padding
		int messageBackPadding = 50 - m_messageRows[i].length() - messageFrontPadding;

		// This loop prints the front padding 
		for (int j = 0; j < messageFrontPadding; j++)
			cout << " ";

		cout << m_messageRows[i];

		// This loop prints the end padding 
		for (int j = 0; j < messageBackPadding; j++)
			cout << " ";

		cout << " *\n";
	}

	// Display the ending section
	cout << "*                                                    *\n"
		<< "******************************************************\n\n";

	// Pauses until the user clicks a button to continue
	system("pause");
	// Clears the screen
	system("CLS");

	return;
}


// Get a double from the user (t_displayText = request text).
double Display::displayGetDouble(string t_displayText, bool t_showAcctInfoHeader, double t_minAmount, string t_errorText) {

	double userValue = 0.0;

	if (t_errorText != "") {
		cout << "ERROR: " << t_errorText << endl << endl;
	}
	
	// Clear the screen and print a header
	if (t_showAcctInfoHeader) {
		system("cls"); // 
		cout << "******************************************************\n"
			<< "* --------------< Account Information >------------- *\n\n";
	}

	cout << t_displayText;

	// Try to get a valid double
	if (cin >> userValue) {
		// Ensure the value is above the specified minimum
		if (userValue < t_minAmount)
			userValue = this->displayGetDouble(t_displayText, false, t_minAmount, "Invalid input. Value is below the minimum.");

		return userValue;
	}

	// Recursively call this function until a valid double is given
	else {
		// Clear cin and ignore the old input
		cin.clear();
		cin.ignore(128, '\n');

		// Recall the function with the error text
		userValue = this->displayGetDouble(t_displayText, false, t_minAmount, "Invalid input. Please input a valid decimal number.");

		return userValue;
	}
}


// Get a int from the user (t_displayText = request text).
int Display::displayGetInt(string t_displayText, bool t_showAcctInfoHeader, int t_minAmount, string t_errorText) {
	int userValue = 0;

	if (t_errorText != "") {
		cout << "ERROR: " << t_errorText << endl << endl;
	}

	// Clear the screen and print a header
	if (t_showAcctInfoHeader) {
		system("cls"); // 
		cout << "******************************************************\n"
			<< "* --------------< Account Information >------------- *\n\n";
	}

	cout << t_displayText;

	// Try to get a valid int
	if (cin >> userValue) {
		// Ensure the value is above the specified minimum
		if (userValue < t_minAmount)
			userValue = this->displayGetInt(t_displayText, false, t_minAmount, "Invalid input. Value is below the minimum.");

		return userValue;
	}

	// Recursively call this function until a valid int is given
	else {
		// Clear cin and ignore the old input
		cin.clear();
		cin.ignore(128, '\n');

		// Recall the function with the error text
		userValue = this->displayGetInt(t_displayText, false, t_minAmount, "Invalid input. Please input a valid whole number.");

		return userValue;
	}
}


// Displays the data input screen
void Display::m_displayDataInput(UserData t_userData) {
	// Clears the screen
	system("CLS");

	// Create a vector of the string outputs
	vector<string> outputData;


	// Create each of the input strings and insert them into the vector. Adjust the precision accordingly.
	string tempString;
	ostringstream stringStream;
	stringStream << fixed;


	// Initial Investment Amount
	stringStream << setprecision(2) << "Initial Investment Amount: $" << t_userData.initInvestAmt;
	tempString = stringStream.str();
	tempString.insert(tempString.end(), m_dataInputScreenWidth - tempString.size(), ' ');
	outputData.push_back(tempString);


	// Monthly Deposit Amount
	stringStream.str(""); // Clears the string
	stringStream << setprecision(2) << "Monthly Deposit: $" << t_userData.monthlyDepAmt;
	tempString = stringStream.str();
	tempString.insert(tempString.end(), m_dataInputScreenWidth - tempString.size(), ' ');
	outputData.push_back(tempString);


	// Annual Interest Rate
	stringStream.str(""); // Clears the string
	stringStream << setprecision(5) << "Annual Interest: " << t_userData.annualIntRate;
	tempString = stringStream.str();

	// Removes excess 0s off the end of the annual interest rate
	for (int i = tempString.size(); i > 0; i--) {
		if (tempString[i - 1] == '0') {
			tempString.pop_back();
		}
		else if (tempString[i - 1] == '.') {
			tempString.pop_back();
			break;
		}
		else {
			break;
		}
	}
	tempString.append("%");
	tempString.insert(tempString.end(), m_dataInputScreenWidth - tempString.size(), ' ');
	outputData.push_back(tempString);


	// Number of Years
	stringStream.str(""); // Clears the string
	stringStream << setprecision(0) << "Number of Years: " << t_userData.numYearsToDisplay;
	tempString = stringStream.str();
	tempString.insert(tempString.end(), m_dataInputScreenWidth - tempString.size(), ' ');
	outputData.push_back(tempString);


	// Output the header
	cout << "******************************************************\n"
		<< "* ------------------< Data Input >------------------ *\n"
		<< "*                                                    *\n";

	// Output a row for each data line in outputData
	for (int i = 0; i < outputData.size(); i++)
		cout << "* " << outputData[i] << " *\n";

	// Output the footer
	cout << "*                                                    *\n"
		<< "******************************************************\n";

	return;
}


// Displays and handles the menu and its input. Returns true if quitting and false if not
void Display::displayDataInputMenu(UserData t_userData) {
	this->m_displayDataInput(t_userData);
	int selectedMenuOption;

	cout << "\n******************************************************\n"
		<< "* ------------------< Main Menu >------------------- *\n\n"
		<< "Select an option below to continue:\n"
		<< "1: Generate Report With Monthly Deposits\n"
		<< "2: Generate Report Without Monthly Deposits\n"
		<< "3: Alter Value(s)\n"
		<< "4: Restart\n"
		<< "5: Quit\n";

	selectedMenuOption = this->displayGetInt("Menu Option: ", false, -1024);

	while(!(selectedMenuOption <= 5 && selectedMenuOption >= 1))
		selectedMenuOption = this->displayGetInt("Menu Option: ", false, -1024, "You must select one of the valid options.");

	// Menu Handling:
	if (selectedMenuOption == 1)
		this->m_displayAnnualReport(t_userData, true);
	else if (selectedMenuOption == 2)
		this->m_displayAnnualReport(t_userData, false);
	else if (selectedMenuOption == 3)
		this->m_displayDataAlterMenu(t_userData);
	else if (selectedMenuOption == 4)
		m_programDone = false; // Program is not done
	else
		m_programDone = true; //  Program is done

	return;
}


// Displays the Data Input with the Data Alteration Menu
void Display::m_displayDataAlterMenu(UserData t_userData) {
	while (1) {
		this->m_displayDataInput(t_userData);
		int selectedMenuOption;

		cout << "\n******************************************************\n"
			<< "* -----------------< Alter Values >----------------- *\n\n"
			<< "Select an option below to change the value:\n"
			<< "1: Investment Amount\n"
			<< "2: Monthly Deposit Amount\n"
			<< "3: Annual Interest Rate\n"
			<< "4: Number of Years to Display\n"
			<< "5: Back to Main Menu\n";

		selectedMenuOption = this->displayGetInt("Menu Option: ", false, -1024);

		while (!(selectedMenuOption <= 5 && selectedMenuOption >= 1))
			selectedMenuOption = this->displayGetInt("Menu Option: ", false, -1024, "You must select one of the valid options.");

		// Menu Handling:
		if (selectedMenuOption == 1)
			t_userData.initInvestAmt = this->displayGetDouble("Enter the Initial Investment Amount (min $0.01): $", true, 0.01);
		else if (selectedMenuOption == 2)
			t_userData.monthlyDepAmt = this->displayGetDouble("Enter the Monthly Deposit Amount (min $0.00): $", true, 0.00);
		else if (selectedMenuOption == 3)
			t_userData.annualIntRate = this->displayGetDouble("Enter the Annual Interest Rate(%) (min 0.00001%): ", true, 0.00001);
		else if (selectedMenuOption == 4)
			t_userData.numYearsToDisplay = this->displayGetDouble("Enter the number of years to calculate (min 1): ", true, 1);
		else
			break; //  Program is done
	}

	this->displayDataInputMenu(t_userData);
	return;
}


// Displays the annual report for the input data
void Display::m_displayAnnualReport(UserData t_userData, bool t_showMonthlyDeposits) {
	// Clear the screen
	system("cls");

	// A copy of t_userData, so it can be manipulated temporarily
	UserData reportUserData = t_userData;

	// Output the header text based on if monthlyDepAmt is 0
	if (t_showMonthlyDeposits)
		cout << "       Balance and Interest With Additional Monthly Deposits       \n";
	else {
		cout << "      Balance and Interest Without Additional Monthly Deposits     \n";
		// Set a copy of t_userData to have no monthly deposit amount
		reportUserData.monthlyDepAmt = 0.00;
	}

	// Output the rest of the header
	cout << "===================================================================\n"
		<< "  Year          Year End Balance      Year End Earned Interest     \n"
		<< "-------------------------------------------------------------------\n";

	// Initiate a structure for the monthly values that will be tracked by the system
	struct MonthTotals {
		int monthNumber;
		double openingAmount;
		double depositedAmount;
		double total;
		double interestEarned;
		double closingAmount;
	};

	vector<MonthTotals> monthlyTotals;

	// Initiate a structure for the yearly values that will be tracked by the system
	struct YearTotals {
		int yearNumber;
		double openingAmount = 0;
		double depositedAmount = 0;
		double total = 0;
		double interestEarned = 0;
		double closingAmount = 0;
	};

	vector<YearTotals> yearlyTotals;


	// Calculate the amounts for each year and print it to the console
	for (int year = 0; year < reportUserData.numYearsToDisplay; year++) {
		YearTotals currYearTotals;
		MonthTotals currMonthTotals;

		// This loop handles the monthly calculation for each year
		for (int month = 0; month < 12; month++) {

			// Add the month number
			currMonthTotals.monthNumber = (month + 1) + (12 * year);

			// Add the opening amount. On year 1, month 1, use the initial investment amount. Otherwise, get the closing amount of the previous month.
			if (month == 0 && year == 0)
				currMonthTotals.openingAmount = reportUserData.initInvestAmt;
			else
				currMonthTotals.openingAmount = monthlyTotals[(month) + (12 * year) - 1].closingAmount;

			// Add the deposited amount to the current month and the year
			currMonthTotals.depositedAmount = reportUserData.monthlyDepAmt;
			currYearTotals.depositedAmount += currMonthTotals.depositedAmount;

			// Add the total (the opening amount + deposited amount).
			currMonthTotals.total = currMonthTotals.openingAmount + currMonthTotals.depositedAmount;

			// Calculate the interest earned from the month and year
			currMonthTotals.interestEarned = currMonthTotals.total * ((reportUserData.annualIntRate / 100.0) / 12.0);
			currYearTotals.interestEarned += currMonthTotals.interestEarned;
			
			// Calculate the closing amount (total + interest)
			currMonthTotals.closingAmount = currMonthTotals.total + currMonthTotals.interestEarned;

			// Add the current month the the vector of month totals
			monthlyTotals.push_back(currMonthTotals);
		}
		// Calculate the current year
		currYearTotals.yearNumber = year + 1;

		// Calculate the opening amount of the current year
		if (year == 0)
			currMonthTotals.openingAmount = reportUserData.initInvestAmt;
		else
			currYearTotals.openingAmount = monthlyTotals[12 * year].openingAmount;

		// Calculate the total of the current year
		currYearTotals.total = currYearTotals.openingAmount + currYearTotals.depositedAmount;

		// Calculate the closing amount of the current year
		currYearTotals.closingAmount = currYearTotals.total + currYearTotals.interestEarned;

		yearlyTotals.push_back(currYearTotals);

		// Prepare the output
		ostringstream rowString;
		string tempString;
		string finalString;
		int paddingNeeded = 0;

		// Format the year and add it to the output string
		rowString << fixed << setprecision(0); 
		rowString << yearlyTotals[year].yearNumber;
		tempString = rowString.str();
		rowString.str("");
		tempString.insert(tempString.begin(), m_reportYearWidth - tempString.length(), ' ');
		rowString << " " << tempString;
		finalString = rowString.str();
		rowString.str("");

		// Format the year end balance and add it to the output string
		rowString << fixed << setprecision(2);
		rowString << yearlyTotals[year].closingAmount;
		tempString = rowString.str();
		rowString.str("");
		tempString.insert(tempString.begin(), m_reportYearEndBalWidth - tempString.length(), ' ');
		rowString << " " << tempString;
		finalString.append(rowString.str());
		rowString.str("");

		// Format the year end earned interest and add it to the output string
		rowString << fixed << setprecision(2);
		rowString << yearlyTotals[year].interestEarned;
		tempString = rowString.str();
		rowString.str("");
		tempString.insert(tempString.begin(), m_reportYearEndEarnedIntWidth - tempString.length(), ' ');
		rowString << " " << tempString;
		finalString.append(rowString.str());
		rowString.str("");

		// Output the final totals
		cout << finalString << endl << endl;
	}

	// Clear cin and ignore the old input
	cin.clear();
	cin.ignore(128, '\n');

	system("pause");
	this->displayDataInputMenu(t_userData);
}
