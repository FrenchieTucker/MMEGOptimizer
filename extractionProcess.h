#include <QtCore/QProcess>
#include <QtCore/QString>

QString extractInfos(QString fileName)
{
    QProcess test;
    test.start("C:\\Program Files\\7-Zip\\7z.exe", QStringList{});
    while(!test.waitForFinished()) ;
    if(test.exitCode() != 0)
        throw;

    QProcess extraction(nullptr);
    extraction.start("C:\\Program Files\\7-Zip\\7z.exe", {"x", "-so", fileName});

    while(!extraction.waitForFinished()) ;

    return extraction.readAllStandardOutput();
}
