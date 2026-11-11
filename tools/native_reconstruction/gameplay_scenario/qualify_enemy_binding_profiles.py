"""Reproduce initialized File #1 enemy binding policy and timer tables."""
import argparse
import hashlib
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[3]
OUTPUT = ROOT / 'game/native/gameplay_world/enemy_binding_profiles.inc'


def generate():
    raw = (ROOT / 'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(raw).hexdigest() == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    lines = ['// Initialized File #1 enemy binding tables. Reproduce with qualify_enemy_binding_profiles.py.']
    tables = [
        ('enemy_score_masks_one', 0x72b170, 'I', 8, 'std::uint32_t'),
        ('enemy_score_masks_two', 0x72b190, 'I', 8, 'std::uint32_t'),
        ('enemy_distance_bits', 0x72b1b0, 'I', 8, 'std::uint32_t'),
        ('enemy_initial_timers', 0x72bc20, 'h', 64, 'std::int16_t'),
        ('enemy_frame_timers', 0x72bca0, 'h', 64, 'std::int16_t'),
        ('enemy_class_flags', 0x72be20, 'B', 62, 'std::uint8_t'),
        ('enemy_body_priorities', 0x734640, 'B', 62, 'std::uint8_t'),
        ('offline_enemy_body_priorities', 0x734690, 'B', 62, 'std::uint8_t'),
        ('controlled_body_priorities', 0x7346d8, 'B', 8, 'std::uint8_t'),
    ]
    for name, address, code, count, kind in tables:
        values = struct.unpack_from('<' + str(count) + code, raw, address - 0x570000)
        lines.append('constexpr std::array<' + kind + ',' + str(count) + '> ' + name + '{{')
        for start in range(0, count, 8):
            lines.append('    ' + ','.join(map(str, values[start:start+8])) + ',')
        lines.append('}};')
    return '\n'.join(lines) + '\n'


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--write', action='store_true')
    arguments = parser.parse_args()
    expected = generate()
    if arguments.write:
        OUTPUT.write_text(expected, encoding='utf-8')
    assert OUTPUT.read_text(encoding='utf-8') == expected
    print(OUTPUT.name, hashlib.sha256(OUTPUT.read_bytes()).hexdigest())
