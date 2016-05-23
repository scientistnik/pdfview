#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include </usr/include/poppler/qt5/poppler-qt5.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QString filename = "1.pdf";
    Poppler::Document* document = Poppler::Document::load(filename);
    if (!document || document->isLocked()) {
      // ... error message ....
      delete document;
      return 0;
    }
    // Paranoid safety check
    if (document == 0) {
      // ... error message ...
      return 0;
    }
    // Access page of the PDF file
    Poppler::Page* pdfPage = document->page(0);  // Document starts at page 0
    if (pdfPage == 0) {
      // ... error message ...
      return 0;
    }
    // Generate a QImage of the rendered page
    QImage image = pdfPage->renderToImage();
    if (image.isNull()) {
      // ... error message ...
      return 0;
    }
    // ... use image ...
    // after the usage, the page must be deleted
    delete pdfPage;

    //QImage image;
    //image.show();avatar.png
    //image.load("avatar.png");

    QLabel myLabel;
    myLabel.setPixmap(QPixmap::fromImage(image));
    myLabel.show();

    return a.exec();
}
