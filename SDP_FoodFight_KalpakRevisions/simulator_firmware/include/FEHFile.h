#ifndef FEHFILE_H
#define FEHFILE_H
#include <stdio.h>

class FEHFile
{
	public:
		FILE wrapper;
		static int prevFileID;
		int fileIdNum;
		FEHFile() {
			fileIdNum = ++prevFileID;
		}
}; 
#endif
