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

static void draw_static_shapes(void) {
  printf("\n--- Section: Static ASCII Art ---\n");

  // Static Box
  puts("Static Box:");
  puts("*****");
  puts("*   *");
  puts("*****");
  printf("\n");

  // Static Pyramid (Height 5)
  puts("Static Pyramid (Height 5):");
  for (int i = 1; i <= 5; i++) {
    // Print leading spaces
    for (int j = 0; j < 5 - i; j++) {
      putchar(' ');
    }
    // Print Asterisks
    for (int k = 0; k < 2 * i -1; k++) {
      putchar('*');
    }
    putchar('\n'); // NewLine after each row
  }

}

static void draw_dynamic_shape(void) {
  printf("\n--- Section: Dynamic ASCII Art ---\n");
  int width, height;
  char symbol, solid_hollow_choice;
  int input_scan_count; // To check scanf return value

  // Get Width
  printf("Enter width for the shape (1-%d): ", MAX_DIMENSION);
  input_scan_count = scanf("%d", &width);
  if (input_scan_count != 1 || width <= 0 || width > MAX_DIMENSION) {
    printf("Invalid width. Skipping dynamic shape.\n");
    clear_input_buffer(); // Clear any remaining invalid input
    return;
  }
  clear_input_buffer(); // Clear the newline left by scanf

  // Get Height
  printf("Enter height for the shape (1-%d): ", MAX_DIMENSION);
  input_scan_count = scanf("%d", &height);
  if (input_scan_count != 1 || height <= 0 || height > MAX_DIMENSION) {
    printf("Invalid height. Skipping dynamic shape.\n");
    clear_input_buffer();
    return;
  }
  clear_input_buffer(); // clear the newline left by scanf

  // Get Symbol
  printf("Enter a character for the shape (e.g., * # $): ");
  input_scan_count = scanf(" %c", &symbol); // Space before %c to consume any leftover whitespace
  if (input_scan_count != 1) {
    printf("Invalid character input. Skipping Dynamic shape.\n");
    clear_input_buffer();
    return;
  }
  clear_input_buffer(); // Clear the newline left by scanf

  // Get Solid/Hollow choice
  printf("Draw solid or hollow shape? (s/h): ");
  input_scan_count = scanf(" %c", &solid_hollow_choice);
  if(input_scan_count != 1 || (solid_hollow_choice != 's' && solid_hollow_choice != 'h')) {
    printf("Invalid choice for solid/hollow. Drawing solid shape by default.\n");
    solid_hollow_choice = 's'; // Default to solid
  }
  clear_input_buffer(); // Clear the newline left by scanf

  printf("Drawing a %dx%d shape using '%c' (%s):\n",
  width, height, symbol, (solid_hollow_choice == 's' ? "Solid" : "Hollow"));

  for (int i = 0; i < height; i++) { // Rows
    for (int j = 0; j < width; j++) { // Columns
      if (solid_hollow_choice == 's' || // Solid shape
        i == 0 || i == height - 1 || // First or last row (for hollow)
        j == 0 || j == width - 1) { // First or last column (for hollow)
          putchar(symbol);
        } else {
          putchar(' '); // Inside of hollow shape
        }
    }
    putchar('\n'); // Newline after each row
  }
  
}