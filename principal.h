#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

public slots:
    void cent2fahr(int i);
    void cent2kel(int i);
    void fahr2cent(int i);

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
