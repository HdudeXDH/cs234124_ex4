//
// Created by User on 6/11/2022.
//

#ifndef CS234124_EX4_EXCEPTION_H
#define CS234124_EX4_EXCEPTION_H

class DeckFileNotFound : public std::logic_error{
public:
    DeckFileNotFound(): std::logic_error("Deck File Error: File not found"){}
};

class DeckFileFormatError : public std::logic_error{
public:
    DeckFileFormatError(int lineNum):
    std::logic_error(formatWhat(lineNum))
    {

    };
    std::string formatWhat(int lineNum) {
        std::string what = "Deck File Error: File format error in line " +std::to_string(lineNum); //todo: validate use
        return what;
    }
};
class DeckFileInvalidSize : public std::logic_error{
public:
    DeckFileInvalidSize(): std::logic_error("Deck File Error: Deck size is invalid"){}
};

#endif //CS234124_EX4_EXCEPTION_H
