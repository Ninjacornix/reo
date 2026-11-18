# Native audio clip preparation

`Loader` parses retained immutable ADX cue extents on a private bounded worker.
Submitting or polling a cue does not read its header on the game thread. Results
are sealed native `adx_sequence::Clip` leases, without guest addresses, emulated
registers, RPC or the original file queue. Existing clip admission still applies;
this does not silently admit unsupported encodings or inline-loop assets.

Use one serialized controller for preparation, ticket release and shutdown.
Read-only observations may overlap the worker. Release invalidates a ticket's
generation; a blocked older job cannot publish into a reused slot. Completed
clip leases survive ticket release. Queue overflow and parsing failures are
explicit results. Stop cancels logical ownership without waiting for reads;
join/destruction waits for actual source ownership to drain and must run off
game/output callbacks. Never destroy the loader from its own source callback.

The queued player can call `adxt_lsc_input::Input::preparing_assets(count)` before
starting/servicing a source. An accepted next clip awaiting preparation keeps
the decoder at its header boundary instead of manufacturing EOF. Publish the
prepared clip into that native queue before decreasing the count. Preparation
failure must be reported and canceled, not represented as successful playback.

Focused tests cover real asynchronous reads, stale-result publication, bounded
admission, canceled work, retained source ownership through join, independent
clip leases, source/allocation errors and destruction outside the result lock.
The control-session test delays the second header, continues real source/player
service, then verifies all 32,000 decoded samples and both channel digests match
the fully prepared comparison. This is native integration evidence, not a game
hook: engine cue resolution, queue commands and source retirement still need
binding before this replaces the remaining game callers.
