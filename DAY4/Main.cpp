//
// Author : Mohammed Shahid M A
//

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "VehicleManager.hpp"

int main()
{
  VehicleManager managerOne{};

  managerOne.AddPassengerVehicle("TN 37 OOP", "IDFAI82310", EngineTypes::Petrol, "suv", 2);

  managerOne.AddPassengerVehicle("TN 23 OOA", "YGFAI89125", EngineTypes::Petrol, "sedan", 2);

  managerOne.AddCommercialVehicle("TN 25 OOD", "ITYAI878790", EngineTypes::Diesel, "truck", 40000.567);

  managerOne.AddCommercialVehicle("TN 66 OOAD", "HJKJKBUEE90", EngineTypes::Diesel, "truck", 500.789);

  managerOne.AddCommercialVehicle("TN 67 OOAD", "HJKJKBUEE90", EngineTypes::Diesel, "truck", 500.789);

  managerOne.AddCommercialVehicle("TN 68 OOAD", "HJKJKBUEE90", EngineTypes::Diesel, "truck", 500.789);

  std::cout << "There are " << managerOne.GetNumberOfVehicles() << " cars\n\n";

  managerOne.TakeFirstCarOfVehicleType("truck");
  std::cout << "There are " << managerOne.GetNumberOfVehicles() << " cars\n\n";

  managerOne.TakeFirstCarOfVehicleType("suv");
  std::cout << "There are " << managerOne.GetNumberOfVehicles() << " cars\n\n";

  managerOne.TakeFirstCarOfVehicleType("truck");
  std::cout << "There are " << managerOne.GetNumberOfVehicles() << " cars\n\n";

  managerOne.TakeFirstCarOfVehicleType("sedan");
  std::cout << "There are " << managerOne.GetNumberOfVehicles() << " cars\n\n";

  managerOne.TakeFirstCarOfVehicleType("truck");
  std::cout << "There are " << managerOne.GetNumberOfVehicles() << " cars\n\n";

  managerOne.TakeFirstCarOfVehicleType("truck");
  std::cout << "There are " << managerOne.GetNumberOfVehicles() << " cars\n\n";

  return 0;
}