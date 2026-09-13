#pragma once

// __TIME__ is a string so the char values get subtraced by the char value of 0 which is 48 to get the actual number
// then skip index 2 and 5 cuz thats the :
constexpr int TimeKey(const char* t) 
{
    return (t[0] - '0') * 100000 + (t[1] - '0') * 10000
         + (t[3] - '0') * 1000   + (t[4] - '0') * 100
         + (t[6] - '0') * 10     + (t[7] - '0');
}

constexpr int GenerateSeed(const char* t)
{
    int Seed = TimeKey(t);
    Seed = (Seed ^ (Seed << 13)) ^ (Seed >> 7) ^ (Seed << 17);
    return Seed;
}