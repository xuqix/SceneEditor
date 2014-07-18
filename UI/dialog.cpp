#include "dialog.h"
#include "ui_dialog.h"
#include "ListWidget.h"

Dialog::Dialog(JsonX *attr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ok()));
    connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(attrChange(QTableWidgetItem*)));

    ui->tableWidget->insertRow(0);

	setAttrTarget(attr);
	showAttrFromTarget();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ok()
{
	storeAttrToTarget();
    this->done(1);
}

void Dialog::cancel()
{
    this->done(0);
}

void Dialog::attrChange(QTableWidgetItem *item)
{
	//清除无效行
	int row = item->row();
	if (ui->tableWidget->item(row, 0)->text().isEmpty()) 
	{
		ui->tableWidget->removeRow(row);
		return;
	}
	if (item->column() != 0) return;
	//如果是最后一行则插入新行
	if ( (item->row() == (ui->tableWidget->rowCount() - 1)) && !item->text().isEmpty() )
		ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void Dialog::showAttrFromTarget()
{
	int row = 0;
	rapidjson::Document &doc = m_attr->getDocument();
	for (auto iter = doc.MemberonBegin(); iter != doc.MemberonEnd(); iter++)
	{
	    ui->tableWidget->insertRow(row);
		ui->tableWidget->setItem(row, 0, new QTableWidgetItem(iter->name.GetString()));
		ui->tableWidget->setItem(row, 1, new QTableWidgetItem(iter->value.GetString()));
		row++;
	}
}

void Dialog::storeAttrToTarget()
{
	//清理
	m_attr->clear();
	for (int i = 0; i < ui->tableWidget->rowCount(); i++)
	{
		QTableWidgetItem *item1 = ui->tableWidget->item(i, 0);
		QTableWidgetItem *item2 = ui->tableWidget->item(i, 1);
		if (!item1 || !item2) continue;

		QByteArray ba1 = item1->text().toLocal8Bit();//.toLatin1();
		QByteArray ba2 = item2->text().toLatin1();
		char *key = ba1.data();
		char *val = ba2.data();
		m_attr->insert(key, val);
	}
}
