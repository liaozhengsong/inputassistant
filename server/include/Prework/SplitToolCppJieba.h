#pragma once
#include "SplitTool.h"
#include "Configuration.h"
class SplitToolCppJieba
{
public:
    SplitToolCppJieba();
    virtual ~SplitToolCppJieba() {}
    virtual vector<string> cut(const string &sentence) = 0;
private:
    Configuration &_conf;
};

