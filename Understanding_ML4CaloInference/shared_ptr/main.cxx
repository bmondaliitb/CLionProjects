#include <iostream>
#include <memory>

class Config {
public:
    void print() { std::cout << "Shared config accessed.\n"; }
};

void useConfig(std::shared_ptr<Config> cfg) {
    cfg->print();
}

class Logger {
public:
    void log(std::string text) {
        std::cout<<" Log: "<<text<<std::endl;
    }
};

void logCount(std::shared_ptr<Logger> log){
    log->log(std::to_string(log.use_count()));
}


int main() {
    std::shared_ptr<Config> cfgPtr = std::make_shared<Config>();
    
    useConfig(cfgPtr);  // shared ownership

    std::cout << "Use count: " << cfgPtr.use_count() << std::endl;

    std::shared_ptr<Logger> loggerPtr = std::make_shared<Logger>();
    logCount(loggerPtr);

    return 0;
}

