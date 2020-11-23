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
    std::string m_string;
    bool isNewTag() {
        constexpr char tagClosureIdentifier = '/';
        return m_string[tagStartLoc] != tagClosureIdentifier;
    }
    std::string getTagName() {
        constexpr char tagDelimiter = ' ';
        return getStringUpToNext(tagDelimiter,tagStartLoc, false);
    }
    std::string getStringUpToNext(const char charToMatch, const int startingPos, const bool includeChar)
    {
        return m_string.substr(startingPos, m_string.find(charToMatch, startingPos) - (includeChar ? 0 : 1));
    }
    

private:
    static constexpr int tagStartLoc = 1;
    std::string& trim(std::string& str, char charToTrim)
    {
        std::string::size_type start{ str.find_first_not_of(charToTrim) };
        std::string::size_type end{ str.find_last_not_of(charToTrim) };
        str = str.substr(start, end - start + 1);
        return str;
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
        getline(cin, input.m_string);
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


    return 0;
}