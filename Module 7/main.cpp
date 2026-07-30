#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// This class stores information about one car.
class Car
{
private:
    string name;
    string year;
    string sellingPrice;
    string kilometersDriven;
    string fuel;

public:
    // Constructor
    Car(string carName, string carYear, string price,
        string kilometers, string fuelType)
    {
        name = carName;
        year = carYear;
        sellingPrice = price;
        kilometersDriven = kilometers;
        fuel = fuelType;
    }

    // Display information about one car.
    void displayCar()
    {
        cout << "Car Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Selling Price: " << sellingPrice << endl;
        cout << "Kilometers Driven: " << kilometersDriven << endl;
        cout << "Fuel Type: " << fuel << endl;
        cout << "----------------------------------" << endl;
    }
};

int main()
{
    // Open the CSV data file.
    ifstream inputFile("cars.csv");

    // Check if the file opened successfully.
    if (!inputFile.is_open())
    {
        cout << "Error: Could not open cars.csv" << endl;
        return 1;
    }

    vector<Car> cars;
    string line;

    // Skip the first line because it contains column names.
    getline(inputFile, line);

    // Read only the first 10 cars from the file.
    while (getline(inputFile, line) && cars.size() < 10)
    {
        stringstream ss(line);

        string name;
        string year;
        string sellingPrice;
        string kilometersDriven;
        string fuel;

        // Read the first five fields from the CSV row.
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, sellingPrice, ',');
        getline(ss, kilometersDriven, ',');
        getline(ss, fuel, ',');

        // Create a Car object and add it to the vector.
        Car newCar(name, year, sellingPrice,
                   kilometersDriven, fuel);

        cars.push_back(newCar);
    }

    inputFile.close();

    cout << "CAR DETAILS FROM CAR DEKHO" << endl;
    cout << "Total cars loaded: " << cars.size() << endl;
    cout << "==================================" << endl;

    // Display all cars that were loaded.
    for (int i = 0; i < cars.size(); i++)
    {
        cout << "Car Number " << i + 1 << endl;
        cars[i].displayCar();
    }

    return 0;
}