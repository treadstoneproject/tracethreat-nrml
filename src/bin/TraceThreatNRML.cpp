
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/processor/TMultiplexedProcessor.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/concurrency/Thread.h>
#include <glog/logging.h>


#include "services/AuthenticationHandler.hpp"
#include "msg/gen-cpp/Authentication.h"

namespace thrift = apache::thrift;
namespace protocol  = thrift::protocol;
namespace transport = thrift::transport;
namespace server    = thrift::server;
namespace concurrency = thrift::concurrency;

int main(){

	LOG(INFO)<<"Start Server TraceThreat-NRML";

	boost::shared_ptr<thrift::transport::TProtocolFactory> protocolFactory;

  

	boost::shared_ptr<thrift::TMultiplexedProcessor>  
			processor(new thrift::TMultiplexedProcessor);
	processor->registerProcessor("Authentication",
															 boost::shared_ptr<thrift::TProcessor>(
																new authentication::AuthenticationProcessor(
																	boost::shared_ptr<services::AuthenticationHandler>(
																		new services::AuthenticationHandler()))));


	LOG(INFO)<<"Register service : Authentication completed.";

	boost::shared_ptr<transport::TServerTransport> serverTransport(
									new transport::TServerSocket(9090));

	boost::shared_ptr<transport::TTransportFactory> transportFactory(
																new transport::TBufferedTransportFactory());


	boost::shared_ptr<concurrency::ThreadManager> threadManager = 
		concurrency::ThreadManager::newSimpleThreadManager(4);// workCount

  boost::shared_ptr<concurrency::PosixThreadFactory> threadFactoryPosix = 
		boost::shared_ptr<concurrency::PosixThreadFactory>(new concurrency::PosixThreadFactory());


  threadManager->threadFactory(threadFactoryPosix);
  threadManager->start();


  server::TThreadPoolServer server(processor,
  	serverTransport,
    transportFactory,
    protocolFactory,
    threadManager); 

  server.serve();	

}
