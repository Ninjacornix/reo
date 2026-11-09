# Actual window pictures and digital movie/audio timing

Status, 2026-11-09: five independent source-picture regions match the actual
owned game-window recording from V35 session `20261109-033631-629`. Local
process audio matches the associated source regions, and its timestamp phase
does not accumulate drift across those anchors. This supplies bounded digital
content/synchronization evidence. It does not establish physical scanout,
speaker latency, subjective lip sync or stutter-free playback.

The [qualification record](../../tools/native_reconstruction/native_movie_window_picture_qualification_v1.json)
retains exact input/helper/source hashes, process identity, matching candidates,
geometry sensitivity, timestamp statistics and packet-continuity limitations.
This offline analysis accesses no live process/window/device and changes no
existing evidence. The private analysis scripts and failed preconditions remain
retained alongside the completed results.

## Independent content comparison

The hash-verified prepared movie is key
`fe761807bc7493769dd7f9720ce6d1cc969f596f76fefc9b5add5385952b153b`,
manifest source `adxsnd.afs/PS2opening_Evl.sfd`, archive 0/member 416. Its MP4
SHA-256 is `2adbed127861815df7f818ac1e0bf69c2c6f42a661b7871d5c475bdecd86a888`.
The independently pinned FFmpeg 9.0.2 decodes all 6,144 pictures, 512×368 with
sample aspect 23:24, into a bounded 128×92 grayscale reference. No new game
recording or whole desktop image is used by this analysis.

Windows Graphics Capture records 6,946 samples of the owned 642×487 window,
reduced to 128×96 grayscale. All retained foreground/iconic fields are zero;
the helper reports no desktop read or focus request. The containing V35
executable SHA-256 is
`fbe53cc5c3784ae4825be82a07b46e47ab75428f473b6ad5f324e5234bb663f8`.
Its ordinary input-driven gallery fixture passes full playback, replay, skip and
playlist gates and closes normally; the main integration record separately
owns those game-control results.

Window decorations and letterboxing are excluded using an empirical geometric
fit, not a filename/aspect assumption. One calibration image, capture index
2,500, fits reference picture 2,685. The fitted full-window rectangle is
approximately left 21.80, top 77.54, width 597.34, height 367.86 pixels.
The capture helper's actual integer sample locations are retained in the model.
The comparison uses an interior region and zero-mean normalized correlation.
Five different held-out regions validate that fit. Every comparison searches
all 6,144 reference pictures; native trace timestamps only bound which capture
samples to examine near the requested audio anchors.

| Audio anchor | Matched source picture | Capture index | Picture correlation | Publication → capture stamp | Audio minus capture stamp | Empirical audio minus first-picture interval |
| --- | --- | --- | --- | --- | --- | --- |
| 300 / 10.01 s | 291 | 954 | 0.99419 | 102.69 ms | −19.66 ms | [−19.66, +47.06] ms |
| 1,200 / 40.04 s | 1,208 | 1,541 | 0.98723 | 130.13 ms | −47.13 ms | [−47.13, +2.91] ms |
| 2,400 / 80.08 s | 2,403 | 2,313 | 0.99591 | 121.03 ms | −39.66 ms | [−39.66, +10.38] ms |
| 4,200 / 140.14 s | 4,210 | 3,480 | 0.98769 | 111.03 ms | −28.38 ms | [−28.38, +21.66] ms |
| 5,700 / 190.19 s | 5,690 | 4,440 | 0.99762 | 118.14 ms | −35.84 ms | [−35.84, +14.20] ms |

Negative phase means the correlated audio source position precedes that picture's
capture stamp. Source audio time is interpolated locally from the independently
correlated audio anchor and known picture cadence, rather than assuming the WAV
file has a continuous wall-clock timeline.

The capture rate is about 20 Hz. A captured picture can already have been held
for part of its display interval, so audio-minus-capture is not the first-display
phase. The table brackets first appearance between the selected capture and the
preceding captured different picture. These are empirical, conditional intervals:
they assume the content matches, monotonic playback and the capture API's
compositor timestamp semantics. They are not certified statistical confidence
or physical presentation bounds.

