#include <iostream>
#include <Windows.h>
using namespace std;

class Car
{
private:
    string model;
    int year;
protected:
    int speed;
    float volume;
public:
    Car() :model("no model"), year(0), speed(0), volume(0){}
    Car(string m, int y, float v) :model(m), year(y), speed(0), volume(v){}
    virtual void Drive()const
    {
        cout << "I am a Car! I can drive with speed : " << speed << " km/h" << endl;
    }
    void setSpeed(int speed)
    {
        if (speed > 0)
            this->speed = speed;
        else
            speed = 0;
    }
    virtual void Print()const
    {
        cout << "---------------Car-----------------" << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
        cout << "Speed : " << speed << endl;
        cout << "Volume : " << volume << endl;
    }
};
class PoliceCar : public Car
{
    int soundVolume;
public:
    PoliceCar() :soundVolume(0), Car(){}
    PoliceCar(string n, int y, float v, int sound) :soundVolume(sound), Car(n,y,y){}
    void Drive()const override
    {
        cout << "I am a Police Car. I can drive with speed " << speed << " km/h" << endl;
    }
    void Print()const override
    {
        Car::Print();
        cout << "Sound Volume : " << soundVolume << "db" << endl;
    }
    void BeepBeep()
    {
        Beep(500, 200);
        Beep(400, 200);
        Beep(1000, 500);
        Beep(400, 200);
    }
    
};

class SportCar : public Car
{
    int turboSpeed;
public:
    SportCar() :turboSpeed(0), Car() {}
    SportCar(string n, int y, float v, int ts) :turboSpeed(ts), Car(n, y, y) {}
    void Drive()const
    {
        cout << "I am a Sport Car. I can drive with speed " << speed << " km/h" << endl;
    }
    void Print()const override
    {
        Car::Print();
        cout << "Turbo Speed : " << turboSpeed << "db" << endl;
    }
    void Nitro()
    {
        speed += turboSpeed;
        cout << "Turbo speed " << speed << "km/h" << endl;
    }
};


void TestDrive(Car& car)
{
    car.setSpeed(70);
    car.Drive();
    car.Print();
    cout << endl;
}
int main()
{
    Car car("BMV", 2024, 3.0);
    car.setSpeed(280);
    car.Drive();
    car.Print();
    cout << "------------------------------------" << endl;
    PoliceCar police("Renult Duster",2015,1.6,500);
    police.setSpeed(220);
    police.Drive();
    police.Print();

    SportCar sport("Formula 1", 2025, 2.5, 100);
    sport.setSpeed(150);
    sport.Drive();
    sport.Print();
    //police.BeepBeep();
    TestDrive(car);
    TestDrive(police);
    TestDrive(sport);

    

    Car* cars[3]{
        new Car("BMV", 2024, 3.0),
        new PoliceCar("Renult Duster",2015,1.6,500),
        new SportCar("Formula 1", 2025, 2.5, 100)
    };

    for (int i = 0; i < 3; i++)
    {
        cars[i]->Drive();
        cars[i]->Print();
        delete cars[i];
    }
}
