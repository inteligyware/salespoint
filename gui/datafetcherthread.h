#ifndef DATAFETCHERTHREAD_H
#define DATAFETCHERTHREAD_H

#include "models.h"

class DataFetcherThread : public QThread {
    Q_OBJECT
    ListingModel* listingmodel;
    int index;
    void run();

public:
    DataFetcherThread(QVector<ListingModel*> &listingmodels , int pos);
    DataFetcherThread(ListingModel** listingmodelptr , int pos);

signals:
    void resultReady(int index);
};

#endif // DATAFETCHERTHREAD_H
