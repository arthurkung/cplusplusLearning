#include <string>
#include <iostream>
#include "tagInput.h"

std::string& TagInput::trim(std::string& str, char charToTrim = ' ')
{
    std::string::size_type start{ str.find_first_not_of(charToTrim) };
    std::string::size_type end{ str.find_last_not_of(charToTrim) };
    str = str.substr(start, end - start + 1);
    return str;
}
std::string TagInput::getFirstPartOfString(const std::string::size_type matchLoc, const int startingPos = 0)
{
    std::string result{ m_string.substr(startingPos,  matchLoc - startingPos) };
    m_string.erase(0, matchLoc + 1);
    return result;
}
std::string TagInput::getStringUpToNext(const char charToMatch, const int startingPos = 0)
{
    std::string::size_type matchLoc{ m_string.find(charToMatch, startingPos) };
    if (matchLoc == m_string.npos)
    {
        return noMatchMsg;
    }
    return getFirstPartOfString(matchLoc, startingPos);
}
bool TagInput::isNewTag() {
    constexpr char tagClosureIdentifier = '/';
    return m_string[tagStartLoc] != tagClosureIdentifier;
}

std::string TagInput::getTagName(){
    constexpr char tagDelimiter = '|';
    return getStringUpToNext(tagDelimiter, tagStartLoc);
}
std::string TagInput::getNextAttributeValue() {
    constexpr char quotes = '"';
    getStringUpToNext(quotes);
    std::string attributeValue{ getStringUpToNext(quotes) };
    return trim(attributeValue);
}

std::string TagInput::getNextAttribute() {
    constexpr char eqSign = '=';
    std::string attribute{ getStringUpToNext(eqSign) };
    if (attribute == noMatchMsg)
    {
        return "No attributes found";
    }
    return trim(attribute);
}

std::string TagInput::getAttributeFromQuery() {
    constexpr char attributeDelimiter = '~';
    std::string tagPart{ getStringUpToNext(attributeDelimiter) };
    if (tagPart == noMatchMsg)
    {
        return "No attributes found";
    }
    std::string attribute{ m_string };
    m_string = tagPart;
    return attribute;
}
const std::string TagInput::noMatchMsg = "Error: char not matched!";


