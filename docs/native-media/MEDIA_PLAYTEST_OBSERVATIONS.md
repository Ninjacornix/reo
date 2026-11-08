# Owned media state observations

`tools/native_reconstruction/observe_media_playtest.py` is an external, read-only
sampler for an already running, private File #1 test session. It checks the
session's copied executable hash, PID, process creation identity, complete owned
File #1 ELF hash and loaded ELF signature before sampling, and retains the opened
process handle. Every sample
checks that same process identity before and after reading. It does not attach
by process name, write game memory, suspend threads or send input.

The bounded command accepts at most 900 seconds and four samples per second.
It reads the original eight-context registry, actual clock selection/callbacks,
counter increments, separate global/helper frequencies, pause/buffering state
and retained audio child observations. The documented EE pointer segments and
RAM bounds are checked before child reads. Failed or racing reads remain
unavailable observations. The output and receipt names must be unused.

These are asynchronous samples. They do not prove an atomic object snapshot,
individual query arguments, exact tick frequency, callback counts, A/V equality
or a stutter's cause. A pointer still present across samples does not establish
an unchanged source generation. Original instruction or native execution
evidence remains necessary for those claims.

The initial declared read-port check covers the eighth registry slot, distinct
frequency fields, original context offsets, audio child reads, admitted aliases
and rejected pointers. Its receipt is
`build-native-sjuni/media-observer-declared-port-check.json`. This check attaches
to no process and does not claim live evidence. A completed live run must retain
its own sampling receipt and source hash.

Example, after the private session is already running:

```powershell
python tools/native_reconstruction/observe_media_playtest.py `
  --session build-native-sjuni/playtests/NAME --seconds 600 --hz 2
```

Step 3 remains open until its source, scheduler and transition integration gates
pass. Observing the original selected provider is preparation for that binding.
