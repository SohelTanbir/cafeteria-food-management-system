#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct FoodSchema {
    string foodname;
    string foodcat;
    int foodprice;
};

// create new food
void createfood() {
    FoodSchema newFood;
    ofstream file("food_list.txt", ios::app);
    cout << "\n\t\t\t What Is Your New Food Name : ";
    cin >> newFood.foodname;
    cout << "\n\t\t\t What Is Your Food CATEGORY : ";
    cin >> newFood.foodcat;
    cout << "\n\t\t\t What Is Your New Food Price : ";
    cin >> newFood.foodprice;
    file << newFood.foodname << "\t\t\t" << newFood.foodcat << "\t\t\t" << newFood.foodprice << "\n";
    file.close();
}

// show all food list
void showallfood() {
    FoodSchema newFood;
    ifstream fp("food_list.txt");
     cout << "\n ";
    cout << "\t\t\t Showing Foods List:";
    cout << "\n\t\t\t--------------------------------------------------------\n";
    cout << "\t\t\tFOOD NAME         FOOD CATEGORY     FOOD PRICE\n";
    cout << "\t\t\t--------------------------------------------------------\n";
    while (fp >> newFood.foodname >> newFood.foodcat >> newFood.foodprice) {
        cout << "\t\t\t " << newFood.foodname << "\t\t\t" << newFood.foodcat << "\t\t" << newFood.foodprice << "\n";
    }
    fp.close();
}

// search food by exact price
void searchFoodPrice() {
    int founds = 0;
    FoodSchema newFood;
    ifstream file("food_list.txt");
    int prices;
    cout << "\n\t\t\t Enter Food price to Search : ";
    cin >> prices;
    cout << "\n\t\t\t --------------------------------------------------------\n";
    cout << "\t\t\t FOOD NAME         FOOD CATEGORY     FOOD PRICE\n";
    cout << "\t\t\t --------------------------------------------------------\n";
    while (file >> newFood.foodname >> newFood.foodcat >> newFood.foodprice) {
        if (newFood.foodprice == prices) {
            founds = 1;
            cout << "\t\t\t" << newFood.foodname << "\t\t\t" << newFood.foodcat << "\t\t" << newFood.foodprice << "\n";
        }
    }
    if (founds == 0)
        cout <<"\t\t\t " << " No Food Found with your price....:" << prices << "\n";
    file.close();
}

//search food by under given price
void searchFoodUnderPrice() {
    int founds = 0;
    FoodSchema newFood;
    ifstream fp("food_list.txt");
    int prices;

    cout << "\n\t\t\t Enter Food price to Search : ";
    cin >> prices;

    cout << "\n\t\t\t --------------------------------------------------------\n";
    cout << "\t\t\t FOOD NAME         FOOD CATEGORY     FOOD PRICE\n";
    cout << "\t\t\t --------------------------------------------------------\n";

    while (fp >> newFood.foodname >> newFood.foodcat >> newFood.foodprice) {
        if (newFood.foodprice < prices) {
            founds = 1;
            cout <<"\t\t\t " << newFood.foodname << "\t\t\t" << newFood.foodcat << "\t\t" << newFood.foodprice << "\n";
        }
    }

    if (founds == 0)
        cout << "\t\t\t " << "\n No Food Found with your price....:" << prices << "\n";

    fp.close();
}


// search food by name
void searchFoodByName() {
    string name;
    FoodSchema newFood;
    ifstream file;
    int found = 0;

    cout << "\n\t\t\t Enter Food Name to Search : ";
    cin >> name;

    file.open("food_list.txt");
    if (!file.is_open()) {
        cerr << "Error opening file." << "\n";
        return;
    }

    cout << "\n\t\t\t --------------------------------------------------------\n";
    cout << "\t\t\t FOOD NAME         FOOD CATEGORY     FOOD PRICE\n";
    cout << "\n\t\t\t --------------------------------------------------------\n";

    while (file >> newFood.foodname >> newFood.foodcat >> newFood.foodprice) {
        if (name == newFood.foodname || newFood.foodname.find(name) != string::npos) {
            found = 1;
            cout << "\t\t\t " << newFood.foodname << "\t\t\t" << newFood.foodcat << "\t\t" << newFood.foodprice << "\n";
        }
    }

    if (!found)
        cout << "\t\t\t" << "\n No Food Found with name...: " << name << "\n";
    file.close();
}


// search by food category
void searchFoodCategory() {
    string category;
    FoodSchema newFood;
    ifstream file;
    int foundcat = 0;

    cout << "\n\t\t\t Enter Food Category Name to Search : ";
    cin >> category;

    file.open("food_list.txt");
    if (!file.is_open()) {
        cerr << "Error opening file." << "\n";
        return;
    }

    cout << "\n\t\t\t --------------------------------------------------------\n";
     cout << "\t\t\t FOOD NAME         FOOD CATEGORY     FOOD PRICE\n";
    cout << "\n\t\t\t --------------------------------------------------------\n";

    while (file >> newFood.foodname >> newFood.foodcat >> newFood.foodprice) {
        if (category == newFood.foodcat || newFood.foodcat.find(category) != string::npos) {
            foundcat = 1;
             cout <<"\t\t\t" << newFood.foodname << "\t\t\t" << newFood.foodcat << "\t\t" << newFood.foodprice << "\n";
        }
    }

    if (!foundcat)
        cout << "\t\t\t" << "\n No Food Category Found with Name...: " << category << "\n";

    file.close();
}



// search food controller
void searchFoodController() {
    cout << "\n\n\t\t\t --------------------------------------------------------\n";
    cout << "\t\t\t ----------------- SEARCH MODE ON -----------------------\n";
    cout << "\t\t\t --------------------------------------------------------\n";

    int selectedOption;

    cout << "\n\t\t\t 1. SEARCH BY SPECIFIC FOOD PRICE:\n";
    cout << "\t\t\t 2. SEARCH FOOD UNDER YOUR PRICE:\n";
    cout << "\t\t\t 3. SEARCH FOOD BY NAME:\n";
    cout << "\t\t\t 4. SEARCH BY CATEGORY:\n";
    cout << "\t\t\t 0. BACK TO MAIN MENU\n";
    cout << "\t\t\t PLEASE SELECT A SEARCH TYPE: ";
    cin >> selectedOption;

    switch(selectedOption) {
        case 1:
            searchFoodPrice();
            break;
        case 2:
            searchFoodUnderPrice();
            break;
        case 3:
            searchFoodByName();
            break;
        case 4:
            searchFoodCategory();
            break;
        default:
           cout << "\t\t\t"  << "INVALID INPUT\n";
    }

    cout << "\n";
}

int main() {
    int mainmenu;
    do {
        cout << "\n\t\t\t Welcome To Cafeteria Food System\n";
        cout << "\t\t\t Version 2.0 | Created By Team Web Development\n\n";
        cout << "\t\t\t 1.CREATE NEW FOOD MENU\n";
        cout << "\t\t\t 2.DISPLAY ALL FOOD\n";
        cout << "\t\t\t 3.SEARCH FOOD\n";
        cout << "\t\t\t 0.EXIT\n\n";
        cout << "\t\t\t Please Select What You Want To Do : ";
        cin >> mainmenu;
        switch(mainmenu) {
            case 1:
                createfood();
                break;
            case 2:
                showallfood();
                break;
            case 3:
                searchFoodController();
                break;
            case 0:
                cout << "\n";
                cout << "\t\t\t Thank You For Using Cafeteria Food Management System.\n\n";
                break;
            default:
                cout << "Invalid input\n";
        }

    } while(mainmenu != 0);
    return 0;
}
