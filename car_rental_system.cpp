#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>                                            //sleep functions(window)
#include <direct.h>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

ifstream fin;

void book(ifstream &fin, vector<string> &vect)
{
    string line;
    getline(fin, line);
    stringstream ss(line);
    string str;
    while (getline(ss, str, ','))
    {
        vect.push_back(str);
        str = "";
    }
    return;
}

class Car
{
public:
    int distance;
    int cost;
    int Acc_no;
    string name;
    string Phone_no;
    Car();
    virtual void feature() = 0; // pure virtual function
    void customer_details();
    virtual void fair_charge() = 0;
};
Car::Car(void)
{
    distance = 0;
    cost = 0;
    Acc_no = 0;
    name = "NULL";
    Phone_no = "NULL";
}
class LuxiriousCar : public Car
{
public:
    int price;
    LuxiriousCar() { price = 0; }
    void feature()
    {
        int choice;
        cout << "\x1b[1;32m"
             << "\n\t\t\t-------Options in luxirious car:-----------\n\t\t\t\t1.Audi\n\t\t\t\t2.BMW\n\t\t\t\t3.Jaguar\n\t\t\t\t4.Land Rover\n\t\t\t\t5.Mercedes-Benz\n\t\t\t\t6.exit\n";
        do{
        cout << "\t\t\t\tEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\t\t\t--------Some feature of AUDI car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 250KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 5 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 50 rupees per KM\n";
            price = 50;
            break;
        case 2:
            cout << "\n\t\t\t--------Some feature of BMW car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 306KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 4 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 60 rupees per KM\n";
            price = 60;
            break;
        case 3:
            cout << "\n\t\t\t--------Some feature of Jaguar car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 283KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 5 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 55 rupees per KM\n";
            price = 55;
            break;
        case 4:
            cout << "\n\t\t\t--------Some feature of Land Rover car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 250KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 5 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 45 rupees per KM\n";
            price = 45;
            break;
        case 5:
            cout << "\n\t\t\t--------Some feature of MERCEDES-BENZ car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 250KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 4 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 50 rupees per KM\n";
            price = 50;
            break;
        case 6:
            exit(0);
            break;
        default:cout<<"\n\t\t\t\tInvalid choice\n\n";
        }
    }
    while(choice>6);
    }
    void bill_receipt()
    {

        vector<string> vect;
        book(fin, vect);
       
        cout << "\n\t\t                       Car Rental - Customer bill receipt                  " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Customer Name:"
             << "-----------------|" << setw(18) << name << " |" << endl;
        // cout << "\t\t	| Car name :"<<"--------------------|"<<setw(10)<<carmodel<<" |"<<endl;
        cout << "\t\t	| Distance travelled :"
             << "-----------|" << setw(18) << distance << " |" << endl;
        cout << "\t\t	| Your Rental Amount is :"
             << "--------|" << setw(18) << cost << " |" << endl;
        cout << "\t\t	| Caution Money :"
             << "----------------|" << setw(18) << "0"
             << " |" << endl;
        cout << "\t\t	| Advanced :"
             << "---------------------|" << setw(18) << "0"
             << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t        | Total Rental Amount is :"
             << "-------|" << setw(18) << cost << " |" << endl;
        cout<<"\t\t        | Driver name is :"<<"---------------|"<<setw(18)<<vect.at(0)<<" |"<<endl;
        cout<<"\t\t        | Driver's phone no. is :"<<"--------|"<<setw(18)<<vect.at(1)<<" |"<<endl;
        cout<<"\t\t        | Car number is :"<<"----------------|"<<setw(18)<<vect.at(2)<<" |"<<endl;
      //  cout << vect.at(0) << "  " << vect.at(1) << "  " << vect.at(2) << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        cout << "\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        int f;
        system("PAUSE");  

        system("CLS");
    }

    void fair_charge()
    {
        ofstream File;
        File.open("Car_rent.txt", ios::app);
        cout << "\x1b[1;32m"
             << "\n\t\t\t\tEnter the distance you want to travel:"
             << "\x1b[1;33m";
        cin >> distance;
        File << "\nDistance:" << distance;
        cost = distance * price;
        File << "\nPaid Money:" << cost << endl;
        // cout<<"\x1b[1;32m"<<"\t\t\t\tYour Fair Charge="<<cost<<endl;
        bill_receipt();
        cout << "\x1b[1;32m"
             << "\n\t\t\t\tEnter your Account number for payment:"
             << "\x1b[1;33m";
        cin >> Acc_no;
        cout << "\t\t\t\tThank you for visiting\n";
        cout << "\t\t\t\tYour payment have succesfully done\n";
        File.close();
        ifstream inf("thanks.txt");
        char str[300];
        while (inf)
        {
            inf.getline(str, 300);
            if (inf)
                cout << str << endl;
        }
        inf.close();
    }
};

