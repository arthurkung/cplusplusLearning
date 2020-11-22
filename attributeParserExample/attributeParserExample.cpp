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
bool newTagDetected(const std::string& input) {
    if (input[1] == '/')
        return false;
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tagLines{};
    int queryLines{};
    cin >> tagLines >> queryLines;
    cin.ignore();
    Tag adamTag;
    Tag* currentTag{ &adamTag };
    std::string inputStr{};
    for (int i{}; i < tagLines; ++i)
    {
        getline(cin, inputStr);
        if (newTagDetected(inputStr)) {
            currentTag = currentTag->addChildTag();
            currentTag->setTagName(inputStr);
            currentTag->setAttributes();

        }
        else {
            currentTag = currentTag->getParentTag();
        }
    }
    
    std::cout << adamTag.m_children[0].m_name;


    return 0;
}