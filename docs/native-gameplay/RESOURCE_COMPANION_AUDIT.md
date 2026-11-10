# Resource companion migration audit

Status: ongoing implementation. The six special factory routes remain
unavailable. The new654720 state policy is qualified; it does not yet
construct a real visual, start a light task or play audio. No game was launched.
Both compilers pass262,144 focused policy cases and20,150,915 combined resource/
inventory/equipment assertions. Policy observations include50,518 render
requests,7,282 fades,23,483 retirements,815 light-task requests and35,335 audio
requests. These are captured intents, not proof that those effects ran.
The full signed timer domains, all seven states, other state bytes, all subtype
destinations, missing owners, action gates, RNG state and pre-increment sample
time are covered. Parent builds and four World/collision regressions pass.
Evidence is sealed in `native_resource_companion_policy_qualification_v1.json`.

5DF450 dispatches these six content IDs. Values below come from the owned o2
instructions and exact float constants, rather than inferred item names. Content,
effect and attribute identifiers in the table are hexadecimal.

| Content | Effect/variant | Local offset | Subtype | Attributes |
| --- | --- | --- | --- | --- |
|72 |27/0 |(0,18.700000762939453,0) |0 |1 |
|3200 |7F/−1 |(0,−1,0) |6 |1 |
|1C |44/0 |(0,10.100000381469727,5.699999809265137) |3 |0E |
|1D, first |40/0 |(0,10.199999809265137,3.5) |4 |15 |
|1D, second |3F/32 |(0,10.100000381469727,5.699999809265137) |3 |4E |
|135 |43/0 |(0,10.100000381469727,5.699999809265137) |3 |0E |
|75 |91/0 |(−54.150001525878906,−2.380000114440918,0) |5 |A5 |

The default3200 argument changes initial age to the original remaining lifetime
and remaining time to2. This write precedes the common null guard, so the full/
missing-visual case needs explicit native admission rather than reproducing a
write through address0. The75 branch supplies camera offset10. The first1D
emission is separately initialized and does not receive the common final
category-byte assignment applied to the last emission.

654720 has seven state destinations at7401D0: initialize, attached update,
retirement, a persistent return state, actor-action waiting, random delay and
material fading. Its subtype destinations at7401B0 are a separate table.
Attachment transforms use a fresh identity with only the model's nine axis XYZ
values copied, and a three-term local-offset transform plus model position.
Model column4 is not a position term in that SDK operation. The policy keeps
the pre-increment child sample time separate from the next age value.

An earlier investigation description called6B2680 a collision object. The
existing lighting mappings and its consumers establish the following correction:

- 6B2680 starts scheduler task5D85E0 and creates a lighting record through6B3090.
  It gates the request on actor action2/secondary11. These are actual gameplay
  and lighting consumers, not an audio call.
- 6B3090 uses6B2FA0's shared64-slot lighting owner at747540, with a56-byte source
  record stride and a52-byte authored payload.6B3020 retires the same records.
- The copied7202C0 payload has its position replaced at float indices8..10.
  Other parameter names require the actual lighting consumer before assigning
  broader rendering semantics.
- 1B8C70 is the distinct resource-audio request in the75 random-delay path,
  selecting cue20 or21 from the canonical RNG.

The shared lighting owner is also needed by ordinary scenario020 and the related
23/24/25 commands, through6B1EC0/6B1FE0/6B2020/6B2170. The earlier owned-content
probe found020 as the first frontier in160 banks. A separate temporary-light
pool would violate shared capacity and identity. Migrate the actual light pool,
room bank importer and timed task before admitting the1D companion route.

The comparison corrected the new policy's unknown-subtype path: it hides the
visual and enters retirement. The first fixture used unrelated synthetic RNG
addresses; it now seeds/compares actual3244B0/3244B8/2B8DE8. Failed cohorts remain
preserved. A focused driver makes policy checks independent of the much larger
combined regression build; production warning checks remain enabled.

Original590D80 clears the complete retired model record. The existing native
retirement already clears its canonical model too. A retained native lease can
observe that cleared object while fading; it must not retarget a recycled model
generation. No invented final-pose snapshot is needed.

Remaining integration includes actual shared work/child capacity, native model
leases, room lighting and timed tasks, real resource audio, material sampling/
fade publication, the six factory branches and full owned-asset acceptance.