class EconomicalCar : public Car
{
public:
    int price;
    EconomicalCar() { price = 0; }
    void feature()
    {
        int choice;
        cout << "\x1b[1;32m"
             << "\n\t\t\t-------Options available in Economical Car Area:-----------------\n";
        cout << "\t\t\t\t1.Toyota Fortuner\n\t\t\t\t2.Mahindra Scorpio\n\t\t\t\t3.Tata Punch\n";
        do{
        cout << "\t\t\t\tEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\t\t\t--------Some feature of Toyota Fortuner car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 190KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 7 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 40 rupees per KM\n";
            price = 40;
            break;
        case 2:
            cout << "\n\t\t\t--------Some feature of Mahindra Scorpio car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 156KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 7 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 37 rupees per KM\n";
            price = 37;
            break;
        case 3:
            cout << "\n\t\t\t--------Some feature of Tata Punch car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 160KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 5 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 35 rupees per KM\n";
            price = 35;
            break;
        default:cout<<"\n\t\t\t\tInvalid choice\n\n";
        }
    }
    while(choice>3);
    }

    void bill_receipt()
    {
        vector<string> vect;
        book(fin, vect);

        cout << "\n\t\t                       Car Rental - Customer bill receipt                  " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Customer Name:"
             << "-----------------|" << setw(18) << name << " |" << endl;
        // cout << "\t\t	| Car name :"<<"--------------------|"<<setw(10)<<carmodel<<" |"<<endl;
        cout << "\t\t	| Distance travelled :"
             << "-----------|" << setw(18) << distance << " |" << endl;
        cout << "\t\t	| Your Rental Amount is :"
             << "--------|" << setw(18) << cost << " |" << endl;
        cout << "\t\t	| Caution Money :"
             << "----------------|" << setw(18) << "0"
             << " |" << endl;
        cout << "\t\t	| Advanced :"
             << "---------------------|" << setw(18) << "0"
             << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
       cout << "\t\t        | Total Rental Amount is :"
             << "-------|" << setw(18) << cost << " |" << endl;
        cout<<"\t\t        | Driver name is :"<<"---------------|"<<setw(18)<<vect.at(0)<<" |"<<endl;
        cout<<"\t\t        | Driver's phone no. is :"<<"--------|"<<setw(18)<<vect.at(1)<<" |"<<endl;
        cout<<"\t\t        | Car number is :"<<"----------------|"<<setw(18)<<vect.at(2)<<" |"<<endl;

        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        cout << "\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        int f;
        system("PAUSE");

        system("CLS");
    }

    void fair_charge()
    {
        ofstream File;
        File.open("Car_rent.txt", ios::app);
        cout << "\033[0m"
             << "\x1b[1;32m"
             << "\n\t\t\t\tEnter the distance you want to travel:"
             << "\x1b[1;33m";
        cin >> distance;
        File << "\nDistance:" << distance;
        cost = distance * price;
        File << "\nPaid Money:" << cost << endl;
        // cout<<"\033[0m"<<"\t\t\t\tYour Fair Charge="<<cost<<endl;
        bill_receipt();
        cout << "\033[0m"
             << "\n\t\t\t\tEnter your Account number for payment:"
             << "\x1b[1;33m";
        cin >> Acc_no;
        cout << "\t\t\t\tThank you for visiting\n";
        cout << "\t\t\t\tYour payment have succesfully done\n";
        File.close();
        ifstream inf("thanks.txt");
        char str[300];
        while (inf)
        {
            inf.getline(str, 300);
            if (inf)
                cout << str << endl;
        }
        inf.close();
    }
};

