#include "server.h"


class Config{
public:
    static Config* get(){
//        if(!config)
//            config = new Config();
        return config;
    }
    Server* server;
private:
    static Config* config;
    Config(){};
    Config& operator= (const Config&);
};
//Config* Config::config = nullptr;
