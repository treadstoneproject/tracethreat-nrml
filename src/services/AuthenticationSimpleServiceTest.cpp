#include "gtest/gtest.h"
#include <glog/logging.h>

#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/server/TSimpleServer.h> 
#include <thrift/transport/THttpServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>

#include <boost/make_shared.hpp>

#include "msg/gen-cpp/Authentication.h"
#include "services/AuthenticationHandler.hpp"  


#include <memory>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

  
TEST(AuthenitcationServer, TestServicesSimple){
	
	LOG(INFO) << "Start Simple Service : Authentication";
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	int port = 8181;
	shared_ptr<services::AuthenticationHandler> handler(new services::AuthenticationHandler());
	shared_ptr<TProcessor> processor(new  authentication::AuthenticationProcessor(handler));
	shared_ptr<TTransportFactory> transportFactory(new THttpServerTransportFactory());
	shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());
	shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));

	//shared_ptr<TJSONProtocol> jsonProtocol = boost::make_shared<TJSONProtocol>(serverTransport->accept());

	TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory); 
	server.serve();
	
	
}

