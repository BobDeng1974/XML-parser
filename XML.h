#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <vector>

#define XML_EOF 0
#define XML_NODE 1
#define XML_VALUE 2

class XAttrib
{
public:
    std::string name;
    std::string value;

    XAttrib();
    XAttrib(const std::string& str);
    std::string toString() const;
};

class XNode
{
private:
    const XNode* _findNode(const char* node_name) const;

public:
    XNode* parent;

    std::string name;
    std::string value;
    std::vector<XAttrib> attributes;
    std::vector<XNode> children;

    XNode();
    void print() const; // print the string representation in the format: name: value ...attributes...
    const XNode* findNode(const char* name) const;
    const XAttrib* findAttribute(const char* name) const;
};

class XFILE
{
private:
    FILE* file; // the file being read

    int read(std::string& buffer);

public:
    XFILE(const char* str); // read the file into the node heirchy
    XNode* getRoot();
    ~XFILE();
};
