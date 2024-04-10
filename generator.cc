import <cassert>;
import <cstdio>;
import <cstdlib>;
import <ctime>;

import config;

void
printRandomNumericString(size_t len) {
  static const char characters[] = "0123456789";

  static constexpr size_t maxIndex = (sizeof(characters) - 1);

  for (size_t i = 0; i < len; ++i) {
    // Compared to printf std::putchar does not need to parse the format string
    std::putchar(characters[std::rand() % maxIndex]);
  }
}

int
generateRandomInteger(const int min, const int max) {
  assert(min <= max && "min must be less or equal to max");

  return std::rand() % (max - min + 1) + min;
}

void
printRandomDateString() {
  const int day = generateRandomInteger(config::minDay, config::maxDay);
  const int month = generateRandomInteger(config::minMonth, config::maxMonth);
  const int year = generateRandomInteger(config::minYear, config::maxYear);

  // C-style printing is used because of the easiness of formating compared to
  // iomanip
  std::printf("%02d.%02d.%04d", day, month, year);
}

void
printRandomEmail() {
  printRandomNumericString(config::emailPrefixLength);
  std::putchar('@');

  const char *domain = config::domains[std::rand() % config::domainCount];
  std::fputs(domain, stdout);
}

void
printName(bool isMale) {
  const char **names = isMale ? config::maleNames : config::femaleNames;

  const size_t nameCount =
      isMale ? config::maleNameCount : config::femaleNameCount;

  std::fputs(names[std::rand() % nameCount], stdout);
}

void
printSurname(bool isMale) {
  const char **surnames =
      isMale ? config::maleSurnames : config::femaleSurnames;

  const size_t surnameCount =
      isMale ? config::maleSurnameCount : config::femaleSurnameCount;

  std::fputs(surnames[std::rand() % surnameCount], stdout);
}

void
printApplicant() {
  bool isMale;

  if constexpr (config::onlyHasMales) {
    isMale = true;
  } else if constexpr (config::onlyHasFemales) {
    isMale = false;
  } else {
    isMale = std::rand() % 2;
  }

  if constexpr (!config::onlyHasSurnames) {
    printName(isMale);
    std::putchar(';');
  }

  if constexpr (!config::onlyHasNames) {
    printSurname(isMale);
    std::putchar(';');
  }

  // This random numeric string represents applicant national ID
  printRandomNumericString(config::nationalIdLength);
  std::putchar(';');

  printRandomDateString();
  std::putchar(';');

  printRandomEmail();
  std::putchar(';');

  // This random numeric string represents applicant ID
  printRandomNumericString(config::applicantIdLength);
  std::putchar('\n');
}

int
main() {
  // Seed the pseudo random number generator
  std::srand(std::time(nullptr));

  for (size_t i = 0; i < config::rowNum; ++i) {
    printApplicant();
  }

  return 0;
}