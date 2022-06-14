#include "PassengerVehicle.h"

PassengerVehicle::PassengerVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType, int numberOfPersons)
    : Vehicle(licensePlate, chassisNumber, engineType, vehicleType), numberOfPersons{numberOfPersons}
{
  std::cout << "Constructor called for Passenger Vehicle\n";
}

PassengerVehicle::~PassengerVehicle()
{
  std::cout << "Destructor called for Passenger Vehicle\n";
}

int PassengerVehicle::GetNumberOfPersons() const
{
  return numberOfPersons;
}