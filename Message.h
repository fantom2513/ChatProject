#pragma once
#include<string>
class Message
{
public:
    //�������� ��������� � ��������� �����������
    Message(const std::string& from, const std::string& to, const std::string& text)
        : m_from(from), m_to(to), m_text(text)
    {}

    //������� ������ ����������� ���������
    std::string get_from() const { return m_from; }

    //������� ������ ���������� ���������
    std::string get_to() const { return m_to; }

    //������� ������ ���������
    std::string get_message() const { return m_text; }

private:
    std::string m_to;
    std::string m_from;
    std::string m_text;
};