class CheapCar : public Car
{
public:
    int price;
    CheapCar() { price = 0; }
    void feature()
    {
        int choice;
        cout << "\x1b[1;31m"
             << "\n\t\t\t-------Options available in cheap Car Area:------------\n";
        cout << "\t\t\t\t1.Maruti Suzuki S\n\t\t\t\t2.Maruti Alto\n\t\t\t\t3.Dastun Go\n";
        do{
        cout << "\t\t\t\tEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\t\t\t--------Some feature of Maruti Suzuki S car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 100KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 5 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 25 rupees per KM\n";
            price = 25;
            break;
        case 2:
            cout << "\n\t\t\t--------Some feature of Maruti Alto car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 140KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 4 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 27 rupees per KM\n";
            price = 27;
            break;
        case 3:
            cout << "\n\t\t\t--------Some feature of Dastun Go car is:--------\n";
            cout << "\t\t\t\t1.Top speed of this car is 165KM/hr\n";
            cout << "\t\t\t\t2.Capacity of this car is 7 person\n";
            cout << "\t\t\t\t3.Fair cost of this cat will be 30 rupees per KM\n";
            price = 30;
            break;
        default:cout<<"\n\t\t\t\tInvalid choice\n\n";
        }
        }
        while(choice>3);
    }
    void bill_receipt()
    {
        vector<string> vect;
        book(fin, vect);

        cout << "\n\t\t                       Car Rental - Customer bill receipt                  " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Customer Name:"
             << "-----------------|" << setw(18) << name << " |" << endl;
        // cout << "\t\t	| Car name :"<<"--------------------|"<<setw(10)<<carmodel<<" |"<<endl;
        cout << "\t\t	| Distance travelled :"
             << "-----------|" << setw(18) << distance << " |" << endl;
        cout << "\t\t	| Your Rental Amount is :"
             << "--------|" << setw(18) << cost << " |" << endl;
        cout << "\t\t	| Caution Money :"
             << "----------------|" << setw(18) << "0"
             << " |" << endl;
        cout << "\t\t	| Advanced :"
             << "---------------------|" << setw(18) << "0"
             << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t        | Total Rental Amount is :"
             << "-------|" << setw(18) << cost << " |" << endl;
        cout<<"\t\t        | Driver name is :"<<"---------------|"<<setw(18)<<vect.at(0)<<" |"<<endl;
        cout<<"\t\t        | Driver's phone no. is :"<<"--------|"<<setw(18)<<vect.at(1)<<" |"<<endl;
        cout<<"\t\t        | Car number is :"<<"----------------|"<<setw(18)<<vect.at(2)<<" |"<<endl;

        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        cout << "\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        int f;
        system("PAUSE");

        system("CLS");
    }

    void fair_charge()
    {
        ofstream File;
        File.open("Car_rent.txt", ios::app);
        cout << "\x1b[1;32m"
             << "\n\t\t\t\tEnter the distance you want to travel:"
             << "\x1b[1;33m";
        cin >> distance;
        File << "\nDistance:" << distance;
        cost = distance * price;
        File << "\nPaid Money:" << cost << endl;
        // cout<<"\033[0m"<<"\t\t\t\tYour Fair Charge="<<cost<<endl;
        bill_receipt();
        cout << "\n\t\t\t\tEnter your Account number for payment:"
             << "\x1b[1;33m";
        cin >> Acc_no;
        cout << "\033[0m"
             << "\t\t\t\tThank you for visiting\n";
        cout << "\t\t\t\tYour payment have succesfully done\n";
        File.close();
        ifstream inf("thanks.txt");
        char str[300];
        while (inf)
        {
            inf.getline(str, 300);
            if (inf)
                cout << str << endl;
        }
        inf.close();
    }
};

