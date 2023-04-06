#pragma once
#include<string>

class User
{
public:

    //Создание пользователя с заданными параметрами
    User(const std::string& name, const std::string& new_password, const std::string& login)
        : username(name), login(login), password(new_password)
    {}

    //Возврат имени пользователя
    std::string get_name() const { return username; }

    //Изменением имени пользователя
    void set_name(const std::string& name)
    {
        username = name;
    }

    //Возврат логина пользователя
    std::string get_login() const { return login; }

    //Возврат пароля пользователя
    std::string get_password() const { return password; }

    //Изменение пароля пользователя
    void set_password(std::string new_password)
    {
        password = new_password;
    }

    ~User()
    {
        //delete[] m_password;
        //m_password = nullptr;
    }
private:
	std::string username;
	std::string login;
	std::string password;
};
