#include <QTest>

class TestCase3: public QObject
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

QTEST_MAIN(TestCase3)

#include "test3.moc"
