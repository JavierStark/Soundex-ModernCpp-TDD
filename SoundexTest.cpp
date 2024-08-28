#include <iostream>

class Soundex{
public:
    std::string encode(const std::string& word)const{
        return word + "000";
    }
};


#include <gmock/gmock.h>
using namespace testing;


TEST(SoundexEncoding, RetainSoleLetterOfOneLetterWord){
    Soundex sut;

    auto encoded = sut.encode("A");

    ASSERT_THAT(encoded, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits){
    Soundex sut;

    auto encoded = sut.encode("I");

    ASSERT_THAT(encoded, Eq("I000"));
}

