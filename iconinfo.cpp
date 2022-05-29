#include <QVector>
#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <iconinfo.h>

IconInfo::IconInfo(QObject* parent) : QObject(parent) {}

IconInfo::~IconInfo(){}

const QString IconInfo::m_onedriveIconPathName = QString(":/images/OneDrive.png");

const QString IconInfo::m_syncingOnedriveIconPathName = QString(":/images/OneDrive-sync.png");

QStringList IconInfo::defaultColorsText()
{
    static const QStringList result = {tr("Blue"), tr("White"), tr("Red"), tr("Green"), tr("Black")};
    return result;
}

QVector<QColor> IconInfo::defaultColors()
{
    QVector<QColor> result {Qt::blue, Qt::white, Qt::red, Qt::green, Qt::black};
    return result;
}

QString IconInfo::onedriveIconPathName()
{
    return m_onedriveIconPathName;
}

QString IconInfo::syncingOnedriveIconPathName()
{
    return m_syncingOnedriveIconPathName;
}

QPixmap IconInfo::changeColorIcon(const QString &imageName, const QColor &color)
{
    QPixmap pixmap(imageName);
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), color);
    painter.end();
    return pixmap;
}

