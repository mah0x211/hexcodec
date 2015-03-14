/*
 *  Copyright 2015 Masatoshi Teruya. All rights reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  main.c
 *
 *  Created by Masatoshi Teruya on 2015/03/14.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hexcodec.h"

int main (int argc, const char * argv[])
{
    char *src = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    size_t len = strlen( src );
    size_t hlen = len * 2;
    char *enc = alloca( hlen + 1 );
    char *dec = alloca( len + 1 );
    
    // encode
    printf("encode:\n\t%s\n", src );
    hex_encode( (unsigned char*)enc, (unsigned char*)src, len );
    enc[hlen] = 0;
    printf("\t%s\n\n", enc );
    
    // decode
    printf("decode:\n\t%s\n", enc );
    assert( hex_decode( dec, (unsigned char*)enc, hlen ) == 0 );
    dec[len] = 0;
    printf("\t%s\n", dec );
    
    assert( memcmp( src, dec, len ) == 0 );
    
    return 0;
}


