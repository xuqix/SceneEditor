#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTableWidgetItem>

namespace Ui {
class Dialog;
}
class ListWidgetItem;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

	//将设置的属性保存到目标
	void storeAttrToTarget();

	void setTarget(ListWidgetItem *target) { m_target = target; }
private:
	//此对话框的服务目标
	ListWidgetItem *m_target;

private slots:
    void ok();
    void cancel();

	void attrChange(QTableWidgetItem *item);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
