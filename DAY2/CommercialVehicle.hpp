#ifndef _COMMERCIAL_H_
#define _COMMERCIAL_H_

#include "Vehicle.hpp"

class CommercialVehicle : public Vehicle
{
private:
  double loadCapacity;

public:
  CommercialVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType, double loadCapacity);

  virtual ~CommercialVehicle();

  double GetLoadCapacity() const;
};

#endif // _COMMERCIAL_H_