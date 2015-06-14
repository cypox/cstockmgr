#ifndef CSTOCK_HPP
#define CSTOCK_HPP

#include "citem.hpp"

#include <vector>


typedef std::vector<citem> stock_items;

class cstock {

public:
    explicit cstock();
    ~cstock();

    void show_stock();
    void buy(int);
    void sell(int);

    stock_items& get_items_in_stock();
    int get_quantity_of(int);

    bool load_from_file(const std::string&);

private:
    bool m_stock_loaded;
    int m_item_count;
    std::vector<citem> m_items_in_stock;
    std::vector<int> m_items_quantity;

};

#endif
