#include "assemble.h"
#include "question.h"

using namespace std;

char carTypeStr[MAX_CAR_TYPE + 1][6] = { "", "Sedan", "SUV", "Truck" };
char engineStr[MAX_ENGINE + 1][7] = { "", "GM", "TOYOTA", "WIA" };
char brakeSystemStr[MAX_BREAK_SYSTEM + 1][12] = { "", "MANDO", "CONTINENTAL", "BOSCH" };
char steeringSystemStr[MAX_STEERING_SYSTEM + 1][6] = { "", "BOSCH", "MOBIS" };

void delay_ms(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

void Car::run() {
    if (!isValidCheck()) {
        cout << "자동차가 동작되지 않습니다" << endl;
        return;
    }

    if (engine == BREAK_DOWN) {
        cout << "엔진이 고장나있습니다." << endl;
        cout << "자동차가 움직이지 않습니다." << endl;
    }
    else
    {
        cout << "Car Type : " << carTypeStr[carType] << endl;
        cout << "Engine : " << engineStr[engine] << endl;
        cout << "Brake System : " << brakeSystemStr[brakeSystem] << endl;
        cout << "Steering System : " << steeringSystemStr[steeringSystem] << endl;
        cout << "자동차가 동작됩니다." << endl;
    }
}

void Car::test() {
    if (!isValidCheckTest()) return;
    cout << "자동차 부품 조합 테스트 결과 : PASS" << endl;
}

bool Car::isValidCheck()
{
    if (carType == SEDAN && brakeSystem == CONTINENTAL)
    {
        return false;
    }
    else if (carType == SUV && engine == TOYOTA)
    {
        return false;
    }
    else if (carType == TRUCK && engine == WIA)
    {
        return false;
    }
    else if (carType == TRUCK && brakeSystem == MANDO)
    {
        return false;
    }
    else if (brakeSystem == BOSCH_B && steeringSystem != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Car::isValidCheckTest() {
    if (carType == SEDAN && brakeSystem == CONTINENTAL)
    {
        cout << "자동차 부품 조합 테스트 결과 : FAIL" << endl;
        cout << "Sedan에는 Continental제동장치 사용 불가" << endl;
        return false;
    }
    else if (carType == SUV && engine == TOYOTA)
    {
        cout << "자동차 부품 조합 테스트 결과 : FAIL" << endl;
        cout << "SUV에는 TOYOTA엔진 사용 불가" << endl;
        return false;
    }
    else if (carType == TRUCK && engine == WIA)
    {
        cout << "자동차 부품 조합 테스트 결과 : FAIL" << endl;
        cout << "Truck에는 WIA엔진 사용 불가" << endl;
        return false;
    }
    else if (carType == TRUCK && brakeSystem == MANDO)
    {
        cout << "자동차 부품 조합 테스트 결과 : FAIL" << endl;
        cout << "Truck에는 Mando제동장치 사용 불가" << endl;
        return false;
    }
    else if (brakeSystem == BOSCH_B && steeringSystem != BOSCH_S)
    {
        cout << "자동차 부품 조합 테스트 결과 : FAIL" << endl;
        cout << "Bosch제동장치에는 Bosch조향장치 이외 사용 불가" << endl;;
        return false;
    }
    return true;
}

CarBuilder& CarBuilder::setCarType(CarType type) {
    this->carType = type;
    printf("차량 타입으로 %s을 선택하셨습니다.\n", carTypeStr[type]);
    return *this;
}

CarBuilder& CarBuilder::setEngine(Engine engine) {
    this->engine = engine;
    printf("%s 엔진을 선택하셨습니다.\n", engineStr[engine]);
    return *this;
}

CarBuilder& CarBuilder::setBrakeSystem(BrakeSystem brake) {
    this->brakeSystem = brake;
    printf("%s 제동장치를 선택하셨습니다.\n", brakeSystemStr[brakeSystem]);
    return *this;
}

CarBuilder& CarBuilder::setSteeringSystem(SteeringSystem steer) {
    this->steeringSystem = steer;
    printf("%s 조향장치를 선택하셨습니다.\n", steeringSystemStr[steeringSystem]);
    return *this;
}

shared_ptr<Car> CarBuilder::build() {
    auto car = make_shared<Car>();
    car->carType = carType;
    car->engine = engine;
    car->brakeSystem = brakeSystem;
    car->steeringSystem = steeringSystem;
    return car;
}

bool CarBuilder::checkAnsner(int step, int answer) {
    if (step == CarType_Q && (answer < MIN_CAR_TYPE || answer > MAX_CAR_TYPE))
    {
        printf("ERROR :: 차량 타입은 %d ~ %d 범위만 선택 가능\n", MIN_CAR_TYPE, MAX_CAR_TYPE);
        delay_ms(800);
        return false;
    }

    if (step == Engine_Q && (answer < MIN_ENGINE || answer > MAX_ENGINE))
    {
        printf("ERROR :: 엔진은 %d ~ %d 범위만 선택 가능\n", MIN_ENGINE, MAX_ENGINE);
        delay_ms(800);
        return false;
    }

    if (step == brakeSystem_Q && (answer < MIN_BREAK_SYSTEM || answer > MAX_BREAK_SYSTEM))
    {
        printf("ERROR :: 제동장치는 %d ~ %d 범위만 선택 가능\n", MIN_BREAK_SYSTEM, MAX_BREAK_SYSTEM);
        delay_ms(800);
        return false;
    }

    if (step == SteeringSystem_Q && (answer < MIN_STEERING_SYSTEM || answer > MAX_STEERING_SYSTEM))
    {
        printf("ERROR :: 조향장치는 %d ~ %d 범위만 선택 가능\n", MIN_STEERING_SYSTEM, MAX_STEERING_SYSTEM);
        delay_ms(800);
        return false;
    }

    if (step == Run_Test && (answer < MIN_DRIVE_TYPE || answer > MAX_DRIVE_TYPE))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay_ms(800);
        return false;
    }
    return true;
}

bool CarBuilder::isNumber(char* checkNumber) {
    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        delay_ms(800);
        return false;
    }
    return true;
}