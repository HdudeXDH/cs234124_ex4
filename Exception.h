//
// Created by User on 6/11/2022.
//

#ifndef CS234124_EX4_EXCEPTION_H
#define CS234124_EX4_EXCEPTION_H

class DeckFileNotFound : public std::logic_error{
public:
    DeckFileNotFound(const std::string& what): std::logic_error(what){}
};
class DeckFileFormatError : public std::logic_error{
public:
    DeckFileFormatError(const std::string& what): std::logic_error(what){}
};
class DeckFileInvalidSize : public std::logic_error{
public:
    DeckFileInvalidSize(const std::string& what): std::logic_error(what){}
};

#endif //CS234124_EX4_EXCEPTION_H