The slowly changing region around picture 1,200 needs special care. Its highest
correlation candidate is picture 1,202, but its adjacent-picture separation is
only 0.0029. That candidate and its wider [−113.90, +186.36] ms sensitivity
interval remain retained. The stated selection rule instead chooses the nearby
picture with greatest adjacent-picture separation among correlations above 0.98:
picture 1,208, separation 0.0109. Selection uses image uniqueness, not the desired
timing result. All five selected ordinals stay unchanged when fitted left/top
vary by ±0.5 window pixel or width/height vary by ±1 pixel. The explicit 0.01
correlation margin is a sensitivity convention, not a confidence guarantee.

## Timestamp and coverage limits

Microsoft defines [SystemRelativeTime](https://learn.microsoft.com/en-us/uwp/api/windows.graphics.capture.direct3d11captureframe.systemrelativetime)
as the compositor's QPC timestamp. It is suitable for comparison with the
retained QPC-based audio/producer observations; it does not measure physical
display scanout. The helper also records a QPC after GPU readback. The signed
readback-QPC-minus-frame-timestamp difference ranges from −14.7739 to +300.8087 ms
over the recording, median −5.6578 ms; 5,888 records have negative differences.
The reason for those negative values is not established. No timestamp offset or
phase correction is invented to make them positive.

During the first full movie, 3,964 retained capture samples normally arrive
50.04 or 66.72 ms apart. One coverage interval, indices 2,995→2,996, spans
316.8931 ms. The earlier record has a 300.8087 ms delayed readback observation.
This is a capture-coverage gap, not proof that the game or display held one
picture for that duration. Independently, native movie publication has a measured
72.3295 ms maximum gap in this run. Neither observation justifies a stutter-free
claim or attributes the historical stutter's root cause.

## The WAV storage timeline contains missing intervals

The packet CSV, not the WAV byte offset alone, is essential. Although all returned
packet flags are zero, adjacent packet timestamps contain five gaps beyond a
two-frame tolerance: 220, 30, 310, 60 and 9.1293 ms. Stored packets contain no
replacement samples for those intervals. Device-position fields are all zero,
so they cannot independently establish sample continuity here.

The 310 ms gap is exact: packet 16,305 has QPC 286,960.7747663 s and 480 frames;
packet 16,306 begins at 286,961.0947663 s. At 48 kHz, 14,880 expected timeline
frames are absent between those packets. This overlaps the window-capture
readback/coverage gap: capture 2,995 has compositor stamp 286,960.8280912 s and
readback observation 286,961.1288999 s. The overlap is measured; its shared
inner cause remains unknown.

Consequently, captured-minus-source WAV frame offsets are **2,276,225** for audio
anchors 300/1,200/2,400 and **2,261,345** for 4,200/5,700. They are not globally
constant. Mapping through each packet's QPC preserves the linear source phase
at all five matched regions on both sides of that storage gap. This supports
no accumulated rate drift at the checked regions while leaving continuity
through the gaps unproved. It does not prove that a physical audio drop occurred,
nor that audio was uninterrupted.

The current C++ capture source copies every returned packet, releases it and
writes its PCM/metadata. It counts flags on returned packets but does not check
timestamp continuity or insert timestamp-based silence. This analysis binds the
actual helper binary and Python launch wrapper hashes; it does not independently
reproduce that helper's build. The original failed hash precondition mistook the
wrapper hash for a C++ build-source hash and is retained separately.

Native audio's zero internal underrun count does not establish OS endpoint or
physical continuity. No endpoint recording, device trace or physical observation
distinguishes game output, process-loopback capture and host scheduling as the
cause of these gaps. These limits remain part of the evidence, alongside the
successful content and bounded digital timing checks. Subjective A/V confirmation
and historical incident attribution remain explicitly unknown.
