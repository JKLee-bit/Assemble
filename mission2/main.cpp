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

        // 엔터 개행문자 제거
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("바이바이\n");
            break;
        }

        // 숫자로 된 대답인지 확인
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

        // 입력받은 문자가 숫자가 아니라면
        if (builder.isNumber(checkNumber) == false) {
            continue;
        }

        // 처음으로 돌아가기
        if (answer == 0 && step == Run_Test)
        {
            step = CarType_Q;
            continue;
        }

        // 이전으로 돌아가기
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
                        cout << "ERROR :: Run 또는 Test 중 하나를 선택 필요" << endl;
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