#include "cards.h"

class ImageCard : public Card
{
private:
    std::string term;          // Термин
    std::string imagePath;     // Путь к изображению
    std::string correctAnswer; // Правильный ответ

public:
    ImageCard(std::string t, std::string imgPath, std::string ans);
    ImageCard() : term(""), imagePath(""), correctAnswer("") {}
    ~ImageCard() {}
    ImageCard &operator=(const ImageCard &other)
    {
        if (this != &other)
        {
            term = other.term;
            imagePath = other.imagePath;
            correctAnswer = other.correctAnswer;
        }
        return *this;
    }
    ImageCard(const ImageCard &other)
    {
        term = other.term;
        imagePath = other.imagePath;
        correctAnswer = other.correctAnswer;
    }

    void show() const override;
    bool checkAnswer() const override;
    const std::string &getTerm() const { return term; }
    const std::string &getImagePath() const { return imagePath; }
    const std::string &getCorrectAnswer() const { return correctAnswer; }
};