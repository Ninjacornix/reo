# Actor room release and shared control state

Native6696C0 and1B0010 now compose with64EF10's local/ordinary-mode control
branch. Typed room-release messages follow the actual811B30/811300 request
branch, using independently pinned and word-audited o9/o8 bodies. Actual external
transport and receiving membership application remain open. The installed game
is still V39; Stage4 remains incomplete.

This work corrects three ownership boundaries:

- OriginalBD0 is one byte. The inherited hit `response_lock` now also supplies
  script/control cleanup and hold transitions. The separate `control_pending`
  field was removed.
- OriginalAD4 is one byte. Inherited `transient_equipment` now supplies the
  scenario control-request pending flag. `ControlRequest` owns only its AD5 kind
  and AD6 parameter. Hit cleanup can therefore cancel an actual queued request.
- Original3243D8 is one byte. `exit_requested` now belongs to the canonical
  Session, shared by the actor hold producer and the outer scheduler. The
  separate Update.State field was removed, preserving its existing default0.

These changes supersede earlier composition claims that treated the separate
control fields as canonical. A passing isolated source comparison did not prove
that the hit, script and scheduler consumers shared their state.

Hold entry clearsBD0, sets actor status10000, and sets the session exit request
only for actual local authority. Incoming request consumption preserves the
source's branch order. In particular, the nonlocal nonzero-mode branch retains
BD0. Comparison rejected an intermediate incorrect clear of that byte.

Room release is independent of actor message phase, pause, status and suppression.
Mode0's original helper only admits slot0; mode1 admits slots0..3. It reads the
canonical primary room, skips rooms outside0..127 and nonlocal slots, then sends
the captured typed channel7 message. Missing capabilities or delivery refuse
explicitly. `RoomClaimSink` keeps the actor core independent of script VM headers.
No legacy packet layout or transport implementation is claimed by the typed value.

Both compiler control comparisons cover196608 room-release cases,65537 hold
cases and65419 special interaction branches.8192 actual World/behavior/hit cases
cancel pending script requests while retaining kind/parameter;256 script-to-hit
cases exercise the sharedBD0 early return. Full current VM comparisons cover
84160 request consumers and1280 opcode dispatches. Outer update comparisons
include2048 worker cases,4096 phases and241 hold-to-scheduler compositions.
Focused receiver regressions and eight parent integration checks run on both
compilers; exact evidence is recorded by the qualification script and receipt.

Offline nonlocal668F20 still needs the actual off-room scene/AI reconstruction
owner. The helper's a2!=0 membership mutation, external transport, higher actor
actions/AI/VM factories, semantic native saves and coherent game installation and
acceptance also remain open. No game was launched for these checks and no
historical slowdown cause or performance fix was established.
