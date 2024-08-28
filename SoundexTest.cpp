#include <iostream>

class Soundex{
public:
    std::string encode(const std::string& word)const{
        return zeroPad(word);
    }

private:
    std::string zeroPad(const std::string& word) const{
        return word + "000";
    }
};


#include <gmock/gmock.h>
using namespace testing;

class SoundexEncoding:public testing::Test{
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

