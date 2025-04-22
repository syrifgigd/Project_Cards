#include "cards.h"

int main() {
    std::vector<Cards> cards;  // Хранилище карточек
    int choice;

    std::cout << "=== Программа 'Карточки для запоминания' ===" << std::endl;

    while (true) {
        std::cout << "\nВыберите действие:" << std::endl;
        std::cout << "1. Добавить карточку" << std::endl;
        std::cout << "2. Просмотреть все карточки" << std::endl;
        std::cout << "3. Пройти тестирование" << std::endl;
        std::cout << "4. Выйти из программы" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore();  // Очистка буфера после ввода числа

        switch (choice) {
            case 1:
                addCard(cards);
                break;
            case 2:
                viewCards(cards);
                break;
            case 3:
                testUser(cards);
                break;
            case 4:
                std::cout << "Спасибо за использование программы. До свидания!" << std::endl;
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }
}