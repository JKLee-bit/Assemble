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
    cout << "� ���� Ÿ���� �����ұ��?" << endl;
    cout << "1. Sedan" << endl;
    cout << "2. SUV" << endl;
    cout << "3. Truck" << endl;
    return;
}

void Question::questionEngine(void) {
    printf(CLEAR_SCREEN);
    cout << "� ������ ž���ұ��?" << endl;
    cout << "0. �ڷΰ���" << endl;
    cout << "1. GM" << endl;
    cout << "2. TOYOTA" << endl;
    cout << "3. WIA" << endl;
    cout << "4. ���峭 ����" << endl;
    return;
}

void Question::questionBreakSystem(void) {
    printf(CLEAR_SCREEN);
    cout << "� ������ġ�� �����ұ��?" << endl;
    cout << "0. �ڷΰ���" << endl;
    cout << "1. MANDO" << endl;
    cout << "2. CONTINENTAL" << endl;
    cout << "3. BOSCH" << endl;
    return;
}

void Question::questionSteeringSytem(void) {
    printf(CLEAR_SCREEN);
    cout << "� ������ġ�� �����ұ��?" << endl;
    cout << "0. �ڷΰ���" << endl;
    cout << "1. BOSCH" << endl;
    cout << "2. MOBIS" << endl;
    return;
}

void Question::runTest(void) {
    printf(CLEAR_SCREEN);
    cout << "���� ������ �ϼ��Ǿ����ϴ�." << endl;
    cout << "� ������ �ұ��?" << endl;
    cout << "0. ó�� ȭ������ ���ư���" << endl;
    cout << "1. RUN" << endl;
    cout << "2. Test" << endl;
    return;
}