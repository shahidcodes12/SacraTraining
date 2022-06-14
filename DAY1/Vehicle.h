#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>
#include <string>

enum class EngineTypes
{
  Petrol,
  Diesel
};

class Vehicle
{
protected:
  std::string licensePlate;
  std::string chassisNumber;
  EngineTypes engineType;
  std::string vehicleType;

public:
  Vehicle(std::string licensePlate, std::string chassisNumber, EngineTypes engineType, std::string vehicleType);

  virtual ~Vehicle();

  std::string GetLicensePlate() const;
  std::string GetChassisNumber() const;
  std::string GetEngineType() const;
  std::string GetVehicleType() const;
};

#endif // _VEHICLE_H_