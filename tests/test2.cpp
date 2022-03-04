#include <QTest>

class TestCase2: public QObject
{
    Q_OBJECT
private slots:
    void success()
    {
        QVERIFY(1 == 1);
    }
};

QTEST_MAIN(TestCase2)

#include "test2.moc"
