#ifndef FEHLCD_H
#define FEHLCD_H

#include "LCDColors.h"

class FEHLCD
{
public:
    /**
     * @brief This enum contains different color combinations for drawing on the screen.
     */
    typedef enum
    {
        Black = 0,
        White = 1,
        Red = 2,
        Green = 3,
        Blue = 4,
		Scarlet = 5,
		Gray = 6
    } FEHLCDColor;

    FEHLCD();
	
    /**
     * @brief Checks whether the screen has been touched (clicked).
     * 
     * If true, the position of the touch will be stored in the two integer parameters.
     * Note: The Proteus stores touches in a buffer. This means that if the screen is touched 5 times and Touch(x, y) is
     * only called once, it will return true another 4 times even if Touch is called much later. To clear the touch buffer,
     * use ClearBuffer().
     * 
     * @param x_pos If true, the x position of the touch will be stored in this pointer
     * @param y_pos If true, the y position of the touch will be stored in this pointer
     * @return true if the screen has been touched, false otherwise
     */
	bool Touch(int* x_pos, int* y_pos);
    
    /**
     * @brief Clears the Proteus touch buffer.
     * 
     * This will disregard any touches that occured before this function call.
     */
    void ClearBuffer();

    /**
     * @brief Clears the screen, and sets it to a certain color.
     * 
     * @param color Color to set the screen to
     */
    void Clear(FEHLCDColor color);

    /**
     * @brief Clears the screen, and sets it to a certain color.
     * 
     * @param color Color to set the screen to
     */
    void Clear(unsigned int color);

    /**
     * @brief Clears the screen, and sets it to black.
     */
    void Clear();

    /**
     * @brief Sets the color to draw text.
     * 
     * @param color Color to draw text
     */
    void SetFontColor(FEHLCDColor color);

    /**
     * @brief Sets the color to draw text.
     * 
     * @param color Color to draw text
     */
    void SetFontColor(unsigned int color);

    /**
     * @brief Sets the color to draw objects.
     * 
     * @param color Color to draw objects
     */
    void SetDrawColor(FEHLCDColor color);

    /**
     * @brief Sets the color to draw objects.
     * 
     * @param color Color to draw objects
     */
    void SetDrawColor(unsigned int color);

    /**
     * @brief Draws a pixel on the screen.
     * 
     * The color is set by SetDrawColor(color)
     * 
     * @param x X position of the pixel
     * @param y Y position of the pixel
     */
    void DrawPixel(int x, int y);

    /**
     * @brief Draws a horizontal line on the screen.
     * 
     * The color is set by SetDrawColor(color)
     * 
     * @param y Y position of the line
     * @param x1 Starting x position of the line
     * @param x2 Ending x position of the line
     */
    void DrawHorizontalLine(int y,int x1, int x2);

    /**
     * @brief Draws a vertical line on the screen.
     * 
     * The color is set by SetDrawColor(color)
     * 
     * @param x X position of the line
     * @param y1 Starting y position of the line
     * @param y2 Ending y position of the line
     */
    void DrawVerticalLine(int x, int y1, int y2);

    /**
     * @brief Draws a line on the screen.
     * 
     * The color is set by SetDrawColor(color)
     * 
     * @param x1 Starting x position of the line
     * @param y1 Starting y position of the line
     * @param x2 Ending x position of the line
     * @param y2 Ending y position of the line
     */
    void DrawLine(int x1, int y1, int x2, int y2);

    /**
     * @brief Draws the borders of a rectangle on the screen.
     * 
     * The color is set by SetDrawColor(color)
     * 
     * @param x Top left x position of the rectangle
     * @param y Top left y position of the rectangle
     * @param width Width of the rectangle
     * @param height Height of the rectangle
     */
    void DrawRectangle(int x, int y, int width, int height);

    /**
     * @brief Draws a filled in rectangle on the screen.
     * 
     * The color is set by SetDrawColor(color)
     * 
     * @param x Top left x position of the rectangle
     * @param y Top left y position of the rectangle
     * @param width Width of the rectangle
     * @param height Height of the rectangle
     */
    void FillRectangle(int x, int y, int width, int height);

    /**
     * @brief Draws the borders of a circle on the screen.
     * 
     * The color is set by SetDrawColor(color)
     * 
     * @param x X position of the center of the circle
     * @param y Y position of the center of the circle
     * @param r Radius of the circle
     */
    void DrawCircle(int x, int y, int r);

