#pragma once
#include "SplitTool.h"
#include "Configuration.h"
class SplitToolNLPIR: public SplitTool
{
public:
    SplitToolNLPIR();
    virtual ~SplitToolNLPIR() {}
    virtual vector<string> cut(const string &sentence) = 0;
private:
    Configuration &_conf;
};

