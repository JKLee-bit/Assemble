#pragma once

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
    MAX_QUESTION_TYPE = 5
};

class Question {
public:
    static void questionCarType(void);
    static void questionEngine(void);
    static void questionBreakSystem(void);
    static void questionSteeringSytem(void);
    static void runTest(void);
};