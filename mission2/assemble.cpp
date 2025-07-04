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
        cout << "�ڵ����� ���۵��� �ʽ��ϴ�" << endl;
        return;
    }

    if (engine == BREAK_DOWN) {
        cout << "������ ���峪�ֽ��ϴ�." << endl;
        cout << "�ڵ����� �������� �ʽ��ϴ�." << endl;
    }
    else
    {
        cout << "Car Type : " << carTypeStr[carType] << endl;
        cout << "Engine : " << engineStr[engine] << endl;
        cout << "Brake System : " << brakeSystemStr[brakeSystem] << endl;
        cout << "Steering System : " << steeringSystemStr[steeringSystem] << endl;
        cout << "�ڵ����� ���۵˴ϴ�." << endl;
    }
}

void Car::test() {
    if (!isValidCheckTest()) return;
    cout << "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS" << endl;
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
        cout << "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL" << endl;
        cout << "Sedan���� Continental������ġ ��� �Ұ�" << endl;
        return false;
    }
    else if (carType == SUV && engine == TOYOTA)
    {
        cout << "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL" << endl;
        cout << "SUV���� TOYOTA���� ��� �Ұ�" << endl;
        return false;
    }
    else if (carType == TRUCK && engine == WIA)
    {
        cout << "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL" << endl;
        cout << "Truck���� WIA���� ��� �Ұ�" << endl;
        return false;
    }
    else if (carType == TRUCK && brakeSystem == MANDO)
    {
        cout << "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL" << endl;
        cout << "Truck���� Mando������ġ ��� �Ұ�" << endl;
        return false;
    }
    else if (brakeSystem == BOSCH_B && steeringSystem != BOSCH_S)
    {
        cout << "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL" << endl;
        cout << "Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�" << endl;;
        return false;
    }
    return true;
}

CarBuilder& CarBuilder::setCarType(CarType type) {
    this->carType = type;
    printf("���� Ÿ������ %s�� �����ϼ̽��ϴ�.\n", carTypeStr[type]);
    return *this;
}

CarBuilder& CarBuilder::setEngine(Engine engine) {
    this->engine = engine;
    printf("%s ������ �����ϼ̽��ϴ�.\n", engineStr[engine]);
    return *this;
}

CarBuilder& CarBuilder::setBrakeSystem(BrakeSystem brake) {
    this->brakeSystem = brake;
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", brakeSystemStr[brakeSystem]);
    return *this;
}

CarBuilder& CarBuilder::setSteeringSystem(SteeringSystem steer) {
    this->steeringSystem = steer;
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", steeringSystemStr[steeringSystem]);
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
        printf("ERROR :: ���� Ÿ���� %d ~ %d ������ ���� ����\n", MIN_CAR_TYPE, MAX_CAR_TYPE);
        delay_ms(800);
        return false;
    }

    if (step == Engine_Q && (answer < MIN_ENGINE || answer > MAX_ENGINE))
    {
        printf("ERROR :: ������ %d ~ %d ������ ���� ����\n", MIN_ENGINE, MAX_ENGINE);
        delay_ms(800);
        return false;
    }

    if (step == brakeSystem_Q && (answer < MIN_BREAK_SYSTEM || answer > MAX_BREAK_SYSTEM))
    {
        printf("ERROR :: ������ġ�� %d ~ %d ������ ���� ����\n", MIN_BREAK_SYSTEM, MAX_BREAK_SYSTEM);
        delay_ms(800);
        return false;
    }

    if (step == SteeringSystem_Q && (answer < MIN_STEERING_SYSTEM || answer > MAX_STEERING_SYSTEM))
    {
        printf("ERROR :: ������ġ�� %d ~ %d ������ ���� ����\n", MIN_STEERING_SYSTEM, MAX_STEERING_SYSTEM);
        delay_ms(800);
        return false;
    }

    if (step == Run_Test && (answer < MIN_DRIVE_TYPE || answer > MAX_DRIVE_TYPE))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        delay_ms(800);
        return false;
    }
    return true;
}

bool CarBuilder::isNumber(char* checkNumber) {
    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        delay_ms(800);
        return false;
    }
    return true;
}