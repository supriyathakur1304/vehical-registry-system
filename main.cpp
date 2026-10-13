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
    static int getTotalVehicles()
    {
        return totalVehicles;
    }
  void display()
    {
        cout << "Vehicle id: " << vehicleID <<endl;
        cout<< "Manufacturer: " << manufacturer <<endl;
        cout<< "Model: " << model <<endl;
        cout<< "Year: " << year<<endl;
    }
};
int Vehicle::totalVehicles = 0;
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
    
    void display()
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
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
    void display()
    {
        Car::display();
        cout << "Battery Capacity : " << batteryCapacity << endl;
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
    void display()
    {
        cout << "Flight Range : " << flightRange << endl;
    }
};
class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft()
    {
    }
    FlyingCar(int id, string manu, string mod, int y, string fuel, int flight) : Car(id, manu, mod, y, fuel), Aircraft(flight)
    {
    }
    void display()
    {
        Car::display();
        Aircraft::display();
        cout << "[Flying Car]" << endl;
    }
};
class SportCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportCar() : ElectricCar()
    {
        topSpeed = 0;
    }
    SportCar(int id, string manu, string mod, int y, string fuel, int battery, int speed) : ElectricCar(id, manu, mod, y, fuel, battery)
    {
        topSpeed = speed;
    }
    void set_topSpeed(int speed)
    {
        topSpeed = speed;
    }
    int get_topSpeed()
    {
        return topSpeed;
    }
    void display()
    {
        ElectricCar::display();
        cout << "topSpeed : " << topSpeed << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan() : Car()
    {
    }
    Sedan(int id, string manu, string mod, int y, string fuel) : Car(id, manu, mod, y, fuel)
    {
    }
    void display()
    {
        Car::display();
        cout << "[Sedan]" << endl;
    }
};
class SUV : public Car
{
public:
    SUV() : Car()
    {
    }
    SUV(int id, string manu, string mod, int y, string fuel) : Car(id, manu, mod, y, fuel)
    {
    }
    void display()
    {
        Car::display();
        cout << "[SUV]" << endl;
    }
};

class VehicleRegistry
    {
    public:
        Vehicle vehicle[10];
        int totalVehicle = 0;

        void add_vehicle(Vehicle v)
        {
            vehicle[totalVehicle] = v;
            totalVehicle++;
            cout << "Vehicle added successfully!" << endl;
        }

        void viewAllVehicles()
        {
            for (int i = 0; i < totalVehicle; i++)
            {
                vehicle[i].display();
            }
        }
        void searchByID(int id)
        {
            for (int i = 0; i < totalVehicle; i++)
            {
                if (vehicle[i].get_vehicleID() == id)
                {
                    cout << "Vehicle found!" << endl;
                    vehicle[i].display();
                    return;
                }
            }
        }
    };

int main()
{
    VehicleRegistry vr;
    int choice;
    do
    {
        cout<<"----Vehicle Registry----"<<endl;
        cout<< "1. Add a vehicle" << endl;
        cout << "2. View all vehicle" << endl;
        cout << "3.Search by ID" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 1)
        {
            int type, id, y,battery=0,speed=0,range=0;
            string manu, mod, fuel;

            cout << "Choose Type : 1. Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV : ";
            cin >> type;

            cout << "Enter vehicle id : ";
            cin >> id;

            cout << "Enter manufacture : ";
            cin >> manu;

            cout << "Enter your model : ";
            cin >> mod;

            cout << "Enter year : ";
            cin >> y;

            cout << "Enter fuel type : ";
            cin >> fuel;

            if (type == 1)
            {
                Car c(id, manu, mod, y, fuel);
                vr.add_vehicle(c);
            }
            else if (type == 2)
            {
                cout << "Enter Battery Capacity: ";
                cin >> battery;
                ElectricCar c(id, manu, mod, y, fuel, battery);
                vr.add_vehicle(c);
            }
            else if (type == 3)
            {
                cout << "Enter Flight Range: ";
                cin >> range;
                FlyingCar c(id, manu, mod, y, fuel, range);
                vr.add_vehicle(c);
            }
            else if (type == 4)
            {
                cout << "Enter Battery Capacity: ";
                cin >> battery;

                cout << "Enter Top Speed: ";
                cin >> speed;

                SportCar c(id, manu, mod, y, fuel, battery, speed);
                vr.add_vehicle(c);
            }
            else if (type == 5)
            {
                Sedan c(id,manu,mod,y,fuel);
                vr.add_vehicle(c);
            }
            else if (type == 6)
            {
                SUV c(id,manu,mod,y,fuel);
                vr.add_vehicle(c);
            }
        }
        else if (choice == 2)
        {
            vr.viewAllVehicles();
        }
        
        else if (choice == 3)
            {
                int id;

                cout << "Enter vehicle ID to search: ";
                cin >> id;

                vr.searchByID(id);
            }
            else if (choice == 4)
            {
                cout << "Exiting Vehicle Registry..." << endl;
            }
            else
            {
                cout << "Invalid choice! Try again." << endl;
            }
    } while (choice != 4);

    return 0;
    } 
