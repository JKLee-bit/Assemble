#include "gmock/gmock.h"
#include <sstream>
#include <iostream>
#include <chrono>
#include "assemble.h"
#include "question.h"

TEST(QUESTION, CARTYPE) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout을 리디렉션

    Question::questionCarType();  // 콘솔 출력

    std::cout.rdbuf(oldCout);  // cout 복원

    std::string output = buffer.str();

    EXPECT_NE(output.find("        ______________"), std::string::npos);
    EXPECT_NE(output.find("       /|            | "), std::string::npos);
    EXPECT_NE(output.find("  ____/_|_____________|____"), std::string::npos);
    EXPECT_NE(output.find(" |                      O  |"), std::string::npos);
    EXPECT_NE(output.find(" '-(@)----------------(@)--'"), std::string::npos);
    EXPECT_NE(output.find("==============================="), std::string::npos);
    EXPECT_NE(output.find("어떤 차량 타입을 선택할까요?"), std::string::npos);
    EXPECT_NE(output.find("1. Sedan"), std::string::npos);
    EXPECT_NE(output.find("2. SUV"), std::string::npos);
    EXPECT_NE(output.find("3. Truck"), std::string::npos);
}

TEST(QUESTION, ENGINE) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout을 리디렉션

    Question::questionEngine();  // 콘솔 출력

    std::cout.rdbuf(oldCout);  // cout 복원

    std::string output = buffer.str();

    EXPECT_NE(output.find("어떤 엔진을 탑재할까요?"), std::string::npos);
    EXPECT_NE(output.find("0. 뒤로가기"), std::string::npos);
    EXPECT_NE(output.find("1. GM"), std::string::npos);
    EXPECT_NE(output.find("2. TOYOTA"), std::string::npos);
    EXPECT_NE(output.find("3. WIA"), std::string::npos);
    EXPECT_NE(output.find("4. 고장난 엔진"), std::string::npos);
}

TEST(QUESTION, BREAKSYSTEM) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout을 리디렉션

    Question::questionBreakSystem();  // 콘솔 출력

    std::cout.rdbuf(oldCout);  // cout 복원

    std::string output = buffer.str();

    EXPECT_NE(output.find("어떤 제동장치를 선택할까요?"), std::string::npos);
    EXPECT_NE(output.find("0. 뒤로가기"), std::string::npos);
    EXPECT_NE(output.find("1. MANDO"), std::string::npos);
    EXPECT_NE(output.find("2. CONTINENTAL"), std::string::npos);
    EXPECT_NE(output.find("3. BOSCH"), std::string::npos);
}

TEST(QUESTION, STEERINGSYSTEM) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout을 리디렉션

    Question::questionSteeringSytem();  // 콘솔 출력

    std::cout.rdbuf(oldCout);  // cout 복원

    std::string output = buffer.str();

    EXPECT_NE(output.find("어떤 조향장치를 선택할까요?"), std::string::npos);
    EXPECT_NE(output.find("0. 뒤로가기"), std::string::npos);
    EXPECT_NE(output.find("1. BOSCH"), std::string::npos);
    EXPECT_NE(output.find("2. MOBIS"), std::string::npos);
}

TEST(QUESTION, RUNTEST) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // cout을 리디렉션

    Question::runTest();  // 콘솔 출력

    std::cout.rdbuf(oldCout);  // cout 복원

    std::string output = buffer.str();

    EXPECT_NE(output.find("멋진 차량이 완성되었습니다."), std::string::npos);
    EXPECT_NE(output.find("어떤 동작을 할까요?"), std::string::npos);
    EXPECT_NE(output.find("0. 처음 화면으로 돌아가기"), std::string::npos);
    EXPECT_NE(output.find("1. RUN"), std::string::npos);
    EXPECT_NE(output.find("2. Test"), std::string::npos);
}


TEST(ASSEMBLE, DELAY_MS) {
    using namespace std::chrono;
    auto start = steady_clock::now();
    delay_ms(10);
    auto end = steady_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    EXPECT_GE(duration, 5);   // 지연시간은 적어도 5ms 이상
    EXPECT_LE(duration, 30);  // 시스템 스케줄링을 감안해 약간의 범위를 허용
}

TEST(ASSEMBLE_CAR, RUN_OK) {
    Car car;
    car.carType = CarType::SEDAN;
    car.engine = Engine::GM;
    car.brakeSystem = BrakeSystem::MANDO;
    car.steeringSystem = SteeringSystem::BOSCH_S;

    // cout 리다이렉트
    std::streambuf* originalBuf = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    // Act
    car.run();

    // 원래대로 복원
    std::cout.rdbuf(originalBuf);

    // Assert
    std::string output = capture.str();
    EXPECT_NE(output.find("자동차가 동작됩니다."), std::string::npos);
    EXPECT_NE(output.find("Car Type : Sedan"), std::string::npos);
}

TEST(ASSEMBLE_CAR, RUN_BREAK_DOWN) {
    Car car;
    car.carType = CarType::SEDAN;
    car.engine = Engine::BREAK_DOWN;
    car.brakeSystem = BrakeSystem::MANDO;
    car.steeringSystem = SteeringSystem::BOSCH_S;

    // cout 리다이렉트
    std::streambuf* originalBuf = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    // Act
    car.run();

    // 원래대로 복원
    std::cout.rdbuf(originalBuf);

    // Assert
    std::string output = capture.str();
    EXPECT_NE(output.find("엔진이 고장나있습니다."), std::string::npos);
    EXPECT_NE(output.find("자동차가 움직이지 않습니다."), std::string::npos);
}

TEST(ASSEMBLE_CAR, RUN_CAR_NOT_WORKING) {
    Car car;
    car.carType = CarType::SEDAN;
    car.engine = Engine::BREAK_DOWN;
    car.brakeSystem = BrakeSystem::CONTINENTAL;
    car.steeringSystem = SteeringSystem::BOSCH_S;

    // cout 리다이렉트
    std::streambuf* originalBuf = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    // Act
    car.run();

    // 원래대로 복원
    std::cout.rdbuf(originalBuf);

    // Assert
    std::string output = capture.str();
    EXPECT_NE(output.find("자동차가 동작되지 않습니다"), std::string::npos);
}

TEST(ASSEMBLE_CAR, TEST) {
    Car car;
    car.carType = CarType::SEDAN;
    car.engine = Engine::TOYOTA;
    car.brakeSystem = BrakeSystem::MANDO;
    car.steeringSystem = SteeringSystem::BOSCH_S;

    // cout 리다이렉트
    std::streambuf* originalBuf = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    // Act
    car.test();

    // 원래대로 복원
    std::cout.rdbuf(originalBuf);

    // Assert
    std::string output = capture.str();
    EXPECT_NE(output.find("자동차 부품 조합 테스트 결과 : PASS"), std::string::npos);
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