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
        while ((attribute  = tagInput.getNextAttribute()) != tagInput.notFoundOutputMsg) {
            attributeValue = tagInput.getNextAttributeValue();
            //std::cout << "attribute: " << attribute << "; value: " << attributeValue << "\n";
            m_attributes.insert({ attribute,attributeValue });
        }
        
        return;
    }
    std::string getQueryResult(TagInput& tagInput) {
        std::string attribute{ tagInput.getAttributeFromQuery() };
        if (attribute == tagInput.notFoundOutputMsg)
        {
            return "Not Found!";
        }
        Tag* currentTag{ this };
        std::string tagName{ };
        while (tagInput.getString().length()) {
            tagName = tagInput.getNextTag();
            auto found{ std::find_if(currentTag->m_children.begin(), currentTag->m_children.end(), [&tagName](const Tag& tag)
                             {
                                return (tag.m_name == tagName);
                             }) 
            };

            if (found == currentTag->m_children.end())
            {
                return "Not Found!";
            }
            else
            {
                currentTag = &(*found);
            }
        }
        if (currentTag->m_attributes.find(attribute) == currentTag->m_attributes.end())
        {
            return "Not Found!";
        }
        return currentTag->m_attributes.find(attribute)->second;

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
    //queries
    for (int i{}; i < queryLines; ++i)
    {
        input.setupInput(std::cin);
        std::cout<<adamTag.getQueryResult(input)<<"\n";
    }


    return 0;
}