//
// Author : Mohammed Shahid M A
//

#include <iostream>
#include <vector>
#include <memory>

#include "PassengerVehicle.hpp"
#include "CommercialVehicle.hpp"

void PrintVehicleInfo(const std::shared_ptr<Vehicle> &source)
{
  std::cout << source->GetLicensePlate() << "\n";
  std::cout << source->GetChassisNumber() << "\n";
  std::cout << source->GetEngineType() << "\n";
  std::cout << source->GetVehicleType() << "\n";
  std::cout << "\n";
}

int main()
{
  std::vector<std::shared_ptr<Vehicle>> vehicles;
  vehicles.push_back(std::make_shared<PassengerVehicle>("UK 25 O", "IDFAI82310", EngineTypes::Petrol, "sedan", 2));
  vehicles.push_back(std::make_shared<CommercialVehicle>("US 25 O", "ITYAI878790", EngineTypes::Diesel, "truck", 40000.567));

  for (int i{}; i < static_cast<int>(vehicles.size()); i++)
  {
    PrintVehicleInfo(vehicles[i]);
    std::cout << "\n";
  }

  return 0;
}