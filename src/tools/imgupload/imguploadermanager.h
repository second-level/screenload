// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: Yurii Puchkov & Contributors
//

#ifndef SCREENLOAD_IMGUPLOADERMANAGER_H
#define SCREENLOAD_IMGUPLOADERMANAGER_H

#include "src/tools/imgupload/storages/imguploaderbase.h"
#include <QObject>

//#define IMG_UPLOADER_STORAGE_DEFAULT "imgur"
#define IMG_UPLOADER_STORAGE_DEFAULT "dwnldr"

class QPixmap;
class QWidget;

class ImgUploaderManager : public QObject
{
    Q_OBJECT
public:
    explicit ImgUploaderManager(QObject* parent = nullptr);

    ImgUploaderBase* uploader(const QPixmap& capture,
                              QWidget* parent = nullptr);
    ImgUploaderBase* uploader(const QString& imgUploaderPlugin);

//    const QString& url();
    const QString& uploaderPlugin();

private:
    void init();

private:
    ImgUploaderBase* m_imgUploaderBase;
    QString m_urlString;
    QString m_imgUploaderPlugin;
};

#endif // SCREENLOAD_IMGUPLOADERMANAGER_H
