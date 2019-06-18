#include <QFileDialog>
#include "helpers.h"
#include "openfiledialog.h"
#include "ui_openfiledialog.h"

OpenFileDialog::OpenFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenFileDialog)
{
    ui->setupUi(this);
}

OpenFileDialog::~OpenFileDialog()
{
    delete ui;
}

QString OpenFileDialog::file()
{
    return ui->fileField->text();
}

QString OpenFileDialog::subs()
{
    return ui->subsField->text();
}

void OpenFileDialog::on_fileBrowse_clicked()
{
    static QString filter;
    if (filter.isEmpty())
        filter = Helpers::fileOpenFilter();

    QUrl url = QFileDialog::getOpenFileUrl(this, tr("Select File"), QUrl(), filter);
    if (url.isValid())
        ui->fileField->setText(url.toDisplayString());
}

void OpenFileDialog::on_subsBrowse_clicked()
{
    static QString subsFilter;
    if (subsFilter.isEmpty())
        subsFilter = Helpers::subsOpenFilter();
    QUrl url = QFileDialog::getOpenFileUrl(this, tr("Select File"), QUrl(), subsFilter);
    if (url.isValid())
        ui->subsField->setText(url.toDisplayString());
}
