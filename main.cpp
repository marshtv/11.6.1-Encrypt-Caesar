#include <iostream>

bool is_Uppercase(char symbol)
{
    if (symbol >= 'A' && symbol <= 'Z')
        return true;
    else
        return false;
}

bool is_Lowercase(char symbol)
{
    if (symbol >= 'a' && symbol <= 'z')
        return true;
    else
        return false;
}

std::string encryptCaesar(std::string str, int shift)
{
    int shiftCode;
    for (int i = 0; i < str.length(); i++)
    {
        if (is_Uppercase(str[i]))
        {
            shiftCode = ((int) (str[i] - 'A') + shift) % 26;
            str[i] = (char) shiftCode + 'A';
        }
        else if (is_Lowercase(str[i]))
        {
            shiftCode = ((int) (str[i] - 'a') + shift) % 26;
            str[i] = (char) shiftCode + 'a';
        }
    }
    return str;
}

std::string decryptCaesar(std::string str, int shift)
{
    return encryptCaesar(str, 26 - shift % 26);
}

int main() {
    int shift;
    std::string text;
    std::cout << "Input text:\n";
    getline(std::cin, text);
    std::cout << "Input shift:\n";
    std::cin >> shift;

    std::cout << "\nEncrypted:\n"<< encryptCaesar(text, shift) << std::endl;
    std::cout << "\nDecrypted:\n"<< decryptCaesar(encryptCaesar(text, shift), shift) << std::endl;
}