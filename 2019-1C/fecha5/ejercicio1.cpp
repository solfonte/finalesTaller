/***1) Escriba una rutina (para ambiente gráfico Windows o Linux) que dibuje un triángulo
 amarillo del tamaño de la ventana.**
*/

//no terminado

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    // Clase que contiene el loop principal
    QApplication app(argc, argv);
    // Instancio un widget
    // Llamo a QLabel(const QString &text, QWidget *parent=0, Qt::WindowFlags f=0);
    QLabel label("Hello QT");
    // Muestro el elemento
    label.show();
    // Arranca el loop de la UI
    return app.exec();
}
