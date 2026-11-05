# HTTP overlay recorded low-address stack candidate report

Static owned File #1 o6 `nethttp.bin`,runtime ID6/base6E0000,SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Four complete catalogue bodies independently reviewed,includingbaseline0failure,alloptionaloutputs,metadataaddressesandformatarguments. No liveprocess/stackread/targetexecution/build/network. [Shared710648lower-addressrecorder](SYMBOLS_SHARED_BODIES.md) writeslowestcandidateandsourcefile/line/hitonlywhenincomingunsignedaddressislowerthanpreviouscandidate. Thesehelpersreportstoredaddressdifference;actualstackusage/threadownership/incidenttimingremainunknown. Hexadecimalunlessstated.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x710620](../recomp/config/output_ovl/o6/o6_00710620_0x710620.cpp) | `initialize_stack_address_baseline_and_lowest_candidate_tracking` | Confirmed complete twoglobalsetter | Writesincominga0to7384B4baselineand7384B0lowestcandidate,returns0. Doesnotvalidatepointer/clearpreviousfile,line,hitmetadataormarkthreadidentity. |
| [o6 0x710638](../recomp/config/output_ovl/o6/o6_00710638_0x710638.cpp) | `get_recorded_stack_address_baseline` | Confirmed complete scalar getter | Returns7384B4word,notlowestaddressorcomputedusage. |
| [o6 0x710680](../recomp/config/output_ovl/o6/o6_00710680_0x710680.cpp) | `query_stack_address_delta_and_low_candidate_source_metadata` | Confirmed fullbaselinegate/optionaloutputflow | Baseline7384B4==0=>275Dwithoutoutputs. Elseoptionalouta0=baseline-lowest7384B0mod32;optionala1=740530sourcefile,a2=740528line,a3=74052Chit,returns0. Metadata beyondownedimageextentwrittenbyalreadyshared710648;no live rereadperformedhereinresearch. |
| [o6 0x7106E8](../recomp/config/output_ovl/o6/o6_007106E8_0x7106e8.cpp) | `print_recorded_stack_candidate_delta_and_source_location_to_stream` | Confirmed completequery/error/formatflow | 710680fills4stacklocals;nonzerostatuspropagates. Success6F1C40(stream,owned73D3F8format,span,file,line,hit),ignoresprintfresult,returns0. Literalformat Peek stack usage = %d bytes [%s:%d, Hit#%d] LF. No stackwalk/threadsampling/actualstack-boundaryverification. |

Ownedformat73D3F8wasreadthroughitsNULterminator. Metadata740528/52C/530liesbeyondownedo6end73FA80;onlystaticwrite/readinstructionsestablishthefieldcontract,noclaimofownedinitialcontentsorlivedata. Setter710620doesnotresetmetadata,andnostackallocation/protectionprobeoccursinthesebodies. Sourcefilenamepointerremainsborrowedandonlynumericaddressdifferenceiscomputed.

Audit:57 verified instruction words, zero conflicts,1 omitted zero word (NOP padding), zero omitted nonzero words.
