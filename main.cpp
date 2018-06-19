#include <iostream>
#include <string>
#include <stdlib.h>

#include "lz4.h"

int main()
{
	char source[1024] = "ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD ABCD\0";

	char buff_compress[1024 * 4] = { 0 };
	char buff_decompress[1024 * 4] = { 0 };

	int compress_size = LZ4_compress_default(source, buff_compress, sizeof(source), sizeof(buff_compress));

	int decompress_size = LZ4_decompress_safe(buff_compress, buff_decompress, compress_size, sizeof(buff_decompress));

	printf("LZ4 Simple compress / decompress\nInput Size = %i\nCompress Size = %i\nDecompress Size = %i\n", strlen(source), compress_size, decompress_size);

	getchar();
	return 0;
}
