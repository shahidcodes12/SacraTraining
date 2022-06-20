#ifndef _VEHICLE_MANAGER_H_
#define _VEHICLE_MANAGER_H_

#include <vector>
#include <memory>

#include "Vehicle.hpp"

class VehicleManager
{
private:
    std::vector<std::shared_ptr<Vehicle>> vehicles;

    VehicleManager();

public:
    virtual ~VehicleManager();

    VehicleManager(const VehicleManager &source) = delete;

    VehicleManager &operator=(const VehicleManager &source) = delete;

    int GetVehicleCount() const;

    void AddVehicle(std::shared_ptr<Vehicle> vehicle);

    void PrintInfoOfAllVehicles() const;

    void TakeFirstVehicleOfVehicleType(std::string vehicleType);

    void VehicleCountByVehicleType(std::string vehicleType) const;

    void FindVehicleByLicense(std::string licensePlate) const;

    static std::shared_ptr<VehicleManager> &GetVehicleManagerInstance();
};

#endif // _VEHICLE_MANAGER_H_