void Car::customer_details()
{
    ofstream file;
    file.open("Car_rent.txt", ios::app);
    cout << "\x1b[1;31m"
         << "\t\t\t*******Please provide your personal details:*********" << endl;
    cout << "\t\t\t\tEnter your name:"
         << "\x1b[1;33m";
    getline(cin >> ws, name);
    // cin>>name;
    file << "Name:" << name;
    cout << "\x1b[1;31m"
         << "\t\t\t\tEnter your Phone number:"
         << "\x1b[1;33m";
    cin >> Phone_no;
    file << "\nPhone number:" << Phone_no;
    file.close();
    // cout<<"\033[0m";
}
class welcome
{
public:
    int welcum()
    {
        ifstream in("welcome.txt");
         cout<< "\x1b[1;33m";
        if (!in)
        {
            cout << "Cannot open input file.\n";
        }
        char str[1000];
        while (in)
        {
            in.getline(str, 1000); // delim defaults to '\n' cp
            if (in)
                cout << str << endl;
        }
        in.close();
        sleep(1);
        cout<<"\x1b[1;32m";
        cout << "\nStarting the program please wait....." << endl;
        sleep(1);
        cout << "\nloading up files....." << endl;
        sleep(2);      // function which waits for (n) seconds
        system("CLS"); // cleares screen
    }
};
int login()
{
    string pass = "";
    char ch;
    cout << "\x1b[1;31m"
         << "\n\n\n\n\n\n\n\t\t\t\t\t  Simple Car Rental System Login";
    cout << "\033[0m";
    cout << "\x1b[1;32m" ;
    //<< setw(86) << "************************************************************************";
    cout << endl
         << setw(35) << "\x1b[1;32m"
         << "*" << setw(57) << "*";
    cout << endl
         << setw(35) << "\x1b[1;32m"
         << "*" << setw(0) << "\x1b[1;31m"
         << "     ---" << setw(4)
         << "-"
         << "    ---"
         << " "
         << "    ---"
         << " "
         << "  ---"
         << "."
         << "   ."
         << " ---." << setw(3) << "-"
         << "   :"
         << "\x1b[1;32m"
         << "      *";
    cout << endl
         << setw(35) << "\x1b[1;32m"
         << "*" << setw(0) << "\x1b[1;31m"
         << "    |   "
         << "  /"
         << " \\"
         << "  |"
         << "___|"
         << " "
         << "  |"
         << "___|"
         << " "
         << "|__"
         << " |"
         << "\\"
         << "  |"
         << "  |"
         << "   /"
         << " \\"
         << "  |"
         << "\x1b[1;32m"
         << "      *";
    cout << endl
         << setw(35) << "\x1b[1;32m"
         << "*" << setw(0) << "\x1b[1;31m"
         << "    |   "
         << " /"
         << "---\\"
         << " |"
         << "   \\"
         << "  "
         << " |"
         << "   \\"
         << " "
         << "|"
         << "   |"
         << " \\"
         << " |"
         << "  |"
         << "  /"
         << "---\\"
         << " |"
         << "\x1b[1;32m"
         << "      *";
    cout << endl
         << setw(35) << "\x1b[1;32m"
         << "*" << setw(0) << "\x1b[1;31m"
         << "     ---"
         << "/"
         << "     \\"
         << "|"
         << "    \\"
         << "  "
         << "|"
         << "    \\"
         << " "
         << "---"
         << "|"
         << "  \\"
         << ":"
         << "  |"
         << " /"
         << "     \\"
         << "|"
         << "___"
         << "\x1b[1;32m"
         << "   *";
    cout << endl
         << setw(35) << "\x1b[1;32m"
         << "*" << setw(57) << "*"
         << "\033[0m";
    cout << endl
         << "\x1b[1;32m" << setw(86) << "*********************************************************"
         << "\033[0m";

    cout << "\n\n\t\t\t\t\t\tEnter Password:Vidyanand "; 
    cout << "\n\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << "\x1b[1;32m" << '*';
        ch = _getch();
    }
    if (pass == "Vidyanand")
    {
        cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
        system("PAUSE");
        system("CLS");
    }
    else
    {
        cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}

int main()
{

    fin.open("1driver.csv", ios::in);
    if (!fin.is_open())
        cout << "error";
    welcome obj1;
    obj1.welcum();
    
    Car *c;
    int choice;
    int login();
    login();
start:
     sleep(0.999999);      // function which waits for (n) seconds
     system("CLS"); // cleares screen
    string decide = "yes";
    cout << "\x1b[1;33m"
         << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
    cout << "\t\t\tWelcome to Our Company ,Choose from the menu : " << endl;
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t----------CAR OPTIONS ARE---------------------\n\t\t\t\t1.Luxirious car\n\t\t\t\t2.Economical car\n\t\t\t\t3.Cheap car\n\t\t\t\t4.exit\n";
    do{
    cout << "\t\t\t\tEnter your choice(for exit press 4):"
         << "\033[0m";
    cin >> choice;
    switch (choice)
    {
    case 1:
        c = new LuxiriousCar();
        c->feature();
        c->customer_details();
        c->fair_charge();
        // exit(0);
        break;
    case 2:
        c = new EconomicalCar();
        c->feature();
        c->customer_details();
        c->fair_charge();
        // exit(0);
        break;
    case 3:
        c = new CheapCar();
        c->feature();
        c->customer_details();
        c->fair_charge();
        // exit(0);
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "\n\t\t\t\tInvalid choice\n\n";
    }
    }
    while(choice>4);
    goto start;
    fin.close();
    return 0;
}