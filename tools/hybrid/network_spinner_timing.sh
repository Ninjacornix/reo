#!/bin/sh
# Time the Network Game connecting screen (REO_COOP_FAST_NETWORK) for one player (GAME=file1|file2)
# against a local server already started with tools/hybrid/coop_server.py.
# usage: network_spinner_timing.sh EXE SESSION_DIR USERNAME [FAST_STEPS] [SECONDS]
#   FAST_STEPS: REO_NETWORK_FAST_STEPS for the game ("0" = nothing fast-forwarded, empty =
#   the game's default);
#   REO_NETWORK_JUMP / REO_NETWORK_FAST_FACTOR from the caller's environment are passed on.
# The memory card comes from build-ninja/hybrid/netflow/card-GAME when present (a returning
# player with a NET file). Prints the game's [NETWORK-FAST] lines.
set -e
exe=$1; S=$2; user=$3; steps=${4-0}; seconds=${5:-120}; game=${GAME:-file1}
rm -rf "$S"
python tools/coop_playtest/coop_playtest.py prepare --game "$game" --players 1 --session "$S" --exe "$exe" >/dev/null 2>&1
card=build-ninja/hybrid/netflow/card-$game
[ -d "$card" ] && cp -r "$card/." "$S/player1/card0/"
W=$(cygpath -w "$(pwd)/$S")
python -I - "$W" "$user" "$steps" <<'PYEOF'
import json, sys, os
S, user, steps = sys.argv[1:4]
cfg = {"environment": {"REO_COOP_HOST": "127.0.0.1", "REO_COOP_PLATFORM_AUTH": "native", "REO_COOP_TEST_INPUT": "1",
                       "REO_COOP_AUTO_ACCOUNT": "1", "REO_SKIP_INTRO": "1", "REO_COOP_FAST_NETWORK": "1",
                       "REO_NETWORK_JUMP": os.environ.get("REO_NETWORK_JUMP", ""),
                       "REO_NETWORK_FAST_FACTOR": os.environ.get("REO_NETWORK_FAST_FACTOR", "8")},
       "players": [{"environment": {"REO_COOP_USERNAME": user,
                                    "REO_COOP_ACCOUNT_STATUS": os.path.join(S, "player1", "account-status")}}]}
if steps:
    cfg["environment"]["REO_NETWORK_FAST_STEPS"] = steps
json.dump(cfg, open(os.path.join(S, "config.json"), "w"), indent=2)
PYEOF
python tools/coop_playtest/coop_playtest.py run --session "$S" --config "$S/config.json" --seconds "$seconds" > "$S/run-console.log" 2>&1 &
python -I tools/hybrid/coop_account_broker.py "$S" 1 "$((seconds - 5))" > "$S/broker.log" 2>&1 &
for i in $(seq 1 60); do sleep 1; grep -q "SKIP-INTRO\] main menu reached" "$S/player1/logs/stderr.log" 2>/dev/null && break; done
sleep 1.5
python tools/coop_playtest/coop_playtest.py input --session "$S" --player 1 --buttons down --hold 0.15 >/dev/null
sleep 0.8
python tools/coop_playtest/coop_playtest.py input --session "$S" --player 1 --buttons cross --hold 0.15 >/dev/null
wait
grep -hE "NETWORK-FAST" "$S/player1/logs/stderr.log" || true
