//
// Author : Mohammed Shahid M A
//

#include <iostream>
#include <vector>

#include "PassengerVehicle.h"
#include "CommercialVehicle.h"

void PrintVehicleInfo(const Vehicle *source)
{
  std::cout << source->GetLicensePlate() << "\n";
  std::cout << source->GetChassisNumber() << "\n";
  std::cout << source->GetEngineType() << "\n";
  std::cout << source->GetVehicleType() << "\n";
  std::cout << "\n";
}

int main()
{
  std::vector<Vehicle *> vehicles;
  vehicles.push_back(new PassengerVehicle("UK 25 O", "IDFAI82310", EngineTypes::Petrol, "sedan", 2));
  vehicles.push_back(new CommercialVehicle("US 25 O", "ITYAI878790", EngineTypes::Diesel, "truck", 40000.567));

  for (int i{}; i < (int)vehicles.size(); i++)
  {
    PrintVehicleInfo(vehicles[i]);
    delete vehicles[i];
    std::cout << "\n";
  }

  return 0;
}