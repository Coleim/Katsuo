#include <QtSql>
#include <iostream>






int main(int argc, char **argv)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("P*is1525");
    db.setDatabaseName("ORI_KatsuoSimulation");
    if(db.open())
    {
        std::cout << "Vous êtes maintenant connecté à " << db.hostName().toStdString() << std::endl;

        QSqlQuery q;
        q.prepare("INSERT INTO ORI_DEPTH (latitude, longitude, depth) VALUES (?,?,?)");

        QVariantList lat;
        lat << 1.1 << 2 << 3.8 << 4;
        q.addBindValue(lat);

        QVariantList lon;
        lon << 1.1 << 2 << 3.8 << 4;
        q.addBindValue(lon);

        QVariantList dep;
        dep << 1.1 << 2 << 3.8 << 4;
        q.addBindValue(dep);

        if (q.execBatch())
        {
            std::cout << "Ça marche ! :)" << std::endl;
        }
        else
        {
            std::cout << "Ça marche pas ! :(" << std::endl;
        }

    }
    else
    {
        std::cout << "La connexion a échouée, désolé :(" << std::endl << db.lastError().text().toStdString() << std::endl;
    }

    return 0;
}
