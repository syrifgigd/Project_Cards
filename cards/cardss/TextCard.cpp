// TextCard.cpp
#include "TextCard.h"
#include <iostream>
#include <string>
#include <cctype>

// Удаляет начальные и конечные пробелы
std::string trim(const std::string &s)
{
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start))
    {
        ++start;
    }

    auto end = s.end();
    do
    {
        --end;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

// Конструктор по умолчанию
TextCard::TextCard() : term(""), definition("") {}

// Конструктор с параметрами
TextCard::TextCard(const std::string &t, const std::string &d) : term(t), definition(d) {}

TextCard::~TextCard() {}

// Метод показа карточки
void TextCard::show() const
{
    std::cout << "Термин: " << term << std::endl;
}

// Проверка ответа пользователя
bool TextCard::checkAnswer() const
{
    std::string answer;
    std::cout << "Введите определение для термина '" << term << "': ";
    std::getline(std::cin >> std::ws, answer); // >> std::ws уберёт начальные пробелы

    std::string expected = trim(definition);
    std::string user = trim(answer);

    std::cout << "Ожидалось: '" << expected << "'\n";
    std::cout << "Получено:   '" << user << "'\n";

    return strcasecmp(expected.c_str(), user.c_str()) == 0;
}

// Перегрузка оператора ввода
std::istream &operator>>(std::istream &is, TextCard &card)
{
    std::cout << "Введите термин: ";
    std::getline(is >> std::ws, card.term);

    std::cout << "Введите определение: ";
    std::getline(is >> std::ws, card.definition);

    return is;
}