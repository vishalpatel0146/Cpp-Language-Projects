#include<iostream>
using namespace std;

class BankAccount {

    private:
        long long accountNumber;
        string accountHolderName;
        string type;
        double balance;
        
        static long long int nextAccountNumber;

    public:

        static int totalAccount;

        BankAccount() {

        }

        BankAccount(string name, string type, double balance) {

            this->accountNumber = nextAccountNumber;
            this->accountHolderName = name;
            this->type = type;
            this->balance = balance;

            nextAccountNumber++;
            totalAccount++;

        }

        virtual void setBankAccount() {

            nextAccountNumber++;
            this->accountNumber = nextAccountNumber;

            cin.ignore();

            cout << endl << "Enter Account Holder name :- ";
            getline(cin, accountHolderName);

            cout << "Enter Initial Amount :- ";
            cin >> balance;
            
            totalAccount++;

        }

        virtual void deposit() {

            double amount;

            cout << endl << "Enter Amouunt :- ";
            cin >> amount;

            balance += amount;
            cout << endl << "Deposit Successfully" << endl;

        }

        virtual void withdraw() {

            double amount;

            cout << endl << "Enter Amouunt :- ";
            cin >> amount;

            if(amount <= balance) {

                balance -= amount;
                cout << endl << "Withdrawal Successfully" << endl;

            } else {
                cout << endl << "Insufficient Balance" << endl;
            }

        }

        void setBalance(double balance) {
            this->balance = balance;
        }

        void setAccountType(string type) {
            this->type = type;
        }

        double getBalance() {
            return balance;
        }

        long long getAccountNo() {
            return accountNumber;
        }

        string getType() {
            return type;    
        }

        virtual void displayAccountInfo() {

            cout << endl << "Acccount Number :- " << accountNumber << endl;
            cout << "Account Holder Name :- " << accountHolderName << endl;
            cout << "Account Type :- " << type << endl;
            cout << "Account Balance :- " << balance << endl;

        }

        virtual void calculateInterest() {

        }

        virtual void checkOverDraft() {

        }

        virtual ~BankAccount() {
            totalAccount--;
        }
        
};

class SavingAccount: public BankAccount {

    private:
        double intrest;
        static int intrestRate;
        string type;
    public:

        void setBankAccount() override {

            type = "Saving";
            BankAccount::setBankAccount();
            
            setAccountType(type);

        }

        void displayAccountInfo() override {

            BankAccount::displayAccountInfo();

            cout << "Bank Intrest Rate :- " << intrestRate << "%" << endl ;

            cout << "According to Your Intrest Rate " << intrestRate << " % :- " << intrest << endl;;

        }

        void deposit() override {

            double amount;

            cout << endl << "Enter Amount :- ";
            cin >> amount;

            amount = getBalance() + amount;

            BankAccount::setBalance(amount);

            cout << endl << "Deposit Successfully" << endl;

        }

        void withdraw() override {

            double amount;

            cout << endl << "Enter Amount :- ";
            cin >> amount;

            if(amount < getBalance()) {

                amount = getBalance() - amount;

                BankAccount::setBalance(amount);

                cout << endl << "Withdrawal Successfully" << endl;

            } else {
                cout << endl << "Insufficient Balance" << endl;
            }

        }

        void calculateInterest() override {

            intrest = getBalance() * intrestRate / 100;

            intrest = getBalance() + intrest;

            setBalance(intrest);

        }

};

class CheckingAccount: public BankAccount {

    private:
        double overDraftLimit;
        string type;

    public:

        void setBankAccount() override {

            type = "Checking";

            BankAccount::setBankAccount();

            setAccountType(type);

            cout << "Enter Account Over Draft Limit :- ";
            cin >> overDraftLimit;

        }

        void displayAccountInfo() override {

            BankAccount::displayAccountInfo();

            cout << "Account Over Draft Limit :- " << overDraftLimit << endl;

        }

        void deposit() override {

            double amount;

            cout << endl << "Enter Amount :- ";
            cin >> amount;

            amount = getBalance() + amount;

            BankAccount::setBalance(amount);

            cout << endl << "Deposit Successfully" << endl;

        }

        void withdraw() override {

            double amount;

            cout << endl << "Enter amount :- ";
            cin >> amount;

            if(amount <= getBalance() + overDraftLimit) {

                amount = getBalance() - amount;

                BankAccount::setBalance(amount);

                cout << endl << "Withdrawal Successfully" << endl;

            } else {
               cout << endl << "Insufficient Balance" << endl;
            }


        }

        void checkOverDraft() override {

            double amount;

            cout << endl << "Enter Amount :- ";
            cin >> amount;

            if(amount <= getBalance() + overDraftLimit) {

                cout << endl << "Withdrawal exceeds the overdraft limit." << endl;

                int choice;

                do {

                    cout << endl << "Press 1 to Withraw" << endl;
                    cout << "Press 0 to go back" << endl;

                    again:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> choice;

                    if(choice < 0 || choice > 1) {
                        cout << endl << "Invalid  Choice..." << endl;
                        goto again;
                    }

                    switch(choice) {

                        case 1:

                            withdraw();

                            break;

                        case 0:

                            break;

                    }

                } while(choice != 0);

            } else {

                cout << endl << "Withdrawal dose not exceeds the overdraft limit." << endl;

            }

        }

