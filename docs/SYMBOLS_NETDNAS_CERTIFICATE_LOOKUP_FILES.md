# Network DNAS: certificate file and hash-directory lookup methods

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, file lookup through the target, live-memory read or authentication occurred.

Ten complete clear bodies were independently read, including token loops, array-growth failures, lookup retry entry and object-release paths. Owned method labels and by_dir.c path establish X509 lookup family; [default strings](SYMBOLS_NETDNAS_CERTIFICATE_ADAPTERS.md), [store insertions/namehash](SYMBOLS_NETDNAS_CERTIFICATE_STORE.md), [byte buffer](SYMBOLS_NETDNAS_GROUPED_NAME_CODEC.md), and [error context](SYMBOLS_NETDNAS_ERROR_CONTEXT.md) provide independent connections. Proposed labels are not original symbols. Host filesystem, default environment, parser conformance, CRLcache validity and successful trust decisions remain partial. No gameplay timing or slowdown attribution follows.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6FAD18](../recomp/config/output_ovl/o4/o4_006FAD18_0x6fad18.cpp) | `get_certificate_hash_directory_lookup_method` | Confirmed complete clear orchestration; parser/store/runtime limits retained | Returns owned7619A8 method: constructor6FADE8,destructor6FAE60,control6FAD28,subjectlookup6FB160. Table/name below; no live lookup. |
| [o4 0x6FAD28](../recomp/config/output_ovl/o4/o4_006FAD28_0x6fad28.cpp) | `control_certificate_lookup_directory_list_and_compiled_environment_defaults` | Confirmed complete clear orchestration; parser/store/runtime limits retained | Only selector2 admitted. Modea3==3 appends72D910 compiled directory with format1, failure adds(Bhex,D7hex,9Chex); success queries resident106880(72D930 environmentname), appends its result format1. Othermodes append originala2 string with signed32a3format. Returns append result; does not validate environment provider or directory existence. |
| [o4 0x6FADE8](../recomp/config/output_ovl/o4/o4_006FADE8_0x6fade8.cpp) | `allocate_certificate_directory_lookup_private_lists_and_byte_buffer` | Confirmed complete clear orchestration; parser/store/runtime limits retained | Allocates14hex private bytes then6FA9F8 byte buffer; failure frees admitted private. Clears directorycount4,pointerarray8,formatarrayC,capacity10, storeslookupC=private, returns1. No filesystem request or lookup validation. |
| [o4 0x6FAE60](../recomp/config/output_ovl/o4/o4_006FAE60_0x6fae60.cpp) | `release_certificate_directory_strings_arrays_buffer_and_private_state` | Confirmed complete clear orchestration; parser/store/runtime limits retained | For signedpositivecount4 frees each nonNULL directory string, then arrays8/C, bytebuffer0 via6FAA50, thenprivate. Initial loop test precedesbody. No lookupC clear, count-capacity validation or NULLprivate guard. |
| [o4 0x6FAF10](../recomp/config/output_ovl/o4/o4_006FAF10_0x6faf10.cpp) | `append_colon_delimited_directory_strings_and_parallel_format_codes` | Confirmed complete clear orchestration; parser/store/runtime limits retained | NULL/empty entire input0. Scans colon orNUL; token span comes from current delimiter minus tokenstart. Compares against existing names10B440 but ignores result, so no dedup guarantee. Grows pointer/format arrays by10 entries, commits capacity before allocating both; partial failure does not locally free admitted replacement or restorecapacity. Copies oldcapacity slots, freesoldarrays, storesnew. Appends allocated token+NUL and format, incrementscount. Empty-token branch returns to comparison without advancing delimiter cursor (while updating tokenstart), so skipping empty components is not established and subsequent signed span may be negative. No token-size/pointer overflow or transactional-failure proof; static observations only. |
| [o4 0x6FB160](../recomp/config/output_ovl/o4/o4_006FB160_0x6fb160.cpp) | `look_up_subject_in_directory_hash_files_then_shared_certificate_cache` | Confirmed complete clear orchestration; parser/store/runtime limits retained | NULLname0; accepts type1/2,otherreports(Bhex,D8hex,A5hex). Builds stack typekey; type1 initializes borrowed name proxy and keypointer, while type2 does not locally initialize keypointerC4. Allocates resizable scratch, hashes name72C6B0. For each directory format constructs `%s/%08lx.%s%d` with empty suffix and increasing fileindex; resident114E20 tests path into stack. Type1 loads6FB498 until failure/statnegative; type2 skips that load call. Under classB guard5/6 performs706368(store4,stackkey), firsthit copies two wrapperwords tocalleroutput andreturns1; no local retain. No filesystem availability, CRLfile convention or completed authentication claim; formatting/capacity and type2 stackkey remain partial. |
| [o4 0x6FB3C8](../recomp/config/output_ovl/o4/o4_006FB3C8_0x6fb3c8.cpp) | `get_certificate_file_cache_lookup_method` | Confirmed complete clear orchestration; parser/store/runtime limits retained | Returns7619D0 method with labelLoad file into cache and control6FB3D8; all other method pointers0. Fulltable below; no loader invocation. |
| [o4 0x6FB3D8](../recomp/config/output_ovl/o4/o4_006FB3D8_0x6fb3d8.cpp) | `control_certificate_file_cache_loader_with_compiled_environment_defaults` | Confirmed complete clear orchestration; parser/store/runtime limits retained | Only selector1; mode3 calls6FB498(lookup,72D920 defaultfile,1); failureadds(Bhex,D6hex,9Dhex). Success queries resident106880(72D940 environmentname),loads resultformat1. Othermodes use callerpath/format. ReturnsBoolean nonzero. Loader NULLpath returns1, so success alone does not prove fileopened. |
| [o4 0x6FB498](../recomp/config/output_ovl/o4/o4_006FB498_0x6fb498.cpp) | `load_certificate_objects_from_file_stream_into_subject_cache` | Confirmed complete clear orchestration; parser/store/runtime limits retained | NULLpath returns1 without opening. Creates6F9C78/6F3370 file stream and control6Chex with flags3/path; failure(Bhex,E0hex,802hex). Format1 loops70AB80 stream decode then72CE98 storeinsert, releases732138 each successful object, counts inserts. Decode failure with errorlow12==6Chex and count>0 clears703A00 errors andreturnscount; otherwise809hexerror0. Format2 single72D508 decode theninsert. Unknownformat9Ahexerror. Frees admitted finalcertificate/stream onexit. Parsing/network/backend contracts remain separate; no loaded trust or fileexistence proof. |
| [o4 0x6FB670](../recomp/config/output_ovl/o4/o4_006FB670_0x6fb670.cpp) | `load_crl_shaped_objects_from_file_stream_through_partial_cache_insert` | Confirmed complete clear orchestration; parser/store/runtime limits retained | Same independently read stream/mode/nullpath/loop/cleanup shape as6FB498; format1 uses70ABB8, format2 uses72D538, destroys730B18, invokes72CFB8 insertion, reportfunctionE1hex. That insertion target is independently partial: its allocated wrapper fields are not locally initialized. Accordingly this entry maps file/decode/orchestration, not a proven valid CRLcache or revocation decision. |

