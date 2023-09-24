#include <gtest/gtest.h>
#include "PayloadToJsonSerializer.hpp"
#include <iostream>


namespace KingsHeart
{
    class PayloadToJsonSerializerTest : public testing::Test
    {
    public:
        std::string _str{R"({"messages":{"message":"Hello World"},"metaData":{"Keep-Alive":"true"}})"};
        Payload _payload = PayloadBuilder{}.add_meta_datum("Keep-Alive", MetaDatum("true"))
                                           .add_message("message", Message("Hello World"))
                                           .build();
    };

    TEST_F(PayloadToJsonSerializerTest, Serialize)
    { EXPECT_TRUE(PayloadToJsonSerializer{}.serialize(_payload) == _str); }

    TEST_F(PayloadToJsonSerializerTest, DeSerialize)
    { EXPECT_TRUE(PayloadToJsonSerializer{}.deserialize(_str) == _payload); }
}