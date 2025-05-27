#include "ImageCard.h"
#include <iostream>
#include <cctype> // для std::tolower
#include <string> // для std::string
#include <algorithm>

// Конструктор
ImageCard::ImageCard(std::string t, std::string imgPath, std::string ans)
    : term(t), imagePath(imgPath), correctAnswer(ans) {}

// Удаляет начальные и конечные пробелы
static std::string trim(const std::string &s)
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

// Сравнение без учёта регистра
static bool equalsIgnoreCase(const std::string &a, const std::string &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (std::tolower(a[i]) != std::tolower(b[i])) // std::tolower('A')='a'
        {
            return false;
        }
    }
    return true;
}

// Метод показа карточки
void ImageCard::show() const
{
    std::cout << "Изображение: [" << imagePath << "]" << std::endl;
    std::cout << "Термин: " << term << std::endl;
}

// Проверка ответа пользователя
bool ImageCard::checkAnswer() const
{
    std::string userAnswer;

    while (true)
    {
        std::cout << "Введите определение: ";

        // Очистка буфера перед вводом
        std::cin.clear();

        // Игнорируем только лишние символы, если они есть
        if (std::cin.peek() == '\n')
        {
            std::cin.ignore(); // Игнорируем только один символ новой строки
        }

        std::getline(std::cin, userAnswer);

        if (userAnswer.empty())
        {
            std::cout << "Ошибка! Ваш ответ пуст!" << std::endl;
            continue;
        }

        std::string expected = trim(correctAnswer);
        std::string userStr = trim(userAnswer);

        std::cout << "Ожидалось: '" << expected << "'\n";
        std::cout << "Получено:   '" << userStr << "'\n";

        if (equalsIgnoreCase(expected, userStr))
        {
            std::cout << "Правильно!\n";
            return true;
        }
        else
        {
            std::cout << "Неверно! Попробуйте еще раз.\n";
        }
    }
}
