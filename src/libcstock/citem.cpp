#include "citem.hpp"


citem::citem() : m_id(-1), m_name("UNKNOWN"), m_price(0)
{
}

citem::citem(const int& id, const std::string& name, const int& price) : m_id(id), m_name(name), m_price(price)
{
}

citem::~citem()
{
}

void citem::set_id(const int &id)
{
    m_id = id;
}

void citem::set_name(const std::string& name)
{
    m_name = name;
}

void citem::set_price(const int& price)
{
    m_price = price;
}

int citem::get_id()
{
    return m_id;
}

std::string& citem::get_name()
{
    return m_name;
}

int citem::get_price()
{
    return m_price;
}

std::ostream& operator<<(std::ostream& os, const citem& object)
{
    os << object.m_id << " " << object.m_name << "(" << object.m_price << ")";
    return os;
}

std::istream& operator>>(std::istream& is, citem& object)
{
    is >> object.m_id;
    is >> object.m_name;
    is >> object.m_price;
    return is;
}
