
#include <iostream>
#include "ChatRoom.h"
#include <fstream>

typedef unsigned int uint;

int main()
{
    setlocale(LC_ALL, "");
    Chat chat;

    while (chat.is_chat_work())
    {
        chat.show_start_menu();
        if (chat.get_authorisation())
        {
            chat.show_user_menu();
        }
    }
    return 0;
}