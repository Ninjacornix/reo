# Native named sound bank loading

`gameplay_bank_loading::Loader` connects queued gameplay bank names to the
existing AFS resource views, asynchronous read owner and native bank Session.
It adds no filesystem singleton, guest-memory bridge, device callback or second
bank mixer. Preparation and sample decoding run on an owned worker; `service`
only advances bounded control operations and hands off completed reads.

The original422 sound aliases retain their exact AFS member ordinals. They are
not inferred from archive display names. Bounded ASCII normalization and first
lookup match complete1AB050/1AB310, including the actual original copy, length,
comparison and uppercasing functions. ROM/RDT/EDIT substring selection and the
four punctuation replacements follow the source. Inputs beyond255 bytes and
non-ASCII inputs explicitly refuse instead of entering unchecked stack reads.

Queued bank names retain the first15 bytes and append `.snd` for lookup. Eight
pending requests plus one active/result slot form a fixed nine-slot domain;
unconsumed completed results retain quota. Matching names skip a reload only
while the actual installed bank ticket is current. Cached names are owned
copies, avoiding the source's pointer into a mutable queue slot. The cache also
checks the installed generation, so cancellation or an external bank replacement
cannot masquerade as a completed installation. Different copied names preserve
their reload behavior even when aliases resolve to the same member.

The loader uses one existing asynchronous exact-read slot with a1MiB member
limit and2MiB staging budget. Every owned SND is at most635200 bytes. Cancelled
active reads remain charged until the provider returns; a following request
waits in bounded admission rather than reading on the gameplay thread. Bank
preparation uses the existing Session capture/prepare/install path on a separate
owned worker. Ticket validation is repeated at commit. Shutdown suppresses
pending publication and joins both workers; it does not detach blocked reads or
undo an installation that completed before cancellation.

Each compiler passes23491 checks:4356 complete original lookup cases,
2098790 original helper calls, twelve loading/ownership contracts, and103
actual stock bank loads from the verified owned sound AFS.2166 real requests
and277248 mixed frames match direct native loading exactly, including11682
nonzero samples. The direct-loading comparison tests I/O handoff and asset
identity; bank decoding/routing retain their separate original-body qualification.
The full owned ISO is verified through the same retained Windows handle used
for reads. No1GiB sound archive copy is created. The known malformed `test.snd`
remains an explicit bank failure.

Contracts cover blocked read cancellation and subsequent backpressure, eight
queued requests, nine retained ready results, live voices preserved by a cache
hit, consumed/foreign tickets, failed partial reads, cache invalidation after
cancelled or external installs, and blocked-provider shutdown/join. Draft
failures are retained: they caught missing installed-generation discrimination
and a GCC header dependency before the final paired cohorts. The core audio
regression still passes891629 checks on each compiler.

This is the bounded direct SND loader. Combined enemy HD/BD construction,
staged1AD220 loading, source session-mode gates, remaining caller migration and
coherent native gameplay acceptance remain open. The native queue's fixed
result quota and immutable cached names are explicit ownership changes; this
cohort does not claim exact execution of the old queue's mutable pointer aliases.
No game is launched, no audio device is opened, and no speedup is claimed.
