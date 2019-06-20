#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "../../include/Prework/Configuration.h"
using namespace std;
Configuration::Configuration(const string& filepath)
:_filepath(filepath)
{
    ifstream ifs;
    cout << _filepath << endl;
    ifs.open(_filepath);
    string line;
    while(ifs.good())
    {   
        getline(ifs,line);
        string key;
        string value;
        stringstream iss(line);
        iss >> key;
        iss >> value;
        _configMap[key] = value;
    }
    ifs.close();
}
map<string,string>& Configuration::getConfigMap()
{
    return _configMap;
}
