#define cimg_display 0
//#define cimg_OS 0
#include "CImg.h"
#include <iostream>
#include <fstream>

using namespace cimg_library;

int main( int argc, char* argv[] )
{
    int cw = 8, ch = 8;

    if( argc<2 )
      {
        printf("Usage: buildfont font.png [cw] [ch]\n");
        return -1;
      }

    if( argc >= 3 ) cw = atoi(argv[2]);
    if( argc >= 4 ) ch = atoi(argv[3]);

    std::cout << "Loading " << argv[1] << std::endl;

    try 
    {
        CImg< unsigned char > fontimg( argv[1] );
        std::cout << "Image size: " << fontimg.width() << "x" << fontimg.height() << std::endl;
	std::cout << "Font character size: " << cw << "x" << ch << std::endl;

        if( fontimg.width() % cw != 0 )
        {
  	    std::cout << "Image width should be multiple of " << cw << std::endl;
            return -1;
        }
        if( fontimg.height() % ch != 0 )
        {
 	    std::cout << "Image height should be multiple of " << ch << std::endl;
            return -1;
        }

        int nrows = fontimg.height() / ch;
        int ncols = fontimg.width() / cw;

        if( nrows*ncols != 256 ) 
        {
            std::cout << "Image does not contain 256 characters." << std::endl;
            return -1;
        }

	char binfilename[100];
	snprintf(binfilename, 100, "font%ix%i.bin", cw, ch);
        std::ofstream ofs(binfilename, std::ios::binary );

        for( unsigned int i=0; i<nrows; ++i )
        {
            for( unsigned int j=0; j<ncols; ++j )
            {
                for( unsigned int y=i*ch; y<i*ch+ch; ++y )
                {
                    for( unsigned int x=j*cw; x<j*cw+cw; ++x )
                    {
                        unsigned char v = fontimg( x,y );
                        v = v==0 ? 0xFF : 0x0;
                        ofs << v;
                        std::cout << (v==0xFF ? "*" : " ") ;
                    }
                    std::cout << std::endl;
                }

            }
        }
        ofs.flush();
        ofs.close();
        
    } 
    catch (CImgIOException& ex )
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }


    return 0;
}
