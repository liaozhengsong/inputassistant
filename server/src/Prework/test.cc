#include "../../include/Prework/Configuration.h"
#include "../../include/Prework/DictProducer.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
int main()
{
    Configuration conf("./conf/config.conf");
    string DictPath = conf.getConfigMap()["DictPath"];
    string LibDir = conf.getConfigMap()["LibDir"];
    string IndexPath = conf.getConfigMap()["IndexPath"];
    DictProducer d(LibDir);
    d.build_dict();
    d.store_dict(DictPath);
    d.store_index(IndexPath);
    return 0;
}

