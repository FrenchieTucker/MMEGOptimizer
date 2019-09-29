#ifndef DATA_DOWNLOADER_H
#define DATA_DOWNLOADER_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>

#include <QtNetwork/QNetworkAccessManager>

class DataDownloader : public QObject
{
    Q_OBJECT

    public:
        explicit DataDownloader(QUrl imageUrl);
        ~DataDownloader() = default;

        void fileDownloaded(QNetworkReply* pReply);
        QByteArray downloadedData() const;

    signals:
        void downloaded();

    private:
        QNetworkAccessManager m_WebCtrl;
        QByteArray m_DownloadedData;
};

#endif // DATA_DOWNLOADER_H
