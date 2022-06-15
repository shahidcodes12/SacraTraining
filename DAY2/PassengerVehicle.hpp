#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include "Vehicle.hpp"

class PassengerVehicle : public Vehicle
{
private:
  int numberOfPersons;

public:
  PassengerVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType, int numberOfPersons);

  virtual ~PassengerVehicle();

  int GetNumberOfPersons() const;
};

#endif // _PASSENGER_H_