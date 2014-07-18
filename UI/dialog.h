#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTableWidgetItem>
#include "../Classes/JsonX.h"

namespace Ui {
class Dialog;
}
class ListWidgetItem;

//属性设置对话框，用于设置操作JsonX对象的数据
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(JsonX *attr, QWidget *parent = 0);
    ~Dialog();

	//将设置的属性保存到目标
	void storeAttrToTarget();
	//显示目标的属性
	void showAttrFromTarget();

	void setAttrTarget(JsonX *attr)	{ m_attr = attr; }
private:
	//对话框设置属性的结构,由外界提供
	JsonX	*m_attr;

private slots:
    void ok();
    void cancel();

	void attrChange(QTableWidgetItem *item);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
