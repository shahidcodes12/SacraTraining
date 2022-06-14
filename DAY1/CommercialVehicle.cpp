#include "CommercialVehicle.h"

CommercialVehicle::CommercialVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType, double loadCapacity)
    : Vehicle(licensePlate, chassisNumber, engineType, vehicleType), loadCapacity{loadCapacity}
{
  std::cout << "Constructor called for Commercial Vehicle\n";
}

CommercialVehicle::~CommercialVehicle()
{
  std::cout << "Destructor called for Commercial Vehicle\n";
}

double CommercialVehicle::GetLoadCapacity() const
{
  return loadCapacity;
}