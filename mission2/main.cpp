#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "question.h"
#include "assemble.h"

extern void delay_ms(int ms);

using namespace std;

int main()
{
    char buf[100];
    int step = CarType_Q;
    typedef void (*QuestionFunc)();
    QuestionFunc questionFunc[MAX_QUESTION_TYPE] = { Question::questionCarType,  Question::questionEngine , Question::questionBreakSystem , Question::questionSteeringSytem , Question::runTest };

    CarBuilder builder;
    while (true)
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
        if (builder.isNumber(checkNumber) == false) {
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
        if (builder.checkAnsner(step, answer) == false) {
            continue;
        }
        switch (step) {
            case CarType_Q:
                builder.setCarType(static_cast<CarType>(answer));
                delay_ms(800);
                step++;
                break;
            case Engine_Q:
                builder.setEngine(static_cast<Engine>(answer));
                delay_ms(800);
                step++;
                break;
            case brakeSystem_Q:
                builder.setBrakeSystem(static_cast<BrakeSystem>(answer));
                delay_ms(800);
                step++;
                break;
            case SteeringSystem_Q:
                builder.setSteeringSystem(static_cast<SteeringSystem>(answer));
                delay_ms(800);
                step++;
                break;
            case Run_Test:
                {
                    auto car = builder.build();
                    if (answer == static_cast<int>(DriveType::DRIVE_TYPE_RUN)) {
                        car->run();
                        delay_ms(2000);
                    } else if (answer == static_cast<int>(DriveType::DRIVE_TYPE_TEST)) {
                        cout << "Test..." << endl;
                        delay_ms(1500);
                        car->test();
                        delay_ms(2000);
                    } else {
                        cout << "ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�" << endl;
                        delay_ms(800);
                        continue;
                    }
                }
                break;
            default:
                break;
        }
    }
}

#endif