# SNIOPINT host transport check

Run `tools\snap_iop_check\run.bat` from a Visual Studio 2022 C++ environment.
The script initializes that environment itself when installed at the standard path.

Tests exercise genuine TCP/UDP loopback sockets, connection refusal, guest socket
zero, network byte order, UDP bulk receive alignment, unsupported operations,
DNS redirection, interface generation, and reset lifetime. The final APP check
requires a local Capcom APP service at `127.0.0.1:10127`, and validates its real
server-first `0x1002` opening. The isolated openSNAP research fixture can supply it.

This verifies the original SNIOPINT RPC `0x01270110` transport boundary. It does
not establish that native game instances have joined a lobby or synchronized a
scenario. Runtime opt-in is controlled by the caller; `REO_COOP_HOST` must be an
explicit numeric IPv4 server address. Only that endpoint and known Outbreak
service aliases are routed. DNAS and unsupported operations fail explicitly.

`REO_NET_TRACE=1` enables bounded RPC stderr records. `REO_COOP_TRACE_FILE` writes
JSONL RPC results and actual socket send/receive byte traces. Keep test accounts
and private network logs outside the public source tree.
