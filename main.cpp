#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class Car {
public:
    string chassisNo;
    string modelName;
    string color;
    int year;
    double price;

    void input() {
        cout << "Enter Chassis No.: ";
        cin >> chassisNo;
        cout << "Enter Model Name: ";
        cin >> modelName;
        cout << "Enter Color: ";
        cin >> color;
        cout << "Enter Manufactured Year: ";
        cin >> year;
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() {
        cout << "-------------------------------------------------------------------------------\n";
        cout << "Chassis No.: " << chassisNo << endl;
        cout << "Model Name: " << modelName << endl;
        cout << "Color: " << color << endl;
        cout << "Manufactured Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "-------------------------------------------------------------------------------\n";
    }

    void saveToFile(ofstream& file) {
        file << chassisNo << "|" << modelName << "|" << color << "|" << year << "|" << price << endl;
    }
};

class Customer {
public:
    string name;
    string phoneNumber;
    string address;

    void input() {
        cout << "Enter Customer Name: ";
        cin >> name;
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;
        cout << "Enter Address: ";
        cin >> address;
    }

    void display() {
        cout << "-------------------------------------------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "-------------------------------------------------------------------------------\n";
    }

    void saveToFile(ofstream& file) {
        file << name << "|" << phoneNumber << "|" << address << endl;
    }
};

void displayAvailableCars() {
    ifstream file("available_cars.txt");
    if (!file) {
        cout << "\nNo available cars at the moment.\n" << endl;
        return;
    }

    cout << "\nAvailable Cars:\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << setw(12) << "Chassis No." << " | "
         << setw(12) << "Model Name" << " | "
         << setw(8) << "Color" << " | "
         << setw(6) << "Year" << " | "
         << setw(10) << "Price" << endl;
    cout << "-------------------------------------------------------------------------------\n";

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string chassisNo, modelName, color, yearStr, priceStr;
        getline(ss, chassisNo, '|');
        getline(ss, modelName, '|');
        getline(ss, color, '|');
        getline(ss, yearStr, '|');
        getline(ss, priceStr, '|');
        cout << setw(12) << chassisNo << " | "
             << setw(12) << modelName << " | "
             << setw(8) << color << " | "
             << setw(6) << yearStr << " | "
             << setw(10) << priceStr << endl;
    }

    cout << "-------------------------------------------------------------------------------\n";

    file.close();
}

void searchCarByChassisNo(const string& chassisNo) {
    ifstream file("available_cars.txt");
    if (!file) {
        cout << "\nNo available cars at the moment.\n" << endl;
        return;
    }

    string line;
    bool carFound = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string currentChassisNo;
        getline(ss, currentChassisNo, '|');
        if (currentChassisNo == chassisNo) {
            cout << "\nCar found:\n";
            cout << "-------------------------------------------------------------------------------\n";
            cout << line << endl;
            cout << "-------------------------------------------------------------------------------\n";
            carFound = true;
            break;
        }
    }

    if (!carFound) {
        cout << "\nNo car found with the provided Chassis No.\n" << endl;
    }

    file.close();
}

void displayBookedCars() {
    ifstream file("booked_cars.txt");
    if (!file) {
        cout << "\nNo booked cars at the moment.\n" << endl;
        return;
    }

    cout << "\nBooked Cars:\n";

    cout << setw(12) << "Chassis No." << " | "
         << setw(12) << "Model Name" << " | "
         << setw(8) << "Color" << " | "
         << setw(6) << "Year" << " | "
         << setw(10) << "Price" << endl;
    cout << "-------------------------------------------------------------------------------\n";

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string chassisNo, modelName, color, yearStr, priceStr;
        getline(ss, chassisNo, '|');
        getline(ss, modelName, '|');
        getline(ss, color, '|');
        getline(ss, yearStr, '|');
        getline(ss, priceStr, '|');
        cout << setw(12) << chassisNo << " | "
             << setw(12) << modelName << " | "
             << setw(8) << color << " | "
             << setw(6) << yearStr << " | "
             << setw(10) << priceStr << endl;
    }

    cout << "-------------------------------------------------------------------------------\n";

    file.close();
}

