//
// Created by javie on 28/08/2024.
//

#ifndef MODERNCPPTDD_SOUNDEX_H
#define MODERNCPPTDD_SOUNDEX_H

#include <string>


class Soundex{
public:
    std::string encode(const std::string& word)const{
        return zeroPad(head(word) + encodedDigits(word));
    }

private:
    static const size_t MaxCodeLength {4};

    std::string head(const std::string& word) const {
        return word.substr(0, 1);
    }

    std::string encodedDigits(const std::string& word) const{
        return word.length() > 1 ? encodedDigit() : "";
    }
    std::string encodedDigit() const{
        return "1";
    }

    std::string zeroPad(const std::string& word) const{
        auto zerosNeeded = MaxCodeLength - word.length();

        return word + std::string(zerosNeeded, '0');
    }
};

#endif //MODERNCPPTDD_SOUNDEX_H
