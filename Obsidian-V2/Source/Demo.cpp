#include "Include/Obsidian.h"
#include <iostream>

int main()
{
    constexpr auto EncryptedStr = OBSIDIAN_CPT_STRING("Very secret!");

    std::cout << "[String]\n";
    std::cout << "  Encrypted : ";
    for (auto c : EncryptedStr)
        std::cout << static_cast<int>(c) << " ";
    std::cout << "\n";

    std::cout << "  Decrypted: ";
    OBSIDIAN_PRINT_ENCRYPTED_STR(EncryptedStr);

    OBSIDIAN_PRINT_ENCRYPTED_STR(OBSIDIAN_CPT_STRING("\n  Very secret string 2"));

    constexpr auto EncryptedNum = OBSIDIAN_CPT_NUMBER(133.7f);

    std::cout << "\n[Number]\n";
    std::cout << "  Encrypted: " << EncryptedNum << "\n";
    std::cout << "  Decrypted: " << OBSIDIAN_DECRYPT_NUMBER(EncryptedNum) << "\n";

    std::cin.get();
    return 0;
}
