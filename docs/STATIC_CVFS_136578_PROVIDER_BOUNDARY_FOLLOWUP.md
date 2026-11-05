# CVFS136578: provider-purpose follow-up and later comparative refinement

Static original File #1 US owned resident ELF,2026-11-05,SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Full136578,device registration135488,lookup135560,path-capability136F98,disc/host registrations131088/131338,factories and both concrete owned optional dispatchers were revisited. No game,device operation,RPC,filesystem request,build or process was used. **Initial provider-only conclusion: purpose unresolved, with no new semantic row. The subsequent [pinned CVX second pass](recvx-crosscheck/FILESYSTEM_SECOND_PASS.md) now supports a narrowly qualified legacy file-count interface role in SYMBOLS_CRI.md; optional selector4 behavior remains unresolved.**

136578's exact registry contract is established:strlen(inputName),scan32 registry slots262068 at stride10hex,compare only input-length name prefix at slot+4. For each match,136F98(inputName) determines the route. Capability nonzero and nonnull interface/method60 calls method60(&stack,4,0,0),with original inputName at stack+4 and stack+0 uninitialized in this function. Capability zero and callable method44 invokes it without explicit argument setup at13663C. Correction from the second pass: the earlier method44(originalName) notation was unsupported;136F98 may change caller-saved registers and explicitly sets a0=0 before its optional capability callback. First callable match returns its actual result;otherwise continue scan and return0 after all32. It does not split a file path or supply a default name. Null methods are skipped rather than called.

The concrete provider closure is stronger than simply restating that dispatch. Original131088 registers the disc factory,131338 the host factory through1353F8/135488. Disc interface21CBF8[26] and host21DA88[26] both have **method44=NULL**. Their method60 targets13A180 and13BCF0;both return0 for capability selector64 and do not implement selector4. Therefore this operation returns0 for either of those ordinary owned providers. This is an unsupported-provider result,not proof that0 means empty directory,success,false,free-space count or an absent file.

The paired neighboring API136688 calls method48 with original path and two additional arguments;one initial structural hypothesis was a device directory/listing family around method44/48. Adjacency alone was not enough to choose GetNumFiles,GetFileList,format,mount or any other original API. The later pinned CVX comparison adds the complete private getNumFiles scan/call structure and full LoadDirInfo wrapper correspondence, supporting qualified names in SYMBOLS_CRI.md. No concrete method44 or optional-selector4 body in the owned providers supplies a more specific output unit.

The [portable static evidence helper](../tools/function_index/review_main_media_purpose_evidence.py) checks both104-byte interface hashes and scans10 hash-bound original image ranges plus12,167 reconstructed o4/o5 DNAS words for aligned literal/J/JAL references to136578 and the other assigned media entries. It finds no additional136578 call/literal candidate;the [receipt](../build-function-index/main-media-purpose-evidence.json) retains hashes and all candidates. This extends the previous resident-only search into owned overlays/recovered code. It does not rule out computed indirect calls,custom providers,dynamic registration or unowned library versions.

What would resolve the remaining optional-provider behavior:an owned implementing device interface with nonnull method44,an implementation of method60 selector4,or a caller that consumes its result with an independently typed contract. None was fabricated from table position. The later comparative legacy-role annotation does not fill these implementation/output gaps. See [CVFS interface contracts](SYMBOLS_CRI.md) and [independently resolved byte-size operations](SYMBOLS_CVFS_64BIT_FILE_SIZE_QUERY_ROUTES.md) for the concrete provider distinction.

The owned IOP follow-up also covered the bounded original `/IOP/MODULES/DRIVE.DAT` member at ISO LBA1212,size356544,SHA-256 `6ac9f10940514fe0d54139498de87d432a4e84db499aa5f07e53ad5889d92c79`. Its11 MUU module entries were individually hash-recorded and their ELF symbol/printable debug strings scanned for CVFS/CVDV/CVHT/GetNumFiles/GetFileList. There were no named CVFS symbols/types or matching operation names. This includes member9 CRI_ADX_Driver,125201 bytes,SHA-256 `456f07cb55a5bed66643fd95ca6ef64874265b578630b905a9328346e01aefb7`,with426 named symbols. Stripped unnamed code is not excluded by a string search.

A file-related debug callback type does exist in that IRX: `_ldfilefunc`,size32bytes,eight pointer fields{beforeOpen,afterOpen,close,setBufSize,beforeRead,read,lseek,getfsize}. Its paired `_lmwooption` has a functable pointer to that type. It is a module-loader file callback family,not the104-byte EE CVFS device interface:it has no offset44/60 member,registered CVFS factory or selector4 binding. The separately reviewed SJRMT RPC service operates streaming queue chunks/reset/UUID/availability,also not a directory/count implementation. Reusing those known file/queue labels would not resolve method44. This is a scoped owned-library negative result;no module was loaded or executed.

Full neighboring provider layout,read from the original104-byte tables (disc21CBF8 SHA-256 `110e07237b9879134ef9aa44289116e0a63f2ff0392b117f842bebb325692d8a`;host21DA88 `40df6d55908bd06ecee4d4c144c3a30a7a3b2aed1f0afcd9202dd43ffd3f2a00`). Existing names below are supplied by independently reviewed callers;NULL slots cannot identify an unimplemented operation:

| Offset | Established EE caller purpose | Disc / host target |
| --- | --- | --- |
|00|service handles|139798 /13B1D8|
|04|error callback registration|139810 /13B250|
|08|path byte-size query|139928 /13B308|
|0C|free-size caller|NULL /NULL|
|10|open|139A50 /13B608|
|14|close|139BD8 /13B790|
|18|seek|139C30 /13B840|
|1C|tell|139CC8 /13B8D8|
|20|request read|139D00 /13B910|
|24|request write caller|NULL /NULL|
|28|stop transfer|139EA8 /13BAA0|
|2C|status|139FA8 /13BBA8|
|30|sector length|139FE0 /13BBE0|
|34|set sector length caller|NULL /NULL|
|38|transfer count|139FE8 /13BBE8|
|3C|change-directory caller|NULL /NULL|
|40|file-existence query|1398A0 /13B268|
|44|136578 legacy file-count candidate from later CVX comparison|NULL /NULL|
|48|136688 LoadDirInfo candidate from later full-wrapper comparison|NULL /NULL|
|4C|max-byte-rate caller|NULL /NULL|
|50|make-directory caller|NULL /NULL|
|54|remove-directory caller|NULL /NULL|
|58|delete-file caller|NULL /NULL|
|5C|extended path-size caller|NULL /NULL|
|60|optional dispatcher|13A180 /13BCF0|
|64|no identified callable provider member|NULL /NULL|

Selector64hex is an argument to method60,not member offset64. Both optional dispatchers explicitly admit C8/C9/CA/CB/CC/CD and12B paths,with all other selectors returning0. This separates method44 and selector4 from the independently resolved low/high size commands and avoids naming it by adjacency. The evidence helper now retains all26 table words,all11 IOP module hashes and the original loader callback debug type for reproducibility.
