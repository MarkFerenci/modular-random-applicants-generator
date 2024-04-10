# Random applicant data generator version with C++20 modules

This program generates random applicant data such as names, surnames, email addresses, and dates. It utilizes random number generation to create realistic-looking applicant information.

## Functions

### printRandomNumericString(size_t len)

Prints a random numeric string of the specified length to the stdout.

### generateRandomInteger(int min, int max)

Generates a random integer within the specified range.

## printRandomDateString()

Prints a randomly generated date string in the format "dd.mm.yyyy" to the stdout.

## printRandomEmail()

Prints a random email address to the stdout.

## printName(bool isMale)

Prints a random applicant name to the stdout.

## printSurname(bool isMale)

Prints a random applicant surname to the stdout.

## printApplicant(const char *name, const char *surname)

Prints a randomly generated applicant information row to the stdout.

## main()

The main function of the program that seeds the random number generator, generates applicant data for both female and male names, and prints the applicant details.

## Usage
To use this program, simply compile and run the executable. It will generate random applicant data based on the defined functions.

## Dependencies
This program requires the standard library headers `<cassert>`, `<cstdio>`, `<cstdlib>`, `<ctime>` as modules and a custom module `config` where configuration of the generator is stored.

## Compile
Compilation tested with clang++ 17.0.6 on Linux

```
cmake .
make
```

## Launch
After compiling, execute the program by running the generated executable:
`./generator`

## Configuration

Configuration is performed in the module `config.cc`

It is possible to set which female and male names and surnames as well as email domains are used by the generator by directly editing the corresponding arrays.

In order for the changes to take effect, you need to recompile the program.