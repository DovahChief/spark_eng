/*
 * file_utils.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#ifndef UTILS_FILE_UTILS_H_
#define UTILS_FILE_UTILS_H_

#include <cstring>
#include <cstdio>
#include <string>

namespace spark {

	class FILEUT{
	public:
		static std::string lee_arch(const char* ruta){
				FILE * arch = fopen(ruta, "rt");
				fseek(arch , 0 , SEEK_END);
				unsigned long length = ftell(arch);
				char* data  = new char[length + 1];
				memset(data, 0 , length + 1);
				fseek(arch, 0 , SEEK_SET);
				fread(data, 1, length, arch);

				fclose(arch);
				std::string r(data);
				delete[] data;
				return (r);
			}
	};

}



#endif /* UTILS_FILE_UTILS_H_ */
