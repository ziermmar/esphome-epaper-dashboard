---
name: commit
description: Analyze changes and create a well-formatted conventional commit
user_invocable: true
---

# Conventional Commit Skill

Create a commit following the Conventional Commits specification.

## Steps

1. Run `git status` to see the current state of the working tree
2. Run `git diff --cached` to see staged changes. If nothing is staged, run `git diff` to see unstaged changes and inform the user they need to stage changes first (or offer to stage all changes)
3. Analyze the nature of the changes:
   - What files were modified, added, or deleted?
   - What is the logical grouping of changes?
   - Is this a feature, fix, refactor, docs, test, chore, ci, style, perf, or build change?
4. Determine the scope from the affected area (e.g., `display`, `sensors`, `fonts`, `ci`, `ha`, `wordclock`)
5. Check if this is a breaking change
6. Generate a commit message following this format:
type(scope): concise description in imperative mood

[optional body explaining WHAT changed and WHY]

[optional footer: BREAKING CHANGE: description]

7. Rules for the commit message:
- Subject line must be under 72 characters
- Use imperative mood ("add feature" not "added feature" or "adding feature")
- Do not end the subject line with a period
- The body should explain the motivation for the change, not just what changed
- Reference issue numbers if apparent from branch names or change context
8. Present the commit message to the user for approval
9. Create the commit with the approved message

## Commit Types
- `feat`: a new feature (new sensor, new display element, new translation)
- `fix`: a bug fix (wrong coordinate, missing icon mapping, broken sensor reference)
- `docs`: documentation only changes (README, comments)
- `style`: formatting, whitespace — no logic change
- `refactor`: code change that neither fixes a bug nor adds a feature
- `perf`: a code change that improves performance
- `test`: adding or updating tests / CI validation
- `build`: changes to build system or dependencies (requirements.txt, GitHub Actions)
- `ci`: changes to CI configuration files (.github/workflows/)
- `chore`: other changes (renovate config, gitignore, etc.)

## ESPHome-Specific Scope Examples
- `display` — changes to display_lambda.cpp layout or rendering
- `sensors` — adding/removing/modifying sensor definitions in YAML
- `ha` — Home Assistant template sensor configuration
- `fonts` — font definitions or glyph lists
- `wordclock` — wordclock.h logic
- `translate` — translate.h or mdi_icon.h lookup tables
- `ci` — GitHub Actions workflow changes
- `deps` — requirements.txt or renovate.json
