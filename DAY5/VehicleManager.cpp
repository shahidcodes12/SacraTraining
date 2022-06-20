#include <iostream>
#include <algorithm>

#include "VehicleManager.hpp"

std::shared_ptr<VehicleManager> &VehicleManager::GetVehicleManagerInstance()
{
    static std::shared_ptr<VehicleManager> vehicleManagerInstance{nullptr};

    if (!vehicleManagerInstance)
    {
        vehicleManagerInstance.reset(new VehicleManager());
    }

    return vehicleManagerInstance;
}

VehicleManager::VehicleManager()
{
    std::cout << "Vehicle Manager constructor called\n";
}

VehicleManager::~VehicleManager()
{
    std::cout << "Vehicle Manager destructor called\n";
}

int VehicleManager::GetVehicleCount() const
{
    return static_cast<int>(vehicles.size());
}

void VehicleManager::AddVehicle(const std::shared_ptr<Vehicle> vehicle)
{
    vehicles.push_back(vehicle);
}

void VehicleManager::PrintInfoOfAllVehicles() const
{
    if (GetVehicleCount() != 0)
    {
        std::cout << "\n---VEHICLES INFO---\n";
        for (auto it{vehicles.begin()}; it != vehicles.end(); it++)
        {
            (*it)->PrintVehicleInfo();
        }
        return;
    }

    std::cout << "\nNo Vehicles in the garage\n";
}

void VehicleManager::TakeFirstVehicleOfVehicleType(std::string vehicleType)
{
    std::transform(vehicleType.begin(), vehicleType.end(), vehicleType.begin(), ::tolower);

    auto itr{
        std::find_if(
                vehicles.begin(),
                vehicles.end(),
                [&](const auto &vehicle) -> bool
                {
                    return (vehicle->GetVehicleType() == vehicleType);
                })};

    if (itr != vehicles.end())
    {
        std::cout << "\nFirst " << vehicleType << " vehicle found\n";
        (*itr)->PrintVehicleInfo();
        vehicles.erase(itr);
        return;
    }

    std::cout << "\nNo " << vehicleType << "s available at the moment\n\n";
}

void VehicleManager::VehicleCountByVehicleType(std::string vehicleType) const
{
    if (GetVehicleCount() == 0)
    {
        std::cout << "\nNo Vehicles in the garage\n\n";
        return;
    }

    std::transform(vehicleType.begin(), vehicleType.end(), vehicleType.begin(), ::tolower);

    int countOfVehicleType{
        static_cast<int>(std::count_if(vehicles.begin(), vehicles.end(), [&vehicleType](const auto &vehicle) -> bool
                                       { return (vehicle->GetVehicleType() == vehicleType); }))};

    if (countOfVehicleType != 0)
    {
        std::cout << "\nThere are " << countOfVehicleType << " " << vehicleType << "s in the garage\n\n";
        return;
    }
    std::cout << "\nNo " << vehicleType << "s found\n\n";
}

void VehicleManager::FindVehicleByLicense(std::string licensePlate) const
{
    std::transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::toupper);

    auto itr{std::find_if(vehicles.begin(), vehicles.end(), [&licensePlate](const std::shared_ptr<Vehicle> &vehicle)
                          { return (vehicle->GetLicensePlate() == licensePlate); })};

    if (itr != vehicles.end())
    {
        std::cout << "\n---Vehicle Found---";
        (*itr)->PrintVehicleInfo();
        return;
    }

    std::cout << "\n---Vehicle Not Found---\n";
}