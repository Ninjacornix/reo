# Actor 6BE6C0 callback and initialization

Static File #1 US research, 2026-11-04. Two complete original bodies reviewed.
Addresses/offsets/selectors hexadecimal; scalar counts decimal. Original actor
identity remains unresolved. No execution, attachment, build, replay or changes
to game speed, rendering or engine code.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BE6C0](../recomp/config/output_ovl/o2/o2_006BE6C0_0x6be6c0.cpp) | `tick_actor_6be6c0_primary_state_contact_and_sixteen_joint_work_candidate` | High mechanics; original identity unresolved | Resets status and previous transforms, scores targets, checks contact, ticks timers and dispatches primary byte8 through72FBD0 without local bounds check. Full post-dispatch joint/health work below. This callback is per actor; no global update or runtime frequency claim. |
| [o2 0x6BEA20](../recomp/config/output_ovl/o2/o2_006BEA20_0x6bea20.cpp) | `initialize_actor_6be6c0_target_motion_collision_and_joint_work_candidate` | High mechanics | Health544<=0 enters terminal tuple(4,0,63,existingB),byte1=0. Positive health calls6F1660(0,&actor),selects roster from63F6B0 lowbyte,binds24/7556E8,C26=targetbyte3,BD4=99999999 converted float. Builds Eulerbasis50,6C0700,byte1=1,553=0,C94|201,6C0400(actor,0,0,0,0float),then clearsC94 entirely. Remaining initialization below. |

6BE6C0 initial operations:

- Half54A=10; C36/CF3/C82/32=0,BA5=1,C94 bit1 clear. CopiesXYZ38..40
  to44..4C and rotation90..96 toA0..A6; zeros4E4/4E8/4EC.
- Global7556E8=actor24, including null. Nonnull target supplies signed byte3 to
  5A98F0(self,id), resultBD4. Calls635E20(self,C8C,0,f12=BCC,f13=BD0).
- Primary8 other than0/4 with13F nonzero calls6C0C80. Positive signedCEE/CF0
  decrement. Calls640210, then actual byte8 selects72FBD0 callback.

Post-dispatch:

- C82=0 calls68A4A0; otherwise clearsC0..CB (12 decimal bytes).
- Nonzero signedCEC decrements; resulting<=0 plays1B9310(self,CE8,0),clearsCEC.
  Calls6347D0.
- Unless primary8=4 and while actorbyte0 nonzero, uses three fixed loops:
  odd joint ordinals1,3,..15 call6C1120(self,ordinal); odd ordinals call58C750
  with work755360+1C*ordinal, bonebyte1A and half-vector+2; even ordinals0,2,..14
  copy half-vector1E/20/22/24 to2/4/6/8, negate firstthree,then58C750.
  First loop condition precedes entry; each has exactly eight iterations if
  helper calls leave shared counter7556F8 unchanged. Shared-counter mutation
  contracts and actual concurrent use remain unverified.
- 6C0FE0 forwards transition code conditionally by session mode. Unless primary4,
  actorY=CD8+20 float. Copies health544 into runtime record74F26C+60*B98.

6BEA20 positive-health continuation:

- F0=1float;C80/C82/CF5/C2E/C94/C9A/C9B=0;546=544.
  616F20(XYZ,&byte,FF) supplies CD8, actorY=CD8+20.
- For model51C byte1 joint count, zeros actor[1FF+20*ordinal]. This is a real
  per-joint byte clear, distinct from the counter-only loop inside6C0400.
- Installs1A8=word72FD38 and1D8=word72FDE8; shape pointer fromword[word728FFC]
  supplies four floatsC70..C7C copiedto1AC..1B8/1BC..1C8.
- 190=20FFFF,194=0,551=C,552=0,global755700=self;
  RNGstream0&7F->CF2;6C1020(self),5DF9F0(self,0),zeroBE8 length4 andC length8.

Owned72FBD0 length18 six entries:
`[6BEA20,6BECB0,6BF6E0,6BFCB0,6BFF30,6C1450]`;
SHA256`143413c0268faa08810a60aa3ac5c8861e571b75aaad7efcbe7804833cb3d307`.
This physical six-entry extent does not establish admission of arbitrary byte8.
Owned image `build-function-index/owned-overlays/o2.bin`,base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

See [motion and target selection](SYMBOLS_ACTOR_6BE6C0_MOTION_TARGET_SELECTION.md).

Full-body owned-word audit: 2 rows, 369 verified instruction words,
zero conflicts, 8 omitted zero/NOP words, zero omitted nonzero words.
