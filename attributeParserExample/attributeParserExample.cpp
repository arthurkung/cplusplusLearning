// https://www.hackerrank.com/challenges/attribute-parser/problem
//
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "tagInput.h"
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
    std::string getQueryResult(TagInput& tagInput) {
        std::string attribute{};
        std::string tag{};
        tagInput.setupInput(std::cin);
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
    /*queries*/
    for (int i{}; i < queryLines; ++i)
    {
        input.setupInput(std::cin);
        
    }


    std::cout << adamTag.m_children[0].m_name;
    //std::string a{ "this is a string" };
    //std::string::size_type i{};
    //std::cout << ((i = a.find(' ')) != a.npos);
    //std::cout << a.find(' ', 6);
    //std::cout << ((i = a.find('x')) != a.npos);

    return 0;
}