#include "cstock.hpp"

#include <boost/range/irange.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>


cstock::cstock() : m_item_count(0), m_stock_loaded(false)
{
}

cstock::~cstock()
{
}

bool cstock::load_from_file(const std::string& database_filename)
{
    boost::filesystem::path file_path(database_filename);

    if ( ! boost::filesystem::is_regular_file(file_path) )
    {
        std::cout << file_path << " is not a regular file." << std::endl;
        return false;
    }

    boost::filesystem::ifstream reader(file_path, std::ios::in);
    if ( !reader.is_open() )
    {
        std::cout << "file could not be opened." << std::endl;
        return false;
    }

    /* TODO : Check for bad file format. */

    reader >> m_item_count;

    for ( const int i : boost::irange(0, m_item_count) )
    {
        std::string name;
        int price;
        int quantity;
        reader >> name;
        reader >> price;
        reader >> quantity;
        m_items_in_stock.emplace_back(0, name, price);
        m_items_quantity.emplace_back(quantity);
    }

    reader.close();

    m_stock_loaded = true;
    return true;
}

stock_items& cstock::get_items_in_stock()
{
    return m_items_in_stock;
}

int cstock::get_quantity_of(int index)
{
    return m_items_quantity[index];
}

void cstock::show_stock()
{
    if ( !m_stock_loaded )
        return;

    for ( const int i : boost::irange(0, m_item_count) )
        std::cout << m_items_quantity[i] << " element of type " << m_items_quantity[i] << std::endl;
}

void cstock::buy(int index)
{
    if ( !m_stock_loaded )
        return;

    if ( m_item_count <= index )
        return;

    -- m_items_quantity[index];

    if ( m_items_quantity[index] == 0 )
    {
        m_items_in_stock.erase(m_items_in_stock.begin() + index);
        m_items_quantity.erase(m_items_quantity.begin() + index);
    }
}

void cstock::sell(int index)
{
    if ( !m_stock_loaded )
        return;

    if ( m_item_count <= index )
        return;

    ++ m_items_quantity[index];
}
