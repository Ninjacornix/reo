# Logical picture capacity and physical reorder storage

The prepared native video graph defaults to two logical frame slots, matching
the observed File #1 configuration. The real D3D11 decoder and Vulkan export
bridge retain their independent bounded three-slot physical storage. Native
surface leases retain every successful submission before its timing publication.
No logical frame reservation is needed merely to hold a future MPEG anchor.

Reorder eligibility still requires a later anchor watermark or genuine parser
EOF. Publication reserves an actual logical slot only when an eligible earliest
picture can enter it. A pending producer remains retained in that slot. Earlier
published pictures must be ready in the pool before any later publication; a
separate fence probe cannot make pool readiness implicit. Full logical or physical
storage returns pending without dropping a decoded picture or overwriting an
unretired surface. The prepared graph does not invent a running transition.

Stop closes logical consumers and separately retires unpublished physical
surfaces. Rebuild waits for both domains, including every real producer and
renderer fence. Explicit blocking drain retains all surviving physical leases
and is restricted to shutdown/error cleanup. Normal service never uses wait_idle
or elapsed-time completion. Decoder reference surfaces remain the bridge's
separate original hardware reference protocol.

Qualification must exercise actual two-slot priming in state two, all complete
owned movie streams with ordered decoded/presented counts, first-frame identity
across rebuild and unsignaled renderer-fence refusal. This capacity/ownership
cut alone does not establish game scheduling, paced playback, skip/recovery,
audible synchronization or a stutter fix.
