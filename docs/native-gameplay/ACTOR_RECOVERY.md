# Native recovery transition and gauge caller

Status: qualified on both compilers; uninstalled. Stage4 is incomplete.
InstalledV39 is unchanged. No game or physical audio device was launched.

`ActorRecovery` implements65FCB0 through the canonical actor, UpdateOwner,
ActorResourceOperations, pose snapshot, health-class helper and WorldAnimation.
It borrows same-World owners and rejects foreign or closed bindings. The
periodic gauge owner can bind this recovery directly; its prior required effect
port remains available only when no native recovery owner is supplied.

The source status prefix clears38 and sets80, then assigns C5E to7200 in
clock-mode0 or3600 for nonzero modes. Two actual6605B0 clear/publication calls
retain selectors5 then8 and their source order. The local actor then clears
the canonical inventory-owner byte before reaching required UI6E1430. UI
failure preserves that prefix. It does not silently skip a requested close.

Raw mode0 clears80, sets40000000, transfers inventory, selects action4/0/0/0
with motion-classA0 and captures the action pose. Actual selector1 publication
precedes the second inventory transfer. For nonzero mode, actual65FAB0's native
class helper uses owned thresholds50/25; a zero denominator remains unavailable
under its existing contract. Previous motion class becomes2. Low-byte caller
mode0/1 selects3/11 or3/10 and skips animation selection/activation. Every other
caller mode clears motion class and action-flag1 and selects1/0/1/0. That branch
uses real WorldAnimation to select2050 at initial0/blend10 and real Playback to
activate the admitted channel count. Selector1 publication precedes the final status400 and
actual inventory-transfer prefix. These are call-based state changes, with no
host-time scaling or speed change.

The comparison passes40,960 cases across all five owned item banks,
including every caller-mode byte, both clock reset branches and synchronous UI
mode mutation. There are30,510 actual animation routes using an owned native
skeleton and confirmed absent banks, plus120 enabled status/full-snapshot
observations. Source descriptor/body/local-shape metadata, resource caches and
channel activation execute. Five native gauge-to-recovery compositions require
the old recovery effect port to stay unentered. Delivery failures retain their
earlier effects. Both compilers pass904,744,826 combined assertions with identical
observations. All90,395 source allocations/releases balance. Forty-five refusal
groups include missing UI/animation, rejected first/second/final delivery,
invalid identity, foreign animation, the existing zero-denominator admission
limit and shutdown. Both parent builds and all eight integration checks per
compiler pass. Evidence: `native_actor_recovery_qualification_v1.json`.

The comparison caught an error in this new policy before installation: modes0/1
branch past animation selection/activation; all other byte values enter it.
Corrected fixtures also initialize matching selectors, collision state and the
complete owned body/shape pointer tables. Failed runs are retained, including
the GCC fixture-formatting warning corrected with strict warnings still enabled.

Confirmed absent banks are not loaded-clip or installed-game recovery acceptance.
The separate65FBA0 entry and its behavior caller now have a
[qualified native consumer](ACTOR_ZERO_HEALTH.md). The actual UI consumer,
broader animation/field initialization, queue/receiver/transport, native
save/load and representative installation tests remain open.
