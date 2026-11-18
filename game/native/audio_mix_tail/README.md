# Shared stream, bank and packet output

`Mixer` is an optional retained tail of `adxt_output_session::Session`. Set
`output::Config::bank_mix` before constructing the output/control session. It
binds once, opens no device itself, and keeps the existing bank session private.
The provider callback renders stream PCM, adds bank audio and applies master
gain. Stream summation order and the existing PCM clamp are preserved.

The default profile exposes native bank preparation/install/command operations.
An optional `PacketProfile` instead selects the unchanged grouped-capture packet
adapter and its transaction lock. Direct mutation APIs refuse in that profile.
Capture identity metadata is an admission input, not proof of an actual game RAM
owner. Game capture and complete-call lifetime still require their real adapter.

Bank/master gain providers must be pure, bounded, nonreentrant and retained for
the full output lifetime. Callback work cannot perform guest execution, resource
reads, allocation, provider operations or joins. Callers release their own bank
Submission and packet Call leases before whole-output join. No output or bank
data lock is held while joining.

Retiring an individual stream leaves banks and peer streams running. Whole-output
retirement fences the provider, drains packet calls and joins the bank session.
A failed provider fence retains bank storage. The bounded packet control pool
remains retained until the last owned graph reference is released; bank assets
are cleared by a successful bank join. The tail cannot bind to a second output.

See the [frozen contract](../../../docs/native-media/SHARED_STREAM_BANK_OUTPUT_CONTRACT.md)
and [implementation evidence](../../../docs/native-media/SHARED_STREAM_BANK_OUTPUT_IMPLEMENTATION.md).
This module is not installed in the game, and stage 3 remains incomplete.
