# hexcodec.h

hexadecimal encoding/decoding header library.

---

### void hex_encode( unsigned char \*dest, unsigned char \*src, size_t len )

hex_encode() function encode the `len` bytes from `src` and copy encoded bytes to the `dest`.

**Parameters**

- `*dest`: dest size must be greater than `len` * 2.
- `*src`: source string.
- `len`: byte length of `src`.


### int hex_decode( char \*dest, unsigned char \*src, size_t len )

hex_encode() function encode the `len` bytes from `src` and copy encoded bytes to the `dest`.

**Parameters**

- `*dest`: dest size must be greater than `len` / 2.
- `*src`: encoded string.
- `len`: byte length of `src`. (this value must be multiples of two.)

**Return Values**

returns `0` on success, or `-1` on failure.  

**Errors**

- `EINVAL`: `len` value is not multiples of two.
- `EILSEQ`: `src` contained an illegal character.


## Usage

```c

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
```
