#include <iostream>
#include <restbed>
#include <cstdlib>
#include <memory>
#include <Processing.NDI.Lib.h>
#pragma comment(lib, "Processing.NDI.Lib.x64.lib")

using namespace std;
using namespace restbed;
using namespace std::chrono;

void post_method_handler( const shared_ptr< Session > session ) {
    const auto request = session->get_request( );
    int content_length = request->get_header( "Content-Length", 0 );

    cout << "content-length: " << content_length << endl;
    session->fetch( content_length, [ ]( const shared_ptr< Session > session, const Bytes & body )
    {
        fprintf( stdout, "%.*s\n", ( int ) body.size( ), body.data( ) );
        session->close( OK, "Hello, World!", { { "Content-Length", "13" } } );
    } );
}

int main() {
    cout << "Hello World!" << endl;

    std::shared_ptr<restbed::Resource> resource = make_shared< Resource >( );
    resource->set_path( "/resource" );
    resource->set_method_handler( "POST", post_method_handler );

    shared_ptr<Settings> settings = make_shared< Settings >( );
    settings->set_port( 1984 );
    settings->set_default_header( "Connection", "close" );

    Service service;
    // service.publish( resource );
    // service.start( settings );
    // cout << "Started server on Port 1984" << endl;

	if (!NDIlib_initialize()) {
        return 0;
    }

	// We are going to create an NDI finder that locates sources on the network.
	NDIlib_find_instance_t pNDI_find = NDIlib_find_create_v2();
	if (!pNDI_find) {
        return 0;
    }

	// Run for one minute
	for (const auto start = high_resolution_clock::now(); high_resolution_clock::now() - start < minutes(1);)
	{	// Wait up till 5 seconds to check for new sources to be added or removed
		if (!NDIlib_find_wait_for_sources(pNDI_find, 5000/* 5 seconds */))
			{ printf("No change to the sources found.\n"); continue; }
		
		// Get the updated list of sources
		uint32_t no_sources = 0;
		const NDIlib_source_t* p_sources = NDIlib_find_get_current_sources(pNDI_find, &no_sources);
				
		// Display all the sources.
		printf("Network sources (%u found).\n", no_sources);
		for (uint32_t i = 0; i < no_sources; i++)
			printf("%u. %s\n", i + 1, p_sources[i].p_ndi_name);
	}

	// Destroy the NDI finder
	NDIlib_find_destroy(pNDI_find);

	// Finished
	NDIlib_destroy();

	// Success. We are done
	return 0;



    return EXIT_SUCCESS;
}