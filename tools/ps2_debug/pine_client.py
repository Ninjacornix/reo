"""
PCSX2 Pine IPC Client

Pure Python implementation of the Pine (Protocol for Instrumentation of
Emulators) IPC protocol. Connects to a running PCSX2 instance and provides:

  - Memory read/write (8/16/32/64 bit)
  - Save/load state
  - Game title query
  - Emulator version query

No external dependencies required — uses only Python stdlib.

Usage:
    from pine_client import PineClient

    client = PineClient()
    client.connect()

    # Read 32-bit value from PS2 RAM
    value = client.read32(0x003445E8)

    # Write 32-bit value
    client.write32(0x003445E8, 0x00000001)

    # Dump memory region
    data = client.read_bytes(0x00100000, 1024)

    client.close()

Pine IPC Protocol (as implemented in PCSX2):
    Socket: TCP localhost:28011 (Windows) or Unix /tmp/pcsx2.sock (Linux)

    Request format:
        uint32_t size       (little-endian, total packet size including this field)
        uint8_t  command[]  (one or more commands, batched)

    Each command:
        uint8_t  opcode
        [command-specific payload]

    Response format:
        uint32_t size
        uint8_t  status     (0 = OK)
        [response data per command]

Enable in PCSX2: Settings → Advanced → Enable Pine IPC (slot 28011)
"""

import socket
import struct
import time
import sys
from typing import Optional, Union


class PineError(Exception):
    """Pine IPC protocol error."""
    pass


