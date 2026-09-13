#pragma once
#include <bit>

template <typename T>
using uint_for = std::conditional_t<sizeof(T) == 1, uint8_t,
                 std::conditional_t<sizeof(T) == 2, uint16_t,
                 std::conditional_t<sizeof(T) == 4, uint32_t,
                 uint64_t>>>;

template <typename T>
constexpr T EncryptNumber(T Input, int Seed, int TimeChar) {
    auto Bits = std::bit_cast<uint_for<T>>(Input);
    Bits ^= static_cast<uint_for<T>>(Seed) ^ static_cast<uint_for<T>>(TimeChar);
    return std::bit_cast<T>(Bits);
}

template <typename T>
T DecryptNumber(T Input, int Seed, int TimeChar) {
    auto Bits = std::bit_cast<uint_for<T>>(Input);
    Bits ^= static_cast<uint_for<T>>(Seed) ^ static_cast<uint_for<T>>(TimeChar);
    return std::bit_cast<T>(Bits);
}