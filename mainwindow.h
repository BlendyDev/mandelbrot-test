#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <complex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int calculate(std::complex<double> c, int iterations) {
        std::complex<double> z(0,0);
        double length = sqrt(c.real()*c.real()+c.imag()*c.imag());
        if (length > 2) return 1;
        for (int i = 0; i < iterations; i++) {
            z = pow (z, 2) + c;
            length = sqrt(z.real()*z.real()+z.imag()*z.imag());
            if (length > 2) return i;
        }
        return 0;
    }

    void paint(QImage* image, int sizeX, int sizeY, int zoom, int iterations) {
        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++) {
                int i = calculate(coordToComplex(x, y, 0.004/zoom, sizeX, sizeY), iterations);
                if (i == 0) {
                    image->setPixel(x, y,  QColor::fromHsv(0, 0, 0).rgb());
                } else {
                    image->setPixel(x, y,  QColor::fromHsv((x+y)%360, 255, i*i).rgb());
                }
            }
        }
    }

    std::complex<double> coordToComplex (int x, int y, double minPixel, int sizeX, int sizeY) {
        return std::complex<double>((x-sizeX/2)*minPixel, (y-sizeY/2)*minPixel);
    }

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
