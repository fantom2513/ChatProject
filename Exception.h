#pragma once
#include <exception>
class MatchLoginExc : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Ошибка: пользователь с таким логином уже существует";
    }
};

//Ошибка авторизации. Пользователь ввел неправильный логин или пароль.
class BadAutorisationExc : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Ошибка: неправильное имя пользователя или пароль";
    }
};

//Ошибка отправки сообщения
class NoMatchLoginExc : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Ошибка: пользователя с таким именем не существует";
    }
};