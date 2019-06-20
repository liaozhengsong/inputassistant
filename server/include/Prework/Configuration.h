#pragma once
#include <string>
#include <map>
using std::string;
using std::map;
class Configuration
{
public:
    Configuration(const string& filepath);
    ~Configuration() {}
    map<string,string> &getConfigMap();
private:
    string _filepath;
    map<string,string> _configMap;
};

