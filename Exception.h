#pragma once
#include <exception>
class MatchLoginExc : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "������: ������������ � ����� ������� ��� ����������";
    }
};

//������ �����������. ������������ ���� ������������ ����� ��� ������.
class BadAutorisationExc : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "������: ������������ ��� ������������ ��� ������";
    }
};

//������ �������� ���������
class NoMatchLoginExc : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "������: ������������ � ����� ������ �� ����������";
    }
};