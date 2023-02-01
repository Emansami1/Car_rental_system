#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car {
  string make;
  string model;
  string license_plate;
  bool is_rented;
};

void display_cars(const vector<Car>& cars) {
  cout << "Cars in Inventory:\n";
  for (const auto& car : cars) {
    cout << car.make << " " << car.model << " " << car.license_plate << " "
         << (car.is_rented ? "(rented)\n" : "(available)\n");
  }
}

void rent_car(vector<Car>& cars) {
  cout << "Enter license plate of car to rent: ";
  string license_plate;
  cin >> license_plate;

  for (auto& car : cars) {
    if (car.license_plate == license_plate && !car.is_rented) {
      car.is_rented = true;
      cout << car.make << " " << car.model << " " << car.license_plate
           << " has been rented.\n";
      return;
    }
  }

  cout << "Could not find car with license plate " << license_plate
       << " or it is already rented.\n";
}

void return_car(vector<Car>& cars) {
  cout << "Enter license plate of car to return: ";
  string license_plate;
  cin >> license_plate;

  for (auto& car : cars) {
    if (car.license_plate == license_plate && car.is_rented) {
      car.is_rented = false;
      cout << car.make << " " << car.model << " " << car.license_plate
           << " has been returned.\n";
      return;
    }
  }

  cout << "Could not find rented car with license plate " << license_plate
       << ".\n";
}

int main() {
  vector<Car> cars = {
      {"Toyota", "Camry", "ABC-123", false},
      {"Honda", "Accord", "DEF-456", false},
      {"Ford", "Mustang", "GHI-789", true},
  };

  while (true) {
    display_cars(cars);

    cout << "Enter 1 to rent a car, 2 to return a car, or 0 to exit: ";
    int option;
    cin >> option;

    if (option == 0) {
      break;
    } else if (option == 1) {
      rent_car(cars);
    } else if (option == 2) {
      return_car(cars);
    }
  }

  return 0;
}
      