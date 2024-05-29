#include <iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<limits>
#include<ctime>
using namespace std;

void intro();
void logpage();
void logging();
void signup();
void signin();
void displayCatalog();
void addTocart();
void removeFromCart();
void displayCart();
void order();
void accountDetail();
void logout();
void aboutus();

string name;
string passwd;

struct Product {
    string type;
    string model;
    struct Specs {
        string CPU;
        string RAM;
        string storage;
        string condition;
    } specs;
    double price;
    int quantity;
};
Product products[] = {{"Laptop","HP EliteBook 840 G3",{"Core i5", "8GB", "1TB HDD", "Slightly used"},26500.0,3},
                          {"Laptop","DELL Latitude D630",{"Core Duo(2)", "4GB", "320GB HDD", "Old"},13000.0,1},
                          {"Smart Phone","SAMSUNG M12",{"", "4GB", "64GB", "Slightly used"},14000.0,5},
                          {"Fast Charger","original smasung",{" "," "," ","new"},600.0,35},
                          {"flash drive","T-max ",{" "," ","128GB","new"},550.0,200},
                          };
int catalogSize = sizeof(products) / sizeof(products[0]);

Product Mycart[100];
double total = 0.0;
int cartItemCount = 0;
bool aftersignin=0;

int main(){
    int lg;
    intro();
    cout<<endl<<endl;
    logpage();
    logging();

    while(!aftersignin){

        cout<<"\nIf You Dont have an account you can create \n";
        logging();
    }

    while (aftersignin) {
        cout << "Main Menu:" << endl;
        cout << "1. To see available items" << endl;
        cout << "2. AddTocart" << endl;
        cout << "3. RemovefromCart" << endl;
        cout << "4. Display Cart" << endl;
        cout << "5. Order "<<endl;
        cout << "6. Account Detail "<<endl;
        cout << "7. Log Out"<<endl;
        cout << "8. About us"<<endl;
        cout << "9. To exit from program "<<endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayCatalog();
                break;
            case 2:
                addTocart();
                break;
            case 3:
                removeFromCart();
                break;
            case 4:
                displayCart();
                break;
            case 5:
                order();
                break;
            case 6:
                accountDetail();
                break;
            case 7:
                logout();
                break;
            case 8:
                aboutus();
                break;
            case 9:
                cout << "Thank you for using the Online Shopping System. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }
return 0;
}

void intro()
{
    cout<<setw(80)<<"=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n";
    cout<<setw(80)<<"||              Welcome to our program                ||\n";
    cout<<setw(80)<<"||        ASTU online shopping managment              ||\n";
    cout<<setw(80)<<"||     Manage your online store with ease.            ||\n";
    cout<<setw(80)<<"||  Track inventory, process orders, and more!        ||\n";
    cout<<setw(80)<<"=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n";
    cout<<setw(65)<<"__________________________________\n";
    cout<<setw(65)<<"  press enter to get started     \n";
    cout<<setw(65)<<"__________________________________\n";
    cin.get();

    system("cls");
}

void logpage(){
    cout <<setw(80) << "\n\n";
    cout <<setw(70) << " =>   LOG PAGE  <= " << endl;
    cout<<setw(70)<<" *=*=*=*=*=*=*=*=*=*=*=\n";
    cout <<setw(70)<<"||    1. SIGNIN     ||" << endl;
    cout <<setw(70)<<"||    2. SIGNUP     ||" << endl;
    cout<<setw(70)<<" *=*=*=*=*=*=*=*=*=*=*=\n";
}

void logging(){
string lg;
do {
        int ig;
        cout << "\n\nPlease enter your choice (1 for Sign In, 2 for Sign Up): \n\n";
        cin >> lg;

        if (lg == "1")
            signin();
        else if (lg == "2")
        {
            signup();
            cout << "\n\nACCOUNT SUCCESSFULLY CREATED NOW YOU CAN SIGN IN.........." << endl;            logpage();
        }
        else
            cout << "You entered the wrong key. Please try again." << endl;
    } while (lg != "1");


}

void signin()
{
    cout << "\nEnter Your name: ";
    cin >> name;
    cout<<"\nPassword : ";
    cin>>passwd;
    ifstream infile("log.txt");
    bool found = false;
    string storedName,storedPasswd;
    while (infile >> storedName >> storedPasswd) {
        if (storedName == name && storedPasswd == passwd) {
            found = true;
            aftersignin = true;
            break;
        }
    }

    infile.close();

    if (found) {
        system("cls");
        cout << "\nLogin Successful!" << endl;
    } else {
        cout << "\nInvalid username or password Detected." << endl;
        cin.get();
        aftersignin=0;
    }
}

void signup()
 {
    struct log {
        char name[50];
        char passwd[50];
        string id;
        int year;
        char department[50];
        string accno;

    };

    log p1;
    ofstream outfile;
    outfile.open("log.txt", ios::app);

    if (!outfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    cout << "\nEnter Your First name: ";
    cin >> p1.name;
    cout << "\nEnter password for the new account: ";
    cin >> p1.passwd;

    cout << "\nEnter Your ID: ";
    cin >> p1.id;

    bool validYear = false;
    while (!validYear) {
        cout << "\nYear: ";
        if (cin >> p1.year) {
            validYear = true;
        } else {
            cout << "Invalid year. Please enter a numeric value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// Ignore any leftover newline characters
        }
    }

    cout << "\nDepartment: ";
    cin >> p1.department;


    cout << "\nTelebirr account: ";
    cin >> p1.accno;

    cout<<endl<<endl;
    cout << "\nAccount successfully created.........." << endl;
    cout << "\n============================================" << endl;
    cout << "Press any key to get started................" << endl;
    cout << "============================================" << endl;

    outfile << p1.name << " " << p1.passwd<<" "<< p1.id << " " << p1.year << " " << p1.department << " " << p1.accno << " "  << endl;
    outfile.close();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("cls");
}

void accountDetail()
{
    ifstream infile("log.txt");
    bool found = false;
    string storedName, storedPasswd, storedID,storedYear , storedDepartment, storedAccNo;
    while (infile >> storedName >> storedPasswd >> storedID >> storedYear >> storedDepartment >> storedAccNo) {
        if (storedName == name && storedPasswd == passwd) {
            found = true;
            break;
        }
    }

    infile.close();

    if (found) {
        cout << endl<<setw(57)<<"Account holder Information" << endl;
        cout << setw(57)<<":::::::::::::::::::::::::::::::::::::::\n";
        cout << setw(37)<<"Name: " << storedName << endl;
        cout << setw(37)<<"Your password : " <<storedPasswd <<endl ;
        cout << setw(37)<<"ID: " << storedID << endl;
        cout << setw(37)<<"Year: " << storedYear << endl;
        cout << setw(37)<<"Department: " << storedDepartment << endl;
        cout << setw(37)<<"Telebirr account: " << storedAccNo << endl;
        cout << setw(57)<<":::::::::::::::::::::::::::::::::::::::\n";
    } else {
        cout << "\nInvalid username or password." << endl;
        cin.get();
    }
}

void displayCatalog()
    {

    for (int i = 0; i < catalogSize; ++i) {
        const auto& product = products[i];
        cout << endl;
        cout <<setw(15)<<(i+1)<<setw(22)<< "Type: " << product.type << endl;
        cout <<setw(37)<< "Model: " << product.model << endl;
        cout <<setw(37)<< "Specs : "<<endl;
        cout <<setw(37)<< "CPU: " << product.specs.CPU << endl;
        cout <<setw(37)<< "RAM: " << product.specs.RAM << endl;
        cout <<setw(37)<< "Storage: " << product.specs.storage << endl;
        cout <<setw(37)<< "Condition: " << product.specs.condition << endl;
        cout <<setw(37)<< "Price: $" << product.price << " ETB" << endl;
        cout <<setw(37)<< "Quantity: " << product.quantity << endl;
        cout <<setw(57)<< "----------------------------------------" << endl;
    }
    }

void addTocart(){
int index;
    cout<<"\nEnter the index of the item what you want : \n";
    cin >> index;
    index--;
    if (index >= 0 && index < catalogSize) {
        if (products[index].quantity > 0){
        Mycart[cartItemCount] = products[index];
        total += products[index].price;
        cartItemCount++;
        products[index].quantity--;

        cout<<"Item added To cart successfully : \n";
        }
        else {
            cout << "Item is out of stock." << endl;
        }
    } else {
        cout << "Invalid index." << endl;
    }

}

void removeFromCart() {
    int index;
    cout<<"\nEnter the index to be removed from the cart : \n";
    cin >> index;
    index--;
    if (index >= 0 && index < cartItemCount) {
        total -= Mycart[index].price;
        for (int i = index; i < cartItemCount - 1; ++i) {
            Mycart[i] = Mycart[i + 1];
    }
        cartItemCount--;
        products[index].quantity++;
        cout << "Item removed from the cart." << endl;
    } else {
        cout << "Invalid index." << endl;
    }

}

void displayCart() {
    cout << "\n\n======= Shopping Cart ====\n\n" << endl;
    for (int i = 0; i < cartItemCount; ++i) {
        cout << "Index: " << i + 1 << endl;
        cout << "Type: " << Mycart[i].type << endl;
        cout << "Model: " << Mycart[i].model << endl;
        cout << "Price: $" << Mycart[i].price << endl;
        cout << "------------------------" << endl;
    }
    cout << "Total: $" << total <<" Birr" << endl;
}

int generatePaymentCode() {
    srand(time(0));
    return rand() % 900000 + 100000; // Generate a 6-digit random number
}

void order() {
cout<<"\n\n============= The total amount in your chart is : \n\n"<<total<<endl;
cout << "Do you want to place the order? (y/n): ";
char choice;
cin >> choice;
if (choice == 'y' || choice == 'Y') {
    int paymentCode = generatePaymentCode();
    cout<<"\n\tyou can pay via Telebirr in the following payment code : \n";
    cout << "\n\tYour payment code is: " << paymentCode << endl;
    cout << "\n\nThank you for using the Online Shopping System. !\n\n" << endl;
    }
else {
    cout << "\n\nOrder canceled.\n\n" << endl;
     }
}

void logout(){
    system("cls");
    cout<<"\n successfully logged out \n";
    logpage();
    logging();
}

void aboutus()
{
    cout<<setw(26)<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout<<setw(36)<< "\n\n\nWe are a group of developers who worked on this  CPP project." << endl;
    cout<<setw(36)<<"Name                "<<"ID             "<<"section   "<<endl;
    cout<<setw(36)<<"Abduselam Tesfaye : "<<"UGR/25696/14 : "<<"section 38"<<endl;
    cout<<setw(36)<<"Suhayl Hashim     : "<<"UGR/32524/14 : "<<"section 38"<<endl;
    cout<<setw(36)<<"Fiker tibebe      : "<<"UGR/30536/15 : "<<"section 37"<<endl;
    cout<<setw(36)<<"Mekdes bedilu     : "<<"UGR 30873/15 : "<<"section 37"<<endl;
    cout<<setw(36)<<"Natati Birhanu    : "<<"UGR/31029/15 : "<<"section 38"<<endl;
    cout<<setw(36)<<"Mekdelawit getaye : "<<"UGR/30871/15 : "<<"section 38"<<endl;
    cout<<setw(36)<<"Tsion wubshet     : "<<"UGR/31333/15 : "<<"section 38"<<endl;
    cout<<setw(26)<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n";

}
