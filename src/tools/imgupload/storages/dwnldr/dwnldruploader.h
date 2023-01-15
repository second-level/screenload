#ifndef DWNLDR_UPLOADER
#define DWNLDR_UPLOADER

#include "src/tools/imgupload/storages/imguploaderbase.h"
#include <QUrl>
#include <QWidget>
#include "dwnldrauthhttpserver.h"

class QNetworkReply;
class QNetworkAccessManager;
class QUrl;

static const char* kDwnldrStorageName = "dwnldr";

static const char* kDwnldrLocalHostUrl = "http://localhost/";
static const int kDwnldrLocalPort = 8087;

static const char* kDwnldrUserAgentTemplate = "ScreenLoad/%1 %2";

static const char* kDwnldrOAuthTokenUrl = "https://download.ru/oauth/token";

static const char* kDwnldrClientId = "0524f0e89a3fd0912b1ed4484e21cde8c02e5e5625fe070ba65e5ff2deaf78e2";
static const char* kDwnldrClientSecret = "7f090e18d58cf2983f071b3f5afb544e0aaba1e8ce80f83e9a9bfb9ee9b917f5";
static const char* kDwnldrAnonymousKey = "d0327c42657d96742bcd979acedbf0a3";

class DwnldrUploader : public ImgUploaderBase
{
    Q_OBJECT
public:
    explicit DwnldrUploader(const QPixmap& capture, QWidget* parent = nullptr);

private slots:
    void onAuthorizationCodeReceived(const QString& authorizationCode);
    void handleReply(QNetworkReply* reply);

private:
    void upload();
    void deleteImage(const QString& fileName, const QString& deleteToken);
    void authorizeViaBrowser();
    void requestAccessToken(const QString& authorizationCode);
    void uploadFile(const QString& accessToken);

private:
    QNetworkAccessManager* m_networkAM;
    DwnldrAuthHttpServer *m_authHttpServer;
};
#endif
