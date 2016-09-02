#include "cppgram/exceptions.h"

const char* cppgram::JsonParseError::what() const throw()
{
    return "Error while parsing JSON document";
}

const char* cppgram::NoHTTPOKResponse::what() const throw()
{
    return "HTTP Response status code is not 200/OK";
}

const char* cppgram::NotOkTelegramAPI::what() const throw()
{
    return "Telegram API's JSON says NOT OK!";
}

const char* cppgram::BgProcessOSNotSupported::what() const throw()
{
    return "Operating System's new background process implementation not supported";
}

const char* cppgram::BgProcessFailed::what() const throw()
{
    return "Error while creating new process";
}

const char* cppgram::MalformedJsonDocument::what() const throw()
{
    return "The fetched JSON document is malformed. Cannot continue, try again!";
}