#pragma once
#include "core/WorldContext.hpp"

class Client
{
public:
    Client();
    ~Client();
    void run();

private:
    WorldContext m_ctx;
};
