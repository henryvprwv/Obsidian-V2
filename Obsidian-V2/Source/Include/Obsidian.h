#pragma once

#include "Obsidian Key.h"
#include "Obsidian String.h"
#include "Obsidian Numbers.h"

#define OBSIDIAN_KEY TimeKey(__TIME__)
#define OBSIDIAN_SEED GenerateSeed(__TIME__)

#define OBSIDIAN_CPT_STRING(str) ([]() { \
    constexpr auto Encrypted = EncryptCPTString(str, OBSIDIAN_KEY); \
    return Encrypted; \
}())

#define OBSIDIAN_PRINT_ENCRYPTED_STR(str) std::cout << DecryptString(str, OBSIDIAN_KEY) << "\n";

#define OBSIDIAN_TIME_CHAR (__TIME__[1] - '0')

#define OBSIDIAN_CPT_NUMBER(number) EncryptNumber(number, OBSIDIAN_SEED, OBSIDIAN_TIME_CHAR)

#define OBSIDIAN_DECRYPT_NUMBER(number) DecryptNumber(number, OBSIDIAN_SEED, OBSIDIAN_TIME_CHAR)

#define OBSIDIAN_PRINT_ENCRYPTED_NUMBER(number) std::cout << OBSIDIAN_DECRYPT_NUMBER(number) << "\n";