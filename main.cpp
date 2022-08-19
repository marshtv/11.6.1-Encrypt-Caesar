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
            shiftCode = (int) str[i] + shift;
            if (shiftCode > 90)
                str[i] = '@' + (shiftCode) % 90;
            else
                str[i] = shiftCode;
        }
        else if (is_Lowercase(str[i]))
        {
            shiftCode = (int) str[i] + shift;
            if (shiftCode > 122)
                str[i] = '`' + (shiftCode) % 122;
            else
                str[i] = shiftCode;
        }
    }
    return str;
}

int main() {
    int shift;
    std::string text;
    std::cout << "Input text:\n";
    getline(std::cin, text);

    do
    {
        std::cout << "Input shift (1-25):\n";
        std::cin >> shift;
    } while (shift < 1 || shift > 25);

    std::cout << std::endl << encryptCaesar(text, shift) << std::endl;
}