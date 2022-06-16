//
// Author : Mohammed Shahid M A
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <memory>
#include <algorithm>

#include "PassengerVehicle.hpp"
#include "CommercialVehicle.hpp"

void PrintVehicleInfo(const std::shared_ptr<Vehicle> &source)
{
  std::cout << "\n";
  std::cout << source->GetLicensePlate() << "\n";
  std::cout << source->GetChassisNumber() << "\n";
  std::cout << source->GetEngineType() << "\n";
  std::cout << source->GetVehicleType() << "\n";
  std::cout << "\n";
}

bool IsSedan(const std::shared_ptr<Vehicle>) {
  return (vehicle->GetVehicleType() == "sedan");
}

void FindFirstSedan(const std::vector<std::shared_ptr<Vehicle>> &vehicles)
{
  auto itr{std::find_if(vehicles.begin(), vehicles.end(),IsSedan)};

  if (itr != vehicles.end())
  {
    std::cout << "\nVehicle found\n";
    PrintVehicleInfo((*itr));
    return;
  }
  std::cout << "\nVehicle not found\n";
}

void FindCarByLicense(const std::vector<std::shared_ptr<Vehicle>> &vehicles, std::string license)
{
  std::map<std::string, std::shared_ptr<Vehicle>> vehicleList;

  for (auto itr{vehicles.begin()}; itr != vehicles.end(); itr++)
  {
    vehicleList.insert(make_pair((*itr)->GetLicensePlate(), *itr));
  }

  auto it{vehicleList.find(license)};

  if (it != vehicleList.end())
  {
    std::cout << "\n---Vehicle Found---";
    PrintVehicleInfo(it->second);
    return;
  }
  std::cout << "\n---Vehicle Not Found---\n";
}

int main()
{
  std::vector<std::shared_ptr<Vehicle>> vehicles;

  vehicles.push_back(std::make_shared<PassengerVehicle>("TN 37 OOP", "IDFAI82310", EngineTypes::Petrol, "suv", 2));

  vehicles.push_back(std::make_shared<PassengerVehicle>("TN 23 OOA", "YGFAI89125", EngineTypes::Petrol, "sedan", 2));

  vehicles.push_back(std::make_shared<CommercialVehicle>("TN 25 OOD", "ITYAI878790", EngineTypes::Diesel, "truck", 40000.567));

  std::string license{"TN 23 OOA"};

  FindCarByLicense(vehicles, license);

  return 0;
}
