//name :iqbal hussain
//rollNo :44
//assignments : OOP
//
//overview :
//This file contain five assignments of  oops including mini project .



////First Assignment:
//#include<iostream>
//#include<string>
//using namespace std;
//
//
//class bankAccount {
//	private:
//		int accountNo;
//		string Name;
//		double belance;
//		
//    public:
////    	method to set account  info
// void setInfo(int accNo,string name,double bel){
// 	accountNo=accNo;
// 	Name=name;
// 	belance=bel;
// }
// void deposit(double amount){
// 	belance +=amount;
// 	cout<<"you are depsoit"<<amount<<endl;
// 	
// }
// 
////  function to withdraw
//void withdraw(double amount){
//	if (amount <= belance){
//		belance -=amount;
//		cout<<"you are withdraw Rs "<<amount<<endl;
//	}
//		else {
//			cout<<"insufficient belance to withdraw"<<endl;
//		} 
//	}
//
////function for customer info
//void display(){
//	cout<<"\n account info"<<endl;
//	cout<<"your account number is "<<accountNo<<endl;
//	cout<<"your name is "<<Name<<endl;
//	cout<<"your belance is "<<belance<<endl;
//	
//}
//
//};
//
//int main (){
//	bankAccount account;
////	setting intial ammount
//account.setInfo(1214579,"iqbalhussain",10000);
////get user info
//account.deposit(20000);
//account.display();
//account.withdraw(15000);
//account.display();
//return 0;
//}


//assignment 2

//#include<iostream>
//using namespace std;
//class calculator {
//	public :
////		multiply two intigers 
//		int mul(int a,int b){
//			return a*b;
//		}
////		multiply decimals
//		int mul(double a,double b){
//			return a*b;
//		}
//		
////		multiply three intiger
//int mul(int a ,int b,int c){
//	return a*b*c;
//}
//};
//
//int main(){
//	
//	calculator c;
//	cout<<c.mul(3,4)<<endl;
//	 cout<<c.mul(2.5,5.8)<<endl;
//	 cout<<c.mul(2,3,4)<<endl;
//	return 0;
//}



//assignment 3


#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
protected:
    string name;
    int age;

public:
    // Function to set person's information
    void setPerson(string n, int a)
    {
        name = n;
        age = a;
    }

    // Function to display person's information
    void displayPerson()
    {
        cout << "\n--- Person Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class from Person
class Employee : public Person
{
protected:
    int employeeID;
    double salary;

public:
    // Function to set employee information
    void setEmployee(int id, double sal)
    {
        employeeID = id;
        salary = sal;
    }

    // Function to display employee information
    void displayEmployee()
    {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Derived class from Employee
class Manager : public Employee
{
private:
    string department;
    int teamSize;

public:
    // Function to set manager information
    void setManager(string dept, int size)
    {
        department = dept;
        teamSize = size;
    }

    // Function to display manager information
    void displayManager()
    {
        cout << "\n--- Manager Details ---" << endl;
        cout << "Department: " << department << endl;
        cout << "Team Size: " << teamSize << endl;
    }
};

int main()
{
    // Creating a Manager object
    Manager m;

    // Setting values
    m.setPerson("Iqbal Hussain", 21);
    m.setEmployee(101, 75000);
    m.setManager("IT Department", 15);

    // Calling all display functions
    m.displayPerson();
    m.displayEmployee();
    m.displayManager();

    return 0;
}


// asigment 4:
// this assigment is submitetd in hard form 




// assigment 5
//assigmnet: LibraryMangementsystem , BankAccount

#include <iostream>

#include <string>
using namespace std;

class Book
{
//	this is the private atributes of Book class
private:
    string title;
    string author;
    string isbn;

public:
//	used constructor for Book atributes
    Book(string t, string a, string i)
    {
        title = t;
        author = a;
        isbn = i;
    }
//following are methods of Book class
    string bookTitle()
    {
        return title;
    }

    string bookAuthor()
    {
        return author;
    }

    string bookIsbn()
    {
        return isbn;
    }
//method / fucntion for displayBook
    void bookDisplay()
    {
        cout << "\nBook Info" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

class Member
{
protected:
    int memberId;
    string name;
    int booksBorrowed;

public:
    Member(int id, string n)
    {
        memberId = id;
        name = n;
        booksBorrowed = 0;
    }

    virtual int maxBookLimit()
    {
        return 4;
    }

    virtual void borrowBook()
    {
        if (booksBorrowed >= maxBookLimit())
        {
            throw "You exceeded the borrowing limit.";
        }

        booksBorrowed++;
        cout << name << " borrowed a book." << endl;
    }

    void displayMember()
    {
        cout << "\nMember Info" << endl;
        cout << "Member ID: " << memberId << endl;
        cout << "Member Name: " << name << endl;
        cout << "Books Borrowed: " << booksBorrowed << endl;
    }
};

class PremiumMember : public Member
{
private:
    int maxBooksAllowed;

public:
    PremiumMember(int id, string n, int maxBooks)
        : Member(id, n)
    {
        maxBooksAllowed = maxBooks;
    }

    int maxBookLimit() override
    {
        return maxBooksAllowed;
    }

    void borrowBook() override
    {
        if (booksBorrowed >= maxBookLimit())
        {
            throw "Premium member borrowing limit exceeded.";
        }

        booksBorrowed++;
        cout << name << " borrowed a book as a premium member." << endl;
    }
};

int main()
{
//	here is bojects for class Book
    Book b1("Data Science from Scratch", "Iqbal Hussain", "109");
    Book b2("Human Physiology", "Sembulingam", "106");
    Book b3("DSA", "Iqbal Hussain", "108");

    b1.bookDisplay();
    b2.bookDisplay();
    b3.bookDisplay();

    Member m1(190, "Iqbal");
    PremiumMember pm1(890, "Hafiz Alam", 4);

    try
    {
        cout << "\nNormal Member\n";

        m1.borrowBook();
        m1.borrowBook();
        m1.borrowBook();
        m1.borrowBook();

        // 5th book causes exception
        m1.borrowBook();
    }
    catch (const char *msg)
    {
        cout << "Exception: " << msg << endl;
    }

    try
    {
        cout << "\nPremium Member\n";

        pm1.borrowBook();
        pm1.borrowBook();
        pm1.borrowBook();
        pm1.borrowBook();

        // 5th book causes exception
        pm1.borrowBook();
    }
    catch (const char *msg)
    {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}







// project 2 : bankAccount
#include<iostream>
using namespace std;

class BankAccount {
public:
    int balance;
    int deposit_amount;
    int withdraw_amount;

    void deposit() {
        if (deposit_amount <= 0) {
            throw "Invalid deposit amount";
        }
//update the belance when belance deposit
        balance += deposit_amount;
        cout << "Deposit successful\n";
    }

    void withdraw() {
        if (withdraw_amount > balance) {
            throw "Insufficient balance";
        }
//update the belance when belance withdraw
        balance -= withdraw_amount;
        cout << "Withdrawal successful\n";
    }
};

int main() {
    BankAccount b1;

    b1.balance = 500;
    b1.deposit_amount = 100;
    b1.withdraw_amount = 1000;

    try {
        b1.deposit();
        b1.withdraw();
    }
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}



