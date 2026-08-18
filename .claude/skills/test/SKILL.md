---
name: test
description: Validate ESPHome configuration and run any available checks
user_invocable: true
---

# Test / Validate Skill

Validate this ESPHome project for correctness.

## Behavior

1. **Determine what to validate:**
   - If an argument is provided (a specific YAML file), validate that file
   - Default target: `dashboard-epaper.yaml`

2. **Run ESPHome config validation:**
   ```
   esphome config dashboard-epaper.yaml
   ```
   This validates YAML syntax, component references, and that all `id()` references are resolvable.

3. **If `esphome` is not installed locally**, inform the user and suggest:
   - Install with `pip install -r requirements.txt` — verify the installed ESPHome version matches what CI uses (check `.github/workflows/on_push.yml`) to avoid local/CI divergence
   - Or rely on CI — the GitHub Actions workflow builds and validates on every push

4. **Analyze results:**
   - If validation passes, report success
   - If validation fails:
     a. Read the error output carefully
     b. Identify the root cause (missing ID, invalid component config, YAML syntax error)
     c. Propose a fix
     d. Ask the user if they want to apply the fix
     e. After fixing, re-run validation to verify

5. **Additional checks to perform manually:**
   - Verify all entity IDs referenced in YAML match HA entities (requires HA access)
   - Check that all weather state strings in YAML match keys in `includes/translate.h` and `includes/mdi_icon.h`
   - Verify `secrets.yaml` exists locally with required keys: `api_key`, `ota_password`, `wifi_ssid`, `wifi_password`, `fallback_ssid`, `fallback_password`
   - Check that font file `fonts/materialdesignicons-webfont.ttf` exists (gitignored — must be downloaded locally; see README for instructions)

## Note on Testing
This project has no automated unit test suite — correctness is validated by:
1. `esphome config` (YAML + component validation)
2. CI build (full compilation check via GitHub Actions)
3. Visual verification on hardware after flashing

For display layout changes, the only definitive test is flashing to the device and observing the screen.
