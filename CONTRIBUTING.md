# Contributing

Contributions are welcome — bug reports, feature ideas, and pull requests all help.

## Setting up a local development environment

### 1. Clone the repository

```shell
git clone https://github.com/ziermmar/esphome-epaper-dashboard.git
cd esphome-epaper-dashboard
```

### 2. Create a virtual environment and install dependencies

```shell
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

### 3. Create `secrets.yaml`

Copy the template from the README and fill in your values. The file is gitignored and will never be committed.

### 4. Download the MDI font

```shell
mkdir -p fonts
curl -L -o fonts/materialdesignicons-webfont.ttf \
  https://github.com/Templarian/MaterialDesign-Webfont/raw/master/fonts/materialdesignicons-webfont.ttf
```

## Validating your changes

Run the ESPHome config validator before opening a pull request:

```shell
./validate.sh
```

CI runs the same check plus a full firmware build on every push and pull request. A passing CI build is required before merging.

## Project structure

| Path | Purpose |
|---|---|
| `dashboard-epaper.yaml` | Main ESPHome configuration — sensors, fonts, display platform |
| `includes/display_lambda.cpp` | Display rendering entry point — all draw calls go here |
| `includes/datetime.h` | Date and time formatting helpers |
| `includes/translate.h` | Weather state string translations |
| `includes/mdi_icon.h` | MDI icon mappings (HA state → Unicode code point) |
| `includes/wordclock.h` | German word clock logic |
| `home_assistant/` | Template sensor configuration to add to Home Assistant |
| `fonts/` | Font files (gitignored — download manually, see above) |

## Guidelines

- **Secrets:** Never hardcode credentials. Always use `!secret <name>` references and add new secrets to `secrets.yaml` only.
- **Sensor IDs:** Use `snake_case` for all component IDs in YAML.
- **C++ style:** Follow the conventions in `includes/` — `camelCase` for function names, `snake_case` for variables. Keep rendering lambdas allocation-free.
- **New weather states:** If you add a new HA weather state, add entries to both `translate.h` and `mdi_icon.h`.
- **Display coordinates:** Keep all coordinates within the 800×480 px display bounds. Coordinate errors only surface on hardware, so double-check your maths.
- **Header guards:** All new `.h` files must use `#ifndef`/`#define`/`#endif` guards.

## Reporting security issues

Please do not open public issues for security vulnerabilities. See [SECURITY.md](SECURITY.md) for the responsible disclosure process.
