#include "JobManager.h"

JobManager* JobManager::instance = NULL;

JobManager::~JobManager() {
    clear();
}

JobManager::JobManager() {
    jobFrontPointer = NULL;
}

JobManager* JobManager::getInstance() {
    if (instance == NULL) {
        instance = new JobManager();
    }
    return instance;
}

bool JobManager::deleteInstance() {
    if (instance != NULL) {
        instance->clear();
        delete instance;
        instance = NULL;
        return 1;
    } else {
        return 0;
    }
}

void JobManager::addJob(int priority) {
    if (jobFrontPointer == NULL) {
        jobFrontPointer = new Job(priority);
    } else {
        Job *p = jobFrontPointer;
        while (p->getNext() != NULL) {
            p = p->getNext();
        }
        Job *temp = p;
        p = p->getNext();
        p = new Job(priority);
        temp->setNext(p);
    }
}

void JobManager::finishOneJob() {
    if (jobFrontPointer != NULL) {
        Job* temp = jobFrontPointer;
        jobFrontPointer = jobFrontPointer->getNext();
        delete temp;
    }
}

void JobManager::sortJob() {
    if (jobFrontPointer != NULL) {
        if (getNumOfJob() == 1) {
            return;
        }
        Job* pNowP = jobFrontPointer;
        //  4个辅助指针，分别指向变换对象的前一个和后一个。
        Job* temp1l, *temp1n;
        Job* temp2l, *temp2n;
        Job* pMaxP;
        Job* p = pNowP;
        temp1l = NULL;
        temp1n = p->getNext();
        temp2l = NULL;
        temp2n = p->getNext();
        int num = getNumOfJob();
        for (int i = 0; i < num - 1; i++) {
            p = pNowP;
            pMaxP = pNowP;
            temp1n = pNowP->getNext();
            temp2n = pMaxP->getNext();
            while (p->getNext() != NULL) {
                if (pMaxP->getPriority() < p->getNext()->getPriority()) {
                    temp2l = p;
                    pMaxP = p->getNext();
                    temp2n = pMaxP->getNext();
                }
                else if (pMaxP->getPriority() == p->getNext()->getPriority()) {
                    if (pMaxP->getId() > p->getNext()->getId()) {
                        temp2l = p;
                        pMaxP = p->getNext();
                        temp2n = pMaxP->getNext();
                    }
                }
                p = p->getNext();
            }
            if (pNowP != pMaxP && pNowP->getNext() != pMaxP) {
                if (pNowP == jobFrontPointer) {
                    jobFrontPointer = pMaxP;
                    pMaxP->setNext(temp1n);
                } else {
                    temp1l->setNext(pMaxP);
                    pMaxP->setNext(temp1n);
                }
                temp2l->setNext(pNowP);
                pNowP->setNext(temp2n);
            }
            else if (pNowP->getNext() == pMaxP) {
                if (pNowP == jobFrontPointer) {
                    jobFrontPointer = pMaxP;
                    pMaxP->setNext(pNowP);
                } else {
                    temp1l->setNext(pMaxP);
                    pMaxP->setNext(pNowP);
                }
                pNowP->setNext(temp2n);
            }
            pNowP = pMaxP;
            temp2l = pNowP;
            temp1l = pNowP;
            pNowP = pNowP->getNext();
            temp1n = pNowP->getNext();
        }
    }
}

void JobManager::printJob() {
    if (jobFrontPointer != NULL) {
        Job* p = jobFrontPointer;
        while (p->getNext() != NULL) {
            cout << p->toString() << "->";
            p = p->getNext();
        }
        cout << p->toString() << endl;
    } else {
        cout << "empty!" << endl;
    }
}

int JobManager::getNumOfJob() {
    int count = 0;
    if (jobFrontPointer != NULL) {
        Job* p = jobFrontPointer;
        count++;
        while (p->getNext() != NULL) {
            p = p->getNext();
            count++;
        }
    }
    return count;
}

void JobManager::clear() {
    if (jobFrontPointer != NULL) {
        Job* p = jobFrontPointer;
        Job* temp = NULL;
        while (p->getNext() != NULL) {
            temp = p;
            p = p->getNext();
            delete temp;
        }
        delete p;
        jobFrontPointer = NULL;
    }
}
