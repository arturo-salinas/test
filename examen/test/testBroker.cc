
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/Broker.h"
#include "../inc/BFX.h"
#include "../inc/CarrierFactory.h"

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
    Carrier *c1 = CarrierFactory::Create(10.1, 0);
    Broker broker(&bfx);
    EXPECT_CALL(bfx, setPvScalingFactor(_, 1, 1)).Times(Exactly(1));
    broker.add(*c1);
    CarrierFactory::Destroy(c1);
}

TEST(BrokerTest, SeveralCarriersWithNoBundling)
{
    MockBFX bfx;
    Carrier *c1 = CarrierFactory::Create(20, 0);
    Carrier *c2 = CarrierFactory::Create(30, 0);
    Carrier *c3 = CarrierFactory::Create(50, 0);
    Broker broker(&bfx);
    EXPECT_CALL(bfx, setPvScalingFactor(_, _, _)).Times(Exactly(1));
    broker.add(*c1);
    EXPECT_CALL(bfx, setPvScalingFactor(_, _, _)).Times(Exactly(2));
    broker.add(*c2);
    EXPECT_CALL(bfx, setPvScalingFactor(_, 1, 0.2)).Times(Exactly(1));
    EXPECT_CALL(bfx, setPvScalingFactor(_, 2, 0.3)).Times(Exactly(1));
    EXPECT_CALL(bfx, setPvScalingFactor(_, 3, 0.5)).Times(Exactly(1));
    broker.add(*c3);
    CarrierFactory::Destroy(c3);
    CarrierFactory::Destroy(c2);
    CarrierFactory::Destroy(c1);
}

TEST(BrokerTest, SeveralCarriersWithBundling)
{
    MockBFX bfx;
    Carrier *c1 = CarrierFactory::Create(20, 1);
    Carrier *c2 = CarrierFactory::Create(30, 1);
    Carrier *c3 = CarrierFactory::Create(50, 0);
    Broker broker(&bfx);
    EXPECT_CALL(bfx, setPvScalingFactor(_, _, _)).Times(Exactly(1));
    broker.add(*c1);
    EXPECT_CALL(bfx, setPvScalingFactor(_, _, _)).Times(Exactly(2));
    broker.add(*c2);
    EXPECT_CALL(bfx, setPvScalingFactor(_, 1, 0.4)).Times(Exactly(1));
    EXPECT_CALL(bfx, setPvScalingFactor(_, 2, 0.6)).Times(Exactly(1));
    EXPECT_CALL(bfx, setPvScalingFactor(_, 3, 1)).Times(Exactly(1));
    broker.add(*c3);
    CarrierFactory::Destroy(c3);
    CarrierFactory::Destroy(c2);
    CarrierFactory::Destroy(c1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}