#ifndef ZPIPE_H
#define ZPIPE_H
#define SET_BINARY_MODE(file)
#include <iostream>
#include <cstring>
#include <cassert>
#include "zlib.h"

// Zpipe class  to perform compression, decompression, display usage, and error.
class Zpipe {
  public:
    const long int CHUNK = {16384};
    int def( FILE *, FILE *, int ); // compress
    int inf( FILE *, FILE * ); // decompress
    void zerr( int ); // error
    void usage( char ** ); // usage
};
#endif