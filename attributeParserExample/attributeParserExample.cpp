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
        return m_string[1] != '/';
    }
    std::string getTagName() {
        return m_string;
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
    void setTagName(std::string input) {
        m_name = input;
    }
    void setAttributes() {
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
            currentTag->setAttributes();

        }
        else {
            currentTag = currentTag->getParentTag();
        }
    }
    
    std::cout << adamTag.m_children[0].m_name;


    return 0;
}