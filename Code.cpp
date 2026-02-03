#include <iostream>   // input / output
#include <vector>     // vector container
#include <string>     // string type
#include <limits>     // numeric_limits for input buffer
using namespace std;

// Structure to store farmer data
struct Farmer {
    string name;
    int id;
    string crop;
    float landSize;
    float waterRequired;
    int seedsRequired;
    string fertilizer;
    string season;
};

// Function to calculate requirements based on crop
void calculateNeeds(Farmer &f) {
    if (f.crop == "wheat") {
        f.waterRequired = f.landSize * 4000;
        f.seedsRequired = f.landSize * 50;
        f.fertilizer = "Urea + DAP";
        f.season = "Winter";
    }
    else if (f.crop == "rice") {
        f.waterRequired = f.landSize * 6000;
        f.seedsRequired = f.landSize * 60;
        f.fertilizer = "Organic Fertilizer";
        f.season = "Summer";
    }
    else if (f.crop == "sugarcane") {
        f.waterRequired = f.landSize * 8000;
        f.seedsRequired = f.landSize * 70;
        f.fertilizer = "Potash Based";
        f.season = "Summer";
    }
    else { // for invalid crop
        f.waterRequired = 0;
        f.seedsRequired = 0;
        f.fertilizer = "Unknown";
        f.season = "Unknown";
    }
}

// Function to display project title
void displayTitleBox() {
    cout << "+==========================================+\n";
    cout << "+         Farmer Management System         +\n";
    cout << "+==========================================+\n";
}

// Function to display farmer details
void displayFarmer(const Farmer &f) {
    cout << "+==========================================+\n";
    cout << "Name           : " << f.name << endl;
    cout << "ID             : " << f.id << endl;
    cout << "Crop           : " << f.crop << endl;
    cout << "Land Size      : " << f.landSize << " acres\n";
    cout << "Water Required : " << f.waterRequired << " liters\n";
    cout << "Seeds Required : " << f.seedsRequired << " kg\n";
    cout << "Fertilizer     : " << f.fertilizer << endl;
    cout << "Season         : " << f.season << endl;
    cout << "+==========================================+\n";
}

int main() {
    displayTitleBox(); // show title

    int totalFarmers;
    cout << "Enter total number of farmers: ";
    cin >> totalFarmers;

    vector<Farmer> farmers; // store all farmers

    for (int i = 0; i < totalFarmers; i++) {
        Farmer f;

        cout << "\nEnter details for Farmer " << i + 1 << endl;

        cout << "ID: ";
        cin >> f.id;

        // clear input buffer before getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Name: ";
        getline(cin, f.name);

        cout << "Crop (wheat/rice/sugarcane): ";
        cin >> f.crop;

        cout << "Land Size (acres): ";
        cin >> f.landSize;

        calculateNeeds(f);  // calculate requirements
        displayFarmer(f);   // display result
        farmers.push_back(f);
    }

    return 0; // program end
}

