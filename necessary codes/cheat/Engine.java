import java.util.ArrayList;
import java.util.List;

class Bank {

    private String name;
    private ArrayList<Customer> customers;

    public Bank(String name) {
        this.name = name;
        this.customers = new ArrayList<>();
    }

    public void addCustomer(Customer customer) {
        customers.add(customer);
    }

}

abstract class Customer {
    protected String name;
    protected String email;
    protected String accountNumber;
    protected Bank bankname;
    protected String identification_number;
    protected String phonenumber;
    protected ArrayList<accounts> Account;

    public Customer(String name, String email, String accountNumber, Bank bankname, String identification_number,
            String phonenumber) {
        this.name = name;
        this.email = email;
        this.accountNumber = accountNumber;
        this.bankname = bankname;
        this.identification_number = identification_number;
        this.phonenumber = phonenumber;
        this.Account = new ArrayList<>();
    }

    void reset_name(String name) {
        this.name = name;
    }

    void reset_phonenumber(String phonenumber) {
        this.phonenumber = phonenumber;
    }

    void reset_email(String email) {
        this.email = email;
    }

    public void addAccount(accounts account) {
        Account.add(account);
    }
}

abstract class Employee {

    protected String name, email, phonenumber, ID_number;
    protected Bank bankname;

    public Employee(String name, String email, Bank bankname, String ID_number, String phonenumber) {
        this.ID_number = ID_number;
        this.bankname = bankname;
        this.email = email;
        this.name = name;
        this.phonenumber = phonenumber;

    }

    void reset_name(String name) {
        this.name = name;
    }

    void reset_phonenumber(String phonenumber) {
        this.phonenumber = phonenumber;
    }

    void reset_email(String email) {
        this.email = email;
    }

}

class manager extends Employee {

    public manager(String name, String email, Bank bankname, String ID_number, String phonenumber) {
        super(name, email, bankname, ID_number, phonenumber);
    }

}

class trainee extends Employee {

    public trainee(String name, String email, Bank bankname, String ID_number, String phonenumber) {
        super(name, email, bankname, ID_number, phonenumber);
    }

}

class officer extends Employee {

    public officer(String name, String email, Bank bankname, String ID_number, String phonenumber) {
        super(name, email, bankname, ID_number, phonenumber);
    }

}

class SinglePerson extends Customer {

    public SinglePerson(String name, String email, String accountnumber, Bank bankname, String BIN,
            String phonenumber) {
        super(name, email, accountnumber, bankname, BIN, phonenumber);
    }

}

class Organization extends Customer {

    public Organization(String name, String email, String accountnumber, Bank bankname, String TIN,
            String phonenumber) {
        super(name, email, accountnumber, bankname, TIN, phonenumber);
    }

}

abstract class accounts {

    // TODO : TAX SCHEME CALCULATE KORTE HOBE(completed)


    protected String accountNumber;
    protected int balance;

    public accounts(String accountNumber) {
        this.accountNumber = accountNumber;
        this.balance = 0;
    }

    public int getBalance() {
        return balance;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public void deposit(int amount) {
        balance += amount;
        System.out.println("Deposit of $" + amount + " successful. Current balance: $" + balance);
    }

    public abstract void withdraw(int amount);

    public void show() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Balance: $" + balance);
    }
}

class savings extends accounts {
    public savings(String bankaccount) {
        super(bankaccount);
    }

    public int estimated_balance(int year) {
        return (int) (balance + balance * (2.5 / 100) * year);
    }

    public void tax_scheme(int balance) {
        if (balance > 100000) {
            System.out.println("this year, the tax is $" + (int) (2 / 100) * balance);
        }
    }

    @Override
    public void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("$" + amount + "has been successfully withdrawn from savings account.");
        } else {
            System.out.println("ERROR! INSUFFICIENT BALANCE");
        }
    }
}

class salary extends accounts {
    public salary(String bankaccount) {
        super(bankaccount);
    }

    public int estimated_balance(int year) {
        return (int) (balance + balance * (2.0 / 100) * year);
    }

    public void tax_scheme(int balance) {
        if (balance > 100000) {
            System.out.println("this year the tax is $" + (int) (1 / 100) * balance);
        }
    }

    @Override
    public void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("$" + amount + "has been successfully withdrawn from salary account.");
        } else {
            System.out.println("ERROR! INSUFFICIENT BALANCE");
        }
    }
}

class bkashwallet extends accounts {
    public bkashwallet(String bankaccount) {
        super(bankaccount);
    }

    @Override
    public void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("$" + amount + "has been successfully withdrawn from bikashwallet.");
        } else {
            System.out.println("ERROR! INSUFFICIENT BALANCE");
        }
    }

}

class credict_card extends accounts {
    public credict_card(String bankaccount) {
        super(bankaccount);
    }

    public int credit_card_limit = 100_000;

    @Override
    public void withdraw(int amount) {
        if (credit_card_limit >= amount) {
            credit_card_limit -= amount;
            System.out.println("$" + amount + "has been successfully withdrawn from creditcard.");
        } else {
            System.out.println("ERROR! INSUFFICIENT BALANCE");
        }
    }
}

class MoneyTransfer {

