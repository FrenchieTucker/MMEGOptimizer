#include "DataDownLoader.h"

#include <QtNetwork/QNetworkReply>
#include <QtCore/QUrl>

DataDownloader::DataDownloader(QUrl imageUrl)
    : QObject()
{
    connect(&m_WebCtrl, &QNetworkAccessManager::finished, this, &DataDownloader::fileDownloaded);
    QNetworkRequest request(imageUrl);
    m_WebCtrl.get(request);
}

void DataDownloader::fileDownloaded(QNetworkReply* pReply) {
    m_DownloadedData = pReply->readAll();
    pReply->deleteLater();
    emit downloaded();
}

QByteArray DataDownloader::downloadedData() const {
    return m_DownloadedData;
}
