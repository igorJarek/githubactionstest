#include <QTest>

class TestCase1: public QObject
{
    Q_OBJECT
private slots:
    void success()
    {
        QString str = "Hello";
        QVERIFY(str.toUpper() == "HELLO");
    }

    void failure()
    {
        QVERIFY(1 == 2);
    }
};

QTEST_MAIN(TestCase1)

#include "test1.moc"
