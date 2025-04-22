#include "cards.h"
#include <algorithm>
#include <iostream>

Cards::Cards(const char* t, const char* d) {
    strncpy(term, t, sizeof(term) - 1);
    term[sizeof(term) - 1] = '\0';  // Убедимся, что строка заканчивается нулевым символом
    strncpy(definition, d, sizeof(definition) - 1);
    definition[sizeof(definition) - 1] = '\0';
}

// Конструктор копирования
Cards::Cards(const Cards& other) {
    strncpy(term, other.term, sizeof(term));
    term[sizeof(term) - 1] = '\0';
    strncpy(definition, other.definition, sizeof(definition));
    definition[sizeof(definition) - 1] = '\0';
}
Cards& Cards::operator=(const Cards& other) {
    if (this != &other) {  // Защита от самоприсваивания
        strncpy(term, other.term, sizeof(term));
        term[sizeof(term) - 1] = '\0';
        strncpy(definition, other.definition, sizeof(definition));
        definition[sizeof(definition) - 1] = '\0';
    }
    return *this;
}
std::istream& operator>>(std::istream& is, Cards& card) {
    std::cout << "Введите термин: ";
    is.getline(card.term, sizeof(card.term));
    std::cout << "Введите определение: ";
    is.getline(card.definition, sizeof(card.definition));
    return is;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Cards& card) {
    os << "Термин: " << card.term << "\nОпределение: " << card.definition;
    return os;
}
Cards::~Cards() {}
const char* Cards::getDefinition() const {
    return definition;
}
const char* Cards::getTerm() const {
    return term;
}
void addCard(std::vector<Cards>& cards) {
    Cards newCard;
    std::cin >> newCard;  // Используем перегруженный оператор ввода
    cards.push_back(newCard);
    std::cout << "Карточка успешно добавлена!" << std::endl;
}
// Функция для просмотра всех карточек
void viewCards(const std::vector<Cards>& cards) {
    if (cards.empty()) {
        std::cout << "Список карточек пуст." << std::endl;
        return;
    }

    std::cout << "Список карточек:" << std::endl;
    for (size_t i = 0; i < cards.size(); ++i) {
        std::cout << i + 1 << ". " << cards[i] << std::endl;  // Используем перегруженный оператор вывода
    }
}
void testUser(const std::vector<Cards>& cards) {
    if (cards.empty()) {
        std::cout << "Нет карточек для тестирования." << std::endl;
        return;
    }

    std::cout << "Начинаем тестирование. Введите определения для терминов." << std::endl;

    // Создаем массив индексов и перемешиваем его
    std::vector<int> indices(cards.size());
    for (size_t i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }
    std::srand(static_cast<unsigned>(std::time(0)));
    std::random_shuffle(indices.begin(), indices.end());

    int correctAnswers = 0;

    for (size_t i = 0; i < indices.size(); ++i) {
        const Cards& currentCard = cards[indices[i]];  // Переименовано из card в currentCard
        std::cout << "Термин: " << currentCard.getTerm() << std::endl;

        char userAnswer[200];
        std::cout << "Ваш ответ: ";
        std::cin.getline(userAnswer, sizeof(userAnswer));

        if (strcmp(userAnswer, currentCard.getDefinition()) == 0) {
            std::cout << "Правильно!" << std::endl;
            ++correctAnswers;
        } else {
            std::cout << "Неправильно. Правильный ответ: " << currentCard.getDefinition() << std::endl;
        }
    }

    std::cout << "Тестирование завершено. Правильных ответов: " << correctAnswers << " из "
              << cards.size() << "." << std::endl;
}
