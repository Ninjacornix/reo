# Native AI control payloads

The canonical Session registry now drains its queued payloads in insertion
order. Each accepted request produces the original nine-byte channel 10
packet, including the local actor marker, registration index, and four-byte
payload. The existing receiver consumes this format. The frame reset clears
the payload count before the other workers run, including on a paused frame.
The registrations retain their own lifetime.

The native message sink reports whether it accepted a packet. On rejection,
the queue removes only the accepted prefix and keeps the unsent suffix for
retry during the current frame. The next frame still applies the original
queue reset. Reentrant flush or reset calls cannot mutate an active drain.

Both compilers pass 516 original drain comparisons with 8,576 matching
packets and 65 original reset comparisons. The original service runs in the
activity-zero profile, where it drains the payload lane without authority
changes. The fixture captures its outbound packets and checks the exact
channel, mode, and bytes. A separate case rejects a packet and verifies
retry order. All thirteen parent tests and the full 2,048-worker and
4,096-phase original-order comparisons pass. See
`native_gameplay_ai_control_payloads_qualification_v1.json`.

The nonzero-activity owner-change lane and its registration callbacks
remain open. The Owner entry uses an explicit sink. Live transport and
gameplay acceptance remain open.
