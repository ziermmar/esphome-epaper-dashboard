# ESPHome Rules

## YAML Configuration
- Keep all secrets in `secrets.yaml` (gitignored) — always use `!secret <name>` references in YAML
- Use `snake_case` for all component IDs (e.g., `id: display_last_update`)
- Place complex logic in `includes/` C++ files and reference via `!include` or the `includes:` block
- Group related sensors together (all HA sensors in one block, all template sensors together)
- Use `entity_category: "diagnostic"` for status/debug sensors not shown in the main HA dashboard
- Use `internal: true` for components (switches, sensors) that should not be exposed to HA

## C++ Headers and Lambdas
- Keep `display_lambda.cpp` as the single rendering entry point — all draw calls go here
- Define helper functions (date formatting, translations, icon mapping) in separate `.h` files under `includes/`
- Use `#ifndef`/`#define`/`#endif` include guards in all header files
- Use `std::map<std::string, std::string>` for lookup tables (translations, icon mappings)
- Coordinate strings must match the ESPHome `text_sensor` state values exactly (e.g., `"partlycloudy"` not `"partly-cloudy"`)
- Check for `isnan()` before rendering float sensor values that may be unavailable

## Display Layout
- Display resolution is 800×480 px — keep all coordinates within bounds
- Use `TextAlign::CENTER_HORIZONTAL` for centered text, `TextAlign::TOP_LEFT`/`TOP_RIGHT` for aligned blocks
- Group related UI elements with consistent Y-coordinate offsets
- Test layout changes in CI before flashing to device — coordinate errors only appear on hardware

## Home Assistant Integration
- All sensor entity IDs in `dashboard-epaper.yaml` must match real HA entity IDs exactly
- Use `on_value` lambdas on sensor platforms to set `data_updated = true` for relevant sensors
- Weather state strings from HA (e.g., `"sunny"`, `"partlycloudy"`) must have entries in both `translate.h` and `mdi_icon.h`
- Template sensors defined in `home_assistant/home-assistant-configuration.yaml` must be manually added to HA config

## Fonts
- Fonts in `fonts/` are gitignored — document download instructions for new contributors
- Define glyphs explicitly — only include characters actually used to minimize binary size
- Use YAML anchors (`&umlaut-glyphs`, `*umlaut-glyphs`) to reuse glyph lists across font sizes
- MDI font glyphs are referenced by Unicode code point — verify against pictogrammers.com

## Secrets and Security
- Never commit `secrets.yaml` — it is gitignored
- Never hardcode WiFi credentials, API keys, or OTA passwords in YAML
- API encryption key must be present for HA native API connection

## CI/CD
- The `on_push.yml` workflow triggers on push to `main` and on pull requests
- CI validates and builds the firmware — a passing CI build confirms the YAML + C++ compiles correctly
- Pre-built binaries are published to GitHub Pages for easy flashing via ESPHome web installer
