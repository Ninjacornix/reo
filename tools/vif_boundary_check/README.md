# VIF boundary admission check

Build the runtime first, then run `tools\vif_boundary_check\run.bat`.
The runner compiles once and runs default-off and opt-in controls in separate
processes, comparing complete GS VRAM hashes for the two completed sessions.
Each process also exercises stop and reinitialization in its middle session.

The fixture uses real runtime guest threads, IRQ dispatch, IO locking, VIF1
normal DMA, VIF DIRECT, GIF A+D packets and the asynchronous GS queue. Main
priority 24 and fixture guest priority 2 are test inputs, not inferred game
priorities. A pending IRQ reads real MMIO before marking progress.
DMAC is explicitly enabled before any guest or IRQ reads D_CTRL, and those
readers and the DMA callback assert it stays enabled in both controls.

Assertions distinguish admission before the VIF kick, admission after DMA
returns, and the unchanged dispatcher admission in the disabled control.
A recursive VIF kick inside the actual DMA callback proves both checkpoint
directions stay suppressed while IO is held. The nested guest entry retains
its native local, PC and RA. Non-STR and other-channel controls remain inert.
Existing GS debt stays pending until the normal dispatcher, preserving overlap.

The candidate admits higher-priority work between VIF batches. It cannot
interrupt a VIF/VU batch holding IO or accelerate VU/GS work.

Validated on 2026-10-11: disabled and enabled controls each passed three
sessions, including stop and reinitialization. Both completed-session VRAM
hashes matched (`28dfe38ab7ba3f70`). The first enabled-control failure used an
uninitialized D_CTRL; its logs are preserved under
`build-ninja/vif_boundary_check/failed-uninitialized-dctrl`.
