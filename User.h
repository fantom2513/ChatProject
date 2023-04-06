#pragma once
#include<string>

class User
{
public:

    //�������� ������������ � ��������� �����������
    User(const std::string& name, const std::string& new_password, const std::string& login)
        : username(name), login(login), password(new_password)
    {}

    //������� ����� ������������
    std::string get_name() const { return username; }

    //���������� ����� ������������
    void set_name(const std::string& name)
    {
        username = name;
    }

    //������� ������ ������������
    std::string get_login() const { return login; }

    //������� ������ ������������
    std::string get_password() const { return password; }

    //��������� ������ ������������
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
