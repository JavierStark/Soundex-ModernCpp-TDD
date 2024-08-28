//
// Created by javie on 28/08/2024.
//

#ifndef MODERNCPPTDD_SOUNDEX_H
#define MODERNCPPTDD_SOUNDEX_H

#include <gmock/gmock.h>
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

#endif //MODERNCPPTDD_SOUNDEX_H
