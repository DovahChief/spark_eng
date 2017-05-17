/*
 * file_utils.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#pragma once

#include <cstring>
#include <string>
#include <iostream>

namespace spark {

	class F{
    public:
        static std::string lee_arch(std::string _ruta){
				FILE * arch = fopen(_ruta.c_str() , "rt");
				fseek(arch , 0 , SEEK_END);
				long length = ftell(arch);
				char* data { new char[length + 1] { } };
				memset(data, 0 , length + 1);
				fseek(arch, 0 , SEEK_SET);
				fread(data, 1, length, arch);

				fclose(arch);
				std::string r(data);
				delete[] data;
				return (r);
		}
    };
		
}/* namespace spark */

