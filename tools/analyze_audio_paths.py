"""Summarize bounded per-voice PCM diagnostics; mixed signal is not proof of clean music.

Usage: python tools/analyze_audio_paths.py <stderr.log> [--out <json>]
Counters describe source PCM availability, not device glitches or listening quality.
"""
import argparse
import json
import re
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('log', type=Path)
parser.add_argument('--out', type=Path)
args = parser.parse_args()
voices = {}
for line in args.log.read_text(errors='replace').splitlines():
    if '[AUDIO-PATH] cri voice=' not in line:
        continue
    fields = dict(re.findall(r'(\w+)=(\w+)', line))
    key = fields['voice']
    row = voices.setdefault(key, dict(reports=0, active=0, valid=0, starved=0,
                                     skipped=0, nonzero_starvation_reports=0))
    row['frequency'] = int(fields['frequency'])
    row['channels'] = int(fields['channels'])
    row['reports'] += 1
    for dest, source in [('active', 'activeFrames'), ('valid', 'validFrames'),
                         ('starved', 'starvedFrames'), ('skipped', 'skippedSamples')]:
        row[dest] += int(fields[source])
    row['nonzero_starvation_reports'] += int(fields['starvedFrames']) != 0
for row in voices.values():
    row['starved_percent'] = 100 * row['starved'] / row['active'] if row['active'] else 0
result = dict(log=str(args.log.resolve()), voices=voices,
              scope='Bounded PCM source diagnostics only; excludes unsampled time and device output quality.')
text = json.dumps(result, indent=2)
if args.out:
    args.out.write_text(text)
print(text)
