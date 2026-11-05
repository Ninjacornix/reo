# Resident disc file adapters and shared formatted diagnostic buffer

Static resident executable SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Three complete original intervals reviewed. No file opened/read, diagnostic formatted or target executed. Hex values.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x18D820](../recomp/config/output/sub_0018D820_0x18d820.cpp) | `read_requested_disc_file_bytes_using_uppercase_prefixed_path` | Confirmed complete static path/delegate/result contract | Args filename,output,length. Builds stack800-bytepathownedcdrom0:+filenameuppercase+;1,invokesempty18D760,entersoptionalnestedopticalguard1AB790. Opens118A70(flags1);negativeleavesguard/returns0. Otherwise1190B0(fd,output,length),close118CF8,leaveguard,returns1regardlessreadcount/error/closestatus. No pathcapacity/outputspancheck. |
| [0x18DAB0](../recomp/config/output/sub_0018DAB0_0x18dab0.cpp) | `query_disc_file_size_by_open_seek_end_and_close` | Confirmed complete static path/delegate/result contract | Sameprefix/uppercase/suffix/emptyhook;enters12BD78directly,opensflags1. Opennegative=>12BD90/0. Otherwise118E78(fd,0,2)size,close,12BD90,returnsrawseeksignedresult. Zero conflatesemptyfile/openfailure;no seek/closeadmission. |
| [0x1A5AA0](../recomp/config/output/sub_001A5AA0_0x1a5aa0.cpp) | `format_variadic_diagnostic_into_shared_2b0000_buffer_and_return_one` | Confirmed complete static path/delegate/result contract | Savesvariadicregisterargsa1..t3in8-byteslots,fixesarglisttostack28 andcalls10F880(destination2B0000,formata0,arglist). Alwaysreturns1ignoringformatterstatus;unboundedsharedbuffer,no printinginthisbody. |

Owned241C68..241C78 bytescdrom0:NULand;1NULwithpadding, SHA-256 `dc589b91c08dca558ad5e43d74334c5b0eed86cfb2b9dded5cb5a90ba7e5e9f6`. The reader'sboolean1 meansopen succeededandreadattempted,notprovenfullrequestedbytes. Sizequery returnsseektargetdirectly;negativeerrorisretainedexceptopenfailure0. Both areseparatefromnative incidentreportstorage.

[Optional optical nesting guard](SYMBOLS_ARCHIVE_NAMES_IOP_STARTUP.md), [existing debug file write/append adapters](SYMBOLS_RESOURCE_HEAP.md), [unbounded argument-list formatter](SYMBOLS_FORMAT_IO_ARITHMETIC.md) and [empty path hook](SYMBOLS_FRAME_DMA_DISPATCH.md) owncalleecontracts. No lock identity or measured duration is implied by guard-like calls.

Audit: 3 rows, 125 verified owned instruction words; 6 omitted interval words are zero/NOP; 0 omitted nonzero words.
