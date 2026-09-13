# Obsidian V2

A lightweight, header-only C++ library for compile-time string and number encryption. Obsidian obfuscates string literals and numeric values at compile time using a key derived from the build time (`__TIME__`), so plain-text secrets never appear in your binary.

---

## Features

- **Compile-time string encryption** — strings are XOR-encrypted before the binary is built
- **Compile-time number encryption** — integers and floats are bit-scrambled at compile time
- **Time-based key** — the encryption key is derived from `__TIME__`, so every build produces a different key
- **Header-only** — just drop the headers in and include them

---

## Requirements

- C++20 or later
- MSVC (uses `<Windows.h>` internally)

---

## How to Use in Your Project

1. Copy the `Source/Include/` folder into your project.
2. Include the main header:

```cpp
#include "Include/Obsidian.h"
```

3. Use the macros:

### Strings

```cpp
// Encrypt a string at compile time
constexpr auto encrypted = OBSIDIAN_CPT_STRING("my secret");

// Print the decrypted string to stdout
OBSIDIAN_PRINT_ENCRYPTED_STR(encrypted);

// Or decrypt it manually into a std::string
std::string plain = DecryptString(encrypted, OBSIDIAN_KEY);
```

### Numbers

```cpp
// Encrypt a number at compile time (works with int, float, etc.)
constexpr auto encrypted = OBSIDIAN_CPT_NUMBER(133.7f);

// Decrypt it back
float value = OBSIDIAN_DECRYPT_NUMBER(encrypted);

// Or print directly
OBSIDIAN_PRINT_ENCRYPTED_NUMBER(encrypted);
```

---

## Macros Reference

| Macro | Description |
|---|---|
| `OBSIDIAN_CPT_STRING(str)` | Encrypts a string literal at compile time |
| `OBSIDIAN_PRINT_ENCRYPTED_STR(str)` | Decrypts and prints a string to stdout |
| `OBSIDIAN_CPT_NUMBER(n)` | Encrypts a number at compile time |
| `OBSIDIAN_DECRYPT_NUMBER(n)` | Decrypts an encrypted number |
| `OBSIDIAN_PRINT_ENCRYPTED_NUMBER(n)` | Decrypts and prints a number to stdout |

---

## How It Works

- The encryption key is generated from the `__TIME__` macro (the build timestamp), turned into an integer.
- Strings are XOR-encrypted character by character against that key.
- Numbers are bit-cast to their underlying integer representation and XOR-ed with a seeded value derived from the same key.
- Decryption is the same XOR operation in reverse — simple and fast at runtime.

---

## License

This project has no license specified. All rights reserved by the author.
