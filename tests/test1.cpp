#include <QTest>

class TestCase1: public QObject
{
    Q_OBJECT
private slots:
    void success()
    {
        QVERIFY(1 == 1);
    }

    void failure()
    {
        QVERIFY(1 == 2);
    }
};

QTEST_MAIN(TestCase1)

#include "test1.moc"
