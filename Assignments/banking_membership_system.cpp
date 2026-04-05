#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Account;

class Customer 
{
    private:
    string name;
    int customerID;

    public:
    Customer () 
    {
        cout << "Default Customer constructor called\n" << endl;
        cout << "Enter customer name: ";
        cin.ignore ();
        getline (cin, name);
        cout << "Enter customer id: ";
        cin >> customerID;
        cout << endl;
    }

    Customer (string n, int id) : name (n), customerID (id) 
    {
        cout << "Parameterized Customer constructor called\n" << endl;
    }

    friend void displayAccountInfo (const Customer&, const Account&);
};

class Account 
{
    private:
    string accountNumber;
    double balance;

    public:
    Account (string accNo, double bal) : accountNumber (accNo), balance (bal) 
    {
        cout << "Account constructor called\n" << endl;
    }

    double getBalance () const 
    {
        return balance;
    }

    void debit (double amount) 
    {
        if (amount > balance) 
        {
            throw runtime_error ("Insufficient balance.");
        }
        else
        {
            balance -= amount;
        }
    }

    void credit (double amount) 
    {
        balance += amount;
    }

    friend void displayAccountInfo (const Customer&, const Account&);
};

void displayAccountInfo (const Customer& c, const Account& a) 
{
    cout << "\n--- Account Details ---\n";
    cout << "Customer ID: " << c.customerID << endl;
    cout << "Name: " << c.name << endl;
    cout << "Balance: Rs. " << a.balance << endl;
}

class Membership 
{
    protected:
    double income;
    double balance;

    public:
    Membership (double inc, double bal) : income (inc), balance (bal) 
    {
        cout << "Membership constructor called\n" << endl;
    }

    virtual void validate () = 0;
    virtual double getTransactionLimit () = 0;
    virtual double getLoanLimit () = 0;
    virtual string getType () = 0;
};

class DiamondMember : public Membership 
{
    public:
    DiamondMember (double inc, double bal) : Membership (inc, bal) 
    {
        cout << "Diamond Member constructor called\n" << endl;
    }

    void validate () override 
    {
        if (income < 200000 || balance < 50000) 
        {
            throw invalid_argument ("Invalid Diamond Membership: income >= 200000 and balance >= 50000 required.");
        }
        else
        {
            cout << "Valid Diamond Membership!" << endl;
        }
    }

    double getTransactionLimit () override 
    {
        return 250000;
    }

    double getLoanLimit () override 
    {
        return 10000000;
    }

    string getType () override 
    {
        return "Diamond";
    }
};

class GoldMember : public Membership 
{
    public:
    GoldMember (double inc, double bal) : Membership (inc, bal) 
    {
        cout << "Gold Member constructor called\n" << endl;
    }

    void validate () override 
    {
        if (income < 100000 || balance < 10000) 
        {
            throw invalid_argument ("Invalid Gold Membership: income >= 100000 and balance >= 10000 required.");
        }
        else
        {
            cout << "Valid Gold Membership!" << endl;
        }
    }

    double getTransactionLimit () override 
    {
        return 150000;
    }

    double getLoanLimit () override 
    {
        return 5000000;
    }

    string getType () override 
    {
        return "Gold";
    }
};

class SilverMember : public Membership 
{
    public:
    SilverMember (double inc, double bal) : Membership (inc, bal) 
    {
        cout << "Silver Member constructor called\n" << endl;
    }

    void validate () override 
    {
        if (income < 20000 || balance < 10000) 
        {
            throw invalid_argument ("Invalid Silver Membership: income >= 20000 and balance >= 10000 required.");
        }
        else
        {
            cout << "Valid Silver Membership!" << endl;
        }
    }

    double getTransactionLimit () override 
    {
        return 100000;
    }

    double getLoanLimit () override 
    {
        return 1000000;
    }

    string getType () override 
    {
        return "Silver";
    }
};

