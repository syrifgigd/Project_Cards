// menu.cpp
#include "menu.h"
#include "TextCard.h"
#include "ImageCard.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
#include "json.hpp" // Подключаем библиотеку JSON

using json = nlohmann::json;
void addTextCard(std::vector<Card *> &cards)
{
    Card *newCard = new TextCard();
    std::cin >> *static_cast<TextCard *>(newCard);
    cards.push_back(newCard);
    std::cout << "Карточка успешно добавлена!" << std::endl;
}

void addImageCard(std::vector<Card *> &cards)
{
    std::string term, imagePath, correctAnswer;

    std::cout << "Введите термин: ";
    std::getline(std::cin, term);

    std::cout << "Введите путь к изображению: ";
    std::getline(std::cin, imagePath);

    std::cout << "Введите правильный ответ: ";
    std::getline(std::cin, correctAnswer);

    cards.push_back(new ImageCard(term, imagePath, correctAnswer));
    std::cout << "Карточка с изображением добавлена!" << std::endl;
}
void deleteTextCard(std::vector<Card *> &cards)
{
    std::string delting;
    std::cout << "Введите элемент который хотите удалить:" << std::endl;
    std::getline(std::cin, delting);

    bool flag = false;
    for (auto it = cards.begin(); it != cards.end(); ++it)
    {
        TextCard *textCard = dynamic_cast<TextCard *>(*it);
        if (textCard && ((textCard->getTerm() == delting) || (textCard->getDefinition() == delting)))
        {
            delete *it;
            cards.erase(it);
            flag = true;
            std::cout << "Карточка " << delting << " была удалена" << std::endl;
            break;
        }
    }

    if (!flag)
    {
        std::cout << "Карточка с термином '" << delting << "' не найдена." << std::endl;
    }
}
void deleteImageCard(std::vector<Card *> &cards)
{
    std::string delting;
    std::cout << "Введите элемент который хотите удалить:" << std::endl;
    std::getline(std::cin, delting);

    bool flag = false;
    for (auto it = cards.begin(); it != cards.end(); ++it)
    {
        ImageCard *imageCard = dynamic_cast<ImageCard *>(*it);
        if (imageCard && ((imageCard->getTerm() == delting) || (imageCard->getCorrectAnswer() == delting)))
        {
            delete *it;
            cards.erase(it);
            flag = true;
            std::cout << "Карточка " << delting << " была удалена" << std::endl;
            break;
        }
    }

    if (!flag)
    {
        std::cout << "Карточка с термином '" << delting << "' не найдена." << std::endl;
    }
}
void viewCards(const std::vector<Card *> &cards)
{
    if (cards.empty())
    {
        std::cout << "Нет карточек для просмотра." << std::endl;
        return;
    }

    for (size_t i = 0; i < cards.size(); ++i)
    {
        std::cout << "Карточка " << i + 1 << ":" << std::endl;

        // Проверка на nullptr
        if (cards[i] == nullptr)
        {
            std::cout << "Недействительная карточка!" << std::endl;
            std::cout << "-------------------------" << std::endl;
            continue;
        }

        // Вызов метода show()
        cards[i]->show();
        std::cout << "-------------------------" << std::endl;
    }
}

void testUser(const std::vector<Card *> &cards)
{
    if (cards.empty())
    {
        std::cout << "Нет карточек для тестирования." << std::endl;
        return;
    }

    std::vector<int> indices(cards.size());
    for (size_t i = 0; i < indices.size(); ++i)
        indices[i] = i;

    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(indices.begin(), indices.end(), std::default_random_engine(seed));

    int correct = 0;
    for (int idx : indices)
    {
        std::cout << "Вопрос:" << std::endl;
        cards[idx]->show();

        if (cards[idx]->checkAnswer())
        {
            std::cout << "Правильно!" << std::endl;
            ++correct;
        }
        else
        {
            std::cout << "Неверно." << std::endl;
        }
    }

    std::cout << "Результат: " << correct << " из " << cards.size() << std::endl;
}
// Сохранение карточек в JSON-файл
void saveCardsToJson(const std::vector<Card *> &cards, const std::string &filename)
{
    json j;

    for (const auto &card : cards)
    {
        if (dynamic_cast<const TextCard *>(card))
        {
            const TextCard *textCard = dynamic_cast<const TextCard *>(card);
            j.push_back({{"type", "text"},
                         {"term", textCard->getTerm()},
                         {"definition", textCard->getDefinition()}});
        }
        else if (dynamic_cast<const ImageCard *>(card))
        {
            const ImageCard *imageCard = dynamic_cast<const ImageCard *>(card);
            j.push_back({{"type", "image"},
                         {"term", imageCard->getTerm()},
                         {"imagePath", imageCard->getImagePath()},
                         {"correctAnswer", imageCard->getCorrectAnswer()}});
        }
    }

    std::ofstream file(filename);
    if (file.is_open())
    {
        file << j.dump(4); // Форматируем JSON с отступами
        file.close();
        std::cout << "Карточки успешно сохранены в файл: " << filename << std::endl;
    }
    else
    {
        std::cerr << "Ошибка: Не удалось открыть файл для записи." << std::endl;
    }
}

// Загрузка карточек из JSON-файла
void loadCardsFromJson(std::vector<Card *> &cards, const std::string &filename)
{
    std::ifstream file(filename);
    if (!std::filesystem::exists(filename))
    {
        std::cerr << "Ошибка: Файл '" << filename << "' не существует." << std::endl;
        return;
    }

    if (!file.is_open())
    {
        std::cerr << "Ошибка: Не удалось открыть файл для чтения." << std::endl;
        return;
    }

    json j;
    file >> j;
    file.close();

    for (const auto &item : j)
    {
        std::string type = item["type"];
        if (type == "text")
        {
            std::string term = item["term"];
            std::string definition = item["definition"];
            cards.push_back(new TextCard(term, definition));
        }
        else if (type == "image")
        {
            std::string term = item["term"];
            std::string imagePath = item["imagePath"];
            std::string correctAnswer = item["correctAnswer"];
            cards.push_back(new ImageCard(term.c_str(), imagePath.c_str(), correctAnswer.c_str()));
        }
    }

    std::cout << "Карточки успешно загружены из файла: " << filename << std::endl;
}