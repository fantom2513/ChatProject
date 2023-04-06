#include "ChatRoom.h"
#include <fstream>
#include<filesystem>
#include <algorithm>
#include <iomanip>

namespace fs = std::filesystem;

Chat::Chat()
{
    std::ifstream f_users("users.log");
    if (f_users.is_open())
    {
        while (!f_users.eof())
        {
            std::string user_login;
            std::string user_pass;
            std::string user_name;
            f_users >> user_login;
            if (user_login.empty())
                break;
            for (int i = 0; i < 5; ++i)
                f_users >> user_pass[i];
            f_users >> user_name;
            m_users.insert({ user_login, User(user_name, user_pass, user_login) });
        }
    }
    f_users.close();
}

bool Chat::get_authorisation() const
{
    return m_authorisation;
}

bool Chat::is_chat_work() const
{
    return m_start;
}

void Chat::show_start_menu()
{
    while (m_start && !m_authorisation)
    {
        std::cout << "�����������!\n" << "�������\n" << "l - ��� ����������� \n r - ��� ����������� \n"
            << "e - ��� ������ �� ���������" << std::endl;
        char key;
        std::cin >> key;
        switch (key)
        {   
        case 'l':
        {
            authorisation();//����� ������� ����������� ������������
            break;
        }
        case 'r':
        {
            registration();//����� �������� ����������� ������������
            break;
        }
        case 'e':
        {
            escape();//����� �� ���������
            break;
        }
        default:
            {
            std::cin.ignore(32767, '\n');
            break;
            }
        }
    }
}

void Chat::show_user_menu()
{
    while (m_authorisation)
    {
        std::cout << "w - ������� ��������� | l - �������� ������ �������������\n"
            << "m - �������� ��������� | e - ����� \n";
        char key;
        std::cin >> key;
        if (key == 'w')
        {
            create_message();
        }

        //����� ������� ��������� ���������
        else if (key == 'l')
        {
            show_users();
        }

        //����� ������� ��������� ���������
        else if (key == 'm')
        {
            show_messages();
        }

        //����� �� ����
        else if (key == 'e')
        {
            m_current_user = nullptr;
            m_authorisation = false;
        }

        //��������� ������ ��������� �������
        else
        {
            continue;
        }
    
    }
}


void Chat::registration()
{
    //�������� ������ ������
    std::string new_login;
    std::cout << "������� �����: ";
    std::cin >> new_login;

    //�������� ������������ ����� ������
    //�������� ������ �� �� ��� �� �� ����.
    if (new_login.empty())
    {
        std::cout << "�� �� ����� �����." << std::endl;
        return;
    }
    else
    {
        //�������� ������ �� ��� ������������.
        try
        {

            std::unordered_map<std::string, User>::iterator it = m_users.find(new_login);
            if (it != m_users.end())
            {
                //������ ������ �������� ��������� ���������� ������
                throw MatchLoginExc();
            }

        }
        catch (const std::exception& e)
        {
            //����� ��������� � ���, ��� ����� �� ��������
            std::cerr << e.what() << '\n';
            return;
        }
    }

    //�������� ������
    std::string new_password;
    std::cout << "���������� ������\n"
        << "������ �� ������ ��������� ������� � ������ �������� �� 8 ��������" << std::endl;
    std::cout << "������� ������: ";
    std::cin >> new_password;

    //�������� ����� ������
    if (new_password.empty() || new_password.length() < 8) {
        std::cout << "�� �� ����� ������." << std::endl;
        return;
    }
    else
    {
        //������������� ������
        std::string correct_password;
        std::cout << "����������� ������: \n";
        std::cin >> correct_password;

        //�������� ������������ ������������� ������
        if (new_password != correct_password) {
            std::cout << "������ �� ���������\n" << std::endl;
            return;
        }
    }

    //�������� ����� ������������
    std::string new_name;
    while (true)
    {
        std::cout << "���������� ��� ������������: ";
        std::cin >> new_name;
        if (new_name.empty())
            continue;
        else
            break;
    }

    //���������� ������ ������������ � ������ �������������
    m_users.insert({ new_login, User(new_name, new_password, new_login) });
}

