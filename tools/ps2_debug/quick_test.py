#!/usr/bin/env python3
"""
Quick connectivity test for PCSX2 Pine IPC.
Run this while PCSX2 has a game running with Pine IPC enabled.
"""
import sys
import os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pine_client import PineClient, PineError

print("=== PCSX2 Pine IPC Quick Test ===")
print("Connecting to localhost:28011...")

client = PineClient()
try:
    client.connect(timeout=5.0, retries=2)
except PineError as e:
    print(f"\nCannot connect: {e}")
    print("\nChecklist:")
    print("  1. Is PCSX2 running?")
    print("  2. Is a game loaded?")
    print("  3. Is Pine IPC enabled?")
    print("     -> Settings -> Advanced -> Enable Pine IPC")
    print("     -> Slot should be 28011")
    sys.exit(1)

print("Connected!\n")

tests = [
    ("Version",  lambda: client.version()),
    ("Title",    lambda: client.title()),
    ("Game ID",  lambda: client.game_id()),
]

for name, fn in tests:
    try:
        result = fn()
        print(f"  {name:12s}: {result}")
    except PineError as e:
        print(f"  {name:12s}: ERROR ({e})")

# Test memory read
print()
test_addrs = [0x00100000, 0x00100008, 0x003445E8]
for addr in test_addrs:
    try:
        val = client.read32(addr)
        print(f"  RAM[0x{addr:08X}] = 0x{val:08X}")
    except PineError as e:
        print(f"  RAM[0x{addr:08X}] = ERROR ({e})")

client.close()
print("\nAll tests passed!")
