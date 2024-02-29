using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <random>
string removeVowels(string word);
string removeConsonants(string word);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Установка кодовой страницы консоли для ввода
    setlocale(0, ""); // Установка локали для консоли

    int vibor;
    string word;
    cout << "Меню: 1.Слово выводится задом наперед, 2.Вывести слово без гласных, 3.Вывести слово без согласных, 4. Рандомно раскидывать буквы заданного слова, 5.Выход.";
    cout << "\nВыберите число:";
    cin >> vibor;
    cout << "Введите слово:";
    cin >> word;

    locale loc("ru_RU.UTF-8");

    while (vibor != 5)
    {
        switch (vibor)
        {
        case(1):

            reverse(word.begin(), word.end());
            cout << "Слово задом наперед: " << word << endl;
            break;

        case(2):

            word = removeVowels(word);
            cout << "Слово без гласных: " << word << endl;
            break;

        case(3):

            word = removeConsonants(word);
            cout << "Слово без согласных: " << word << endl;
            break;

        case (4):

            wstring wideWord(word.begin(), word.end());
            wstring shuffledWord = wideWord;
            default_random_engine rng{ random_device{}() };
            shuffle(shuffledWord.begin(), shuffledWord.end(), rng);
            wcout << L"Слово с перемешанными буквами: " << shuffledWord << endl;
            break;
        }
        cout << "Меню: 1.Слово выводится задом наперед, 2.Вывести слово без гласных, 3.Вывести слово без согласных, 4. Рандомно раскидывать буквы заданного слова, 5.Выход.";
        cout << "\nВыберите число:";
        cin >> vibor;
        cout << "Введите слово:";
        cin >> word;
    }
}

string removeVowels(string word)
{
    word.erase(remove_if(word.begin(), word.end(), [](char c) {
        return ("aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ");
        }), word.end());
    return word;
}
string removeConsonants(string word)
{
    word.erase(remove_if(word.begin(), word.end(), [](char c) {
        return ("бвгджзйклмнпрстфхцчшщьъБВГДЖЗЙКЛМНПРСТФХЦЧШЩЬЪbcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ");
        }), word.end());
    return word;
}
