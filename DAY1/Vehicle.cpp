#include "Vehicle.h"

Vehicle::Vehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType)
    : licensePlate{licensePlate}, chassisNumber{chassisNumber}, engineType{engineType}, vehicleType{vehicleType}
{
  std::cout << "Overloaded Constructor called for (Parent) Vehicle\n";
}

Vehicle::~Vehicle()
{
  std::cout << "Destructor called for (Parent) Vehicle\n";
}

std::string Vehicle::GetLicensePlate() const
{
  return licensePlate;
}

std::string Vehicle::GetChassisNumber() const
{
  return chassisNumber;
}

std::string Vehicle::GetEngineType() const
{
  std::string engType{"Petrol"};
  if (engineType == EngineTypes::Diesel)
  {
    engType = "Diesel";
  }
  return engType;
}

std::string Vehicle::GetVehicleType() const
{
  return vehicleType;
}
