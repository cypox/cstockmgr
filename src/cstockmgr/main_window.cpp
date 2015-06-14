#include <main_window.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main_stock = new cstock();
    main_stock->load_from_file("stock.rawdb");
    ui->product_table->horizontalHeader()->setStretchLastSection(true);
    connect(ui->refresh_btn, SIGNAL(clicked(bool)), this, SLOT(update_product_view()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_product_view()
{
    ui->product_table->setRowCount(0);
    ui->product_table->setSortingEnabled(false);
    stock_items& item_list = main_stock->get_items_in_stock();
    int index(0), total(0);
    for ( stock_items::iterator it = item_list.begin() ; it != item_list.end() ; ++ it, ++ index )
    {
        int current_item_value = it->get_price() * main_stock->get_quantity_of(index);
        ui->product_table->insertRow(index);
        ui->product_table->setItem(index, 0, new QTableWidgetItem(QString("%1").arg(index)));
        ui->product_table->setItem(index, 1, new QTableWidgetItem(QString("%1").arg((*it).get_name().c_str())));
        ui->product_table->setItem(index, 2, new QTableWidgetItem(QString("%1").arg((*it).get_price())));
        ui->product_table->setItem(index, 3, new QTableWidgetItem(QString("%1").arg(main_stock->get_quantity_of(index))));
        ui->product_table->setItem(index, 4, new QTableWidgetItem(QString("%1").arg(current_item_value)));
        total += current_item_value;
    }
    ui->product_table->setSortingEnabled(true);
    ui->products_total->setText(QString(""
                                        "<html>"
                                        "<head/>"
                                        "<body>"
                                        "<p align=\"center\">"
                                        "<span style=\" font-size:24pt; font-weight:600; color:#000000;\">"
                                        "%1"
                                        "</span>"
                                        "</p>"
                                        "</body>"
                                        "</html>"
                                        ).arg(total));
}

int MainWindow::calculate_total_from_product_list()
{
    return 0;
}
