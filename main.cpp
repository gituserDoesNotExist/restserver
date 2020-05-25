#include <iostream>
#include <restbed>
#include <cstdlib>
#include <memory>

using namespace std;
using namespace restbed;

void post_method_handler( const shared_ptr< Session > session ) {
    session->get_request( );

}

int main() {
    cout << "Hello World!" << endl;

    auto resource = make_shared< Resource >( );
    resource->set_path("resource");
    
}