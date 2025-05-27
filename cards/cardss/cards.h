#pragma once
#include <iostream>

class Card
{
public:
    virtual void show() const = 0; // Чисто виртуальная функция
    virtual bool checkAnswer() const = 0;
    virtual ~Card() {} // Всегда нужен виртуальный деструктор
};