#ifndef FEHUTILITY_H
#define FEHUTILITY_H

/**
 * @brief Sleeps for the specified number of milliseconds.
 * 
 * @param msec Milliseconds to sleep
 */
void Sleep( int msec );

/**
 * @brief Sleeps for the specified number of seconds.
 * 
 * @param sec Seconds to sleep
 */
void Sleep( float sec );

/**
 * @brief Sleeps for the specified number of seconds.
 * 
 * @param sec Seconds to sleep
 */
void Sleep( double sec );

/**
 * @brief Gets the time since the program started.
 * 
 * @return double Time since the program started in seconds
 */
double TimeNow();

#endif // FEHUTILITY_H