    /**
     * @brief Draws a filled in circle on the screen.
     * 
     * The color is set by SetDrawColor(color)
     * 
     * @param x X position of the center of the circle
     * @param y Y position of the center of the circle
     * @param r Radius of the circle
     */
    void FillCircle(int x, int y, int r);

    /**
     * @brief Writes text to the screen at a spefific position.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param str String to write
     * @param x X position to write the text
     * @param y Y position to write the text
     */
	void WriteAt(const char* str, int x, int y);
    /**
     * @brief Writes text to the screen at a spefific position.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param i Integer to write
     * @param x X position to write the text
     * @param y Y position to write the text
     */
	void WriteAt( int i, int x, int y );

    /**
     * @brief Writes text to the screen at a spefific position.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param f Float to write
     * @param x X position to write the text
     * @param y Y position to write the text
     */
	void WriteAt( float f, int x, int y );

    /**
     * @brief Writes text to the screen at a spefific position.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param d Double to write
     * @param x X position to write the text
     * @param y Y position to write the text
     */
	void WriteAt( double d, int x, int y );

    /**
     * @brief Writes text to the screen at a spefific position.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param b Boolean to write
     * @param x X position to write the text
     * @param y Y position to write the text
     */
	void WriteAt( bool b, int x, int y );

    /**
     * @brief Writes text to the screen at a spefific position.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param c Character to write
     * @param x X position to write the text
     * @param y Y position to write the text
     */
	void WriteAt( char c, int x, int y );

    /**
     * @brief Writes text to the screen at a specific row and column.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param str String to write
     * @param row Row to write the text. There are 29 rows
     * @param col Column to write the text. There are 13 columns
     */
	void WriteRC( const char * str, int row, int col );

    /**
     * @brief Writes text to the screen at a specific row and column.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param i Integer to write
     * @param row Row to write the text. There are 29 rows
     * @param col Column to write the text. There are 13 columns
     */
	void WriteRC( int i, int row, int col );

    /**
     * @brief Writes text to the screen at a specific row and column.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param f Float to write
     * @param row Row to write the text. There are 29 rows
     * @param col Column to write the text. There are 13 columns
     */
	void WriteRC( float f, int row, int col );

    /**
     * @brief Writes text to the screen at a specific row and column.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param d Double to write
     * @param row Row to write the text. There are 29 rows
     * @param col Column to write the text. There are 13 columns
     */
	void WriteRC( double d, int row, int col );

    /**
     * @brief Writes text to the screen at a specific row and column.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param b Boolean to write
     * @param row Row to write the text. There are 29 rows
     * @param col Column to write the text. There are 13 columns
     */
	void WriteRC( bool b, int row, int col );

    /**
     * @brief Writes text to the screen at a specific row and column.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param c Character to write
     * @param row Row to write the text. There are 29 rows
     * @param col Column to write the text. There are 13 columns
     */
	void WriteRC( char c, int row, int col );

    /**
     * @brief Writes text to the screen one character after the last written character.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param str String to write
     */
    void Write( const char* str );

    /**
     * @brief Writes text to the screen one character after the last written character.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param i Integer to write
     */
    void Write( int i );

    /**
     * @brief Writes text to the screen one character after the last written character.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param f Float to write
     */
    void Write( float f );

    /**
     * @brief Writes text to the screen one character after the last written character.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param d Double to write
     */
    void Write( double d );

    /**
     * @brief Writes text to the screen one character after the last written character.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param b Boolean to write
     */
    void Write( bool b );

    /**
     * @brief Writes text to the screen one character after the last written character.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param c Character to write
     */
	void Write( char c );

    /**
     * @brief Writes text to the screen one character after the last written character and starts a new line.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param str String to write
     */
    void WriteLine( const char* str );

    /**
     * @brief Writes text to the screen one character after the last written character and starts a new line.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param i Integer to write
     */
    void WriteLine( int i );

    /**
     * @brief Writes text to the screen one character after the last written character and starts a new line.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param f Float to write
     */
    void WriteLine( float f );

    /**
     * @brief Writes text to the screen one character after the last written character and starts a new line.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param d Double to write
     */
    void WriteLine( double d );

    /**
     * @brief Writes text to the screen one character after the last written character and starts a new line.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param b Boolean to write
     */
    void WriteLine( bool b );

    /**
     * @brief Writes text to the screen one character after the last written character and starts a new line.
     * 
     * The color is set by SetFontColor(color)
     * 
     * @param c Character to write
     */
	void WriteLine( char c );
};

extern FEHLCD LCD;
#endif // FEHLCD_H