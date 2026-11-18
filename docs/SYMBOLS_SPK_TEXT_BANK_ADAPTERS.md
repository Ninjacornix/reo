# SPK text-bank cleanup, layout and auxiliary bit adapters

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed.
Addresses/offsets/constantshex; layoutparameterspreservedwithoutoriginalUIlabels.
No targetexecution,textureload,renderbenchmarkorfixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B9F30](../recomp/config/output_ovl/o2/o2_006B9F30_0x6b9f30.cpp) | `adapt_text_bank_layout_parameters_then_apply_auxiliary_flags_candidate` | High mechanics; probable role | a0selector,a1index,a2/a3/t0layout,t1drawarg;buildsstackdescriptor(selector,index,a2,a3,t0,18,16),A070(descriptor,t1),thenA190(originalselector,index). Noresultgatebeforeflags. |
| [o2 0x6B9FA0](../recomp/config/output_ovl/o2/o2_006B9FA0_0x6b9fa0.cpp) | `clean_text_bank_entries_or_single_resolved_text_key_candidate` | High mechanics; probable role | Selector0baseword32443C,selector1base324438;index8-byteentryrelativeoffset/count,iteratescount32signed,1B49B0(base+eachoffset). Selector2resolves1C1CE0(index),1B49B0(result). Otherselectorusesbase/pointerregistersnotlocallyinitialized;callercontractunresolved. |
| [o2 0x6BA070](../recomp/config/output_ovl/o2/o2_006BA070_0x6ba070.cpp) | `draw_resolved_text_bank_entries_with_per_entry_vertical_spacing_candidate` | High mechanics; probable role | Descriptorselector0->base32443C,1->324438;selected8-byteoffset/countentry;iterates1B4820(originaldrawarg,desc8,descC+desc18*i,desc10,desc14,base+entryoffset),returnoffsetlistpointer. Selector2single1C1CE0(desc4),1B4820(drawarg,desc8/C/10/14,resolved),returns0. Otherselectorslacklocalbase/pointerinitialization;no inferredfallback. |
| [o2 0x6BA190](../recomp/config/output_ovl/o2/o2_006BA190_0x6ba190.cpp) | `apply_eight_text_bank_auxiliary_bit_commands_except_selector_two_candidate` | High mechanics; probable role | a0selector,a1entryindex;selector2returns. Allotherselectorsreadbase32443C(regardlessselector0/1),list=base+unsignedhalf0+10*index. Eightcommandhalves:FFFFskip,othersA230(low15,highbit?1:0). No content/typecheck,selector1notrewrittentobase324438. |

A190'sshared32443Cbaseforselector0/1wascheckedthroughexactbranchesratherthan
copiedfromA070'sdifferentselectorcontract. Runtimebasecontentsunread.
[Originalfont/nativeboundary](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md)retained.
Related[textwork](SYMBOLS_SPK_TEXT_WORK_AND_DISPLAY.md)and
[condition/history](SYMBOLS_SPK_CONDITION_AND_HISTORY.md).