## Complete owned lookup methods and strings

7619A8..7619D0, tenlittle-endianwords, SHA-256 `575b53ada30acc16d397465d23abdf9e8533a5671adeeea4a861f7a37a18f58c`:

```text
0077CE90 006FADE8 006FAE60 00000000 00000000 006FAD28 006FB160 00000000 00000000 00000000
```

7619D0..7619F8, tenlittle-endianwords, SHA-256 `8610976926396ae6b9dbb7124afa037e7741ed3bafd789914d2f3b8118397f3f`:

```text
0077CF00 00000000 00000000 00000000 00000000 006FB3D8 00000000 00000000 00000000 00000000
```

77CE90: `Load certs from files in a directory` plusNUL; complete37bytes SHA-256 `56ee5aecd50b382442366d88ff3c1dcbd0620ee506b2b9070d52f21483b2a3e2`.

77CF00: `Load file into cache` plusNUL; complete21bytes SHA-256 `31444b16829e1a6fa81e65f6173ec77c83aa9569436aad4db4850c8498ba351a`.

77CEB8: `` plusNUL; complete1bytes SHA-256 `6e340b9cffb37a989ca544e6bb780a2c78901d3fb33738768511a30617afa01d`.

77CEC0: `%s/%08lx.%s%d` plusNUL; complete14bytes SHA-256 `a9f40b87a38f9e7fe18e5c1627ce88b4235e98f2c8d1d0fee5389e137017995a`.

77CED0: `./crypto/x509/../../crypto/x509/by_dir.c` plusNUL; complete41bytes SHA-256 `39c62792185dcca98839f0e3d0c0fc260996b6019cba0e521d0bebec8ed58555`.

The empty suffix is literal; no `r` CRL filename suffix is read by6FB160. Paired provider/default paths do not show current platform files or configured trust. Static malformed-input/unwind observations above are not reproduced defects.