void searchBookedCarByChassisNo(const string& chassisNo) {
    ifstream file("booked_cars.txt");
    if (!file) {
        cout << "\nNo booked cars at the moment.\n" << endl;
        return;
    }

    string line;
    bool carFound = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string currentChassisNo;
        getline(ss, currentChassisNo, '|');
        if (currentChassisNo == chassisNo) {
            cout << "\nBooked car found:\n";
            cout << "-------------------------------------------------------------------------------\n";
            cout << line << endl;
            cout << "-------------------------------------------------------------------------------\n";
            carFound = true;
            break;
        }
    }

    if (!carFound) {
        cout << "\nNo booked car found with the provided Chassis No.\n" << endl;
    }

    file.close();
}

void displayCustomers() {
    ifstream file("customers.txt");
    if (!file) {
        cout << "\nNo customer details found.\n" << endl;
        return;
    }

    cout << "\nCustomer Details:\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << setw(12) << "Name" << " | "
         << setw(15) << "Phone Number" << " | "
         << setw(30) << "Address" << endl;
    cout << "-------------------------------------------------------------------------------\n";

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, phoneNumber, address;
        getline(ss, name, '|');
        getline(ss, phoneNumber, '|');
        getline(ss, address, '|');
        cout << setw(12) << name << " | "
             << setw(15) << phoneNumber << " | "
             << setw(30) << address << endl;
    }

    cout << "-------------------------------------------------------------------------------\n";

    file.close();
}

void searchCustomerByName(const string& name) {
    ifstream file("customers.txt");
    if (!file) {
        cout << "\nNo customer details found.\n" << endl;
        return;
    }

    string line;
    bool customerFound = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string currentName;
        getline(ss, currentName, '|');
        if (currentName == name) {
            cout << "\nCustomer found:\n";
            cout << "-------------------------------------------------------------------------------\n";
            cout << line << endl;
            cout << "-------------------------------------------------------------------------------\n";
            customerFound = true;
            break;
        }
    }

    if (!customerFound) {
        cout << "\nNo customer found with the provided name.\n" << endl;
    }

    file.close();
}

void addCar() {
    Car car;
    car.input();

    ofstream file("available_cars.txt", ios::app);
    if (!file) {
        cout << "\nError: Failed to open the available cars file.\n" << endl;
        return;
    }

    car.saveToFile(file);
    file.close();

    cout << "\nCar added successfully.\n" << endl;
}

void bookCar() {
    string chassisNo;
    cout << "\nEnter Chassis No. of the car to book: ";
    cin >> chassisNo;

    ifstream inFile("available_cars.txt");
    if (!inFile) {
        cout << "\nError: Failed to open the available cars file.\n" << endl;
        return;
    }

    ofstream outFile("temp.txt", ios::app);
    if (!outFile) {
        cout << "\nError: Failed to open the temp file.\n" << endl;
        inFile.close();
        return;
    }

    Car car;
    bool carFound = false;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, '|');
        if (token == chassisNo) {
            carFound = true;
            car.chassisNo = token;
            getline(ss, car.modelName, '|');
            getline(ss, car.color, '|');
            string yearStr;
            getline(ss, yearStr, '|');
            car.year = stoi(yearStr);
            string priceStr;
            getline(ss, priceStr, '|');
            car.price = stod(priceStr);
        } else {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
    remove("available_cars.txt");
    rename("temp.txt", "available_cars.txt");

    if (!carFound) {
        cout << "\nNo car found with the provided Chassis No.\n" << endl;
        return;
    }

    Customer customer;
    customer.input();

    ofstream bookedCarsFile("booked_cars.txt", ios::app);
    if (!bookedCarsFile) {
        cout << "\nError: Failed to open the booked cars file.\n" << endl;
        return;
    }

    car.saveToFile(bookedCarsFile);
    bookedCarsFile.close();

    ofstream customersFile("customers.txt", ios::app);
    if (!customersFile) {
        cout << "\nError: Failed to open the customers file.\n" << endl;
        return;
    }

    customer.saveToFile(customersFile);
    customersFile.close();

    cout << "\nCar booked successfully.\n" << endl;
}

