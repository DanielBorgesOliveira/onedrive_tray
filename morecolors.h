#ifndef MORECOLORS_H
#define MORECOLORS_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QColorDialog;
class QToolButton;
QT_END_NAMESPACE

class MoreColorsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MoreColorsDialog(const QColor &defaultColor);
    QColor colorValidated();

protected:

private slots:
    void currentColorChanged(const QColor &color);

private:
  QColorDialog *colorDlg;
  QToolButton *iconButton;
};

#endif
