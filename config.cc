export module config;

import <cstdlib>;

export namespace config {
  // How many rows do you want to generate?
  const size_t rowNum = 100;

  const char *femaleNames[] = {
      "Alice",  "Barbora",  "Dagmar",   "Eva",   "Frida",  "Hanna",
      "Ingrid", "Johanna",  "Katarina", "Lena",  "Maria",  "Nina",
      "Olga",   "Pia",      "Quinn",    "Rita",  "Sandra", "Tania",
      "Ursula", "Viktoria", "Wilma",    "Xenia",
  };

  const char *femaleSurnames[] = {
      "Ludvíková",   "Kovács",        "Pácz",    "Hajdár",     "Šulcová",
      "Procházková", "Kratochvílová", "Hůrková", "Kašparová",  "Králová",
      "Machová",     "Michnová",      "Němcová", "Novotná",    "Pokorná",
      "Pospíšilová", "Svitáčková",    "Vachová", "Závadilová",
  };

  const char *maleNames[] = {
      "Alexander", "Benjamin",  "Daniel", "Erik",   "Filip",     "Gabriel",
      "Harri",     "Igor",      "Jakub",  "Kamil",  "Luka",      "Marek",
      "Michal",    "Nikolas",   "Ondrej", "Patrik", "Rastislav", "Samuel",
      "Tobias",    "Vladislav", "Xaver",  "Yannik",
  };

  const char *maleSurnames[] = {
      "Svátek",
      "Kovács",
      "Pácz",
      "Hajdár",
      "Novák",
      "Havel",
      "Veselý",
      "Jílek",
      "Svátek",
      "Holoubek",
      "Kratochvíl",
      "Kubík",
      "Pospíšil",
      "Svitáček",
      "Závadil",
      "Králík",
      "Trávník",
      "Beneš",
  };

  const char *domains[] = {
      "gmail.com",
      "yahoo.com",
      "hotmail.com",
      "aol.com",
      "mail.com",
  };

  // Prefix is the part of the email before the @ sign
  const size_t emailPrefixLength = 10;

  const size_t minYear = 1900;

  const size_t maxYear = 2005;

  const size_t minMonth = 1;

  const size_t maxMonth = 12;

  const size_t minDay = 1;

  const size_t maxDay = 28;

  const size_t nationalIdLength = 10;

  const size_t applicantIdLength = 8;

  constexpr size_t maleNameCount = sizeof(maleNames) / sizeof(maleNames[0]);

  constexpr size_t maleSurnameCount =
      sizeof(maleSurnames) / sizeof(maleSurnames[0]);

  constexpr size_t femaleNameCount =
      sizeof(femaleNames) / sizeof(femaleNames[0]);

  constexpr size_t femaleSurnameCount =
      sizeof(femaleSurnames) / sizeof(femaleSurnames[0]);

  constexpr bool onlyHasMales = femaleNameCount == 0;

  constexpr bool onlyHasFemales = maleNameCount == 0;

  constexpr bool onlyHasNames = (onlyHasMales && !maleSurnameCount) ||
                                (onlyHasFemales && !femaleSurnameCount) ||
                                (!maleSurnameCount && !femaleSurnameCount);

  constexpr bool onlyHasSurnames = (onlyHasMales && !maleNameCount) ||
                                   (onlyHasFemales && !femaleNameCount) ||
                                   (!maleNameCount && !femaleNameCount);

  constexpr size_t domainCount = sizeof(domains) / sizeof(domains[0]);

  static_assert(minYear <= maxYear,
                "Min year must be less or equal to max year");

  static_assert(maxYear <= 9999,
                "Max year must be less or equal to maximum allowed year");

  static_assert(minMonth > 0, "Min month must be positive");

  static_assert(minMonth <= maxMonth,
                "Min month must be less or equal to max month");

  static_assert(maxMonth <= 12,
                "Max month must be less or equal to max allowed month");

  static_assert(minDay > 0, "Min day must be positive");

  static_assert(minDay <= maxDay, "Min day must be less or equal to max day");

  // max allowed day is 28 in order not to account for leap years and different
  // number of days in months
  static_assert(maxDay <= 28,
                "Max day must be less or equal to max allowed day");

  static_assert(nationalIdLength > 0, "National ID length must be positive");

  static_assert(applicantIdLength > 0, "Applicant ID length must be positive");
}; // namespace config