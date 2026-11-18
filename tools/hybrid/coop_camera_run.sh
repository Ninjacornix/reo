set -e
cd /c/Users/Ninjacornix/reo
B=tools/hybrid
S=build-ninja/hybrid/coop/$1; TAG=$2
python tools/coop_playtest/coop_playtest.py prepare --game file2 --players 2 --session $S --exe build-ninja/hybrid/file2-ready-v1/reo_recomp.exe | tail -1
W=$(cygpath -w $(pwd)/$S)
python -I - "$W" "$TAG" <<'PY'
import json,sys,os
S,tag=sys.argv[1],sys.argv[2]
def p(n,extra):
    e={"REO_COOP_USERNAME":f"{tag}{n}","REO_COOP_ACCOUNT_STATUS":os.path.join(S,f"player{n}","account-status"),
       "REO_COOP_TRACE_FILE":os.path.join(S,f"player{n}","network.jsonl")}
    e.update(extra);return {"environment":e}
cfg={"environment":{"REO_COOP_HOST":"127.0.0.1","REO_COOP_PLATFORM_AUTH":"native","REO_COOP_TEST_INPUT":"1",
     "REO_TEST_ROUTE":"network-auto","REO_COOP_AUTO_ACCOUNT":"1","REO_NET_TRACE":"1"},
     "players":[p(1,{"REO_NATIVE_ROOM_CAMERA":"1","REO_CAMERA_MOD":"tps","REO_CAMERA_MOUSE":"0","REO_CAMERA_TPS_LOG":"1"}),p(2,{})]}
json.dump(cfg,open(os.path.join(S,"config.json"),"w"),indent=2)
PY
python tools/coop_playtest/coop_playtest.py run --session $S --config $S/config.json --seconds 900 > $S/run-console.log 2>&1 &
python -I $B/coop_account_broker.py $S 2 180
python tools/coop_playtest/coop_playtest.py drive-lobby --session $S --goal waiting-room --timeout 300 --press-limit 100 > $S/drive-lobby.log 2>&1 || true
python -I -c "import json;d=json.load(open('$S/drive-lobby-waiting-room.json'));print('lobby',d['driverVerdict'])"
python tools/coop_playtest/coop_playtest.py drive-start --session $S --timeout 300 > $S/drive-start.log 2>&1 || true
python -I -c "import json;d=json.load(open('$S/drive-start.json'));print('start',d['driverVerdict'],d.get('allInGameplay'))"
sleep 3
python -I $B/coop_actor_probe.py $S
