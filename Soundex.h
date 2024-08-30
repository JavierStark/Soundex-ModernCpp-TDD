//
// Created by javie on 28/08/2024.
//

#ifndef MODERNCPPTDD_SOUNDEX_H
#define MODERNCPPTDD_SOUNDEX_H

#include <string>


class Soundex{
public:
    std::string encode(const std::string& word)const{

        return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
    }

    std::string encodedDigit(char letter) const {
        const std::unordered_map<char, std::string> encodings{
                {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
                {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                {'s', "2"}, {'x', "2"}, {'z', "2"},
                {'d', "3"}, {'t', "3"},
                {'l', "4"},
                {'m', "5"}, {'n', "5"},
                {'r', "6"}
        };
        auto it = encodings.find(lower(letter));

        return it == encodings.end() ? NotADigit : it->second;
    }

private:
    static const size_t MaxCodeLength {4};
    const std::string NotADigit{"*"};

    static std::string head(const std::string& word) {
        return word.substr(0, 1);
    }

    static std::string tail(const std::string& word) {
        return word.substr(1);
    }

    std::string lastDigit(std::string encoding) const {
        if(encoding.empty()) return NotADigit;
        return std::string(1, encoding.back());
    }

    std::string upperFront(const std::string& string) const{
        return std::string(1, std::toupper(static_cast<unsigned char>(string.front())));
    }

    char lower(char c) const{
        return std::tolower(static_cast<unsigned char>(c));
    }

    std::string encodedDigits(const std::string& word) const{
        std::string encoding;

        for(auto c : word) {
            if(isComplete(encoding)) break;

            auto digit = encodedDigit(c);

            if(digit != NotADigit && digit != lastDigit(encoding))
                encoding += encodedDigit(c);
        }

        return encoding;
    }

    static bool isComplete(const std::string &encoding) { return encoding.length() == MaxCodeLength - 1; }

    std::string zeroPad(const std::string& word) const{
        auto zerosNeeded = MaxCodeLength - word.length();

        return word + std::string(zerosNeeded, '0');
    }
};

#endif //MODERNCPPTDD_SOUNDEX_H
