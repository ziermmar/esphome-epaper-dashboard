# C++ Rules (ESPHome Headers)

## Style
- Use `snake_case` for variables and function parameters
- Use `camelCase` for function names (matching existing codebase: `getGermanDate`, `getTimeInWords`) — this mixed convention is intentional; do not unify to one style
- Use `UPPER_SNAKE_CASE` for constants and macros
- Always include header guards (`#ifndef`/`#define`/`#endif`)

## Includes and Dependencies
- Do not include standard library headers directly — ESPHome's build system provides them
- Use `std::string`, `std::map`, `std::vector` — they are available in the ESPHome Arduino environment
- Avoid heap allocations in rendering lambdas (called frequently); prefer stack-allocated strings

## Error Handling
- Always check `isnan(sensor.state)` before rendering float values — HA sensors can be unavailable
- Use `c_str()` when passing `std::string` to `printf`-style functions
- Do not use exceptions — the Arduino environment does not support them

## Map Lookups
- Use `.c_str()` when indexing `std::map<std::string, std::string>` with a sensor state value
- Be aware that `operator[]` on a map inserts a default entry if the key is missing — prefer `.count()` check or `.at()` with a fallback when the key may be absent
- Weather state strings from HA must exactly match map keys — differences in hyphenation matter (e.g., `"partlycloudy"` vs `"partly-cloudy"`)

## Display Lambda Conventions
- The display object is available as `it` inside lambdas
- Fonts are referenced by ID (e.g., `id(small)`, `id(font_mdi_large)`)
- Sensor states: numeric via `.state` (float), text via `.state.c_str()` (string)
- All coordinate values are in pixels; origin is top-left corner of the display

## Naming
- Header files: `snake_case.h` (e.g., `mdi_icon.h`, `datetime.h`)
- Map variables: descriptive noun (e.g., `translate`, `mdi_icon`)
- Function names: verb + noun describing the return value (e.g., `getGermanDate`, `getTimeInWords`)
