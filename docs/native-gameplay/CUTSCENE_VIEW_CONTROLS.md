# Scene visibility and fullscreen color

The sole CutscenePlayback can own CutsceneViewControls. Binding requires the exact
controller state and canonical session clock reference; duplicate, foreign and
active-callback binding attempts refuse while preserving caller ownership. The
real callback positions now execute complete5EF740 and1BBBA0 through this owner.
The controller's color reset executes complete1BBB10 and retires the old binding.
The unbound service boundary remains explicit.

5EF740 writes the existing SceneModels128-byte physical visibility bank, preserving
its independent style words. It consumes kind0/1 frames in the live descriptor
workspace and retains kind2 color bindings. Its two packed room-view words have one
RoomViewMasks owner. The first drives the complete58FE80 tag decision; the second
remains numeric pending its actual consumer.5ECCA0's established scene defaults are
first0 and secondFFFFFFFF. Full5BED30 room-entry adoption is separate work.

FullscreenColor implements complete1BBB10,1BBB80 and1BBBA0. It retains the first
three control words and the actual640x480 rectangle. Interpolation uses signed
frame division by2 toward zero, independently of clock mode. The first following
kind2 record within32 records controls interpolation or the fixed-color fallback;
an exhausted32-record search preserves the prior color. Raw16-bit channels retain
the original shifts and ORs, without invented byte masks or clamps.

CutsceneDescriptorWorkspace is an asset-relative256KiB load domain. Original
1BAEC0 clears the enclosing startup allocation,1AF910/1AF970 allocate its actual
subrange, and5ED900 uses its upper256KiB for ordinary DM loads. A load overwrites
the new storage prefix, appendsFFFFFFFF and retains the old suffix. Complete
1A9F20 returns the AFS sector count shifted by11, so an ordinary load includes
the archive's actual sector padding. The marker follows that physical extent,
not the logical member length. Movie5EDA40
clears exactly96KiB of that descriptor domain. Typed event consumption writes only
the frame halfword. Generation changes invalidate old live views, while immutable
descriptor snapshots retain their original bytes. Production contains no CPU,
register file or addressed RAM.

This retained workspace matters for actual content. Among548 admitted0950
descriptors there are2,028 kind2 records:1,480 find the next color within their
secondary section,304 find it across other descriptor sections,243 exhaust the
32-record search and one dm2500A lookup crosses the logical member end. The real
loader retains the archive's actual sector padding before the marker; a lookup
beyond that storage extent sees the workspace suffix. No invented terminal
padding is substituted for these bytes. The earlier logical-prefix fixture did
not establish the physical loader's boundary and its cold-tail explanation is
superseded by the reached sector-reader evidence.

The independent event-resource writer1D2FE0 still has an explicit boundary.
Its2100..23FF route uses1CD5B0's owned MODEL/ST/Rnnn/Ennnrrvv namespace. No matching
E[0-9]{7,9}.NBD is present in any supplied NETBIO00/01/02 nested archive. The absence
inventory establishes no node-index bound for that writer. Placement E*.BIN files
are a distinct format; resource1800..1FFF saved-pose bounds cannot substitute for
this evidence. This checkpoint qualifies the actual admitted workspace operations,
not every possible unported resource constructor or replacement asset.

Both compilers pass1,179,655 fullscreen checks over131,072 cases and524,288 original
calls. Workspace v4 passes714,870 checks,8,192 synthetic overlays and1,097 actual
loads: cold dm2500A, all548 admitted descriptors forward and all548 in reverse.
The owned visits now read whole sectors directly from the archive, including its
real padding. Both compilers pass12,174 original fullscreen samples over4,058 keys.
View-control v4 passes1,128,449 checks,3,539,200 literal visibility writes,42,520
color bindings,55,301 consumed frames and524,288 mask decisions. Whole-controller
v22 passes2,744,818 checks,2,048 bound view ticks and26,057 callback guards, including
frame/clock mutation between callbacks and stale-workspace refusal. Source bodies
and constants are checked against the pinned owned executable/overlays.

CutsceneDescriptorLoader now composes the actual5ED900 ordinary loading route and
the existing complete5F15A0 parser. It borrows the canonical Session and actual
ScenarioArchive, including its authored_H index. Complete1AA3E0 selects that same
scenario before resolving the resident basename. Nonzero loading modes read its
actual AFS sector storage. Mode0 selects1AA480's distinct default romdata catalogue,
whose1,342 owned compiled keys contain no scene-DM name; it returns a missing read.
A scenario member cannot satisfy that separate namespace. Signed session_state==1 reparses the existing live
workspace without requiring a new source mode or scenario. A missing read preserves
the previous snapshot/workspace. Complete parser return0 versus early terminal1 is
retained, rather than declaring every parsed descriptor fully loaded.

Historical loader v3 passed21,870,333 checks on each compiler:548 assets in modes0/1/255,
1,644 reads and1,644 direct reparses,146,676 section checks,21,546,264 retained-tail
checks and three missing-name routes. Complete5ED900,5F15A0 and1AA3E0 execute with
independent fixtures for reads and bounded standard formatting. Those fixtures
incorrectly treated mode0 as a successful scenario lookup and returned logical
member lengths. The expanded reached-lookup comparison supersedes those two
claims; the original v3 receipts and seal remain retained development evidence.
SDK disk scheduling and movie5EDA40 merging remain unestablished.

Corrective loader v9 passes14,591,013 checks on both compilers. It visits all548
descriptors in modes0/1/255:1,096 real sector loads,1,096 live reparses,548 genuine
default-catalogue misses and three further missing-name routes. It compares97,784
sections and14,364,176 retained-tail records. Eleven complete source bodies execute,
including both catalogue selectors, both name resolvers,1A9F20 and its129C08/130E40
sector-size path. The original default catalogue contains all1,342 owned encoded
keys. SDK task allocation/sector transfer/completion/close remain explicit fixture
operations; the independently qualified AFS range implementation establishes the
storage metadata. Per-resource sector digests preserve the actual archive padding.
Development v4/v6 caught incomplete direct-link closures; v7 caught a missing SDK
getter fixture and a GCC overlap warning; v8 retained an LLVM compile timeout while
GCC passed. V9 passes both compilers with the complete unchanged production closure.

Development snapshots are retained: initial view v1 lacked a test SRA macro and
v2 exposed an incomplete direct-link closure; v3/v4 include real content and math
sources. The workspace initial synthetic-only proof remains separate from the
later all-content proof. Loader v1 exposed an incomplete direct-link closure and
a GCC fixture warning; v2 caught a test fixture that failed to restore its scenario
between loading modes. V3 uses the complete native source closure and restores the
canonical input before each visit. A renderer, full scene lifecycle/movie merge, complete
session/frame installation and game acceptance remain open. No game or device is
started by these tests, and full Step4 completion is not claimed.

Current SessionRooms v7 and parent25 v6 CMake cohorts pass on both compilers with
no source drift. They capture the earlier ordinary-loader and view registration,
before the default-catalogue and sector-extent corrections described above.
The [scoped seal](../../tools/native_reconstruction/native_cutscene_view_controls_qualification_v1.json)
records the exact fourteen comparison/integration receipts and the independent
event-namespace absence inventory. Later light-track work is excluded.
