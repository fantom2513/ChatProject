# ChatProject

## Описание работы программы
   Приложение представляет собой консоль, в которой реализован чат между несколькими пользователями. Сначала пользователь должен зарегистрироваться, придумав имя     пользователя, пароль и логин. Далее необходимо авторизоваться, после чего пользователь может отправлять сообщения как всем участникам чата, так и какому-то отдельному пользователю. также можно просматривать участников чата, просматривать сообщения и покинуть чат.
---
Описание состава программы:

    #class User
        Поля класса:
            name - имя пользователя;
            password - пароль пользвателя;
            login - логин пользователя;
        
        Методы класса:
            Конструктор;
            Геттеры;
            Сеттеры;
            Деструктор.

    #class Message
        Поля класса:
            m_from - имя отправителя;
            m_to - имя адресата;
            m_text. - текст сообщения

        Методы класса:
            Конструктор;
            Геттеры.

    #class Chat
        Поля класса:
            m_start - флаг-указатель работы чата;
            m_autorisation - флаг-указатель успешной авторизации пользователя;
            m_users - массив зарегистрированных пользователей;
            m_currrent_user - указатель на авторизовавшегося пользователя.

        Методы класса:
            get_autorisation - возврат флага-указателя успешной авторизации пользователя;
            is_chat_work - возврат флага-указателя работы чата;
            show_start_menu - стартовое меню чата;
            show_user_menu - меню авторизовавшегося пользователя;
            registration - функция регистрации нового пользователя;
            autorisation - функция авторизации пользователя;
            set_current_user - функция утсановки указателя на текущего пользователя в массиве пользователей;
            create_message - функция создания нового сообщения;
            show_users - функция отображения списка зарегистрированных пользователей;
            show_messages - функция отображения сообщений из чата;
            escape - функция изменения состояния флага-указателя работы чата;

Программа состоит из 5 файлов:
    Chat.cpp - основной алгоритм программы
    User.h - файл с описанием класса User
    Message.h - файл с описанием класса Message
    ChatRoom.h - заголовочный файл класса Chat, так же содержащий в себе описание использующихся в программе ошибок
    ChatRoom.cpp - файл с описанием класса Chat
    Exeption.h - обработка исключений

### Выполнил - Бруев Лев
