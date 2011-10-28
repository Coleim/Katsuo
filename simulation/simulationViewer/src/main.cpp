#include <QtGui/QApplication>

#include "viewer/widgets/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    simulationviewer::widgets::MainWindow aMainWindow;
    aMainWindow.show();

    return app.exec();
}

// doc qt : http://doc.qt.nokia.com/4.7/index.html

/*
  Code pour connexion
void FenPrincipale::afficheClient()
{
    // On se connecte ? la bdd
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("Boulangerie.db");
    db.setUserName("root");
    db.setPassword("");

    if (!db.open())
    {
        QMessageBox::critical(this, "Titre de la fenÍtre", "Impossible de se connecter ? la base de donnÈe");
    }

     QSqlTableModel *model = new QSqlTableModel;
     model->setTable("Clients");
     model->select();
     model->removeColumn(0);
     model->setHeaderData(0, Qt::Horizontal,"Genre");
     model->setHeaderData(1, Qt::Horizontal,"Nom");
     model->setHeaderData(2, Qt::Horizontal,"PrÈnom");
     model->setHeaderData(3, Qt::Horizontal,"Adresse");
     model->setHeaderData(4, Qt::Horizontal,"Code Postal");
     model->setHeaderData(5, Qt::Horizontal,"Ville");
     model->setHeaderData(6, Qt::Horizontal,"Tel PrivÈ");
     model->setHeaderData(7, Qt::Horizontal,"Tel Professionnel");
     model->setHeaderData(8, Qt::Horizontal,"Tel Portable");
     model->setHeaderData(9, Qt::Horizontal,"Fax");
     model->setHeaderData(10, Qt::Horizontal,"Email");

     QTableView *view = new QTableView;
     view->setModel(model);

     QVBoxLayout *layoutPrincipal = new QVBoxLayout;
     layoutPrincipal->addWidget(view);

     QWidget *zoneCentrale = new QWidget;
     zoneCentrale->setLayout(layoutPrincipal);
     setCentralWidget(zoneCentrale);
}

*/
