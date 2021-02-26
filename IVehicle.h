//  abstract class with virtual destructor
class IVehicle
{
public:
	virtual ~IVehicle() = default; // avoid memory leak
    virtual int getMaxFuelCapacity() = 0;
    virtual int getMaxSpeed() = 0;
};

class Car : public IVehicle
{
private:
	int m_remainingFuel;
	int m_maxFuelCapacity;
	int m_speed;
	int m_maxSpeed;
public:
	Car() : m_remainingFuel(0), 
		m_maxFuelCapacity(200), 
		m_speed(0), 
		m_maxSpeed(140) {}
	Car(int maxFuel, int maxSpeed) : m_remainingFuel(maxFuel), 
		m_maxFuelCapacity(maxFuel), 
		m_speed(0), 
		m_maxSpeed(maxSpeed) {}
	~Car() {}
	
    int getRemainingFuel() { return m_remainingFuel; }
    int getMaxFuelCapacity() {	return m_maxFuelCapacity; }
    int getMaxSpeed() { return m_maxSpeed; }
    int getCurrentSpeed() { return m_speed; }
};