        void calculateInterest() override {
            cout << endl << "Interest is not available for Checking Account." << endl;
        }

};

class FixedDepositAccount: public BankAccount {

    private:
        double intrest;
        int term;
        static int intrestRate;
        string type;

    public:

        void setBankAccount() override {

            type = "Fixed";

            BankAccount::setBankAccount();

            setAccountType(type);

            cout << "Enter F.D Terms :- ";
            cin >> term;

        }

        void displayAccountInfo() override {

            BankAccount::displayAccountInfo();

            cout << "F.D Term :- " << term << " Months" << endl;
            cout << "F.D Interst Rate :- " << intrestRate << " %" << endl;
            cout << "According to Your Intrest Rate " << intrestRate << " % :- " << intrest << endl;

        }

        void deposit() override {
            cout << "Additional deposit is not allowed in Fixed Deposit Account." << endl;
        }

        void withdraw() override {
            cout << "Withdrawal is not allowed before maturity." << endl;
        }

        void calculateInterest() override {

            intrest = (getBalance() * intrestRate * term) / (100 * 12);

            intrest = getBalance() + intrest;

            setBalance(intrest);

        }

};

long long int BankAccount::nextAccountNumber = 100;
int BankAccount::totalAccount = 0;
int SavingAccount::intrestRate = 3;
int FixedDepositAccount::intrestRate = 7;


