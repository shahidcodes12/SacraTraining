#include "PassengerVehicle.hpp"

PassengerVehicle::PassengerVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType, int numberOfPersons)
    : Vehicle(licensePlate, chassisNumber, engineType, vehicleType), numberOfPersons{numberOfPersons}
{
}

PassengerVehicle::~PassengerVehicle()
{
}

int PassengerVehicle::GetNumberOfPersons() const
{
  return numberOfPersons;
}