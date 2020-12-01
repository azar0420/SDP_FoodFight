#ifndef FEHRANDOM_H
#define FEHRANDOM_H

/**
 * @brief Generates a random integer between [0, RAND_MAX].
 * 
 * For generating an integer in a given range, the value of RAND_MAX does not matter.
 * The modulo operator can be used like so to generate a number between [0, 9]:
 * 
 * RandInt() % 10;
 * 
 * @return Random number between [0, RAND_MAX]
 */
int RandInt();

#endif // FEHRANDOM_H