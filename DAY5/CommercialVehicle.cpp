#include "CommercialVehicle.hpp"

CommercialVehicle::CommercialVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType, double loadCapacity)
    : Vehicle(licensePlate, chassisNumber, engineType, vehicleType), loadCapacity{loadCapacity}
{
}

CommercialVehicle::~CommercialVehicle()
{
}

double CommercialVehicle::GetLoadCapacity() const
{
  return loadCapacity;
}