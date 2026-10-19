# Contributing

Start with a small change and a reproducible problem. File #1 gameplay and
native co-op are active work. Four-client local movement is verified; item/door
interactions, reconnects and LAN/WAN testing remain open. File #2 is a placeholder.

## Setup and validation

- Follow [the build guide](docs/BUILDING.md). Supply your own game data locally.
- Check Git status before editing. Keep generated sources and third-party changes separate from handwritten code.
- Run the smallest relevant test. Launcher changes use `launcher/build.ps1` and the launcher's `--self-test` command. Runtime and graphics checks are listed in [tools/README.md](tools/README.md).
- Apply `.clang-format` to changed project-owned C/C++ and C#. Use `.editorconfig` for other files. Preserve include order and dependency notices.

Run `python tools/format_code.py` to check project-owned C/C++ and C#, or add
`--write` to format them. It respects `.clang-format-ignore`, generated-file
exclusions and vendored code. Dependency changes follow [the patch workflow](third_party/patches/README.md).

Run `python tools/check_repository.py` before committing publication changes. It checks the current index, not Git history or ownership rights.

## Pull requests

Explain the problem, resulting behavior, and validation. Include platform, build settings, and game revision when relevant. Distinguish measured results from expectations. Keep formatting-only changes separate from behavioral fixes.

Comments should explain an invariant, hardware rule, or non-obvious decision. Avoid narrating straightforward statements. Retain copyright, license notices, and correctness explanations.

Do not submit discs, BIOS files, extracted assets, generated game code, memory dumps, saves, private handoffs, or credentials. Use synthetic fixtures and redact local paths from logs. Contributions must be yours to submit and compatible with GPL-3.0-only; retain the original license on imported work.
