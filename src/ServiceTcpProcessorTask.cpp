#include "ServiceTcpProcessorTask.h"


ServiceTcpProcessorTask::ServiceTcpProcessorTask()
{
}

void ServiceTcpProcessorTask::setRequestData(QByteArray requestData) {
    this->requestData = requestData;
}

void ServiceTcpProcessorTask::run()
{
    // Process the data
    QByteArray responseData;
    DataRequestProcessor dataRequestProcessor;

    responseData = dataRequestProcessor.processRequest(this->requestData);

    emit socketDataProcessed(responseData);
}
