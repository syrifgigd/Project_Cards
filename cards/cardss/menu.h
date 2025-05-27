// menu.h
#include "cards.h"
#include <vector>
#include <string>

void addTextCard(std::vector<Card *> &cards);
void addImageCard(std::vector<Card *> &cards);
void deleteTextCard(std::vector<Card *> &cards);
void deleteImageCard(std::vector<Card *> &cards);
void viewCards(const std::vector<Card *> &cards);
void testUser(const std::vector<Card *> &cards);

// Новые функции для работы с JSON
void saveCardsToJson(const std::vector<Card *> &cards, const std::string &filename);
void loadCardsFromJson(std::vector<Card *> &cards, const std::string &filename);