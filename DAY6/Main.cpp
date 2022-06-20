//
// Author : Mohammed Shahid M A
//

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "VehicleManager.hpp"
#include "PassengerVehicle.hpp"
#include "CommercialVehicle.hpp"

int main()
{
  std::shared_ptr<VehicleManager> vehicleManager = VehicleManager::GetVehicleManagerInstance();

  vehicleManager->AddVehicle(std::make_shared<PassengerVehicle>("TN 38 OOA", "IDFAI82310", EngineTypes::Petrol, "suv", 4));

  vehicleManager->AddVehicle(std::make_shared<PassengerVehicle>("TN 37 OOP", "IDFAI82310", EngineTypes::Petrol, "suv", 2));

  vehicleManager->AddVehicle(std::make_shared<PassengerVehicle>("TN 23 OOA", "YGFAI89125", EngineTypes::Petrol, "sedan", 2));

  vehicleManager->AddVehicle(std::make_shared<CommercialVehicle>("TN 25 OOD", "ITYAI878790", EngineTypes::Diesel, "truck", 40000.567));

  vehicleManager->AddVehicle(std::make_shared<CommercialVehicle>("TN 66 OOAD", "HJKJKBUEE90", EngineTypes::Diesel, "truck", 500.789));

  vehicleManager->AddVehicle(std::make_shared<CommercialVehicle>("TN 68 OOAD", "HJKJKBUEE90", EngineTypes::Diesel, "truck", 500.789));

  vehicleManager->PrintInfoOfAllVehicles();

  vehicleManager->FindVehicleByLicense("TN 38 OOA");

  return 0;
}