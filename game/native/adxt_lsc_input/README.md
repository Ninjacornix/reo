# Owned live ADX queue

`Input` connects the original-qualified LSC queue to the actual native encoded
ring, asynchronous read worker and phased decoder/player. It owns a sealed clip
catalogue, opaque asset keys and a bounded boundary journal. Only the private
session/player integration can bind its backend or publish source observations.

Prepare clips with `adx_sequence::Clip::prepare`, register them, enqueue their
returned keys and start the input. Supply it as `player::Config::lsc_input`, enable
seamless decoding, set the source byte domain to `byte_domain`, and open the
control-session player with `input->origin()`. The origin cannot be read directly.
Queue controls require the same serialized control owner as the session.
`minimum` admits the original signed 0..capacity byte threshold control for the next
lower-file open. Invalid values retain the preceding minimum and diagnose.
Zero admits no refill; changing the queue control does not revise an already
opened lower file or accepted read.

`Config::encoded_capacity` defaults to8192. An explicit sector-aligned capacity
from2048 through1048576 uses the bounded source/worker/staging profile. Set the
player source capacity, threshold and maximum request to this same capacity,
maximum sectors to capacity/2048, and select `bounded_sectors` for nondefault
capacity. Profile mismatch refuses before taking the input's one-use binding.
See [the current larger-buffer qualification](../../../docs/native-media/LSC_CAPACITY_PROFILE.md).

Additional prepared keys may be enqueued during playback, including from the
empty notification. No worker reads mutable queue state. Stop a bound player by
retiring its session key; successful retirement includes the actual output fence
and worker join. A new playback lifetime needs a fresh input.

See the [contract](../../../docs/native-media/ADXT_DYNAMIC_LSC_SOURCE_CONTRACT.md)
and [evidence](../../../docs/native-media/ADXT_DYNAMIC_LSC_SOURCE_IMPLEMENTATION.md).
The bounded-threshold, finite-clip profile is not selected in the game.
General stop/restart, error recovery and original global scheduler parity remain
explicit boundaries. It does not complete native media or the six-stage plan.
