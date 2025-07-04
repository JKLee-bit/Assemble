#include <iostream>
#include "question.h"

using namespace std;
#define CLEAR_SCREEN "\033[H\033[2J"

void Question::questionCarType(void) {
    printf(CLEAR_SCREEN);
    cout << "        ______________" << endl;
    cout << "       /|            | " << endl;
    cout << "  ____/_|_____________|____" << endl;
    cout << " |                      O  |" << endl;
    cout << " '-(@)----------------(@)--'" << endl;
    cout << "===============================" << endl;
    cout << "어떤 차량 타입을 선택할까요?" << endl;
    cout << "1. Sedan" << endl;
    cout << "2. SUV" << endl;
    cout << "3. Truck" << endl;
    return;
}

void Question::questionEngine(void) {
    printf(CLEAR_SCREEN);
    cout << "어떤 엔진을 탑재할까요?" << endl;
    cout << "0. 뒤로가기" << endl;
    cout << "1. GM" << endl;
    cout << "2. TOYOTA" << endl;
    cout << "3. WIA" << endl;
    cout << "4. 고장난 엔진" << endl;
    return;
}

void Question::questionBreakSystem(void) {
    printf(CLEAR_SCREEN);
    cout << "어떤 제동장치를 선택할까요?" << endl;
    cout << "0. 뒤로가기" << endl;
    cout << "1. MANDO" << endl;
    cout << "2. CONTINENTAL" << endl;
    cout << "3. BOSCH" << endl;
    return;
}

void Question::questionSteeringSytem(void) {
    printf(CLEAR_SCREEN);
    cout << "어떤 조향장치를 선택할까요?" << endl;
    cout << "0. 뒤로가기" << endl;
    cout << "1. BOSCH" << endl;
    cout << "2. MOBIS" << endl;
    return;
}

void Question::runTest(void) {
    printf(CLEAR_SCREEN);
    cout << "멋진 차량이 완성되었습니다." << endl;
    cout << "어떤 동작을 할까요?" << endl;
    cout << "0. 처음 화면으로 돌아가기" << endl;
    cout << "1. RUN" << endl;
    cout << "2. Test" << endl;
    return;
}