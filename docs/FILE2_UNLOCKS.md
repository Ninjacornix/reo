# File #2 progression unlocks

Select **File #2 → Cheats**, enable **Enable cheats** and **Unlock everything**, then use **Play alone**. This option grants scenario, difficulty, costume, NPC, bonus-mode and collection availability through the running game's progression data. It does not grant points, add inventory items or play through scenarios. The game's normal save operation is needed to retain changes after disabling the option; the launcher does not replace or directly edit a memory card.

File #2 uses the native marker `[CHEATS-UNLOCK-FILE2-1] progression`. The launcher rejects an older File #2 native build that has only the health/infection/ammunition hook or File #1's unlock marker. Rebuild or update the game when prompted. Both the master cheat switch and the File #2 unlock selection are required. File #1 and File #2 selections remain separate, and cheats are unavailable in co-op.

## Original-code evidence

The supported executable is **SLUS-20984 NTSC-U v1.05**, ELF SHA-256:

`5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d`

Original routine `0x13c190` and helper `0x13c110` establish the progression layout rooted at `0x2feea0`. Save initialization at `0x13a610` clears `0x1474` bytes, initializes scenario availability at `0x30022c` to `0x1f`, and initializes difficulty availability to `3`. The implementation uses the original unlock masks and valid collection counts, preserving unrelated bits rather than filling entire structures.

| Feature | Progression field and applied mask | Original evidence |
| --- | --- | --- |
| Costumes | Eight bytes at `0x2feea8`; OR masks `03 03 03 03 03 0f 0f 0f` | Table `0x217878`; selection reader `0x59c680`, setter `0x597dd0` |
| NPC characters | Four words at `0x2feeb0`; OR the corresponding masks from both original tables, preserving the zero-mask final word | Tables `0x217880` and `0x217890`; getter `0x59c550` |
| Difficulties | Byte `0x2feec5` OR `0x0f` | Getter `0x59bb00`, setter `0x597f20` |
| Main and extra scenarios | Word `0x30022c` OR `0x0fff` | Unlock routine `0x13c190`; save initialization `0x13a610`; availability getter `0x59bab0` and scenario list `0x59bda0` |
| Bonus-mode availability | Byte `0x2feec3` OR `0x0d`; active mode stays unchanged | Getters `0x59bc30`, `0x59bc40`, `0x59bc50` read masks `1`, `8`, `4` |
| Collection availability and purchases | Bases `0x300248` and `0x3002ac`; five banks at a 20-byte stride, valid bit counts `145, 59, 146, 14, 11` | Count table `0x2178b0`; getters `0x593fd0` and `0x594020` |

The availability getter `0x59bab0` reads banks at `0x2ff8c8 + index * 0x964`; the scenario list `0x59bda0` requests index `1`, selecting `0x30022c`. The original full-unlock routine also writes `0x0ffe` to the other availability bank at `0x2ff8c8`. This feature deliberately omits that direct write.

The original menus may subsequently reconcile availability from owned collection extras. Routine `0x597fd0` calls `0x597f70` to set bits `6`–`11` in both banks. A fresh live run observed the other bank change from `0x1e` to `0xfde` after leaving Collection, through that original game behavior and without gameplay. Direct cheat writes preserve reward points, active options, padding, unused collection bits and data outside the documented masks; normal game processing is retained.

## Verification

Static evidence comes from the original ELF instructions and matching generated opcode comments. REA diagnostics found unavailable registration/engine state; no analysis engine or configuration was installed or changed.

An independent bounded interpreter executed the original unlock routine and its own data tables: **13,068 original instructions**. Its result matched the native implementation across **5,236 progression bytes**, except for the deliberately omitted original-only write to the other scenario-availability bank at `0x2ff8c8`. The private receipt is `build-ninja/issue-29-unlocks/original-oracle.json` in the original development workspace; private game inputs and generated game sources are not published.

Regression checks pass **23 File #2 progression checks**, **76 existing File #2 health/infection/ammunition checks** and **55 File #1 checks**. They cover the write boundary, preserved data, repeated application and game-specific behavior. The launcher passes **788 checks**, including separate selections, unlock-only export, co-op rejection and native capability markers.

Live verification on a fresh test card confirmed the native unlock marker, Elimination 1 availability, Kevin Type-B, NPC Luke, all four difficulties with Very Hard selectable, the Infinity menu, owned Gallery entries and all 11 owned EXTRA entries while reward points remained zero. The private run is `build-ninja/issue-29-unlocks/enabled-02` in the original development workspace.

Save/reload persistence remains unverified. The oracle, fixtures and observed menus do not establish full scenario completion, every costume's in-game rendering or saved-unlock persistence.

To repeat the original-code comparison with your own supported ELF, run:

```bat
tools\cheat_check\run-file2-unlocks.bat build-ninja\file2-unlock-check\after.bin
python tools\cheat_check\verify_file2_unlock_elf.py path\to\SLUS_209.84 build-ninja\file2-unlock-check\after.bin build-ninja\file2-unlock-check\oracle.json
```

The first command also checks full-RAM preservation for three input patterns and repeated frames. The second refuses any ELF whose SHA-256 differs from the supported revision and executes only the bounded original routines. Neither command edits a memory card.
