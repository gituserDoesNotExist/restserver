
#include <iostream>
//#include <restbed>
#include <cstdlib>
#include <memory>

using namespace std;
using namespace restbed;
using namespace std::chrono;

// void post_method_handler( const shared_ptr< Session > session ) {
//     const auto request = session->get_request( );
//     int content_length = request->get_header( "Content-Length", 0 );

//     cout << "content-length: " << content_length << endl;
//     session->fetch( content_length, [ ]( const shared_ptr< Session > session, const Bytes & body )
//     {
//         fprintf( stdout, "%.*s\n", ( int ) body.size( ), body.data( ) );
//         session->close( OK, "Hello, World!", { { "Content-Length", "13" } } );
//     } );
// }

int main() {
    cout << "Hello World!" << endl;

    // std::shared_ptr<restbed::Resource> resource = make_shared< Resource >( );
    // resource->set_path( "/resource" );
    // resource->set_method_handler( "POST", post_method_handler );

    // shared_ptr<Settings> settings = make_shared< Settings >( );
    // settings->set_port( 1984 );
    // settings->set_default_header( "Connection", "close" );

    // Service service;
    // service.publish( resource );
    // service.start( settings );
    // cout << "Started server on Port 1984" << endl;

}