class PineClient:
    """Client for PCSX2's Pine IPC protocol."""

    # Pine IPC opcodes (from PCSX2 PINE.h)
    MSG_READ8      = 0
    MSG_READ16     = 1
    MSG_READ32     = 2
    MSG_READ64     = 3
    MSG_WRITE8     = 4
    MSG_WRITE16    = 5
    MSG_WRITE32    = 6
    MSG_WRITE64    = 7
    MSG_VERSION    = 8
    MSG_SAVE_STATE = 9
    MSG_LOAD_STATE = 10
    MSG_TITLE      = 11
    MSG_ID         = 12
    MSG_UUID       = 13
    MSG_GAME_VERSION = 14
    MSG_STATUS     = 15
    MSG_UNIMPLEMENTED = 0xFF

    # Response status
    IPC_OK    = 0
    IPC_FAIL  = 0xFF

    def __init__(self, host: str = "127.0.0.1", port: int = 28011):
        self.host = host
        self.port = port
        self.sock: Optional[socket.socket] = None
        self.connected = False

    def connect(self, timeout: float = 5.0, retries: int = 3) -> bool:
        """Connect to PCSX2's Pine IPC server."""
        for attempt in range(retries):
            try:
                self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                self.sock.settimeout(timeout)
                self.sock.connect((self.host, self.port))
                self.connected = True
                return True
            except (ConnectionRefusedError, socket.timeout, OSError) as e:
                if attempt < retries - 1:
                    time.sleep(1.0)
                else:
                    raise PineError(
                        f"Cannot connect to PCSX2 Pine IPC at {self.host}:{self.port}\n"
                        f"Make sure PCSX2 is running with Pine IPC enabled:\n"
                        f"  Settings > Advanced > Enable Pine IPC (slot {self.port})"
                    ) from e
        return False

    def close(self):
        """Disconnect from PCSX2."""
        if self.sock:
            try:
                self.sock.close()
            except OSError:
                pass
            self.sock = None
            self.connected = False

    def _send_command(self, opcode: int, payload: bytes = b"") -> bytes:
        """Send a single IPC command and return the response data."""
        if not self.connected or not self.sock:
            raise PineError("Not connected to PCSX2")

        # Build packet: size(4) + opcode(1) + payload
        cmd = struct.pack("<B", opcode) + payload
        packet = struct.pack("<I", len(cmd) + 4) + cmd

        try:
            self.sock.sendall(packet)

            # Read response: size(4) first
            header = self._recv_exact(4)
            resp_size = struct.unpack("<I", header)[0]

            # Read remaining response data
            if resp_size > 4:
                data = self._recv_exact(resp_size - 4)
            else:
                data = b""

            # First byte of response data is status
            if len(data) > 0:
                status = data[0]
                if status != self.IPC_OK:
                    raise PineError(f"IPC command 0x{opcode:02X} failed (status={status})")
                return data[1:]  # Return data after status byte
            return b""

        except socket.timeout:
            raise PineError("IPC command timed out")
        except (ConnectionResetError, BrokenPipeError):
            self.connected = False
            raise PineError("Connection to PCSX2 lost")

    def _recv_exact(self, size: int) -> bytes:
        """Receive exactly `size` bytes from the socket."""
        data = b""
        while len(data) < size:
            chunk = self.sock.recv(size - len(data))
            if not chunk:
                raise PineError("Connection closed by PCSX2")
            data += chunk
        return data

    # ── Memory read operations ──────────────────────────────

    def read8(self, addr: int) -> int:
        """Read an 8-bit value from PS2 memory."""
        resp = self._send_command(self.MSG_READ8, struct.pack("<I", addr))
        return struct.unpack("<B", resp[:1])[0]

    def read16(self, addr: int) -> int:
        """Read a 16-bit value from PS2 memory."""
        resp = self._send_command(self.MSG_READ16, struct.pack("<I", addr))
        return struct.unpack("<H", resp[:2])[0]

    def read32(self, addr: int) -> int:
        """Read a 32-bit value from PS2 memory."""
        resp = self._send_command(self.MSG_READ32, struct.pack("<I", addr))
        return struct.unpack("<I", resp[:4])[0]

    def read64(self, addr: int) -> int:
        """Read a 64-bit value from PS2 memory."""
        resp = self._send_command(self.MSG_READ64, struct.pack("<I", addr))
        return struct.unpack("<Q", resp[:8])[0]

    def read_bytes(self, addr: int, size: int) -> bytes:
        """Read a block of bytes from PS2 memory (uses repeated read32)."""
        data = bytearray()
        # Read in 4-byte chunks
        for offset in range(0, size, 4):
            remaining = min(4, size - offset)
            val = self.read32(addr + offset)
            data.extend(struct.pack("<I", val)[:remaining])
        return bytes(data)

    # ── Memory write operations ─────────────────────────────

    def write8(self, addr: int, value: int):
        """Write an 8-bit value to PS2 memory."""
        self._send_command(self.MSG_WRITE8,
                          struct.pack("<IB", addr, value & 0xFF))

    def write16(self, addr: int, value: int):
        """Write a 16-bit value to PS2 memory."""
        self._send_command(self.MSG_WRITE16,
                          struct.pack("<IH", addr, value & 0xFFFF))

    def write32(self, addr: int, value: int):
        """Write a 32-bit value to PS2 memory."""
        self._send_command(self.MSG_WRITE32,
                          struct.pack("<II", addr, value & 0xFFFFFFFF))

    def write64(self, addr: int, value: int):
        """Write a 64-bit value to PS2 memory."""
        self._send_command(self.MSG_WRITE64,
                          struct.pack("<IQ", addr, value & 0xFFFFFFFFFFFFFFFF))

    # ── Emulator control ────────────────────────────────────

    def save_state(self, slot: int = 0):
        """Save emulator state to slot."""
        self._send_command(self.MSG_SAVE_STATE,
                          struct.pack("<B", slot))

    def load_state(self, slot: int = 0):
        """Load emulator state from slot."""
        self._send_command(self.MSG_LOAD_STATE,
                          struct.pack("<B", slot))

    # ── Info queries ────────────────────────────────────────

    def version(self) -> str:
        """Get PCSX2 version string."""
        resp = self._send_command(self.MSG_VERSION)
        # Response is a null-terminated string
        return resp.rstrip(b"\x00").decode("utf-8", errors="replace")

    def title(self) -> str:
        """Get current game title."""
        resp = self._send_command(self.MSG_TITLE)
        return resp.rstrip(b"\x00").decode("utf-8", errors="replace")

    def game_id(self) -> str:
        """Get current game ID (e.g., SLUS-20765)."""
        resp = self._send_command(self.MSG_ID)
        return resp.rstrip(b"\x00").decode("utf-8", errors="replace")

    def game_uuid(self) -> str:
        """Get current game UUID."""
        resp = self._send_command(self.MSG_UUID)
        return resp.rstrip(b"\x00").decode("utf-8", errors="replace")

    def status(self) -> int:
        """Get emulator status."""
        resp = self._send_command(self.MSG_STATUS)
        if len(resp) >= 4:
            return struct.unpack("<I", resp[:4])[0]
        return -1


# ── Convenience functions ────────────────────────────────────

def wait_for_pcsx2(host="127.0.0.1", port=28011, timeout=60) -> PineClient:
    """Wait for PCSX2 to start and connect via Pine IPC."""
    print(f"Waiting for PCSX2 Pine IPC on {host}:{port}...")
    start = time.time()
    while time.time() - start < timeout:
        try:
            client = PineClient(host, port)
            client.connect(timeout=2.0, retries=1)
            ver = client.version()
            title = client.title()
            print(f"Connected to PCSX2 {ver}")
            if title:
                print(f"Game: {title}")
            return client
        except PineError:
            time.sleep(1.0)
    raise PineError(f"Timed out waiting for PCSX2 after {timeout}s")


if __name__ == "__main__":
    # Quick connectivity test
    try:
        client = wait_for_pcsx2(timeout=10)
        print(f"Version: {client.version()}")
        print(f"Title:   {client.title()}")
        print(f"Game ID: {client.game_id()}")

        # Test memory read at a known address
        val = client.read32(0x00100000)
        print(f"RAM[0x100000] = 0x{val:08X}")

        client.close()
        print("Pine IPC test passed!")
    except PineError as e:
        print(f"Error: {e}")
        sys.exit(1)
