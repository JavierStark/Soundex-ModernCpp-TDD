#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;

class SoundexEncoding : public Test{
public:
    Soundex sut;
};


TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord){
    auto encoded = sut.encode("A");

    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits){
    auto encoded = sut.encode("I");

    ASSERT_THAT(encoded, Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropiateDigits){
    EXPECT_THAT(sut.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics){
    ASSERT_THAT(sut.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, DISABLED_ReplacesMultipleConsonantsWithDigits){
    ASSERT_THAT(sut.encode("Acdl"), Eq("A234"));
}
