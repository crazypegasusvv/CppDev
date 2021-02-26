#include "IVehicle.h"
#include <bits/stdc++.h>
#include <bits/shared_ptr.h>
#include <iostream>

typedef std::shared_ptr<IVehicle> IVehiclePtr;

class VehicleStorage
{
private:
    IVehiclePtr m_vehicle; // manages memory for us
    int m_numVehicles;
public:
    VehicleStorage() : m_vehicle(std::make_shared<Car>()), m_numVehicles(0) {} 
    VehicleStorage(IVehiclePtr vehicle) : m_vehicle(vehicle), m_numVehicles(0) {}
    VehicleStorage(IVehiclePtr vehicle, int numVehicles) : m_vehicle(vehicle), m_numVehicles(numVehicles) {}
    IVehiclePtr getVehicle() { return m_vehicle; }
    void addVehicles(int numVehicles) { m_numVehicles += numVehicles; }
    void getStoreDetails();
    int getAvailableVehicles() { return m_numVehicles; }
};     

void VehicleStorage::getStoreDetails()
{
	std::cout << "max speed of our vehicles is: " << m_vehicle->getMaxSpeed() << " kmph\n";
	std::cout << "max fuel capacity of our vehicles is: " << m_vehicle->getMaxFuelCapacity() << " litres\n";
	std::cout << "we have " << m_numVehicles << " vehicles in our storage\n";
}

int main()
{ 
    std::shared_ptr<VehicleStorage> vehicleStorage = std::make_shared<VehicleStorage>(std::make_shared<Car>(350, 180), 20);
    vehicleStorage->getStoreDetails();
    return 0;
}
