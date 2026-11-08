# V26 native movie producer and consumer capture

The opening freeze reproduces upstream of game pixel conversion and upload.
The game continues asking for pictures while the native movie owner stops
publishing them. This locates the bottleneck; it does not yet prove a decoder,
driver or scheduling root cause.

The sealed source is `0c9fa680911faad6a573ee2ad6f46f17bd64886f` and executable
SHA-256 is `9cd40bc4ffc13fd28aae0652d2bb77e32a515ee936ac61ea1e10187a6ca508a3`.
The private session is `build-native-sjuni/playtests/native-mp4-v26`, PID 275732,
creation FILETIME 134386279224621338. The route uses the same native MP4 assets
and Windows Media Engine as V25; character/menu input timing differs, so these
are content-matched observations rather than an identical input replay.

The 100 Hz observer records 42,920 samples. Opening frame 5,958 remains
published for **830.546 ms**, then advances to 5,978. Progress CSV lines 35,995
and 36,075 bound the incident, QPC nanoseconds 249674780698800–249675611244800.
Observer spacing stays below 10.593 ms; the longest read is 1.6879 ms.
Presentation continues with a maximum observed start gap of 17.1885 ms and
span of 1.0272 ms in the surrounding window.

Consumer CSV lines 9,893–9,917 contain 25 requests during that interval: 24
have no fresh frame and the last obtains one. Request spacing stays below
33.8141 ms and borrowing below 0.0018 ms. The game is asking normally rather
than spending the freeze in conversion or holding a renderer lease.

Producer CSV lines 9,873–9,874 bound an **841.3405 ms** publication gap.
Serial 5,959/ordinal 5,958 publishes at 249674742752900; the next publication,
serial 5,960/ordinal 5,963, is at 249675584093400. Backpressure remains zero.
Recorded transfer and readback operations around the gap are short; the longest
recorded whole iteration in the surrounding window is 13.3707 ms. However,
this trace records fresh frames and slow iterations, omitting fast empty polls.
A worker preempted between recorded iterations remains possible. Do not call
the Media Engine or hardware decoding the confirmed cause.

Both producer and consumer traces report zero dropped rows. All 2,216 original
MWSFD slot observations are inactive. The native movie owner reports five
source generations, 11,804 delivered frames, joined shutdown and no source
error. Duplicate final report lines represent one owner. An owned WM_CLOSE
ends the run; current classification is `exited-no-fatal-diagnostic`.

Native audio reports 20,722,560 output frames, 18,798,636 signal frames and
**99,680 source underrun frames**, zero hard failures and queue rejections.
All owners retire; the 13 packet-log diagnostic refusals remain separate.
Process-only capture has 21,353,280 frames, peak 22,528, RMS 2,356.208 and no
OS discontinuity/timestamp-error flags. Those flags do not erase application
underruns, whose final totals cannot be assigned to this video incident.
The user is away; audible synchronization is unconfirmed.

Both memory observers retain their partial results and teardown WinError 299.
The offline `native-movie-analysis-v2.json` contains incident references and input
hashes. Original run and capture receipts are preserved.

The next controlled candidate adds periodic producer state/clock samples and
an explicit software/WIC Media Engine comparison. Omitting the DXGI manager
selects software decoding/processing according to Microsoft's
[attribute contract](https://learn.microsoft.com/en-us/windows/win32/medfound/mf-media-engine-dxgi-manager);
[TransferVideoFrame](https://learn.microsoft.com/en-us/windows/win32/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-transfervideoframe)
supports a WIC bitmap. The existing route is called DXGI-enabled, not proven
hardware decoding. Both retain the OS playback clock and native MP4 assets.
No stutter fix, audible sync or Step 3 completion is claimed here.
