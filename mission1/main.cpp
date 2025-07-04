#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (*QuestionFunc)(void);
#define CLEAR_SCREEN "\033[H\033[2J"
#define MAX_STACK_COUNT (10)

int stack[MAX_STACK_COUNT];

void selectCarType(int answer);
void selectEngine(int answer);
void selectbrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay_ms(int ms);

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
    MAX_QUESTION_TYPE = 5
};

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

enum brakeSystem
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

char carType[MAX_CAR_TYPE+1][6] = { "", "Sedan", "SUV", "Truck" };
char engine[MAX_ENGINE+1][7] = { "", "GM", "TOYOTA", "WIA" };
char brakeSystem[MAX_BREAK_SYSTEM+1][12] = { "", "MANDO", "CONTINENTAL", "BOSCH" };
char steeringSystem[MAX_STEERING_SYSTEM+1][6] = { "", "BOSCH", "MOBIS" };

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


void questioncarType(void) {
    printf(CLEAR_SCREEN);
    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("� ���� Ÿ���� �����ұ��?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
    return;
}

void questionEngine(void) {
    printf(CLEAR_SCREEN);
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. ���峭 ����\n");
    return;
}

void questionBreakSystem(void) {
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
    return;
}

void questionSteeringSytem(void) {
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
    return;
}

void runTest(void) {
    printf(CLEAR_SCREEN);
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
    printf("1. RUN\n");
    printf("2. Test\n");
    return;
}

bool checkAnsner(int step, int answer) {
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

bool isNumber(char* checkNumber) {
    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        delay_ms(800);
        return false;
    }
    return true;
}

bool doAssemble(int step, int answer) {
    if (step == CarType_Q)
    {
        selectCarType(answer);
        delay_ms(800);
        return true;
    }
    else if (step == Engine_Q)
    {
        selectEngine(answer);
        delay_ms(800);
        return true;
    }
    else if (step == brakeSystem_Q)
    {
        selectbrakeSystem(answer);
        delay_ms(800);
        return true;
    }
    else if (step == SteeringSystem_Q)
    {
        selectSteeringSystem(answer);
        delay_ms(800);
        return true;
    }
    else {
        return false;
    }
}

void doDriveTest(int step, int answer) {
    if (step == Run_Test && answer == DRIVE_TYPE_RUN)
    {
        runProducedCar();
        delay_ms(2000);
    }
    else if (step == Run_Test && answer == DRIVE_TYPE_TEST)
    {
        printf("Test...\n");
        delay_ms(1500);
        testProducedCar();
        delay_ms(2000);
    }
}

int main()
{
    char buf[100];
    int step = CarType_Q;
    QuestionFunc questionFunc[MAX_QUESTION_TYPE] = { questioncarType,  questionEngine , questionBreakSystem , questionSteeringSytem , runTest };

    while (1)
    {
        if (step >= MAX_QUESTION_TYPE)
        {
            printf("ERROR : step is invalid(%d)\r\n", step);
        }
        questionFunc[step]();
        printf("===============================\n");

        printf("INPUT > ");
        fgets(buf, sizeof(buf), stdin);

        // ���� ���๮�� ����
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("���̹���\n");
            break;
        }

        // ���ڷ� �� ������� Ȯ��
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

        // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
        if (isNumber(checkNumber) == false) {
            continue;
        }

        // ó������ ���ư���
        if (answer == 0 && step == Run_Test)
        {
            step = CarType_Q;
            continue;
        }

        // �������� ���ư���
        if (answer == 0 && step >= Engine_Q)
        {
            step -= 1;
            continue;
        }

        // ��� ���� Ȯ��
        if (checkAnsner(step, answer) == false) {
            continue;
        }
        if (doAssemble(step, answer) == true)
        {
            step++;
        }
        else
        {
            doDriveTest(step, answer);
        }
    }
}

void selectCarType(int answer)
{
    stack[CarType_Q] = answer;
    printf("���� Ÿ������ %s�� �����ϼ̽��ϴ�.\n", carType[answer]);
}

void selectEngine(int answer)
{
    stack[Engine_Q] = answer;
    printf("%s ������ �����ϼ̽��ϴ�.\n", engine[answer]);
}

void selectbrakeSystem(int answer)
{
    stack[brakeSystem_Q] = answer;
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", brakeSystem[answer]);
}

void selectSteeringSystem(int answer)
{
    stack[SteeringSystem_Q] = answer;
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", steeringSystem[answer]);
}

int isValidCheck()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (stack[Engine_Q] == BREAK_DOWN)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        }
        else
        {
            printf("Car Type : %s\n", carType[stack[CarType_Q]]);
            printf("Engine : %s\n", engine[stack[Engine_Q]]);
            printf("Brake System : %s\n", brakeSystem[stack[brakeSystem_Q]]);
            printf("SteeringSystem : %s\n", steeringSystem[stack[SteeringSystem_Q]]);
            printf("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}

#endif