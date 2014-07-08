#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ok()));
    connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(attrChange(QTableWidgetItem*)));

    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("true"));
    qDebug("%s",ui->tableWidget->item(0,0)->text().toLatin1().data());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ok()
{
    this->done(1);
}

void Dialog::cancel()
{
    this->done(0);
}

void Dialog::attrChange(QTableWidgetItem *item)
{
	if (item->column() != 0) return;
	qDebug("change");
	//如果是最后一行则插入新行
	if ( (item->row() == (ui->tableWidget->rowCount() - 1)) && !item->text().isEmpty() )
		ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}
