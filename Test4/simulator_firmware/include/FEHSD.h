#ifndef FEHSD_H
#define FEHSD_H
#include "FEHFile.h"
#include "ctype.h"

class FEHSD
{
public:
    FEHSD();

    /**
     * @brief Opens a file.
     * 
     * File modes:
     * 'r': Open for reading; the file must exist
     * 'w': Open for writing; the file will be created if it doesn't exist. Will overwrite existing files
     * 'a': Open for appending; the file will be created if it doesn't exist
     * 
     * 'r+': Open for reading and writing,; the file must exist
     * 'w+': Open for reading and writing; the file will be created if it doesn't exist. Will overwrite existing files
     * 'a+': Open for reading and appending; the file will be created if it doesn't exist
     * 
     * @param str Name of file to open
     * @param mode Mode to open file
     * @return A FEHFile pointer to be used with other SD functions if successful, NULL if unsuccessful
     */
    FEHFile* FOpen(const char* str, const char* mode);

    /**
     * @brief Closes a file.
     * 
     * @param fptr File to close
     * 
     * @return 0 if successful, EOF otherwise
     */
    int FClose(FEHFile *fptr);

    /**
     * @brief Closes all currently open files.
     * 
     * @return 0 if successful, EOF otherwise
     */
    int FCloseAll();

    /**
     * @brief Prints to a file.
     * 
     * @param fptr File to write to
     * @param format String format to scan. Same format specifier as fscanf on Linux
     * @param ... variables to print
     * 
     * @returns Total number of characters written if successful, negative otherwise
     */
    int FPrintf(FEHFile *fptr,const char* format,
    		/* Pointer to the format string */ ...);

    /**
     * @brief Scans from a file.
     * 
     * @param fptr File to read from
     * @param format String format to scan. Same format specifier as fscanf on Linux
     * @param ... variables to scan into, as pointers
     * 
     * @returns How many variables were successfully matched
     */        
    int FScanf(FEHFile *fptr, const char* format, ...);

    /**
     * @brief Checks if a file has been completely read.
     * 
     * @param fptr File to check for EOF
     * @return 0 if at end of file, non zero otherwise
     */
    int FEof(FEHFile *fptr);

private:
	int numberOfFiles;
};

extern FEHSD SD;
#endif
    