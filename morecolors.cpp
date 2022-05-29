#include <QBoxLayout>
#include <QColorDialog>
#include <QToolButton>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QPainter>
#include <iconinfo.h>
#include <morecolors.h>

// TO DO : ajouter le parent
MoreColorsDialog::MoreColorsDialog(const QColor &defaultColor)
// Dialog box to choose the color of the icon
{
    setWindowTitle(tr("More colors"));

    colorDlg = new QColorDialog(this);
    colorDlg->setWindowFlags(Qt::Widget);
    colorDlg->setWindowTitle(tr("Icon color"));
    colorDlg->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);
    colorDlg->setCurrentColor(defaultColor);
    colorDlg->setCustomColor(0, Qt::blue);
    colorDlg->setCustomColor(1, Qt::black);
    colorDlg->setCustomColor(2, Qt::white);
    colorDlg->setCustomColor(3, Qt::green);
    colorDlg->setCustomColor(4, Qt::red);
    colorDlg->setCustomColor(5, Qt::yellow);
    colorDlg->setCustomColor(6, Qt::cyan);
    connect(colorDlg, &QColorDialog::currentColorChanged, this, &MoreColorsDialog::currentColorChanged);
    
    iconButton = new QToolButton;
    iconButton->setIconSize(QSize(128, 128));
    iconButton->setIcon(IconInfo::changeColorIcon(IconInfo::syncingOnedriveIconPathName(), defaultColor));

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(colorDlg);
    hLayout->addWidget(iconButton);
    QGroupBox *groupBox = new QGroupBox(tr("Color your clouds..."));
    groupBox->setLayout(hLayout);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(groupBox);
    vLayout->addWidget(buttonBox);
    vLayout->setSizeConstraint(QLayout::SetFixedSize); // Prevent resizing the window
    setLayout(vLayout);
}

void MoreColorsDialog::currentColorChanged(const QColor &color)
// Slot function called when the user selects a new color
{
    iconButton->setIcon(IconInfo::changeColorIcon(IconInfo::syncingOnedriveIconPathName(), color));
}

QColor MoreColorsDialog::colorValidated()
// Return the selected color by the user
{
    return colorDlg->currentColor();
}
