#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseConnect {
public:
    virtual bool login(string username, string password) {
        return true;
    }
    virtual bool logout(string username) {
        return true;
    }
    virtual int fetchRecord() {
        return -1;
    }
};

class MockDB : public DataBaseConnect {
public:
    MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD1(logout, bool (string));
    MOCK_METHOD2(login, bool(string, string));

};

class MyDatabase {
public:
    MyDatabase(DataBaseConnect &_dbc) : dbc(_dbc) {}

    int init(string username, string password) {
        if (dbc.login(username, password) != true) {
            cout << "DB FAILURE" << endl;
            return -1;
        } else {
            cout << "DB SUCESS" << endl;
            return 1;
        }
    }

private:
    DataBaseConnect &dbc;

};


TEST(MyDBTest, LoginTest) {
    // Arragnge
    MockDB mockDB;
    MyDatabase myDatabse(mockDB);
    string username = "Tung";
    string password = "123456";

    EXPECT_CALL(mockDB, login(username, password)).Times(1).WillOnce(Return(true));

    // Act
    int value = myDatabse.init(username, password);

    // Assert
    EXPECT_EQ(1, value);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}