    public void transferMoney(accounts sender, accounts receiver, int amount) {
        if (sender.getBalance() >= amount) {
            sender.withdraw(amount);
            receiver.deposit(amount);
            System.out.println("Transfer of $" + amount + " from " + sender.getAccountNumber() + " to "
                    + receiver.getAccountNumber() + " successful.");
        } else {
            System.out.println("Transfer failed due to insufficient funds of the sender.");
        }
    }
}

    // Class representing different ways of withdrawing money
    class MoneyWithdrawal {
        public void directChequeWithdraw(accounts account, int amount) {
            if (account instanceof savings) {
                account.withdraw(amount);
                System.out.println("Withdrawal of $" + amount + " to savings account successful.");
            } else if (account instanceof salary) {
                account.withdraw(amount);
                System.out.println("Withdrawal of $" + amount + " to salary account successful.");
            }
        }

        public void withdrawToBkash(accounts account, int amount) {

            if (account instanceof bkashwallet) {
                account.withdraw(amount);
                System.out.println("Withdrawal of $" + amount + " to BKash wallet successful.");
            } else {
                System.out.println("Withdrawal to BKash wallet failed. Specified account is not a BKash wallet.");
            }
        }

        public void creditCardWithdraw(accounts account, int amount) {
            if (account instanceof credict_card) {
                account.withdraw(amount);
                System.out.println("Withdrawal of $" + amount + " from creditcard.");
            } else {
                System.out.println("Withdrawal failed,INSUFFICIENT BALANCE.");
            }
        }
    }



public class Engine {
    public static void main(String[] args) {
        // Creating a bank
        Bank bank = new Bank("Example Bank");

        // Creating customers
        SinglePerson customer1 = new SinglePerson("John Doe", "john@example.com", "123456", bank, "BIN123",
                "1234567890");
        Organization customer2 = new Organization("XYZ Inc.", "info@xyz.com", "789012", bank, "TIN456", "9876543210");

        // Creating accounts for customers
        savings savingsAccount1 = new savings("123456.savings");
        salary salaryAccount1 = new salary("123456.salary");
        bkashwallet bkashWallet1 = new bkashwallet("123456.bkash");
        credict_card Credict_card = new credict_card("123456.creditcard");

        savings savingsAccount2 = new savings("1234567.savings");
        salary salaryAccount2 = new salary("1234567.salary");
        bkashwallet bkashWallet2 = new bkashwallet("1234567.bkash");
        credict_card Credict_card2 = new credict_card("1234567.creditcard");

        // Adding accounts to customers
        customer1.addAccount(savingsAccount1);
        customer1.addAccount(salaryAccount1);
        customer1.addAccount(bkashWallet1);
        customer1.addAccount(Credict_card);

        customer2.addAccount(savingsAccount2);
        customer2.addAccount(salaryAccount2);
        customer2.addAccount(bkashWallet2);
        customer2.addAccount(Credict_card2);

        // Depositing initial amounts
        savingsAccount1.deposit(2000);
        salaryAccount1.deposit(3000);
        bkashWallet1.deposit(1000);

        savingsAccount2.deposit(22000);
        salaryAccount2.deposit(33000);
        bkashWallet2.deposit(51000);

        System.out.println();
        System.out.println();

        // Showing initial balances

        System.out.println("Initial balances:");
        System.out.println("Savings Account Balance of customer1: $" +
                savingsAccount1.getBalance());
        System.out.println("Salary Account Balance of customer1: $" +
                salaryAccount1.getBalance());
        System.out.println("BKash Wallet Balance of customer1: $" + bkashWallet1.getBalance());

        System.out.println("Savings Account Balance of customer2: $" +
                savingsAccount2.getBalance());
        System.out.println("Salary Account Balance of customer2: $" +
                salaryAccount2.getBalance());
        System.out.println("BKash Wallet Balance of customer2: $" + bkashWallet2.getBalance());

        System.out.println();
        System.out.println();

        // Performing transactions
        MoneyTransfer moneyTransfer = new MoneyTransfer();
        moneyTransfer.transferMoney(savingsAccount1, salaryAccount1, 500);
        moneyTransfer.transferMoney(salaryAccount1, bkashWallet1, 700);
        moneyTransfer.transferMoney(savingsAccount1, bkashWallet1, 10);

        // Performing inter-transcations between accounts of different persons

        moneyTransfer.transferMoney(savingsAccount1, salaryAccount2, 113);
        moneyTransfer.transferMoney(bkashWallet1, salaryAccount2, 10);

        System.out.println();

        // Showing updated balances after transactions
        System.out.println("Balances after transactions:");
        System.out.println("Savings Account Balance of customer1: $" + savingsAccount1.getBalance());
        System.out.println("Salary Account Balance of customer1: $" + salaryAccount1.getBalance());
        System.out.println("BKash Wallet Balance of customer1: $" + bkashWallet1.getBalance());

        System.out.println("Savings Account Balance of customer2: $" + savingsAccount2.getBalance());
        System.out.println("Salary Account Balance of customer2: $" + salaryAccount2.getBalance());
        System.out.println("BKash Wallet Balance of customer2: $" + bkashWallet2.getBalance());

        System.out.println();
        System.out.println();

        // Withdrawing money using different methods

        MoneyWithdrawal moneyWithdrawal = new MoneyWithdrawal();
        moneyWithdrawal.directChequeWithdraw(savingsAccount1, 300); 
        moneyWithdrawal.withdrawToBkash(bkashWallet1, 200); 
        moneyWithdrawal.creditCardWithdraw(bkashWallet1, 150); 

        System.out.println();
        // Showing final balances after withdrawals
        System.out.println("Final balances after withdrawals:");
        System.out.println("Savings Account Balance of customer1: $" + savingsAccount1.getBalance());
        System.out.println("Salary Account Balance of customer1: $" + salaryAccount1.getBalance());
        System.out.println("BKash Wallet Balance of customer1: $" + bkashWallet1.getBalance());
        System.out.println("Savings Account Balance of customer2: $" + savingsAccount2.getBalance());
        System.out.println("Salary Account Balance of customer2: $" + salaryAccount2.getBalance());
        System.out.println("BKash Wallet Balance of customer2: $" + bkashWallet2.getBalance());

    }
}
