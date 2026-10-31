#!/bin/zsh
set -eu
cd "$(dirname "$0")"
if (( $# )); then
    exec python3 tools/macos/play.py "$@"
fi
reo_launcher="$PWD/build-macos/common-launcher/RE Outbreak RC1.app"
if [[ -d "$reo_launcher" ]]; then
    exec /usr/bin/open "$reo_launcher"
fi
print -u2 'Build the shared RC1 launcher with: python3 tools/launcher/package.py'
exit 1
