#include <stdio.h> // Required for standard input/output functions (printf, puts, fgets, scanf)
#include <string.h> // Required for string manipulation functions (strcspn)

// --- Constants ---
#define NAME_BUFFER_SIZE 100 // Maximum buffer size for user's name (including null terminator)
#define MAX_DIMENSION    80 // Maximum allowed dimension for ASCII art shapes

// --- Function Prototypes ---

/**
 * @brief Clears the standard input buffer
 * 
 * This function reads and discards characters from stdin until a newline character or EOF is encountered. It is useful after using scanf to prevent leftover characters (like newline) from affecting subsequent input operations (like fgets)
 */
static void clear_input_buffer(void);

/**
 * @brief prints a simple greeting message
 * 
 * This function demonstrates a basic modularity by encapsulating a common output operation
 */
static void simple_greet(void);

/**
 * @brief Prompts the user for their name and prints a personalized greeting
 * 
 * uses fgets for safe string input and includes basic input validation
 */
static void greet_user(void);

/**
 * @brief Prompts the user for shape dimensions and character, then draws the shape.
 * 
 * Allows for dynamic generation of solid or hollow rectangles
 * Includes extensive input validation
 */
static void draw_dynamic_shape(void);