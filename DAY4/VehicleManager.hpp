#ifndef _VEHICLE_MANAGER_H_
#define _VEHICLE_MANAGER_H_

#include <vector>
#include <memory>

#include "PassengerVehicle.hpp"
#include "CommercialVehicle.hpp"

class VehicleManager
{
private:
    std::vector<std::shared_ptr<Vehicle>> vehicles;

public:
    VehicleManager();

    virtual ~VehicleManager();

    int GetNumberOfVehicles() const;

    void AddPassengerVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes enginetype, std::string vehicleType, int numberOfPersons);

    void AddCommercialVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes enginetype, std::string vehicleType, double loadCapacity);

    void PrintInfoOfAllCars() const;

    void TakeFirstCarOfVehicleType(std::string vehicleType);

    void CarCountByVehicleType(std::string vehicleType) const;
    
    void FindCarByLicense(std::string licensePlate) const;
};

#endif // _VEHICLE_MANAGER_H_