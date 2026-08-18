---
name: review
description: Perform a thorough code review of staged changes or a specific file/directory
user_invocable: true
---

# Code Review Skill

Perform a detailed code review for this ESPHome e-paper dashboard project.

## Input
- If no argument is provided, review all staged changes (`git diff --cached`)
- If a file or directory path is given as argument, review that path
- If a branch name is given, review changes between that branch and HEAD: `git diff <branch>...HEAD`

## Review Process

1. **Gather the changes**: Read the diff or the specified files
2. **Understand context**: Read surrounding code to understand how the changes fit
3. **Review for the following categories**:

### Correctness
- Logic errors in C++ helpers (off-by-one in time calculations, modulo errors in wordclock)
- Sensor ID references in YAML matching actual HA entity IDs
- `isnan()` checks before rendering float sensor values
- Map key strings matching HA weather state values exactly (hyphenation, casing)
- Display coordinates within 800×480 bounds
- Missing `\U` prefix on MDI icon Unicode strings in mdi_icon.h

### Security
- Secrets referenced via `!secret` — never hardcoded values in YAML
- No API keys, WiFi passwords, or OTA passwords committed to repository
- OTA password protected (not left as empty string)

### ESPHome Specifics
- All `id()` references in lambdas match defined component IDs in YAML
- `on_value` triggers set `data_updated = true` for sensors that should trigger refresh
- Font glyph lists include all characters actually used in display output
- `entity_category` set appropriately for diagnostic vs user-facing sensors
- `internal: true` on components not intended to be exposed to Home Assistant

### C++ Header Quality
- Include guards present in all `.h` files
- No missing `c_str()` calls when passing `std::string` to `printf`-style functions
- Map lookups handle missing keys gracefully (weather states not in translation/icon maps)

### Home Assistant Integration
- Template sensor YAML in `home_assistant/` is valid HA template syntax
- Entity IDs in HA config match what is referenced in ESPHome YAML
- Forecast array indices match documented intent (H1=[0], H2=[1], H3=[2])

### Code Quality
- Display lambda not excessively long — extract helper functions if needed
- Duplicated coordinate constants extracted to named variables
- Commented-out code blocks intentional and documented (not accidental dead code)

### CI/CD
- GitHub Actions workflow syntax valid
- Secrets referenced in workflow exist in repository settings
- Build matrix covers the intended hardware targets

## Output Format

Present findings grouped by severity:

**Critical** — Must fix before merging (broken builds, secret exposure, wrong entity IDs)
**Warning** — Should fix (missing nan checks, map key mismatches, out-of-bounds coordinates)
**Suggestion** — Nice to have (code quality improvements, extract helper functions)
**Praise** — Good patterns worth highlighting

For each finding, include:
- File and line reference
- What the issue is
- Why it matters
- A suggested fix (with code snippet when helpful)
