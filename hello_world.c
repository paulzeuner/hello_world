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

// --- Function Implementations ---

static void clear_input_buffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

static void simple_greet(void) {
  puts("Hello from a modular helper function!");
}

static void print_basic_greetings(void) {
  printf("\n--- Section: Basic Greetings ---\n");

  // Using printf for simple output
  printf("Hello, World!\n");

  // Using puts for simple string output (automatically adds newline)
  puts("Hello, C Programmers!");

  // printf with multiple lines and tabs (escape sequences)
  printf("Hello,\n\tWorld!\n");

  // Combining printf and puts
  printf("This is output from printf. ");
  puts("And this is from puts.");

  // Calling a helper function;
  simple_greet();
}

static void greet_user(void) {
  printf("\n--- Section: Interactive Greeting ---\n");
  char name[NAME_BUFFER_SIZE];

  printf("Enter your name (up to %d characters): ", NAME_BUFFER_SIZE - 1);

  // Use fgets for safe string input. It reads up to N-1 chars or until newline/EOF
  // It includes the newline character if there's space
  if (fgets(name, sizeof(name), stdin) == NULL) {
    perror("Error reading name");
    return; // Exit function on input error
  }

  // Remove the trailing newline character that fgets might have included
  // strcspn finds the first occurrence of a character from the second argument
  // If '\n' is found, replace it with '\0' (null terminator)

  name[strcspn(name, "\n")] = '\0';

  // Check if the input was empty (only newline or EOF was entered)
  if (name[0] == '\0') {
    printf("No name entered. Proceeding with a generic greeting.\n");
  } else {
    printf("Hello, %s!\n", name);
  }
}