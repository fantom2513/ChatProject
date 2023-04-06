#pragma once
#include"User.h"
#include"ChatRoom.h"
#include"Message.h"
#include"Exeption.h"
#include<iostream>
#include<vector>
#include <memory>
#include <unordered_map>
class Chat
{
private:
    bool m_start{ true };
    bool m_authorisation{ false };
    std::string login;
    std::unordered_map <std::string, User> m_users;
    //Нужен ли будет в дальнейшем этот массив????
    //std::vector <Message> m_messages; 
    std::unique_ptr <User> m_current_user;

    void registration();
    void authorisation();
    void set_current_user(const User& autorised);
    void create_message();
    void show_users() const;
    void show_messages() const;
    void escape();

public:
    Chat();
    bool get_authorisation() const;
    bool is_chat_work() const;
    void show_start_menu();
    void show_user_menu();
    ~Chat();
};