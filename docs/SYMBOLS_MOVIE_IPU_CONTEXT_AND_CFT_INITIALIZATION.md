# Movie IPU context adapters and CFT initialization

Static File #1 US research, 2026-11-04. Complete original bodies and ownedversionstring in **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**, reviewed. No target, IPU, build or conversion test executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x149178](../recomp/config/output/sub_00149178_0x149178.cpp) | `save_movie_IPU_DMA_context_into_private_offset_68_candidate` | Confirmed full adapter and reviewed SDKcallee | Resolvesowner40,passesprivate+68to113C98(stop/captureinput-outputDMAcontext),ignorescalleevalue,returns1. Doesnotitselfallocatecontextorprovepixelcompletion. |
| [0x1491A0](../recomp/config/output/sub_001491A0_0x1491a0.cpp) | `restore_movie_IPU_DMA_context_from_private_offset_68_candidate` | Confirmed full counterpart | Resolvesowner40,113D80(private+68) restorescontextwithbitpointer/FIFOcompensation,returns1. Originalhardwareownershiprequirementsin[SDKcontextnote](SYMBOLS_IPU_DMA_CONTEXT_AND_RESET.md). |
| [0x1491C8](../recomp/config/output/sub_001491C8_0x1491c8.cpp) | `initialize_CRI_CFT_version_pointer_and_default_movie_alpha_candidate` | Confirmed complete owned version and setter | Storesowned23E260versionpointerat264C00;149208returnsalphaaddress,stores0there,then149218(80hex=128). Ownedstring CRI CFT/PS2EE Ver.1.33 Build:Jul29 2003 15:13:52 identifiesoriginalconverterlibrary,notcurrentnativebuildID. No decoder,experimentalrenderpathorVUenable. |

Related: [movie global alpha contract](SYMBOLS_MOVIE_CLIPPED_CONVERSION_AND_MAX_ALPHA.md), [workspace](SYMBOLS_MOVIE_WORKSPACE_AND_LIFECYCLE.md), [central index](FUNCTION_INDEX.md). Alpha units inherit the complete149218 review; no assumed255-based host blend parity.