void Chat::authorisation()
{
	std::cout << "������� �����\n";
	std::string user_login;
	std::cin >> user_login;
	if (user_login.empty()) {
		std::cout << "�� �� ����� �����\n";
		return;
	}
	std::cout << "������� ������\n";
	std::string user_password;
	std::cin >> user_password;
	if (user_password.empty()) {
		std::cout << "�� �� ����� ������\n";
		return;
	}
    try
    {
        //�������� ������������ ����� ������ � ������
        std::unordered_map<std::string, User>::iterator it = m_users.find(user_login);
        if (it != m_users.end())
        {
            if (user_login == it->second.get_login())
            {
                    if ((user_password) != (it->second.get_password()))
                        throw BadAutorisationExc();
                std::cout << "�����������, " << it->second.get_name() << std::endl;
                set_current_user(it->second);
                m_authorisation = true;
                return;
            }
        }
        //������ ������ �����������
        else
            throw BadAutorisationExc();
    }
    //����� ��������� �� ������ �����������
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Chat::set_current_user(const User& autorised)
{
    m_current_user = std::make_unique<User>(autorised);
}

void Chat::create_message()
{
    std::string address;
    bool match = false;
    do {
        std::cout << "������ ����� ������������, �������� ������ ��������� ���������\n "
            <<"��� ������� ALL ��� �������� ���� �������������\n";
        std::cin >> address;
    } while (address.empty());

    try {
        if (address != "ALL") {
            std::unordered_map<std::string, User>::iterator it = m_users.find(address);
            if (it != m_users.end()) {
                match = true;
            }
            else
                throw NoMatchLoginExc();//����� ������, ���� �������� � ����� ������� �� ����������
        }
    }
    catch (const std::exception& e){
        //����� ��������� � ���, ��� ������������ � ����� ������� �� ����������
        std::cerr << e.what() << '\n';
        return;
    }

    //���� ������ ��������� ��� ���������� ��������� ������
    if (address == "ALL" || match)
    {
        std::cout << "������� ����� ���������: ";
        std::string text;
        std::getline(std::cin, text);
        //m_messages.push_back(Message((*m_current_user).get_login(), address, text));
        std::ofstream f_messages("messages.log", std::ios::app);
        f_messages.seekp(0, std::ios::end);
        if (f_messages.tellp() == 0)
        {
            fs::permissions("messages.log", fs::perms::none);
            fs::permissions("messages.log", fs::perms::owner_read | fs::perms::owner_write);
        }
        f_messages << (*m_current_user).get_login() << " " << address << " " << text << std::endl;
    }
}

void Chat::show_users() const
{
    for (auto elem : m_users)
    {
        std::cout << "������������: " << elem.second.get_login() << "\t\t ���: " << elem.second.get_name();
        if ((*m_current_user).get_login() == elem.second.get_login())
            std::cout << " <- ��� ��";
        std::cout << std::endl;
    }
}

void Chat::show_messages() const
{
    std::ifstream f_message("messages.log");
    while (!f_message.eof())
    {
        std::string from, to, text;
        f_message >> from >> to;
        if (from.empty())
            break;
        std::getline(f_message, text);
        Message message(from, to, text);
        //�������� ������ ������� � ���������� � ���� ���� ��������� ����� ��� ���� ��������� � ����� ����
        if (message.get_to() == (*m_current_user).get_login() || message.get_to() == "ALL")
        {
            if (message.get_to() == (*m_current_user).get_login())
                std::cout << "������ ���������" << std::endl;
            else
                std::cout << "����� ���" << std::endl;
            std::cout << "��������� ��: " << message.get_from() << '\n' << '\n'
                << message.get_message() << '\n' << std::endl;
        }
    }
}

void Chat::escape()
{
    m_start = false;
}

Chat::~Chat()
{
    if (!m_users.empty())
    {
        std::ofstream f_users("users.log");
        f_users.seekp(0, std::ios::end);
        if (f_users.tellp() == 0)
        {
            fs::permissions("users.log", fs::perms::none);
            fs::permissions("users.log", fs::perms::owner_read | fs::perms::owner_write);
        }
        for (auto elem : m_users)
        {
            f_users << elem.second.get_login() << " ";
            for (int i = 0; i < 5; ++i)
                f_users << (elem.second.get_password()) << " ";
            f_users << elem.second.get_name() << std::endl;
            f_users << elem.second.get_password() << std::endl;
        }
    }
}