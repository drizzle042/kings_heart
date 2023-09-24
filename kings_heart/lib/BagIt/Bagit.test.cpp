#include <gtest/gtest.h>
#include "Bagit.hpp"


namespace KingsHeart
{
    class MetaDatumTest : public testing::Test
    {
    public:
        MetaDatum _metaDatum{"application/json"};
    };

    TEST_F(MetaDatumTest, MetaDatumEquality)
    { EXPECT_TRUE(_metaDatum == MetaDatum{"application/json"}); }

    TEST_F(MetaDatumTest, ReadMetaDatum)
    { EXPECT_TRUE(_metaDatum.read() == "application/json"); }

    // #############################################

    class MessageTest : public testing::Test
    {
    public:
        Message _msg{"Hello World"};
    };

    TEST_F(MessageTest, MessageEquality)
    { EXPECT_TRUE(_msg == Message("Hello World")); }

    TEST_F(MessageTest, ReadMessage)
    { EXPECT_TRUE(_msg.read() == "Hello World"); }

    // #############################################

    class PayloadBuilderTest : public testing::Test
    {
    public:
        PayloadBuilder _payloadBuilder = PayloadBuilder{}.add_meta_datum("Content-Type", MetaDatum{"application/json"})
                                                         .add_message("message", Message{"Hello World"});
    };

    TEST_F(PayloadBuilderTest, RequiredMetaDatumPassed)
    {
        _payloadBuilder.add_required_meta_data({"Content-Type"});
        EXPECT_NO_THROW(_payloadBuilder.build());
    }

    TEST_F(PayloadBuilderTest, RequiredMetaDatumFailed)
    { 
        _payloadBuilder.add_required_meta_data({"Keep-Alive"});
        EXPECT_THROW(
            try {_payloadBuilder.build();}
            catch (const std::runtime_error& e)
            {
                EXPECT_TRUE(std::string(e.what()) == "Keep-Alive metaDatum is required");
                throw;
            }, std::runtime_error);
    }

    TEST_F(PayloadBuilderTest, RequiredMessagePassed)
    {
        _payloadBuilder.add_required_messages({"message"});
        EXPECT_NO_THROW(_payloadBuilder.build());
    }

    TEST_F(PayloadBuilderTest, RequiredMessageFailed)
    { 
        _payloadBuilder.add_required_messages({"ping"});
        EXPECT_THROW(
            try {_payloadBuilder.build();}
            catch (const std::runtime_error& e)
            {
                EXPECT_TRUE(std::string(e.what()) == "ping message is required");
                throw;
            }, std::runtime_error);
    }

    // #############################################

    class PayloadTest : public testing::Test
    {
    public:
        Payload _payload = PayloadBuilder{}.add_meta_datum("Content-Type", MetaDatum{"application/json"})
                                           .add_meta_datum("Keep-Alive", MetaDatum{"true"})
                                           .add_message("ping", Message{"status"})
                                           .add_message("message", Message{"Hello World"})
                                           .build();
    };

    TEST_F(PayloadTest, PayloadEquality)
    {
        Payload payload = PayloadBuilder{}.add_meta_datum("Content-Type", MetaDatum{"application/json"})
                                          .add_meta_datum("Keep-Alive", MetaDatum{"true"})
                                          .add_message("ping", Message{"status"})
                                          .add_message("message", Message{"Hello World"})
                                          .build();
        EXPECT_TRUE(_payload == payload);
    }

    TEST_F(PayloadTest, GetMetaDatum)
    { EXPECT_TRUE(*_payload.get_meta_datum("Content-Type") == MetaDatum{"application/json"}); }

    TEST_F(PayloadTest, GetNullMetaDatum)
    { EXPECT_TRUE(_payload.get_meta_datum("Cache-Policy") == nullptr); }

    TEST_F(PayloadTest, GetMetaData)
    {
        std::unordered_map<std::string, MetaDatum> _m{
            {"Content-Type", MetaDatum{"application/json"}},
            {"Keep-Alive", MetaDatum{"true"}}
        };
        EXPECT_TRUE(_payload.get_meta_data() == _m);
    }

    TEST_F(PayloadTest, GetMessage)
    { EXPECT_TRUE(*_payload.get_message("message") == Message{"Hello World"}); }

    TEST_F(PayloadTest, GetNullMessage)
    { EXPECT_TRUE(_payload.get_message("data") == nullptr); }

    TEST_F(PayloadTest, GetMessages)
    {
        std::unordered_map<std::string, Message> _m{
            {"ping", Message{"status"}},
            {"message", Message{"Hello World"}}
        };
        EXPECT_TRUE(_payload.get_messages() == _m);
    }
}