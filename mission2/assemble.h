#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void delay_ms(int ms);

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK,
    MIN_CAR_TYPE = SEDAN,
    MAX_CAR_TYPE = TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    BREAK_DOWN,
    MIN_ENGINE = GM,
    MAX_ENGINE = WIA,
};

enum BrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B,
    MIN_BREAK_SYSTEM = MANDO,
    MAX_BREAK_SYSTEM = BOSCH_B,
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS,
    MIN_STEERING_SYSTEM = BOSCH_S,
    MAX_STEERING_SYSTEM = MOBIS,
};

enum DriveType
{
    DRIVE_TYPE_RUN = 1,
    DRIVE_TYPE_TEST,
    MIN_DRIVE_TYPE = DRIVE_TYPE_RUN,
    MAX_DRIVE_TYPE = DRIVE_TYPE_TEST,
};

class Car {
public:
    CarType carType;
    Engine engine;
    BrakeSystem brakeSystem;
    SteeringSystem steeringSystem;

    void run();
    void test();
    bool isValidCheck();
    bool isValidCheckTest();
};

class CarBuilder {
private:
    CarType carType;
    Engine engine;
    BrakeSystem brakeSystem;
    SteeringSystem steeringSystem;

public:
    CarBuilder& setCarType(CarType type);
    CarBuilder& setEngine(Engine engine);
    CarBuilder& setBrakeSystem(BrakeSystem brake);
    CarBuilder& setSteeringSystem(SteeringSystem steer);
    bool isNumber(char* checkNumber);
    bool checkAnsner(int step, int answer);
    shared_ptr<Car> build();
};