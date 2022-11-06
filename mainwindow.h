#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTime>
#include <QColor>
#include <QVector>
#include <QString>
#include <QPalette>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Symbol
{
private:
    QString strHiragana;
    QString strKatakana;
    QString strRomanSound;
public:
    const static QVector<QString> vtrHiragana, // 平假名
                                  vtrKatakana, // 片假名
                                  vtrRomanSound; // 罗马音
    Symbol();
    Symbol(const QString &hir, const QString &kat, const QString &roman);

    const QString &getHiragana() const;
    const QString &getKatakana() const;
    const QString &getRomanSound() const;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<Symbol> vtrSymbols;
    Symbol          curSelected;
    int             curShowing;

    void Random(); // 随机抽取

private slots:
    void showSymbol(); // 显示已抽取的假名
    void showPrompt(); // 显示提示
    void next(); // 抽取并显示下一个
};

#endif // MAINWINDOW_H
