#include <QTest>

class TestCase: public QObject
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

QTEST_MAIN(TestCase)

#include "test.moc"
