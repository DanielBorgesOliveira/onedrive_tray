#ifndef ICONINFO_H
#define ICONINFO_H

#include <QObject>
#include <QVector>

class IconInfo : public QObject
{
  Q_OBJECT
public:
  explicit IconInfo(QObject* parent = nullptr);
  ~IconInfo();
  static QStringList defaultColorsText(); // Default colors in QString
  static QVector<QColor> defaultColors(); // Default colors in QColor
  static QString onedriveIconPathName(); // Path name of the onedrive icon
  static QString syncingOnedriveIconPathName(); // Path name of the onedrive icon when syncing
  static QPixmap changeColorIcon(const QString &imageName, const QColor &color);

private:
  static const QString m_onedriveIconPathName;
  static const QString m_syncingOnedriveIconPathName;
};

#endif
