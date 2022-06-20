#include "Vehicle.hpp"

Vehicle::Vehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType)
    : licensePlate{licensePlate}, chassisNumber{chassisNumber}, engineType{engineType}, vehicleType{vehicleType}
{
}

Vehicle::~Vehicle()
{
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

void Vehicle::PrintVehicleInfo() const
{
  std::cout << "\n";
  std::cout << GetLicensePlate() << "\n";
  std::cout << GetChassisNumber() << "\n";
  std::cout << GetEngineType() << "\n";
  std::cout << GetVehicleType() << "\n";
  std::cout << "\n";
}