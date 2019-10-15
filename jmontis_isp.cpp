// COSC 1435

#include <iostream>
using namespace std;

int main()

{
	bool valid_input = false;
    char choice;
	string words;
	int hours = 0, extra = 0, addtl = 0;
	float price = 0.0, savings1 = 0.0, savings2 = 0.0, overmath = 0.0, planCsaved = 0.0;
	float aSpent = 0.0, bSpent = 0.0, cSpent = 0.0;

	cout << ".___  ___________________  __________.__        __  tm             \n";
	cout << "|   |/   _____/\\______   \\ \\______   \\__| ____ |  | __ ___________\n";
	cout << "|   |\\_____  \\  |     ___/  |     ___/  |/ ___\\|  |/ // __ \\_  __ \\\n";
	cout << "|   |/        \\ |    |      |    |   |  \\  \\___|    <\\  ___/|  | \\/\n";
	cout << "|___/_______  / |____|      |____|   |__|\\___  >__|_ \\\\___  >__|   \n";
	cout << "            \\/                               \\/     \\/    \\/    ";

    cout << "\n\nWelcome to ISP picker" << endl;
    cout << "Please pick an ISP Plan\n\n" << endl;
    cout << "Plan A: $9.95/mo for 10 hours, +$2 each additional hour\n";
    cout << "Plan B: $14.95/mo for 20 hours, +$1 each additional hour\n";
    cout << "Plan C: $19.95/mo for unlimited use.\n";
	
	// getting plan choice from user
	
	do
	{
		cout << "\nPlease select plan A,B, or C\n" << endl;
		cin >> choice;
	} while (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'a' && choice != 'b' && choice != 'c');
		
	// checking if valid # of hours entered

	do
	{
		cout << "\n\nPlease enter a real amount of hours used\n" << endl;
		cin >> hours;
		if (isdigit(hours)) {
			valid_input = true; // using boolean to stop while loop
		}
	} while ((hours < 0) || (hours > 744) || (valid_input=false));
	
	cout << "Good work, you used " << hours << " hours.\n" << endl;
	
	// inputs have been validated (maybe)
	
	choice = toupper(choice); // make the choice uppercase for switch
	
	switch (choice)
	{
		case 'A':
			price = 9.95;
			extra = hours - 10;
			if (extra < 0) {
					extra = 0;
			}
			addtl = 2;
			break;
		case 'B':
			price = 14.95;
			extra = hours - 20;
			if (extra < 0) {
				extra = 0;
			}
			addtl = 1;
			cout << "On plan C you would have saved" << planCsaved << endl;
			break;
		case 'C':
			price = 19.95;
			addtl = 0;
		default: cin >> choice;
	}
	
	overmath = price + (extra * addtl);  // math to see overage costs
	aSpent = (9.95 + (extra * 2)); // each plan spent costs even if theoretical
	bSpent = (14.95 +(extra * 1));
	cSpent = 19.95;

	// see if they had savings or not
	
	if (choice == 'A' && aSpent > 9.95) {
		savings1 = (aSpent - bSpent);
		savings2 = (aSpent - cSpent);
		if (savings1 > 0) {
			cout << "You would have saved $" << savings1 << " on plan B.\n";
			cout << "You would have saved $" << savings2 << " on plan C.\n";
		}
	}
	if (choice == 'B' && price >= 14.95) {
			savings1 = (bSpent - cSpent);
			savings2 = (bSpent - cSpent);
			if (savings2 <= 0) {
					savings2 = 0;
				}
			if (savings1 > 0) {
				cout << "You would have saved $" << savings1 << " on plan B.\n";
				cout << "You would have saved $" << savings2 << " on plan C.\n";
		} else if (choice == 'C') {
			cout << "Enjoy your unlimited use plan of $19.95/mo!";
		}
	}
	
	cout << "\nYou selected choice " << choice << "!\n" << "It costs $" << price << " a month, additional fees may apply, see above.\n\n";
	
	if (choice == 'A') {
		
		cout << " and you have gone over by " << extra << " hours.\n" << endl;
	} else if (choice == 'B') {
		cout << " and you have gone over by " << extra << " hours.\n" << endl;
	}
    cout << "You owe a total of $" << overmath << "\n\n" << endl;
    
    cout << "Thank you for using....\n\n";
    cout << ".___  ___________________  __________.__        __        tm         \n";
	cout << "|   |/   _____/\\______   \\ \\______   \\__| ____ |  | __ ___________\n";
	cout << "|   |\\_____  \\  |     ___/  |     ___/  |/ ___\\|  |/ // __ \\_  __ \\\n";
	cout << "|   |/        \\ |    |      |    |   |  \\  \\___|    <\\  ___/|  | \\/\n";
	cout << "|___/_______  / |____|      |____|   |__|\\___  >__|_ \\\\___  >__|   \n";
	cout << "            \\/                               \\/     \\/    \\/    ";

    
    return 0;
}

