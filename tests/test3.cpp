#include <QTest>

class TestCase3: public QObject
{
    Q_OBJECT
private slots:
    void success()
    {
        QVERIFY(1 == 1);
    }
};

QTEST_MAIN(TestCase3)

#include "test3.moc"
