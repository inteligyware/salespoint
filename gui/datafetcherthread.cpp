#include "datafetcherthread.h"

DataFetcherThread::DataFetcherThread(QVector<ListingModel *> &listingmodels, int pos):QThread(), index{pos}{
    listingmodel = listingmodels[pos];    
}

DataFetcherThread::DataFetcherThread(ListingModel** listingmodelptr, int pos):QThread(), index{pos}{
    listingmodel = *listingmodelptr;
}

void DataFetcherThread::run(){

//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL",QUuid::createUuid().toString());
//    db.setDatabaseName("odb_db");
//    db.setUserName("odb_user");
//    db.setPassword("odb_pwd");
//    db.setHostName("localhost");
//    db.setPort(5432);

//    if (!db.open()){
//        //QMessageBox::information(&mw ,qApp->applicationName(),db.lastError().text());
//        qApp->exit(EXIT_FAILURE);
//    }

    listingmodel->load();
    emit resultReady(index);
}


