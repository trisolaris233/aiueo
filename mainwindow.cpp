#include "mainwindow.h"
#include "ui_mainwindow.h"

const QVector<QString> Symbol::vtrHiragana =
              {"あ", "い", "う", "え", "お",
               "か", "き", "く", "け", "こ",
               "さ", "し", "す", "せ", "そ",
               "た", "ち", "つ", "て", "と",
               "な", "に", "ぬ", "ね", "の",
               "は", "ひ", "ふ", "へ", "ほ",
               "ま", "み", "む", "め", "も",
               "や", "ゆ", "よ", "ら", "り",
               "る", "れ", "ろ", "わ", "を",
               "ん", "が", "ぎ", "ぐ", "げ",
               "ご", "ざ", "じ", "ず", "ぜ",
               "ぞ", "だ", "ぢ", "づ", "で",
               "ど", "ば", "び", "ぶ", "べ",
               "ぼ", "ぱ", "ぴ", "ぷ", "ぺ",
               "ぽ"};
const QVector<QString> Symbol::vtrKatakana =
              {"ア", "イ", "ウ", "エ", "オ",
               "カ", "キ", "ク", "ケ", "コ",
               "サ", "シ", "ス", "セ", "ソ",
               "タ", "チ", "ツ", "テ", "ト",
               "ナ", "ニ", "ヌ", "ネ", "ノ",
               "ハ", "ヒ", "フ", "ヘ", "ホ",
               "マ", "ミ", "ム", "メ", "モ",
               "ヤ", "ユ", "ヨ", "ラ", "リ",
               "ル", "レ", "ロ", "ワ", "ヲ",
               "ン", "ガ", "ギ", "グ", "ゲ",
               "ゴ", "ザ", "ジ", "ズ", "ゼ",
               "ゾ", "ダ", "ヂ", "ず", "デ",
               "ド", "バ", "ビ", "ブ", "ベ",
               "ボ", "パ", "ピ", "プ", "ぺ",
               "ポ"};
const QVector<QString> Symbol::vtrRomanSound =
                {"a","i","u","e","o",
                 "ka","ki","ku","ke","ko",
                 "sa","shi","su","se","so",
                 "ta","chi","tsu","te","to",
                 "na","ni","nu","ne","no",
                 "ha","hi","fu","he","ho",
                 "ma","mi","mu","me","mo",
                 "ya","yu","yo",
                 "ra","ri","ru","re","ro",
                 "wa","o","n",
                 "ga", "gi", "gu", "ge", "go",
                 "za", "ji", "zu", "ze", "zo",
                 "da", "ji", "zu", "de", "do",
                 "ba", "bi", "bu", "be", "bo",
                 "pa", "pi", "pu", "pe", "po"};

Symbol::Symbol() {}

Symbol::Symbol(const QString &hir, const QString &kat, const QString &roman) :
    strHiragana(hir), strKatakana(kat), strRomanSound(roman)
{

}

const QString &Symbol::getHiragana() const { return strHiragana; }

const QString &Symbol::getKatakana() const { return strKatakana; }

const QString &Symbol::getRomanSound() const { return strRomanSound; }

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化变量
    for(int i = 0; i < Symbol::vtrHiragana.size(); i++)
    {
        vtrSymbols.push_back(Symbol(Symbol::vtrHiragana[i], Symbol::vtrKatakana[i], Symbol::vtrRomanSound[i]));
    }

    // 初始化成员变量
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); // 初始化随机数种子
    Random();
    showSymbol();

    connect(ui->mainPushButton, SIGNAL(clicked(bool)), this, SLOT(showPrompt()));
    connect(ui->nextButton, SIGNAL(clicked(bool)), this, SLOT(next()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Random()
{
    curShowing = qrand() % 2;
    curSelected = vtrSymbols[qrand() % vtrSymbols.size()];
}

void MainWindow::showSymbol()
{
    ui->promptButton->setText(QString());
    ui->romanButton->setText(QString());
    ui->mainPushButton->setText(curShowing ? curSelected.getHiragana() : curSelected.getKatakana());
}

void MainWindow::showPrompt()
{
    ui->promptButton->setText(curShowing ? curSelected.getKatakana() : curSelected.getHiragana());
    ui->romanButton->setText(curSelected.getRomanSound());
}

void MainWindow::next()
{
    Random();
    showSymbol();
}