void cancelBooking() {
    string chassisNo;
    cout << "\nEnter Chassis No. of the car to cancel booking: ";
    cin >> chassisNo;

    ifstream inFile("booked_cars.txt");
    if (!inFile) {
        cout << "\nError: Failed to open the booked cars file.\n" << endl;
        return;
    }

    ofstream outFile("temp.txt", ios::app);
    if (!outFile) {
        cout << "\nError: Failed to open the temp file.\n" << endl;
        inFile.close();
        return;
    }

    Car car;
    bool carFound = false;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, '|');
        if (token == chassisNo) {
            carFound = true;
            car.chassisNo = token;
            getline(ss, car.modelName, '|');
            getline(ss, car.color, '|');
            string yearStr;
            getline(ss, yearStr, '|');
            car.year = stoi(yearStr);
            string priceStr;
            getline(ss, priceStr, '|');
            car.price = stod(priceStr);
        } else {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
    remove("booked_cars.txt");
    rename("temp.txt", "booked_cars.txt");

    if (!carFound) {
        cout << "\nNo car found with the provided Chassis No.\n" << endl;
        return;
    }

    ofstream availableCarsFile("available_cars.txt", ios::app);
    if (!availableCarsFile) {
        cout << "\nError: Failed to open the available cars file.\n" << endl;
        return;
    }

    car.saveToFile(availableCarsFile);
    availableCarsFile.close();

    cout << "\nBooking cancelled successfully. Car moved back to available cars.\n" << endl;
}

void displayMenu() {
    cout << "-------------------------------------------------------------------------------\n";
    cout << "Car Showroom Management System\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "1. Display Available Cars\n";
    cout << "2. Search Car by Chassis No.\n";
    cout << "3. Display Booked Cars\n";
    cout << "4. Search Booked Car by Chassis No.\n";
    cout << "5. Display Customer Details\n";
    cout << "6. Search Customer by Name\n";
    cout << "7. Add Car\n";
    cout << "8. Book Car\n";
    cout << "9. Cancel Booking\n";
    cout << "10. Exit\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice, count = 0;
    string usr, pswd;
    cout << "Enter Username: ";
    cin >> usr;

    if (usr == "admin1" || usr == "admin2") {
        while (count != 3) {
            cout << "Enter Password: ";
            cin >> pswd;

            if (pswd == "car369") {
                do {
                    displayMenu();
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            displayAvailableCars();
                            break;
                        case 2: {
                            string chassisNo;
                            cout << "\nEnter Chassis No. to search: ";
                            cin >> chassisNo;
                            searchCarByChassisNo(chassisNo);
                            break;
                        }
                        case 3:
                            displayBookedCars();
                            break;
                        case 4: {
                            string chassisNo;
                            cout << "\nEnter Chassis No. to search: ";
                            cin >> chassisNo;
                            searchBookedCarByChassisNo(chassisNo);
                            break;
                        }
                        case 5:
                            displayCustomers();
                            break;
                        case 6: {
                            string name;
                            cout << "\nEnter Customer Name to search: ";
                            cin >> name;
                            searchCustomerByName(name);
                            break;
                        }
                        case 7:
                            addCar();
                            break;
                        case 8:
                            bookCar();
                            break;
                        case 9:
                            cancelBooking();
                            break;
                        case 10:
                            cout << "\nExiting... Thank you!\n" << endl;
                            exit(0);
                        default:
                            cout << "\nInvalid choice. Please try again.\n" << endl;
                    }
                } while (choice != 10);
            } else {
                cout << "\nIncorrect password\n";
                count++;
            }
        }
    } else {
        cout << "\nUsername Does not exist\n";
    }

    return 0;
}
