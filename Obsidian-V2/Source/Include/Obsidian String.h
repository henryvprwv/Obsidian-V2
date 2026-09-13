#pragma once
#include <array>
#include <cstdint>
#include <chrono>
#include <Windows.h>
#include <iostream>

template <std::size_t N>
constexpr std::array<char, N> EncryptCPTString(const char(&Input)[N], int Key) {
    std::array<char, N> Output{};
    for (std::size_t i = 0; i < N; ++i) {
        Output[i] = Input[i] ^ Key;
    }
    return Output;
}

template <std::size_t N>
std::string DecryptString(const std::array<char, N>& Input, int Key) {
    std::string Output = "";
    for (std::size_t i = 0; i < N - 1; ++i) { 
        Output += static_cast<char>(Input[i] ^ Key);
    }
    return Output;
}