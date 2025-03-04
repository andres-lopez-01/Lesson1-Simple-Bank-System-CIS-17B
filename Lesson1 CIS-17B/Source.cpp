//CIS-17B
//Andres Lopez
//03/03/2025
#include <iostream>

using namespace std;

class BankAccount { //Bank Account class
private:
	string AccountHolderName; //name
	int accountNumber; //account number, not implemented in program
	double balance; //balance

public:
	BankAccount(string name,double balance){ //constructor
		AccountHolderName = name;
		accountNumber = 0;
		this->balance = balance;
	}
	void deposit(double);
	void withdraw(double);
	double getBalance();
};

void BankAccount::deposit(double deposit) { //deposit function
	if (deposit > 0) { //checks if deposit is positive number
		balance += deposit;
	}
	else
		throw invalid_argument("Deposit amount must be greater than zero."); //errors

}

void BankAccount::withdraw(double amount) { //withdraw function
	if (amount >= balance) { //checks if amount is less than balance
		balance -= amount;
	}
	else
		throw out_of_range("Insufficient funds to complete the withdrawal.");//errors

}

double BankAccount::getBalance() { //get balance function
	return balance;
}

//function parameters
void menu();

int main() //main function
{
	bool run = true;
	BankAccount *userAccount = nullptr;

	//function definitions
	string name;
	double initDeposit;
	double depositAmount;
	double withdrawAmount;

	cout << "Welcome to Simple Bank System" << endl;

	while (run){ //runs until user chooses 5(Exit)

		menu();
		int choice = 0;
		cin >> choice;
		if (choice < 1 || choice > 5) //checks for valid choice input
			cout << "\nInvalid choice!" << endl << endl;

		switch (choice) {
		case 1: //case 1 to create account
			cout << "Enter account holder name: ";
			cin >> name;

			cout << "Enter initial deposit: ";
			cin >> initDeposit;
			if (initDeposit >= 0) { //checks if initial deposite is positive number
				userAccount = new BankAccount(name, initDeposit);
				cout << "\nAccount created successfully!" << endl << endl;
			}
			else
				cout << "\nInvalid Deposit Amount" << endl << endl;//invalid if deposit is wrong

			break;

		case 2: //case 2 deposite money into account
			if (!userAccount) { //checks if Account has been created
				cout << "\nError, You must create an Account first!" << endl << endl;
				break;
			}
			cout << "Enter amount to deposit: "; //ask user to input amount
			cin >> depositAmount;
			if (depositAmount < 0 || cin.fail()) { //checks if amount is valid number
				cin.clear();
				cout << "\nError, Invalid Deposit Amount!" << endl << endl;
				break;
			}
			userAccount->deposit(depositAmount); //deposit using the deposit function
			break;


		case 3: //case 3 withdraw from account
			if (!userAccount) { //checks if Account has been created
				cout << "\nError, You must create an Account first!" << endl << endl;
				break;
			}
			cout << "Enter amount to withdraw: ";
			cin >> withdrawAmount;
			if (withdrawAmount > userAccount->getBalance() || cin.fail()) { //checks if amount is valid
				cin.clear();cout << "\nError, you cannot withdraw more than account balance." << endl << endl;
			}
			userAccount->withdraw(withdrawAmount);
			break;

		case 4: //case 3 get current balance
			if (!userAccount) { //checks if Account has been created
				cout << "\nError, You must create an Account first!" << endl << endl;
				break;
			}
			cout << "Current balance: $" << userAccount->getBalance() << endl << endl;
			break;

		case 5: //case 5 Exits the program
			cout << "Thank you for using Simple Bank System!";
			return 1;
		}
	}
	
}

void menu() { //menu function to display menu
	cout << "1. Create Account" << endl;
	cout << "2. Deposit Money" << endl;
	cout << "3. Withdraw Money" << endl;
	cout << "4.Check Balance" << endl;
	cout << "5. Exit" << endl << endl;
	cout << "Enter your choice: ";
}

