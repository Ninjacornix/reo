# Online progression unlocks (#29)

For the selected game, open **Cheats**, turn on **Enable cheats**, and select
**Unlock everything**. Deselect other cheats, then host or join normally.
File #1 and File #2 retain separate selections. Saving through the game can
retain unlocks; the launcher does not replace or directly edit a memory card.

The built-in progression option is allowed in co-op. Health, infection,
ammunition, results points, escape time and imported data cheats remain
restricted to Play alone. Imported patches are not accepted simply because
their name is "Unlock everything". Saved selections are preserved on rejection.

## Host unlocked, guest locked

A host can choose an unlocked scenario and start it with a guest who has not
unlocked it. The guest does not need to enable the option. Unlock selections
are local: they are not part of the shared randomizer configuration, and the
host's cheat does not grant the guest its progression or costumes.

This was verified with two native Windows clients in each game, separate fresh
cards, and the cheat enabled only on the host:

| Game | Host selection | Guest before and during gameplay | Result |
| --- | --- | --- | --- |
| File #1 | The Hive | Offline and online scenario masks both `0x01` (Outbreak only) | Both clients entered stage 28, room 8; guest movement observed |
| File #2 | Elimination 1 | Offline mask `0x1f`, online mask `0x1e`; bonus scenario 6 absent from guest's own choices | Both clients entered stage 29, room 1; guest movement observed |

Both original waiting-room rosters contained two members before the host started.
Both clients reached interactive phase 2, without modal or pause layers. Ordinary
private controller input moved the guest's local actor in both tests. Its unlock
masks remained unchanged after movement. These runs stopped before completing a
scenario: they do not establish save/reload persistence or every scenario's behavior.

## Native implementation and compatibility

The live test exposed a gap in the previous implementation: offline unlock bits
were set while File #1's online room menu still offered only Outbreak. Online
room creation uses separate progression banks:

| Game | Original reader | Online bank | Applied mask |
| --- | --- | --- | --- |
| File #1 | `5CCA50`, scenario cycling `5CD7D0` | `0x321ef4` (save base `0x31fb60` + `0x2394`) | OR `0x1f` |
| File #2 | `5EBE80` | `0x2ff8c8` | OR `0x0ffe` |

The per-frame built-in now updates those fields as well as offline availability,
preserving other bits. File #2's bank also matches the original full-unlock routine
`13C190`. No lobby result, guest input or network packet is fabricated.

Online use requires native marker `[CHEATS-ONLINE-UNLOCK-1] progression`, in
addition to the edition's existing progression marker. An older native build is
rejected with a Game files rebuild/update instruction when online unlocks are
selected. A guest who does not select unlocks does not require this new capability.

## Verification

Private evidence is under `build-ninja/mixed-unlock-verification/`: the pre-fix
File #1 run is `file1-02`, and corrected runs are `file1-03` and `file2-01`.
Receipts retain executable hashes, PID/creation identities, menu/progression
observations, two-member rosters, scenario-start states, actor samples and native
window captures. Windows ran on a private desktop which was never switched to;
all audio buses were muted. Guest RAM was read-only to the test driver. The only
gameplay input was ordinary private controller/keyboard reports.

The test images compile the updated authored bootstrap and cheat headers against
the existing audited RC1 guest/runtime objects. They are isolated verification
images, not a clean full RC2 build or replacements for the user's installed games.

Launcher tests cover host/guest selections, real UDP transfer with an unlocked
host and cheat-free guest, unchanged shared configuration, gameplay-cheat
rejection, and native capability handling. Native full-RAM checks cover both
availability banks, preserve unrelated state, and verify repeated application.
The File #2 oracle executes 13,068 original instructions and compares all 5,236
progression bytes, including the online bank.

```sh
c++ -std=c++17 -O2 tools/cheat_check/online_unlock_tests.cpp -o /tmp/reo-online-unlocks
/tmp/reo-online-unlocks
```
