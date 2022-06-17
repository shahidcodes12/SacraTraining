#include <iostream>
#include <algorithm>

#include "VehicleManager.hpp"

VehicleManager::VehicleManager()
{
    std::cout << "Manager constructor called\n";
}

VehicleManager::~VehicleManager()
{
    std::cout << "Manager destructor called\n";
}

int VehicleManager::GetNumberOfVehicles() const
{
    return static_cast<int>(vehicles.size());
}

void VehicleManager::AddPassengerVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes enginetype, std::string vehicleType, int numberOfPersons)
{
    vehicles.push_back(std::make_shared<PassengerVehicle>(licensePlate, chassisNumber, enginetype, vehicleType, numberOfPersons));
}

void VehicleManager::AddCommercialVehicle(std::string licensePlate, std::string chassisNumber, EngineTypes enginetype, std::string vehicleType, double loadCapacity)
{
    vehicles.push_back(std::make_shared<CommercialVehicle>(licensePlate, chassisNumber, enginetype, vehicleType, loadCapacity));
}

void VehicleManager::PrintInfoOfAllCars() const
{
    if (GetNumberOfVehicles() != 0)
    {
        for (auto it{vehicles.begin()}; it != vehicles.end(); it++)
        {
            (*it)->PrintVehicleInfo();
        }
        return;
    }
    std::cout << "\nNo Cars in the garage\n";
}

void VehicleManager::TakeFirstCarOfVehicleType(std::string vehicleType)
{
    std::transform(vehicleType.begin(), vehicleType.end(), vehicleType.begin(), ::tolower);
    auto itr{
        std::find_if(
            vehicles.begin(),
            vehicles.end(),
            [&vehicleType](const auto &vehicle) -> bool
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

void VehicleManager::CarCountByVehicleType(std::string vehicleType) const
{
    if (GetNumberOfVehicles() == 0)
    {
        std::cout << "\nNo cars in the garage\n\n";
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

void VehicleManager::FindCarByLicense(std::string licensePlate) const
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