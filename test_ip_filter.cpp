#include "filter_lib.h"
#include "gtest/gtest.h"
#include <fstream>

class IpFixture : public ::testing::Test {
public:
    ~IpFixture() override {}

protected:
    virtual void SetUp()  {
        std::ifstream in("ip_filter.tsv");
        if (in.is_open()) {
            for (std::string line; std::getline(in, line);) {
                auto v = split(line, '\t');
                ip_pool.push_back(split(v.at(0), '.'));
            }
        } else {
            std::cout << "File open error";
        }
        in.close();
    }

    pool_ip ip_pool;
};

TEST_F(IpFixture, split) {
    EXPECT_EQ(true, "113" == ip_pool[0][0]);
    EXPECT_EQ(true, "129" == ip_pool[500][1]);
    EXPECT_EQ(true,  "82" == ip_pool[999][3]);
    EXPECT_EQ(true, true);
}

TEST_F(IpFixture, radixSort) {
    radixSort(ip_pool);
    EXPECT_EQ(true, "222"==ip_pool[0][0]);
    EXPECT_EQ(true, "169"==ip_pool[500][1]);
    EXPECT_EQ(true,   "8"==ip_pool[999][3]);
    EXPECT_EQ(true, true);

}