class Rewards 
{
    public:
    static int calculatePoints (double amount) 
    {
        if (amount > 100000)
        {
            return 1000;
        }
        else if (amount >= 10000)
        {
            return 100;
        }
        else
        {
            return 0;
        }
    }

    static double mobileTopUp (double amount) 
    {
        return (amount > 100000) ? amount * 0.01 : 0.0;
    }
};

class Transaction 
{
    protected:
    double amount;

    public:
    Transaction (double amt) : amount (amt) 
    {
        cout << "Transaction constructor called\n" << endl;
    }

    virtual void process (Account& acc, Membership* mem) = 0;
};

class PoS_Transaction : public Transaction 
{
    public:
    PoS_Transaction (double amt) : Transaction (amt) 
    {
        cout << "Point of Sales Transaction constructor called\n" << endl;
    }

    void process (Account& acc, Membership* mem) override 
    {
        if (amount > mem->getTransactionLimit ()) 
        {
            throw runtime_error ("Transaction exceeds daily limit for " + mem->getType ());
        }

        acc.debit (amount);

        int points = Rewards::calculatePoints (amount);
        double topUp = Rewards::mobileTopUp (amount);

        if (topUp > 0) acc.credit (topUp);

        cout << "PoS transaction of Rs. " << amount << " processed." << endl;
        cout << "Bonus Points: " << points << ", Mobile Top-Up: Rs. " << topUp << endl;
    }
};

class Loan 
{
    private:
    double amount;
    double propertyValue;

    public:
    Loan (double amt, double propVal) : amount (amt), propertyValue (propVal) 
    {
        cout << "Loan constructor called\n" << endl;
    }

    void checkEligibility (Membership* mem) 
    {
        if (amount > mem->getLoanLimit () || propertyValue < amount) 
        {
            throw runtime_error (mem->getType () + " member not eligible for this loan amount.");
        }
        else
        {
            cout << "Loan approved for Rs. " << amount << " against property worth Rs. " << propertyValue << endl;
        }
    }
};

int main () 
{
    try 
    {
        Customer customer;

        string accNo = "ACC123";
        double initialBalance, income;
        int membershipChoice;

        cout << "Enter initial account balance: ";
        cin >> initialBalance;

        cout << "Enter your monthly income: ";
        cin >> income;

        cout << "\nChoose Membership Type:\n";
        cout << "1. Diamond\n2. Gold\n3. Silver\n";
        cout << "Enter choice (1-3): ";
        cin >> membershipChoice;

        Account account (accNo, initialBalance);
        Membership* member = nullptr;

        switch (membershipChoice) 
        {
            case 1:
                member = new DiamondMember (income, account.getBalance ());
                break;
            case 2:
                member = new GoldMember (income, account.getBalance ());
                break;
            case 3:
                member = new SilverMember (income, account.getBalance ());
                break;
            default:
                throw invalid_argument ("Invalid membership choice.");
        }

        // Display info before transaction
        cout << "\nBefore Transaction:" << endl;
        displayAccountInfo (customer, account);
        cout << "\nMembership Type: " << member->getType () << endl;

        // Validate membership
        member->validate ();

        cout << "Transaction Limit: Rs. " << member->getTransactionLimit ();
        cout << "\nLoan Limit: Rs. " << member->getLoanLimit () << endl;

        // Perform PoS transaction
        double transactionAmount;
        cout << "\nEnter PoS transaction amount: ";
        cin >> transactionAmount;

        PoS_Transaction t (transactionAmount);
        t.process (account, member);

        // Apply for loan
        double loanAmount, propertyValue;
        cout << "\nEnter loan amount: ";
        cin >> loanAmount;
        cout << "Enter property value: ";
        cin >> propertyValue;

        Loan loan (loanAmount, propertyValue);
        loan.checkEligibility (member);

        // Final account state
        displayAccountInfo (customer, account);

        delete member;

    } 
    catch (const exception& e) 
    {
        cerr << "\nError: " << e.what () << endl;
    }

    return 0;
}
