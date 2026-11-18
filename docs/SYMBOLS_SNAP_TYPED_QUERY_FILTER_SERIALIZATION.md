# SNAP typed query filter serialization

Static original File #1 US resident ELF, 2026-11-04; SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Two entire original intervals read, all type-switch arms, reservations, initial count tests and delay slots. No target execution or query submission.

The caller evidence is concrete: o3 [browse controllers](SYMBOLS_O3_BROWSE_COLLECTORS.md) pass NAME filters and1/5/99 limits to1E677C; [OID lookup controller](SYMBOLS_O3_ROOM_OPTIONS_LOOKUP.md) uses1E677C then1E6D08 with4F494400 and pointed values. This supports typed-filter query roles without recovering original enum names or naming the two distinct query operations.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1E677C](../recomp/config/output/sub_001E677C_0x1e677c.cpp) | `serialize_up_to_32_snap_typed_filters_and_enqueue_query_type_48` | Confirmed complete serializer/ownership; query meaning partial | a1 is C-byte descriptor array{tag0,type/operator word4,value pointer8}, zero tag terminates. Payload header8: BE32(a2) at0, emitted count byte4. Emits each tagBE32, lowbyte descriptor4, then4/8/10 bytes by fullword descriptor4>>5. Queue flagsB000/type48/subtype0; success installs callback31=a3 and returns0. Full type/count/failure mechanics below. |
| [0x1E6D08](../recomp/config/output/sub_001E6D08_0x1e6d08.cpp) | `serialize_up_to_32_snap_typed_filters_and_enqueue_query_type_49` | Confirmed complete distinct query entry | Same full descriptor/payload/type branches and admission gates as1E677C, independently reviewed. Distinct type49 and callback32=a3. O3 named OID controller invokes this after completing its preceding type48 query. No stronger original operation name is asserted. |

Both validate handle1/259D0C (error259D10=64/-1) and context50C==0 (66/-1), then request2A8 payload capacity from1DB0B8. Null allocation gives65/-1. Reserve header8; failure releases packet to context520 then65/-1. The8-byte header initializes only word0 and, after serialization, byte4. Bytes5..7 are not locally cleared.

Loop index starts0, tests signed i<20 before each descriptor read, then stops early for tag==0. At most32 descriptors emit. For each descriptor, calculate q=unsigned32(descriptor4)>>5, **not merely low-byte type>>5**. q==2 reserves15 bytes, q==1 reservesD, all other q reserves9. Header of every record is5 bytes: BE32(tag) followed by low8 descriptor4. q==2 zeroes10-byte value then strncpy(value pointer,10), with no extra forced terminator; q==1 reads two input words, reverses each independently and stores in input order; all other q reads/reverses one word. No pointer admission or descriptor-array extent parameter.

The default branch also admits q>2, rather than rejecting it. The fullword type selector and emitted lowbyte can disagree for caller words with upper bits; whether such descriptors occur remains unproved. Descriptor tag0 is always a terminator, not an emitted filter. Successful count byte equals the number serialized; reaching index20 exits without reading a33rd descriptor.

Each record reservation is separately checked; any null releases the whole packet and returns65/-1. Maximum output8+32*15=2A8, matching the requested maximum payload. Final requested queue length is low16(packetPayloadLength-10), so it reflects actual serialized records. Queue failure sets66/-1 without local release; success installs callback and returns0. There is no request-token increment. [Header/queue child](SYMBOLS_SNAP_SEND_QUEUE_AND_CONNECTION_OPTIONS.md) and [packet reserve/length helpers](SYMBOLS_SNAP_PACKET_BUFFER_AND_RETRY_FIELDS.md) own those contracts. No latency or runtime reachability beyond indexed caller evidence was measured.

Audit: 2 bodies, 602 owned instruction comments matched; 108 omitted aligned words are zero/NOP, zero omitted nonzero words.
