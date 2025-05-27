// main.cpp
#include "cardss/menu.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<Card *> cards; // Хранилище карточек
    int choice;

    std::cout << "=== Программа 'Карточки для запоминания' ===" << std::endl;

    while (true)
    {
        std::cout << "\nВыберите действие:" << std::endl;
        std::cout << "1. Добавить текстовую карточку\n";
        std::cout << "2. Добавить карточку с изображением\n";
        std::cout << "3. Удалить текстовую карточку\n";
        std::cout << "4. Удалить карточку с изображением\n";
        std::cout << "5. Просмотреть все карточки\n";
        std::cout << "6. Пройти тест\n";
        std::cout << "7. Сохранить карточки в файл\n";
        std::cout << "8. Загрузить карточки из файла\n";
        std::cout << "9. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера после ввода числа

        switch (choice)
        {
        case 1:
            addTextCard(cards);
            break;
        case 2:
            addImageCard(cards);
            break;
        case 3:
            deleteTextCard(cards);
            break;
        case 4:
            deleteImageCard(cards);
            break;
        case 5:
            viewCards(cards);
            break;
        case 6:
            testUser(cards);
            break;
        case 7:
        {
            std::string filename;
            std::cout << "Введите имя файла для сохранения (например, cards.json): ";
            std::getline(std::cin, filename);
            saveCardsToJson(cards, filename);
            break;
        }
        case 8:
        {
            std::string filename;
            std::cout << "Введите имя файла для загрузки (например, cards.json): ";
            std::getline(std::cin, filename);
            loadCardsFromJson(cards, filename);
            break;
        }
        case 9:
            std::cout << "Спасибо за использование программы. До свидания!" << std::endl;
            return 0;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }
}