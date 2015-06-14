#ifndef CITEM_HPP
#define CITEM_HPP

#include <string>

#include <iostream>


class citem {

public:
    citem();
    citem(const int&, const std::string&, const int&);
    ~citem();

    void set_id(const int&);
    void set_name(const std::string&);
    void set_price(const int&);

    int get_id();
    std::string& get_name();
    int get_price();

    friend std::ostream& operator<<(std::ostream&, const citem&);
    friend std::istream& operator>>(std::istream&, citem&);

private:
    int m_id;
    std::string m_name;
    int m_price;

};

#endif CITEM_HPP
