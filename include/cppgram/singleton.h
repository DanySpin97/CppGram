#ifndef CPPGRAM_SINGLETON_H
#define CPPGRAM_SINGLETON_H

#include <string>

#include "parameters.h"

namespace Json
{
class Reader;
class FastWriter;
class Value;
}

namespace cppgram 
{
    
class Singleton
{
public:
    Singleton(const Singleton& prev) = delete;
    ~Singleton();
    static Singleton* getInstance();
    std::string write(Json::Value& val);
    Json::Reader* getReader();
    Json::FastWriter* getWriter();
private:
    Singleton();
    static Singleton* instance;
    Json::Reader* reader;
    Json::FastWriter* writer;
    class InlineKeyboard* keyboards[THREADS];
};

}

#endif //CPPGRAM_SINGLETON_H