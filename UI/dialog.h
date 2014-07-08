#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTableWidgetItem>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void ok();
    void cancel();

	void attrChange(QTableWidgetItem *item);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
