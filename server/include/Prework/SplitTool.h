#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;
class SplitTool
{
public:
    SplitTool() {}
    virtual ~SplitTool() {}
    virtual vector<string> cut(const string& sentence)=0;
private:

};