int main() {

    cout << "<========== - Banking System - ==========>" << endl << endl;

    BankAccount *account[50];
    int index = 0;
    int choice;

    cout << "<---------- Welcome ---------->" << endl;
    
    do {

        cout << "Press 1 to create Bank Account." << endl;
        cout << "Press 2 to display Bank Details." << endl;
        cout << "Press 3 for Deposit in your account." << endl;
        cout << "Press 4 for Withdraw from your account." << endl;
        cout << "Press 5 fot Calculate Intreest." << endl;
        cout << "Press 6 to Exit." << endl;

        tryAgain:
        cout << "Enter Your Choice :- ";
        cin >> choice;

        if(choice < 1 || choice > 6) {
            cout << endl << "Invalid Choice......." << endl << "Please Try Again......" << endl << endl;
            goto tryAgain;
        }

        switch(choice) {

            case 1:

                int option;
                
                do {
                    
                    cout << endl << "<===== Account Type =====>" << endl;
                    
                    cout << "press 1 to create Saving Account." << endl;
                    cout << "Press 2 to create Checking Account." << endl;
                    cout << "Press 3 to create Fixed Deposit (F.D) Account." << endl;
                    cout << "Press 0 to Go Back." << endl;

                    try_Again:
                    cout << "Enter Your Choice :- ";
                    cin >> option;

                    if(option < 0 || option > 3) {
                        cout << endl << "Invalid Choice......." << endl << "Please Try Again......" << endl << endl;
                        goto try_Again;
                    }

                    switch(option) {

                        case 1:
                            account[index] = new SavingAccount();
                            account[index]->setBankAccount();
                            index++;

                            break;

                        case 2:
                            account[index] = new CheckingAccount();
                            account[index]->setBankAccount();
                            index++;

                            break;

                        case 3:
                            account[index] = new FixedDepositAccount();
                            account[index]->setBankAccount();
                            index++;

                            break;

                        case 0:

                            break;

                    }

                } while(option != 0);

                break;

            case 2:

                int option_one;

                do {

                    cout << endl << "<===== Account Type =====>" << endl;
                    
                    cout << "press 1 to display Saving Account." << endl;
                    cout << "Press 2 to display Checking Account." << endl;
                    cout << "Press 3 to display Fixed Deposit (F.D) Account." << endl;
                    cout << "Press 0 to Go Back." << endl;

                    try__Again:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> option_one;

                    if(option_one < 0 || option_one > 3) {
                        cout << endl << "Invalid Choice......." << endl << "Please Try Again......" << endl << endl;
                        goto try__Again;
                    }

                    switch(option_one) {

                        case 1:

                            if(index != 0) {

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getType() == "Saving") {
                                        account[i]->displayAccountInfo();
                                    }

                                }

                            } else {
                                cout << endl << "No Information Found." << endl;
                            }

                            break;

                        case 2:

                            if(index != 0) {

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getType() == "Checking") {
                                        account[i]->displayAccountInfo();
                                    }

                                }

                            } else {
                                cout << endl << "No Information Found." << endl;
                            }

                            break;

                        case 3:

                            if(index != 0) {

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getType() == "Fixed") {
                                        account[i]->displayAccountInfo();
                                    }

                                }

                            } else {
                                cout << endl << "No Information Found." << endl;
                            }

                            break;

                        case 0:

                            break;

                    }

                } while(option_one != 0);

                break;

            case 3:

                int option_two;

                do {

                    cout << endl << "<===== Select Account =====>" << endl;
                    
                    cout << "press 1 for Saving Account." << endl;
                    cout << "Press 2 for Checking Account." << endl;
                    cout << "Press 3 for Fixed Deposit (F.D) Account." << endl;
                    cout << "Press 0 to Go Back." << endl;

                    try__again:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> option_two;

                    if(option_two < 0 || option_two > 3) {
                        cout << endl << "Invalid Choice......." << endl << "Please Try Again......" << endl << endl;
                        goto try__again;
                    }

                    switch(option_two) {

                        case 1:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {

                                        account[i]->deposit();
                                        found++;

                                        break;

                                    }

                                }

                                if(found ==0) {
                                    cout << endl << "No Account Found" << endl;
                                }

                            } else {
                                cout << endl << "No Information Found." << endl;
                            }

                            break;

                        case 2:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {

                                        account[i]->deposit();
                                        found++;

                                        break;

                                    }

                                }

                                if(found == 0) {
                                    cout << endl << "No Account Found" << endl;
                                }

                            } else {
                                cout << endl << "No Information Found." << endl;
                            }

                            break;

                        case 3:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {

                                        account[i]->deposit();
                                        found++;

                                        break;

                                    }

                                }

                                if(found == 0) {
                                    cout << endl << "No Account Found" << endl;
                                }

                            } else {
                                cout << endl << "No Information Found." << endl;
                            }

                            break;

                        case 0:

                            break;

                    }

                } while(option_two != 0);

                break;

            case 4:

                int option_three;

                do {

                    cout << endl << "<===== Select Account =====>" << endl;
                    
                    cout << "press 1 for Saving Account." << endl;
                    cout << "Press 2 for Checking Account." << endl;
                    cout << "Press 3 for Fixed Deposit (F.D) Account." << endl;
                    cout << "Press 0 to Go Back." << endl;

                    try_Again1:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> option_three;

                    if(option_three < 0 || option_three > 3) {
                        cout << endl << "Invalid Choice......" << endl;
                        goto try_Again1;
                    }

                    switch(option_three) {

                        case 1:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {

                                        account[i]->withdraw();
                                        found++;

                                        break;

                                    }

                                }

                                if(found == 0) {
                                    cout << endl << "No Account Found" << endl;                                }

                            } else {
                                cout << endl << "No Information Found." << endl;
                            }

                            break;

                        case 2:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {

                                        account[i]->checkOverDraft();
                                        found++;

                                        break;

                                    }

                                }

                                if(found == 0) {
                                    cout << endl << "No Account Found" << endl;
                                }

                            } else {
                                cout << endl << "No Information Found."<< endl;
                            }

                            break;

                        case 3:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {
                                        
                                        account[i]->withdraw();
                                        found++;

                                        break;

                                    }

                                }

                                if(found == 0) {
                                    cout << endl << "No Account Found" << endl;
                                }
                                
                            } else {
                                cout << endl << "No Information Found."<< endl;
                            }

                            break;

                        case 0:

                            break;

                    }

                } while(option_three != 0);

                break;

            case 5:

                int option_for;

                do {

                    cout << endl << "<===== Select Account =====>" << endl;
                    
                    cout << "press 1 for Saving Account." << endl;
                    cout << "Press 2 for Checking Account." << endl;
                    cout << "Press 3 for Fixed Deposit (F.D) Account." << endl;
                    cout << "Press 0 to Go Back." << endl;

                    trY_Again:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> option_for;

                    if(option_for < 0 || option_for > 3) {
                        cout << endl << "Invalid Choice..." << endl;
                        goto trY_Again;
                    }

                    switch(option_for) {

                        case 1:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {

                                        account[i]->calculateInterest();
                                        found++;

                                        break;

                                    }

                                }

                                if(found == 0) {
                                    cout << endl << "No Account Found" << endl;
                                }

                            } else {
                                cout << endl << "No Information Found."<< endl;
                            }

                            break;
  
                        case 2:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {

                                        account[i]->calculateInterest();
                                        found++;

                                        break;

                                    }

                                }

                                if(found == 0) {
                                    cout << endl << "No Account Found" << endl;
                                }

                            } else {
                                cout << endl << "No Information Found."<< endl;
                            }

                            break;
                        case 3:

                            if(index != 0) {

                                long long accNo;
                                int found = 0;

                                cout << endl << "Enter Account Number :- ";
                                cin >> accNo;

                                for(int i = 0; i < index; i++) {

                                    if(account[i]->getAccountNo() == accNo) {

                                        account[i]->calculateInterest();
                                        found++;

                                        break;

                                    }

                                }

                                if(found == 0) {
                                    cout << endl << "No Account Found" << endl;
                                }

                            } else {
                                cout << endl << "No Information Found."<< endl;
                            }

                            break;

                        case 0:

                            break;

                    }

                } while(option_for != 0);

                break;

            case 6:

                cout << endl << "Total Bank Accounts Created :- " << BankAccount::totalAccount << endl;

                cout << endl << "<===== Thank You Come Again =====>" << endl;

                break;

        }

    } while(choice != 6);
    
    for(int i=0; i<index; i++){
        delete account[i];
    }

    return 0;
}