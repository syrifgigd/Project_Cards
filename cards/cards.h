#pragma once
#include <iostream>

class Cards {
        char term[100];
        char definition[150];

    public:
        const char* getTerm() const;
        const char* getDefinition() const;
        Cards() = default;
        Cards(const char* termInput, const char* definitionInput);
        Cards(const Cards& other);
        Cards& operator=(const Cards& other);
        ~Cards();
        friend std::istream& operator>>(std::istream& is, Cards& card);
        friend std::ostream& operator<<(std::ostream& os, const Cards& card);
};
void addCard(std::vector<Cards>& cards);
void viewCards(const std::vector<Cards>& cards);
void testUser(const std::vector<Cards>& cards);