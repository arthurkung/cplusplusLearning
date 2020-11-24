// https://www.hackerrank.com/challenges/attribute-parser/problem
//
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class TagInput
{
public:
    bool isNewTag() {
        constexpr char tagClosureIdentifier = '/';
        return m_string[tagStartLoc] != tagClosureIdentifier;
    }
    std::string getTagName() {
        constexpr char tagDelimiter = '|';
        return getStringUpToNext(tagDelimiter,tagStartLoc);
    }
    
    std::string getNextAttributeValue() {
        constexpr char quotes = '"';
        getStringUpToNext(quotes);
        std::string attributeValue{ getStringUpToNext(quotes) };
        return trim(attributeValue);
    }
    std::string getNextAttribute() {
        constexpr char eqSign = '=';
        std::string attribute{ getStringUpToNext(eqSign) };
        if (attribute == "Error: char not matched!")
        {
            return "No attributes found";
        }
        return trim(attribute);
    }
    void setupInput(std::istream& in) {
        getline(in, m_string);
    }
    void printString() {
        std::cout << m_string<<"\n";
    }
private:
    static constexpr int tagStartLoc = 1;
    std::string m_string;
    std::string& trim(std::string& str, char charToTrim=' ')
    {
        std::string::size_type start{ str.find_first_not_of(charToTrim) };
        std::string::size_type end{ str.find_last_not_of(charToTrim) };
        str = str.substr(start, end - start + 1);
        return str;
    }
    std::string getFirstPartOfString(const std::string::size_type matchLoc, const int startingPos = 0)
    {
        std::string result{ m_string.substr(startingPos,  matchLoc - startingPos) };
        m_string.erase(0, matchLoc+1);
        return result;
    }
    std::string getStringUpToNext(const char charToMatch, const int startingPos=0)
    {
        std::string::size_type matchLoc{ m_string.find(charToMatch, startingPos) };
        if (matchLoc == m_string.npos)
        {
            return "Error: char not matched!";
        }
        return getFirstPartOfString(matchLoc, startingPos);
    }
};


class Tag {
public:
    string m_name;
    std::vector<Tag> m_children;
    std::map<std::string, std::string> m_attributes;
    Tag* m_parent;

    void setParent(Tag* parent) {
        m_parent = parent;
    }

    Tag* addChildTag() {
        Tag* child = new Tag;
        child->setParent(this);
        m_children.push_back(*child);
        return &m_children.back();  

    }
    Tag* getParentTag() {
        return m_parent;
    }
    void setTagName(const std::string& inputStr) {
        m_name = inputStr;
    }
    void setAttributes(TagInput& tagInput) {
        std::string attribute{};
        std::string attributeValue{};
        while ((attribute  = tagInput.getNextAttribute()) != "No attributes found") {
            attributeValue = tagInput.getNextAttributeValue();
            std::cout << "attribute: " << attribute << "; value: " << attributeValue << "\n";
        }
        
        return;
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tagLines{};
    int queryLines{};
    cin >> tagLines >> queryLines;
    cin.ignore();
    Tag adamTag;
    Tag* currentTag{ &adamTag };
    TagInput input{};

    for (int i{}; i < tagLines; ++i)
    {
        input.setupInput(std::cin);
        if (input.isNewTag()) {
            currentTag = currentTag->addChildTag();
            currentTag->setTagName(input.getTagName());
            currentTag->setAttributes(input);

        }
        else {
            currentTag = currentTag->getParentTag();
        }
    }
    
    std::cout << adamTag.m_children[0].m_name;
    //std::string a{ "this is a string" };
    //std::string::size_type i{};
    //std::cout << ((i = a.find(' ')) != a.npos);
    //std::cout << a.find(' ', 6);
    //std::cout << ((i = a.find('x')) != a.npos);

    return 0;
}