# Interactive map view cycling, panning and zoom transitions

Static File #1 US research, 2026-11-04. One complete large original body reviewed,
covering all interaction and transition branches. Addresses/offsets hexadecimal.
W=755EC0, M=pointer at755768, P=pointer at755770. No game/build/replay/attachment
or live-memory inspection. Numeric input/actor states retain original values.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6E6710](../recomp/config/output_ovl/o2/o2_006E6710_0x6e6710.cpp) | `tick_interactive_map_view_cycle_pan_zoom_and_actor_state_gates_candidate` | Probable role; full body reviewed | Requires selected actor8==1, else6E1430 closes. Increments M halfE per invocation. M4==1 refreshes projection6D9480; exact held mask(W3CE2&F30)==200 for ten ticks advances to M4=2, clears4BADEE and sets M2=1, otherwise sets local actorBA0 bit8000 and resets map mode/counters through6EC680. M4==2 follows actor view6DAF90 while200 held andD20 clear, closes on FF or conflicting input. Main M0==0 handles cancel10, multi-group confirm20 to M0=2, next/previous masks400/800 cycling M14 over M15, matching metadata M48[index] to M word68 and570A10 admission. Analog W3CEC beyond +/-40 initiates zoom state1 unless already at outer M2 level; W3CEA/3CE6 beyond thresholds pan M2E/2C by guest cvt.w.s(4*unsigned W3CEE/127). Changed panning is constrained using1.5 scaling, map boundsM16C..172, scaleM20 and screen640x448, restoring prior coordinate if boundary test rejects. M0==1 changes floatM6C by owned742E40 each invocation: direction0 increases toward1/1.5, direction1 decreases toward.5/1; clamps endpoint, changes M2 zoom level, returns to state0 and seeds eight-tick cooldownM A. M0==2 calls6DAFB0 next-view selection, updates M14/M37 from M58 and projection, then resets state0. No frame-rate assumption or blocking render wait. |

The next/previous view loops wrap across M15 but have no separate iteration cap.
Their return-to-current check occurs after metadata equality at6E6A10/6E6A9C;
the equality-mismatch branch goes straight back to the cyclic step. Valid decoded
map data must supply a matching entry for progress. This is a static admission
contract, not a reproduced infinite loop or slowdown diagnosis. Panning uses the
original guest rounding instruction, not an assumed host truncation conversion.

The controller connects already-mapped [map texture/projection state](SYMBOLS_MAP_TEXTURE_STATE.md)
and [tile/marker composition](SYMBOLS_MAP_TILE_AND_MARKER_COMPOSITION.md). This
describes interactive map UI work, not gameplay world camera movement.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
