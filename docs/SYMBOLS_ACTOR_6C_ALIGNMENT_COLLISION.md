# Actor 6C aligned movement and surface transitions

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed.
Addresses and offsets hex; scalar distances below are decimal. Actor identity,
original action names and collision material identities remain unresolved.
No execution, attachment, replay, profiling or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CA710](../recomp/config/output_ovl/o2/o2_006CA710_0x6ca710.cpp) | `transform_actor_6c_root_motion_by_alignment_and_apply_position_candidate` | High mechanics; probable role | BA3=0 builds Euler90/92/94. NonzeroBA3 in primary1/secondary6 or7 copies current matrix50 instead. Otherwise modes1/2 compose Euler with quaternionD18;other modes use yaw-only Euler. Unless54A bit8 is set,composes scale(B4,1,BC);always clearsbit8. Transforms4E4 XYZ intoC0,scales resultingC0/C4/C8 byF0,adds toposition38. Does not commit position to matrix or run collision itself. |
| [o2 0x6CAA20](../recomp/config/output_ovl/o2/o2_006CAA20_0x6caa20.cpp) | `trace_actor_6c_pitch_yaw_offset_ray_for_surface_normal_and_point_candidate` | High mechanics; probable role | a0actor,a1normal-out,a2point-out,a3signed-low16 yawoffset,f12distance. Builds370220 basis frompitch90,yaw92+offset,roll0;rotates(0,0,distance),addsactorXYZ,5795E0 trace fromactorXYZ,mask20FFFF,t1=0. Success requireshit,lowtype!=2,and100000flag. Copiesnormal thenhitpoint into required output pointers,returns1;otherwise0 withoutputsuntouched. No null-output tests. |
| [o2 0x6CAB70](../recomp/config/output_ovl/o2/o2_006CAB70_0x6cab70.cpp) | `enter_actor_6c_primary_seven_on_forward_surface_contact_candidate` | High mechanics; probable role | Nonpositive lengthC0 returns. Traces fromposition alongnormalizedC0*73. Admits hit withlowtype!=2 and100000flag; saves8/9 toBE8/BE9,motion520 toD46,old9 toB,sets9=7 andA=2 whenBA3=0 otherwise3. Mode2 chooses heading orientation by exactdot(D00,normal)==0;sets54A bit1,placesXYZ=hit+normal*74,commitsA900,optionally adds8000 yaw aftercommit,setsC36=7,copieshitD0C/normalD00. No primary8write. |
| [o2 0x6CADB0](../recomp/config/output_ovl/o2/o2_006CADB0_0x6cadb0.cpp) | `resolve_actor_6c_aligned_surface_edges_or_restore_previous_position_candidate` | High mechanics; probable role | NonpositiveC0 length returns. FormsP=position+D00+C0+normalize(C0)*73. IfP.y<D28,or>D2C,savesstate/motion,sets9=7,A=2/3 respectively,headingopposed/alignedD00,setsY=D28+74 orD2C-74,A900,C36=7. Inrange performs three bounded traces between priorposition44+D00 andP,with20*normal offsetvectors; qualified first/thirdhits enter9=7,A=0/1 respectively,secondhit keepsstates. Noqualifiedhit restoresXYZfrom44,6367C0,9ED0(actor,1,0). Accepted hit path handling below. |
| [o2 0x6CB420](../recomp/config/output_ovl/o2/o2_006CB420_0x6cb420.cpp) | `steer_actor_6c_from_vertical_bounds_or_normal_flagged_surface_candidate` | High mechanics; probable role | NonpositiveC0lengthreturns. Radiusr=148*BC;forwardcandidate=position+normalize(C0)*r. IfcandidateY+0.1<D28 target=position-(0,r,0);else ifcandidateY>D2C target=position+(0,r,0). Otherwise tracesforward thenreverse parallel segment offset20*D00 inXZ only. Qualifiedforwardhit selectsposition-normal*r,qualifiedreversehit position+normal*r. Onanyselection getsB900 heading,adds634B20(signed16heading-yaw,BDC) to92. NoXYZwrite,phasewrite or finalmatrixcommit. |
| [o2 0x6CB6D0](../recomp/config/output_ovl/o2/o2_006CB6D0_0x6cb6d0.cpp) | `find_actor_6c_nearest_horizontal_flagged_surface_heading_delta_candidate` | High mechanics; probable role | a0actor,a1optionalnormal-out,a2optionalpoint-out. Fourownedworld-axisrays oflength1000;admits hit,lowtype!=2,100000flag,strictdistance<initial10000. Firststrictminimumwins. Returns signed16(heading(actorXYZ,hit)-yaw92),copiesselectednormal/point onlyifcorrespondingpointer nonnull. Noqualifiedhit returns0 withoutoutputwrites;0also representsalignedsuccessfulhit. |
| [o2 0x6CB900](../recomp/config/output_ovl/o2/o2_006CB900_0x6cb900.cpp) | `calculate_actor_6c_target_heading_in_selected_alignment_frame_candidate` | High mechanics; probable role | a0actor,a1targetXYZ. BA3=0 returns376E70(position,target) signed16. Mode1 buildsquaternion5A8220(D00,up),convertsmatrix,transforms(target-position),returnsheadingfromzero. Mode2 composes5A8220(down,D00) with5A8220(D00,up) using192360 beforematrixconversion andsamevectorheading. Othermodesreturnwithoutlocallydefinedv0. Noactorwrites. |

The surface qualification above is precisely `(type & FF) != 2` and
`(type & 100000) != 0`, using trace mask20FFFF. These constants do not establish
an original material or actor species name.

6CADB0 accepted inrange traces, withN=returnednormal,H=hitpoint:

- Firsttrace priorposition44+D00 ->P: enter9=7,A=0,save state/motion;case2
  setsheadingnormal->zero andpositionH+74*N,thenA900.
- Secondtrace P->P-20*oldnormal: case1 storesD0C=H-normalize(C0)*73,
  copiesNtoD00,5A82A0(quaternionD18,N,BA3),thenreturns. It does not take the
  subsequentposition/yaw/C36 path.
- Thirdtrace P-20*oldnormal ->priorposition44+D00-20*oldnormal: enter9=7,A=1,
  save state/motion;case3 setsheadingzero->N andpositionH+20*oldnormal-74*N,
  thenA900.
- Cases2/3 constructquaternion(oldnormal,N),matrix;exactmatrixelement[8]==1
  replacedwithowned0.9999899864. Adds signed16rounded
  `65536*192110(element[8])/2pi+0.5` toyaw92,thenstoresHtoD0C,NtoD00,C36=7.
  No new general clamp or vector normalization is inferred here.

Owned o2 file-backed data independently decoded:730660 has four floatvectors
(1000,0,0),(-1000,0,0),(0,0,1000),(0,0,-1000);730690up(0,1,0),7306A0down(0,-1,0).
740FC8=0.1000000015,740FD0=0.9999899864,740FF0=6.28318548.
The four-ray routine copies exactly48bytes,notthreeXYZentries.

The boundary transitions preserve their precise branch/delay-slot behavior and
original update order; their occurrence, frequency and performance cost remain
unknown without runtime evidence. Related [motionhelpers](SYMBOLS_ACTOR_6C_MOTION_CONTROLS.md)
and [motion-event dispatcher](SYMBOLS_ACTOR_6C_MOTION_EVENTS.md).
