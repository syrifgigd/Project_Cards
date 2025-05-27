#include "cards.h"

class TextCard : public Card
{
private:
    std::string term;
    std::string definition;

public:
    TextCard();
    TextCard(const std::string &t, const std::string &d);
    ~TextCard();
    TextCard &operator=(const TextCard &other)
    {
        if (this != &other)
        {
            term = other.term;
            definition = other.definition;
        }
        return *this;
    }
    TextCard(const TextCard &other)
    {
        term = other.term;
        definition = other.definition;
    }
    void show() const override;
    bool checkAnswer() const override;

    // Геттеры
    const std::string &getTerm() const { return term; }
    const std::string &getDefinition() const { return definition; }

    friend std::istream &operator>>(std::istream &is, TextCard &card);
};