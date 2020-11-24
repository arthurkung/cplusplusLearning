#ifndef TAGINPUT_H
#define TAGINPUT_H
#include <string>

class TagInput
{
public:
    bool isNewTag();

    std::string getTagName();

    std::string getNextAttributeValue();

    std::string getNextAttribute();

    void setupInput(std::istream& in) {
        getline(in, m_string);
    }
    std::string const getString() {
        return m_string;
    }
    std::string getAttributeFromQuery();
private:
    static const std::string noMatchMsg;
    static constexpr int tagStartLoc=1;
    std::string m_string;
    std::string& trim(std::string& str, char charToTrim);
    std::string getFirstPartOfString(const std::string::size_type matchLoc, const int startingPos);
    std::string getStringUpToNext(const char charToMatch, const int startingPos);
};

#endif
