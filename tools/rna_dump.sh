#!/bin/bash
# usage: rna_dump.sh <pid>   -- dump PS2RNA records and their SJ objects (read-only)
P="C:/Users/Ninjacornix/ghidra-mcp/.venv/Scripts/python.exe"; G=/c/Users/Ninjacornix/reo/tools/guest_peek.py; E=/c/Users/Ninjacornix/reo/game_data/SLUS_207.65
pid=$1
out=$("$P" -I $G $pid $E 223880:384)
echo "$out"
# parse entries: 16 x 0x60 bytes = 24 words each
words=$(echo "$out" | grep "^0x00223880" | cut -d: -f2)
arr=($words)
for e in $(seq 0 15); do
  b=$((e*24)); w0=${arr[$b]}
  st=$(( (0x${arr[$((b+20))]} ) & 0xff ))  # +0x50 byte
  [ "$st" = "1" ] || continue
  echo "== entry $e state=1 words: ${arr[@]:$b:24}"
  for k in 2 3; do sj=${arr[$((b+k))]}; [ "$sj" = "00000000" ] && continue
    "$P" -I $G $pid $E ${sj}:16 | tail -1
    inner=$("$P" -I $G $pid $E $(printf "%x" $((0x$sj+8))):1 | tail -1 | awk '{print $2}')
    [ -n "$inner" ] && [ "$inner" != "00000000" ] && "$P" -I $G $pid $E ${inner}:24 | tail -1
  done
done
