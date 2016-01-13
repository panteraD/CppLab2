#include <stddef.h>
#include <mingw32/bits/c++config.h>
#include <stdexcept>
#include "String.h"


void copyString(const char *str);

void clean();


String::String() {
    length = 1; ///???? should be 0?
    string = (char) 0;
}

String::String(const char *str) {
    while (*(str++) != '\0') {
        length++;
    }
    char *strCopy = new char[length + 1];
    for (std::size_t i = 0; i < length; i++) {
        strCopy[i] = str[i];
    }

}

//cut from beginning
String::String(const char *str, unsigned count) {
    string = new char[count + 1];
    length = count;
    for (std::size_t i = 0; i <= length; i++) {
        string[i] = str[i];
    }
}

//repeat symbol count times
String::String(char ch, unsigned count) {
    length = count + 1;
    string = new char[length];

    for (std::size_t i; i < length - 1; i++) {
        string[i] = ch;
    }
    string[length - 1] = (char) 0;
}

String::String(const String &other) {
    string = new char[other.length];
    length = other.length;
    for (size_t i = 0; i < length; i++) {
        string[i] = other.string[i];
    }
}


//nice example: http://stackoverflow.com/questions/3106110/what-are-move-semantics/3109981#3109981
String::String(String &&other) {
    string = other.string;
    length = other.length;
    other.string = nullptr;
    other.length = 0;
}


String::~String() {
    delete[] string;
}

String &String::operator=(const String &other) {
    delete[] string;
    string = new char[other.length + 1];
    length = other.length;
    for (size_t i = 0; i < length; i++) {
        string[i] = other.string[i];
    }
    return *this;
}

String &String::operator=(String &&other) {
    delete[] string;
    string = other.string;
    length = other.length;
    other.string = nullptr;
    other.length = 0;
    return *this;

}

String &String::operator+=(const String &suffix) {
    char *concat = new char[length + suffix.length + 1];
    for (size_t i = 0; i < length; ++i) {
        concat[i] = string[i];
    }
    for (size_t j = length; j < length + suffix.length; ++j) {
        concat[j] = suffix.string[j];
    }
    delete[] string;
    string = concat;
    length += suffix.length;

    return *this;
}

String &String::operator+=(const char *suffix) {
    size_t suffixLength = 0;
    while (*(suffix++) != '\0') {
        suffixLength++;
    }
    char *concat = new char[length + suffixLength + 1];
    for (size_t i = 0; i < length; ++i) {
        concat[i] = string[i];
    }
    for (size_t j = length; j < length + suffixLength; ++j) {
        concat[j] = suffix[j];
    }
    //set last symvot to char(0)??
    delete[] string;
    string = concat;
    length += suffixLength;
    return *this;
}

String &String::operator+=(char suffix) {
    char *concat = new char[length + 2];
    for (size_t i = 0; i < length; ++i) {
        concat[i] = string[i];
    }
    concat[length] = suffix;
    concat[length + 1] = '\0';
    delete string;
    string = concat;
    length++;
    return *this;
}

void String::swap(String &other) {
    char *tmp;
    size_t tmpLength;
    tmp = string;
    tmpLength = length;
    string = other.string;
    length = other.length;
    other.string = tmp;
    other.length = tmpLength;
}

char &String::operator[](size_t pos) {
    return string[pos];
}

const char String::operator[](size_t pos) const {
    return string[pos];
}

char &String::at(size_t pos) {
    if (pos >= length || pos < 0) {
        throw std::out_of_range("");
    }
    return string[pos];
}

//this is the same
const char String::at(size_t pos) const {
    if (pos >= length || pos < 0) {
        throw std::out_of_range("");
    }
    return string[pos];
}

const char *String::data() const {
    return string;
}

size_t String::size() const {
    size_t currLength = 0;
    while (string[currLength++] != '\0') {
    }
    return currLength;
}

bool operator==(const String &lhs, const String &rhs) {
    if (lhs.length == rhs.length) {
        for (size_t i = 0; i < lhs.length; ++i) {
            if (lhs.string[i] != rhs.string[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator<(const String &lhs, const String &rhs) {
    size_t size;
    size = lhs.length <= rhs.length ? lhs.length : rhs.length;
    for (size_t i = 0; i < size; ++i) {
        if(lhs.string[i] <rhs.string[i]) {
            return true;
        } else if (lhs.string[i] > rhs.string[i]) {
            return false;
        }
    }
    return false;
}


String operator+(const String &lhs, const String &rhs) {
    return String(lhs) += rhs;
}

String operator+(const String &lhs, const char *rhs) {
    return String(lhs) += rhs;
}

String operator+(const char *lhs, const String &rhs) {
    return String(rhs) += lhs;
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}

bool operator<=(const String &lhs, const String &rhs) {
    return (lhs == rhs) || (lhs < rhs);
}

bool operator>(const String &lhs, const String &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
    return !(lhs < rhs);
}

std::ostream & operator << (std::ostream &stream, const String & A) {
    return stream << A.data();
}




























