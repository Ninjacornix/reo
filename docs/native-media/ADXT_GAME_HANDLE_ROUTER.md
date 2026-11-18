# Guest handle routing to the canonical native owner

`GameHandles` maps prepared File #1 handle identities to the existing canonical
native instance owner. It creates no second session, source decoder, clock or
output device. The map retains opaque metadata and generation keys, with no
guest RAM pointers. A serialized guest adapter supplies the independently
qualified handle description and fences accepted guest calls during teardown.

Adoption translates the ADXT slot to the native stream-service index, retaining
the independent file descriptor index for ownership checks. It retains native
bookkeeping reservations for both original stereo DTR identities and rejects shared decoder/file/RNA/route/SJ or
paired-stream identities. The native instance facade independently validates its
own service indices and capacity.

Controls receive a bounded borrow of the current native key. Keys from another
map or a previous lifetime refuse. Native destruction must actually complete
before the map releases its child reservations or admits reuse. The runtime hook
must withhold original destruction until that result; this map does not write or
lock guest pool records. Service
can progress another source while a worker is blocked; a pending destroy retains
the game mapping even if its private output is already fenced. Whole-map clearing
requires the canonical owner's published joined proof. Mixing order remains an
explicit caller obligation; a three-source service refuses before file reads
until the complete order is supplied.

Both compilers pass three workflows with actual native source workers and a
declared guest layout: stereo playback from a handle using file descriptor 39;
refusal of a new owner claiming the stereo peer's second DTR; and blocked
destruction, peer rendering, ordered service and subsequent slot reuse. Three
deliberate faults are detected on each compiler: using the file slot as the
service slot, releasing children on pending cancellation, and ignoring the
second transfer reservation.

The V1 prototype passed LLVM but failed GCC because a helper call could evaluate
the status argument before its operation argument. V2 explicitly sequences the
owner operation before reading every result. The failed cohort's seven exact
source files and receipts remain under
`build-native-sjuni/adxt-binding/game-handles-v1-source`; it is not qualified as a
two-compiler cohort. This was a real prototype defect, not a fixture correction.

`recomp/overrides/native_adxt/game_handles_qualification.json` identifies the V2
source and native archive cohorts. These checks install no guest hooks and use
no actual runtime RAM acquisition or audio device. The router is outside the
frozen V16 production preflight kit. Original ABI/source/control/reset/callback
entry points, live RAM/identity admission, service/mix ordering and actual game
transition/A/V validation still need integration. Step 3 remains open.
