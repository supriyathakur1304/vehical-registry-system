#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }
    Vehicle(int id, string manu, string mod, int y)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = y;
        totalVehicles++;
    }
    ~Vehicle()
    {
        totalVehicles--;
    }

    void set_vehicleID(int id)
    {
        vehicleID = id;
    }
    void set_manufacturer(string manu)
    {
        manufacturer = manu;
    }
    void set_model(string mod)
    {
        model = mod;
    }
    void set_year(int y)
    {
        year = y;
    }
    int get_vehicleID()
    {
        return vehicleID;
    }
    string get_manufacturer()
    {
        return manufacturer;
    }
    string get_model()
    {
        return model;
    }
    int get_year()
    {
        return year;
    }
};
class Car : public Vehicle
{
private:
    string fuelType;

public:
    Car() : Vehicle()
    {
        fuelType = "";
    }
    Car(int id, string manu, string mod, int y, string fuel) : Vehicle(id, manu, mod, y)
    {
        fuelType = fuel;
    }

    void set_fuelType(string fuel)
    {
        fuelType = fuel;
    }
    string get_fuelType()
    {
        return fuelType;
    }
};
class ElectricCar : public Car
{
private:
    int batteryCapacity;

    public:

    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string manu, string mod, int y, string fuel, int battery) : Car(id, manu, mod, y, fuel)
    {
        batteryCapacity = battery;
    }

    void set_batteryCapacity(int battery)
    {
        batteryCapacity = battery;
    }
    int get_batteryCapacity()
    {
        return batteryCapacity;
    }
};
class Aircraft
{
private:
    int flightRange;

    public:

    Aircraft()
    {
        flightRange = 0;
    }
    Aircraft(int flight)
    {
        flightRange = flight;
    }
    ~Aircraft()
    {
    }

    void set_flightRange(int flight)
    {
        flightRange = flight;
    }
    int get_flightRange()
    {
        return flightRange;
    }
};
class FlyingCar:public Car,public Aircraft
{
public:
    FlyingCar():Car(),Aircraft()
    {
    }
    FlyingCar(int id, string manu, string mod, int y, string fuel,int flight) :Car(id,manu,mod,y,fuel) ,Aircraft(flight)
    {
    }
};
class SportCar:public ElectricCar
{
private:
    int topSpeed;

    public:
        SportCar() : ElectricCar()
        {
            topSpeed=0;
        }
        SportCar(int id, string manu, string mod, int y, string fuel, int battery,int speed) : ElectricCar(id,manu,mod,y,fuel,battery){
            topSpeed=speed;
        }
        

   

   



    void set_topSpeed(int speed)
    {
        topSpeed = speed;
    }
    int get_topSpeed()
    {
        return topSpeed;
    }
};

int main()
{

    return 0;
}