
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/Broker.h"
#include "../inc/BFX.h"

using ::testing::_;
using ::testing::Exactly;

class BrokerTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

class MockBFX : public BFX
{
public:
    MOCK_METHOD(void, setPvScalingFactor, (std::string, int, double), (override));
};

TEST(BrokerTest, AddOneCarrierWithNoBundling)
{
    MockBFX bfx;
    Carrier c1(1, 10.1);
    Broker broker(&bfx);
    EXPECT_CALL(bfx, setPvScalingFactor(_, 1, 1)).Times(Exactly(1));
    broker.add(c1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}