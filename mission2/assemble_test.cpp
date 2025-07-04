#include "gmock/gmock.h"
#include <sstream>
#include <iostream>
#include <chrono>
#include "assemble.h"
#include "question.h"

TEST(QUESTION, CARTYPE) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout�� ���𷺼�

    Question::questionCarType();  // �ܼ� ���

    std::cout.rdbuf(oldCout);  // cout ����

    std::string output = buffer.str();

    EXPECT_NE(output.find("        ______________"), std::string::npos);
    EXPECT_NE(output.find("       /|            | "), std::string::npos);
    EXPECT_NE(output.find("  ____/_|_____________|____"), std::string::npos);
    EXPECT_NE(output.find(" |                      O  |"), std::string::npos);
    EXPECT_NE(output.find(" '-(@)----------------(@)--'"), std::string::npos);
    EXPECT_NE(output.find("==============================="), std::string::npos);
    EXPECT_NE(output.find("� ���� Ÿ���� �����ұ��?"), std::string::npos);
    EXPECT_NE(output.find("1. Sedan"), std::string::npos);
    EXPECT_NE(output.find("2. SUV"), std::string::npos);
    EXPECT_NE(output.find("3. Truck"), std::string::npos);
}

TEST(QUESTION, ENGINE) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout�� ���𷺼�

    Question::questionEngine();  // �ܼ� ���

    std::cout.rdbuf(oldCout);  // cout ����

    std::string output = buffer.str();

    EXPECT_NE(output.find("� ������ ž���ұ��?"), std::string::npos);
    EXPECT_NE(output.find("0. �ڷΰ���"), std::string::npos);
    EXPECT_NE(output.find("1. GM"), std::string::npos);
    EXPECT_NE(output.find("2. TOYOTA"), std::string::npos);
    EXPECT_NE(output.find("3. WIA"), std::string::npos);
    EXPECT_NE(output.find("4. ���峭 ����"), std::string::npos);
}

TEST(QUESTION, BREAKSYSTEM) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout�� ���𷺼�

    Question::questionBreakSystem();  // �ܼ� ���

    std::cout.rdbuf(oldCout);  // cout ����

    std::string output = buffer.str();

    EXPECT_NE(output.find("� ������ġ�� �����ұ��?"), std::string::npos);
    EXPECT_NE(output.find("0. �ڷΰ���"), std::string::npos);
    EXPECT_NE(output.find("1. MANDO"), std::string::npos);
    EXPECT_NE(output.find("2. CONTINENTAL"), std::string::npos);
    EXPECT_NE(output.find("3. BOSCH"), std::string::npos);
}

TEST(QUESTION, STEERINGSYSTEM) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout�� ���𷺼�

    Question::questionSteeringSytem();  // �ܼ� ���

    std::cout.rdbuf(oldCout);  // cout ����

    std::string output = buffer.str();

    EXPECT_NE(output.find("� ������ġ�� �����ұ��?"), std::string::npos);
    EXPECT_NE(output.find("0. �ڷΰ���"), std::string::npos);
    EXPECT_NE(output.find("1. BOSCH"), std::string::npos);
    EXPECT_NE(output.find("2. MOBIS"), std::string::npos);
}

TEST(QUESTION, RUNTEST) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout�� ���𷺼�

    Question::runTest();  // �ܼ� ���

    std::cout.rdbuf(oldCout);  // cout ����

    std::string output = buffer.str();

    EXPECT_NE(output.find("���� ������ �ϼ��Ǿ����ϴ�."), std::string::npos);
    EXPECT_NE(output.find("� ������ �ұ��?"), std::string::npos);
    EXPECT_NE(output.find("0. ó�� ȭ������ ���ư���"), std::string::npos);
    EXPECT_NE(output.find("1. RUN"), std::string::npos);
    EXPECT_NE(output.find("2. Test"), std::string::npos);
}


TEST(ASSEMBLE, DELAY_MS) {
    using namespace std::chrono;
    auto start = steady_clock::now();
    delay_ms(10);
    auto end = steady_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    EXPECT_GE(duration, 5);   // �����ð��� ��� 5ms �̻�
    EXPECT_LE(duration, 30);  // �ý��� �����ٸ��� ������ �ణ�� ������ ���
}

TEST(ASSEMBLE_CAR, RUN_OK) {
    Car car;
    car.carType = CarType::SEDAN;
    car.engine = Engine::GM;
    car.brakeSystem = BrakeSystem::MANDO;
    car.steeringSystem = SteeringSystem::BOSCH_S;

    // cout �����̷�Ʈ
    std::streambuf* originalBuf = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    // Act
    car.run();

    // ������� ����
    std::cout.rdbuf(originalBuf);

    // Assert
    std::string output = capture.str();
    EXPECT_NE(output.find("�ڵ����� ���۵˴ϴ�."), std::string::npos);
    EXPECT_NE(output.find("Car Type : Sedan"), std::string::npos);
}

