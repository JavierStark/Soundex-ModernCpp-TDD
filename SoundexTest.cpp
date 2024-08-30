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
    ASSERT_THAT(sut.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics){
    ASSERT_THAT(sut.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits){
    ASSERT_THAT(sut.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters){
    ASSERT_THAT(sut.encode("Dcbld").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoreVowelLikeLetters){
    ASSERT_THAT(sut.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings){
    ASSERT_THAT(sut.encodedDigit('b'), Eq(sut.encodedDigit('f')));
    ASSERT_THAT(sut.encodedDigit('c'), Eq(sut.encodedDigit('g')));
    ASSERT_THAT(sut.encodedDigit('d'), Eq(sut.encodedDigit('t')));
    ASSERT_THAT(sut.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter){
    ASSERT_THAT(sut.encode("abcd"), StartsWith("A"));
}