TEST(ASSEMBLE_CAR, RUN_BREAK_DOWN) {
    Car car;
    car.carType = CarType::SEDAN;
    car.engine = Engine::BREAK_DOWN;
    car.brakeSystem = BrakeSystem::MANDO;
    car.steeringSystem = SteeringSystem::BOSCH_S;

    // cout �����̷�Ʈ
    std::streambuf* originalBuf = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    // Act
    car.run();

    // ������� ����
    std::cout.rdbuf(originalBuf);

    // Assert
    std::string output = capture.str();
    EXPECT_NE(output.find("������ ���峪�ֽ��ϴ�."), std::string::npos);
    EXPECT_NE(output.find("�ڵ����� �������� �ʽ��ϴ�."), std::string::npos);
}

TEST(ASSEMBLE_CAR, RUN_CAR_NOT_WORKING) {
    Car car;
    car.carType = CarType::SEDAN;
    car.engine = Engine::BREAK_DOWN;
    car.brakeSystem = BrakeSystem::CONTINENTAL;
    car.steeringSystem = SteeringSystem::BOSCH_S;

    // cout �����̷�Ʈ
    std::streambuf* originalBuf = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    // Act
    car.run();

    // ������� ����
    std::cout.rdbuf(originalBuf);

    // Assert
    std::string output = capture.str();
    EXPECT_NE(output.find("�ڵ����� ���۵��� �ʽ��ϴ�"), std::string::npos);
}

TEST(ASSEMBLE_CAR, TEST) {
    Car car;
    car.carType = CarType::SEDAN;
    car.engine = Engine::TOYOTA;
    car.brakeSystem = BrakeSystem::MANDO;
    car.steeringSystem = SteeringSystem::BOSCH_S;

    // cout �����̷�Ʈ
    std::streambuf* originalBuf = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    // Act
    car.test();

    // ������� ����
    std::cout.rdbuf(originalBuf);

    // Assert
    std::string output = capture.str();
    EXPECT_NE(output.find("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS"), std::string::npos);
}

TEST(ASSEMBLE_CAR, ISVALID_CHECK_SEDAN_CONTINENTAL) {
    Car car;
    car.carType = SEDAN;
    car.brakeSystem = CONTINENTAL;

    bool ret = car.isValidCheck();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, ISVALID_CHECK_SUV_TOYOTA) {
    Car car;
    car.carType = SUV;
    car.engine = TOYOTA;

    bool ret = car.isValidCheck();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, ISVALID_CHECK_TRUCK_WIA) {
    Car car;
    car.carType = TRUCK;
    car.engine = WIA;

    bool ret = car.isValidCheck();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, ISVALID_CHECK_TRUCK_MANDO) {
    Car car;
    car.carType = TRUCK;
    car.brakeSystem = MANDO;

    bool ret = car.isValidCheck();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, ISVALID_CHECK_BOSCH_B_BOSCH_S) {
    Car car;
    car.brakeSystem = BOSCH_B;
    car.steeringSystem = MOBIS;

    bool ret = car.isValidCheck();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, ISVALID_CHECK_SUV_WIA) {
    Car car;
    car.carType = SUV;
    car.engine = WIA;

    bool ret = car.isValidCheck();
    EXPECT_EQ(true, ret);
}

TEST(ASSEMBLE_CAR, IS_VALID_CHECK_TEST_SEDAN_CONTINENTAL) {
    Car car;
    car.carType = SEDAN;
    car.brakeSystem = CONTINENTAL;

    bool ret = car.isValidCheckTest();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, IS_VALID_CHECK_TEST_SUV_TOYOTA) {
    Car car;
    car.carType = SUV;
    car.engine = TOYOTA;

    bool ret = car.isValidCheckTest();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, IS_VALID_CHECK_TEST_TRUCK_WIA) {
    Car car;
    car.carType = TRUCK;
    car.engine = WIA;

    bool ret = car.isValidCheckTest();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, IS_VALID_CHECK_TEST_TRUCK_MANDO) {
    Car car;
    car.carType = TRUCK;
    car.brakeSystem = MANDO;

    bool ret = car.isValidCheckTest();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, IS_VALID_CHECK_TEST_BOSCH_B_BOSCH_S) {
    Car car;
    car.brakeSystem = BOSCH_B;
    car.steeringSystem = MOBIS;

    bool ret = car.isValidCheckTest();
    EXPECT_EQ(false, ret);
}

TEST(ASSEMBLE_CAR, IS_VALID_CHECK_TEST_OK) {
    Car car;
    car.carType = SEDAN;
    car.engine = TOYOTA;

    bool ret = car.isValidCheckTest();
    EXPECT_EQ(true, ret);
}

TEST(ASSEMBLE_BUILD, SETCARTYPE) {
    CarBuilder builder;
    builder.setCarType(CarType::SEDAN);
    auto car = builder.setEngine(Engine::GM)
        .setBrakeSystem(BrakeSystem::MANDO)
        .setSteeringSystem(SteeringSystem::BOSCH_S)
        .build();

    ASSERT_EQ(car->carType, CarType::SEDAN);
}